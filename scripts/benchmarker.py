import os
import subprocess
import sys
import time
import json

def get_git_sha():
    try:
        return subprocess.check_output(['git', 'rev-parse', 'HEAD']).decode('utf-8').strip()
    except Exception:
        return "unknown"

def parse_unix_time(stderr_output):
    import re
    match = re.search(r'real\s+([0-9.]+)', stderr_output)
    if match:
        return float(match.group(1))
    return None

def run_benchmarks():
    tests_dir = 'tests'
    results = {}
    
    if not os.path.exists(tests_dir):
        print(f"No {tests_dir} directory found.")
        return

    for root, dirs, files in os.walk(tests_dir):
        for file in files:
            if not file.startswith('test_'):
                continue
                
            filepath = os.path.join(root, file)
            print(f"Benchmarking {filepath}...")
            
            start_time = time.perf_counter()
            try:
                if file.endswith('.py'):
                    if sys.platform != 'win32':
                        res = subprocess.run(f"time -p {sys.executable} '{filepath}'", shell=True, capture_output=True, text=True)
                        exec_time = parse_unix_time(res.stderr) or (time.perf_counter() - start_time)
                    else:
                        subprocess.run([sys.executable, filepath], check=True, stdout=subprocess.DEVNULL)
                        exec_time = time.perf_counter() - start_time
                elif file.endswith('.js'):
                    if sys.platform != 'win32':
                        res = subprocess.run(f"time -p node '{filepath}'", shell=True, capture_output=True, text=True)
                        exec_time = parse_unix_time(res.stderr) or (time.perf_counter() - start_time)
                    else:
                        subprocess.run(['node', filepath], check=True, stdout=subprocess.DEVNULL)
                        exec_time = time.perf_counter() - start_time
                elif file.endswith('.cpp'):
                    bin_path = os.path.join(root, 'test_bin')
                    if os.name == 'nt':
                        bin_path += '.exe'
                    subprocess.run(['g++', '-O3', '-std=c++17', filepath, '-o', bin_path], check=True, stdout=subprocess.DEVNULL)
                    
                    if sys.platform != 'win32':
                        res = subprocess.run(f"time -p ./{bin_path}", shell=True, capture_output=True, text=True)
                        exec_time = parse_unix_time(res.stderr) or 0
                    else:
                        exec_start = time.perf_counter()
                        try:
                            subprocess.run([bin_path], check=True, stdout=subprocess.DEVNULL)
                        except OSError:
                            pass
                        exec_time = time.perf_counter() - exec_start
                    
                    if os.path.exists(bin_path):
                        os.remove(bin_path)
                    
                    results[filepath] = exec_time
                    continue
                    
                results[filepath] = exec_time
            except subprocess.CalledProcessError as e:
                print(f"Benchmark failed for {filepath}")
                
    report = {
        "commit_sha": get_git_sha(),
        "timestamp": time.time(),
        "results": results
    }
    
    os.makedirs('benchmarks', exist_ok=True)
    with open('benchmarks/results.json', 'w', encoding='utf-8') as f:
        json.dump(report, f, indent=2)
        
    print("Benchmarking complete. Results saved to benchmarks/results.json")

if __name__ == '__main__':
    run_benchmarks()

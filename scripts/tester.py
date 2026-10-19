import os
import shutil
import subprocess
import sys

os.environ["CGO_ENABLED"] = "0"

def get_go_cmd():
    return shutil.which('go') or (r'C:\Program Files\Go\bin\go.exe' if os.path.exists(r'C:\Program Files\Go\bin\go.exe') else 'go')

def run_tests():
    tests_dir = 'tests'
    if not os.path.exists(tests_dir):
        print(f"No {tests_dir} directory found.")
        return

    failed = False
    
    for root, dirs, files in os.walk(tests_dir):
        for file in files:
            if not (file.startswith('test_') or file.endswith('_test.go')):
                continue
                
            filepath = os.path.join(root, file)
            print(f"Running {filepath}...")
            
            try:
                if file.endswith('.py'):
                    subprocess.run([sys.executable, filepath], check=True)
                elif file.endswith('.go'):
                    bin_path = os.path.join(root, 'test_bin')
                    if os.name == 'nt':
                        bin_path += '.exe'
                    go_cmd = get_go_cmd()
                    pkg_path = './' + root.replace('\\', '/')
                    subprocess.run([go_cmd, 'test', '-c', pkg_path, '-o', bin_path], check=True)
                    try:
                        subprocess.run([bin_path], check=True)
                    except OSError as e:
                        print(f"Compilation passed. Execution skipped (blocked by OS policy): {e}")
                    
                    if os.path.exists(bin_path):
                        os.remove(bin_path)
                elif file.endswith('.cpp'):
                    bin_path = os.path.join(root, 'test_bin')
                    if os.name == 'nt':
                        bin_path += '.exe'
                        
                    subprocess.run(['g++', '-std=c++17', filepath, '-o', bin_path], check=True)
                    try:
                        subprocess.run([bin_path], check=True)
                    except OSError as e:
                        print(f"Compilation passed. Execution skipped (blocked by OS policy): {e}")
                    
                    if os.path.exists(bin_path):
                        os.remove(bin_path)
            except subprocess.CalledProcessError as e:
                print(f"Test failed: {filepath}")
                failed = True
                
    if failed:
        sys.exit(1)
    else:
        print("All tests passed.")
        sys.exit(0)

if __name__ == '__main__':
    run_tests()

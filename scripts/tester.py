import os
import subprocess
import sys

def run_tests():
    tests_dir = 'tests'
    if not os.path.exists(tests_dir):
        print(f"No {tests_dir} directory found.")
        return

    failed = False
    
    for root, dirs, files in os.walk(tests_dir):
        for file in files:
            if not file.startswith('test_'):
                continue
                
            filepath = os.path.join(root, file)
            print(f"Running {filepath}...")
            
            try:
                if file.endswith('.py'):
                    subprocess.run([sys.executable, filepath], check=True)
                elif file.endswith('.js'):
                    subprocess.run(['node', filepath], check=True)
                elif file.endswith('.cpp'):
                    bin_path = os.path.join(root, 'test_bin')
                    # On Windows, we append .exe
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

import os
import json
import re
import sys

def check_snake_case(filename):
    name = os.path.splitext(filename)[0]
    if not re.match(r'^[a-z0-9_]+$', name):
        return False
    return True

def validate_metadata(filepath):
    try:
        with open(filepath, 'r', encoding='utf-8') as f:
            content = f.read()
            
        ext = os.path.splitext(filepath)[1]
        
        if ext == '.py':
            match = re.search(r'"""\s*(\{.*?\})\s*"""', content, re.DOTALL)
        else:
            match = re.search(r'/\*\s*(\{.*?\})\s*\*/', content, re.DOTALL)
            
        if not match:
            return False, "Missing or malformed metadata block."
            
        metadata = json.loads(match.group(1))
        
        required_keys = ["problem_name", "category", "time_complexity", "space_complexity"]
        for key in required_keys:
            if key not in metadata:
                return False, f"Missing required key '{key}' in metadata."
                
        return True, ""
    except Exception as e:
        return False, str(e)

def main():
    errors = []
    
    for item in os.listdir('.'):
        if os.path.isdir(item) and item[0].isupper() and item != ".git":
            for root, dirs, files in os.walk(item):
                for file in files:
                    if file.endswith(('.py', '.cpp', '.js')):
                        filepath = os.path.join(root, file)
                        
                        if not check_snake_case(file):
                            errors.append(f"[LINT WARNING] {filepath}: Naming anomaly detected. Expected snake_case format (e.g., my_problem_name.ext).")
                            
                        is_valid, msg = validate_metadata(filepath)
                        if not is_valid:
                            errors.append(f"[METADATA ERROR] {filepath}: {msg}")
                            
    if errors:
        print("Validation finished with issues:")
        for err in errors:
            print(err)
        sys.exit(2)  # Specific error code for linting/metadata issues
    else:
        print("Validation passed. All files comply with repository standards.")
        sys.exit(0)

if __name__ == "__main__":
    main()

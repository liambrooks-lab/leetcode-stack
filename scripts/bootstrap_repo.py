import os
import json
import re

def get_default_complexity(category, filename):
    time = "O(N)"
    space = "O(1)"
    
    if category == "Trees":
        time = "O(N)"
        space = "O(H)"
    elif category == "Graphs":
        time = "O(V + E)"
        space = "O(V + E)"
    elif category == "Dynamic_Programming":
        time = "O(N^2)"
        space = "O(N)"
    elif category == "Matrices":
        time = "O(M * N)"
        space = "O(M * N)"
    elif category == "Sorting" or category == "Cyclic_Sort":
        time = "O(N)"
        space = "O(1)"
    elif category == "Backtracking":
        time = "O(2^N)"
        space = "O(N)"
    elif category == "Binary_Search":
        time = "O(log N)"
        space = "O(1)"
    elif category == "Sliding_Window":
        time = "O(N)"
        space = "O(1)" # or O(K)
    
    # Specific exceptions
    if "median_of_two_sorted_arrays" in filename:
        time = "O(log(min(M, N)))"
    elif "longest_palindromic_substring" in filename:
        time = "O(N^2)"
    elif "two_sum" in filename:
        space = "O(N)"
        
    return time, space

def process_file(filepath, category):
    filename = os.path.basename(filepath)
    ext = os.path.splitext(filename)[1]
    
    with open(filepath, 'r', encoding='utf-8') as f:
        content = f.read()
        
    if 'problem_name' in content and 'time_complexity' in content:
        return # Already has metadata
        
    problem_name = filename.replace('.py', '').replace('.cpp', '').replace('.js', '').replace('_', ' ').title()
    time, space = get_default_complexity(category, filename)
    
    meta = {
        "problem_name": problem_name,
        "category": category,
        "time_complexity": time,
        "space_complexity": space
    }
    
    meta_str = json.dumps(meta, indent=2)
    
    if ext == '.py':
        meta_block = f'"""\n{meta_str}\n"""\n'
    else:
        meta_block = f'/*\n{meta_str}\n*/\n'
        
    new_content = meta_block + content
    with open(filepath, 'w', encoding='utf-8') as f:
        f.write(new_content)

for item in os.listdir('.'):
    if os.path.isdir(item) and item[0].isupper() and item != ".git":
        for root, dirs, files in os.walk(item):
            for file in files:
                if file.endswith(('.py', '.cpp', '.js')):
                    process_file(os.path.join(root, file), item)
print("Metadata injected successfully.")

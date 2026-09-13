import os
import json
import re

def get_metadata(filepath):
    try:
        with open(filepath, 'r', encoding='utf-8') as f:
            content = f.read()
            
        ext = os.path.splitext(filepath)[1]
        if ext == '.py':
            match = re.search(r'"""\s*(\{.*?\})\s*"""', content, re.DOTALL)
        else:
            match = re.search(r'/\*\s*(\{.*?\})\s*\*/', content, re.DOTALL)
            
        if match:
            return json.loads(match.group(1))
    except Exception:
        pass
    return None

def main():
    index_data = []
    
    for item in os.listdir('.'):
        if os.path.isdir(item) and item[0].isupper() and item != ".git":
            for root, dirs, files in os.walk(item):
                for file in files:
                    if file.endswith(('.py', '.cpp', '.js')):
                        filepath = os.path.join(root, file)
                        meta = get_metadata(filepath)
                        if meta:
                            meta['file'] = filepath.replace('\\', '/')
                            index_data.append(meta)
                            
    os.makedirs('index', exist_ok=True)
    
    # Write JSON
    with open('index/index.json', 'w', encoding='utf-8') as f:
        json.dump(index_data, f, indent=2)
        
    # Write Markdown
    markdown_content = "# LeetCode Stack Index\n\n"
    markdown_content += "Automatically generated problem index.\n\n"
    
    categories = {}
    for entry in index_data:
        cat = entry['category']
        if cat not in categories:
            categories[cat] = []
        categories[cat].append(entry)
        
    for cat in sorted(categories.keys()):
        markdown_content += f"## {cat}\n\n"
        markdown_content += "| Problem | Time Complexity | Space Complexity | File |\n"
        markdown_content += "|---|---|---|---|\n"
        for entry in sorted(categories[cat], key=lambda x: x['problem_name']):
            markdown_content += f"| {entry['problem_name']} | `{entry['time_complexity']}` | `{entry['space_complexity']}` | [{os.path.basename(entry['file'])}](../{entry['file']}) |\n"
        markdown_content += "\n"
        
    with open('index/README.md', 'w', encoding='utf-8') as f:
        f.write(markdown_content)
        
    print("Index generated successfully.")

if __name__ == "__main__":
    main()

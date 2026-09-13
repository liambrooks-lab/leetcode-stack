# 1. Variables Definition
CXX = g++
CXXFLAGS = -O3 -std=c++17
PYTHON = python3
NODE = node

# 2. PHONY Targets
.PHONY: cpp py js clean push validate test benchmark index

# 3. Execution Rules
cpp:
	@echo "Compiling and running C++ file: $(file)..."
	$(CXX) $(CXXFLAGS) $(file) -o executable
	./executable

py:
	@echo "Running Python script: $(file)..."
	$(PYTHON) $(file)

js:
	@echo "Running Node.js script: $(file)..."
	$(NODE) $(file)

# 4. Infrastructure Rules
validate:
	@echo "Running Repository Validator..."
	python scripts/validator.py

test:
	@echo "Running Test Framework..."
	python scripts/tester.py

benchmark:
	@echo "Running Reproducible Benchmarking..."
	python scripts/benchmarker.py

index:
	@echo "Generating Problem Index..."
	python scripts/indexer.py

# 5. Clean Rule
clean:
	@echo "Cleaning up workspace..."
	rm -f executable test_bin test_bin.exe

# 6. Git Automation Rule
push:
	@echo "Staging, Committing, and Pushing to GitHub..."
	git add .
	git commit -m "$(msg)"
	git push origin main
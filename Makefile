.PHONY: build run test clean new debug

CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall

BUILD_DIR = build
PROBLEMS_DIR = problems
TEMPLATE_DIR = template

name ?= two_sum

SRC = $(PROBLEMS_DIR)/$(name)/solution.cpp
BIN = $(BUILD_DIR)/$(name)
INPUT = $(PROBLEMS_DIR)/$(name)/input.txt
EXPECTED = $(PROBLEMS_DIR)/$(name)/expected.txt
OUTPUT = $(PROBLEMS_DIR)/$(name)/output.txt

# ======================
# COMMANDS
# ======================

new:
	@echo "Creating $(name)..."
	@mkdir -p $(PROBLEMS_DIR)/$(name)
	@cp $(TEMPLATE_DIR)/solution.cpp $(SRC)
	@cp $(TEMPLATE_DIR)/input.txt $(INPUT)
	@cp $(TEMPLATE_DIR)/expected.txt $(EXPECTED)
	@echo "Done."

build:
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(SRC) $(CXXFLAGS) -o $(BIN)

run: build
	@echo "Running..."
	@$(BIN) < $(INPUT)

test: build
	@echo "Testing..."
	@$(BIN) < $(INPUT) > $(OUTPUT)
	@diff -u -w $(EXPECTED) $(OUTPUT) || echo "❌ Wrong Answer"
	@echo "Done."

debug:
	$(CXX) $(SRC) $(CXXFLAGS) -DLOCAL -g -o $(BIN)
	gdb $(BIN)

clean:
	rm -rf $(BUILD_DIR)
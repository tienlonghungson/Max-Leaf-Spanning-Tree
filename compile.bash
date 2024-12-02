#!/bin/bash

# Directories
SRC_DIR="src"
BIN_DIR="src/bin"
OUTPUT_FILE="$BIN_DIR/main"

# Create bin directory if it doesn't exist
mkdir -p "$BIN_DIR"

# Find all .cpp files in the src directory recursively
CPP_FILES=$(find "$SRC_DIR" -type f -name "*.cpp")

# Check if there are any .cpp files
if [ -z "$CPP_FILES" ]; then
    echo "No .cpp files found in the src directory."
    exit 1
fi

# Compile the .cpp files into the executable
g++ -std=c++20 -o "$OUTPUT_FILE" $CPP_FILES

# Check if the compilation succeeded
if [ $? -eq 0 ]; then
    echo "Compilation successful! Executable created at: $OUTPUT_FILE"
else
    echo "Compilation failed."
    exit 2
fi

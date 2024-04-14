# Compiler
CXX = g++

# Base compiler flags
BASE_CXXFLAGS = -Wall

# Build directory for object files
OBJ_DIR = bin

# Source directory
SRC_DIR = src

# Target executable name
TARGET = $(OBJ_DIR)/main

# Find all cpp files in the src directory and subdirectories
SRCS = $(shell find $(SRC_DIR) -name '*.cpp' -or -name '*.c')

# Create a list of object files from the source files
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# Default make target
all: CXXFLAGS = $(BASE_CXXFLAGS) -O2
all: $(TARGET)

# Debug target
debug: CXXFLAGS = $(BASE_CXXFLAGS) -g
debug: $(TARGET)

# Run the main file
run: clean all
	./$(TARGET)

# Link object files into a binary
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@

# Compile cpp files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean bin files
clean:
	@find $(OBJ_DIR) -type f -name '*.o' -delete
	@rm -f $(TARGET)

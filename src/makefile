# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -g

# Build directory for object files
OBJ_DIR = build

# Source directory
SRC_DIR = .

# Target executable name
TARGET = $(OBJ_DIR)/main

# Find all cpp files in the src directory and subdirectories
SRCS = $(wildcard $(SRC_DIR)/*.cpp) \
       $(wildcard $(SRC_DIR)/Breeder/*.cpp) \
       $(wildcard $(SRC_DIR)/Command/*.cpp) \
       $(wildcard $(SRC_DIR)/configClass/*.cpp) \
       $(wildcard $(SRC_DIR)/Farm/*.cpp) \
       $(wildcard $(SRC_DIR)/Farmer/*.cpp) \
       $(wildcard $(SRC_DIR)/Game/*.cpp) \
       $(wildcard $(SRC_DIR)/Grid/*.cpp) \
       $(wildcard $(SRC_DIR)/Inventory/*.cpp) \
       $(wildcard $(SRC_DIR)/Item/*.cpp) \
       $(wildcard $(SRC_DIR)/loadconfig/*.cpp) \
       $(wildcard $(SRC_DIR)/Mayor/*.cpp) \
       $(wildcard $(SRC_DIR)/PColor/*.cpp) \
       $(wildcard $(SRC_DIR)/Player/*.cpp) \
       $(wildcard $(SRC_DIR)/Ranch/*.cpp) \
       $(wildcard $(SRC_DIR)/Resident/*.cpp) \
       $(wildcard $(SRC_DIR)/Store/*.cpp)

# Create a list of object files from the source files
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# Default make target
all: $(TARGET)

# Link object files into a binary
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@

# Compile cpp files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	@rm -rf $(OBJ_DIR)/*.o
	@rm -f $(TARGET)

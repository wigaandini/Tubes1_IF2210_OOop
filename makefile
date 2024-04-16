CXX = g++

BASE_CXXFLAGS = -Wall -std=c++17

OBJ_DIR = bin

SRC_DIR = src

TARGET = $(OBJ_DIR)/main

SRCS = $(shell find $(SRC_DIR) -name '*.cpp' -or -name '*.c')

OBJS =  $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

all: CXXFLAGS = $(BASE_CXXFLAGS) -O2
all: $(TARGET)

debug: CXXFLAGS = $(BASE_CXXFLAGS) -g
debug: $(TARGET)

run: clean all
	./$(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

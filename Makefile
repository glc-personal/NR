# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++2a -stdlib=libc++ -I./LA.Core/include -I./LA.Utilities/include -I/usr/local/include -fvisibility=hidden
LDFLAGS = -stdlib=libc++ -L/usr/local/lib -lgtest -lgtest_main -pthread -undefined dynamic_lookup
#LDFLAGS = -stdlib=libc++ -L/usr/local/lib -lgtest -lgtest_main -pthread

# Directories
CORE_DIR = ./LA.Core
CORE_SRC_DIR = $(CORE_DIR)/src
CORE_INC_DIR = $(CORE_DIR)/include
CORE_TEST_DIR = $(CORE_DIR)/tests
UTILITIES_DIR = ./LA.Utilities
UTILITIES_SRC_DIR = $(UTILITIES_DIR)/src
UTILITIES_INC_DIR = $(UTILITIES_DIR)/include
BUILD_DIR = ./build

# Source files
CORE_SOURCES = $(wildcard $(CORE_SRC_DIR)/*.cpp)
UTILITIES_SOURCES = $(wildcard $(UTILITIES_SRC_DIR)/*.cpp)
MAIN_SOURCE = main.cpp
TEST_SOURCES = $(wildcard $(CORE_TEST_DIR)/*.cpp)

# Object files
CORE_OBJECTS = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(notdir $(CORE_SOURCES)))
UTILITIES_OBJECTS = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(notdir $(UTILITIES_SOURCES)))
MAIN_OBJECT = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(notdir $(MAIN_SOURCE)))
TEST_OBJECTS = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(notdir $(TEST_SOURCES)))

# Executables
EXEC = $(BUILD_DIR)/NR
TEST_EXEC = $(BUILD_DIR)/LA_Core_Tests

# Build all targets
all: $(EXEC) $(TEST_EXEC)

# Link the main executable
$(EXEC): $(CORE_OBJECTS) $(UTILITIES_OBJECTS) $(MAIN_OBJECT) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Link the test executable
$(TEST_EXEC): $(TEST_OBJECTS) $(CORE_OBJECTS) $(UTILITIES_OBJECTS) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Compile main.cpp
$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile core sources
$(BUILD_DIR)/%.o: $(CORE_SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile utilities sources
$(BUILD_DIR)/%.o: $(UTILITIES_SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile test sources
$(BUILD_DIR)/%.o: $(CORE_TEST_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean up
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean


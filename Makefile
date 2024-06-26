# Compiler
CXX = g++

# Directories
# LA.Core
LA_CORE_DIR = ./LA.Core
LA_CORE_SRC_DIR = $(LA_CORE_DIR)/src
LA_CORE_INC_DIR = $(LA_CORE_DIR)/include
LA_CORE_TEST_DIR = $(LA_CORE_DIR)/tests
# LA.Utilities
LA_UTILITIES_DIR = ./LA.Utilities
LA_UTILITIES_SRC_DIR = $(LA_UTILITIES_DIR)/src
LA_UTILITIES_INC_DIR = $(LA_UTILITIES_DIR)/include
# LA.Solvers
LA_SOLVERS_DIR = ./LA.Solvers
LA_SOLVERS_SRC_DIR = $(LA_SOLVERS_DIR)/src
LA_SOLVERS_INC_DIR = $(LA_SOLVERS_DIR)/include
LA_SOLVERS_TEST_DIR = $(LA_SOLVERS_DIR)/tests
# Build
BUILD_DIR = ./build

# Compiler flags
CXXFLAGS = -std=c++2a -stdlib=libc++ -I./$(LA_CORE_INC_DIR) -I./$(LA_UTILITIES_INC_DIR) -I./$(LA_SOLVERS_INC_DIR) -I/usr/local/include
LDFLAGS = -stdlib=libc++ -L/usr/local/lib -lgtest -lgtest_main -pthread -undefined dynamic_lookup

# Source files
LA_CORE_SOURCES = $(wildcard $(LA_CORE_SRC_DIR)/*.cpp)
LA_UTILITIES_SOURCES = $(wildcard $(LA_UTILITIES_SRC_DIR)/*.cpp)
LA_SOLVERS_SOURCES = $(wildcard $(LA_SOLVERS_SRC_DIR)/*.cpp)
MAIN_SOURCE = main.cpp
LA_CORE_TEST_SOURCES = $(wildcard $(LA_CORE_TEST_DIR)/*.cpp)
LA_SOLVERS_TEST_SOURCES = $(wildcard $(LA_SOLVERS_TEST_DIR)/*.cpp)

# Object files
LA_CORE_OBJECTS = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(notdir $(LA_CORE_SOURCES)))
LA_UTILITIES_OBJECTS = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(notdir $(LA_UTILITIES_SOURCES)))
LA_SOLVERS_OBJECTS = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(notdir $(LA_SOLVERS_SOURCES)))
MAIN_OBJECT = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(notdir $(MAIN_SOURCE)))
LA_CORE_TEST_OBJECTS = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(notdir $(LA_CORE_TEST_SOURCES)))
LA_SOLVERS_TEST_OBJECTS = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(notdir $(LA_SOLVERS_TEST_SOURCES)))

# Executables
EXEC = $(BUILD_DIR)/NR
LA_TEST_EXEC = $(BUILD_DIR)/LA_Tests

# Build all targets
all: $(EXEC) $(LA_TEST_EXEC)

# Link the main executable
$(EXEC): $(LA_CORE_OBJECTS) $(LA_UTILITIES_OBJECTS) $(LA_SOLVERS_OBJECTS) $(MAIN_OBJECT) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Link the test executable
$(LA_TEST_EXEC): $(LA_CORE_TEST_OBJECTS) $(LA_SOLVERS_TEST_OBJECTS) $(LA_CORE_OBJECTS) $(LA_UTILITIES_OBJECTS) $(LA_SOLVERS_OBJECTS) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Compile main.cpp
$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile LA.Core sources
$(BUILD_DIR)/%.o: $(LA_CORE_SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile LA.Utilities sources
$(BUILD_DIR)/%.o: $(LA_UTILITIES_SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile LA.Solvers sources
$(BUILD_DIR)/%.o: $(LA_SOLVERS_SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile test sources
$(BUILD_DIR)/%.o: $(LA_CORE_TEST_DIR)/%.cpp $(LA_SOLVERS_TEST_DIR) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean up
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean


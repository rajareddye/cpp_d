CXX = g++
CXXFLAGS = -std=c++14 -Wall -g

# List of source files
SRC_FILES = main.cpp PluginManager.cpp UppercasePlugin.cpp

# List of header files
HEADER_FILES = PluginInterface.h

# Generate a list of object files from source files
OBJ_FILES = $(SRC_FILES:.cpp=.o)

# Output executable name
OUTPUT = TextProcessingApp.out

# Targets
all: $(OUTPUT)

$(OUTPUT): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $(OUTPUT) $(OBJ_FILES)

# Rule to generate object files
%.o: %.cpp $(HEADER_FILES)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES) $(OUTPUT)

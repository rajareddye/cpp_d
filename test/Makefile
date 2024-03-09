CXX = g++
CXXFLAGS = -std=c++14 -Wall -g

# List of source files
SRC_FILES = test2.cpp

# List of header files
HEADER_FILES = .

# Generate a list of object files from source files
OBJ_FILES = $(SRC_FILES:.cpp=.o)
# Include Boost linker files
LDFLAGS += -lboost_system -lboost_thread -lboost_filesystem

# Output file
OUTPUT = myprogram

# Targets
all: $(OUTPUT)

# Linker flags
$(OUTPUT): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $(OBJ_FILES) $(LDFLAGS) -o $(OUTPUT) 

# Rule to generate object files
%.o: %.cpp $(HEADER_FILES)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES) $(OUTPUT)

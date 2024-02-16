# Define the compiler and the flags
CXX=g++
CXXFLAGS=-std=c++11 -Wall -g

# Name of the executable
TARGET=main

# All cpp files to be compiled
SRCS=main.cpp graph.cpp heap.cpp prims.cpp

# Corresponding object files
OBJS=$(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Linking all the object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compiling each source file to an object file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Cleaning the build
clean:
	rm -f $(OBJS) $(TARGET)

# Defining .PHONY to say that 'all' and 'clean' are not files
.PHONY: all clean

# Makefile to compile the program

CXX = c++        # C++ compiler (version 11	or greater)
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic  # Options compiler C++17

# Name of the executable
TARGET = main.out

# List of source files
SRCS = main.cpp sources/task.cpp sources/focusForge.cpp

# List of header files
HEADERS = headers/task.h headers/focusForge.h

# List of object files
OBJS = $(SRCS:.cpp=.o)

# Rule to link the program
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile the source files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean the directory
clean:
	rm -f $(OBJS) $(TARGET)

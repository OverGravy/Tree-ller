# Makefile

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall

# Directories
OBJDIR = obj
BINDIR = bin
SRCDIR = src

# Source files
SRC = $(wildcard $(SRCDIR)/*.cpp)
$(info SRC files: $(SRC))

# Object files
OBJ = $(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

# Target executable
TARGET = $(BINDIR)/Tree-ller

# Default target
all: $(TARGET)

# Link the target executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files into object files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -rf $(OBJDIR) $(BINDIR)/Tree-ller
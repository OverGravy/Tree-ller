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

# Object files
OBJ = $(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

# Target executable
TARGET = $(BINDIR)/Tree-ller

# SFML libraries
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Default target
all: $(TARGET)

# Link the target executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(SFML_LIBS)

# Compile source files into object files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -rf $(OBJDIR) $(BINDIR)/Tree-ller
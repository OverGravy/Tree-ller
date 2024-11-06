# Nome del compilatore
CXX = g++

# Opzioni del compilatore
CXXFLAGS = -Wall -Wextra -std=c++17

# Directory di output
OBJDIR = obj
BINDIR = bin

# File sorgenti e oggetti
SRCS = BinaryTree.cpp main.cpp
OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)

# Nome del file eseguibile
TARGET = $(BINDIR)/BinaryTreeApp

# Regola di default
all: $(TARGET)

# Regola per creare l'eseguibile
$(TARGET): $(OBJS)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) -o $@ $^ -lsfml-graphics -lsfml-window -lsfml-system

# Regola per creare i file oggetto
$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Regola per pulire i file generati
clean:
	rm -rf $(OBJDIR) $(BINDIR)

# Regola per eseguire il programma
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
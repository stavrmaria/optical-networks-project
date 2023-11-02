# Compiler and compiler flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Directories
SRCDIR = src
INCDIR = include
BUILDDIR = build
TARGET = optnet

# Source and header files
SOURCES := $(wildcard $(SRCDIR)/*.cpp)
HEADERS := $(wildcard $(INCDIR)/*.h)

# Object files
OBJECTS := $(SOURCES:$(SRCDIR)/%.cpp=$(BUILDDIR)/%.o)

# Build rule for the target executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Build rule for object files
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp $(HEADERS)
	@mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

# Clean rule
clean:
	rm -rf $(BUILDDIR) $(TARGET)

.PHONY: clean

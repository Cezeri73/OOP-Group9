CXX = g++
CXXFLAGS := $(shell fltk-config --cxxflags) 
LDFLAGS := $(shell fltk-config --ldflags --use-images)  
TARGET = smart_home

SRC = $(wildcard *.cpp) 
OBJ = $(SRC:.cpp=.h)
DEL = $(SRC:.cpp=.o)


all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)
clean:
	rm -f $(DEL) $(TARGET)

CXX = g++
CXXFLAGS := $(shell fltk-config --cxxflags) 
LDFLAGS := $(shell fltk-config --ldflags --use-images)  

SRC = $(wildcard *.cpp) 
OBJ = $(SRC:.cpp=.h)
DEL = $(SRC:.cpp=.o)

ifeq ($(OS),Windows_NT)
	RM = cmd /C del
	EXE = .exe
else
	RM = rm -f
	EXE = 
endif

TARGET = smart_home$(EXE)

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)
clean:
	$(RM) $(DEL) $(TARGET)

CXX = g++
CXXFLAGS := $(shell fltk-config --cxxflags)
LDFLAGS := $(shell fltk-config --ldflags --use-images)
TARGET = smart_home

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean-linux:
	rm -f $(OBJ) $(TARGET)

clean-windows:
	del /f /q $(OBJ) $(TARGET).exe

clean:
ifdef OS
ifeq ($(OS),Windows_NT)
	@$(MAKE) clean-windows
else
	@$(MAKE) clean-linux
endif
else
	@$(MAKE) clean-linux
endif

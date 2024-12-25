CXX = g++
CXXFLAGS = -std=c++11 -I C:\Users\Tunahan\Documents\external_source\fltk-1.4.0-1 -I C:\Users\Tunahan\Documents\external_libs\FLTK

# Linker Flags
LDFLAGS = -L C:\Users\Tunahan\Documents\external_libs\FLTK\lib -lfltk -lcomctl32 -lole32 -luuid -lgdi32 -lws2_32 -lgdiplus -lwinspool -lcomdlg32
TARGET = smart_home

SRC = $(wildcard *.cpp) 
OBJ = $(SRC:.cpp=.h)
DEL = $(SRC:.cpp=.o)


all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)
clean:
	rm -f $(DEL) $(TARGET)

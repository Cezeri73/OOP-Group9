CXX = g++
CXXFLAGS = -I/usr/local/include -I/usr/local/include/FL/images -I/usr/local/include/png -I/usr/local/include/zlib -I/usr/local/include/jpeg -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_THREAD_SAFE -D_REENTRANT
LDFLAGS = -L/usr/local/lib -lfltk -pthread -lpthread -lm -lX11
TARGET = smart_home

SRC = main.cpp SmartDevice.cpp Room.cpp MainWindow.cpp
OBJ = $(SRC:.cpp=.h)

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

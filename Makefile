# A basic makefile for oour pill project.
# -L/Applications/MATLAB_R2014b.app/bin/maci64 -leng -lmx 

CXX = g++
CFLAGS = -std=c++11 -I/usr/local/include/tesseract/ -I/usr/local/include/leptonica/ -O3 -I/Applications/MATLAB_R2014b.app/extern/include 
LIBS = -L/usr/local/lib -ltesseract -llept `pkg-config --libs opencv`
EXE = pilz

src = $(wildcard src/*.cpp)
obj = $(src:.cpp=.o)

$(EXE):$(obj)
	$(CXX) $(CFLAGS) $(LIBS) -o $@ $^

.PHONY: clean
clean:
	rm -f $(EXE)

# A basic makefile for oour pill project.
# -L/Applications/MATLAB_R2014b.app/bin/maci64 -leng -lmx 

CXX = g++ -std=c++11
CXXFLAGS = -I/usr/include/tesseract/ -I/usr/local/leptonica/
LIBS = -L/usr/local/lib -ltesseract -llept `pkg-config --libs opencv tesseract `
EXE = pilz

src = $(wildcard src/*.cpp)
obj = $(src:.cpp=.o)

$(EXE):$(obj)
	$(CXX) $(CXXFLAGS) $(LIBS) -o $@ $^

.PHONY: clean
clean:
	rm -f $(EXE)

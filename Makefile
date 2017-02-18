# A basic makefile for oour pill project.
# -L/Applications/MATLAB_R2014b.app/bin/maci64 -leng -lmx 

CXX = g++ -std=c++11
CXXFLAGS = -I/usr/include/tesseract/ -I/usr/local/leptonica/
LIBS = -ltesseract `pkg-config --libs opencv lept`
EXE = pilz

src = $(wildcard src/*.cpp)
obj = $(src:.cpp=.o)

$(EXE):$(obj)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LIBS)

.PHONY: clean
clean:
	rm -f src/*.o $(EXE)

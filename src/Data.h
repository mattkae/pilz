#pragma once
#include <tuple>
#include <string>

const int MaxElements_ = 1024;

class Data {
public:
	Data(const char* filename = "outtext.txt");
	~Data();
	void Write(std::string outText, int confidence, int index);
	std::string GetFileName() { return this->filename; }
private:
	std::string filename;
};
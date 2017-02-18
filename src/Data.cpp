#include "Data.h"
#include <iostream>
#include <fstream>

using namespace std;

Data::Data(const char* filename) {
	this->filename = filename;
	ofstream file;
	file.open(this->filename);
	file.close();
}

Data::~Data() {

}

void Data::Write(std::string outText, int confidence, int index) {
	ofstream file;
	file.open(this->filename, std::fstream::in | std::fstream::app);
	file << "-----------------PRESCRIPTION: #" << index << "-----------------" << std::endl;
	file << "Confidence: " << confidence << std::endl;
	file << outText;
	file << "-----------------END PRESCRIPTION " << index << "-----------------" <<std::endl << std::endl << std::endl;
	file.close();
}
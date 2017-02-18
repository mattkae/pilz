#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;


std::vector<string> labelParse(string filename) {
    ifstream inFile;
    inFile.open(filename);

    stringstream stringStream;
    stringStream << inFile.rdbuf();
    string input = stringStream.str();

    string pillNum = "";
    string frequency = "";
    string timePeriod = "";
    string drugName = "";
    string dosage = "";
    
    int pos = 0;
    int space = 0;

    pos = input.find("TAKE ");
    pos += 5; //we pass take
    space = input.find(" ", pos);
    pillNum = input.substr(pos, space - pos);

    pos = input.find("TIMES DAILY");
    if(pos!= input.size()) {
        timePeriod = "DAILY";
    }
    pos = input.find("TIMES WEEKLY");
    if(pos!= input.size()) {
        timePeriod = "WEEKLY";
    }
    pos = input.find("TIMES MONTHLY");
    if(pos!= input.size()) {
        timePeriod = "MONTHLY";
    }
    pos = input.find("EVERY DAY");
    if(pos!= input.size()) {
        timePeriod = "DAILY";
    }

    pos = input.find("BY ");
    pos = pos + 3;
    pos = input.find(" ", pos);
    pos = pos + 1;
    int newLine = 0;
    int temp = 0;
    newLine = input.find("\n",pos);
    temp = input.find(" ", pos);
    if (temp < newLine) {
        space = temp;    
    } else if (newLine < temp) {
        space = newLine;
    }
    frequency = input.substr(pos, space - pos);

    pos = input.find("MG"); //lets find dosage
    pos = pos - 1; //the space to the left of MG
    space = pos - 1; //the index to the left of the space
    while (input.at(space) != ' ') {
        if(input.at(space) != ' ') {
            space = space - 1;
        }    
    }
    //this should get the number of MG's in a pill
    dosage = input.substr(space + 1, pos - space + 3);

    space = space - 1; //first character of drug name
    pos = space - 1;

    while(input.at(pos) != '\n') {
        if(input.at(pos) != '\n') {
            pos = pos - 1;
        }
    }

    drugName = input.substr(pos + 1, space - pos + 1);

    inFile.close();
    std::vector<string> output;
    output.push_back(drugName);
    output.push_back(dosage);
    output.push_back(pillNum);
    output.push_back(frequency);
    output.push_back(timePeriod);
    return output;
}
#ifndef REC_H
#define REC_H

#include<vector>
using std::vector;

#include<string>
using std::string;
using std::to_string;

#include<iostream>

#include<fstream>
using std::ofstream;

class Rec {
public:
	//Constructor
	Rec();

	//Destructor
	~Rec();

	//Functions
	void Save(vector<string>);
	void Record(string);
	void Del();

private:
	//Variables
	vector<vector<string>> animals;

	//Functions
	void Write(string, string);
	vector<vector<string>> DelElems(vector<vector<string>>);
};
Rec::Rec() {
}
Rec::~Rec() {
}
void Rec::Save(vector<string> temp) {
	animals.push_back(temp);
}
void Rec::Record(string file) {
	string out = "";

	for(int i(0); i < animals.size(); i++) {
		for(int j(0); j < animals[i].size(); j++) {
			out += animals[i][j] + ',';
		};
		out += '\n';
	};
	Write(file, out);
	animals = DelElems(animals);
}
void Rec::Write(string file, string out) {
	ofstream men;
	men.open(file);
	men << out;
	men.close();
}
void Rec::Del() {
	animals.clear();
}
// Private
vector<vector<string>> Rec::DelElems(vector<vector<string>> temp1) {
	vector<string> temp2 = temp1[0];
	temp1.clear();
	temp1.push_back(temp2);
	return temp1;
}
#endif

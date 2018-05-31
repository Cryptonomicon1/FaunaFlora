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

private:
	//Variables
	vector<vector<string>> animals;

	//Functions
	void Write(string, string);
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
}
void Rec::Write(string file, string out) {
	ofstream men;
	men.open(file);
	men << out;
	men.close();
}
#endif

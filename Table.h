#ifndef TABLE_H
#define TABLE_H

#include<string>
using std::string;

#include<vector>
using std::vector;

#include"Glob.h"

class Table {
public:
	//Constructor
	Table(string, vector<string>, vector<vector<int>>, vector<string>);

	//Destructor
	~Table();

	//Functions
	string getNam();
	string getElem(string, int);

private:
	//Variables
	string name;

	//The roll_lim vector is a vector of limits for random rolls.
	// Each entry will be inclusive for rolls lower than it.
	// Each entry will be exclusive for rolls higher than it.
	vector<vector<int>> roll_lims;
	vector<string> ins;
	vector<string> outs;

	//Functions
	int getItmRef(string);
};
Table::Table(string n, vector<string> i, vector<vector<int>> rl, vector<string> o) {
	name = n;
	roll_lims = rl;
	ins = i;
	outs = o;
}
Table::~Table() {
}
//Public
string Table::getNam() {
	return name;
}
string Table::getElem(string item, int roll) {
	int itm_ref = getItmRef(item);
	int lim_ref = 0;
	string output;

	if(itm_ref == global_error) return "Error: Bad Table Reference";

	while(lim_ref != roll_lims[itm_ref].size() && roll > roll_lims[itm_ref][lim_ref]) {
		lim_ref += 1;
	};
	return (roll <= 0 || lim_ref >= outs.size()) ? "Error: Roll Out of Range" : outs[lim_ref];
}
//Private
int Table::getItmRef(string item) {
	int ref = 0;

	while(ref != ins.size() && item != ins[ref]) {
		ref += 1;
	};
	return (ref >= ins.size()) ? global_error : ref;
}
#endif

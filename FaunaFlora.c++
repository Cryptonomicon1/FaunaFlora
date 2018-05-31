#include<string>
using std::string;

#include<iostream>
using std::cout;

#include"Rec.h"
#include"Glob.h"
#include"Table.h"
#include"TablesManager.h"

int main() {
	vector<string> inputs = {"Skeleton"};
	vector<vector<int>> limits = {{80, 95, 100}};
	vector<string> outputs = {"Exoskeleton", "Endoskeleton", "Muscoskeleton"};
	Table TabA("A: Skeleton", inputs, limits, outputs);
	int file_count = 100;

	TablesManager TabMan;
	Rec R;

	TabMan.MakePlant();
	R.Save(TabMan.getFloraNams());

	for(int i(0); i < file_count; i++) {
		for(int j(0); j < 1000; j++) {
			R.Save( TabMan.MakePlant() );
		};
		R.Record("Flora" + to_string(i+1) + ".csv");
		cout << "Flora File: " << to_string(i+1) << " / " << file_count << "\n";
	};
	TabMan.MakeAnimal();
	R.Save(TabMan.getFaunaNams());

	for(int i(0); i < file_count; i++) {
		for(int j(0); j < 1000; j++) {
			R.Save( TabMan.MakeAnimal() );
		};
		R.Record("Fauna" + to_string(i+1) + ".csv");
		cout << "Fauna File: " << to_string(i+1) << " / " << file_count << "\n";
	};
}

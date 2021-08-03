
#include <iterator>
#include <map>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include "exceptions.cpp"
#include "LookUpTable.h"


LookUpTable::LookUpTable() {
	OpenFiles();
	LoadOpCodes();
	LoadRegisters();
	PrintOpCodes();
}
void LookUpTable::OpenFiles() {
	opCodeFile.open("opCodeFile.txt");
	if (!opCodeFile) {
		cerr << "Unable to open file opCodeFile.txt";
		exit(1);   // call system to stop
	}

	registerFile.open("registerFile.txt");
	if (!registerFile) {
		cerr << "Unable to open file registerFile.txt";
		exit(1);   // call system to stop
	}


}

void LookUpTable::LoadOpCodes() {
	string opCode;
	string instName;
	string line;

	while (getline(opCodeFile, line)) {
		istringstream ss(line);
		ss >> instName;
		ss >> opCode;
		opCodeMap.insert(pair<string, string>(instName, opCode));
	}
}

void LookUpTable::LoadRegisters() {
	string name;
	string value;
	string line;

	while (getline(opCodeFile, line)) {
		istringstream ss(line);
		ss >> name;
		ss >> value;
		opCodeMap.insert(pair<string, string>(name, value));
	}
}

void LookUpTable::PrintOpCodes() {
	for (auto it = opCodeMap.cbegin(); it != opCodeMap.cend(); ++it)
	{
		cout << it->first << " " << it->second << "\n";
	}

}

string LookUpTable::GetOpCode(string mnemonic) {
	map<string, string>::iterator it = opCodeMap.find(mnemonic);

	if (it != opCodeMap.end()) return it->second;
	else throw mnemonicException();
}

#pragma once


class LookUpTable {
private:
	map<string, string> opCodeMap;
	map<string, string> registers;
	ifstream opCodeFile;
	ifstream registerFile;
public:
	LookUpTable();
	void OpenFiles();
	void LoadOpCodes();
	void LoadRegisters();
	void PrintOpCodes();
	string GetOpCode(string mnemonic);
};

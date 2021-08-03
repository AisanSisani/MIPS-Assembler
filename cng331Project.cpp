#include <iostream>
#include "exceptions.cpp"
#include  "LookUpTable.h"


using namespace std;



int main() {

	LookUpTable look_up_table;
	try
	{
		string result = look_up_table.GetOpCode("and");

	}
	catch (int e)
	{
		cout << "An exception occurred. Exception Nr. " << e << '\n';
	}
	
	catch (exception& e) {
		cout << e.what() << "general"<<'\n';
	}
	catch (mnemonicException& e) {
		cout << e.what() << '\n';
	}

	return 0;
}



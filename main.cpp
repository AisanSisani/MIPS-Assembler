// cng331Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iterator>
#include <map>
#include <fstream>
#include <string>
#include <sstream>
#define checkBit(n,p) (bool)(n&(1<<p))
using namespace std;

size_t  SplitTillChar(string str, string& des, char c, size_t pos) {

    size_t index = str.find(c, pos);
    cout<<"in: "<<index<<endl;
    if (index != std::string::npos) {
        des = str.substr(pos, index - pos ); // found
        return index + 1;
    }


    else {
        des =  ""; // not f
        return pos;
    }

}
string decToBin(long int num,int length)
{
    string result = "";
    for(int i=0;i<length;i++)
    {
        if(checkBit(num,i))
        {
            result = "1" + result;
        }
        else
        {
            result = "0" + result;
        }
    }
    return result;
}
template <typename T, typename S>
bool MapGetValue(map<T, S> myMap, T name, S& des) {
    std::map<T, S>::iterator it = myMap.find(name);

    if (it != myMap.end()) {
        des = it->second;
        return true;
    }
    else {
        return false;
    }
}

int main() {
 cout<<decToBin(-2,10);
    map<string, string> m;
    m.insert(pair<string , string >("a","1"));
    string des;
    string val = "a";
    cout<< MapGetValue(m,(string) "a",des );
 //cout<<(-pow(2,15));


    try
    {
        long int i = std::stoi("-2147483647");
        std::cout << i << '\n';
    }
    catch (std::invalid_argument const &e)
    {
        std::cout << "Bad input: std::invalid_argument thrown" << '\n';
    }
    catch (std::out_of_range const &e)
    {
        std::cout << "Integer overflow: std::out_of_range thrown" << '\n';
    }
    return 0;
}



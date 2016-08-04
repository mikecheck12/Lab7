#include "hash.h"
#include "LinkedList.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

	HashSet<string> hashTable;

	string cmd;
	string item;
	
	ifstream in;
	in.open("in75.txt");

	//ofstream out;
	//out.open("actual.txt");

	while (in >> cmd) {
		if (cmd == "clear") {
			cout << "clear" << endl;
			hashTable.clear();
		}
		if (cmd == "add") {
			in >> item;
			cout << "add " << item << endl;
			hashTable.add(item);
		}
		if (cmd == "remove") {
			in >> item;
			cout << "remove " << item << endl;
			hashTable.remove(item);
		}
		if (cmd == "find") {
			in >> item;
			cout << "find " << item << " " << boolalpha << hashTable.find(item) << endl;
		}
		if (cmd == "print") {
			hashTable.print();			//pass out when writing to file
		}
	}

	//out.close();


	system("pause");
	return 0;
}
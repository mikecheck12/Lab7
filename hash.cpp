#include "hash.h"
#include "LinkedList.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char*argv[]) {

	HashSet<string> hashTable;

	string cmd;
	string item;
	
	ifstream in;
        in.open(argv[1]);

        ofstream out;
        out.open(argv[2]);

	while (in >> cmd) {
		if (cmd == "clear") {
                        out << "clear" << endl;
			hashTable.clear();
		}
		if (cmd == "add") {
			in >> item;
                        out << "add " << item << endl;
			hashTable.add(item);
		}
		if (cmd == "remove") {
			in >> item;
                        out << "remove " << item << endl;
			hashTable.remove(item);
		}
		if (cmd == "find") {
			in >> item;
                        out << "find " << item << " " << boolalpha << hashTable.find(item) << endl;
		}
		if (cmd == "print") {
                        hashTable.print(out);			//pass out when writing to file
		}
	}

        out.close();

	return 0;
}

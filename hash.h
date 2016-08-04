#pragma once

#include"LinkedList.h"

#include<iostream>
#include<fstream>

using namespace std;

template <typename ItemType>

class HashSet {
private:

		LinkedList<ItemType>* table;
		int tableSize;
		int itemCount;

public:

//constructor
	HashSet<ItemType> () {
		table = NULL;
		this->tableSize = 0;			//this is used if a variable passing in a certain size is of the same name this will reference the objects variable
		this->itemCount = 0;
	}
//destructor
	~HashSet() { clear(); };

//hashCode function

	unsigned hashCode(const ItemType& s) {
		unsigned hashIndex = 0;
		for (int i = 0; i < s.length(); i++) {
			char c = s[i];
			int ascii = c;
			hashIndex = (hashIndex * 31) + ascii;
		}
		return hashIndex;
	}

//rehash larger function
	void rehashLarger() {
		int newTableSize = tableSize * 2 + 1;
		LinkedList<ItemType>* newHashTable = new LinkedList<ItemType>[newTableSize];
		unsigned index;																			// does this need to be unsigned?

		if (table != NULL) {
			for (int i = 0; i < tableSize; i++) {
				for (int j = 0; j < table[i].getSize(); j++) {
					index = hashCode(table[i].at(j));
					index = index % newTableSize;
					newHashTable[index].push_back(table[i].at(j));
				}
			}
		}
		rehashClear();
		tableSize = newTableSize;
		table = newHashTable;
	}

//rehash smaller function
	void rehashSmaller() {
		int newTableSize = tableSize / 2;
		LinkedList<ItemType>* newHashTable = new LinkedList<ItemType>[newTableSize];
		unsigned index;

		if (table != NULL) {
			for (int i = 0; i < tableSize; i++) {
				for (int j = 0; j < table[i].getSize(); j++) {
					index = hashCode(table[i].at(j));
					index = index % newTableSize;
					newHashTable[index].push_back(table[i].at(j));
				}
			}
		}
		rehashClear();
		tableSize = newTableSize;
		table = newHashTable;
	}

//add function
	void add(const ItemType& item) {
		
		if (!find(item)) {
			if (tableSize == itemCount) {
				rehashLarger();
			}
			unsigned index = hashCode(item);
			index = index % tableSize;
			table[index].push_back(item);
                        itemCount++;
		}
		else{
                    return;
                }
	}

//remove function
	void remove(const ItemType& item) {
		if (!find(item)) {
			return;
		}
		else {
			unsigned index = hashCode(item);
			index = index % tableSize;
			table[index].removeItem(item);
			itemCount--;

		}
		if (itemCount == tableSize / 2) {
			rehashSmaller();
		}
	}

//find function
	bool find(const ItemType& item) {
		if (table == NULL) {
			return false;
		}
		int index = hashCode(item);
		for (int i = 0; i < tableSize; i++) {
			if (table[i].find(item)) {
				return true;
			}
		}
		return false;
	}

//print function
	void print(ofstream& out) {
		int max = 8;
		out << "print" << endl;
		for (int i = 0; i < tableSize; i++) {
			out << "hash " << i << ":";
			for (int j = 0, k = 0; j < table[i].getSize(); j++, k++) {
				if (k == max) {
					k = 0;
					out << endl;
					out << "hash " << i << ":";
				}
				out << " " << table[i].at(j);			//item is in the node structure not linked list
			}
			out << endl;
		}
	}

//rehashClear
	void rehashClear() {
		delete[] table;
	}

//clear function
	void clear() {

		delete[] table;
		table = NULL;
		tableSize = 0;
		itemCount = 0;			

	}

};



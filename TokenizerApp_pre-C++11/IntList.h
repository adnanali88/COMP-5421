//pragma once
#ifndef IntList_H
#define IntList_H
#include <iostream>
using namespace std;


class IntList
{
	int* dynarray;
	int capacity;
	int used;
public:
	IntList();
	IntList(IntList& array);
	IntList(IntList&& array);
	IntList& operator =(const IntList& rhs);
	IntList& operator =(const IntList&& rhs);
	~IntList();
	bool empty();
	bool full();
	int size();
	void resize();
	void pushBack(int x);
	bool contains(int x);
	bool get(int position, int&value) const;
	int getCapacity();
	void print(ostream& sout);
	friend ostream& operator <<(ostream& out, const IntList& rhs);
};
#endif // !IntList_H

#include "IntList.h"



IntList::IntList()
{
	dynarray=new int[1];
	capacity=1;
	used=0;
}

IntList::IntList(IntList & array)
{
	capacity = array.capacity;
	used = array.used;
	dynarray = new int[capacity];
	for (int i = 0; i < used; i++)
	{
		dynarray[i] = array.dynarray[i];
	}
}

IntList::IntList(IntList && array)
{
	capacity = array.capacity;
	used = array.used;
	dynarray = new int[capacity];
	for (int i = 0; i < used; i++)
	{
		dynarray[i] = array.dynarray[i];
	}
}

IntList & IntList::operator=(const IntList & rhs)
{
	IntList lfs;
	lfs.capacity = rhs.capacity;
	lfs.used = rhs.used;
	lfs.dynarray = new int[lfs.capacity];
	for (int i = 0; i < lfs.capacity; i++)
	{
		int *a = new int(rhs.dynarray[i]);
		lfs.dynarray[i] = *a;
	}
	return lfs;
}

IntList & IntList::operator=(const IntList && rhs)
{
	IntList lfs;
	lfs.capacity = rhs.capacity;
	lfs.used = rhs.used;
	lfs.dynarray = new int[lfs.capacity];
	for (int i = 0; i < lfs.capacity; i++)
	{
		lfs.dynarray[i] = rhs.dynarray[i];
	}
	return lfs;
}

IntList::~IntList()
{
	delete [] (dynarray);
}

bool IntList::empty()
{
	if (used == 0)
		return true;
	return false;
}

bool IntList::full()
{
	if (used == capacity)
		return true;
	return false;
}

int IntList::size()
{
	return used;
}

void IntList::resize()
{
	capacity = capacity + capacity;
	int* newarray = new int[capacity];
	for (int i = 0; i < used; i++)
	{
		newarray[i] = dynarray[i];
	}
	dynarray = newarray;
}

void IntList::pushBack(int x)
{
	if (full())
	{
		resize();
	}
	dynarray[used] = x;
	used++;
}

bool IntList::contains(int x)
{
	for (int i = 0; i < used; i++)
	{
		if (dynarray[i] == x)
		{
			return true;
		}
	}
	return false;
}

bool IntList::get(int position, int & value) const
{
	if (position >= 0 && position < used)
	{
		value = dynarray[position];
		return true;
	}
	return false;
}

int IntList::getCapacity()
{
	return capacity;
}

void IntList::print(ostream & sout)
{
	for (int i = 0; i < used; i++)
	{
		sout << dynarray[i]<< "  ";
	}
}

ostream & operator<<(ostream & out, const IntList & rhs)
{
	for (int i = 0; i < rhs.used; i++)
	{
		out << rhs.dynarray[i] << "  ";
	}
	return out;
}

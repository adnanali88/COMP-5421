//#pragma once
#ifndef TOKEN_H
#define TOKEN_H
#include <cstring>
#include <cctype>
#include "IntList.h"
#include <ostream>
using namespace std;
using std::cout;
using std::endl;


class Token
{
	char* text;
	IntList number_list;
public:
	Token(const char* cstr, int line_num);
	Token();
	Token(const Token& token);
	Token(Token&& token);
	Token& operator=(const Token& rhs);
	Token& operator=(Token&& rhs);
	~Token();
	int compare(const Token& aToken);
	char* getText()const;
	void pushBackLineNumber(int line_num);
	int size();
	void print(ostream& sout); // check cout lecture_3 
	char getChar(int k)const;
	int getNum() const
	{
		int v;
		number_list.get(0, v);
		return v;
	}
	friend ostream& operator <<(ostream& out, const Token& rhs);

};
#endif // !TOKEN_H

#include "Token.h"
#include <cstring>
#include <cctype>
#include "IntList.h"
#include <ostream>
using namespace std;
using std::cout;
using std::endl;



Token::Token(const char * cstr, int line_num)
{
	int len = strlen(cstr);
	text = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		text[i] = tolower(cstr[i]);
	}
	text[len] = '\0';
	number_list = IntList();
	number_list.pushBack(line_num);
}

Token::Token()
{
	text = new char[100];
	strcpy(text," ") ;
	number_list = IntList();
}

Token::Token(const Token & token)
{
	text = new char[100];
	strcpy(text, token.text);
	number_list.pushBack(token.getNum());
}

Token::Token(Token && token)
{
	text = new char[100];
	strcpy(text, token.text);
	number_list = token.number_list;
}

Token & Token::operator=(const Token & rhs)
{
	Token lhs;
	strcpy(lhs.text, rhs.text);
	lhs.number_list = rhs.number_list;
	return lhs;
}

Token & Token::operator=(Token && rhs)
{
	Token lhs;
	strcpy(lhs.text, rhs.text);
	lhs.number_list = rhs.number_list;
	return lhs;
}


Token::~Token()
{
	delete[] (text);
}

int Token::compare(const Token & aToken)
{
	return strcmp(text,aToken.text);
}

char * Token::getText() const
{
	return text;
}

void Token::pushBackLineNumber(int line_num)
{
	number_list.pushBack(line_num);
}

int Token::size()
{
	return strlen(text);
}

void Token::print(ostream & sout)
{
	sout << text << ",  " << number_list;
}

char Token::getChar(int k) const
{
	if (k >= 0 && k < strlen(text))
		return text[k];
	return '\0';
}

ostream & operator<<(ostream & out, const Token & rhs)
{
	out << rhs.text << ",  " << rhs.number_list;
	return out;
}

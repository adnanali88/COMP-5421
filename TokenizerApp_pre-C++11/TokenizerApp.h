//#pragma once



#ifndef TOKENIZERAPP_H
#define TOKENIZERAPP_H
#include <ostream>

#include "TList.h"

class TokenizerApp
{
private:
	TList tokenList{};
public:
	void loadTokenList(const char* filename);
	TokenizerApp(const char* filename);
	void print(ostream& sout)const;
};

#endif //  !TOKENIZERAPP_H
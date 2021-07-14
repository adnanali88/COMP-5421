
#include <ostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <string>
#include "TList.h"
#include "TokenizerApp.h"

void TokenizerApp::loadTokenList(const char* filename)
{
	ifstream fin(filename);
	if (!fin)
	{
		cout << "could not open input file: " << filename << endl;
		exit(1);
	}
	int linenum = 0;
	string line;
	getline(fin, line);  // attempt to read a line
	while (fin)
	{
		++linenum;
		istringstream sin(line); // convert the line just read into an input stream
		string word;
		while (sin >> word)  // extract the tokens and add them to tokenList
		{
			//transform(word.begin(), word.end(), word.begin(), ::tolower);
			tokenList.addOrdered(Token(word.c_str(), linenum));
			//tokenList.addSorted(Token(word.c_str(), linenum));

		}
		getline(fin, line);
	}
	fin.close();
}

TokenizerApp::TokenizerApp(const char* filename)
{
	loadTokenList(filename);
}

void TokenizerApp::print(ostream& sout)const
{
	tokenList.print(sout);
}

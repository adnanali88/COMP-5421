//#pragma once
#ifndef Tokenizer_H
#define Tokenizer_H

#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

void ProcessTokensInLine(const string& line, size_t linenum);
std::vector <string> splitLineIntoTokens(const string& line);

#endif

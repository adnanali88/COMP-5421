#include "Token.h"
#include<iostream>
#include <vector>
using namespace std;
class Token{
private:
    string theText{}; // word
    vector<size_t> theLineNumbers{}; //found on which line
    size_t theFrequency{1}; // what is the frequency
public:
    Token(string text, size_t linenum){
        theText = text;
        theLineNumbers.push_back(linenum);
        theFrequency = 1;
    }
    Token(const Token &rhs){
        theText = rhs.theText;
        theLineNumbers = rhs.theLineNumbers;

    }
    ~Token(){
    }
    
    void setLinerNumber(size_t line){
        theLineNumbers.push_back(line);
    }
    void updateLineList(vector<size_t> lines){
        theLineNumbers = lines;
    }
    vector<size_t> getLinerNumber(){
        return theLineNumbers;
    }
    
    void setFrequency(size_t frequency){
        theFrequency = frequency;
    }
    size_t getFrequency(){
        return theFrequency;
    }
    
    void setText(string text){
        theText = text;
    }
    string getText(){
        return theText;
    }
    
    
};




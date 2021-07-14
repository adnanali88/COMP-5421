#include "Token.h"
#include <iostream>
#include<list>
#include<vector>
#include <fstream>
#include <string>
#include <algorithm>
#include "Token.cpp"
#include<string.h>
using namespace std;


class Tokenizer
{
private:
    const string theSeparators;
    list<Token> theTokenList;
    vector<string> theLines;
    string fileLocation;

public:
    Tokenizer(const string& filename, const string& separators) {
        fileLocation = filename;    //read the file from location
        string myText;
        size_t lineNumber = 1;
        ifstream MyReadFile(filename);

        while (getline(MyReadFile, myText)) {
            ProcessTokensInLine(myText, lineNumber);
            lineNumber++;

        }
        MyReadFile.close();

    }
    ~Tokenizer() {
    }
private:
    void ProcessTokensInLine(const string& line, size_t linenum) {
        vector<string> tokens;
        tokens = splitLineIntoTokens(line);
        for (int i = 0; i < tokens.size(); i++) {
            string word = removeSpecialCharacter(tokens[i]);
            Token t(word, linenum);

            if (isTokenInList(t)) {
                updateItem(t);

            }
            else {
                theTokenList.push_back(t);
            }

        }
    }
    vector<string> splitLineIntoTokens(const string& line) {

        vector<string> tokens;
        int first = 0;
        while (first < line.size()) {
            int second = line.find_first_of(' ', first);
            if (second == std::string::npos) {
                second = line.size();
            }
            std::string token = line.substr(first, second - first);
            tokens.push_back(token);
            first = second + 1;
        }
        return tokens;

    }
    bool isTokenInList(Token t) {
        bool check = false;
        for (auto it = theTokenList.begin(); it != theTokenList.end(); ++it) {
            if (toLowerCase(it->getText()) == toLowerCase(t.getText())) {
                check = true;
                break;
            }
            else {
                check = false;
            }
        }
        return check;
    }
    void updateItem(Token t) {
        for (auto it = theTokenList.rbegin(); it != theTokenList.rend(); ++it) {
            if (toLowerCase(it->getText()) == toLowerCase(t.getText())) {

                size_t lastIndex = it->getLinerNumber()[it->getLinerNumber().size() - 1];
                size_t itemIndex = t.getLinerNumber()[t.getLinerNumber().size() - 1];
                if (lastIndex == itemIndex) {

                    it->setFrequency(it->getFrequency() + 1);
                }
                else {
                    it->setLinerNumber(t.getLinerNumber()[0]);
                    it->setFrequency(it->getFrequency() + 1);
                }
                return;
            }
        }
    }
    string removeSpecialCharacter(string s) {
        for (int i = 0; i < s.size(); i++) {
            if ((s[i] < 'A' || s[i] > 'Z') &&
                (s[i] < 'a' || s[i] > 'z'))
            {

                s.erase(i, 1);
                i--;
            }
        }
        return s;
    }


public:
    void showTokens() {
        cout << "\n";
        for (auto it = theTokenList.begin(); it != theTokenList.end(); ++it) {
            if (it->getText().length() == 0) {
                continue;
            }
            cout << "     " << it->getText() << " (" << it->getFrequency() << ") ";
            for (int i = 0; i < it->getLinerNumber().size(); i++) {
                cout << it->getLinerNumber()[i] << " ";
            }
            cout << endl;
        }
    }
    void showAllLines() {
        cout << "\n";
        string myText;
        ifstream MyReadFile(fileLocation);
        while (getline(MyReadFile, myText)) {
            cout << "     " << myText;

        }
        MyReadFile.close();
    }
    void sortOnFrequency() {
        list<Token> sortedList;
        sortedList.assign(theTokenList.begin(), theTokenList.end());
        for (auto i = sortedList.begin(); i != sortedList.end(); ++i) {
            for (auto j = sortedList.begin(); j != sortedList.end(); ++j) {
                if (i->getLinerNumber().size() < j->getLinerNumber().size()) {

                    string iText = i->getText();
                    vector<size_t> iLineNumber = i->getLinerNumber();

                    string jText = j->getText();
                    vector<size_t> jLineNumber = j->getLinerNumber();

                    // setting values
                    i->setText(jText);
                    j->setText(iText);

                    i->setFrequency(jLineNumber.size());
                    j->setFrequency(iLineNumber.size());

                    i->updateLineList(jLineNumber);
                    j->updateLineList(iLineNumber);

                }
            }
        }


        // show the sorted data
        for (auto it = sortedList.begin(); it != sortedList.end(); ++it) {
            if (it->getText().length() == 0) {
                continue;
            }
            cout << "     " << it->getText() << " (" << it->getFrequency() << ") ";
            for (int i = 0; i < it->getLinerNumber().size(); i++) {
                cout << it->getLinerNumber()[i] << " ";
            }
            cout << endl;
        }

    }
    void sortOnLength() {
        list<Token> sortedList;
        sortedList.assign(theTokenList.begin(), theTokenList.end());
        for (auto i = sortedList.begin(); i != sortedList.end(); ++i) {
            for (auto j = sortedList.begin(); j != sortedList.end(); ++j) {
                if (i->getText().length() < j->getText().length()) {

                    string iText = i->getText();
                    vector<size_t> iLineNumber = i->getLinerNumber();

                    string jText = j->getText();
                    vector<size_t> jLineNumber = j->getLinerNumber();

                    // setting values
                    i->setText(jText);
                    j->setText(iText);

                    i->setFrequency(jLineNumber.size());
                    j->setFrequency(iLineNumber.size());

                    i->updateLineList(jLineNumber);
                    j->updateLineList(iLineNumber);

                }

                if (i->getText().length() == j->getText().length() && i->getText() != j->getText()) {
                    if (strcmp(i->getText().c_str(), j->getText().c_str()) < 0) {
                        string iText = i->getText();
                        vector<size_t> iLineNumber = i->getLinerNumber();

                        string jText = j->getText();
                        vector<size_t> jLineNumber = j->getLinerNumber();

                        // setting values
                        i->setText(jText);
                        j->setText(iText);

                        i->setFrequency(jLineNumber.size());
                        j->setFrequency(iLineNumber.size());

                        i->updateLineList(jLineNumber);
                        j->updateLineList(iLineNumber);
                    }
                }
            }

        }


        // show the sorted data
        for (auto it = sortedList.begin(); it != sortedList.end(); ++it) {
            if (it->getText().length() == 0) {
                continue;
            }
            cout << "     " << it->getText() << " (" << it->getFrequency() << ") ";
            for (int i = 0; i < it->getLinerNumber().size(); i++) {
                cout << it->getLinerNumber()[i] << " ";
            }
            cout << endl;
        }


    }
    void searchWord(string word) {
        cout << "\n";
        string myText;
        ifstream MyReadFile(fileLocation);
        int count = 1;
        int checkcount = 0;
        while (getline(MyReadFile, myText)) {
            if (myText.find(word) != std::string::npos) {
                std::cout << "     " << count << ": " << myText;
                checkcount++;
            }
            count++;
        }
        MyReadFile.close();
        if (checkcount == 0) {
            cout << "     " << "WORD NOT FOUND\n";
        }
        cout << endl;
    }
    string toLowerCase(string data) {
        for_each(data.begin(), data.end(), [](char& c) {
            c = ::tolower(c);
            });
        return data;
    }

};

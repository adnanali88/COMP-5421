#include<iostream>
#include "Tokenizer.cpp"
#include "Tokenizer.h"
using namespace std;
#include <fstream>
bool isLocationExist(string fileLocation){
    bool check;
    ifstream ifile;
       ifile.open(fileLocation);
       if(ifile) {
           check = true;
       } else {
           check = false;
       }
    return  check;
}
int main(){

    string fileLocation;
    string seprator;
    //"C:\Users\rizwa\OneDrive\Desktop\Concordia Courses\COMP 5421 - Advanced Programming\Assignments\A2\custom string tokenizer\custom string tokenizer\input_text_file.txt"
    //"C:\Users\rizwa\OneDrive\Desktop\Concordia Courses\COMP 5421 - Advanced Programming\Assignments\A1\A1_40181614\input_file_A1.txt"
    
    //Project > Properties > Linker > System > Subsystem > Set to console
    //getting file location 
    while (true) {
        cout<<"Enter the name of the input file of text: ";
        std::getline(std::cin, fileLocation);
        if(isLocationExist(fileLocation)){
            break;
        }else{
            cout<<"INVALID FILE LOCATION\n";
        }
    }
    cout<<"Enter the seprator character: ";
    std::getline(std::cin, seprator);
    
    
    
    while (true) {
        string choice;
        Tokenizer t(fileLocation,seprator);
        cout<<"\n     MENUE\n    =======\n";
        cout<<"     A - Print all input lines\n";
        cout<<"     P - Print indexed tokens\n";
        cout<<"     F - Print tokens sorted on frequency\n";
        cout<<"     L - Print tokens sorted on length\n";
        cout<<"     S - Search\n";
        cout<<"     X - Exit\n";
        cout<<"     Enter your choice: ";
        cin>>choice;
        if(t.toLowerCase(choice) == "a"){
            t.showAllLines();
        } else if (t.toLowerCase(choice) == "p"){
            t.showTokens();
        }else if (t.toLowerCase(choice) == "f"){
            t.sortOnFrequency();
        }else if (t.toLowerCase(choice) == "l"){
            t.sortOnLength();
        }else if (t.toLowerCase(choice) == "s"){
            string word;
            cout<<"     Enter the word for search: ";
            cin>>word;
            t.searchWord(word);
        }
        else if (t.toLowerCase(choice) == "x"){
            cout << "     Thank you for trying my program, Goodbye ";
            exit(0);
        }else{
            cout<<"INVALID ENTRY\n";
        }
        
        
    }
    
    return 0;
}




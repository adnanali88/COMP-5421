
#include<iostream> 
#include<cassert> 
#include "TokenizerApp.h"
using std::cout;
using std::endl;
int main()
{
	const char * filename = "input_file_A1.txt"; //C:\Users\rizwa\OneDrive\Desktop\Concordia Courses\COMP 5421 - Advanced Programming\Assignments\A1\\input_file_A1.txt
	TokenizerApp app(filename);
	app.print(cout);
	cout << endl;

	char x;
	cin >> x; //Just to open terminal
	return 0;
}
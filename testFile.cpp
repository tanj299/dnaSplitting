#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main () {

	// test add char in every index of string
	string test = "foxy"; 
	string addChar = "";
  	//string tempString = ""; 
  	stringstream ss; 
  	int position = 0; 
  	for(int i = 0; i < test.length() + 1; i++) {
	  	for(char k = 97; k <= 122; k++) { 
	      //char temp = k;
	      //cout << k << endl;
	      string tempString(1, k);
	      //cout << tempString << endl;
	      test.insert(i, tempString);
	      cout << test << endl;
	      tempString = "";
	      test = "foxy";
	    }
	}

	/*string newstring; 
	char temp2 = 101;
	string newstring(1, temp2);
	//ss >> newstring; 
	cout << newstring << endl;*/
}


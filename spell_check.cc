// Name: Jayson Tan 
// Course: CSCI 335
// Instructor: Ioannis Stamos 
// Term: Spring 2019 
// Assignment: Assignment 3 
// External Source Code Used: N/A 
// SN: Student Notes 

#include "quadratic_probing.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// @param: strings with punctuation attached to it
// @return: string without punctuation
// ex: don't -> dont | hello. -> hello 
string stripPunctuation(string &docWords) { 
  string checkWord = ""; 
  for(size_t i = 0; i < docWords.length(); i++) {
    if(isalnum(docWords[i])) {
      checkWord += docWords[i];
    }
  }
  // used std::transform to change string to lowercase
  std::transform(checkWord.begin(), checkWord.end(), checkWord.begin(), ::tolower); 
  return checkWord;  
}


// test function for hashtable 
template <typename HashTableType>
void TestFunctionForHashTable(HashTableType &hash_table, const string &words_filename, const string &query_filename) { 
  cout << "TestFunctionForHashTable..." << endl;
  cout << "Words filename: " << words_filename << endl;
  cout << "Query filename: " << query_filename << endl;
  hash_table.MakeEmpty();  
  cout << endl;

  // initialize input stream to store strings in words_filename into hash table - for dictionary
  ifstream documentFileIn;
  documentFileIn.open(words_filename);
  if (documentFileIn.fail()) {
    cerr << "Cannot read from " << words_filename << endl;
    exit(1);
  }

  
  int itemCount = 0; 
  string wordsInFile; 

  // insert words into hashtable 
  while(getline(documentFileIn, wordsInFile)) {
    if(hash_table.Insert(wordsInFile)) {
      itemCount++; 
    }
  }
  //cout << itemCount << endl; 

  // initialize input stream to store strings in words_filename into hash table - for document to check for words against 
  ifstream queryStream; 
  queryStream.open(query_filename);
  if (queryStream.fail()) {
    cerr << "Cannot read from " << query_filename << endl;
    exit(1);
  }

  // @pre: read words in from document
  // @param: correct punctation from words and push to vector
  // @post: vector is filled with words from document 
  vector<string> listOfDocWords;
  string queryWords; 
  while(queryStream >> queryWords) {
    listOfDocWords.push_back(stripPunctuation(queryWords));
  }

  vector<string> misspelledList; 
  // output misspelled words - ignores `i` since it's a correct word and there are too many instances 
  // @post: misspelled words are placed in vector 
  for(vector<string>::iterator itr = listOfDocWords.begin(); itr != listOfDocWords.end(); ++itr) {
    if(hash_table.Contains(*itr) == false && *itr != "i") {
      misspelledList.push_back(*itr);
    }
  }

  
  /******************************************************************************************************************
  add character in every position of a string 
  ******************************************************************************************************************/
  
  // triple for loop 
  // 1) size of vector 
  // 2) every character's place in word 
  // 3) every character in alphabet
  // use string::insert to place character in between string
  string addChar = "";
  cout << "// ADD A CHARACTER IN EACH INDEX" << endl;
  for(size_t i = 0; i < misspelledList.size(); i++) {
    addChar = misspelledList[i]; 
    string addQuery = addChar; 
    for(size_t position = 0; position < addChar.length() + 1; position++) {
      for(char k = 97; k < 123; k++) { 
        string tempString(1, k);
        // method to insert a string into an index another string
        // ex: foxy.insert(0, "the") will insert "the" into the 0th position of foxy, returning "thefoxy"
        addQuery.insert(position, tempString);
        if(hash_table.Contains(addQuery)) {
          cout << "Misspelled word: " << addChar << " | Corrected word: " << addQuery << endl;
          tempString = ""; 
          addQuery = addChar; 
        }
        else {
          addChar = misspelledList[i];
          tempString = ""; 
          addQuery = addChar;  
        }
      }
    }
  }
  cout << endl;

  /******************************************************************************************************************
  remove character in a position of a string 
  ******************************************************************************************************************/
    
  string removeChar = ""; 

  cout << "// REMOVE A CHARACTER IN EACH INDEX" << endl;
  for(size_t i = 0; i < misspelledList.size(); i++) {
    removeChar = misspelledList[i]; 
    string removeQuery = removeChar; 
    for(size_t position = 0; position < removeChar.length(); position++) {
      removeQuery = removeQuery.erase(position, 1);
      if(hash_table.Contains(removeQuery)) {
        cout << "Misspelled word: " << removeChar << " | Corrected word: " << removeQuery << endl;
      }      
      removeQuery = removeChar;
    }
  }

  cout << endl;
  /******************************************************************************************************************
  swap character positions of a string 
  ******************************************************************************************************************/
  
  string swapChar = ""; 

  cout << "// SWAP CHARACTERS IN EACH INDEX" << endl;
  for(size_t i = 0; i < misspelledList.size(); i++) {
    swapChar = misspelledList[i]; 
    string swapQuery = swapChar; 
    for(size_t position = 0; position < removeChar.length(); position++) {
      swap(swapQuery[position], swapQuery[position+1]);
      if(hash_table.Contains(swapQuery)) {
        cout << "Misspelled word: " << swapChar << " | Corrected word: " << swapQuery << endl;
      }      
      swapQuery = swapChar;
    }
  }

}


// Sample main for program spell_check
int main(int argc, char **argv) {
  if (argc != 3) {
    cout << "Usage: " << argv[0] << " <document-file> <dictionary-file>" << endl;
    return 0;
  }
  
  const string document_filename(argv[1]);
  const string dictionary_filename(argv[2]);
  
  cout << "Input document filename is " << document_filename << endl;
  cout << "Input dictionary filename is " << dictionary_filename << endl;

  // Call functions implementing the assignment requirements.
  ifstream documentFile;
  documentFile.open(document_filename);
  if(documentFile.fail()) {
    cerr << "Cannot read from: " << document_filename << endl;
    exit(1);
  }

  // hash words from document - begin spell check
  HashTable<string> quadratic_probing_table; 
  TestFunctionForHashTable(quadratic_probing_table, dictionary_filename, document_filename); 

  return 0;
}


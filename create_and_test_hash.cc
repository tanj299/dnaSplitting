// Name: Jayson Tan 
// Course: CSCI 335
// Instructor: Ioannis Stamos 
// Term: Spring 2019 
// Assignment: Assignment 3 
// External Source Code Used: N/A 
// SN: Student Notes 

#include "linear_probing.h"
#include "quadratic_probing.h"
#include "double_probing.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


template <typename HashTableType>
void TestFunctionForHashTable(HashTableType &hash_table, const string &words_filename, const string &query_filename) { 

  cout << "TestFunctionForHashTables..." << endl;
  cout << "Words filename: " << words_filename << endl;
  cout << "Query filename: " << query_filename << endl;
  hash_table.MakeEmpty();  

  // initialize input stream to store strings in words_filename into hash table 
  ifstream wordIn;
  wordIn.open(words_filename);
  if (wordIn.fail()) {
    cerr << "Cannot read from " << words_filename << endl;
    exit(1);
  }

  int itemCount = 0; 
  string wordsInFile; 

  // insert words into hashtable 
  while(getline(wordIn, wordsInFile)) {
    if(hash_table.Insert(wordsInFile) == true) {
      itemCount++;
    } 
  }
  
  // calculate the math for collisions and load factor 
  int countCollisions = hash_table.countCollisions();
  float loadFactor = (float)itemCount/ (float)hash_table.getArraySize();
  float avgCollisions = (float) countCollisions / float(itemCount);

  // Part A
  cout << "Collisions: " << countCollisions << endl;
  cout << "Number of items: " << itemCount << endl;
  cout << "Size of hash table: " << hash_table.getArraySize() << endl;
  cout << "Load factor: " << loadFactor << endl;
  cout << "Avg. number of collisions: " << avgCollisions << endl;

  // Part B
  ifstream queryStream; 
  queryStream.open(query_filename);
  if (queryStream.fail()) {
    cerr << "Cannot read from " << query_filename << endl;
    exit(1);
   }
  
  // calculate probe count 
  string queryStrings; 
  while(getline(queryStream, queryStrings)) {
    if(hash_table.Contains(queryStrings) == true) {
      cout << queryStrings << ": Found" << " | Number of Probes: " << hash_table.getProbeCount()<< endl;
      hash_table.resetProbeCount();
    }

    else {
      cout << queryStrings << ": Not Found" << " | Number of Probes: " << hash_table.getProbeCount() << endl;
      hash_table.resetProbeCount();
    }
  }
}

// Sample main for program create_and_test_hash 
int main(int argc, char **argv) {
  if (argc != 4) {
    cout << "Usage: " << argv[0] << " <words_filename> <query_filename> <flag>" << endl;
    return 0;
  }
  
  const string words_filename(argv[1]);
  const string query_filename(argv[2]);
  const string param_flag(argv[3]);

  if (param_flag == "linear") {
    HashTableLinear<string> linear_probing_table;
    TestFunctionForHashTable(linear_probing_table, words_filename, query_filename);    
  } else if (param_flag == "quadratic") {
    HashTable<string> quadratic_probing_table;
    TestFunctionForHashTable(quadratic_probing_table, words_filename, query_filename);    
  } else if (param_flag == "double") {
    HashTableDouble<string> double_probing_table;
    TestFunctionForHashTable(double_probing_table, words_filename, query_filename);    
  } else {
    cout << "Unknown tree type " << param_flag << " (User should provide linear, quadratic, or double)" << endl;
  }
  return 0;
}

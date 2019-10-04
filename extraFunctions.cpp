  // if i wanted to be lazy and only spell check words with punctuation at the end of a string 

  /*
  // check if the word's last char is a char, since it can be a punctuation mark
  if(isalpha(docWords[docWords.length()-1])) {
    listOfDocWords.push_back(docWords);
  }

  else {
    // if the word's last char is a punctuation, delete it and push only the words up to the word
    // ex: 
    listOfDocWords.push_back(docWords.substr(0, docWords.length()-1));
  }*/

/*
  string docWords; 
  while(documentFile >> docWords) {
    string checkWord = ""; 
    for(size_t i = 0; i < docWords.length(); i++) {
      if(isalpha(docWords[i])) {
        checkWord += docWords[i];
      }
    }
    // used std::transform to change string to lowercase
    std::transform(checkWord.begin(), checkWord.end(), checkWord.begin(), ::tolower);
    listOfDocWords.push_back(checkWord);  
  }*/
  

  /*
  // iterates through vector and make sure everything is in there correctly
  for(vector<string>::iterator itr = listOfDocWords.begin(); itr != listOfDocWords.end(); ++itr) {
    cout << *itr << endl;
  }*/

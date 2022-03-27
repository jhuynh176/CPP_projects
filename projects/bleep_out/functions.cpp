//header declaration
#include "functions.hpp"

//library 
#include <iostream>
#include <string>

void bleep(std::string word, std::string &text) {
  for(int i = 0; i < text.size(); i++){
    int count = 0;

    for(int j = 0; j < word.size(); j++){
      if(std::tolower(text[i + j]) == word[j]) count++;
    }

    if(count == word.size()) {
      replace(word, text, i);
    }
  }
  std::cout << "\n" << text << std::endl;
}

void replace(std::string word, std::string &text, int &i) {

  for(int j = 0; j < word.size(); j++) {
    text[i + j] = '*';
  }

  i += word.size();
}

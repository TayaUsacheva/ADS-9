// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

bool isLetter(char ch){
    if(ch >= 'a' && ch <= 'z')
        return ch;
    else if (ch >= 'A' && ch <= 'Z')
        return tolower(ch);
}

BST<std::string> makeTree(const char* filename) {
  BST <std::string> tree;
  std::ifstream file(filename);
  if (!file) {
    std::cout << "File error!" << std::endl;
    return tree;
  } else {
     while (!file.eof()) {
     std::string temp = "";
     while (true) {
       char c;
       c = file.get();
       if (isLetter(ch))
         temp += ch;
        else {
            break;
        }
    }
        tree.add(temp);
    }
        return tree;
    }
}

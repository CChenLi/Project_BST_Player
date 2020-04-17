#include <iostream>
#include <fstream>
#include <string>
#include "utility.h"
#include "cards.h"
using namespace std;

int main(int argv, char** argc){
  if(argv < 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail() || cardFile2.fail() ){
    cout << "Could not open file " << argc[2];
    return 1;
  }
  BSTplayer p1("Alice");
  BSTplayer p2("Bob");

  //Read each file
  while (getline (cardFile1, line) && (line.length() > 0)){
  		card c(line);
  		p1.insert(c);
  }
  cardFile1.close();


  while (getline (cardFile2, line) && (line.length() > 0)){
  		card c(line);
  		p2.insert(c);
  }
  cardFile2.close();

  gameStart(p1, p2);
  return 0;
}

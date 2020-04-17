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
  card c1("c a");
  card c2("h 9");
  card c18("c 3");
  card c3("s q");
  card c4("c 4");
  card c5("s 10");
  card c6("c 7");
  card c7("s 8");
  card c8("c 8");
  card c9("s 5");
  card c0("d 2");
  card c11("s 3");
  card c12("d 3");
  card c13("s 2");
  card c14("d 5");
  card c15("d k");  
  card c16("d 9");
  card c17("d j");





  p1.deleteCard(c1);
  p1.deleteCard(c2);
  p1.deleteCard(c18);
  p1.deleteCard(c3);
  p1.deleteCard(c4);
  p1.deleteCard(c5);
  p1.deleteCard(c6);
  p1.deleteCard(c7);
  p1.deleteCard(c8);
  p1.deleteCard(c9);
  p1.deleteCard(c0);
  p1.deleteCard(c11);
  p1.deleteCard(c12);
  p1.deleteCard(c13);
  p1.deleteCard(c14);
  p1.deleteCard(c15);
  p1.deleteCard(c16);
  p1.deleteCard(c17);
  //p1.deleteCard(c18);
  p1.printPreorder("\n");
 // p1.printInorder("\n");




  return 0;
}










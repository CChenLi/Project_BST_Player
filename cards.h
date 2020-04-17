//cards.h
//Chen Li
//All class declarations go here
// CLASS PROVIDED: BSTplayer
//   (a class to keep card player's name and cards in hand and some 
//		opeartions)
//
// CONSTRUCTOR 
//  BSTplayer(string name);
//     Postcondition: The object has been initialized, and is ready to accept
//     a sequence of cards. 
//
// PUBLIC MODIFICATION member functions for the Player class:
//	bool insert(card c);
//		insert c to BSTplayer, if duplicated reuturn false, return true otherwise.
//	void deleteCard(card n);
//		precondiction: card c exist in BSTplayer;
//		postcondition: card c gets deleted from BSTplayer, while the BST property holds.
//
// NON-MEMBER functions for the Player class:
//	void gameStart(BSTplayer& p1, BSTplayer& p2);
//		start the game between p1 and p2, show result on terminal
//
// PUBLIC CONSTANT member functions for the Player class:
//	card precessor(card c) const;
//		return the precessor of c
//	card successor(card c) const;
//		return the successor of c
//	printInorder(string s) const;
//		inorder print all cards with seperated by s in between.


#ifndef CARDS_H
#define CARDS_H
#include "utility.h"
using namespace std;


class card;
class BSTplayer{
private:
	card* root;
	string name;

	bool insertHelper(card c, card* now);
	void printInorderHelper(card* c, string s) const;
	void printPreorderHelper(card* c, string s) const;//------------
	card* precessorNode(card c) const;
	card* successorNode(card c) const;
	void clear(card* c);
	card* searchHelper(card c, card* now) const;//this is find().
	card* search(card c);
	card* runInorder(const BSTplayer& rival, card* n);
	card* runBack(const BSTplayer& rival, card* n);


public:
	
	BSTplayer(string n); //constrcutor
	~BSTplayer(); //destructor
	void deleteCard(card n);
	bool find(card c);
	bool insert(card c);
	card precessor(card c) const;
	card successor(card c) const;
	void printInorder(string s) const;
	friend void gameStart(BSTplayer& p1, BSTplayer& p2);
	void printPreorder(string s) const;//-----------
};











#endif

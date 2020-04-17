//cards.cpp
//Authors: Your name and your partner's name
//Implementation of the classes defined in cards.h

#include <iostream>
#include "cards.h"
using namespace std;


//functions for BSTplayer

BSTplayer::BSTplayer(string n){
	name = n;
	root = 0;
}

BSTplayer::~BSTplayer(){
	clear(root);
	root = 0;
}

void BSTplayer::clear(card* c){
	if(c){
		clear(c->left);
		clear(c->right);
		delete c;
	}
}

bool BSTplayer::insertHelper(card c, card* now){	
	if(c == *now){
		return 0;
	} 
	if(c < *now){
		if(now->left){
			return insertHelper(c, now->left);
		} else{
			now->left = new card(c);
			now->left->parent = now;
			return 1;
		}	
	}else{
		if(now->right){
			return insertHelper(c, now->right);
		} else {
			now->right = new card(c);
			now->right->parent = now;
			return 1;
		}
	}
}

bool BSTplayer::insert(card c){
	if(!root){
		root = new card(c);
		return 1;
	} else {
		return insertHelper(c, root);
	}
}

card* BSTplayer::searchHelper(card c, card* now) const{
	if(!now) return NULL;
	if(c == *now){
		return now;
	}
	if(c < *now){
		return(searchHelper(c, now->left));
	} else return(searchHelper(c, now->right));	
}

card* BSTplayer::precessorNode(card c) const{
	card* n = searchHelper(c, root);
	if(n->left) {
		n = n->left;
		while(n->right){
			n = n->right;
		}
		return n;
	} else {
		while(1){
			if(*n < c){
				return n;
			} else if(n->parent){
				n = n->parent;
			} else return NULL;
		}
	}
	
}

card BSTplayer::precessor(card c) const{
	card* n = precessorNode(c);
	if(!n){
		card newcard("0 0");
		return newcard;
	} else{
		card newcard(*n);
		return newcard;
	}
}

card* BSTplayer::successorNode(card c) const{
	card* n = searchHelper(c, root);
	if(n->right){
		n=n->right;
		while(n->left){
			n=n->left;
		}
		return n;
	} else{
		while(c > *n || c == *n){
			if(n->parent){
				n=n->parent;
			} else return NULL;
		}
		return n;
	}
}

card BSTplayer::successor(card c) const{
	card* n = successorNode(c);
	if(!n){
		card newcard("0 0");
		return newcard;
	} else{
		card newcard(*n);
		return newcard;
	}
}

void BSTplayer::deleteCard(card c){
	card* n = searchHelper(c, root);
	if(n){
		card* p = n->parent;
		card* l = n->left;
		card* r = n->right;

		if(!l&&!r){
			if(!p){
				root = 0;
			} else if(n==p->left){
				p->left = 0;
			} else{
				p->right = 0;
			}
			delete n;
		}

		else if(l&&r){
			card s = successor(c);
			deleteCard(s);
			*n = s;
		}

		else{
			card* child = l;
			if(r) child = r;
			if(!p){
				root = child;
			} else if(n==p->left){
				p->left = child;
			} else {
				p->right = child;
			}
		
		child->parent = p;
		delete n;
		}
}}

	/*
	card* n = searchHelper(c, root);
	if(n->parent&&!n->left&&!n->right){
	//	cout << * n<< " case 1 " << endl;//----------
		if(n==n->parent->right){
			n->parent->right=0;
		} else {
			n->parent->left=0;
		}
		delete n;
		return;
	}
	if(n->parent&&!n->right){
		//cout << *n<< " case 2 " << endl;//-------------
		if(n==n->parent->right){
			n->parent->right=n->left;
			n->left->parent=n->parent;
		} else {
			n->parent->left=n->left;
			n->left->parent=n->parent;
		}
		delete n;
		return;
	}
	if(n->parent&&!n->left){
	//	cout << *n << " case 3 " << endl;//-------------
		if(n==n->parent->right){
			n->parent->right=n->right;
			n->right->parent=n->parent;
		} else {
			n->parent->left=n->right;
			n->right->parent=n->parent;
		}
		delete n;
		return;
	}
	if(n->left&&n->right){
	//	cout << *n <<" case 4 ";//-----------
		card succ = successor(c);
		card tem = succ;
		deleteCard(succ);
		*n = tem;
		return;
	}
	if(!n->parent&&!n->left){
		//cout << *n <<" case 5 "<< endl;//---------
		root = n->right;
		delete n;
	}
	if(!n->parent&&!n->right){
		//cout << *n <<" case 5 "<< endl;//---------
		root = n->left;
		delete n;
	}
}
*/
card* BSTplayer::search(card c){
	return searchHelper(c, root);
}

void BSTplayer::printInorderHelper(card* c, string s) const{
	if(c){
		printInorderHelper(c->left, s);
		cout << *c << s;
		printInorderHelper(c->right, s);
	} else return;
}

void BSTplayer::printInorder(string s) const{
	cout << name << "'s cards:" << s;
	printInorderHelper(root, s);
}

void BSTplayer::printPreorderHelper(card* c, string s) const{//-----------------
	if(c){
		cout << *c << s;
		printPreorderHelper(c->left, s);
		printPreorderHelper(c->right, s);
	} else return;
}

void BSTplayer::printPreorder(string s) const{//---------------
	cout << name << "'s cards preorder:" << s;
	printPreorderHelper(root, s);
}

card* BSTplayer::runInorder(const BSTplayer& rival, card* n){
	if(!n) return NULL;
	else{
		card* left = runInorder(rival, n->left);
		if(left) return left;
		card* now = rival.searchHelper(*n, rival.root);
		if(now) return now;
		card* right = runInorder(rival, n->right);
		if(right) return right;
		return NULL;
	}
}


card* BSTplayer::runBack(const BSTplayer& rival, card* n){
	if(!n) return NULL;
	else{
		card* right = runBack(rival, n->right);
		if(right) return right;
		card* now = rival.searchHelper(*n, rival.root);
		if(now) return now;
		card* left = runBack(rival, n->left);
		if(left) return left;
		return NULL;
	}
}

void gameStart(BSTplayer& p1, BSTplayer& p2){
	card* now = 0;
  	while(1){
  	now = p1.runInorder(p2, p1.root);
  	if(now){
  		cout << p1.name <<" picked matching card " << *now << endl;
  		card k = *now;
  		p1.deleteCard(k);
  		p2.deleteCard(k);
  	} else {
  		break;
  	}
  	now = p2.runBack(p1, p2.root);
  	if(now){
  		cout << p2.name <<" picked matching card " << *now << endl;
  		card k = *now;
  		p1.deleteCard(k);
  		p2.deleteCard(k);
  	} else {
  		break;
  	}
  }
  cout << endl;
  p1.printInorder("\n");
  cout << endl;
  p2.printInorder("\n");
}

bool BSTplayer::find(card c){
	return true;//stub
}























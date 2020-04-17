#include <iostream>
#include "utility.h"
#include "cards.h"
using namespace std;

void assert_equal(bool expression, string message){
	if(expression){
		cout << "PASSED" << endl;
	} else{
		cout << "	FAILED case " << message << endl;
	}
}

void test_equal(){
	cout << "---------equal----------" << endl;
	card c1("h 9");
	card c2("h 9");
	card c3("s 3");
	card c4("s 3");
	card c5("d 3");
	card c6("d 3");

	assert_equal(c1==c2, "c1, c2");
	assert_equal(c3==c4, "c3, c4");
	assert_equal(c5==c6, "c5, c6");
	assert_equal(!(c1==c3), "c1, c3");
	assert_equal(!(c2==c3), "c2, c3");
	assert_equal(c1==c1, "c1, c1");
}

void test_less(){
	cout << "---------less----------" << endl;
	card c1("c 1");
	card c2("c 10");
	card c3("c q");
	card c4("h 1");
	card c5("h 2");
	card c6("h j");
	assert_equal((c1<c2), "ca, ck");
	assert_equal((c2<c3), "ck, d3");
	assert_equal((c3<c4), "d3, s3");
	assert_equal((c1<c4), "h9, hj");
	assert_equal((c5<c6), "ca, s3");
}

void test_larger(){
	cout << "---------larger----------" << endl;
	card c1("c 1");
	card c2("c 2");
	card c3("c 10");
	card c4("h 1");
	card c5("h 2");
	card c6("h j");
	assert_equal((c6>c5), "c6, c5");
	assert_equal((c5>c4), "c5, c4");
	assert_equal((c4>c1), "c4, c1");
	assert_equal((c3>c2), "c3, c2");
	assert_equal((c2>c1), "c2, c1");
}

//--------------------BSTplayer----------------------

void usePrecessor(const BSTplayer& p ,card c){
	cout << "Precessor of " << c.name << ": " << p.precessor(c)<< endl;
}

void useSuccessor(const BSTplayer& p, card c){
	cout << "Successor of " << c.name << ": " << p.successor(c)<< endl;
}

void usedelete(BSTplayer& p, card c){
	cout << "delete card: " << c.name << endl;
	p.deleteCard(c);
}

void test_ips(){
	cout << "---insert---precessor---successor---" << endl;
	card c1("c 10");
	card c2("h 2");
	card c3("c 9");
	card c4("d 1");
	card c5("s 2");
	card c6("h j");
	BSTplayer p1("Alice");
	p1.insert(c1);
	p1.insert(c2);
	p1.insert(c3);
	p1.insert(c4);
	p1.insert(c5);
	p1.insert(c6);
	cout << "Cards inserted:   c 1, h 2, c 10, c 1, c 2, h j," << endl;
	cout << "Printed in-order: ";
	p1.printInorder(", "); cout << endl;
	usePrecessor(p1, c2);
	usePrecessor(p1, c3);
	usePrecessor(p1, c6);
	useSuccessor(p1, c1);
	useSuccessor(p1, c4);
	useSuccessor(p1, c5);
}

void test_find(){
	cout << "-----------find-------------" << endl;
	card c1("c 10");
	card c2("h 2");
	card c3("c 9");
	card c4("d 1");
	card c5("s 2");
	card c6("h j");
	BSTplayer p1("Alice");
	assert_equal(p1.find(c1), "c 1");
	assert_equal(p1.find(c2), "c 2");
	assert_equal(p1.find(c3), "c 3");
}

void test_delete(){
	cout << "-----------deleteCard-------------" << endl;
	card c1("c 10");
	card c2("h 2");
	card c3("c 9");
	card c4("d 1");
	card c5("s 2");
	card c6("h j");
	BSTplayer p1("Alice");
	p1.insert(c1);
	p1.insert(c2);
	p1.insert(c3);
	p1.insert(c4);
	p1.insert(c5);
	p1.insert(c6);
	cout << "inorder before delete: "; 
	p1.printInorder(", "); cout << endl;
	usedelete(p1, c1);
	usedelete(p1, c3);
	usedelete(p1, c5);
	cout << "inorder after deletion: ";
	p1.printInorder(", "); cout << endl;
}

int main(){
	test_equal();
	test_larger();
	test_less();
	test_find();
	test_ips();
	test_delete();
	
	

	




	return 0;



}
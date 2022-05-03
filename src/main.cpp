#include <iostream> 
#include "bst.h"

using namespace std;



int main(){
	bst::bst bst;
	bst.addNode(4);
	bst.addNode(2);
	bst.addNode(6);
	bst.addNode(3);
	bst.addNode(1);
	bst.addNode(5);
	bst.addNode(7);
	bst.print();
	
	
	return 0;
}

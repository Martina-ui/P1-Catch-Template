#include <iostream>
#include <sstream>
#include "AVL.h"
using namespace std;

int main(){
	AVLTree tree;
	string numCommands;
	getline(cin, numCommands);
	istringstream in(numCommands);

	string command;
	in >> command;

	string next;
	getline(in, next, '"');
	while(getline(in, next, '"')){
		tree.check_commands(next);
		getline(in, next, '"');
	}

	return 0;
}
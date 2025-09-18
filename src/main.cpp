#include <iostream>
#include <sstream>
#include "AVL.h"
using namespace std;

int main(){
	//got syntax from project 1 ppt slide on code parsing
	AVLTree tree;
	string numCommands;

	while (getline(cin, numCommands)) {
		tree.check_commands(numCommands);
	}
	return 0;
}
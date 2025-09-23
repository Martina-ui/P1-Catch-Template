#include <iostream>
#include <sstream>
#include "AVL.h"
using namespace std;

int main(){
	//got syntax from project 1 ppt slide on code parsing
	AVLTree tree;
	int num_commands;
	cin >> num_commands;
	cin.ignore();

	for (int i=0; i < num_commands; i++) {
		string command;
		getline(cin, command);
		cout << "DEBUG: [" << command << "]" << endl;
		tree.check_commands(command);
	}
	return 0;
}
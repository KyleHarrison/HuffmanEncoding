

#include "HuffmanTree.h"
#include "HuffmanNode.h"
#include <memory>
#include<string>
#include<iostream>

using namespace std;

int main(int argc, char *argv[]){
	if(argc == 1){
			cout << "No argument specified" << endl;
			return 0;
	}
	else if(argc > 3){
			cout << "Incorrect argument specified" << endl;
			return 0;
	}

	HuffmanTree h(argv[1],argv[2]);
		return 0;
}









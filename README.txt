Kyle Harrison
HRRKYL008

Huffman encoding:

The file can be run as follows:
make
./huffencode <arg1> <arg2>

It takes a text file as first arugment and produces an encoded binary file and code table header with the name of the second argument.

Files:
HuffmanNode.cpp/h:
	The nodes make up a tree
	They contain frequency, character and a string for the characters code
HuffmanTree.cpp/h:
	This is all the computing in the program
	It reads in the text file, assembles a map, tree and code table and outputs to file
Huffencode.cpp:
	This is the driver containing main for running
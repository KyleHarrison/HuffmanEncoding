libhuffman_lib.so: HuffmanTree.o HuffmanNode.o
	g++ -o libhuffman_lib.so HuffmanTree.o HuffmanNode.o -fPIC -shared -std=c++11
HuffmanTree.o: HuffmanTree.cpp
	g++ -c -o HuffmanTree.o HuffmanTree.cpp -fPIC -shared -std=c++11
HuffmanNode.o: HuffmanNode.cpp
	g++ -c -o HuffmanNode.o HuffmanNode.cpp -fPIC -shared -std=c++11

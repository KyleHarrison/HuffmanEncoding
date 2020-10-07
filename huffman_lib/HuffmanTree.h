

#ifndef HUFFMANTREE_H_
#define HUFFMANTREE_H_

#include<string>
#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<memory>
#include "HuffmanNode.h"
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <queue>
#include <cstdio>

	
class HuffmanTree {

private:
	struct NodeCmp{
		bool operator()(const std::shared_ptr<HuffmanNode>& lhs, const std::shared_ptr<HuffmanNode>& rhs) const { return lhs->getFreq() > rhs->getFreq(); }
	};
	
	std::priority_queue<std::shared_ptr<HuffmanNode>, std::vector<std::shared_ptr<HuffmanNode> >, NodeCmp> pq;
	
	//std::priority_queue<HuffmanNode,std::vector<HuffmanNode>, CompareNodes> pq;

	std::unordered_map<char, int> buildMap(std::string chars);
	std::string readFile(std::string file);

	void buildQueue(std::unordered_map<char, int>& frequencyMap);

	void buildTree();

	void buildCodeTable(std::shared_ptr<HuffmanNode> node);
	void buildFiles(std::string out);

	
public:
	std::shared_ptr<HuffmanNode> root;  
	HuffmanTree(std::string, std::string);
	~HuffmanTree();
    std::unordered_map<char, std::string> codeTable; 
   

    std::string message;

};

#endif /* HUFFMANTREE_H_ */


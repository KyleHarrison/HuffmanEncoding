

#ifndef HUFFMANNODE_H_
#define HUFFMANNODE_H_
#include <memory>
#include<string>

class HuffmanNode {
private:
	int f;
	char c;
	std::string code;
	
public:

	HuffmanNode();
	HuffmanNode(char character, int frequency);
	HuffmanNode(int frequency, HuffmanNode left, HuffmanNode right);

	~HuffmanNode();

	std::shared_ptr<HuffmanNode> left;
	std::shared_ptr<HuffmanNode> right;
	
	char getChar();
	int getFreq();
	std::string getCode();
	void setChar(char);
	void setFreq(int);
	void setCode(std::string);
};

#endif /* HUFFMANNODE_H_ */


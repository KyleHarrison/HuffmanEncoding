
#include "HuffmanNode.h"
HuffmanNode::HuffmanNode()
{

}
HuffmanNode::HuffmanNode(char character, int frequency): c(character),f(frequency) {}

HuffmanNode::HuffmanNode(int freq, HuffmanNode node1, HuffmanNode node2)
{
    left = std::make_shared<HuffmanNode>(node1);
    right = std::make_shared<HuffmanNode>(node2);
    f = freq;
    c = ' ';
}
                
HuffmanNode::~HuffmanNode() {
}

char HuffmanNode::getChar(){
	return c;
}
int HuffmanNode::getFreq(){
	return f;
}
std::string HuffmanNode::getCode(){
	return code;
}

void HuffmanNode::setFreq(int frequency){
	f = frequency;
}
void HuffmanNode::setChar(char character){
	c = character;
}
void HuffmanNode::setCode(std::string c){
	code = c;
}



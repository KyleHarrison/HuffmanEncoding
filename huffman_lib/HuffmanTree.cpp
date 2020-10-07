
#include "HuffmanTree.h"
#include <stdio.h>
#include <string.h>

using namespace std;

HuffmanTree::HuffmanTree(string in, string out) {


	message = readFile(in);
	
	unordered_map<char, int> freqMap = buildMap(message);
	
	buildQueue(freqMap);
	

	buildTree();

	string s = "";
	buildCodeTable(root);

	buildFiles(out);

}

HuffmanTree::~HuffmanTree() {
	root = nullptr;
}

void HuffmanTree::buildQueue (std::unordered_map<char, int>& map){
	for(auto i = map.begin(); i != map.end(); ++i){
			shared_ptr<HuffmanNode> node = make_shared<HuffmanNode>(i->first,i->second);
			pq.push(node);
		}
}

void HuffmanTree::buildTree (){
				
		while(pq.size() != 1){
			shared_ptr<HuffmanNode> temp(new HuffmanNode(' ',0));
			temp ->left = pq.top();
			pq.pop();
			temp->right = pq.top();
			pq.pop();
			temp ->setFreq(temp->left->getFreq() + temp->right->getFreq());
			temp ->setCode("");
			pq.push(temp);
		}
        root = pq.top();
        pq.pop();

}

void HuffmanTree::buildCodeTable(std::shared_ptr<HuffmanNode> node){
  static string code = "";
    
        if (node->right)
        {
            code += "1";
            buildCodeTable(node -> right);         
            code = code.substr(0, code.size() - 1);
        }
        if (node ->left)
        {
            code += "0";
            buildCodeTable(node->left);
            code = code.substr(0, code.size() - 1);
        }
        if(node->left == nullptr && node->right == nullptr)
        {
            cout<<node->getChar() <<"->"<<node->getFreq() << ": "<<code<<endl;
            codeTable[node->getChar()] = code;
        }
}


void HuffmanTree::buildFiles(string outfilename){
	string code;
	
	ofstream outfile;
	outfile.open(outfilename +".hdr");	
	
	outfile << codeTable.size() << endl;
	for (auto ch: codeTable)
	{    			              
	    outfile << ch.first<< " -> "<<ch.second << endl;;
	}  			    
	outfile.close();
				
	int encodedbits = 0;
	int bytes =0;			
    for (char ch: message)
    {
 	    code += codeTable[ch];
    	encodedbits += codeTable[ch].size();	
    	bytes++;		            
    }
     int enbytes = (encodedbits/8) + (encodedbits%8 ? 1 : 0);

    cout <<"Number of bytes in input file: "<<bytes<<endl;
	cout <<"Number of bytes in encoded message: "<<enbytes<<endl;
	cout <<"Compression ratio: "<<100 -((float)enbytes/bytes)*100<<"%"<<endl;
	cout <<"Encoded: "<<code<<endl;

	ofstream binout(outfilename + ".bin", ios::out | ios::binary);

	binout.put(encodedbits);
	
	for (int i = 0; i < code.length(); i+=8)
		{
	    unsigned char byte = 0;
	    string sub8 = "";
	    if (code.length() > i + 8 ){
	    	sub8 = code.substr(i, i + 8);
		}
	    else
	        sub8 = code.substr(i, code.length());
	    for (unsigned j = 0; j != 8; ++j)
	    {
	        if (j < sub8.length())
	            byte |= (sub8[j] & 1) << j; 
	        else
	            byte |= 1 << j;
	    }
	    binout.put(byte);
	}
   
}
	



unordered_map<char, int> HuffmanTree::buildMap(string read){
	
		unordered_map<char, int> map;
			char c;
			int freq;
			
			for(int i = 0; i < read.length(); i++){
				c = read.at(i);
				freq = std::count(begin(read), end(read), c);
				map.insert(make_pair(c, freq));
			}
			
			return map;
}

string HuffmanTree::readFile(string fileName){

	ifstream inFile;
	inFile.open(fileName+".txt");

	if(inFile.is_open()){
		
		string line;
		string str;
		while(getline(inFile, line)){
			str += line;
		}
		inFile.close();
		//cout << str<<endl;
		return str;
	}
	else{
		cout << fileName << " not found" <<endl;
		exit(EXIT_FAILURE);
	}

}


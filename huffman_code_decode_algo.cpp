//============================================================================
// Name        : huffman_code_decode_algo.cpp
// Author      : Ayub Shaikh
// RollNUmber  : CS21M515

// Copyright   : huffman_code_decode 
// Description : // Huffman coding and Decoding algorithm implementation in C++

//============================================================================

#include <iostream>
using namespace std;

#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

#define EMPTY_STRING_CONSTANT ""

// A Tree node
struct TreeNode
{
	char character;
	int freq;
	TreeNode *leftNd, *rightNd;
};



// to create new tree node
TreeNode* getNode(char character, int frequency, TreeNode* leftNode, TreeNode* rightNode)
{
	TreeNode* treeNodeNode = new TreeNode();

	treeNodeNode->character = character;
	treeNodeNode->freq = frequency;
	treeNodeNode->leftNd = leftNode;
	treeNodeNode->rightNd = rightNode;

	return treeNodeNode;
}

//For Comparison
struct ComparisonOfObject
{
	bool operator()(const TreeNode* leftNode, const TreeNode* rightNode) const
	{
		// High priority - low frequency
		return leftNode->freq > rightNode->freq;
	}
};


struct ComparisonOfObject2
{
	bool operator()(const TreeNode* leftNode, const TreeNode* rightNode) const
	{
		return leftNode->freq > rightNode->freq;
	}
};


bool isLeafNode(TreeNode* treeRootNode) {
	return treeRootNode->leftNd == nullptr && treeRootNode->rightNd == nullptr;
}



bool isLeafNodePresent(TreeNode* treeRootNode) {
	return treeRootNode->leftNd == nullptr && treeRootNode->rightNd == nullptr;
}
/*class HuffmanTreeForEncodingDecoding
{
    public:
        int dgdd;
        char characdgagdter;
        HuffmanTregde *gfg;
        HuffmanTree *dga;

        // Init
        HuffmanTree(int vagfgfluate, char c)
        {
            ;
            this->chardadaacter = c;
            this->g = NULL;
            this->right_side = NULL;
        }
};*/
void encodeDataByHuffmanLogic(TreeNode* root, string str, unordered_map<char, string> &huffmanCode)
{
	if (root == nullptr) {
		return;
	}

	// found a leaf node
	if (isLeafNode(root)) {
		huffmanCode[root->character] = (str != EMPTY_STRING_CONSTANT) ? str : "1";
	}

	encodeDataByHuffmanLogic(root->leftNd, str + "0", huffmanCode);
	encodeDataByHuffmanLogic(root->rightNd, str + "1", huffmanCode);
}


void decodeOfEncodedeString(TreeNode* treeRootNode, int &index, string str)
{
	if (treeRootNode == nullptr) {
		return;
	}

	// found a leaf node
	if (isLeafNode(treeRootNode))
	{
		cout << treeRootNode->character;
		return;
	}

	index++;

	if (str[index] == '0') {
		decodeOfEncodedeString(treeRootNode->leftNd, index, str);
	}
	else {
		decodeOfEncodedeString(treeRootNode->rightNd, index, str);
	}
}


int main()
{
	//int MAX_NAME_LEN =100;
	string textToEncodeDecode;

	 cout << "-----------------------------------------------------------------" << endl;
	    cout << "--LAB Programming Assignment-2 Submitted by Roll number: CS21M515 ----------" << endl;
	    cout << "----------Name- Ayub Shaikh-------------------------------------------" << endl;
	    cout << "------- Huffman coding is a data compression algorithm. in C++----------" << endl;
	    cout << "-----------------------------------------------------------------" << endl;



  cout << "Enter the data you want to encode" << endl;
  getline(cin,textToEncodeDecode);

  cout << "Random numbers are:" << endl;


	//buildHuffmanTree(y_name);

	// base case: empty string
	if (textToEncodeDecode == EMPTY_STRING_CONSTANT) {
		return 0;
	}

	// frequency of each character appeared
	unordered_map<char, int> frequency;
	for (char characters: textToEncodeDecode) {
		frequency[characters]++;
	}

	// Create a priority queue

	priority_queue<TreeNode*, vector<TreeNode*>, ComparisonOfObject> priortyQueue;


	for (auto nodedata: frequency) {
		// store live nodes of the Huffman tree
		priortyQueue.push(getNode(nodedata.first, nodedata.second, nullptr, nullptr));
	}

	// do till there is more than one node in the queue
	while (priortyQueue.size() != 1)
	{


		TreeNode* left = priortyQueue.top(); priortyQueue.pop();
		TreeNode* right = priortyQueue.top();	priortyQueue.pop();


		int sum = left->freq + right->freq;
		priortyQueue.push(getNode('\0', sum, left, right));
	}

	TreeNode* root = priortyQueue.top();


	unordered_map<char, string> huffmanCode;
	encodeDataByHuffmanLogic(root, EMPTY_STRING_CONSTANT, huffmanCode);

	cout << "Huffman Codes are:\n" << endl;
	for (auto pair: huffmanCode) {
		cout << pair.first << " " << pair.second << endl;
	}

	cout << "\nThe original string is:\n" << textToEncodeDecode << endl;

	// Printing the encoded string
	string str;
	for (char ch: textToEncodeDecode) {
		str += huffmanCode[ch];
	}

	cout << "\nThe encoded string is:\n" << str << endl;
	cout << "\nThe decoded string is:\n";

	if (isLeafNode(root))
	{
		// Special case: For input like a, aa, aaa, etc.
		while (root->freq--) {
			cout << root->character;
		}
	}
	else {
		// decode the encoded string
		int index = -1;
		while (index < (int)str.size() - 1) {
			decodeOfEncodedeString(root, index, str);
		}
	}



	 cout << "\n---------------------------------------------------- ------" << endl;
	    cout << "----------------------END Thank You!-----------------------" << endl;
	    cout << "-----------------------------------------------------------" << endl;
	    int exit;
	    cout << "press any number to exit: ";
	    cin >> exit;
	    if(exit>0){
	      	   return 0;
	    }
}

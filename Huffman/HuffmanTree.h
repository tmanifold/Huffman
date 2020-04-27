
#ifndef __HUFFMAN_TREE__
#define __HUFFMAN_TREE__

#include <string>
#include <tuple>
#include <vector>

using std::string;
using std::tuple;
using std::vector;

class HuffmanTreeNode {
private:
	string _key;
	int _value;
	string _code;

	HuffmanTreeNode* _left;
	HuffmanTreeNode* _right;
public:
	HuffmanTreeNode();
	HuffmanTreeNode(string, int);
	HuffmanTreeNode(HuffmanTreeNode*); // copy constructor

	void key(string);
	string key();

	void value(int);
	int value();

	void encoding(string);
	string encoding();

	void left(HuffmanTreeNode*);
	void left(string, int);

	void right(HuffmanTreeNode*);
	void right(string, int);

	HuffmanTreeNode* left();
	HuffmanTreeNode* right();
};

// HuffmanTree class
// Builds a Huffman tree out of the vector of <string,int> tuples
// assumes the vector is already sorted by tuple integer values
class HuffmanTree {

public:

	HuffmanTree();

	HuffmanTree(vector<tuple<string, int>>* data);

	// vector to store the character and it's corresponding encoding
	vector<tuple<string, string>> codetable;

private:

	// the current root node of the tree
	// this should get updated as intermediate node values are calculated
	HuffmanTreeNode* root;

	// an initial list of the nodes created from the vector passed to the class constructor
	vector<HuffmanTreeNode*>* nodes;

	// initialize member of the vector as nodes
	void init_nodes(vector<tuple<string, int>>* data);

	int levels;

	// build the tree out of the generated nodes vector
	void make_tree();

	// reorder the list after combining nodes into a subtree
	void reorder();

	// initialize the assign_codes procedure by assigning the first 0 or 1 based on left or right trajectories
	void init_assign_codes();

	// recursively traverse the tree and assign binary encodings to leaf nodes
	void assign_codes(HuffmanTreeNode*, string);

	// print the tree
	void print(HuffmanTreeNode*, int);
};


#endif // __HUFFMAN_TREE__
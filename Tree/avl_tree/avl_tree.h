#pragma once

#include <iostream>
#include <queue>
#include <vector>
#include <assert.h>
using namespace std;

typedef int KeyType;
struct AVLNode
{ 
	AVLNode* left_;
	AVLNode* right_;
	//T key_;
	KeyType key_;
	int bf_;

	//AVLNode(): left_(nullptr),right_(nullptr),key_(T()),bf_(0) { }
	AVLNode(int x): left_(nullptr),right_(nullptr),key_(x),bf_(0) { }
};

class AVLTree
{ 
public:
	AVLTree(): root_(nullptr) {}
	~AVLTree() { Destroy();} 

	AVLNode* LL_Rotate(AVLNode* root);
	AVLNode* LR_Rotate(AVLNode* root);
	AVLNode* RR_Rotate(AVLNode* root);
	AVLNode* RL_Rotate(AVLNode* root);

	void Insert(const KeyType& x);
	//void Insert(int x);
	void DeleteTree(AVLNode* curRoot);          //删除指定子树
	void Destroy()  { DeleteTree(root_); root_ = nullptr; }
	bool Empty() const { return root_ == nullptr;}
	void Bfs() const;
private:
	AVLNode* root_;
};

//#include "avl_tree.cc"

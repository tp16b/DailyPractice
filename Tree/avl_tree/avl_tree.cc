#include "avl_tree.h"

//template <class T>
void AVLTree::Insert(const KeyType& x)
{ 
	AVLNode* s = new AVLNode(x);
	if(root_ == nullptr){ 
		root_ = s; return; 
	}
	AVLNode* a=root_;
	AVLNode* fa = nullptr; //a记录最小不平衡树根,fa记录a的双亲结点

	AVLNode* cur=root_;
	AVLNode* curFa = nullptr;	

	//找到合适位置,插入结点
	while(cur != nullptr){ 
		if(cur->key_ == x) return;  //avl树中存在相同key值结点
		if(cur->bf_ != 0)  {a = cur; fa = curFa; }
		curFa = cur;
		if(x < cur->key_) cur = cur->left_;
		else cur = cur->right_;
	}
	if(x < curFa->key_) curFa->left_ = s; //插入结点s
	else curFa->right_ = s;

	//插入结点后，修改相关结点平衡因子
	cur = a;
	while(cur != s){ 
		if(x < cur->key_){   
			cur->bf_++; cur = cur->left_;
		}else{ 
			cur->bf_--; cur = cur->right_;
		}
	}
	if(abs(a->bf_) < 2) return;    //插入结点后，没有破坏平衡 
	
	if(a->bf_ == 2){               //插入导致不平衡,调整最小不平衡树结构
		if(a->left_->bf_ == 1)  cur = LL_Rotate(a);
		else  cur = LR_Rotate(a);
	}else if(a->bf_ == -2){ 
		if(a->right_->bf_ == -1) cur= RR_Rotate(a);
		else cur= RL_Rotate(a);
	}else assert(false);

	//调整好的平衡树链到fa结点上
	if(fa == nullptr)		root_ = cur;
	else if(fa->left_ == a) fa->left_ = cur;
	else fa->right_ = cur; 
}

AVLNode* AVLTree::LL_Rotate(AVLNode* a)
{ 
	AVLNode* b = a->left_;
	a->left_ = b->right_;
	b->right_ = a;

	//调整平衡因子
	a->bf_ = b->bf_ = 0;
	return b;
}

AVLNode* AVLTree::LR_Rotate(AVLNode* a)
{ 
	AVLNode* b = a->left_;
	AVLNode* c = b->right_;
	
	b->right_ = c->left_;
	a->left_ = c->right_;
	c->left_ = b;
	c->right_ = a;
	//调整平衡因子
	if(c->bf_ == 0){ //c就是新插入的结点
		a->bf_ = b->bf_ = 0;	
	}else if(c->bf_ == -1){ 
		a->bf_ = 0; b->bf_ = 1;
	}else if(c->bf_ == 1){ 
		a->bf_ = -1; b->bf_ = 0;
	}else assert(false);
	c->bf_ = 0;

	return c;
}

AVLNode* AVLTree::RR_Rotate(AVLNode* a)
{ 
	AVLNode* b = a->right_;
	a->right_ = b->left_;
	b->left_ = a;
	a->bf_ = b->bf_ = 0;
	return b;
}
AVLNode* AVLTree::RL_Rotate(AVLNode* a)
{ 
	AVLNode* b = a->right_;
	AVLNode* c = b->left_;

	b->left_ = c->right_;
	a->right_ = c->left_;
	c->right_ = b;
	c->left_ = a;
	if(c->bf_ == 0){ 
		a->bf_ = b->bf_ = 0;
	}else if(c->bf_ == 1){ 
		a->bf_ = 0; b->bf_ = -1;
	}else if(c->bf_ == -1){ 
		a->bf_ = 1; b->bf_ = 0;
	}else assert(false); 
	c->bf_ = 0;

	return c;
}
void AVLTree::Bfs() const
{ 
	queue<AVLNode*> q;
	q.push(root_);
	while(!q.empty( )){ 
		int num = q.size();
		while(num--){ 
			AVLNode* cur = q.front();
			q.pop();
			cout<<cur->key_<<" ";
			if(cur->left_)	q.push(cur->left_);
			if(cur->right_)	q.push(cur->right_);
		}
		cout<<endl;
	}
}


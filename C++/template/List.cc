/*************************************************************************
  > File Name: List.cc
  > Author: tp
  > Mail: 
  > Created Time: Sat 05 May 2018 08:39:46 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

template<class T>
struct ListNode
{ 
	T _val;
	ListNode* _prev;
	ListNode* _next;
	ListNode(const T& x)
		:_val(x), _prev( NULL),_next( NULL)
	{ }
};

template<class T>
class List
{ 
	typedef ListNode<T> Node;
public:
	List()	
	:_head(new Node(T()))  
	{ 
		_head->_prev = _head;
		_head->_next = _head;
	}
	void PushBack(const T& x)
	{ 
		Insert(_head, x);
	}
	void PopBack() 
	{ 
		Erase( _head->_prev);
	}
	void PushFront(const T& x)
	{ 
		Insert(_head->_next, x);
	}
	void PopFront() 
	{ 
		Erase(_head->_next);
	}
	void Insert(Node* pos, const T& x) 
	{ 
		assert( pos);
		Node* prev = pos->_prev;
		//prev newnode  pos
		Node* newnode = new Node(x);
		prev->_next = newnode;
		newnode->_prev = prev;

		newnode->_next = pos;
		pos->_prev = newnode;
	} 
	void Erase(Node* pos)
	{ 
		assert( pos && pos != _head);
		//能删头结点？
		Node* prev = pos->_prev;
		Node* next = pos->_next;
		delete pos;
		prev->_next = next;
		next->_prev = prev;
	}
	bool Empty() 
	{ 
		return _head == _head->_next;
	}
	Node* Find(const T& x)  
	{ 
		Node* cur = _head->_next;
		while( cur != _head)
		{ 
			if( cur->_val == x)
				return cur;
			cur = cur->_next;
		}
		return NULL;
	}
	//以O( 1)的时间复杂度, 多开4字节进行计数,不能让头结点存计数，因为类型不确定
	//这里普通做法
	size_t Size() 
	{ 
		size_t count = 0;
		Node* cur = _head->_next;	
		while( cur != _head)
		{ 
			++count;
			cur = cur->_next;
		}
		return count;
	}

	void Clear( )
	{ 
		Node* cur = _head->_next;
		while(cur != _head)
		{ 
			Node* next = cur->_next;
			delete cur;
			cur = next;
		}
	}
	~List( )
	{ 
		Clear();
		_head = NULL;
	}
	void Print();
protected:
	Node* _head;
};
template<class T>
void List<T>::Print()
{ 
	Node* cur = _head->_next;
	while( cur != _head)
	{ 
		cout<<cur->_val<<" ";
		cur = cur->_next;
	}
	cout<<endl;
}
template <class T, template<class>class Container>
class Vector
{ 
public:
	void Push( const T& x)
	{ 
		_con.PushBack(x);
	}
	void Pop()
	{ 
		_con.PopBack();
	}
	size_t Size()
	{ 
		return _con.Size();
	}
	bool Empty( )
	{ 
		return _con.Empty( );
	}
	void Print( )
	{ 
		_con.Print( );
	}
private:
	Container<T> _con;
};
void test( )
{ 
	Vector<string, List> v;
	v.Push("hello");
	v.Print( );
	cout<<v.Empty();
}

int main( )
{ 
	test();
//	List<int> l;
//	l.PushBack(1);
//	l.PushBack(2);
//	l.PushBack(3);
//	l.PushBack(4);
//	l.PopBack( );
//	l.Print();
//	cout<<l.Size( )<<endl;
//
//	List<string> l1;
//	l1.PushBack( " 11");
//	l1.PushBack( " 1i32");
//	l1.PushBack( " 1112019jhja");
//	l1.PushBack( " 11");
//	l1.Print( );
	return 0;
}


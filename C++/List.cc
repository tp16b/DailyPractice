#include<iostream>
#include<assert.h>

using namespace std;
typedef int DataType;
//带头结点双向链表·
struct ListNode
{
	ListNode* _next;
	ListNode* _prev;
	DataType _val;

	ListNode(DataType x)
		:_val(x)
		 ,_next(NULL)
		 ,_prev(NULL)
	{}
};
class DbList
{
	typedef ListNode Node;
	private:
		Node* _head;
	public:
		DbList()
			:_head(new Node(DataType()))
		{
			_head->_next = _head;
			_head->_prev = _head;
		}

		DbList(const DbList& l) //深拷贝的拷贝构造
			:_head(new Node(DataType()))
		{
			_head->_next = _head;
			_head->_prev = _head;

			Node* cur = l._head->_next;
			while(cur != l._head)
			{
				PushBack(cur->_val);
				cur = cur->_next;
			}
		}
		DbList& operator=(DbList l)
		{
			swap(_head, l._head);
		}
		~DbList() //将头置空
		{
			Node* cur = _head->_next;
			while(cur != _head)
			{
				Node* next = cur->_next;
				delete cur;
				cur = next;
			}
			delete _head;
			_head = NULL;
		}

		void PushBack(DataType x); 
		void PopBack();
		void Insert(Node* pos, DataType x);
		void Erase(Node* pos);
		void Print();

};
void DbList::PopBack()
{
	Erase(_head->_prev);
}
void DbList::Erase(Node* pos)
{
	if(pos != _head)
	{
		Node* prev = pos->_prev;
		prev->_next = pos->_next;
		pos->_next->_prev = prev;

		delete pos;
		
	}
}
void DbList::Insert(Node* pos, DataType x)
{
	Node* prev = pos->_prev;
	Node* newNode = new Node(x);
	//
	prev->_next = newNode;
	newNode->_prev = prev;

	newNode->_next = pos;
	pos->_prev = newNode;

}
void DbList::PushBack(DataType x)
{
	//Node* tail = _head->_prev;
	//Node* newNode = new Node(x);

	//tail->_next = newNode;
	//newNode->_prev = tail;
	//newNode->_next = _head;
	//_head->_prev = newNode;
	
	Insert(_head, x);
}
void DbList::Print()
{
	Node* cur = _head->_next;
	while(cur != _head)
	{
		cout<<cur->_val<<" ";
		cur = cur->_next;
	}
	cout<<endl;
}
int main(void)
{
	DbList l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.PushBack(4);

	l.Print();
	l.PopBack();
	l.Print();
	return 0;
}

#pragma once
namespace work
{
	/* 双向循环带头链表 */
	template<class T>
	 struct ListNode
	{
 
		 ListNode<T>* p_pre;
		 ListNode<T>* p_next;
		 T m_val;
	 
		 ListNode(const T& val = T())
			 : p_pre(nullptr)
			 , p_next(nullptr)
			 , m_val(val)
		 {}

	};
/* 因为链表是用户自定义的数据结构所以，他不像容器，string类一样，使用的是int double char等
系统内置好的，已经明确的知道内存大小的数据类型，所以要对链表进行遍历的时候，除了使用用户自己
写的for循环外，还有iterator迭代器，它是一个类，此时需要我们自己手动实现这个类，才能使用他*/
    template<class T,class Ref,class Ptr>
	class ListIterator
	{
		typedef ListNode<T>* PNode;/* 链表节点 */
		typedef ListIterator<T, Ref, Ptr> Self;/* 迭代器 */
		PNode _pNode;
	public:
		ListIterator(PNode pNode = nullptr) :_pNode(pNode)
		{}
		ListIterator(const Self& l)
			: _pNode(l._pNode)
		{}
		T*operator*()
		{
			return _pNode->m_val;
		}
		T* operator->()
		{
			/* 没看懂 */
			return &(operator*());
		}
		Self &operator++()
		{
			_pNode = _pNode->p_next;
			return *this;
		}
		Self operator++(int)
		{
			Self temp(*this);
			_pNode = _pNode->p_next;
			return temp;
		}
	};
	template<class T>
	class list
	{
		typedef ListNode<T> Node;
		typedef Node* PNode;
	private:
		Node _pHead;
		void CreatHead()
		{
			_pHead = new Node;
			_pHead->p_pre = _pHead;
			_pHead->p_next = _pHead;
		}
	public:
		typedef ListIterator<T, T&, T*> iterator;

		/* 开始构造 */
		list()
		{
			CreatHead();

		}

		list(int n, const T& value = T())
		{
			CreatHead();
			for (int i = 0; i < n; ++i)
				push_back(value);
		}
		iterator begin()
		{ 
			return iterator(_pHead->p_next);
		}
		void push_back(const T& val)
		{
			insert(begin(), val); 
		}

		// 在pos位置前插入值为val的节点
		iterator insert(iterator pos, const T& val)
		{
			PNode pNewNode = new Node(val);/* 申请空间并赋值 */
			PNode pCur = pos._pNode;/* 要在它之前插入的节点指针 */
			// 先将新节点插入
			pNewNode->p_pre = pCur->p_pre;
			pNewNode->p_next = pCur;
			pNewNode->p_pre->p_next = pNewNode;
			pCur->p_pre = pNewNode;
			return iterator(pNewNode);
		}
		
	};

 }
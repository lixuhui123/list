#pragma once
namespace work
{
	/* ˫��ѭ����ͷ���� */
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
/* ��Ϊ�������û��Զ�������ݽṹ���ԣ�������������string��һ����ʹ�õ���int double char��
ϵͳ���úõģ��Ѿ���ȷ��֪���ڴ��С���������ͣ�����Ҫ��������б�����ʱ�򣬳���ʹ���û��Լ�
д��forѭ���⣬����iterator������������һ���࣬��ʱ��Ҫ�����Լ��ֶ�ʵ������࣬����ʹ����*/
    template<class T,class Ref,class Ptr>
	class ListIterator
	{
		typedef ListNode<T>* PNode;/* ����ڵ� */
		typedef ListIterator<T, Ref, Ptr> Self;/* ������ */
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
			/* û���� */
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

		/* ��ʼ���� */
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

		// ��posλ��ǰ����ֵΪval�Ľڵ�
		iterator insert(iterator pos, const T& val)
		{
			PNode pNewNode = new Node(val);/* ����ռ䲢��ֵ */
			PNode pCur = pos._pNode;/* Ҫ����֮ǰ����Ľڵ�ָ�� */
			// �Ƚ��½ڵ����
			pNewNode->p_pre = pCur->p_pre;
			pNewNode->p_next = pCur;
			pNewNode->p_pre->p_next = pNewNode;
			pCur->p_pre = pNewNode;
			return iterator(pNewNode);
		}
		
	};

 }
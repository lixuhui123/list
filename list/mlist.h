#pragma once
namespace lxh
{
	template<class T>
	class ListNode
	{
	public:
		/* 链表节点 */
		T m_val;
		ListNode * p_prev;
		ListNode * p_next;
		ListNode(const T & val=T()) :p_next(nullptr), p_prev(nullptr), m_val(val)
		{

		}

	};
	template<class T>
	class list
	{
		/* 私有造头 */
		ListNode<T>* m_head;
		void creadHead()
		{
			/* 开辟空间,并且生成链表 */
			m_head = new ListNode<T>;
			m_head->p_next = m_head->p_prev = m_head;
		}
	public:
		/* 内部类 ，省去了友元或者声明的麻烦，更有利于阅读吧*/
		class iterator
		{
			/* 因为链表是用户自定义的数据结构所以，他不像容器，string类一样，
			使用的是int double char等系统内置好的，已经明确的知道内存大小的数据类型，
			所以要对链表进行遍历的时候，除了使用用户自己写的for循环外，
			还有iterator迭代器，它是一个类，此时需要我们自己手动实现这个类，才能使用他*/
		public:
			/* 作为一种指针首先它需要一个链表节点的指针 */
			ListNode<T> * m_pos;
			iterator(ListNode<T>* val = nullptr)
				:m_pos(val)
			{
				/* 构造函数 */
			}
			/*下面就是关于迭代器的一些重载 */
			T& operator*()
			{
				return m_pos->m_val;
			}
			T &operator->()
			{
				return &m_pos->m_val;
			}
			iterator operator++()
			{
				m_pos = m_pos->p_next;
				return *this;/* m_pos */
			}
			iterator operator++(int)
			{
				/* 后加 */
				iterator tmp = m_pos;
				m_pos = m_pos->p_next;
				return tmp;
			}
			iterator operator--()
			{
				m_pos = m_pos->p_prev;
				return *this;/* m_pos */
			}
			iterator operator--(int)
			{
				/* 后加 */
				iterator tmp = m_pos;
				m_pos = m_pos->p_prev;
				return tmp;
			}

			bool operator==(const iterator & tmp)
			{
				return m_pos = tmp.m_pos;
			}
			bool operator!=(const iterator & tmp)
			{
				return m_pos != tmp.m_pos;
			}
			 
		};
		/* 如上作为内部类的迭代器初步完成，接下来是list的一些操作 */
		/* list构造函数 */
		list()
		{
			creadHead();
		}
		list(int n, const T & val=T())
		{
			/* 构造n个val */
			creadHead();
			for (int i=0;i<n;++i)
			{
				push_back(val);
			}
		}
		list(iterator _begin, iterator _end)
		{
			/* 用另一个链表的一段，初始化链表 */
			creadHead();
			insert(end(), _begin, _end);
		}
		list(T* _begin, T*_end)
		{
			creadHead();
			insert(end(), _begin, _end);
		}
		list(list & l)
		{
			insert(end(), l.begin(), l.end());
		}
		~list()
		{
			erase(begin(), end());
			delete m_head;
		}
		void clear()
		{
			erase(begin(), end());

		}
		void push_back(const T & val)
		{
			/* 在头后插 */
			insert(end(),val);
		}
		void push_front(const T & val)
		{
			/* 在头前插 */
			insert(begin(), val);
		}
		void pop_back()
		{
			erase(--end());
		}
		void pop_front()
		{
			erase(begin());
		}
		iterator begin()
		{
			return m_head->p_next;
		}
		iterator end()
		{
			return m_head;
		}
		iterator insert(iterator pos, T* _begin, T*_end)
		{
			T* tmp;
			iterator tag = --pos;
			pos++;
			for (tmp = _begin; tmp != _end; ++tmp)
			{
				insert(pos, *tmp);
			}
			return ++tag;
		}

		iterator insert(iterator pos, iterator _begin,iterator _end)
		{
			iterator tmp;
			iterator tag = --pos;
			pos++;
			for (tmp=_begin;tmp!=_end;++tmp)
			{
				insert(pos, *tmp);
			}
			return ++tag;
		}
		iterator insert(iterator pos, const T & val)
		{
			/* 插入函数，给定位置和值 */
			/* 首先要一个新的链表节点 */
			ListNode<T>* cur = new ListNode<T>;
			ListNode<T>* npos = pos.m_pos;/* 从位置数到指针位置的转换 */
			cur->m_val = val;
			
			cur->p_prev = npos->p_prev;
			cur->p_prev->p_next = cur;
			
			cur->p_next = npos;
			npos->p_prev = cur;
			
			return cur;
		}
		iterator erase(iterator pos)
		{
			ListNode<T>* npos = pos.m_pos;/* 转数字为节点指针 */
			ListNode<T>* res = npos->p_next;/*  指针指向的对象已经无效了*/
			npos->p_prev->p_next = npos->p_next;
			npos->p_next->p_prev = npos->p_prev;
			delete npos;


			npos = nullptr;
			return res;
		}
		iterator erase(iterator start, iterator finsh)
		{
			iterator i;
			//iterator tmp = ++finsh;
			for (i = start; i != finsh;  )
			{
				i=erase(i);
			}
			 
			return finsh;
		}
	};

}
 
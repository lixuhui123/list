#pragma once
namespace lxh
{
	template<class T>
	class ListNode
	{
	public:
		/* ����ڵ� */
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
		/* ˽����ͷ */
		ListNode<T>* m_head;
		void creadHead()
		{
			/* ���ٿռ�,������������ */
			m_head = new ListNode<T>;
			m_head->p_next = m_head->p_prev = m_head;
		}
	public:
		/* �ڲ��� ��ʡȥ����Ԫ�����������鷳�����������Ķ���*/
		class iterator
		{
			/* ��Ϊ�������û��Զ�������ݽṹ���ԣ�������������string��һ����
			ʹ�õ���int double char��ϵͳ���úõģ��Ѿ���ȷ��֪���ڴ��С���������ͣ�
			����Ҫ��������б�����ʱ�򣬳���ʹ���û��Լ�д��forѭ���⣬
			����iterator������������һ���࣬��ʱ��Ҫ�����Լ��ֶ�ʵ������࣬����ʹ����*/
		public:
			/* ��Ϊһ��ָ����������Ҫһ������ڵ��ָ�� */
			ListNode<T> * m_pos;
			iterator(ListNode<T>* val = nullptr)
				:m_pos(val)
			{
				/* ���캯�� */
			}
			/*������ǹ��ڵ�������һЩ���� */
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
				/* ��� */
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
				/* ��� */
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
		/* ������Ϊ�ڲ���ĵ�����������ɣ���������list��һЩ���� */
		/* list���캯�� */
		list()
		{
			creadHead();
		}
		list(int n, const T & val=T())
		{
			/* ����n��val */
			creadHead();
			for (int i=0;i<n;++i)
			{
				push_back(val);
			}
		}
		list(iterator _begin, iterator _end)
		{
			/* ����һ�������һ�Σ���ʼ������ */
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
			/* ��ͷ��� */
			insert(end(),val);
		}
		void push_front(const T & val)
		{
			/* ��ͷǰ�� */
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
			/* ���뺯��������λ�ú�ֵ */
			/* ����Ҫһ���µ�����ڵ� */
			ListNode<T>* cur = new ListNode<T>;
			ListNode<T>* npos = pos.m_pos;/* ��λ������ָ��λ�õ�ת�� */
			cur->m_val = val;
			
			cur->p_prev = npos->p_prev;
			cur->p_prev->p_next = cur;
			
			cur->p_next = npos;
			npos->p_prev = cur;
			
			return cur;
		}
		iterator erase(iterator pos)
		{
			ListNode<T>* npos = pos.m_pos;/* ת����Ϊ�ڵ�ָ�� */
			ListNode<T>* res = npos->p_next;/*  ָ��ָ��Ķ����Ѿ���Ч��*/
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
 
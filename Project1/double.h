#pragma once
#include <assert.h>

using namespace std;

template <typename T>
class ListNode {
	template<typename T>
	friend class LinkedList;
private:
	ListNode() {
		m_pNext = nullptr;
		m_pPrev = nullptr;
	}
	~ListNode() {}
	T m_data;
	ListNode<T>* m_pNext;
	ListNode<T>* m_pPrev;
};

template<typename T>
class LinkedList {
public:
	LinkedList() {
		m_First = new NODE;
		m_End = new NODE;
		m_First->m_pNext = m_End;
		m_End->m_pPrev = m_First;
	}
	~LinkedList() {
		PNODE pNode = m_First->m_pNext;
		while (pNode != m_End) {
			PNODE pNext = pNode->m_pNext;
			delete pNode;
			pNode = pNext;
		}
		m_size = 0;
		m_End->m_pPrev = m_First;
		m_First->m_pNext = m_End;
	}
	void showing() {
		PNODE pNode = m_First->m_pNext;
		cout << m_size << endl;
		while (pNode != m_End) {
			PNODE pNext = pNode->m_pNext;
			cout << pNode->m_data << endl;
			pNode = pNext;
		}
	}
private:
	typedef ListNode<T> NODE;
	typedef ListNode<T>* PNODE;
	PNODE m_First;
	PNODE m_End;
	int m_size = 0;
public:
	void push_back(const T& value) {
		PNODE node = new NODE;
		node->m_data = value;

		PNODE pPrev = m_End->m_pPrev;

		pPrev->m_pNext = node;
		node->m_pPrev = pPrev;

		m_End->m_pPrev = node;
		node->m_pNext = m_End;

		m_size++;
	}
	void push_front(const T& value) {
		PNODE node = new PNODE;
		node->m_data = value;
		
		PNODE pPrev = m_First->m_pNext;
		
		node->m_pNext = pPrev;
		node->m_pPrev = m_First;

		pPrev->m_pPrev = node;
		m_First->m_pNext = node;
	}

	void pop_back() {
		if (m_size == 0)
			return;
		PNODE node = m_End->m_pPrev;
		PNODE pPrev = node->m_pPrev;

		pPrev->m_pNext = m_End;
		m_End->m_pPrev = pPrev;

		delete node;
		
		m_size--;
	}
	void pop_front() {
		if (m_size == 0)
			return;
		PNODE node = m_First->m_pNext;
		PNODE pNext = node->m_pNext;

		m_First->m_pNext = pNext;
		pNext->m_pPrev = m_First;

		delete node;

		m_size--;
	}
	void insert(int a, T newValue) {
		if (a > m_size) {
			cout << "그만큼은 없습니다." << endl;
		}
		cout << 1 << endl;
		PNODE newNode=new NODE;
		newNode->m_data = newValue;
		PNODE node = m_First;
		if (a == 0) {
			newNode->m_pNext = m_First->m_pNext;
			m_First->m_pNext = newNode;
			newNode->m_pPrev = m_First;
		}
		else {
			for (int i = 0;i < a-1;i++) {
				node = node->m_pNext;
			}
			cout << node->m_data << endl;
			

			newNode->m_pNext = node->m_pNext;
			newNode->m_pPrev = node;
			node->m_pNext = newNode;
			
		}
	
		m_size++;

	}
};


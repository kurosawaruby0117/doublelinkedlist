#pragma once

#include <assert.h>

template<typename T>
class ListNode {

    template<typename T>
    friend class LinkedList;
    template<typename T>
    friend class Listiterrator;
    template<typename T>
    friend class ReListiterrator;

private:
    T m_data;
    ListNode<T>* m_pNext;
    ListNode<T>* m_pPrev;
    ListNode() {
        m_pNext = nullptr;
        m_pPrev = nullptr;
    }
    ~ListNode() {}
};

template <typename T>
class Listiterrator {
    template<typename T>
    friend class LinkedList;

public:
    Listiterrator() {
        m_pNode = nullptr;
    }
    ~Listiterrator() {

    }

    bool operator==(const Listiterrator<T>& iter) {
        return m_pNode == iter.m_pNode;
    }
    bool operator!=(const Listiterrator<T>& iter) {
        return m_pNode != iter.m_pNode;
    }

    void operator ++() {
        m_pNode = m_pNode->m_pNext;
    }
    void operator --() {
        m_pNode = m_pNode->m_pPrev;
    }
    T& operator * () {
        return m_pNode->m_data;
    }
private:
    typedef ListNode<T> NODE;
    typedef ListNode<T>* PNODE;
    PNODE m_pNode;

};

template <typename T>
class ReListiterrator {
    template<typename T>
    friend class LinkedList;

public:
    ReListiterrator() {
        m_pNode = nullptr;
    }
    ~ReListiterrator() {

    }

    bool operator==(const Listiterrator<T>& iter) {
        return m_pNode == iter.m_pNode;
    }
    bool operator!=(const Listiterrator<T>& iter) {
        return m_pNode != iter.m_pNode;
    }

    void operator ++() {
        m_pNode = m_pNode->m_pPrev;
    }
    void operator --() {
        m_pNode = m_pNode->m_pNext;
    }
    T& operator * () {
        return m_pNode->m_data;
    }
private:
    typedef ListNode<T> NODE;
    typedef ListNode<T>* PNODE;
    PNODE m_pNode;
};


template<class T>
class LinkedList {
public:
    LinkedList() {
        m_pBegin = new NODE;
        m_pEnd = new NODE;

        m_pBegin->m_pNext = m_pEnd;
        m_pEnd->m_pPrev = m_pBegin;

        m_size = 0;
    }
    ~LinkedList() {
        clear();
        delete m_pBegin;
        delete m_pEnd;
    }
private:
    typedef ListNode<T> NODE;
    typedef ListNode<T>* PNODE;
    PNODE m_pBegin;
    PNODE m_pEnd;
    int m_size;

public:
    typedef Listiterrator<T> iterator;
    typedef ReListiterrator<T> reIteror;

    void push_back(const T& data) {
        PNODE pNode = new NODE;
        pNode->m_data = data;

        PNODE pPrev = m_pEnd->m_pPrev;

        pPrev->m_pNext = pNode;
        pNode->m_pPrev = pPrev;

        pNode->m_pNext = m_pEnd;
        m_pEnd->m_pPrev = pNode;

        m_size++;
    }

    void push_front(const T& data) {
        PNODE pNode = new NODE;
        pNode->m_data = data;

        PNODE pNext = m_pBegin->m_pNext;


        pNext->pPrev = pNode;
        pNode->m_pPrev -= pNode;

        m_pBegin->m_pNext = pNode;
        pNode->pPrev = m_pBegin;

        ++m_size;
    }
    int size() {
        return m_size;
    }

    bool empty() {
        return m_size == 0;
    }
    void pop_back() {
        if (empty()) {
            assert(false);
        }
        PNODE pDelete = m_pEnd->m_pPrev;
        PNODE pPrev = pDelete->m_pPrev;
        pPrev->m_pNext = m_pEnd;
        m_pEnd->m_pPrev = pPrev;

        delete pDelete;

        m_size--;
    }
    void pop_front() {
        if (empty()) {
            assert(false);
        }
        PNODE pDelete = m_pBegin->m_pNext;
        PNODE pNext = pDelete->m_pNext;

        m_pBegin->m_pNext = pNext;
        pNext->m_pPrev = m_pBegin;

        delete pDelete;
    }
    void clear() {
        PNODE pNode = m_pBegin->m_pNext;
        while (pNode != m_pEnd) {
            PNODE pNext = pNode->m_pNext;

            delete pNode;

            pNode = pNext;
        }
        m_size = 0;
        m_pBegin->m_pNext = m_pEnd;
        m_pEnd->m_pPrev = m_pBegin;
    }
    T front() {
        if (empty())
            assert(false);
        return m_pBegin->m_pNext->m_data;
    }

    T end() {
        if (empty())
            assert(false);
        return m_pEnd->m_pPrev->m_data;
    }

public:
    iterator rbegin() {
        iterator iter;
        iter.m_pNode = m_pBegin->m_pNext;
        return iter;
    }
    iterator rend() {
        iterator iter;
        iter.m_pNode = m_pEnd;
        return iter;
    }
};
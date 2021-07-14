//pragma once
#ifndef TList_H
#define TList_H
#include "Token.h"
#include <cstring>
#include <cctype>
#include <ostream>
using namespace std;
using std::cout;
using std::endl;



class TList
{
	struct TNode
	{
		Token theToken = Token{};
		TNode* prev;
		TNode* next;
		TNode(const Token& token = Token{}, TNode* p = nullptr, TNode* n = nullptr) :
			theToken{ token }, prev{ p }, next{ n }{}
		TNode(Token&& token, TNode* p = nullptr, TNode* n = nullptr) :
			theToken{ std::move(token) }, prev{ p }, next{ n }{}
		TNode & operator=(const TNode&) = delete;
		TNode & operator=(TNode&&) = delete;
		~TNode() = default;
	};

	TNode* headerPtr;
	TNode* trailerPtr;
	int theSize;

public:
	TList()
	{
		init();
	}
	TList(const TList&)
	{

	}
	TList(TList&&)
	{
	};
	TList &operator=(const TList& rhs)
	{

	}
	TList &operator=(TList&& rhs)
	{

	}
	~TList()
	{

	}
	bool empty()
	{
		if (theSize==0)
			return true;
		return false;
	}
	Token& front()
	{
		return headerPtr->next->theToken;
	}
	Token& back()
	{
		return trailerPtr->prev->theToken;
	}
	void addOrdered(const Token& aToken)
	{
		if (theSize == 0)
		{
			addBefore(trailerPtr, aToken);
			return;
		}
		TNode * temp = headerPtr->next;
		while (temp!=trailerPtr)
		{
			if (temp->theToken.compare(aToken) == 0)
			{
				temp->theToken.pushBackLineNumber(aToken.getNum());
				return;
			}
			else if (temp->theToken.compare(aToken) == 1)
			{
				addBefore(temp, aToken);
				return;
			}
			temp = temp->next;
		}

		addBefore(trailerPtr, aToken);


	}
	bool removeFront()
	{
		if (theSize > 0)
		{
			TNode* temp = headerPtr->next;
			headerPtr->next=headerPtr->next->next;
			(headerPtr->next)->prev = headerPtr;
			delete [] (temp);
			theSize--;
			return true;
		}
		return false;
	}
	bool removeBack()
	{
		if (theSize > 0)
		{
			TNode* temp = trailerPtr->prev;
			trailerPtr->prev = trailerPtr->prev->prev;
			(headerPtr->prev)->next = trailerPtr;
			delete [] (temp);
			theSize--;
			return true;
		}
		return false;
	}
	int size()const
	{
		return theSize;
	}
	void print(ostream& sout)const
	{
		TNode* temp = headerPtr->next;
		while (temp != trailerPtr)
		{
			sout << temp->theToken<<endl;
			temp = temp->next;
		}
	}
	friend ostream& operator <<(ostream& out, const TList& rhs)
	{
		TNode* temp = rhs.headerPtr->next;
		while (temp != rhs.trailerPtr)
		{
			out << temp->theToken << endl;
			temp = temp->next;
		}
		return out;
	}
	bool search(const Token& aToken) const
	{
		TNode* temp = headerPtr->next;
		while (temp != trailerPtr)
		{
			if (temp->theToken.compare(aToken) == 0)
				return true;
			temp = temp->next;
		}
		return false;
	}
	TNode* search(const Token& aToken)
	{
		TNode* temp = headerPtr->next;
		while (temp != trailerPtr)
		{
			if (temp->theToken.compare(aToken) == 0)
				return temp;
			temp = temp->next;
		}
		return nullptr;
	}
	void init()
	{
		theSize = 0;
		headerPtr = new TNode{};
		trailerPtr = new TNode{};
		headerPtr->next = trailerPtr;
		trailerPtr->prev = headerPtr;
	}
	void addBefore(TNode* q, const Token& t)
	{
		theSize++;
		TNode* p = new TNode(t);
		p->next = q;
		p->prev = q->prev;
		q->prev = (q->prev)->next = p;
	}
	void remove(TNode* nodePtr)
	{
		(nodePtr->prev)->next = nodePtr->next;
		(nodePtr->next)->prev = nodePtr->prev;
		delete [] (nodePtr);
		theSize--;
	}
};
#endif // !TList_H

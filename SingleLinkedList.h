/*
 * SingleLinkedList.h
 *
 *  Created on: 16-Mar-2022
 *      Author: rajdeep
 */

#ifndef SINGLELINKEDLIST_H_
#define SINGLELINKEDLIST_H_
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <functional>
using namespace std;
using namespace placeholders;
template <typename itemType>
class SingleLinkedList {
private:
	struct SingleList{
		itemType data;
		SingleList* pNextNode;
	}__attribute__((packed));
	using pFuncSet = std::function<void(itemType*)>;
	using pFuncGet = std::function<void(itemType)>;
	pFuncSet pFsetData;
	pFuncGet pFgetData;
public:
	SingleList* pHeadNode;
	SingleLinkedList(pFuncSet pFtempSet,pFuncGet pFtempGet){
		pHeadNode = nullptr;
		pFsetData = pFtempSet;
		pFgetData = pFtempGet;
	}
	virtual ~SingleLinkedList(){
		SingleList* pTemp1;
		SingleList* pTemp2 = nullptr;

		pTemp1 = pHeadNode;
		while(pTemp1 != nullptr)
		{
			pTemp2 = pTemp1;
			pTemp1 = pTemp1->pNextNode;
			delete pTemp2;
		}
	}
	void AddNodeAtBegin(void){
		SingleList* pTemp;
		pTemp = new SingleList;
		pFsetData((itemType*)&pTemp->data);
		pTemp->pNextNode = nullptr;
		if(pHeadNode == nullptr)
		{
			pHeadNode = pTemp;
		}
		else{
		pTemp->pNextNode	=	pHeadNode;
		pHeadNode			=	pTemp;
		}
	}
	void DisplayList(void)
	{
		SingleList* pTemp = pHeadNode;
		cout << "Your ListData:" << endl;
		while(pTemp != nullptr){
			pFgetData(pTemp->data);
			pTemp = pTemp->pNextNode;
		}
	}
	int CountListNode(void)
	{
		SingleList* pTemp = pHeadNode;
		int counter = 0;
		while(pTemp != nullptr)
		{
			counter++;
			pTemp = pTemp->pNextNode;
		}
		return counter;
	}
};

#endif /* SINGLELINKEDLIST_H_ */

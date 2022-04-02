/*
 * GenericSingleListMain.cpp
 *
 *  Created on: 16-Mar-2022
 *      Author: rajdeep
 */

#include "SingleLinkedList.h"
using namespace placeholders;

template <typename itemType>
void SetVal(itemType* pV)
{
	//*pV = 's';//this line belong to character type single linked list
	*pV	=	10;//this line belong to integer type single linked list
}

template <typename itemType>
void GetVal(itemType v)
{
	cout << v << endl;
}

int main()
{
/*--Generic Single Linked list for character data type
	using fS = std::function<void(char*)>;
	using fG = std::function<void(char)>;
	fS fSet = std::bind(&SetVal<char>,_1);
	fG fGet = std::bind(&GetVal<char>,_1);
	SingleLinkedList<char> singleLinkedList(fSet,fGet);
	singleLinkedList.AddNodeAtBegin();
	singleLinkedList.AddNodeAtBegin();
	singleLinkedList.AddNodeAtBegin();
	singleLinkedList.AddNodeAtBegin();
	singleLinkedList.AddNodeAtBegin();
	cout << "Total Node in List....:" << singleLinkedList.CountListNode() << endl;
	singleLinkedList.DisplayList();
	*/


//Generic Single Linked list for integer data type
 	using fS = std::function<void(int*)>;
	using fG = std::function<void(int)>;
	fS fSet = std::bind(&SetVal<int>,_1);
	fG fGet = std::bind(&GetVal<int>,_1);
	SingleLinkedList<int> singleLinkedList(fSet,fGet);
	singleLinkedList.AddNodeAtBegin();
	singleLinkedList.AddNodeAtBegin();
	cout << "Total Node in List....:" << singleLinkedList.CountListNode() << endl;
	singleLinkedList.DisplayList();
}



#pragma once
#include "ListNode.h"

class SortedList
{
public:
	SortedList();
	~SortedList();
	void AddElem(int value);
	int Get();
private:
	ListNode* Root;
	int n;
	

};

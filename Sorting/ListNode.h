#pragma once


class ListNode
{
public:
	ListNode();

	~ListNode() = default;

	inline int Value()
	{
		return value;
	}
	inline void Value(int value)
	{
		this->value = value;
	}
	inline ListNode* Next()
	{
		return next;
	}
	inline void Next(ListNode* next)
	{
		this->next = next;
	}
private:
	int value;
	ListNode* next;
};
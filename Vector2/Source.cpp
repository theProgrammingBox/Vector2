//#include "Vector2_.h"
#include <iostream>

using OBJECT = std::pair<int, void*>;
using ITERATOR = OBJECT*;
using ITERATOR_POINTER = ITERATOR*;
//using OBJECT = std::pair<int, ITERATOR_POINTER>;

size_t currentSize;
size_t maxSize;
ITERATOR arr = nullptr;

void new_()
{
	currentSize = 0;
	maxSize = 1;
	arr = new OBJECT[1];
}

void expand()
{
	if (currentSize == maxSize)
	{
		maxSize = maxSize << 1;

		ITERATOR newArr = new OBJECT[maxSize];
		memcpy(newArr, arr, sizeof(OBJECT) * currentSize);
		delete[] arr;
		arr = newArr;

		for (ITERATOR i = arr + currentSize - 1; i >= arr; i--)
		{
			*(ITERATOR_POINTER)i->second = i;
		}
	}
}

void push_back(const int data)
{
	expand();
	arr[currentSize].first = data;
	arr[currentSize].second = new ITERATOR(arr + currentSize);
	currentSize++;
}

void pop()
{
	if (currentSize != 0)
	{
		delete arr[--currentSize].second;
	}
}

void insert(const ITERATOR_POINTER iteratorPointer, const int data)
{
	expand();
	memmove(
		*iteratorPointer + 1,
		*iteratorPointer,
		sizeof(OBJECT) * (arr + currentSize - *iteratorPointer)
	);
	(*iteratorPointer)->first = data;
	(*iteratorPointer)->second = new ITERATOR(*iteratorPointer);
	for (ITERATOR i = arr + currentSize++ - 1; i > *iteratorPointer; i--)
	{
		*(ITERATOR_POINTER)i->second = i;
	}
}

void erase(const ITERATOR_POINTER iteratorPointer)
{
	memmove(
		*iteratorPointer,
		*iteratorPointer + 1,
		sizeof(OBJECT) * (arr + currentSize - *iteratorPointer)
	);
	for (ITERATOR i = arr + --currentSize - 1; i >= *iteratorPointer; i--)
	{
		*(ITERATOR_POINTER)i->second = i;
	}
	delete iteratorPointer;
}

void print()
{
	int j = currentSize;
	for (ITERATOR i = arr + currentSize - 1; i >= arr; i--)
	{
		std::cout << --j << ": "
			<< i->first << '\t'
			<< (*(ITERATOR_POINTER)i->second)->first
			<< std::endl;
	}
	std::cout << std::endl;
}

void delete_()
{
	for (ITERATOR i = arr + currentSize - 1; i >= arr; i--)
	{
		delete i->second;
	}
	delete[] arr;
}

int main()
{
	new_();
	push_back(101);
	push_back(321);
	push_back(345);
	print();
	pop();
	print();
	push_back(456);
	push_back(645);
	push_back(978);
	print();
	insert((ITERATOR_POINTER)arr[0].second, 789);
	insert((ITERATOR_POINTER)arr[4].second, 789);
	print();
	erase((ITERATOR_POINTER)arr[4].second);
	print();
	delete_();

	return 0;
}
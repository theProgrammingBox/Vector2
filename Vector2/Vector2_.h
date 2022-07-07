#pragma once
#include <iostream>

template <typename OBJECT_TYPE> class Vector2
{
	using OBJECT = std::pair<OBJECT_TYPE, void*>;
	using ITERATOR = OBJECT*;
	using ITERATOR_POINTER = ITERATOR*;

public:
	Vector2()
	{
		currentSize = 0;
		maxSize = 1;
		arr = new OBJECT[1];
	}

	~Vector2()
	{
		for (ITERATOR i = arr + currentSize - 1; i >= arr; i--)
		{
			delete i->second;
		}
		delete[] arr;
	}

	void push_back(const OBJECT_TYPE data)
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

	void insert(const ITERATOR_POINTER iteratorPointer, const OBJECT_TYPE data)
	{
		expand();
		memmove(
			*iteratorPointer + 1,
			*iteratorPointer,
			sizeof(OBJECT) * (arr + currentSize - *iteratorPointer)
		);
		(*iteratorPointer)->first = data;
		(*iteratorPointer)->second = new ITERATOR(*iteratorPointer);
		for (ITERATOR i = arr + currentSize++; i > *iteratorPointer; i--)
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

	void clear()
	{
		for (ITERATOR i = arr + currentSize - 1; i >= arr; i--)
		{
			delete i->second;
		}
		currentSize = 0;
	}

	size_t size() const { return currentSize; }
	OBJECT_TYPE operator[](const size_t index) const { return arr[index].first; }
	OBJECT_TYPE& operator[](const size_t index) { return arr[index].first; }

	ITERATOR_POINTER begin() const { return (ITERATOR_POINTER)arr->second; }
	ITERATOR_POINTER end() const { return (ITERATOR_POINTER)(arr + currentSize - 1)->second; }

private:
	size_t currentSize;
	size_t maxSize;
	ITERATOR arr = nullptr;

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
};
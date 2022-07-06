#pragma once
#include <iostream>

template <typename OBJECT_TYPE> class Vector2
{
	using PERM_ITERATOR = OBJECT_TYPE**;
	using TEMP_ITERATOR = OBJECT_TYPE*;
private:
	size_t currentSize;
	size_t maxSize;
	OBJECT_TYPE* arr = nullptr;
	PERM_ITERATOR* arrPtr = nullptr;
	bool needToUpdateIterators;

	void expand()
	{
		maxSize = maxSize << 1;

		OBJECT_TYPE* newArr = new OBJECT_TYPE[maxSize];
		memcpy(newArr, arr, sizeof(OBJECT_TYPE) * currentSize);
		delete[] arr;
		arr = newArr;

		PERM_ITERATOR* newArrPtr = new PERM_ITERATOR[maxSize];
		memcpy(newArrPtr, arrPtr, sizeof(PERM_ITERATOR) * currentSize);
		delete[] arrPtr;
		arrPtr = newArrPtr;
		needToUpdateIterators = true;
	}

	void updatePermIterators()
	{
		if (needToUpdateIterators)
		{
			for (size_t i = 0; i < currentSize; i++)
			{
				*arrPtr[i] = arr + i;
			}
			needToUpdateIterators = false;
		}
	}

public:
	Vector2()
	{
		currentSize = 0;
		maxSize = 1;
		arr = new OBJECT_TYPE[1];
		arrPtr = new PERM_ITERATOR[1];
		needToUpdateIterators = false;
	}

	~Vector2()
	{
		delete[] arr;
		for (size_t i = 0; i < currentSize; i++)
		{
			delete arrPtr[i];
		}
		delete[] arrPtr;
	}

	PERM_ITERATOR push_back(const OBJECT_TYPE data)
	{
		if (currentSize == maxSize)
		{
			expand();
		}

		arr[currentSize] = data;
		PERM_ITERATOR newAddress = new TEMP_ITERATOR(arr + currentSize);
		arrPtr[currentSize] = newAddress;
		++currentSize;

		return newAddress;
	}

	void pop()
	{
		delete arrPtr[--currentSize];
	}

	void insert(TEMP_ITERATOR iterator, const OBJECT_TYPE data)
		// must use begin() or end() otherwise run the risk of invalid iterator
	{
		if (currentSize == maxSize)
		{
			expand();
		}
		memmove(
			iterator + 1,
			iterator,
			sizeof(OBJECT_TYPE) * (arr + currentSize++ - iterator)
		);
		*iterator = data;
	}

	void insert(PERM_ITERATOR iteratorc, onst OBJECT_TYPE data)
	{
		updatePermIterators();
		if (currentSize == maxSize)
		{
			expand();
		}
		memmove(
			*iterator + 1,
			*iterator,
			sizeof(OBJECT_TYPE) * (arr + currentSize++ - *iterator)
		);
		**iterator = data;
		for (size_t i = 0; i < currentSize; i++)
		{
			arrPtr[i] = arr + i;
		}
	}

	void erase(TEMP_ITERATOR iterator)
		// must use begin() or end() otherwise run the risk of invalid iterator
	{
		memmove(
			iterator,
			iterator + 1,
			sizeof(OBJECT_TYPE) * (arr + --currentSize - iterator)
		);
	}

	void erase(PERM_ITERATOR iterator)
	{
		updatePermIterators();
		memmove(
			*iterator,
			*iterator + 1,
			sizeof(OBJECT_TYPE) * (arr + --currentSize - *iterator)
		);
	}

	void clear()
	{
		for (size_t i = 0; i < currentSize; i++)
		{
			delete arrPtr[i];
		}
		currentSize = 0;
	}

	size_t size() const { return currentSize; }
	OBJECT_TYPE operator[](const size_t index) const { return arr[index]; }
	OBJECT_TYPE& operator[](const size_t index) { return arr[index]; }

	TEMP_ITERATOR begin() const { return arr; }
	TEMP_ITERATOR end() const { return arr + currentSize; }
	PERM_ITERATOR getPermIterator(TEMP_ITERATOR iterator)
	{
		updatePermIterators();
		return arrPtr[iterator - arr];
	}
	PERM_ITERATOR getPermIterator(size_t index)
	{
		updatePermIterators();
		return arrPtr[index];
	}
};
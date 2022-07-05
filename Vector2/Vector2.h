#pragma once
#include <iostream>

template <typename OBJECT_TYPE> class Vector2
{
public:
	Vector2()
	{
		currentSize = 0;
		minimumSize = 1;
		arr = new OBJECT_TYPE[1];
	}

	~Vector2() { delete[] arr; }

	void push(const OBJECT_TYPE data)
	{
		if (currentSize == minimumSize)
		{
			minimumSize = minimumSize << 1;
			OBJECT_TYPE* temp = new OBJECT_TYPE[minimumSize];
			memcpy(temp, arr, sizeof(OBJECT_TYPE) * currentSize);
			delete[] arr;
			arr = temp;
		}
		arr[currentSize++] = data;
	}

	void pop() { --currentSize; }

	void insert(const OBJECT_TYPE data, const int index)
	{
		if (currentSize == minimumSize)
		{
			minimumSize = minimumSize << 1;
			OBJECT_TYPE* temp = new OBJECT_TYPE[minimumSize];
			memcpy(temp, arr, sizeof(OBJECT_TYPE) * currentSize);
			delete[] arr;
			arr = temp;
		}
		memmove(
			&arr[index + 1], &arr[index],
			sizeof(OBJECT_TYPE) * (currentSize++ - index)
		);
		arr[index] = data;
	}

	void erase(const uint64_t index)
	{
		memmove(
			arr + index, arr + index + 1,
			(--currentSize - index) * sizeof(OBJECT_TYPE)
		);
	}

	void clear() { currentSize = 0; }
	uint64_t size() const { return currentSize; }
	OBJECT_TYPE operator[](const uint64_t index) const { return arr[index]; }

private:
	uint64_t currentSize;
	uint64_t minimumSize;
	OBJECT_TYPE* arr = nullptr;
};
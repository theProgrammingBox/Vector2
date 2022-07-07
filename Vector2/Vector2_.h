//#pragma once
//#include <iostream>
//
//template <typename OBJECT_TYPE> class Vector2
//{
//	using OBJECT = std::pair<OBJECT_TYPE, void *>;
//	using PERM_ITERATOR = OBJECT*;
//	using TEMP_ITERATOR = OBJECT_TYPE*;
//private:
//	size_t currentSize;
//	size_t maxSize;
//	OBJECT* arr = nullptr;
//
//	void expand()
//	{
//		if (currentSize == maxSize)
//		{
//			maxSize = maxSize << 1;
//
//			OBJECT* newArr = new OBJECT[maxSize];
//			memcpy(newArr, arr, sizeof(OBJECT) * currentSize);
//			delete[] arr;
//			arr = newArr;
//
//			for (TEMP_ITERATOR i = arr + currentSize; i >= arr; --i)
//			{
//				*(i.second) = i;
//			}
//		}
//	}
//
//public:
//	Vector2()
//	{
//		currentSize = 0;
//		maxSize = 1;
//		arr = new OBJECT[1];
//	}
//
//	~Vector2()
//	{
//		for (TEMP_ITERATOR i = arr + currentSize; i >= arr; --i)
//		{
//			delete i.second;
//		}
//		delete[] arr;
//	}
//
//	void push_back(const OBJECT_TYPE data)
//	{
//		expand();
//		arr[currentSize].first = data;
//		arr[currentSize++].second = new TEMP_ITERATOR(arr + currentSize);
//	}
//
//	void pop()
//	{
//		if (currentSize != 0)
//		{
//			delete (arr + --currentSize).second;
//		}
//	}
//
//	void insert(PERM_ITERATOR iterator, const OBJECT_TYPE data)
//	{
//		expand();
//		memmove(
//			*iterator + 1,
//			*iterator,
//			sizeof(OBJECT) * (arr + currentSize++ - *iterator)
//		);
//		for (TEMP_ITERATOR i = arr + currentSize; i != *iterator; --i)
//		{
//			*(i.second) = i;
//		}
//		*iterator.first = data;
//		*iterator.second = new TEMP_ITERATOR(*iterator);
//	}
//
//	void erase(PERM_ITERATOR iterator)
//	{
//		delete iterator.second;
//		if (iterator != arr + --currentSize)
//		{
//			memmove(
//				*iterator,
//				*iterator + 1,
//				sizeof(OBJECT) * (arr + currentSize - *iterator)
//			);
//			for (TEMP_ITERATOR i = arr + currentSize; i >= *iterator; --i)
//			{
//				*(i.second) = i;
//			}
//		}
//	}
//
//	void clear()
//	{
//		for (TEMP_ITERATOR i = arr + currentSize; i >= arr; --i)
//		{
//			delete i.second;
//		}
//		currentSize = 0;
//	}
//
//	size_t size() const { return currentSize; }
//	OBJECT_TYPE operator[](const size_t index) const { return arr[index].first; }
//	OBJECT_TYPE& operator[](const size_t index) { return arr[index].first; }
//
//	PERM_ITERATOR begin() const { return arr.second; }
//	PERM_ITERATOR end() const { return (arr + currentSize).second; }
//};
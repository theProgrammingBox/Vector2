#include "Vector2.h"
#include <chrono>
#include <vector>

void TestVector2()
{
	std::chrono::duration<float> averageTimePush = std::chrono::duration<float>::zero();
	//std::chrono::duration<float> averageTimePop = std::chrono::duration<float>::zero();
	std::chrono::duration<float> averageTimeErase = std::chrono::duration<float>::zero();
	for (int j = 0; j < 100; j++)
	{
		Vector2<int> v;

		auto tpStart = std::chrono::system_clock::now();
		for (int i = 0; i < 10000; i++)
		{
			v.push(i);
		}

		std::chrono::duration<float> duration = std::chrono::system_clock::now() - tpStart;
		averageTimePush += duration;

		tpStart = std::chrono::system_clock::now();
		while (v.size() != 0)
		{
			//v.pop();
			v.erase(0);
			//v.erase(v.size() - 1);
		}
		duration = std::chrono::system_clock::now() - tpStart;
		//averageTimePop += duration;
		averageTimeErase += duration;

		//std::cout << j << "%" << std::endl;
	}
	std::cout << "Average time push: " << averageTimePush.count() / 100 << " seconds" << std::endl;
	//std::cout << "Average time pop : " << averageTimePop.count() / 100 << " seconds" << std::endl;
	std::cout << "Average time erase: " << averageTimeErase.count() / 100 << " seconds" << std::endl;
}

void TestVector()
{
	std::chrono::duration<float> averageTimePush = std::chrono::duration<float>::zero();
	//std::chrono::duration<float> averageTimePop = std::chrono::duration<float>::zero();
	std::chrono::duration<float> averageTimeErase = std::chrono::duration<float>::zero();
	for (int j = 0; j < 100; j++)
	{
		std::vector<int> v;

		auto tpStart = std::chrono::system_clock::now();
		for (int i = 0; i < 10000; i++)
		{
			v.push_back(i);
		}

		std::chrono::duration<float> duration = std::chrono::system_clock::now() - tpStart;
		averageTimePush += duration;

		tpStart = std::chrono::system_clock::now();
		while (v.size() != 0)
		{
			//v.pop_back();
			v.erase(v.begin());
			//v.erase(v.end() - 1);
		}
		duration = std::chrono::system_clock::now() - tpStart;
		//averageTimePop += duration;
		averageTimeErase += duration;
	}
	std::cout << "Average time push: " << averageTimePush.count() / 100 << " seconds" << std::endl;
	//std::cout << "Average time: " << averageTimePop.count() / 100 << " seconds" << std::endl;
	std::cout << "Average time erase: " << averageTimeErase.count() / 100 << " seconds" << std::endl;
}

int main()
{
	TestVector2();
	TestVector();/**/

	/*Vector2<int> v;
	for (int i = 0; i < 20; i++)
	{
		v.push(i);
	}
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << std::endl;
	}
	std::cout << std::endl;
	v.pop();
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << std::endl;
	}
	std::cout << std::endl;
	v.erase(0);
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << std::endl;
	}*/
	return 0;
}
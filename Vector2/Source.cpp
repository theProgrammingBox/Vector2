#include "Vector2.h"
#include <chrono>
#include <vector>

void TestVector2()
{
	std::chrono::duration<float> averageTimePush = std::chrono::duration<float>::zero();
	std::chrono::duration<float> averageTimeErase = std::chrono::duration<float>::zero();
	for (int j = 0; j < 1000; j++)
	{
		Vector2<int> v;
		//std::vector<int> v;

		auto tpStart = std::chrono::system_clock::now();
		for (int i = 0; i < 100000; i++)
		{
			v.push(i);
			//v.push_back(i);
		}

		std::chrono::duration<float> duration = std::chrono::system_clock::now() - tpStart;
		averageTimePush += duration;

		tpStart = std::chrono::system_clock::now();
		while (v.size() != 0)
		{
			//v.pop();
			//v.erase(v.begin());
			v.erase(v.end() - 1);
		}
		duration = std::chrono::system_clock::now() - tpStart;
		averageTimeErase += duration;

		//std::cout << j << "%" << std::endl;
	}
	std::cout << "Average time push: " << averageTimePush.count() / 100 << " seconds" << std::endl;
	std::cout << "Average time erase: " << averageTimeErase.count() / 100 << " seconds" << std::endl;
}

int main()
{
	TestVector2();

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
	v.erase(v.begin());
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << std::endl;
	}
	std::cout << std::endl;
	v.insert(0, v.begin() + 5);
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << std::endl;
	}
	std::cout << std::endl;

	v[8] = 10;
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << std::endl;
	}
	std::cout << std::endl;*/

	return 0;
}
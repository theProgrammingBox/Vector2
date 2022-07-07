#include "Vector2_.h"

int main()
{
	Vector2<int> v;
	v.push_back(101);
	v.push_back(321);
	v.push_back(345);
	v.pop();
	v.push_back(456);
	v.push_back(645);
	v.push_back(978);
	v.insert(v.begin(), 789);
	v.insert(v.end(), 789);
	v.erase(v.begin());
	v.erase(v.end());

	for (size_t i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << std::endl;
	}

	return 0;
}
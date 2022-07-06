#include "Vector2_.h"

int main()
{
	Vector2<int> v;
	for (int i = 0; i < 100; i++)
	{
		v.push_back(i);
	}

	/*v.insert(5, v.begin());
	v*/

	for (int i = 0; i < 100; i++)
	{
		std::cout << v[i] << std::endl;
	}

	return 0;
}
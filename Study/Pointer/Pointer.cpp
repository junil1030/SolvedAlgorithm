#include <iostream>

void Output(const int* p)
{
	int i = *p;
	int* pInt = (int*)p;
	*pInt = 1000;
}

struct MyStruct
{
	int		a;
	float	f;
};

int main()
{
	int nNum{};

	int* pInt = &nNum;

	*pInt = 10;

	printf("%d\n", nNum);

	int* const pint = &nNum;

	for (int i = 0; i < 10; i++)
	{
		*pInt += 1;
		printf("%d\n", nNum);
	}

	Output(pInt);
	printf("%d\n", nNum);

	void* pVoid = nullptr;

	char szChar[7] = "abcdef";

	int a = 0;

	MyStruct s{};

	s.a;

	MyStruct* pS = &s;

	return 0;
}
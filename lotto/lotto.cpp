// 최종본
#include <iostream>
#include <ctime>
using namespace std;

void swap(int *a, int *b)
{
	int *tmp;
	tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	int iLotto[45];
	int used[46] = {0,};

	srand((unsigned int)time(0));

	for (int i = 0; i < 45; i++)
		iLotto[i] = i + 1;

	int j;
	for (int i = 0; i < 45; i++)
	{
		j = rand() % 45;
		swap(iLotto[i], iLotto[j]);
	}
	for (int i = 0; i < 6; i++)
		cout << iLotto[i] << '\t';
	cout << "bonus num : " << iLotto[6] << endl;
}
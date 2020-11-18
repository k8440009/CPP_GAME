// 야구 게임
#include <iostream>
#include <ctime>
using namespace std;

#define INPUT_ERR 1
#define INPUT_ZERO 2

struct BALL
{
	int strike, ball;
};

void swap(int *a, int *b)
{
	int *tmp;
	tmp = a;
	a = b;
	b = tmp;
}

void shuffle(int number[9])
{
	srand((unsigned int)time(0));

	int j = 0;
	for (int i = 0; i < 9; i++)
	{
		j = rand() % 9;
		swap(number[i], number[j]);
	}
}

int getData(int input[3], int number[9])
{
	int used[10];

	fill_n(used, 10, 0);

	cout << "input data : ";
	for (int i = 0; i < 3; i++)
	{
		cin >> input[i];
		used[input[i]]++;
		if (input[i] == 0)
			return INPUT_ZERO;
	}

	for (int i = 0; i < 3; i++)
	{
		if (used[input[i]] > 1)
		{
			cout << "input error" << endl;
			return INPUT_ERR;
		}
	}
	return 0;
}

void getPoint(BALL &status, int input[3], int number[9])
{
	status.strike = 0, status.ball = 0;
	for (int i = 0; i < 3; i++)
	{
		if (number[i] == input[i])
			status.strike++;
		else
		{
			for (int j = 0; j < 3; j++)
			{
				if (i == j)
					continue;
				
				if (number[i] == input[j])
					status.ball++;
			
			}
		}	
	}
}

int main()
{
	bool flag = true;
	int number[9];
	int input[3];
	BALL ball;

	for (int i = 0; i < 9; i++)
		number[i] = i + 1;
	shuffle(number);
	while(flag)
	{
		int status;
		
		status = getData(input, number);
		if (status == INPUT_ERR)
		{
			cout << "input error" << endl;
			continue;
		}
		else if (status == INPUT_ZERO)
			exit(0);

		getPoint(ball, input, number);
		if (ball.strike == 0 && ball.ball == 0)
			cout << "OUT" << endl;
		else
			cout << ball.strike << " strike " << ball.ball << " ball" << endl;
		if (ball.strike == 3)
			flag = false;
	}
	cout << "answer : " << number[0] << ' ' << number[1] << ' ' << number[2] << endl;
	return 0;
}
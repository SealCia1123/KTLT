#include <ctime>
#include <iostream>
using namespace std;

struct MaTran
{
	int soDong, soCot;
	int **ptr;
};

void generateRandomNumber(MaTran &mt);

void printMatrix(const MaTran mt);

void freeMemMatrix(MaTran &mt);

bool checkPalindrome(const int n);

int sumOfPalindrome(const MaTran mt);

int main()
{
	srand(time(0));
	MaTran mt;
	generateRandomNumber(mt);
	printMatrix(mt);
	cout << "Tong cac so doi xung trong mang la: " << sumOfPalindrome(mt) << endl;
	freeMemMatrix(mt);
	return 0;
}

void generateRandomNumber(MaTran &mt)
{
	do
	{
		cout << "Nhap vao so hang va so cot cua ma tran: ";
		cin >> mt.soDong >> mt.soCot;
		if (mt.soDong < 0 || mt.soCot < 0)
			cout << "Nhap lai so dong va so cot\n";
	} while (mt.soDong < 0 || mt.soCot < 0);
	mt.ptr = new int *[mt.soDong];
	for (int i = 0; i < mt.soDong; i++)
		mt.ptr[i] = new int[mt.soCot];

	int max, min;
	cout << "Nhap vao khoang min, max: ";
	cin >> min >> max;
	for (int i = 0; i < mt.soDong; i++)
	{
		for (int j = 0; j < mt.soCot; j++)
			mt.ptr[i][j] = rand() % (max - min + 1) + min;
	}
}

void printMatrix(const MaTran mt)
{
	for (int i = 0; i < mt.soDong; i++)
	{
		for (int j = 0; j < mt.soCot; j++)
			cout << mt.ptr[i][j] << "\t";
		cout << endl;
	}
}

void freeMemMatrix(MaTran &mt)
{
	for (int i = 0; i < mt.soDong; i++)
		delete[] mt.ptr[i];
	delete[] mt.ptr;
}

bool checkPalindrome(const int n)
{
	int reversedNum = 0;
	int temp = n;
	while (temp)
	{
		int lastDigit = temp % 10;
		reversedNum = reversedNum * 10 + lastDigit;
		temp /= 10;
	}
	return (n == reversedNum) ? true : false;
}

int sumOfPalindrome(const MaTran mt)
{
	int sum = 0;
	for (int i = 0; i < mt.soDong; i++)
	{
		for (int j = 0; j < mt.soCot; j++)
			if (checkPalindrome(mt.ptr[i][j]))
				sum += mt.ptr[i][j];
	}
	return sum;
}

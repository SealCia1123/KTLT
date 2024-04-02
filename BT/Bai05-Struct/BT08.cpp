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

int main()
{
	MaTran mt;
	generateRandomNumber(mt);
	printMatrix(mt);
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
}

void printMatrix(const MaTran mt)
{
	for (int i = 0; i < mt.soDong; i++)
	{
		for (int j = 0; j < mt.soCot; j++)
			cout << mt.ptr[i][j] << " ";
		cout << endl;
	}
}

void freeMemMatrix(MaTran &mt)
{
	for (int i = 0; i < mt.soDong; i++)
		delete[] mt.ptr[i];
	delete[] mt.ptr;
}

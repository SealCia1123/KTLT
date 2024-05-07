/*

De bai:
Cho ma tran voi moi phan tu la mot phan so
a) Nhap va xuat ma tran voi dang tu/mau
b) Toi gian phan so
c) Tinh tong cac phan tu cua ma tran
d) Tim phan so lon nhat cua ma tran
e) Tim va in ra phan so lon nhat tren tung dong

*/

#include <iomanip>
#include <iostream>
#include <stdlib.h>
using namespace std;

int UCLN(int a, int b)
{
	a = abs(a);
	b = abs(b);
	if (b == 0)
		return a;
	return UCLN(b, a % b);
}

struct PhanSo
{
	int tuSo, mauSo;

	void dinhDang()
	{
		if (tuSo == mauSo)
		{
			tuSo = 1;
			mauSo = 1;
		}
		if (mauSo < 0)
		{
			tuSo *= -1;
			mauSo *= -1;
		}
	}

	void toiGian()
	{
		int temp = tuSo;
		tuSo /= UCLN(tuSo, mauSo);
		mauSo /= UCLN(temp, mauSo);
	}

	void nhapPS()
	{
		int tuSo, mauSo;
		do
		{
			cout << "Nhap vao tu so va mau so: ";
			cin >> tuSo >> mauSo;
			if (mauSo == 0)
				cout << "Loi chia cho 0\n";
		} while (mauSo == 0);
		this->tuSo = tuSo;
		this->mauSo = mauSo;
		dinhDang();
	}

	void inPS()
	{
		toiGian();
		dinhDang();
		if (mauSo == 1)
			cout << tuSo;
		else if (tuSo == 0)
			cout << 0;
		else
			cout << tuSo << "/" << mauSo;
	}

	int soSanh(PhanSo p)
	{
		float temp1 = (float)this->tuSo / this->mauSo;
		float temp2 = (float)p.tuSo / p.mauSo;
		if (temp1 == temp2)
			return 0;
		else if (temp1 > temp2)
			return 1;
		return -1;
	}
};

struct MaTranPS
{
	int row, col;
	PhanSo **arr;

	void nhapMT()
	{
		int r, c;
		cout << "Nhap so dong va so cot: ";
		cin >> r >> c;
		row = r;
		col = c;

		arr = new PhanSo *[row];
		for (int i = 0; i < row; i++)
			arr[i] = new PhanSo[col];

		cout << "\nBat dau nhap vao ma tran phan so\n";
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
				arr[i][j].nhapPS();
		}
	}

	void inMT()
	{
		cout << "Ma tran:\n";
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				arr[i][j].inPS();
				cout << "\t";
			}
			cout << "\n";
		}
	}

	void freeMT()
	{
		for (int i = 0; i < row; i++)
			delete[] arr[i];
		delete[] arr;
	}
};

double tongMaTran(const MaTranPS mt)
{
	double sum = 0;
	for (int i = 0; i < mt.row; i++)
	{
		for (int j = 0; j < mt.col; j++)
			sum += (double)mt.arr[i][j].tuSo / mt.arr[i][j].mauSo;
	}
	return sum;
}

PhanSo timPSLonNhat(const MaTranPS mt)
{
	PhanSo p;
	p.tuSo = mt.arr[0][0].tuSo;
	p.mauSo = mt.arr[0][0].mauSo;
	for (int i = 0; i < mt.row; i++)
	{
		for (int j = 0; j < mt.col; j++)
		{
			if ((double)mt.arr[i][j].tuSo / mt.arr[i][j].mauSo < (double)p.tuSo / p.mauSo)
			{
				p.tuSo = mt.arr[i][j].tuSo;
				p.mauSo = mt.arr[i][j].mauSo;
			}
		}
	}
	return p;
}

int main()
{
	MaTranPS p;
	p.nhapMT();
	p.inMT();
	double t = tongMaTran(p);
	cout << "Tong cac phan tu trong ma tran: " << fixed << setprecision(2) << t << "\n";

	PhanSo psLonNhat = timPSLonNhat(p);
	cout << "Phan so lon nhat trong mang: ";
	psLonNhat.inPS();
	cout << "\n";

	p.freeMT();
	return 0;
}

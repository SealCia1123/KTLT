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
			cin >> tuSo;
			cin.ignore();
			cin >> mauSo;
			if (mauSo == 0)
				cout << "Loi chia cho 0\n";
		} while (mauSo == 0);
		this->tuSo = tuSo;
		this->mauSo = mauSo;
		dinhDang();
	}

	void inPS()
	{
		dinhDang();
		if (mauSo == 1)
			cout << tuSo;
		else if (tuSo == 0)
			cout << 0;
		else
			cout << tuSo << "/" << mauSo;
	}

	PhanSo congPS(const PhanSo p1, const PhanSo p2)
	{
		this->tuSo = p1.tuSo * p2.mauSo + p2.tuSo * p1.mauSo;
		this->mauSo = p1.mauSo * p2.mauSo;
		this->toiGian();
		return *this;
	}
};

struct MaTranPS
{
	int row, col;
	PhanSo **arr;

	void nhapMT()
	{
		int r, c;
		do
		{
			cout << "Nhap so dong va so cot: ";
			cin >> r >> c;
			if (r < 0 || c < 0)
				cout << "Nhap khong hop le, nhap lai!\n";
		} while (r < 0 || c < 0);
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

	void toiGianMT()
	{
		cout << "Ma tran:\n";
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
				arr[i][j].toiGian();
		}
	}

	void freeMT()
	{
		for (int i = 0; i < row; i++)
			delete[] arr[i];
		delete[] arr;
	}
};

int soSanh(const PhanSo p1, const PhanSo p2)
{
	double temp1 = (double)p1.tuSo / p1.mauSo;
	double temp2 = (double)p2.tuSo / p2.mauSo;
	if (temp1 == temp2)
		return 0;
	else if (temp1 > temp2)
		return 1;
	return -1;
}

PhanSo tongMT(const MaTranPS mt)
{
	PhanSo sum;
	sum.tuSo = 0;
	sum.mauSo = 1;
	for (int i = 0; i < mt.row; i++)
	{
		for (int j = 0; j < mt.col; j++)
			sum.congPS(sum, mt.arr[i][j]);
	}
	return sum;
}

PhanSo timPSLonNhat(const MaTranPS mt)
{
	PhanSo psLonNhat;
	psLonNhat.tuSo = mt.arr[0][0].tuSo;
	psLonNhat.mauSo = mt.arr[0][0].mauSo;
	for (int i = 0; i < mt.row; i++)
	{
		for (int j = 0; j < mt.col; j++)
		{
			if (soSanh(psLonNhat, mt.arr[i][j]) == -1)
			{
				psLonNhat.tuSo = mt.arr[i][j].tuSo;
				psLonNhat.mauSo = mt.arr[i][j].mauSo;
			}
		}
	}
	return psLonNhat;
}

PhanSo *lonNhatTungDong(const MaTranPS mt)
{
	int index = 0;
	PhanSo *p = new PhanSo[mt.row];
	for (int i = 0; i < mt.row; i++)
	{
		PhanSo temp = mt.arr[i][0];
		for (int j = 0; j < mt.col; j++)
		{
			if (soSanh(temp, mt.arr[i][j]) == -1)
			{
				temp.tuSo = mt.arr[i][j].tuSo;
				temp.mauSo = mt.arr[i][j].mauSo;
			}
		}
		p[index++] = temp;
	}
	return p;
}

PhanSo *lonNhatTungCot(const MaTranPS mt)
{
	int index = 0;
	PhanSo *p = new PhanSo[mt.col];
	for (int j = 0; j < mt.col; j++)
	{
		PhanSo temp = mt.arr[0][j];
		for (int i = 0; i < mt.row; i++)
		{
			if (soSanh(temp, mt.arr[i][j]) == -1)
				temp = mt.arr[i][j];
		}
		p[index++] = temp;
	}
	return p;
}

int main()
{
	MaTranPS mtPS;
	mtPS.nhapMT();
	cout << "=====Ma tran goc=====\n";
	mtPS.inMT();
	cout << "=====Ma tran da toi gian=====\n";
	MaTranPS mtToiGian = mtPS;
	mtToiGian.toiGianMT();
	mtToiGian.inMT();

	PhanSo tong = tongMT(mtPS);
	cout << "\nTong phan so trong ma tran: ";
	tong.inPS();
	cout << "\n";

	PhanSo psLonNhat = timPSLonNhat(mtPS);
	cout << "Phan so lon nhat trong mang: ";
	psLonNhat.inPS();
	cout << "\n";

	PhanSo *dayPSLonNhat = lonNhatTungDong(mtPS);
	cout << "\nCac phan so lon nhat trong tung dong:\n";
	for (int i = 0; i < mtPS.row; i++)
	{
		cout << "Dong " << i + 1 << ": ";
		dayPSLonNhat[i].inPS();
		cout << "\n";
	}

	PhanSo *lonNhatCot = lonNhatTungCot(mtPS);
	cout << "\nCac phan so lon nhat trong tung cot:\n";
	for (int i = 0; i < mtPS.col; i++)
	{
		cout << "Cot " << i + 1 << ": ";
		lonNhatCot[i].inPS();
		cout << "\n";
	}

	delete[] dayPSLonNhat;
	delete[] lonNhatCot;
	mtPS.freeMT();
	return 0;
}
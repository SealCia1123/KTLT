#include <iostream>
using namespace std;

int UCLN(const int a, const int b);

class PhanSo
{
  private:
	int tuSo, mauSo;

  public:
	void setFraction();
	void getFraction();
	void simplify(int &ts, int &ms);
	PhanSo sumFractions(const PhanSo p1, const PhanSo p2);
};

void PhanSo::setFraction()
{
	int a, b;
	do
	{
		cout << "Nhap vao tu so va mau so: ";
		cin >> a >> b;
		if (b == 0)
			cout << "Nhap mau khac 0\n";
	} while (b == 0);
	tuSo = a;
	mauSo = b;
}

void PhanSo::getFraction()
{
	simplify(tuSo, mauSo);
	if (mauSo == 1)
		cout << tuSo << endl;
	else
		cout << tuSo << "/" << mauSo << endl;
}

void PhanSo::simplify(int &ts, int &ms)
{
	int UC = UCLN(tuSo, mauSo);
	ts = ts / UC;
	ms = ms / UC;
}

PhanSo PhanSo::sumFractions(const PhanSo p1, const PhanSo p2)
{
	PhanSo res;
	if (p1.mauSo == p2.mauSo)
	{
		res.tuSo = p1.tuSo + p2.tuSo;
		res.mauSo = p1.mauSo;
	}
	else
	{
		res.tuSo = p1.tuSo * p2.mauSo + p2.tuSo * p1.mauSo;
		res.mauSo = p1.mauSo * p2.mauSo;
	}
	return res;
}

int main()
{
	PhanSo p, q, res;
	p.setFraction();
	p.getFraction();
	q.setFraction();
	q.getFraction();
	res = res.sumFractions(p, q);
	res.getFraction();
	return 0;
}

int UCLN(const int a, const int b)
{
	if (b == 0)
		return a;
	int d = a % b;
	return UCLN(b, d);
}

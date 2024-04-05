#include <cstdlib>
#include <iostream>
using namespace std;

inline int UCLN(int a, int b)
{

	a = abs(a);
	b = abs(b);
	if (b == 0)
		return a;
	int d = a % b;
	return UCLN(b, d);
}

class PhanSo
{
   private:
	int tuSo, mauSo;

   public:
	int getTS()
	{
		return tuSo;
	}

	int getMS()
	{
		return mauSo;
	}

	void setFraction()
	{
		do
		{
			cout << "Nhap vao tu so va mau so: ";
			cin >> tuSo >> mauSo;
			if (mauSo == 0)
				cout << "Nhap mau so khac 0\n";
		} while (mauSo == 0);
	}

	void getFraction()
	{
		if (mauSo == 1)
			cout << tuSo << endl;
		else
			cout << tuSo << "/" << mauSo << endl;
	}

	void simplify(PhanSo &p)
	{
		if (p.mauSo < 0)
		{
			p.tuSo *= -1;
			p.mauSo *= -1;
		}
		int UC = UCLN(p.tuSo, p.mauSo);
		p.tuSo /= UC;
		p.mauSo /= UC;
	}

	PhanSo sumFractions(const PhanSo p1, const PhanSo p2)
	{
		PhanSo result;
		if (p1.mauSo == p2.mauSo)
		{
			result.tuSo = p1.tuSo + p2.tuSo;
			result.mauSo = p1.mauSo;
		}
		else
		{
			result.tuSo = p1.tuSo * p2.mauSo + p2.tuSo * p1.mauSo;
			result.mauSo = p1.mauSo * p2.mauSo;
		}
		simplify(result);
		return result;
	}

	PhanSo subFractions(const PhanSo p1, const PhanSo p2)
	{
		PhanSo result;
		if (p1.mauSo == p2.mauSo)
		{
			result.tuSo = p1.tuSo - p2.tuSo;
			result.mauSo = p1.mauSo;
		}
		else
		{
			result.tuSo = p1.tuSo * p2.mauSo - p2.tuSo * p1.mauSo;
			result.mauSo = p1.mauSo * p2.mauSo;
		}
		simplify(result);
		return result;
	}

	PhanSo mulFractions(const PhanSo p1, const PhanSo p2)
	{
		PhanSo result;
		result.tuSo = p1.tuSo * p2.tuSo;
		result.mauSo = p1.mauSo * p2.mauSo;
		simplify(result);
		return result;
	}

	PhanSo divFractions(const PhanSo p1, const PhanSo p2)
	{
		PhanSo result;
		result.tuSo = p1.tuSo * p2.mauSo;
		result.mauSo = p1.mauSo * p2.tuSo;
		simplify(result);
		return result;
	}
};

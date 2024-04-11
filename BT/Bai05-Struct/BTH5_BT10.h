#include <cstdlib>
#include <iostream>
using namespace std;

class GPG
{
  private:
	int gio, phut, giay;

  public:
	void setTime()
	{
		do
		{
			cout << "Nhap vao gio phut giay: ";
			cin >> gio >> phut >> giay;
			if ((gio < 0 || gio > 24) || (phut < 0 || phut > 60) || (giay < 0 || giay > 60))
				cout << "Thoi gian nhap vao khong hop le\n";
		} while ((gio < 0 || gio > 24) || (phut < 0 || phut > 60) || (giay < 0 || giay > 60));
	}

	void printGPG()
	{
		if (gio < 10)
			cout << 0 << gio << ":";
		else
			cout << gio << ":";
		if (phut < 10)
			cout << 0 << phut << ":";
		else
			cout << phut << ":";
		if (giay < 10)
			cout << 0 << giay << endl;
		else
			cout << giay << endl;
	}

	GPG cal(GPG t1, GPG t2)
	{
		GPG res;
		res.gio = abs(t1.gio - t2.gio);
		res.phut = abs(t1.phut - t2.phut);
		res.giay = abs(t1.giay - t2.giay);
		return res;
	}
};

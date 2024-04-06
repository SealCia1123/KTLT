#include <cstdlib>
#include <iostream>
using namespace std;

class GPG
{
   private:
	int gio, phut, giay;

   public:
	int getHour()
	{
		return gio;
	}

	int getMinute()
	{
		return phut;
	}

	int getSecond()
	{
		return giay;
	}

	void setTime()
	{
		cout << "Nhap vao gio phut giay: ";
		cin >> gio >> phut >> giay;
	}

	GPG cal(const GPG t1, const GPG t2)
	{
		GPG result;
		result.gio = abs(t1.gio - t2.gio);
		result.phut = abs(t1.phut - t2.phut);
		result.giay = abs(t1.giay - t2.giay);
		return result;
	}

	void printGPG()
	{
		cout << gio << ":" << phut << ":" << giay << endl;
	}
};

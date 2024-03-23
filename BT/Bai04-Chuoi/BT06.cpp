#include <climits>
#include <cstring>
#include <iostream>
#define MAX_SIZE 15
using namespace std;

int *split(char *s);

bool isLeapYear(int year);

int daysInMonth(int month, int year);

int countDays(int date, int month, int year);

int main()
{
	char s[MAX_SIZE];
	// Mang chua [ngay][thang][nam]
	int *dates, res;
	do
	{
		cout << "Nhap vao ngay-thang-nam: ";
		cin >> s;
		dates = split(s);
		res = countDays(dates[0], dates[1], dates[2]);
		if (res == INT_MIN)
			cout << "Gia tri ngay thang nam khong hop le\n";
	} while (res == INT_MIN);

	cout << "Ngay " << dates[0] << " thang " << dates[1] << " nam " << dates[2] << " la ngay thu " << res << " trong nam\n";
	delete[] dates;
	dates = NULL;
	return 0;
}

int *split(char *s)
{
	// Tao mang so nguyen theo dinh dang [ngay][thang][nam]
	int *temp = new int[3];
	int i = 0;
	char *p = strtok(s, "-");
	while (p != NULL)
	{
		// Chuyen doi mang char thanh so nguyen
		temp[i++] = atoi(p);
		p = strtok(NULL, "-");
	}
	return temp;
}

bool isLeapYear(int year)
{
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		return true;
	return false;
}

int daysInMonth(int month, int year)
{
	int daysInMonth;
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return daysInMonth = 31;
	case 2:
		return (isLeapYear(year) ? 29 : 28);
	case 4:
	case 6:
	case 9:
	case 11:
		return daysInMonth = 30;
	default:
		return daysInMonth = 0;
	}
}

int countDays(int date, int month, int year)
{
	// Neu nhan vao ngay-thang khong hop le (vd: ngay < 1 || ngay > 31) thi return INT_MIN
	if ((date > 31 || date < 1) || (month > 12 || month < 1) || (month == 2 && date > 29))
		return INT_MIN;

	int result = 0;
	for (int i = 1; i < month; i++)
	{
		switch (daysInMonth(i, year))
		{
		case 30:
			result += 30;
			break;
		case 31:
			result += 31;
			break;
		case 28:
			result += 28;
			break;
		case 29:
			result += 29;
			break;
		}
	}
	return result + date;
}

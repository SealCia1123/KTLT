/*
Cho biết điểm trong mặt phẳng toạ độ gồm hoành độ và tung độ, đường tròn gồm toạ độ tâm và bán kính đường tròn. Viết chương trình thực hiện các chức năng sau:
Nhập thông tin 1 điểm và một đường tròn, kiểm tra điểm có nằm trong đường tròn không?
Nhập thông tin hai đường tròn, kiểm tra hai đường tròn có giao nhau không?
Nhập danh sách đường tròn, sắp xếp kết quả giảm dần theo diện tích, mỗi kết quả xuất ra gồm (toạ độ tâm, bán kính, diện tích).
*/

#include <cmath>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>

const double PI = 3.14;
using namespace std;

struct Point
{
	double x, y;

	void inputPoint()
	{
		double x, y;
		cout << "Nhap vao hoanh do va tung do: ";
		cin >> x >> y;
		this->x = x;
		this->y = y;
	}

	void printPoint()
	{
		cout << "(" << this->x << ", " << this->y << ")";
	}
};

struct Circle
{
	Point centerPoint;
	double radius;

	void inputCircle()
	{
		cout << "Nhap vao tam duong tron\n";
		centerPoint.inputPoint();
		do
		{
			cout << "Nhap vao ban kinh: ";
			cin >> radius;
			if (radius <= 0)
				cout << "Nhap lai ban kinh!\n";
		} while (radius <= 0);
	}

	void printCircle()
	{
		this->centerPoint.printPoint();
		cout << ", r = " << this->radius;
	}
};

double distancePoints(const Point p1, const Point p2)
{
	double result = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
	return result;
}

int pointInsideCircle(const Point p, const Circle c)
{
	double distance = distancePoints(p, c.centerPoint);
	if (distance < c.radius)
		return 1;
	else if (distance == c.radius)
		return 0;
	return -1;
}

double distanceBetweenCircle(const Circle c1, const Circle c2)
{
	double result = sqrt(pow(c1.centerPoint.x - c2.centerPoint.x, 2) + pow(c1.centerPoint.y - c2.centerPoint.y, 2));
	return result;
}

int viTriHaiDuongTron(const Circle c1, const Circle c2)
{
	double distance = distanceBetweenCircle(c1, c2);
	if (distance == 0 || distance < abs(c1.radius - c2.radius) || distance > (c1.radius + c2.radius))
		return 0;
	else if (distance == (c1.radius + c2.radius) || distance == abs(c1.radius - c2.radius))
		return 1;
	return 2;
}

double circleArea(const Circle c)
{
	return PI * c.radius * c.radius;
}

void sortCircleArea(Circle *listCircle, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (circleArea(listCircle[j]) > circleArea(listCircle[j + 1]))
			{
				Circle temp = listCircle[j];
				listCircle[j] = listCircle[j + 1];
				listCircle[j + 1] = temp;
			}
		}
	}
}

int main()
{
	int choice;
	system("clear");
	cout << "1. Nhap 1 diem va 1 duong tron, kiem tra diem co nam trong duong tron khong?\n";
	cout << "2. Nhap 2 duong tron, kiem tra 2 duong tron co giao nhau khong?\n";
	cout << "3. Nhap danh sach cac duong tron, sap xep lai theo dien tich va xuat ra file txt\n";
	cout << "Nhap lua chon: ";
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		Point p;
		Circle c;
		cout << "\nNhap diem\n";
		p.inputPoint();
		cout << "\nNhap duong tron\n";
		c.inputCircle();
		cout << "Diem: P";
		p.printPoint();
		cout << "\n";
		cout << "Duong tron: O";
		c.printCircle();
		cout << "\n";
		if (pointInsideCircle(p, c) == 0)
			cout << "Diem nam tren duong tron\n";
		else if (pointInsideCircle(p, c) == 1)
			cout << "Diem nam trong duong tron\n";
		else
			cout << "Diem nam ngoai duong tron\n";
		break;
	}
	case 2:
	{
		Circle c1, c2;
		cout << "\nNhap duong tron thu 1\n";
		c1.inputCircle();
		cout << "\nNhap duong tron thu 2\n";
		c2.inputCircle();
		cout << "\n=====Thong tin hai duong tron=====\n";
		cout << "O1: ";
		c1.printCircle();
		cout << "\n";
		cout << "O2: ";
		c2.printCircle();
		cout << "\n";
		int diemChung = viTriHaiDuongTron(c1, c2);
		if (diemChung == 0)
			cout << "Hai duong tron khong giao nhau\n";
		else if (diemChung == 1)
			cout << "Hai duong tron tiep xuc\n";
		else
			cout << "Hai duong tron cat nhau\n";
		break;
	}
	case 3:
	{
		int n;
		do
		{
			cout << "Nhap vao so luong duong tron: ";
			cin >> n;
			if (n < 0)
				cout << "Vui long nhap lai!\n";
		} while (n < 0);
		Circle *listCircle = new Circle[n];
		for (int i = 0; i < n; i++)
			listCircle[i].inputCircle();
		sortCircleArea(listCircle, n);
		cout << "=====Thu tu duong tron theo dien tich tang dan=====\n";
		for (int i = 0; i < n; i++)
		{
			cout << "O" << i + 1 << ": ";
			listCircle[i].printCircle();
			cout << "\n";
		}

		ofstream writeCircle;
		writeCircle.open("data.txt", ios::out);
		if (!writeCircle.is_open())
			cout << "Mo file khong thanh cong!\n";
		else
		{
			writeCircle << "=====Danh sach duong tron theo thu tu dien tich tang dan=====\n";
			for (int i = 0; i < n; i++)
			{
				writeCircle << "O" << i + 1 << ": ";
				writeCircle << "(" << listCircle[i].centerPoint.x << ", " << listCircle[i].centerPoint.y << "), r = " << listCircle[i].radius << "\n";
			}
			cout << "Ghi file thanh cong!\n";
			writeCircle.close();
		}
		delete[] listCircle;
		break;
	}
	default:
		cout << "Lua chon khong hop le\n";
	}
	return 0;
}

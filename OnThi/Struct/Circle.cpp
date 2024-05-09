/* Cho biết điểm trong mặt phẳng toạ độ gồm hoành độ và tung độ, đường tròn gồm toạ độ tâm và bán kính đường tròn. Viết chương trình thực hiện các chức năng sau: */
/* Nhập thông tin 1 điểm và một đường tròn, kiểm tra điểm có nằm trong đường tròn không? */
/* Nhập thông tin hai đường tròn, kiểm tra hai đường tròn có giao nhau không? */
/* Nhập danh sách đường tròn, sắp xếp kết quả giảm dần theo diện tích, mỗi kết quả xuất ra gồm (toạ độ tâm, bán
kính, diện tích).
*/
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <string>
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
		cout << "( " << this->x << ", " << this->y << " )";
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
		cout << "Tam: ";
		this->centerPoint.printPoint();
		cout << ", ban kinh: " << this->radius;
	}
};

double distancePoints(const Point p1, const Point p2)
{
	double result = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
	return result;
}

bool pointInsideCircle(const Point p, const Circle c)
{
	double distance = distancePoints(p, c.centerPoint);
	return (distance < c.radius) ? true : false;
}

int main()
{
	Circle c;
	c.inputCircle();
	c.printCircle();
	return 0;
}

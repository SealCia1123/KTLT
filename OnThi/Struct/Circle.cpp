/* Cho biết điểm trong mặt phẳng toạ độ gồm hoành độ và tung độ, đường tròn gồm toạ độ tâm và bán kính đường tròn. Viết chương trình thực hiện các chức năng sau: */
/* Nhập thông tin 1 điểm và một đường tròn, kiểm tra điểm có nằm trong đường tròn không? */
/* Nhập thông tin hai đường tròn, kiểm tra hai đường tròn có giao nhau không? */
/* Nhập danh sách đường tròn, sắp xếp kết quả giảm dần theo diện tích, mỗi kết quả xuất ra gồm (toạ độ tâm, bán
kính, diện tích).
*/
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

struct Point
{
	int x, y;

	void inputPoint()
	{
		int x, y;
		cout << "Nhap vao hoanh do va tung do: ";
		cin >> x >> y;
		this->x = x;
		this->y = y;
	}

	string printPoint()
	{
		return "( " + to_string(this->x) + ", " + to_string(this->y) + " )";
	}
};

struct Circle
{
	Point centerPoint;
	double radius;
};

int main()
{
	Point p1;
	p1.inputPoint();
	cout << p1.printPoint() << endl;
	return 0;
}

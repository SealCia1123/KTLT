#include <iostream>
#include <string>
using namespace std;

struct PhongBan
{
    string maPhongBan;
    string tenPhongBan;
};

int main()
{
    PhongBan p;
    cout << "Nhap ma phong ban: ";
    getline(cin, p.maPhongBan);
    cout << "Nhap ten phong ban: ";
    getline(cin, p.tenPhongBan);
    cout << "Ma phong ban: " << p.maPhongBan << endl;
    cout << "Ten phong ban: " << p.tenPhongBan << endl;
    return 0;
}

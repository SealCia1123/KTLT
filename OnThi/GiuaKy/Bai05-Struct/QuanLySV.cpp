#include <fstream>
#include <iostream>
#include <string.h>
#include <string>
#define SO_MON 3
using namespace std;

struct SinhVien
{
	int MSSV;
	string hoTen;
	char queQuan[30];
	int diemMonHoc[SO_MON];
};

struct DanhSachSV
{
	int soLuong;
	SinhVien *sv;
};

void readFile(DanhSachSV &ds);

void print(const DanhSachSV ds);

DanhSachSV sapXepTenGiamDan(const DanhSachSV ds);

void swapSV(SinhVien &sv1, SinhVien &sv2);

int main()
{
	DanhSachSV ds;
	readFile(ds);
	print(ds);
	cout << "================Thu tu ten giam dan===================\n";
	DanhSachSV dsGiamDan = sapXepTenGiamDan(ds);
	print(dsGiamDan);
	return 0;
}

void readFile(DanhSachSV &ds)
{
	ifstream f;
	f.open("data.txt", ios::in);
	f >> ds.soLuong;
	ds.sv = new SinhVien[ds.soLuong];
	f.ignore();
	for (int i = 0; i < ds.soLuong; i++)
	{
		f >> ds.sv[i].MSSV;
		f.ignore();
		getline(f, ds.sv[i].hoTen);
		f.getline(ds.sv[i].queQuan, 30);
		for (int j = 0; j < SO_MON; j++)
		{
			f >> ds.sv[i].diemMonHoc[j];
			f.ignore();
		}
	}
	f.close();
}

void print(const DanhSachSV ds)
{
	cout << "====IN THONG TIN SINH VIEN====\n";
	for (int i = 0; i < ds.soLuong; i++)
	{
		cout << "====Sinh vien thu " << i + 1 << "====\n";
		cout << "MSSV: " << ds.sv[i].MSSV << "\n";
		cout << "Ho ten: " << ds.sv[i].hoTen << "\n";
		cout << "Que quan: " << ds.sv[i].queQuan << "\n";
		cout << "Diem cac mon:\t";
		for (int j = 0; j < SO_MON; j++)
			cout << ds.sv[i].diemMonHoc[j] << "\t";
		cout << "\n";
	}
}

void swapSV(SinhVien &sv1, SinhVien &sv2)
{
	// Tao temp
	SinhVien temp;
	temp.MSSV = sv1.MSSV;
	temp.hoTen = sv1.hoTen;
	strcpy(temp.queQuan, sv1.queQuan);
	for (int i = 0; i < SO_MON; i++)
		temp.diemMonHoc[i] = sv1.diemMonHoc[i];

	// Gan a cho b
	sv1.MSSV = sv2.MSSV;
	sv1.hoTen = sv2.hoTen;
	strcpy(sv1.queQuan, sv2.queQuan);
	for (int i = 0; i < SO_MON; i++)
		sv1.diemMonHoc[i] = sv2.diemMonHoc[i];

	// Gan b cho temp
	sv2.MSSV = temp.MSSV;
	sv2.hoTen = temp.hoTen;
	strcpy(sv2.queQuan, temp.queQuan);
	for (int i = 0; i < SO_MON; i++)
		sv2.diemMonHoc[i] = temp.diemMonHoc[i];
}

DanhSachSV sapXepTenGiamDan(const DanhSachSV ds)
{
	DanhSachSV result;
	result.soLuong = ds.soLuong;
	result.sv = new SinhVien[result.soLuong];
	for (int i = 0; i < ds.soLuong; i++)
		result.sv[i] = ds.sv[i];

	for (int i = 0; i < result.soLuong - 1; i++)
	{
		for (int j = i + 1; j < result.soLuong; j++)
		{
			if (result.sv[i].hoTen < result.sv[j].hoTen)
				swapSV(result.sv[i], result.sv[j]);
		}
	}
	return result;
}

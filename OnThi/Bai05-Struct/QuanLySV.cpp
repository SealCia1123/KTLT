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

DanhSachSV sortNameDescending(const DanhSachSV ds);

DanhSachSV sortHomeAscending(const DanhSachSV ds);

void swapSV(SinhVien &sv1, SinhVien &sv2);

DanhSachSV searchName(const DanhSachSV ds);

bool datHocBong(const SinhVien sv);

DanhSachSV dsDatHocBong(const DanhSachSV ds);

void xuatDSHocBong(const DanhSachSV ds);

int main()
{
	DanhSachSV ds;
	readFile(ds);
	print(ds);

	cout << "\n================Thu tu ten giam dan===================\n";
	DanhSachSV tenGiamDan = sortNameDescending(ds);
	print(tenGiamDan);

	cout << "\n================Thu tu que quan tang dan===================\n";
	DanhSachSV queTangDan = sortHomeAscending(ds);
	print(queTangDan);

	cout << "\n==================Danh sach sinh vien tim thay===================\n";
	DanhSachSV timKiem = searchName(ds);
	print(timKiem);

	DanhSachSV hocBong = dsDatHocBong(ds);
	xuatDSHocBong(hocBong);

	delete[] ds.sv;
	delete[] tenGiamDan.sv;
	delete[] queTangDan.sv;
	delete[] timKiem.sv;
	delete[] hocBong.sv;
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
	for (int i = 0; i < ds.soLuong; i++)
	{
		cout << "\n================================\n";
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
	SinhVien temp;
	temp.MSSV = sv1.MSSV;
	temp.hoTen = sv1.hoTen;
	strcpy(temp.queQuan, sv1.queQuan);
	for (int i = 0; i < SO_MON; i++)
		temp.diemMonHoc[i] = sv1.diemMonHoc[i];

	sv1.MSSV = sv2.MSSV;
	sv1.hoTen = sv2.hoTen;
	strcpy(sv1.queQuan, sv2.queQuan);
	for (int i = 0; i < SO_MON; i++)
		sv1.diemMonHoc[i] = sv2.diemMonHoc[i];

	sv2.MSSV = temp.MSSV;
	sv2.hoTen = temp.hoTen;
	strcpy(sv2.queQuan, temp.queQuan);
	for (int i = 0; i < SO_MON; i++)
		sv2.diemMonHoc[i] = temp.diemMonHoc[i];
}

DanhSachSV sortNameDescending(const DanhSachSV ds)
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

DanhSachSV sortHomeAscending(const DanhSachSV ds)
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
			if (strcmp(result.sv[i].queQuan, result.sv[j].queQuan) > 0)
				swapSV(result.sv[i], result.sv[j]);
		}
	}
	return result;
}

DanhSachSV searchName(const DanhSachSV ds)
{
	string name;
	cout << "Nhap vao ten can tim: ";
	getline(cin, name);
	DanhSachSV result;
	result.soLuong = 0;
	result.sv = new SinhVien[ds.soLuong];
	for (int i = 0; i < ds.soLuong; i++)
	{
		if (ds.sv[i].hoTen.find(name) != string::npos)
			result.sv[(result.soLuong)++] = ds.sv[i];
	}
	return result;
}

bool datHocBong(const SinhVien sv)
{
	double diemTong = 0;
	for (int i = 0; i < SO_MON; i++)
	{
		if (sv.diemMonHoc[i] < 5)
			return false;
		diemTong += sv.diemMonHoc[i];
	}
	return (diemTong / SO_MON > 7.5) ? true : false;
}

DanhSachSV dsDatHocBong(const DanhSachSV ds)
{
	DanhSachSV result;
	result.sv = new SinhVien[ds.soLuong];
	result.soLuong = 0;

	for (int i = 0; i < ds.soLuong; i++)
	{
		if (datHocBong(ds.sv[i]) == true)
			result.sv[(result.soLuong)++] = ds.sv[i];
	}
	return result;
}

void xuatDSHocBong(const DanhSachSV ds)
{
	ofstream f;
	f.open("hocbong.txt", ios::out);
	f << "Danh sach dat hoc bong" << endl;
	for (int i = 0; i < ds.soLuong; i++)
	{
		f << "\n=====Sinh vien thu " << i + 1 << "=====" << endl;
		f << "MSSV: " << ds.sv[i].MSSV << endl;
		f << "Ho ten: " << ds.sv[i].hoTen << endl;
		f << "Que quan: " << ds.sv[i].queQuan << endl;
		f << "Diem:\t";
		for (int j = 0; j < SO_MON; j++)
			f << ds.sv[i].diemMonHoc[j] << "\t";
		f << endl;
	}
	f.close();
}

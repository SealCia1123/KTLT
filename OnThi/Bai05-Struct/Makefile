CXXFLAGS = -Wall --std=c++23
SV: QuanLySV.cpp
	g++ QuanLySV.cpp $(CXXFLAGS) -o .output/QuanLySV; .output/QuanLySV

MT: MaTran.cpp
	g++ MaTran.cpp $(CXXFLAGS) -o .output/MaTran; .output/MaTran

PS: PhanSo.cpp
	g++ PhanSo.cpp $(CXXFLAGS) -o .output/PhanSo; .output/PhanSo

clean:
	rm .output/*

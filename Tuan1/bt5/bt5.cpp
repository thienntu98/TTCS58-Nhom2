#include <iostream>
#include<conio.h>
#include<math.h>
#include<fstream>
#define MAX 29
using namespace std;
struct Co {
	int tren;
	int duoi;
};
Co a[29];
int ttluu[29], tt[29], cl = 168, dolech;
int n, dem = 0;;
void NhapCo(int &n) {
	cout << "Nhap so quan co: ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cout << "Quan co thu: " << i << endl;
		cout << "Mat tren: ";
		do {
			cin >> a[i].tren;
		} while (a[i].tren <= 0 || a[i].tren > 6);
		cout << "Mat duoi: ";
		do {
			cin >> a[i].duoi;
		} while (a[i].duoi <= 0 || a[i].duoi > 6);
	}
	for (int i = 1; i <= n; i++)
		cout << a[i].tren << "   " << a[i].duoi << "   " << endl;
}

void KiemTra() {
	int tren = 0, duoi = 0, dochenh;
	for (int i = 1; i <= n; i++)
	{
		if (tt[i] == 0)
		{
			tren += a[i].tren;
			duoi += a[i].duoi;
		}
		else
		{
			tren += a[i].duoi;
			duoi += a[i].tren;
		}
	}
	dochenh = abs(tren - duoi);
	if (dochenh < cl)
	{
		cl = dochenh;
		dolech = dochenh;
		for (int k = 1; k <= n; k++)
			ttluu[k] = tt[k];
	}
}

void Xuat() {
	cout<<"Trang thai sau khi xoay: ";
	for (int i = 1; i <= n; i++)
	{
		if (ttluu[i] == 1)
		{
			dem++;
		}
		cout << ttluu[i] << "   ";
	}
	cout << "\nDo chenh lech = " << dolech<< "   So lan xoay: " << dem<<endl;
}

void Thu(int i) {
	int k;
	for (k = 0; k <= 1; k++)
	{
		tt[i] = k;
		if (i < n) {
			i++;
			Thu(i);
		}
		else	KiemTra();
		tt[i] = 0;
	}
}

void DocFile(int &n){
	int data;
	ifstream co;
	co.open("bt5.txt");
	co >> data;
	n = data;
	for (int i = 1; i <= n; i++)
	{
		co >> data;
		a[i].tren = data;
		co >> data;
		a[i].duoi = data;
	}
	co.close();
}

void InFile(){
	ofstream co;
	co.open("kqbt5.txt");
	Thu(1);
	Xuat();
	co<<"Trang thai sau khi xoay: ";
	for (int i = 1; i <= n; i++)
	{
		co << ttluu[i] << "   ";
	}
	co<<"\nDo chenh lech nho nhat: "<<cl<<"  So lan xoay: "<<dem;
	co.close();
	
}


int main()
{
	DocFile(n);
	InFile();
	getch();
}



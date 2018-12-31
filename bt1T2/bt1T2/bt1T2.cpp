#include "pch.h"
#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

int A[10][10];
int n, hang, cot;

void NhapMT(int &n, int A[10][10]) {
	do
	{
		cout << "Nhap cap ma tran: ";
		cin >> n;
	} while (n < 3 || n > 10);
	hang = n; cot = n;
	srand(time(NULL));
	for(int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			A[i][j] = rand()%100 + 1;//rand()%101 +1 từ công thức rand()%(b - a +1) + 1,, số ngẫu nhiên trong khoảng [a, b]
		}
}

void XuatMT(int A[10][10]) {
	for (int i = 0; i < hang; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			cout << A[i][j] << "     ";
		}
		cout << endl;
	}
}

void XoaDong(int &hang,int A[10][10]) {
	int dong;
	cout << endl << "Nhap hang can xoa: ";
	cin >> dong;
	for(int index = 0; index < hang; index++)	
		if (dong == index)//tìm được dòng cần xóa
		{
			for(int i = index; i < hang; i++)//vòng lặp for bắt đầu từ vị trí dòng cần xóa
				for (int j = 0; j < cot; j++)
				{
					A[i][j] = A[i + 1][j];//gán giá trị hàng i = i+1
				}
			hang--;//trừ đi 1 hàng.
			return;
		}
}

void XoaCot(int &cot, int A[10][10]) {
	int m;
	cout << endl << "Nhap hang can xoa: ";
	cin >> m;
	for (int index = 0; index < cot; index++)
		if (m == index)//tìm được cột cần xóa
		{
			for (int i = 0; i < hang; i++)
				for (int j = index; j < cot; j++)//vòng lặp for bắt đầu từ vị trí cột cần xóa
				{
					A[i][j] = A[i][j+1];//gán giá trị hàng i = i+1
				}
			cot--;//trừ đi 1 hàng.
			return;
		}
}

bool KiemTraDX(int hang, int cot, int A[10][10])
{
	if (hang != cot) return 0;//Nếu ma trận không vuông thì ma trận không đối xứng
	for (int i = 0; i < cot - 1; i++)//xét từ hàng 0 dến hàng n - 2, vì hàng n -1 ta không có giá trị để xét 
		for (int j = i + 1; j < cot; j++)//Xét 2 điểm đối xứng qua đường trục chính
			if (A[i][j] != A[j][i])//Nếu không bằng nhau thì xuất 0 tương đương cới không đối xứng
				return 0;
	return 1;
}

void XuatDX() {
	if (KiemTraDX(hang, cot, A) == 0)
		cout << endl << "MA TRAN KHONG DOI XUNG!!!";
	else cout << endl << "MA TRAN NAY DOI XUNG!!!";
}

bool MaxCheo(int i, int j){
	int k, h;
	for (k = i, h = j; k >= 0 && h < cot; k--, h++)
		if (A[k][h] > A[i][j])
			return false;

	for (k = i + 1, h = j - 1; k < hang && h >= 0; k++, h--)
		if (A[k][h] > A[i][j])
			return false;

	for (k = i - 1, h = j - 1; k >= 0 && h >= 0; k--, h--)
		if (A[k][h] > A[i][j])
			return false;

	for (k = i + 1, h = j + 1; k < hang && h < cot; k++, h++)
		if (A[k][h] > A[i][j])
			return false;

	return true;
}

bool MaxDoc(int i, int j) {
	for (int k = 0; k < hang; k++)
		if (A[k][j] > A[i][j])
			return false;
	for (int k = 0; k < cot; k++)
		if (A[i][k] > A[i][j])
			return false;
	return true;
}

void KiemTraHH() {
	int dem = 0;//đếm số lượng hoàng hậu
	cout << endl << "So hoang hau trong ma tran: ";
	for(int i = 0; i < hang; i++)
		for(int j = 0; j < cot;j++)
			if (MaxCheo(i, j) && MaxDoc(i, j))
			{
				cout << A[i][j] << "     ";
				dem++;
			}
}

int main() {
	NhapMT(n, A);
	XuatMT(A);
	XoaDong(hang, A);
	XuatMT(A);
	XoaCot(cot, A);
	XuatMT(A);
	XuatDX();
	KiemTraHH();
}
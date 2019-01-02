#include "BigNum.h"
#include<iostream>
#include<string>

using namespace std;

void BigNum::Nhap(){
	string str;
	getline(cin, str);
	n = str.size();
	for(int i = 0; i <= n -1 ; i++)
		data[i] = str.at(i) - '0';
	cout<<endl;
}

void BigNum::Xuat(){
	int dem = 0;
	for(int i = 0; i <= n-2; i++)
		if(data[i] == 0)	
			dem+=1;
		else 
			break;
	for(int i = dem; i <= n-1; i++)
		cout<<data[i];
	cout<<endl;
}

void BigNum::Cong(BigNum a, BigNum b){
	if(a.n > b.n)
		{
			n = a.n;
			for(int i = n - 1; i >= n - b.n; i--)
				b.data[i] = b.data[i - (n - b.n)];
			for(int i = 0; i < n - b.n; i++)
				b.data[i] = 0;
		}
	else
		{
			n = b.n;
			for(int i = n - 1; i >= n - a.n; i--)
				a.data[i] = a.data[i - (n - a.n)];
			for(int i = 0; i < n - a.n; i++)
				a.data[i] = 0;
		}
	int nho = 0, tg;
	for(int i = n - 1; i >= 0; i--)
		{
			tg = a.data[i] + b.data[i] + nho;
			nho = tg/10;
			tg = tg%10;
			data[i] = tg;
		}
	cout<<endl;
}

bool BigNum::KiemTran(BigNum a){
	if(n > a.n)
		return 1;
	if(n < a.n)
		return 0;
	else
		for(int i=0; i <= n -1; i++)
			{
				if(data[i] > a.data[i])
					return 1;
				if(data[i] < a.data[i])
					return 0;
			}
}

void BigNum::Tru(BigNum a, BigNum b){
	if(a.KiemTran(b) == 1)//so nguyen a > b thi ta tru binh thuong
		{
			n = a.n;//gan chieu dai cua kq = chieu dai cua so nguyen a
			if(a.n > b.n)//neu chieu dai so b nho hon a thi ta dua so b bang chieu dai so a
			{
				for(int i = n - 1; i >= n - b.n; i--)
					b.data[i] = b.data[i - (n - b.n)];//dua gia tri ra sau
				for(int i = 0; i < n - b.n; i++)
					b.data[i] = 0;//gan cac gia tri dau bang 0
			}

			int nho = 0;//nho dung de luu tru muon
			for(int i = n - 1; i >= 0; i--)
			{
				b.data[i] += nho;//a muon 1 truoc nen b + them 1
				if(a.data[i] < b.data[i])//neu a < b thi ta cho a muon 10 
					{
						a.data[i] += 10;
						data[i] = a.data[i] - b.data[i]; 
						nho = 1;//khi muon thi luu gia tri muon lai
					}
		
				else{//a > b tru binh thuong va khong muon de tru nen gan gia tri muon bang 0
						data[i] = a.data[i] - b.data[i];
						nho = 0;
					}
			}
			cout<<endl;				
		}
	else// so nguyen b lon hon a thi ta lay b - a va ket qua nhan cho (-1)
		{
			n = b.n;
			if(b.n > a.n)//chinh cho chieu dai a = b
			{
				for(int i = n - 1; i >= n - a.n; i--)
					a.data[i] = a.data[i - (n - a.n)];
				for(int i = 0; i < n - a.n; i++)
					a.data[i] = 0;
			}
			int nho = 0, tg;
			for(int i = n - 1; i >= 0; i--)//thuc hien b - a
			{
				a.data[i] += nho;
				if(b.data[i] < a.data[i])
					{
						b.data[i] += 10;
						data[i] = b.data[i] - a.data[i]; 
						nho = 1;
					}
		
				else{
						data[i] = b.data[i] - a.data[i];
						nho = 0;
					}
			}
			for(int i = 0; i <= n -1; i++)//thuc hien nhan ket qua voi (-1)
				if(data[i] != 0)//nhan voi so dau khac 0
					{
						data[i] = data[i]*(-1);
						return;
					}
			cout<<endl;	
		}
}

void BigNum::Nhan(BigNum a, BigNum b){
	n = a.n + b.n;//chieu dai mang ket qua
	int *luu;//mang luu cac ket qua nhan
	luu = new int[n];
	for(int i = 0; i <= n-1; i++)//khoi tao gia tri dau cho mang
		luu[i] = 0;
	for(int i = a.n - 1; i >= 0; i--)//tong gia tri da nhan trong tung vi tri cua mang
			for(int j = b.n - 1; j >= 0; j--)
				luu[i+j+1] += a.data[i] * b.data[j];
	for(int i = n-1; i >= 0; i--)//chuyen tong tren thanh so nguyen
		if(luu[i] > 9)
			{
				luu[i-1] += luu[i]/10;
				luu[i] = luu[i]%10;
			}
	for(int i = 0; i <= n-1; i++)//dua ket qua ra ngoai
		data[i] = luu[i];	
}

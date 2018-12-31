#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include<ctime>
#define max 50
using namespace std;



void TaoMang(int a[max],int &n)
{
	srand(time(0));
	for(int i=0;i<n;i++)
	{
		a[i]=rand()%51;
	}
}

//nhap mang 

void NhapMang(int a[max],int &n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"\nnhap phan tu: "<<i<<" ";
		cin>>a[i];
	}
}


void XuatMang(int a[max],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<"\t";
	}
}
//hoan vi
void swap(int &a,int &b)
{
	int tmp=a;
	a=b;
	b=tmp;
}
// a[i] la cay goc
// cay co root la i(lar)
// n la kich thuoc cua dong
void heapify(int a[max],int n,int i)
{
	// khoi tao
	int lar=i;
	int left= (2*i)+1;
	int right= (2*i)+2;
	//neu con trai lon hon lar
	if(left<n && a[left]> a[lar])
		lar=left;
	//neu con phai lon hon lar
	if(right<n&& a[right]>a[lar])
		lar=right;
	//neu i khong phai la root lon nhat
	if(lar != i)
	{
		swap(a[i],a[lar]);
		//de quy lai ham
		heapify(a,n,i);
	}
}
// sap xep 
void heapsort(int a[max],int n)
{
	//tao mot dong
	cout<<"\n\n		==================TAO CAY===============================\n";
	for(int i=n/2-1;i>=0;i--)
	{
		cout<<"\n\nDuyet lan "<<i<<": "<<a[i]<<endl;
		heapify(a,n,i);
		XuatMang(a, n);
		getch();
	}
	//qua trinh dung lai khi con 1 phan tu(trich xuat tung phan tu)
	cout<<"\n\n		================SAP XEP TANG DAN========================";
	for(int i=n-1;i>=0;i--)
	{
		cout<<endl<<"\nSap xep "<<i<<": "<<a[i]<<endl;
		// di chuyen ve nut cuoi cung
		swap(a[0],a[i]);
		//goi ham heapify
		heapify(a,i,0);
		XuatMang(a, n);
		getch();
	}
}


int main()
{
	int a[max],n;
	cout<<"\nnhap so phan tu cua mang: ";
	cin>>n;
//	nhapmang(a,n);
	TaoMang(a,n);
	XuatMang(a,n);
	heapsort(a,n);
	cout<<"\n sau khi vun dong: \n";
	XuatMang(a,n);
}









#include<iostream>
#include<ctime>
#include<cstdlib>
#include<conio.h>

using namespace std;
int n, m, A[1000], B[1000];
void Nhap(){//Nhap m so ngau nhien
	do{
		cout<<"Nhap so luong phan tu: ";
		cin>>m;//so luong so nguyen
	}while(m< 0 || m >= 1000);
	srand(time(NULL));
	for(int i = 0; i < m; i++)
		A[i] = rand()%100 + 1;//Nhap mot so ngau nhien tu 1 - 100
}

void Xuat(int a[], int sl){//Xuat mang
	cout<<"Day so nguyen: ";
	for(int i = 0; i < sl; i++)
		cout<<a[i]<<"   ";
}

void TimSoNgauNhien(){
	int so;
	Nhap();
	cout<<"Nhap so luong phan tu ngau nhien muon tim kiem(n < m): ";
	do{
		cin>>n;
	}while(n>=m);
	srand(time(NULL));//tinh time
	for(int i = 0; i < n; i++)
		{
			so = rand()%m;//vi tri muon xuat trong mang A rand()%m de xuat ra vi tri nam trong pham vi tu 0 - m
			B[i] = so;//Luu lai vi tri muon xuat
			cout<<A[so]<<"   ";	//xuat gia tri tai vi tri so ra man hinh
		}
	cout<<endl;	
}

int main(){
	int chon;
	    do
    {
        system("cls");
        cout<<("\t\t\t 1. Chay chuong trinh.\n");
        cout<<("\t\t\t 2. Thoat.\n");
        cout<<("Ban chon: ");
        cin>>(chon);
        switch(chon)
        {
            case 1:
 				TimSoNgauNhien();
 				cout<<"(Mang A)";
 				Xuat(A, m);
 				cout<<"\n(Mang vit tri)";
 				Xuat(B, n);
                break;
            case 2:
                break;
            default:
                cout<<"Ban chon sai. Moi ban chon lai\n";
                break;
        }
        getch();
    }while(chon!=2);
}

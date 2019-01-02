#include "BigNum.h"
#include<iostream>
#include<conio.h>

using namespace std;
BigNum a, b, c;
int chon, x;
int main(){
    do
    {
        system("cls");
        cout<<("\t\t\t ============MENU================================\n");
        cout<<("\t\t\t |1. Nhap so nguyen A                           |\n");
        cout<<("\t\t\t |2. Nhap so nguyen B                           |\n");
        cout<<("\t\t\t |3. Cong hai so nguyen A + B                   |\n");
        cout<<("\t\t\t |4. Tru hai so nguyen A - B                    |\n");
        cout<<("\t\t\t |5. Nhan hai so nguyen A*B                     |\n");
        cout<<("\t\t\t |6. Thoat                                      |\n");
        cout<<("\t\t\t ================================================\n");
        cout<<("Ban chon: ");
        cin>>(chon);
        switch(chon)
        {
            case 1:
            	cout<<"Nhap so nguyen A: ";
            	fflush(stdin);
             	a.Nhap();
                break;
            case 2:
            	cout<<"Nhap so nguyen B: ";
            	fflush(stdin);
                b.Nhap();
                break;
            case 3:
 				c.Cong(a, b);
 				cout<<"A = ";
				a.Xuat();
				cout<<"B = ";
 				b.Xuat();
 				cout<<"A + B = ";
 				c.Xuat();
                break;
            case 4:
 				c.Tru(a, b);
 				a.Xuat();
 				b.Xuat();
 				cout<<"A - B = ";
 				c.Xuat();
                break;
            case 5:
    			c.Nhan(a, b);
    			a.Xuat();
    			b.Xuat();
				cout<<"A * B = ";
    			c.Xuat();
                break;
            case 6:
                break;
            default:
                printf("Ban chon sai. Moi ban chon lai MENU!\n");
                break;
        }
        getch();
    }while(chon!=6);
}

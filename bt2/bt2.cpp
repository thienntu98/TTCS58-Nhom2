#include <iostream>
#include <conio.h>
#include <windows.h>
#include<fstream>
using namespace std;

ifstream file("chuthich.txt");
struct date
{
    int d;//ngay
	int m;//thang
	int y;//nam
	int a;//ngay du
};

date x;
int month[42];
int i,j,ngaymax,ngaydu,thu;//i, j toa  do cua ngay trong mang, ngaymax: ngay lon nhat cua thang, ngaydu: so ngay thua cua 1 thang, thu: luu so ngay trong nam
char key;//bien tuong tac voi ban phim
//to mau chu
void textcolor(int x)
{
	HANDLE mau; 
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}

//Kiem tra nam nhuan hay ko
int nhuan(date x) 
{
    return (x.y%4==0 && x.y%100 != 0 || x.y % 400 == 0)?1:0;//1 la nam nhuan, 0 la khong phai nam nhuan
}

//Tinh khoang cach tu ngay nhap vao voi ngay 1/1/1
long TinhNgay(date x) 
{
    return x.d-1+(x.m-1)*30+(x.y-1)*365+x.a+(x.y-1)/4;
}

void Nhap(date &x){
	do
    {
        cout<<"\nXin loi, thang (nam) ban vua nhap ko hop le,xin nhap lai\n-\n";
        cout<<"Nhap thang, nam (vi du 11 2007): ";
        fflush(stdin);
		cin>>x.m>>x.y;
    } while(x.y < 0 || x.m < 1 || x.m > 12);
}
//Tinh toan va nhap tat ca cac ngay trong thang vao mang? month[42]
void NhapLich(date x){
	switch(x.m)
    {
        case 1: ngaymax=31; ngaydu=0; break;
        case 2: if(nhuan(x)) ngaymax=29; else ngaymax=28; ngaydu=1;  break;
        case 3: ngaymax=31; ngaydu=-1+nhuan(x); break;
        case 4: ngaymax=30; ngaydu=nhuan(x); break;
        case 5: ngaymax=31; ngaydu=nhuan(x); break;
        case 6: ngaymax=30; ngaydu=1+nhuan(x); break;
        case 7: ngaymax=31; ngaydu=1+nhuan(x); break;
        case 8: ngaymax=31; ngaydu=2+nhuan(x); break;
        case 9: ngaymax=30; ngaydu=3+nhuan(x); break;
        case 10: ngaymax=31; ngaydu=3+nhuan(x); break;
        case 11: ngaymax=30; ngaydu=4+nhuan(x); break;
        case 12: ngaymax=31; ngaydu=4+nhuan(x); break;
    }
    x.a=ngaydu;
    x.d=1; //Gan ngay la ngay mung 1
    thu=TinhNgay(x)%7; //de tinh thu cua ngay dau tien cua thang 1: thu 2 2: thu3 .... 7:chu nhat.
    //Gan tat ca ngay trong thang vao mang 
    for(i=0;i<5;i++)// 5 la so hang de in ra lich
    {
        for(j=0;j<7;j++)// moi hang bao gom 7 ngay
        {
            if(7*i+j+1<=ngaymax) 
			month[7*i+j+thu]=7*i+j+1;
        }
    }
    for(i=0;i<thu;i++)
        month[i]=32; //Gan gia tri tam thoi bieu thi nhung ngay ko ton tai
    for(i=ngaymax+thu;i<42;i++)
        month[i]=32; //Gan gia tri tam thoi bieu thi nhung ngay ko ton tai
}

void TimNgay(date x){
	int ngay, thutk;
	do{
		cout<<"\nNhap ngay muon tim: Ngay ";
		cin>>ngay;
	}while(ngay <= 0 || ngay > ngaymax);
	thutk = (ngay+thu-1)%7;
	textcolor(4);
	switch(thutk){
		case 1:
			cout<<"\nThu hai "<<ngay<<"/"<<x.m<<"/"<<x.y<<"\n";
			break;
		case 2:
			cout<<"\nThu ba "<<ngay<<"/"<<x.m<<"/"<<x.y<<"\n";
			break;
		case 3:
			cout<<"\nThu tu "<<ngay<<"/"<<x.m<<"/"<<x.y<<"\n";
			break;
		case 4:
			cout<<"\nThu Nam "<<ngay<<"/"<<x.m<<"/"<<x.y<<"\n";
			break;
		case 5:
			cout<<"\nThu sau "<<ngay<<"/"<<x.m<<"/"<<x.y<<"\n";
			break;
		case 6:
			cout<<"\nThu bay "<<ngay<<"/"<<x.m<<"/"<<x.y<<"\n";
			break;
		case 0:
			cout<<"\nChu nhat "<<ngay<<"/"<<x.m<<"/"<<x.y<<"\n";
			break;
	}
	textcolor(15);
}

//Xuat lich ra man hinh
void Xuat(date x){
    cout<<"\n\n\t\t\t------------------------------------------------------\n";
	cout<<"\t\t\t                       "<<x.m<<" , "<<x.y<<"\n";
    cout<<"\t\t\t------------------------------------------------------\n";
	cout<<"\t\t\tCN\tThu 2\tThu 3\tThu 4\tThu 5\tThu 6\tThu 7\n\n";
    for(i=0;i<6;i++)
    {
        cout<<"\t\t\t";
        for(j=0;j<7;j++)
        {
            if(month[7*i+j]==32) cout<<"\t"; //Thay the gia tri tam thoi bang null
            else if(j == 0)
            		{
            			textcolor(4);
            			cout<<month[7*i+j]<<"\t";
					}
				else	{
					textcolor(15);
					cout<<month[7*i+j]<<"\t";
				}
        }
        cout<<"\n";
    }
    textcolor(15);
}

date TangThang(date &x){
	x.m += 1;
	if(x.m>12)
	{
		x.y += 1;
		x.m = 1;
		
	}
	return x;
}

date GiamThang(date &x){
	x.m -= 1;
	if(x.m < 1)
	{
		x.m = 12;
		x.y -= 1;
		if(x.y<1)
		{
			x.d=1;
			x.m=1;
			x.y=1;
		}
	}
	return x;
}

void GhiChu(){
	string data;
	getline(file, data);
	cout<<"\nGhi chu: "<<data<<endl;
	getch();
}

void PhimLenh()
{
	key=getch();
	if(key== 'n'||  key== 'N')	x= TangThang(x);
	if(key== 'p'||  key== 'P')	x= GiamThang(x);
	if(key== 's'|| 	key== 'S')	GhiChu();
	if(key== '1')	 Nhap(x);
}

void ChuThich(){
	textcolor(6);
	cout<<"\nn: chuyen sang thang ke tiep.\n";
	cout<<"p: lui ve thang truoc.\n";
	cout<<"s: Hien ghi chu cua nhung ngay cuoi tuan.\n";
	cout<<"1: Nhap lai thang can in lich.\n";
	cout<<"2.Thoat.";
	textcolor(15);
}
int  main()
{
    Nhap(x);
	do{
		system("cls");
		NhapLich(x);
		Xuat(x);
		TimNgay(x);
		ChuThich();
		PhimLenh();
	}while(key != '2');
	file.close();
	getch();
}

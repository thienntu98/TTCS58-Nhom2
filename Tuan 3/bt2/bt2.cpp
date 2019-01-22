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
    x.a=ngaydu;//ngay du cua cac thang truoc thang dang xet
    x.d=1; //Gan ngay la ngay mung 1, de ta t im ngay dau tien cua thang thuoc thu may
    thu=TinhNgay(x)%7; //de tinh thu cua ngay dau tien cua thang 1: thu 2 2: thu3 .... 7:chu nhat.
    //Gan tat ca ngay trong thang vao mang 
    for(i=0;i<5;i++)// 5 la so hang de in ra lich
    {
        for(j=0;j<7;j++)// moi hang bao gom 7 ngay
        {
            if(7*i+j+1<=ngaymax)//neu nho hon hoac bang ngay lon nhat cua thang 
			month[7*i+j+thu]=7*i+j+1;//7*i+j+thu vi tri cua ngay duoc xep theo tuan (+ thu:sap xep theo ngay dau cua thang)
        }
    }
    for(i=0;i<thu;i++)//nhung ngay truoc < thu
        month[i]=32; //Gan gia tri tam thoi bieu thi nhung ngay ko ton tai
    for(i=ngaymax+thu;i<42;i++)// nhung ngay > ngaymax + thu
        month[i]=32; //Gan gia tri tam thoi bieu thi nhung ngay ko ton tai
}

void TimNgay(date x){
	int ngay, thutk;//ngay: nhap tu ban phim ngay muon tim kiem, thutk: thu cua ngay muon tim kiem 
	do{
		cout<<"\nNhap ngay muon tim: Ngay ";
		cin>>ngay;
	}while(ngay <= 0 || ngay > ngaymax);//kiem tra ngay co hop le hay khong
	thutk = (ngay+thu-1)%7;//tim ngay thuoc thu may trong tuan
	textcolor(4);//doi thanh mau do de xuat ket qua tim kiem
	switch(thutk){
		case 1://neu =1 la thu 2
			cout<<"\nThu hai "<<ngay<<"/"<<x.m<<"/"<<x.y<<"\n";
			break;
		case 2://neu =2 la thu 3
			cout<<"\nThu ba "<<ngay<<"/"<<x.m<<"/"<<x.y<<"\n";
			break;
		case 3://neu =3 la thu 4
			cout<<"\nThu tu "<<ngay<<"/"<<x.m<<"/"<<x.y<<"\n";
			break;
		case 4://neu =4 la thu 5
			cout<<"\nThu Nam "<<ngay<<"/"<<x.m<<"/"<<x.y<<"\n";
			break;
		case 5://neu =5 la thu 6
			cout<<"\nThu sau "<<ngay<<"/"<<x.m<<"/"<<x.y<<"\n";
			break;
		case 6://neu =6 la thu 7
			cout<<"\nThu bay "<<ngay<<"/"<<x.m<<"/"<<x.y<<"\n";
			break;
		case 0://neu =0 la chu nhat
			cout<<"\nChu nhat "<<ngay<<"/"<<x.m<<"/"<<x.y<<"\n";
			break;
	}
	textcolor(15);//chuyen lai mau trang
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
            else if(j == 0)//ngay chu nhat
            		{
            			textcolor(4);//chuyen sang mau do
            			cout<<month[7*i+j]<<"\t";//xuat ga tri cua ngay duoc luu trong mang
					}
				else	{
					textcolor(15);//chuyen chhu trang
					cout<<month[7*i+j]<<"\t";//xuat ga tri cua ngay duoc luu trong mang
				}
        }
        cout<<"\n";
    }
    textcolor(15);
}

//chuyen sang thang tiep theo
date TangThang(date &x){
	x.m += 1;//tang thang 1 don vi
	if(x.m>12)//neu thang lon hon 12 thi cho thang = 1 va tang nam len 1 don vi
	{
		x.y += 1;
		x.m = 1;
		
	}
	return x;
}

//lùi vè thang truoc
date GiamThang(date &x){
	x.m -= 1;//giam thang di 1 don vi
	if(x.m < 1)//neu thang nho hon 1 thì cho thang  = 12 và gi?m nam di 1 don vi
	{
		x.m = 12;
		x.y -= 1;
		if(x.y<1)//neu nam nho hon 1 thi cho ngay thang nam vè gia tri ban dau la 1/1/1
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
	getline(file, data);//doc du lieu trong file
	cout<<"\nGhi chu: "<<data<<endl;//xuat dl ra man hinh
	getch();
}

void PhimLenh()
{
	key=getch();
	if(key== 'n'||  key== 'N')	x= TangThang(x);//tang thang cua x  len 1 don vi
	if(key== 'p'||  key== 'P')	x= GiamThang(x);//giam thang cua x  len 1 don vi
	if(key== 's'|| 	key== 'S')	GhiChu();//Xuat ghi chu
	if(key== '1')	 Nhap(x);//Nhap lai thang nam dein lich
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

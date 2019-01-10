#include <iostream>
#include <conio.h>
using namespace std;
struct date
{
    int d,m,y,a;
};

int nhuan(date x) //Kiem tra nam nhuan hay ko
{
    return (x.y%4==0)?1:0;
}

long daycount(date x) //Tinh khoang cach tu ngay nhap vao voi ngay 1/1/1
{
    return x.d-1+(x.m-1)*30+(x.y-1)*365+x.a+(x.y-1)/4;
}

int  main()
{
    date x;
    int month[42];
    int i,j,ngaymax,ngaydu,k,thu,ok;
    cout<<"\nChuong trinh in ra cac ngay trong thang cua nam nao do\n------\n\n";
    do
    {
        if(ok==0)
        cout<<"\nXin loi, thang (nam) ban vua nhap ko hop le,xin nhap lai\n-\n";
        ok=1;
        cout<<"Nhap thang, nam (vi du 11 2007): ";
        fflush(stdin); cin>>x.m>>x.y;
        if(x.y<0||x.m<1) ok=0; //Kiem tra tinh hop le cua
        else if (x.m>12) ok=0; //so lieu nhap vao tu ban phim
    } while(ok==0);
    switch(x.m)
        {
            case 1: ngaymax=31; ngaydu=0; break;
            case 2: if(nhuan(x)) ngaymax=29; else ngaymax=28; ngaydu=1;  break;
            case 3: ngaymax=31; ngaydu=-1+nhuan(x); break;
            case 4: ngaymax=30; ngaydu=0+nhuan(x); break;
            case 5: ngaymax=31; ngaydu=0+nhuan(x); break;
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
        thu=daycount(x)%7; //de tinh thu cua ngay dau tien cua thang
        
        for(i=0;i<5;i++)
        {
            for(j=0;j<7;j++)
            {
                if(7*i+j+1<=ngaymax) *(month+7*i+j+thu)=7*i+j+1;
            }
        } //Gan tat ca ngay trong thang vao mot day
        for(i=0;i<thu;i++)
            *(month+i)=32; //Gan gia tri tam thoi bieu thi nhung ngay ko ton tai
        for(i=ngaymax+thu;i<42;i++)
            *(month+i)=32; //Gan gia tri tam thoi bieu thi nhung ngay ko ton tai
        cout<<"----\n\nLich thang "<<x.m<<"\\"<<x.y<<"\n------\n\n";
        cout<<"CN\tThu 2\tThu 3\tThu 4\tThu 5\tThu 6\tThu 7\n\n";
        for(i=0;i<6;i++)
        {
            for(j=0;j<7;j++)
            {
                if(*(month+7*i+j)==32) cout<<"\t"; //Thay the gia tri tam thoi bang null
                else cout<<*(month+7*i+j)<<"\t";
            }
            cout<<"\n";
        }
    getch();
}

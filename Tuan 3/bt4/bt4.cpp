#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
#define TRUE 1 
#define FALSE  0 
#define MAX  10000 

ofstream fi("input.txt");
ifstream f("input.txt");
ofstream file("output.txt");
int a[100][100];//ma tran trong so cua do thi
int n;//so dinh cua do thi
int m;//so canh cua do thi
int sc;//so canh cua cay khung nho nhat,, se bang n - 1
int w;//do dai cua cay khung nho nhat
int chuaxet[100];//mang danh dau cac dinh da them vao cay khung nho nhat
int cck[100][3];//danh sach cac canh cua cay khung nho nhat
void TaoDoThi(){
	int dinh, canh;
	int d, c, gt;
	cout<<"Nhap vao so dinh: ";
	cin>>dinh;
	fi<<dinh<<" ";
	cout<<"Nhap vao so canh: ";
	cin>>canh;
	fi<<canh<<endl;
	cout<<"Nhap danh sach cac canh vd: 1 5 32 voi 1: dinh xuat phat, 2: dinh ket thuc, 32: gia tri cua canh."<<endl;
	for(int i = 0; i < canh; i++){
		do{
			cin>>d>>c>>gt;
		}while(d <= 0 || d > dinh || c <= 0 || c > dinh || d == c);//dieu kien khi nhap dinh ca canh
		fi<<d<<" "<<c<<" "<<gt<<endl;
	}
}
void Nhap(){
	 int i, j, k;
	 f>>n>>m;
	 file<<"So dinh: "<<n<<endl;
	 file<<"So canh: "<<m<<endl;
	 //khoi tao ma tran trong so cua do thi a[i][j] = MAX
	 for (i = 1; i <= n; i++){
		chuaxet[i] = TRUE;//Gan nhan~  cho cac dinh?
		for (j = 1; j <= n; j++)
			a[i][j] = MAX;//MAX duoc dinh nghia la so cuc lon so voi gia tri cua cac canh
	 }
	 
	 //nhap danh sach cac canh
	 for (int p = 1; p <= m; p++){
		f>>i>>j>>k;
		a[i][j] = k;
		a[j][i] = k;//vì ?? dài i -> j = j-> i nen ta cho a[i][j] = a[j][i]
	 }
}
void PRIM(){
	int k, top, min, l, t, u;
	int s[100];//mang chua cac dinh cua cay khung nho nhat
	sc = 0; w = 0;
	do{
		cout<<"Nhap dinh bat ky: ";
		cin>>u;
	}while(u <= 0 || u >6);
	cout<<"Dinh bat dau xet: "<<u<<endl;
	top = 1;//dinh dau tien
	s[top] = u;// them dinh u bat ky vao mang s[]
	chuaxet[u] = FALSE;
	while (sc<n - 1) {//trong khi sc < n - 1, vi so canh de di het tat ca cac dinh se bang n - 1
		min = MAX;//dat gia tri min bang cuc dai
		//tim cac canh co do dai nho nhat voi cac dinh trong mang s[].
		cout<<"Min = : ";
		for (int i = 1; i <= top; i++){//Vong lap for giup xet lai cac canh chua duoc chon neu du dieu kien thi van se duoc chon
	   		t = s[i];//cho t = dinh cuoi cung cua mang chua cac dinh da chon
			for (int j = 1; j <= n; j++){//xet tu i den tat ca cac dinh j neu du dieu kien thi ta se dat gia tri min cho canh co gia tri nho nhat
	    		//Dieu kien de lay canh co gia tri nho nhat, chuaxet[j] yeu cau j la dinh chua duoc chon, min>[t][j] yeu cau canh dang xet phai co gia tri nho ho min
				if (chuaxet[j] && min>a[t][j]){
	    			min = a[t][j];//gan min cho canh co gia tri nho hon va luu lai co thong so c ua canh do
	    		 	k = t;//gan dinh xuat phat cua canh
	     		 	l = j;//gan dinh ket thuc cua canh
	     		 	cout<<min<<"\t";//xuat ra man hinh gia tri min vua chon de xem tien do cua thuat toan
	    		}
	    		
	  	  	}
	   }
		cout<<endl;
		sc++;//tang so canh len 1 don vi
		w = w + min;//tinh tong chieu dai cua cay khung nho nhat
		//them vao danh sach cac canh cua cay khung
		cck[sc][0] = k;
		cck[sc][1] = l;
		cck[sc][2] = min;
		chuaxet[l] = FALSE;//chuyen dinh l ve dinh dang FALSE tuong duong voi dinh da chon 
		top++;//tang mang chua cac dinh duoc chon len 1 don vi
		s[top] = l;//gan dinh l o vi tri cuoi cung cua mang
		getch();//dung chuong trinh de xem tien do
		//Dieu kien de kiem tra tien do
		if(sc >=1 && sc <= n - 2)	cout<<"Dinh dang xet: "<<s[top	]<<endl;
 	}
}
//ghi file va xuat ra man hình cay khung.
void XuatFile(){
	file<<"Do dai ngan nhat:"<< w<<endl;
	cout<<"\nDo dai ngan nhat:"<< w<<endl;
	file<<"Cac canh cua cay khung nho nhat"<<endl;
	cout<<"Cac canh cua cay khung nho nhat"<<endl;
	for (int i = 1; i <= sc; i++)
		{
			file<<cck[i][0]<<" "<< cck[i][1]<<" "<<cck[i][2]<<endl;
			cout<<cck[i][0]<<" "<< cck[i][1]<<" "<<cck[i][2]<<endl;
		}
}
int main(){
	TaoDoThi();//tao do thi nhap tu ban phim
	Nhap(); //Doc file
 	PRIM();//Tien hanh tim cay khung
 	XuatFile();//Ghi file va xuat cay khung ra man hinh
 	cout<<"Xuat ket qua ra file thanh cong!!!";
 	f.close();
 	file.close();
 	getch();
}

#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
#define TRUE 1 
#define FALSE  0 
#define MAX  10000 

ifstream f("input.txt");
ofstream file("output.txt");
int a[100][100];//ma tran trong so cua do thi
int n;//so dinh cua do thi
int m;//so canh cua do thi
int sc;//so canh cua cay khung nho nhat,, se bang n - 1
int w;//do dai cua cay khung nho nhat
int chuaxet[100];//mang danh dau cac dinh da them vao cay khung nho nhat
int cck[100][3];//danh sach cac canh cua cay khung nho nhat
void Nhap(){
	 int i, j, k;
	 f>>n>>m;
	 file<<"So dinh: "<<n<<endl;
	 file<<"So canh: "<<m<<endl;
	 //khoi tao ma tran trong so cua do thi a[i][j] = MAX
	 for (i = 1; i <= n; i++){
		chuaxet[i] = TRUE;//Gan nhan~  cho cac dinh?
		for (j = 1; j <= n; j++)
			a[i][j] = MAX;
	 }
	 
	 //nhap danh sach cac canh
	 for (int p = 1; p <= m; p++){
		f>>i>>j>>k;
		a[i][j] = k;
		a[j][i] = k;
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
	top = 1;
	s[top] = u;// them dinh u bat ky vao mang s[]
	chuaxet[u] = FALSE;
	while (sc<n - 1) {
		min = MAX;
		//tim cac canh co do dai nho nhat voi cac dinh trong mang s[].
		cout<<"Min = : ";
		for (int i = 1; i <= top; i++){
	   		t = s[i];
			for (int j = 1; j <= n; j++){
	    		if (chuaxet[j] && min>a[t][j]){
	    			min = a[t][j];
	    		 	k = t;//gan dinh xuat phat cua canh
	     		 	l = j;//gan dinh ket thuc cua canh
	     		 	cout<<min<<"\t";
	    		}
	    		
	  	  	}
	   }
		cout<<endl;
		sc++;
		w = w + min;//tinh tong chieu dai cua cay khung nho nhat
		//them vao danh sach cac canh cua cay khung
		cck[sc][1] = k;
		cck[sc][2] = l;
		chuaxet[l] = FALSE; 
		top++;
		s[top] = l;
		getch();
		if(sc >=1 && sc <= n - 2)	cout<<"Dinh dang xet: "<<cck[sc][2]<<endl;
 	}
}
void XuatFile(){
	file<<"Do dai ngan nhat:"<< w<<endl;
	cout<<"\nDo dai ngan nhat:"<< w<<endl;
	file<<"Cac canh cua cay khung nho nhat"<<endl;
	cout<<"Cac canh cua cay khung nho nhat"<<endl;
	for (int i = 1; i <= sc; i++)
		{
			file<<cck[i][1]<<" "<< cck[i][2]<<" "<<a[cck[i][1]][cck[i][2]]<<endl;
			cout<<cck[i][1]<<" "<< cck[i][2]<<" "<<a[cck[i][1]][cck[i][2]]<<endl;
		}
}
int main(){
 Nhap(); 
 PRIM();
 XuatFile();
 cout<<"Xuat ket qua ra file thanh cong!!!";
 f.close();
 file.close();
 getch();
}

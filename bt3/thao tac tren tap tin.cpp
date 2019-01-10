#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<stdlib.h>
#include<conio.h>

using namespace std;
ifstream file("customer.txt");//Mo file
ofstream f("customer.txt");
ofstream fi("trans.txt");
int n, m = 0;
class Customer{//tao lop khach hang
	protected: 
		string makh, tenkh;
		int sodu;
	public:
		~Customer(){
		}
		virtual void DocFile(){//doc file
			string data;
			getline(file, data); makh = data;
			getline(file, data); tenkh = data;
			getline(file, data); sodu = atoi(data.c_str());
			}
		virtual void Nhap(){
			fflush(stdin);
			cout<<"Nhap ma khach hang: ";
			getline(cin, makh);
			cout<<"Nhap ten khach hang: ";
			getline(cin, tenkh);
			cout<<"Nhap so tien du: ";
			cin>>sodu;
		}
		virtual void Xuat(){//xuat file
			cout<<"MaKH: "<<makh<<"\t";
			cout<<"TenKH: "<<tenkh<<"\t";
			cout<<"Sodu: "<<sodu<<"\t";
		}
		virtual void XuatFileKH(){
			f<<"MaKH: "<<makh<<"\t";
			f<<"TenKH: "<<tenkh<<"\t";
			f<<"Sodu: "<<sodu<<"\t";
			f.close();
		}
		friend class LiskCustomer;
};

class Trans{
//	protected:
//		string makh, loaigiaodich;
//		int sotien;
	public:
		string makh, loaigiaodich;
		int sotien;
		virtual void Nhap(){
			fflush(stdin);
			cout<<"Nhap MaKH: ";
			getline(cin, makh);
			cout<<"Loai giao dich: ";
			getline(cin, loaigiaodich);
			cout<<"So tien gui: ";
			cin>>sotien;
		}
		virtual void XuatTrans(){
			cout<<"MaKH: "<<makh<<"\t";
			cout<<"Loai giao dich: "<<loaigiaodich<<"\t";
			cout<<"So tien: "<<sotien;
			cout<<endl;
		}
		virtual void XuatFileTrans(){
			fi<<"MaKH: "<<makh<<"\t";
			fi<<"Loai giao dich: "<<loaigiaodich<<"\t";
			fi<<"So tien: "<<sotien;
			cout<<endl;
		}
		friend class LiskTrans;
};

class LiskCustomer: public Customer{
	public:
		vector<Customer> ds;
		void Nhapds(){
			if (file.fail())
				cout << "Failed to open this file!" << endl;
			else {
				string data;
				getline(file, data); n = atoi(data.c_str());
				ds.resize(n);
				for(int i = 0; i < n; i++)
					{
						ds[i].DocFile();
					}
				file.close();	
			}
		}
		void Xuatds(){
			for(int i = 0;i < n; i++)	
				{
					ds[i].Xuat();
					cout<<endl;
				}
		}
		void AddKH(){
			Customer kh ;
			int x;
			cout<<"Nhap so khach hang muon them vao: ";
			cin>>x;
			for(int i = 0; i < x; i++)
			{
				cout<<"---Thong tin khach hang thu "<<i+1<<"\n";
				kh.Nhap();
				ds.push_back(kh);
				n++;
			}
		}
		
		void GuiTien(string a, int tiengui){
			for(int i = 0; i < n; i++)
				if(a == ds[i].makh)
					{
						ds[i].sodu += tiengui;
					}
		}
};

class LiskTrans: public Trans{
	protected:
	public:
		vector<Trans> trans;
		void AddTrans(){
			Trans data ;
			int sl;
			cout<<"Nhap so luong giao dich: ";
			cin>>sl;
			for(int i = 0; i < m; i++)
			{
				cout<<"Nhap thong tin\n";
				data.Nhap();
				trans.push_back(data);
				m++;
			}
		}	
		void XuatTrans(){
			for(int i = 0; i < trans.size(); i++)
				trans[i].XuatTrans();
		}
		void XuatFileTrans(){
			for(int i =0; i < trans.size(); i++)
				{
					trans[i].XuatFileTrans();
				}
			fi.close();
		}
		void DuLieuRa(string a, int b, int c){
				a = trans[c].makh;
				b = trans[c].sotien;
		}
};

int main(){
	string ma;
	int tien;
	LiskCustomer ds;
	ds.Nhapds();
	LiskTrans trans;
	trans.AddTrans();
	trans.XuatTrans();
	trans.XuatFileTrans();
	for(int j = 0; j < m; j++)
	{
		trans.DuLieuRa(ma, tien, j);
		for(int i = 0; i < n; i++)
		{
			ds.GuiTien(ma, tien);
		}
	}
//	for(int i= 0; i<m; i++)
//	{
//		ma = trans[i].makh;
//		tien = trans[i].tien;
//	}
//	int chon;
//    do
//    {
//        system("cls");
//        cout<<("\t\t\t ============MENU================================\n");
//        cout<<("\t\t\t |1. Doc File                                   |\n");
//        cout<<("\t\t\t |2. Hien thi danh sach khach hang              |\n");
//        cout<<("\t\t\t |3. Them moi khach hang                        |\n");
//        cout<<("\t\t\t |4. Tim kiem nhan vien                         |\n");
//        cout<<("\t\t\t |5. Xoa nhan vien                              |\n");
//        cout<<("\t\t\t |6. Thoat                                      |\n");
//		cout<<("\t\t\t ================================================\n");
//        cout<<("Ban chon: ");
//        cin>>(chon);
//        switch(chon)
//        {
//            case 1:
//				ds.Nhapds();
//				cout<<"Doc File thanh cong!!!";
//                break;
//            case 2:
//            	cout<<"-------------------------------DANH SACH KHACH HANG-----------------------------\n";
//            	ds.Xuatds();
//                break;
//            case 3:
//            	ds.AddKH();
//				break;
//            case 4:
//                break;
//            case 5:
//                break;
//            case 6:
//                break;
//            default:
//                printf("Ban chon sai. Moi ban chon lai MENU!\n");
//                break;
//        }
//        getch();
//    }while(chon!=6);
}

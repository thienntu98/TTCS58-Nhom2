#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<stdlib.h>
#include<conio.h>

using namespace std;

ifstream file("customer.txt");
ifstream fil("trans.txt");
ofstream f("customer.txt");
ofstream fi("trans.txt");

int n, m;
class GiaoDich{//tao lop khach hang
	protected: 
		string makh;
		bool loaigiaodich;//neu loaigiaodihc = 1 rut tien, = 0 gui tien
		int sotien;
	public:
		GiaoDich(string _makh, bool _loaigiaodich, int _sotien){
			makh = _makh;
			loaigiaodich = _loaigiaodich;
			sotien = _sotien;
		}
		friend class QuanLy;
};

class Customer{//tao lop khach hang
	protected: 
		string makh, tenkh;
		int sodu;
	public:
		void DocFileKH(){//doc file
			string data;
			getline(file, data); makh = data;
			getline(file, data); tenkh = data;
			getline(file, data); sodu = atoi(data.c_str());
			}
		friend class QuanLy;
};

class QuanLy{
	protected:
	public:
		vector<GiaoDich> dsTrans;
		vector<Customer> dskh;
		//them mot khach hang
		void AddKH(Customer &kh){
			cout<<"---Thong tin khach hang \n";
			Nhap(kh);
			dskh.push_back(kh);
			cout<<"Ghi file thanh cong!!";
		}
		//Thuc hien giao dich
		void THGiaoDich(string makh, int sotien, bool loaigiaodich){
				//neu makh cua giao dich trung voi makh cua Khach hang thi ta thuc hien rut hoac gui tien
				if(KiemTra(makh) == 1){
					if(loaigiaodich == 1){
						for(int i = 0; i <= dskh.size(); i++){
							if(makh == dskh[i].makh){
								if(dskh[i].sodu >= sotien)
								{
									dskh[i].sodu -= sotien;
									f<<dskh.size()<<endl;
									for(int i = 0; i < dskh.size(); i++){
										GhiFileKH(dskh[i]);//Cap nhat lai file khach hang
									}
									GiaoDich gd(makh, loaigiaodich, sotien);
									dsTrans.push_back(gd);//them giao dich vao vector
									fi<<dsTrans.size()<<endl;
									for(int i = 0; i < dsTrans.size(); i++){
										GhiFileGD(dsTrans[i]);//cap nhat lai file Trans
									}
									return;
								}
								else	cout<<"Giao dich khong thanh cong!!!\n";
								}
							}
						}
					else
					{
						for(int i = 0; i <= dskh.size(); i++){
							if(makh == dskh[i].makh){
								dskh[i].sodu += sotien;
								f<<dskh.size()<<endl;
								for(int i = 0; i < dskh.size(); i++){
									GhiFileKH(dskh[i]);//Cap nhat lai file khach hang
								}
								GiaoDich gd(makh, loaigiaodich, sotien);
								dsTrans.push_back(gd);//them giao dich vao vector
								fi<<dsTrans.size()<<endl;
								for(int i = 0; i < dsTrans.size(); i++){
									GhiFileGD(dsTrans[i]);//cap nhat lai file Trans
								}
								return;
							}
						}	
					}
				}
				else 
					cout<<"Khong co khach hang tuong ung!!!\n";
		}
		//Nhap mot khach hang
		void Nhap(Customer &kh){
			fflush(stdin);
			cout<<"Nhap ma khach hang: ";
			getline(cin, kh.makh);
			cout<<"Nhap ten khach hang: ";
			getline(cin, kh.tenkh);
			cout<<"Nhap so tien du: ";
			cin>>kh.sodu;
		}
		//Kiem tra ma khach hang giao dich co trong danh sach khach hang hay khong
		bool KiemTra(string ma){
			for(int i = 0 ; i <= dskh.size(); i++)
			{
				if(ma == dskh[i].makh)
					return 1;
			}
			return 0;
		}
		//Ghi File khach hang
		void GhiFileKH(Customer kh){
			fflush(stdin);
			f<<kh.makh<<endl;
			f<<kh.tenkh<<endl;
			f<<kh.sodu<<endl;
		}
		//Ghi file giao dich
		void GhiFileGD(GiaoDich gd){
			fflush(stdin);
			fi<<gd.makh<<endl;
			fi<<gd.loaigiaodich<<endl;
			fi<<gd.sotien<<endl;
		}
		//Xuat danh sach khach hang
		void XuatDSKH(){
			for(int i = 0; i < dskh.size(); i++){
				XuatKH(dskh[i]);
				cout<<endl;
			}
		}
		//Xuat mot dah sach khach hang ra man hinh
		void XuatKH(Customer kh){
			cout<<"MaKH: "<<kh.makh<<"\t";
			cout<<"TenKH: "<<kh.tenkh<<"\t";
			cout<<"Sodu: "<<kh.sodu<<"\t";
		}
		void XuatGD(GiaoDich gd){
			cout<<"MaKH: "<<gd.makh<<"\t";
			cout<<"TenKH: "<<gd.loaigiaodich<<"\t";
			cout<<"Sodu: "<<gd.sotien<<"\t";
		}

		void InSaoKe(){
			cout<<"Size kh: "<<dskh.size()<<endl;
			cout<<"Size gd: "<<dsTrans.size()<<endl;
			for(int i = 0; i < dskh.size(); i++)
				for(int j = 0; j < dsTrans.size(); j++)
					if(dskh[i].makh == dsTrans[j].makh)
					{
						cout<<"KHACH HANG "<<dsTrans[i].makh<<endl;
						XuatGD(dsTrans[j]);
						cout<<endl;
					}
		}
};

int main(){
	QuanLy ql;
	Customer kh;
	string makh;
	bool loaigiaodich;
	int chon, sotien;
    do
    {
        system("cls");
        cout<<("\t\t\t ============MENU================================\n");
        cout<<("\t\t\t |1. Them moi khach hang                        |\n");
        cout<<("\t\t\t |2. Gui tien                                   |\n");
        cout<<("\t\t\t |3. Rut tien                                   |\n");
        cout<<("\t\t\t |4. In danh sach khach hang                    |\n");
        cout<<("\t\t\t |5. In sao ke cho khach hang                   |\n");
        cout<<("\t\t\t |6. Thoat                                      |\n");
		cout<<("\t\t\t ================================================\n");
        cout<<("Ban chon: ");
        cin>>(chon);
        switch(chon)
        {
            case 1:
				ql.AddKH(kh);
				cout<<"Them thanh cong!!!\n";
                break;
            case 2:
            	loaigiaodich = 0;
            	fflush(stdin);
            	cout<<"Nhap ma khach hang muon gui tien: ";
            	getline(cin, makh);
            	cout<<"Nhap so tien muon gui: ";
            	cin>>sotien;
            	ql.THGiaoDich(makh, sotien, loaigiaodich);
                break;
            case 3:
            	loaigiaodich = 1;
            	fflush(stdin);
            	cout<<"Nhap ma khach hang muon rut tien: ";
            	getline(cin, makh);
            	cout<<"Nhap so tien muon gui: ";
            	cin>>sotien;
            	ql.THGiaoDich(makh, sotien, loaigiaodich);
				break;
            case 4:
            	cout<<"======================DANH SACH KHACH HANG====================\n";
            	ql.XuatDSKH();
                break;
            case 5:
            	cout<<"=======================DANH SACH SAO KE=======================\n";
            	ql.InSaoKe();
                break;
            case 6:
                break;
            default:
                printf("Ban chon sai. Moi ban chon lai MENU!\n");
                fflush(stdin);
                break;
        }
        getch();
    }while(chon!=6);
	f.close();
	fi.close();
}

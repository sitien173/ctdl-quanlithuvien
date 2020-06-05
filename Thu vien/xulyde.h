#pragma once 
#include "ctdl.h"
#include "hotro.h"
#include "doc_ghi_file.h"
//=============================================Khoi tao===============================
void khoi_tao_muontra(LIST_MT& l)
{
	l.pHead = l.pTail = NULL;
}
void khoi_tao_cay(TREE& t)
{
	t = NULL;
}
void khoi_tao_dau_sach(LIST_DS& l)
{
	l.sl = 0;
}
void khoi_tao_sach(LIST_DMS& l)
{
	l.pHead = l.pTail = NULL;
}

// ======================================Doc gia========================================================

int nhap_doc_gia(docgia& x);// nhập thành công rt 1 <> esc rt -2
int them_doc_gia_vao_ds(TREE& t); // Thêm độc giả vào danh sách thêm thành công rt 1 < > return -2
void them_node_vao_cay(TREE& t, docgia x);
void Xuat_Thong_Tin_Doc_Gia(docgia a, int tungdo);// Xuất thông tin của 1 độc giả
void xuat_ds_thong_tin_doc_gia(TREE t, int& i);//duyet theo LNR in ra ma the tang dan
void chuyen_cay_sang_mang(TREE t, docgia* arr, int& i);// duyệt cây copy dữ liệu vào mảng
void sap_xep_doc_gia_theo_ten(docgia* arr, int n);// sắp xếp độc giả theo tên + họ tăng dần
void tim_kiem_pt_the_mang(TREE& p, TREE& q);//Phần tử p đang được thế mạng cho phần tử q
void xoa_theo_ma_doc_gia(TREE& t, int x);// hàm có chức năng xóa 1 độc giả bất kì theo mã độc giả
TREE tim_kiem_docgia_ma(TREE& t, int ma_doc_gia);// tìm kiếm độc giả trong danh sách với mã độc giả
void tim_kiem_ds_doc_gia_ten(TREE t, string ch1, int& tungdo);// tìm kiếm tên độc giả
int sua_thong_tin_doc_gia(TREE& t);// hiệu chỉnh thông tin độc giả thành công rt 1 <> ESC rt -2
int SoluongDG(TREE t);// đếm số đọc giả trong cây

//========================================== Đau Sach ==================================================

int nhap_DauSach(LIST_DS& l, dausach& data);// thêm đầu sách nếu thêm thành công rt 1 <> ESC rt -2
void xuat_dau_sach(dausach& a, int tungdo);// in ra 1 đầu sách
void xuat_ds_dausach(LIST_DS& l);// in danh sach theo the loai
void them_vao_ds_dausach(LIST_DS& l, dausach data);// Thêm đầu sách vào danh sách đầu sách để quản lí
void sap_xep_theo_theloai_dausach(LIST_DS& l);// sắp xếp đầu sách theo thể loại
int tim_kiem_dau_sach_theo_ten(LIST_DS l, string temp);// tim kiếm đầu sách theo tên đầu sách nếu có xuất ra đầu sách <> -1;
int tim_kiem_dau_sach_theo_ma(LIST_DS l, string ma);// tìm kiếm đầu sách theo mã đầu sách nêu có trả về vị trí <> -1
int sua_dau_sach(LIST_DS& l);// sửa đầu sách theo mã đầu sách. Nếu sửa thành công return 1 <> -1 ;ESC return -2


//=========================================Danh muc sach===============================================
NODE_DMS* tao_node_sach(danhmucsach& x);// tạo 1 node mới 
int them_sach(LIST_DS& l);// Thêm sách nếu thêm thành công rt 1 <> -1 ; ESC rt -2;
void them_sach_vao_ds(LIST_DMS& l, NODE_DMS* p);// thêm sách vào danh sách sách để quản lí
void xuat_sach1(string ten_sach, danhmucsach a, int tungdo);// xuất 1 cuốn sách
void xuat_ds_sach1(LIST_DS l);// xuất các sách có trong danh sách sách
NODE_DMS* tim_kiem_sach(LIST_DS l, string ma_sach);// tìm kiếm sách theo mã sách nếu có trả về  vị trí node trong ds <>  NULL

//==========================================Muon tra===================================================

NODE_MT* tao_node_muontra(muontra x);// tạo 1 node mượn trả 
void them_phieu_muon(muontra& x);// lập phiếu mượn sách
void xuat_thong_tin_phieu_muontra(muontra a, string ten_sach, int tungdo);// in thong tin của 1 phiếu mượn trả
void them_vao_ds_muontra(LIST_MT& l, NODE_MT* p);// thêm phiếu vào danh sách để quản lí
int xuat_sach_dang_muon(TREE t, LIST_DS l);// hàm có chức năng xuất các sách đang mượn của 1 độc giả nếu có sách mượn rt 1 <> 0
int dem_sach_docgia_muon(TREE t);// đếm số sách độc giả đang mượn dùng để kiểm tra điều kiện mượn sách 
int muonsach(TREE& t, LIST_DS& l);// mượn thành công tr 1 <> -1 ; esc rt -2
int trasach(TREE& t, LIST_DS& l);// trả sách thành công tr 1 <> -1 ; ESC rt -2

// =========================================== Qua Han ================================
void ds_quahan(TREE t, LIST_QUAHAN& l);// in ra danh sách các độc giả quá hạn

// =================== 10 sách có lượt mượn nhiều nhất ====================
void top10sach(LIST_DS l);

// ========================================== Độc Giả==========================================

// nhập thành công rt 1 <> esc rt -2
int nhap_doc_gia(docgia& x)
{
	Box_NhapDG();
	int k = 0;
	x.trangthaithe = 1; // trạng thái lúc thêm độc giả auto =1. có thể mượn sách
	gotoXY(boxx + 18, boxy + 10);
	cout << x.trangthaithe;
	gotoXY(boxx + 10, boxy + 2);
	cout << x.mathe;
	gotoXY(boxx + 11, boxy + 4);
	k = nhap_ki_tu(x.ho);
	if (k == -1) // ESC
		return -2;
	gotoXY(boxx + 12, boxy + 6);
	k = nhap_ki_tu(x.ten);
	if (k == -1) // ESC
		return -2;
	gotoXY(boxx + 13, boxy + 8);
	k = nhap_gioitinh(x.phai);
	if (k == -1) // ESC
		return -2;

	x.tongsosach = 0;
	return 1;
}
// Thêm độc giả vào danh sách thêm thành công rt 1 <> -1 ESC rt -2
int them_doc_gia_vao_ds(TREE& t)
{
	docgia x;
	ifstream filein("MADOCGIA.txt");
	ofstream filetemp("Temp.txt");
	filein >> x.mathe;
	int i = nhap_doc_gia(x);
	if (i == -2) // ESC
		return -2;
	else
	{
		them_node_vao_cay(t, x);
		int temp;
		while (filein >> temp)
		{
			if (temp != x.mathe)
				filetemp << temp << endl;
		}
		filein.close();
		filetemp.close();
		remove("MADOCGIA.txt");
		rename("Temp.txt", "MADOCGIA.txt");
		return 1;
	}

}

// them 1 node vao cay theo ma doc gia 
void them_node_vao_cay(TREE& t, docgia x)
{
	if (t == NULL)
	{
		t = new NODE_DG;
		if (t == NULL) return;
		t->data = x;
		t->pLeft = t->pRight = NULL;
	}
	else
	{
		if (x.mathe < t->data.mathe)
			them_node_vao_cay(t->pLeft, x);
		else if (x.mathe > t->data.mathe)
			them_node_vao_cay(t->pRight, x);
	}
}

// Xuất thông tin của 1 độc giả
void Xuat_Thong_Tin_Doc_Gia(docgia a, int tungdo)
{
	int x = whereX();
	int y = whereY();
	TextColor(15);
	gotoXY(50, 0);
	cout << "MA DOC GIA";
	gotoXY(65, 0);
	cout << "HO";
	gotoXY(90, 0);
	cout << "TEN";
	gotoXY(120, 0);
	cout << "Phai";
	gotoXY(135, 0);
	cout << "Trang Thai The";
	gotoXY(50, tungdo);
	cout << a.mathe;
	gotoXY(65, tungdo);
	cout << a.ho;
	gotoXY(90, tungdo);
	cout << a.ten;
	gotoXY(120, tungdo);
	cout << a.phai;
	gotoXY(137, tungdo);
	if (a.trangthaithe == 1)
		cout << "HOAT DONG";
	else
		cout << "KHOA";
	TextColor(7);
	gotoXY(x, y);
}

//duyet theo LNR in ra ma the tang dan
void xuat_ds_thong_tin_doc_gia(TREE t, int& i)
{
	TREE Stack[STACKSIZE];
	int top = -1;
	do
	{
		while (t != NULL)
		{
			Stack[++top] = t; // push vào Stack
			t = t->pLeft;
		}
		if (top != -1)
		{
			t = Stack[top--]; // pop Stack
			if (i <= 40)
			{
				Xuat_Thong_Tin_Doc_Gia(t->data, ++i);
			}
			else
			{
				ButtonNext();
				char c = _getch();
				if (c == -32)
					c = _getch();
				if (c == 27) // ESC
				{
					xoa_hienthi_buttonNext();
					return;
				}
				else if (c == 77)
				{
					i = 0;
					xoa_hien_thi_doc_gia();
					Xuat_Thong_Tin_Doc_Gia(t->data, ++i);
				}
			}
			t = t->pRight;
		}
		else
			break;
	} while (1);
	TextColor(7);
}

// duyệt cây copy dữ liệu vào mảng
void chuyen_cay_sang_mang(TREE t, docgia* arr, int& i)
{
	if (t != NULL)
	{
		arr[i++] = t->data;
		chuyen_cay_sang_mang(t->pLeft, arr, i);
		chuyen_cay_sang_mang(t->pRight, arr, i);
	}// nếu cây rỗng thoát hàm
	else
		return;
}

// sắp xếp độc giả theo tên + họ tăng dần
void sap_xep_doc_gia_theo_ten(docgia* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{  // kiểm tra tên 2 đg
			if (arr[i].ten > arr[j].ten)
			{
				// hoán đổi vị trí
				hoandoi(arr[i], arr[j]);
			} // ngược lại
			else if (arr[i].ten == arr[j].ten)
			{ // kiểm tra họ 2 đg
				if (arr[i].ho < arr[j].ho)
				{ // hoán đổi vị trí
					hoandoi(arr[i], arr[j]);
				}
			}
		}
	}
}

//Phần tử p đang được thế mạng cho phần tử q
void tim_kiem_pt_the_mang(TREE& p, TREE& q)
{
	// duyệt đến phần tử trái nhất của cây
	if (q->pLeft != NULL)
	{
		tim_kiem_pt_the_mang(p, q->pLeft);
	}
	// đã tìm được phần tử thế mạng
	else
	{
		p->data = q->data;
		p = q;
		q = q->pRight;
	}
}

// hàm có chức năng xóa 1 độc giả bất kì theo mã độc giả
void xoa_theo_ma_doc_gia(TREE& t, int x)
{
	if (t != NULL)
	{
		// duyệt cây để tìm phần tử cần xóa
		if (t->data.mathe < x)
		{
			xoa_theo_ma_doc_gia(t->pRight, x);
		}
		else if (t->data.mathe > x)
		{
			xoa_theo_ma_doc_gia(t->pLeft, x);
		}
		// đã tìm được mã độc giả
		else
		{
			if (t->data.tongsosach > 0)
			{
				 int temp=dem_sach_docgia_muon(t);
				 if (temp > 0)
				 {
					 BaoLoi("DOC GIA DANG CON SACH MUON.KHONG THE XOA");
					 return;
				 }
			}
			NODE_DG* p = t;
			// xóa node có 1 con hoặc không có con nào
			if (t->pLeft == NULL) // cây con phải
			{
				t = t->pRight;
			}
			else if (t->pRight == NULL) // cây con trái
			{
				t = t->pLeft;
			}
			// xóa node có 2 con.Trái nhất của cây con phải
			else
			{
				// trái nhất của cây con phải
				tim_kiem_pt_the_mang(p, t->pRight);
			}
			delete p;
			BaoLoi("XOA THANH CONG");
		}

	}
}

// tìm kiếm độc giả trong danh sách với mã độc giả
TREE tim_kiem_docgia_ma(TREE& t, int ma_doc_gia)
{
	if (t)
	{
		if (t->data.mathe == ma_doc_gia)
			return t;
		else if (t->data.mathe < ma_doc_gia)
			return tim_kiem_docgia_ma(t->pRight, ma_doc_gia);
		else
			return tim_kiem_docgia_ma(t->pLeft, ma_doc_gia);
	}
	return NULL;
}

// tìm kiếm tên độc giả
void tim_kiem_ds_doc_gia_ten(TREE t, string ch1, int& tungdo)
{
	if (t != NULL)
	{
		// ch1 là chuỗi con của tên độc giả
		if (t->data.ten.find(ch1) != string::npos)
		{
			if (tungdo == 1)
				xoa_hien_thi_doc_gia();
			Xuat_Thong_Tin_Doc_Gia(t->data, tungdo);
			tungdo++;
		}
		tim_kiem_ds_doc_gia_ten(t->pLeft, ch1, tungdo);
		tim_kiem_ds_doc_gia_ten(t->pRight, ch1, tungdo);
	}
	return;
}

// hiệu chỉnh thông tin độc giả thành công rt 1 <>  ESC rt -2
int sua_thong_tin_doc_gia(TREE& t)
{
	int ma_doc_gia = 0;
	int k = 0;
	docgia x;
	do
	{
		gotoXY(1, 10); cout << "                      ";
		gotoXY(1, 10);
		cout << "NHAP MA DOC GIA: ";
		k = nhap_so_nguyen(ma_doc_gia);
		if (k == -1) // ESC
			return -2;
		TREE p = tim_kiem_docgia_ma(t, ma_doc_gia);
		if (p == NULL) // khong tim thay doc gia
		{
			ma_doc_gia = 0; // gan lai ma the ve 0
			BaoLoi("MA DOC GIA KHONG DUNG");
			continue;
		}
		xoa_hien_thi_doc_gia();
		Box_NhapDG();
		gotoXY(boxx + 10, boxy + 2);
		cout << p->data.mathe;

		x.ho = p->data.ho;
		gotoXY(boxx + 11, boxy + 4);
		cout << x.ho;
		k = nhap_ki_tu(x.ho);
		if (k == -1) // ESC
			return -2;

		x.ten = p->data.ten;
		gotoXY(boxx + 12, boxy + 6);
		cout << x.ten;
		k = nhap_ki_tu(x.ten);
		if (k == -1) // ESC
			return -2;

		x.phai = p->data.phai;
		gotoXY(boxx + 13, boxy + 8);
		cout << x.phai;
		k = nhap_gioitinh(x.phai);
		if (k == -1) // ESC
			return -2;

		x.trangthaithe = p->data.trangthaithe;
		gotoXY(boxx + 18, boxy + 10);
		cout << x.trangthaithe;
		k = nhap_so_nguyen(x.trangthaithe);
		if (k == -1) // ESC
			return -2;
		p->data.ho = x.ho;
		p->data.ten = x.ten;
		p->data.phai = x.phai;
		p->data.trangthaithe = x.trangthaithe;
		break;
	} while (1);
	return 1;
}

// đếm số đọc giả trong cây
int SoluongDG(TREE t)
{
	int n = 0;
	TREE Stack[STACKSIZE];
	int top = -1;
	do
	{
		while (t != NULL)
		{
			Stack[++top] = t;
			t = t->pLeft;
		}
		if (top != -1)
		{
			t = Stack[top--];
			n++;
			t = t->pRight;
		}
		else break;
	} while (1);
	return n;
}

// =========================================Dau sach==============================================

// thêm đầu sách nếu thêm thành công rt 1 <> ESC rt -2
int nhap_DauSach(LIST_DS& l, dausach& data)
{
	Box_NhapDS();
	int k = 0;
	while (1)
	{

		gotoXY(boxx + 8, boxy + 2);
		k = nhap_ki_tu1(data.ISBN);
		if (k == -1) // ESC
			return -2;
		if (tim_kiem_dau_sach_theo_ma(l, data.ISBN) != -1)
		{
			BaoLoi("MA ISBN DA TON TAI");
			gotoXY(boxx + 8, boxy + 2);
			cout << "                  ";
			data.ISBN = "";
			continue;
		}
		gotoXY(boxx + 12, boxy + 4);
		k = nhap_ki_tu1(data.tensach);
		if (k == -1) // ESC
			return -2;
		gotoXY(boxx + 12, boxy + 6);
		k = nhap_so_nguyen(data.sotrang);
		if (data.sotrang == -1) // ESC
			return -2;
		gotoXY(boxx + 11, boxy + 8);
		k = nhap_ki_tu(data.tacgia);
		if (k == -1) // ESC
			return -2;
		gotoXY(boxx + 10, boxy + 10);
		k = nhap_so_nguyen(data.namxuatban);
		if (k == -1) // ESC
			return -2;
		gotoXY(boxx + 12, boxy + 12);
		k = nhap_ki_tu(data.theloai);
		if (k == -1) // ESC
			return -2;
		data.soluongmuon = 0;
		data.soluongsach = 0;
		return 1;
	}
}

// in ra 1 đầu sách
void xuat_dau_sach(dausach& a, int tungdo)
{
	int x = whereX();
	int y = whereY();
	TextColor(15);
	gotoXY(40, 0);
	cout << "Ma Dau Sach";
	gotoXY(55, 0);
	cout << "Ten sach";
	gotoXY(95, 0);
	cout << "So trang";
	gotoXY(105, 0);
	cout << "Tac gia";
	gotoXY(145, 0);
	cout << "Nam XB";
	gotoXY(155, 0);
	cout << "The Loai";
	gotoXY(40, tungdo);
	cout << a.ISBN;
	gotoXY(55, tungdo);
	cout << a.tensach;
	gotoXY(95, tungdo);
	cout << a.sotrang;
	gotoXY(105, tungdo);
	cout << a.tacgia;
	gotoXY(145, tungdo);
	cout << a.namxuatban;
	gotoXY(155, tungdo);
	cout << a.theloai;
	gotoXY(x, y);
	TextColor(7);
}

// Thêm đầu sách vào danh sách đầu sách để quản lí
void them_vao_ds_dausach(LIST_DS& l, dausach data)
{	  // nếu còn thêm được
	if (l.sl < MAX)
	{
		l.ds_dausach[l.sl] = new dausach;
		*l.ds_dausach[l.sl] = data;
		l.sl++;
	}
}

// sắp xếp đầu sách theo thể loại
void sap_xep_theo_theloai_dausach(LIST_DS& l)
{
	for (int i = 0; i < l.sl - 1; i++)
	{
		for (int j = i + 1; j < l.sl; j++)
		{
			if (l.ds_dausach[i]->theloai[0] > l.ds_dausach[j]->theloai[0])
			{
				if (l.ds_dausach[i]->tensach[0] > l.ds_dausach[j]->tensach[0])
				{
					swap(l.ds_dausach[i], l.ds_dausach[j]);
				}
			}
		}
	}
}

// in danh sach theo the loai
void xuat_ds_dausach(LIST_DS& l)
{
	TextColor(15);
	sap_xep_theo_theloai_dausach(l);
	for (int i = 0; i < l.sl; i++)
	{
		if (i < 40)
			xuat_dau_sach(*l.ds_dausach[i], i + 1);
		else
		{
			ButtonNext();
			char c = _getch();
			if (c == -32)
				c = _getch();
			if (c == 77)
			{
				xoa_hien_thi_dausach();
				for (int j = i, tungdo = 1; tungdo < 40 && j < l.sl; j++, tungdo++)
				{
					xuat_dau_sach(*l.ds_dausach[j], tungdo);
					i = j;
				}
			}
			else
			{
				return;
			}
		}
	}
	TextColor(7);
}

// tim kiếm đầu sách theo tên đầu sách nếu có xuất ra đầu sách <> -1 , ESC rt -2
int tim_kiem_dau_sach_theo_ten(LIST_DS l, string temp)
{
	int kt = 0; // biến dùng để kiểm tra có tìm được đầu sách hay ko
	xoa_hien_thi_dausach();
	for (int i = 0; i < l.sl; i++)
	{
		int tungdo1 = 3;
		// nếu tìm thấy temp là chuỗi con của tên đầu sách
		if (l.ds_dausach[i]->tensach.find(temp) != string::npos)
		{
			xoa_hien_thi_dausach();
			xuat_dau_sach(*l.ds_dausach[i], 1);
			kt++;
			for (NODE_DMS* p = l.ds_dausach[i]->dms.pHead; p != NULL; )
			{
				if (tungdo1 < 40)
				{

					xuat_sach1(l.ds_dausach[i]->tensach, p->data, tungdo1++);
					p = p->pNext;
				}
				else if (tungdo1 >= 40)
				{
					ButtonNext();
					char c = _getch();
					if (c == -32) c = _getch();
					if (c == 77)
					{
						xoa_hien_thi_dausach();
						xoa_hien_thi_sach();
						xuat_dau_sach(*l.ds_dausach[i], 1);
						for (int j = 3; j < 40; j++)
						{

							xuat_sach1(l.ds_dausach[i]->tensach, p->data, j);
							p = p->pNext;
							if (p == l.ds_dausach[i]->dms.pTail)
							{
								xuat_sach1(l.ds_dausach[i]->tensach, p->data, ++j);
								c = _getch();
								if (c == -32) c = _getch();
								if (c == 27) return -2;
								else if (c == 77)
									break;
							}
						}
						break;
					}
					else return -2;
				}
			}
		}
	}
	if (kt == 0)
		return -1;
}

// tìm kiếm đầu sách theo mã đầu sách nêu có trả về vị trí <> -1
int tim_kiem_dau_sach_theo_ma(LIST_DS l, string ma)
{
	for (int i = 0; i < l.sl; i++)
	{
		if (l.ds_dausach[i]->ISBN == ma)
			return i;
	}
	return -1;
}

// sửa đầu sách theo mã đầu sách. Nếu sửa thành công return 1 <> -1 ;ESC return -2
int sua_dau_sach(LIST_DS& l)
{
	int k = 0;
	string ma_dau_sach = "";
	do
	{
		xuat_ds_dausach(l);
		gotoXY(1, 10);
		cout << "                             ";
		gotoXY(1, 10);
		cout << "Nhap Ma Dau Sach: ";
		k = nhap_ki_tu1(ma_dau_sach);
		if (k == -1) // ESC
		{
			return -2;
		}
		int i = tim_kiem_dau_sach_theo_ma(l, ma_dau_sach);
		// nếu tìm kiếm thất bại
		if (i == -1)
		{
			BaoLoi("MA DAU SACH KHONG DUNG");
			ma_dau_sach = "";
			continue;
		}
		xoa_hien_thi_dausach();
		Box_NhapDS();
		dausach data;
		gotoXY(boxx + 8, boxy + 2);
		cout << l.ds_dausach[i]->ISBN;

		data.tensach = l.ds_dausach[i]->tensach;
		gotoXY(boxx + 12, boxy + 4);
		cout << data.tensach;
		k = nhap_ki_tu1(data.tensach);
		if (k == -1) // ESC
			return -2;

		data.sotrang = l.ds_dausach[i]->sotrang;
		gotoXY(boxx + 12, boxy + 6);
		cout << data.sotrang;
		k = nhap_so_nguyen(data.sotrang);
		if (k == -1) // ESC
			return -2;

		data.tacgia = l.ds_dausach[i]->tacgia;
		gotoXY(boxx + 11, boxy + 8);
		cout << data.tacgia;
		k = nhap_ki_tu(data.tacgia);
		if (k == -1) // ESC
			return -2;

		data.namxuatban = l.ds_dausach[i]->namxuatban;
		gotoXY(boxx + 10, boxy + 10);
		cout << data.namxuatban;
		k = nhap_so_nguyen(data.namxuatban);
		if (k == -1) // ESC
			return -2;

		data.theloai = l.ds_dausach[i]->theloai;
		gotoXY(boxx + 12, boxy + 12);
		cout << data.theloai;
		k = nhap_ki_tu(data.theloai);
		if (k == -1) // ESC
			return -2;

		l.ds_dausach[i]->tensach = data.tensach;
		l.ds_dausach[i]->sotrang = data.sotrang;
		l.ds_dausach[i]->tacgia = data.tacgia;
		l.ds_dausach[i]->namxuatban = data.namxuatban;
		l.ds_dausach[i]->theloai = data.theloai;
		return 1;
	} while (1);
}


// =========================================Danh muc sach=====================================
// tạo 1 node mới 
NODE_DMS* tao_node_sach(danhmucsach& x)
{
	node_danhmucsach* p = new node_danhmucsach;
	if (p == NULL)

		return NULL;
	p->data = x;
	p->pNext = NULL;
	return p;
}
// Thêm sách nếu thêm thành công rt 1 <> -1 ; ESC rt -2;
int them_sach(LIST_DS& l)
{
	int k = 0;
	string ma_dau_sach="";
	cout << "\nNhap Ma Dau Sach: ";
	k = nhap_ki_tu1(ma_dau_sach);
	if (k == -1) // ESC
		return -2;
	int i = tim_kiem_dau_sach_theo_ma(l, ma_dau_sach);
	if (i == -1) // Khong tim thay
	{
		BaoLoi("MA DAU SACH KHONG DUNG");
		return -1;
	}
	int n = 0;
	cout << "So Luong Sach Can Them : ";
	k = nhap_so_nguyen(n);
	if (k == -1) // ESC
		return -2;
	string temp="";
	cout << "Them Vao Vi Tri: ";
	k = nhap_ki_tu1(temp);
	if (k == -1) // ESC
		return -2;
	danhmucsach x;
	// lược bỏ phần mã đầu sách
	int q = 0;
	if (l.ds_dausach[i]->soluongsach > 0)
	{
		string str;
		int pos = l.ds_dausach[i]->dms.pTail->data.masach.find("-"); // lấy vị trí của kí tự - trong chuỗi
		str = l.ds_dausach[i]->dms.pTail->data.masach.substr(pos + 1); //  lấy chuỗi con của l.ds_dausach[i]->dms.pTail->data.masach bắt đầu sau kí tự -
		q = chuoi_sang_so(str);
	}
	else
		khoi_tao_sach(l.ds_dausach[i]->dms);
	for (int j = 0; j < n; j++)
	{
		if (q == 0)
			x.masach = l.ds_dausach[i]->ISBN + "-" + so_sang_chuoi(j + 1);
		else
			x.masach = l.ds_dausach[i]->ISBN + "-" + so_sang_chuoi(q + j + 1);

		cout << "Ma Sach: " << x.masach << endl;
		cout << "Them Vao Vi Tri: " << temp;
		k = nhap_ki_tu1(temp);
		if (k == -1) // ESC
			break;
		x.vitri = temp;
		x.trangthai = 0; // mặc định sách có thể mượn được
		them_sach_vao_ds(l.ds_dausach[i]->dms, tao_node_sach(x));
		l.ds_dausach[i]->soluongsach++;
	}
	return 1;
}

// thêm sách vào danh sách sách để quản lí
void them_sach_vao_ds(LIST_DMS& l, NODE_DMS* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}

// xuất 1 cuốn sách
void xuat_sach1(string ten_sach, danhmucsach a, int tungdo)
{
	int x = whereX();
	int y = whereY();
	TextColor(15);
	gotoXY(40, 2);
	cout << "Ma Sach";
	gotoXY(55, 2);
	cout << "Ten Sach";
	gotoXY(95, 2);
	cout << "Trang Thai";
	gotoXY(110, 2);
	cout << "Vi Tri";
	gotoXY(40, tungdo);
	cout << a.masach;
	gotoXY(55, tungdo);
	cout << ten_sach;
	gotoXY(95, tungdo);
	cout << a.trangthai;
	gotoXY(110, tungdo);
	cout << a.vitri;
	gotoXY(x, y);
	TextColor(7);
}

// xuất các sách có trong danh sách sách
void xuat_ds_sach1(LIST_DS l)
{
	for (int i = 0; i < l.sl; i++)
	{
		int j = 1; // tung độ xuất sách
		xoa_hien_thi_sach();
		for (NODE_DMS* p = l.ds_dausach[i]->dms.pHead; p != NULL; )
		{
			if (j < 40)
			{
				xuat_sach1(l.ds_dausach[i]->tensach, p->data, j++);
				if (p != l.ds_dausach[i]->dms.pTail)
					p = p->pNext;
				else // nếu p là node cuối thoát vòng lặp tăng i lên 1
				{
					ButtonNext();
					char c = _getch();
					if (c == -32)
						c = _getch();
					if (c == 77)
						break;
					else
					{
						return;
					}
				}
			}
			else if (j >= 40)
			{
				do
				{
					ButtonNext();
					char c = _getch();
					if (c == -32)
						c = _getch();
					if (c == 77)
					{
						xoa_hien_thi_sach();
						for (j = 0; j < 40; j++)
						{
							xuat_sach1(l.ds_dausach[i]->tensach, p->data, j + 1);
							if (p != l.ds_dausach[i]->dms.pTail)
								p = p->pNext;
							else
								return;
						}
						break;
					}
					return;
				} while (1);
			}
		}
	}
}


// tìm kiếm sách theo mã sách nếu có trả về  vị trí node trong ds <>  NULL
NODE_DMS* tim_kiem_sach(LIST_DS l, string ma_sach)
{
	for (int i = 0; i < l.sl; i++)
	{
		for (NODE_DMS* p = l.ds_dausach[i]->dms.pHead; p != NULL; p = p->pNext)
		{
			if (p->data.masach == ma_sach)
				return p;
		}
	}
	return NULL;
}


// =========================================== Muon Tra=====================================
// tạo 1 node mượn trả 
NODE_MT* tao_node_muontra(muontra x)
{
	NODE_MT* p = new NODE_MT;
	if (p == NULL)
	{
		cout << "Khong du bo nho cap phat" << endl;
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
	p->pPrev = NULL;
	return p;
}

// lập phiếu mượn sách
void them_phieu_muon(muontra& x)
{
	// phiếu mượn trả chỉ cần nhập mã sách . ngày mượn sẽ được cập nhật từ hệ thống thời gian thực, trạng thái sẽ mặc định = 0 nghĩa là sách đó đang mượn
	thoi_gian_thuc(x.ngaymuon);
	cout << "Ngay muon:" << x.ngaymuon.ngay << "/" << x.ngaymuon.thang << "/" << x.ngaymuon.nam << endl;
	x.ngaytra.ngay = 0;
	x.ngaytra.thang = 0;
	x.ngaytra.nam = 0;
	x.trangthai = 0; // trạng thái mặc định =0 độc giả đang mượn cuốn sách
	cout << "Trang thai: " << x.trangthai << endl;
}

// in thong tin của 1 phiếu mượn trả
void xuat_thong_tin_phieu_muontra(muontra a, string ten_sach, int tungdo)
{
	TextColor(15);
	int x = whereX();
	int y = whereY();
	gotoXY(45, 0);
	cout << "Ma Sach";
	gotoXY(60, 0);
	cout << "Ten Sach";
	gotoXY(100, 0);
	cout << "Ngay Muon";
	gotoXY(130, 0);
	cout << "Ngay Tra";
	gotoXY(160, 0);
	cout << "Trang Thai";
	gotoXY(45, tungdo);
	cout << a.masach;
	gotoXY(60, tungdo);
	cout << ten_sach;
	gotoXY(100, tungdo);
	cout << a.ngaymuon.ngay << "/" << a.ngaymuon.thang << "/" << a.ngaymuon.nam;
	gotoXY(130, tungdo);
	cout << a.ngaytra.ngay << "/" << a.ngaytra.thang << "/" << a.ngaytra.nam;
	gotoXY(160, tungdo);
	if (a.trangthai == 0)
		cout << "DANG MUON";
	else if (a.trangthai == 1)
		cout << "DA TRA";
	else
		cout << "LAM MAT";
	gotoXY(x, y);
	TextColor(7);
}

// thêm phiếu vào danh sách để quản lí
void them_vao_ds_muontra(LIST_MT& l, NODE_MT* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		p->pPrev = l.pTail;
		l.pTail = p;
	}
}

// hàm có chức năng xuất các sách đang mượn của 1 độc giả nếu có sách mượn rt 1 <> 0
int xuat_sach_dang_muon(TREE t, LIST_DS l)
{
	int kt = 0; // kiểm tra nếu độc giả có sách đang mượn thì tăng. nếu không có sách đang mượn =0
	int tungdo = 0;
	for (NODE_MT* p = t->data.mt.pHead; p != NULL; p = p->pNext)
	{
		for (int i = 0; i < l.sl; i++)
		{
			for (NODE_DMS* k = l.ds_dausach[i]->dms.pHead; k != NULL; k = k->pNext)
			{
				if (p->data.masach == k->data.masach)
				{
					if (p->data.trangthai == 0 || p->data.trangthai == 2)
					{
						kt++;
						xuat_thong_tin_phieu_muontra(p->data, l.ds_dausach[i]->tensach, ++tungdo);
					}
				}
			}
		}
	}
	if (kt == 0) // độc giả không mượn sách
	{
		return 0;
	}
	return 1;
}


// đếm số sách độc giả đang mượn dùng để kiểm tra điều kiện mượn sách 
int dem_sach_docgia_muon(TREE t)
{
	int so_sach_muon = 0;
	for (NODE_MT* p = t->data.mt.pHead; p != NULL; p = p->pNext)
	{
		if (p->data.trangthai == 0) // sách chưa trả
			so_sach_muon++;
	}
	return so_sach_muon;
}

// mượn thành công tr 1 <> -1 ; esc rt -2
int muonsach(TREE& t, LIST_DS& l)
{
	int k1 = 0; // bieesn kiem tra ESC cua ham nhap
	int tungdo = 0;
	TREE p = NULL;// lưu  độc giả tìm được
	int ma_doc_gia = 0;
	do
	{
		xuat_ds_thong_tin_doc_gia(t, tungdo);
		tungdo = 0;
		gotoXY(1, 10);
		cout << "                            ";
		gotoXY(1, 10);
		cout << "Nhap Ma DG: ";
		k1 = nhap_so_nguyen(ma_doc_gia);
		if (k1 == -1) // ESC
		{
			return -2;
		}
		p = tim_kiem_docgia_ma(t, ma_doc_gia);
		if (p == NULL)
		{
			BaoLoi("MA DOC GIA KHONG DUNG");
			ma_doc_gia = 0;
			continue;
		}
		xoa_hien_thi_doc_gia();
		if (p->data.trangthaithe == 0) // thẻ bị khóa
		{
			BaoLoi("! THE BI KHOA. !TRA SACH DE TIEP TUC");
			ma_doc_gia = 0;
			continue;
		}
		// kiểm tra số lượng sách độc giả đã mượn nếu > 3 không mượn được
		int dem = dem_sach_docgia_muon(p);
		if (dem >= 3)
		{
			BaoLoi("! DOC GIA MUON QUA 3 CUON. !TRA SACH DE MUON THEM");
			ma_doc_gia = 0;
			continue;
		}
		break;
	} while (1);
	NODE_DMS* k = NULL;
	string ma_sach = "";
	string ma_dau_sach;
	bool check = false; // kiem tra co tim thay ma sach hay ko
	int i = 0;
	do
	{
		gotoXY(1, 10); cout << "                                  ";
		gotoXY(1, 10); cout << "Nhap Ma Sach Can Muon: ";
		k1 = nhap_ki_tu1(ma_sach);
		if (k1 == -1) // ESC
			return -2;
		ma_dau_sach = tach_ma_sach(ma_sach);
		i = tim_kiem_dau_sach_theo_ma(l, ma_dau_sach);
		if (i == -1) // khoong tim thay
		{
			BaoLoi("MA SACH KHONG DUNG");
			ma_sach = "";
			continue;
		}
		else // tim thay lay vi tri cua i
		{
			for (k = l.ds_dausach[i]->dms.pHead; k != NULL; k = k->pNext)
			{
				if (k->data.masach == ma_sach)
				{
					check = true; // danh dau tim thay sach
					k->data.trangthai = 1; // cap nhat sach co nguoi muon
					break;
				}
			}
			if (check == true)
				break;
			else
			{
				BaoLoi("KHONG TIM THAY MA SACH");
				ma_sach = "";
				continue;
			}
		}
	} while (1);
	// thêm vào danh sách mượn trả
	muontra x;
	x.masach = ma_sach;
	l.ds_dausach[i]->soluongmuon++; // tăng số lượng mượn cuốn sách
	p->data.tongsosach++;
	them_phieu_muon(x);
	them_vao_ds_muontra(p->data.mt, tao_node_muontra(x));
	return 1;
}

// trả sách thành công tr 1 <> -1 ; ESC rt -2
int trasach(TREE& t, LIST_DS& l)
{
	int k1 = 0;
	int tungdo = 0;
	xuat_ds_thong_tin_doc_gia(t, tungdo);
	tungdo = 0;
	int ma = 0;
	TREE p = NULL;
	do
	{
		gotoXY(1, 10);
		cout << "                             ";
		gotoXY(1, 10);
		cout << "NHAP MA DG: ";
		k1 = nhap_so_nguyen(ma);
		if (k1 == -1) // ESC
			return -2;

		p = tim_kiem_docgia_ma(t, ma);
		xoa_hien_thi_doc_gia();

		if (p == NULL)
		{
			BaoLoi("MA DOC GIA KHONG DUNG");
			ma = 0;
			continue;
		}
		else
		{
			if (xuat_sach_dang_muon(p, l) == 0) // độc giả không có sách mượn
			{
				BaoLoi("DOC GIA KHONG CO SACH MUON");
				return -1;
			}
			string ma_sach="";
			do
			{
				gotoXY(1, 10);
				cout << "                                  ";
				gotoXY(1, 10);
				cout << "NHAP MA SACH CAN TRA: ";
				k1 = nhap_ki_tu1(ma_sach);
				if (k1 == -1) // ESC
					return -2;
				NODE_DMS* k = tim_kiem_sach(l, ma_sach); // lưu vị trí của sách trả về trong danh sách qua mã sách
				if (k == NULL)
				{
					BaoLoi("MA SACH KHONG DUNG");
					ma_sach = "";
					continue;
				}
				else
				{
					Date n1;
					NODE_MT* q = NULL;
					int dem = 0; // biến kiểm tra số sách độc giả đã làm mất =0 mở thẻ
					for (q = p->data.mt.pHead; q != NULL; q = q->pNext)
					{
						if (q->data.masach == ma_sach)
						{
							k->data.trangthai = 0;// cập nhật lại sách cho mượn được 
							q->data.trangthai = 1; // cập nhật lại đọc giả đã trả sách
							thoi_gian_thuc(n1); // lấy thời gian hệ thống
							q->data.ngaytra.ngay = n1.ngay;
							q->data.ngaytra.thang = n1.thang;
							q->data.ngaytra.nam = n1.nam;
						}
						if (q->data.trangthai == 2) dem++;
					}
					// nếu đếm !=0 . còn sách làm mất. Khóa thẻ
					if (dem != 0)
						p->data.trangthaithe = 0;
					// ngược lại mở thẻ
					else
						p->data.trangthaithe = 1;
				}
				break;
			} while (1);
			break;
		}
	} while (1);

	return 1;
}
// ========================================= Qua Han =============================

// in ra danh sách các độc giả quá hạn
void ds_quahan(TREE t, LIST_QUAHAN& l)
{
	int x = whereX();
	int y = whereY();
	int n = 0;
	TREE Stack[STACKSIZE];
	int top = -1;
	Date n1;
	do
	{
		while (t != NULL)
		{
			Stack[++top] = t;
			t = t->pLeft;
		}
		if (top != -1)
		{
			t = Stack[top--];
			for (NODE_MT* p = t->data.mt.pHead; p != NULL; p = p->pNext)
			{
				n++;
				l.ds_quahan[n - 1].ma_doc_gia = t->data.mathe;
				thoi_gian_thuc(n1);
				if (p->data.trangthai == 0)
				{
					l.ds_quahan[n - 1].so_ngay_quahan = tinh_so_ngay(p->data.ngaymuon);
				}
				else
					l.ds_quahan[n - 1].so_ngay_quahan = 0;
				l.ds_quahan[n - 1].ma_sach = p->data.masach;
				l.ds_quahan[n - 1].ho = t->data.ho;
				l.ds_quahan[n - 1].ten = t->data.ten;
				l.ds_quahan[n - 1].phai = t->data.phai;
			}
			t = t->pRight;
		}
		else
			break;
	} while (1);
	l.sl = n;
	quahan temp;
	// sap xep giam dan ds qua han
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (l.ds_quahan[i].so_ngay_quahan < l.ds_quahan[j].so_ngay_quahan)
			{
				temp = l.ds_quahan[i];
				l.ds_quahan[i] = l.ds_quahan[j];
				l.ds_quahan[j] = temp;
			}
		}
	}
	// xuat ds qua han theo thu tu giam dan
	for (int k = 0; k < l.sl; k++)
	{
		if (l.ds_quahan[k].so_ngay_quahan > 7)
		{
			gotoXY(45, 0);
			cout << "MA THE";
			gotoXY(65, 0);
			cout << "HO";
			gotoXY(85, 0);
			cout << "TEN";
			gotoXY(100, 0);
			cout << "PHAI";
			gotoXY(120, 0);
			cout << "MA SACH";
			gotoXY(140, 0);
			cout << "SO NGAY QUA HAN";
			gotoXY(45, k + 1);
			cout << l.ds_quahan[k].ma_doc_gia;
			gotoXY(65, k + 1);
			cout << l.ds_quahan[k].ho;
			gotoXY(85, k + 1);
			cout << l.ds_quahan[k].ten;
			gotoXY(100, k + 1);
			cout << l.ds_quahan[k].phai;
			gotoXY(120, k + 1);
			cout << l.ds_quahan[k].ma_sach;
			gotoXY(145, k + 1);
			cout << l.ds_quahan[k].so_ngay_quahan;
			gotoXY(x, y);
		}
	}
}

// =================== 10 sách có lượt mượn nhiều nhất ====================
void top10sach(LIST_DS l)
{
	dausach* temp = NULL;
	// sắp xếp theo thứ tự giảm dần top 10 sách
	for (int i = 0; i < l.sl - 1; i++)
	{
		for (int j = i + 1; j < l.sl; j++)
		{
			if (l.ds_dausach[i]->soluongmuon < l.ds_dausach[j]->soluongmuon)
			{
				temp = l.ds_dausach[i];
				l.ds_dausach[i] = l.ds_dausach[j];
				l.ds_dausach[j] = temp;
			}

		}
	}
	for (int k = 0; k < l.sl && k < 10; k++)
	{
		xuat_dau_sach(*l.ds_dausach[k], k + 1);
	}
}
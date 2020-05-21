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
void chuyen_cay_sang_mang(TREE t, docgia * arr, int& i);// duyệt cây copy dữ liệu vào mảng
void sap_xep_doc_gia_theo_ten(docgia* arr, int n);// sắp xếp độc giả theo tên + họ tăng dần
void tim_kiem_pt_the_mang(TREE& p, TREE& q);//Phần tử p đang được thế mạng cho phần tử q
void xoa_theo_ma_doc_gia(TREE& t, int x);// hàm có chức năng xóa 1 độc giả bất kì theo mã độc giả
TREE tim_kiem_docgia_ma(TREE& t, int ma_doc_gia);// tìm kiếm độc giả trong danh sách với mã độc giả
void tim_kiem_ds_doc_gia_ten(TREE t, string ch1, int tungdo);// tìm kiếm tên độc giả
int sua_thong_tin_doc_gia(TREE& t, int ma_doc_gia);// hiệu chỉnh thông tin độc giả thành công rt 1 <> ESC rt -2
int SoluongDG(TREE t);// đếm số đọc giả trong cây

//========================================== Đau Sach ==================================================

int nhap_DauSach(LIST_DS& l, dausach& data);// thêm đầu sách nếu thêm thành công rt 1 <> ESC rt -2
void xuat_dau_sach(dausach& a, int tungdo);// in ra 1 đầu sách
void them_vao_ds_dausach(LIST_DS& l, dausach data);// Thêm đầu sách vào danh sách đầu sách để quản lí
void them_vao_ds_dausach(LIST_DS& l, dausach data);// Thêm đầu sách vào danh sách đầu sách để quản lí
void sap_xep_theo_theloai_dausach(LIST_DS& l);// sắp xếp đầu sách theo thể loại
void xuat_ds_dausach(LIST_DS& l);// in danh sach theo the loai
int tim_kiem_dau_sach_theo_ten(LIST_DS l, string temp);// tim kiếm đầu sách theo tên đầu sách nếu có xuất ra đầu sách <> -1;
int tim_kiem_dau_sach_theo_ma(LIST_DS l, string ma);// tìm kiếm đầu sách theo mã đầu sách nêu có trả về vị trí <> -1
int sua_dau_sach(LIST_DS& l);// sửa đầu sách theo mã đầu sách. Nếu sửa thành công return 1 <> -1 ;ESC return -2
int xoa_dau_sach(LIST_DS& l, string ma_dau_sach);// xóa đầu sách thành công return 1 <> return -1

//=========================================Danh muc sach===============================================
NODE_DMS* tao_node_sach(danhmucsach& x);// tạo 1 node mới 
int them_sach(LIST_DS& l);// Thêm sách nếu thêm thành công rt 1 <> -1 ; ESC rt -2;
void them_sach_vao_ds(LIST_DMS& l, NODE_DMS* p);// thêm sách vào danh sách sách để quản lí
void xuat_sach1(string ten_sach, danhmucsach a, int tungdo);// xuất 1 cuốn sách
void xuat_ds_sach1(LIST_DS l);// xuất các sách có trong danh sách sách
int tim_kiem_sach_ten(LIST_DS l, string ten_sach);// tim kiem sach theo ten sach nếu thấy in ra. nếu không trả về -1
NODE_DMS* tim_kiem_sach(LIST_DS l, string ma_sach);// tìm kiếm sách theo mã sách nếu có trả về  vị trí node trong ds <>  NULL
int xoa_sach(LIST_DS& l, string ma_sach);// xóa sách theo mã đầu sách. Xóa thành công rt 1 <> -1
int hieu_chinh_sach(danhmucsach& a, string ma_sach);// hiệu chỉnh sách theo mã sách . hiệu chỉnh thành công rt 1 <> -1 ; ESC rt -2

//==========================================Muon tra===================================================

NODE_MT* tao_node_muontra(muontra x);// tạo 1 node mượn trả 
void them_phieu_muon(muontra& x);// lập phiếu mượn sách
void xuat_thong_tin_phieu_muontra(muontra a, string ten_sach, int tungdo);// in thong tin của 1 phiếu mượn trả
void them_vao_ds_muontra(LIST_MT& l, NODE_MT* p);// thêm phiếu vào danh sách để quản lí
int xuat_sach_dang_muon(TREE t, LIST_DS l);// hàm có chức năng xuất các sách đang mượn của 1 độc giả nếu có sách mượn rt 1 <> 0
int tim_kiem_doc_gia_qua_han(LIST_QUAHAN& l, int ma_doc_gia);// kiểm tra độc giả quá hạn trong danh sách quá hạn nếu số ngày quá hạn > 7 tra ve so ngay quahan <> 0
int dem_sach_docgia_muon(TREE t);// đếm số sách độc giả đang mượn dùng để kiểm tra điều kiện mượn sách 
int muonsach(TREE& t, LIST_DS& l, LIST_QUAHAN l1);// mượn thành công tr 1 <> -1 ; esc rt -2
int trasach(TREE& t, LIST_DS& l);// trả sách thành công tr 1 <> -1 ; ESC rt -2

// =========================================== Qua Han ================================
int so_ngay_quahan(Date n1, Date n2);// hàm trả về số ngày quá hạn. Tính số ngày chênh lệch giữa 2 mốc thời gian
void ds_quahan(TREE t, LIST_QUAHAN& l);// in ra danh sách các độc giả quá hạn

// =================== 10 sách có lượt mượn nhiều nhất ====================
void top10sach(LIST_DS l);

// ========================================== Độc Giả==========================================

// nhập thành công rt 1 <> esc rt -2
int nhap_doc_gia(docgia& x)
{
	cout << "Ma the: " << x.mathe << endl;
	cout << "Nhap ho doc gia: ";
	x.ho = nhap_ki_tu();
	if (x.ho == "-1") // ESC
		return -2;
	cout << "Nhap ten doc gia: ";
	x.ten = nhap_ki_tu();
	if (x.ten == "-1") // ESC
		return -2;
	cout << "Nhap gioi tinh doc gia: ";
	x.phai = nhap_ki_tu();
	if (x.phai == "-1") // ESC
		return -2;
	x.trangthaithe = 1; // trạng thái lúc thêm độc giả auto =1. có thể mượn sách
	cout << "Trang thai the: " << x.trangthaithe << endl;
	x.tongsosach = 0;
	return 1;
}
// Thêm độc giả vào danh sách thêm thành công rt 1 <> -1 ESC rt -2
int them_doc_gia_vao_ds(TREE& t)
{
	docgia x;
	x.mathe = tao_ma_doc_gia(t);
	int i = nhap_doc_gia(x);
	if ( i== -2) // ESC
			return -2;
	else
	{
		them_node_vao_cay(t, x);
		BaoLoi("Them Thanh Cong");
	}
	return 1;
}

// them 1 node vao cay theo ma doc gia 
void them_node_vao_cay(TREE& t,docgia x)
{
	if (t == NULL)
	{
		NODE_DG* p = new NODE_DG;
		if (p == NULL) return;
		p->data = x;
		p->pLeft = p->pRight = NULL;
		t = p;
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
	gotoXY(45, 0);
	cout << "Ma Doc Gia";
	gotoXY(65, 0);
	cout << "Ho va Ten";
	gotoXY(90, 0);
	cout << "Phai";
	gotoXY(100, 0);
	cout << "Trang Thai The";
	gotoXY(45, tungdo);
	cout << a.mathe;
	gotoXY(65, tungdo);
	cout << a.ho << " " << a.ten;
	gotoXY(90, tungdo);
	cout << a.phai;
	gotoXY(107, tungdo);
	cout << a.trangthaithe;
	gotoXY(x, y);

}

//duyet theo LNR in ra ma the tang dan
void xuat_ds_thong_tin_doc_gia(TREE t, int& i)
{
	if (t != NULL)
	{
		
		xuat_ds_thong_tin_doc_gia(t->pLeft, i);
		Xuat_Thong_Tin_Doc_Gia(t->data, ++i);
		xuat_ds_thong_tin_doc_gia(t->pRight, i);
	}

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
			else if(arr[i].ten == arr[j].ten)
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
			BaoLoi("Xoa Thanh Cong");
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
void tim_kiem_ds_doc_gia_ten(TREE t, string ch1, int tungdo)
{
	if (t != NULL)
	{
		// ch1 là chuỗi con của tên độc giả
		if (t->data.ten.find(ch1) != string::npos)
		{
			TextColor(14);
			Xuat_Thong_Tin_Doc_Gia(t->data, tungdo);
		}
		tim_kiem_ds_doc_gia_ten(t->pLeft, ch1, tungdo++);
		tim_kiem_ds_doc_gia_ten(t->pRight, ch1, tungdo++);

	}
	TextColor(7);
	return;
}

// hiệu chỉnh thông tin độc giả thành công rt 1 <> ESC rt -2
int sua_thong_tin_doc_gia(TREE& t, int ma_doc_gia)
{
	TREE p = tim_kiem_docgia_ma(t, ma_doc_gia);
	if (p == NULL)
	{
		BaoLoi("Ma Doc Gia Khong Ton Tai");
		return 0;
	}
	else
	{
		int tungdo = 0;
		Xuat_Thong_Tin_Doc_Gia(p->data,tungdo);
		TextColor(15);
		cout << "Ma the: " << p->data.mathe << endl;
		cout << "Ho: ";
		p->data.ho = nhap_ki_tu();
		if (p->data.ho == "-1") // ESC
			return -2;
		cout << "Ten: ";
		p->data.ten = nhap_ki_tu();
		if (p->data.ten == "-1") // ESC
			return -2;
		cout << "Phai: ";
		p->data.phai = nhap_ki_tu();
		if (p->data.phai == "-1") // ESC
			return -2;
		cout << "Trang thai the: ";
		p->data.trangthaithe = nhap_so_nguyen();
		if (p->data.trangthaithe == -1) // ESC
			return -2;
		TextColor(7);
	}
	return 1;
}

// đếm số đọc giả trong cây
int SoluongDG(TREE t)
{
	int n = 0;
	const int STACKSIZE = 100;
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
	while (1)
	{
		cout << "Ma ISBN : ";
		data.ISBN = nhap_ki_tu1();
		if (data.ISBN == "-1") // ESC
			return -2;
		if (tim_kiem_dau_sach_theo_ma(l, data.ISBN) != -1)
		{
			BaoLoi("Ma ISBN bi trung vui long nhap lai");
			continue;
		}
		cout << "Ten Sach: ";
		data.tensach = nhap_ki_tu1();
		if (data.tensach == "-1") // ESC
			return -2;
		cout << "So Trang: ";
		data.sotrang = nhap_so_nguyen();
		if (data.sotrang == -1) // ESC
			return -2;
		cout << "Tac Gia: ";
		data.tacgia = nhap_ki_tu();
		if (data.tacgia == "-1") // ESC
			return -2;
		cout << "Nam Xuat Ban: ";
		data.namxuatban = nhap_so_nguyen();
		if (data.namxuatban == -1) // ESC
			return -2;
		cout << "The Loai: ";
		data.theloai = nhap_ki_tu();
		if (data.theloai == "-1") // ESC
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
	gotoXY(30, 0);
	cout << "Ma Dau Sach";
	gotoXY(45, 0);
	cout << "Ten sach";
	gotoXY(75, 0);
	cout << "So trang";
	gotoXY(85, 0);
	cout << "Tac gia";
	gotoXY(115, 0);
	cout << "Nam XB";
	gotoXY(125, 0);
	cout << "The Loai";
	gotoXY(30, tungdo);
	cout << a.ISBN;
	gotoXY(45, tungdo);
	cout << a.tensach;
	gotoXY(75, tungdo);
	cout << a.sotrang;
	gotoXY(85, tungdo);
	cout << a.tacgia;
	gotoXY(115, tungdo);
	cout << a.namxuatban;
	gotoXY(125, tungdo);
	cout << a.theloai;
	gotoXY(x, y);
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
		xuat_dau_sach(*l.ds_dausach[i], i + 1);
	TextColor(7);
}

// tim kiếm đầu sách theo tên đầu sách nếu có xuất ra đầu sách <> -1;
int tim_kiem_dau_sach_theo_ten(LIST_DS l, string temp)
{
	int kt = 0; // biến dùng để kiểm tra có tìm được đầu sách hay ko
	for (int i = 0; i < l.sl; i++)
	{
		// nếu tìm thấy temp là chuỗi con của tên đầu sách
		if (l.ds_dausach[i]->tensach.find(temp) != string::npos)
		{
			TextColor(14);
			xuat_dau_sach(*l.ds_dausach[i],i+1);
			kt = 1;
			continue;
		}
	}
	TextColor(7);
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
	string ma_dau_sach;
	do
	{
		cout << "\nNhap Ma Dau Sach: ";
		ma_dau_sach = nhap_ki_tu1();
		if (ma_dau_sach == "-1") // ESC
		{
			return -2;
		}
		int i = tim_kiem_dau_sach_theo_ma(l, ma_dau_sach);
		// nếu tìm kiếm thất bại
		if (i == -1)
		{
			BaoLoi("Ma Dau Sach Khong Ton Tai");
			return -1;
		}
		cout << "Ten sach: ";
		l.ds_dausach[i]->tensach = nhap_ki_tu1();
		if (l.ds_dausach[i]->tensach == "-1") // ESC
		{
			return -2;
		}
		cout << "So trang: ";
		l.ds_dausach[i]->sotrang = nhap_so_nguyen();
		if (l.ds_dausach[i]->sotrang == -1) // ESC
		{
			return -2;
		}
		cout << "Tac gia: ";
		l.ds_dausach[i]->tacgia = nhap_ki_tu();
		if (l.ds_dausach[i]->tacgia == "-1") // ESC
		{
			return -2;
		}
		cout << "Nam xuat ban: ";
		l.ds_dausach[i]->namxuatban = nhap_so_nguyen();
		if (l.ds_dausach[i]->namxuatban == -1) // ESC
		{
			return -2;
		}
		cout << "The loai: ";
		l.ds_dausach[i]->theloai = nhap_ki_tu();
		if (l.ds_dausach[i]->theloai == "-1") // ESC
		{
			return -2;
		}
		BaoLoi("Sua thanh cong.");
		return 1;
	} while (1);
}

// xóa đầu sách thành công return 1 <> return -1
int xoa_dau_sach(LIST_DS& l, string ma_dau_sach)
{
	int i = tim_kiem_dau_sach_theo_ma(l, ma_dau_sach);
	if (i == -1)
	{
		return -1;
	}
	delete l.ds_dausach[i];
	for (; i < l.sl; i++)
	{
		l.ds_dausach[i] = l.ds_dausach[i + 1];
	}l.sl--;

	return 1;
}


// =========================================Danh muc sach=====================================

// tạo 1 node mới 
NODE_DMS* tao_node_sach(danhmucsach& x)
{
	node_danhmucsach* p = new node_danhmucsach;
	if (p == NULL)
	{
		BaoLoi("Khong du bo nho cap phat");
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}

// Thêm sách nếu thêm thành công rt 1 <> -1 ; ESC rt -2;
int them_sach(LIST_DS& l)
{
	string ma_dau_sach;
	cout << "\nNhap Ma Dau Sach: ";
	ma_dau_sach = nhap_ki_tu1();
	if (ma_dau_sach == "-1") // ESC
		return -2;
	int i = tim_kiem_dau_sach_theo_ma(l, ma_dau_sach);
	if (i == -1) // Khong tim thay
	{
		BaoLoi("Ma Dau Sach Khong Ton Tai");
		return -1;
	}
	int n;
	cout << "\nNhap So Luong Sach Can Them: ";
	n = nhap_so_nguyen();
	if (n == -1) // ESC
		return -2;
	string temp;
	cout << "Them Vao Vi Tri: ";
	temp = nhap_ki_tu1();
	if (temp == "-1") // ESC
		return -2;
	khoi_tao_sach(l.ds_dausach[i]->dms);
	for (int j = 0; j < n; j++)
	{
		NODE_DMS* p = new NODE_DMS;
		p->data.masach = tao_masach(l.ds_dausach[i]->dms, ma_dau_sach);
		p->data.vitri = temp;
		p->data.trangthai = 0; // mặc định sách có thể mượn được
		them_sach_vao_ds(l.ds_dausach[i]->dms, tao_node_sach(p->data));
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
	gotoXY(45, 0);
	cout << "Ma Sach";
	gotoXY(65, 0);
	cout << "Ten Sach";
	gotoXY(95, 0);
	cout << "Trang Thai";
	gotoXY(110, 0);
	cout << "Vi Tri";
	gotoXY(45, tungdo);
	cout << a.masach;
	gotoXY(65, tungdo);
	cout << ten_sach;
	gotoXY(95, tungdo);
	cout << a.trangthai;
	gotoXY(110, tungdo);
	cout << a.vitri;
	gotoXY(x, y);
}

// xuất các sách có trong danh sách sách
void xuat_ds_sach1(LIST_DS l)
{
	int j = 0;
	for (int i = 0; i < l.sl; i++)
	{
		for (NODE_DMS* p = l.ds_dausach[i]->dms.pHead; p != NULL; p = p->pNext)
		{
			xuat_sach1(l.ds_dausach[i]->tensach, p->data, ++j);
		}
	}
}

// tim kiem sach theo ten sach nếu thấy in ra. nếu không trả về -1
int tim_kiem_sach_ten(LIST_DS l, string ten_sach)
{
	int kt = 0; // biến dùng để kiểm tra có tìm thấy hay ko. Nếu thấy tăng kt lên <> =0
	int tungdo = 0;
	xoa_hien_thi_sach(l);
	for (int i = 0; i < l.sl; i++)
	{
		if (l.ds_dausach[i]->tensach.find(ten_sach) != string::npos)
		{
			kt++; // tăng kt để biết đã tìm thấy
			TextColor(15);
			for (NODE_DMS* p = l.ds_dausach[i]->dms.pHead; p != NULL; p = p->pNext)
			{
				TextColor(14);
				xuat_sach1(l.ds_dausach[i]->tensach,p->data,++tungdo);
			}
		}
	}
	TextColor(7);
	if (kt == 0)
		return -1;
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

// xóa sách theo mã đầu sách. Xóa thành công rt 1 <> -1
int xoa_sach(LIST_DS& l, string ma_sach)
{
	for (int i = 0; i < l.sl; i++)
	{
		NODE_DMS* p = l.ds_dausach[i]->dms.pHead;
		if (l.ds_dausach[i]->dms.pHead == NULL)
		{
			if (i == l.sl - 1)
			{
				BaoLoi("Danh Sach Rong");
				return -1;
			}
			continue;
		}
		NODE_DMS* q = NULL; // con trỏ q chạy song song với p và đứng trước p
		while (p != NULL)
		{
			if (p->data.masach == ma_sach)
				break;
			q = p;
			p = p->pNext;
		}
		if (p == NULL)
		{
			if (i == l.sl - 1)
			{
				BaoLoi("Ma Sach Khong Ton Tai");
				return -1;
			}
			continue;
		}
		// xoa node dau
		else if (q == NULL)
		{
			l.ds_dausach[i]->dms.pHead = p->pNext;
			if (l.ds_dausach[i]->dms.pHead == NULL)
				l.ds_dausach[i]->dms.pTail = NULL;
	
			delete p;
			l.ds_dausach[i]->soluongsach--;
			return 1;
		}
		// xóa node p sau q
		else
		{
			q->pNext = p->pNext;
			if (p = l.ds_dausach[i]->dms.pTail)
				l.ds_dausach[i]->dms.pTail = q;
			delete p;
			l.ds_dausach[i]->soluongsach--;
			return 1;
		}
	}
	return -1;
}

// hiệu chỉnh sách theo mã sách . hiệu chỉnh thành công rt 1 <> -1 ; ESC rt -2
int hieu_chinh_sach(danhmucsach& a, string ma_sach)
{
		TextColor(15);
		cout << "Ma sach: " << a.masach<< endl;
		cout << "Trang thai: ";
		a.trangthai = nhap_so_nguyen();
		if (a.trangthai == -1) // ESC
			return -2;
		cout << "Vi tri: ";
		a.vitri = nhap_ki_tu1();
		if (a.vitri == "-1") // ESC
			return -2;
		TextColor(7);
		return 1;
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
	cout << "Ngay muon:" << x.ngaymuon.ngay_hien_tai << "/" << x.ngaymuon.thang_hien_tai << "/" << x.ngaymuon.nam_hien_tai << endl;
	x.ngaytra.ngay_hien_tai = 0;
	x.ngaytra.thang_hien_tai = 0;
	x.ngaytra.nam_hien_tai = 0;
	x.trangthai = 0; // trạng thái mặc định =0 độc giả đang mượn cuốn sách
	cout << "Trang thai: " << x.trangthai << endl;
}

// in thong tin của 1 phiếu mượn trả
void xuat_thong_tin_phieu_muontra(muontra a, string ten_sach, int tungdo)
{
	int x = whereX();
	int y = whereY();
	gotoXY(45, 0);
	cout << "Ma Sach";
	gotoXY(65, 0);
	cout << "Ten Sach";
	gotoXY(85, 0);
	cout << "Ngay Muon";
	gotoXY(100, 0);
	cout << "Ngay Tra";
	gotoXY(120, 0);
	cout << "Trang Thai";
	gotoXY(45, tungdo);
	cout << a.masach;
	gotoXY(65, tungdo);
	cout << ten_sach;
	gotoXY(85, tungdo);
	cout << a.ngaymuon.ngay_hien_tai << "/" << a.ngaymuon.thang_hien_tai << "/" << a.ngaymuon.nam_hien_tai;
	gotoXY(100, tungdo);
	cout << a.ngaytra.ngay_hien_tai << "/" << a.ngaytra.thang_hien_tai << "/" << a.ngaytra.nam_hien_tai;
	gotoXY(120, tungdo);
	cout << a.trangthai;
	gotoXY(x, y);

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
				if (p->data.masach == k->data.masach && p->data.trangthai == 0)
				{
					kt++;
					xuat_thong_tin_phieu_muontra(p->data, l.ds_dausach[i]->tensach, ++tungdo);
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

// kiểm tra độc giả quá hạn trong danh sách quá hạn nếu số ngày quá hạn > 7 tra ve so ngay quahan <> 0
int tim_kiem_doc_gia_qua_han(LIST_QUAHAN& l, int ma_doc_gia)
{

	for (int i = 0; i < l.sl; i++)
	{
		if (l.ds_quahan[i].ma_doc_gia == ma_doc_gia)
		{
			return l.ds_quahan->so_ngay_quahan;
		}
	}
	return 0;
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
int muonsach(TREE& t, LIST_DS& l, LIST_QUAHAN l1)
{
	int tungdo=0;
	xuat_ds_thong_tin_doc_gia(t, tungdo);
	tungdo = 0;
	int ma_doc_gia;
	cout << "Nhap ma doc gia: ";
	ma_doc_gia = nhap_so_nguyen();
	if (ma_doc_gia == -1) // ESC
	{
		return -2;
	}
	TREE p = tim_kiem_docgia_ma(t, ma_doc_gia);
	if (p == NULL)
	{
		BaoLoi("Ma doc gia khong ton tai.");
		return -1;
	}
	xoa_hien_thi_doc_gia(t);
	// kiểm tra số lượng sách độc giả đã mượn nếu > 3 không mượn được
	int dem = dem_sach_docgia_muon(p);
	if (dem >= 3)
	{
		BaoLoi("Doc gia da muon qua 3 cuon.Khong the muon them");
		return -1;
	}
	int so_ngay_quahan = tim_kiem_doc_gia_qua_han(l1, ma_doc_gia);
	if (so_ngay_quahan > 7)
	{
		BaoLoi("Doc gia da muon sach qua han (>7 ngay).Khong the muon them");
		return -1;
	}
	// thêm vào danh sách mượn trả
	xuat_ds_dausach(l);
	muontra x;
	string temp;
	cout << "Nhap Ten Sach : ";
	temp = nhap_ki_tu1();
	if (temp == "-1") // ESC
	{
		return -2;
	}
	else
	{
		xoa_hien_thi_dausach(l);
		int j = tim_kiem_dau_sach_theo_ten(l, temp);
		// Không tìm thấy tên sách
		if (j == -1)
		{
			BaoLoi("Ten Sach Khong Tim Thay");
			return -1;
		}
		string ma;
		int i = -1; // lưu vị trí của mã sách nhập vào 
		bool kt = true; // biến tạm thời dùng để dừng vòng lặp
		do
		{
			cout << "Nhap Ma Dau Sach Sach Can Muon: ";
			ma = nhap_ki_tu1();
			if (ma == "-1") // ESC
			{
				return -2;
			}
			i = tim_kiem_dau_sach_theo_ma(l, ma);
			if (i == -1)
			{
				BaoLoi("Ma dau sach khong dung.Vui long nhap lai.");
				kt = false;
			}
			else
			{
				kt = true;
			}
		} while (kt == false);
		xoa_hien_thi_dausach(l);
		// in danh sách các sách còn mượn được
		TextColor(15);
		// biến tạm thời truyền vào hàm xuat_sach1 để in ra theo tung độ
		int tungdo = 0;
		for (NODE_DMS* q = l.ds_dausach[i]->dms.pHead; q != NULL; q = q->pNext)
		{
			if (q->data.trangthai == 0) // sách còn mượn được
				xuat_sach1(l.ds_dausach[i]->tensach, q->data, ++tungdo);
		}
		TextColor(7);
		string ma_sach;
		NODE_DMS* k = NULL; // lưu vị trí node trả về trong tim_kiem_sach
		do
		{
			cout << "Nhap ma sach can muon: ";
			ma_sach = nhap_ki_tu1();
			if (ma_sach == "-1") // ESC
				return -2;
			k = tim_kiem_sach(l, ma_sach); // node chứa vị trí của sách trong trong ds
			if (k == NULL)
			{
				BaoLoi("Ma sach khong ton tai. vui long nhap lai");
				kt = false;
			}
			else
			{
				if (k->data.trangthai == 1)
				{
					BaoLoi("sach da co nguoi muon");
					kt = false;
				}
				else if (k->data.trangthai == 2)
				{
					BaoLoi("Sach da thanh li");
					kt = false;
				}
				else
				{
					x.masach = ma_sach;
					k->data.trangthai = 1; // cập nhật sách đã mượn
					l.ds_dausach[i]->soluongmuon++; // tăng số lượng mượn cuốn sách
					kt = true;
				}

			}
		} while (kt == false);

	}
	p->data.tongsosach++;
	them_phieu_muon(x);
	them_vao_ds_muontra(p->data.mt, tao_node_muontra(x));
	return 1;
}

// trả sách thành công tr 1 <> -1 ; ESC rt -2
int trasach(TREE& t, LIST_DS& l)
{
	int tungdo = 0;
	xuat_ds_thong_tin_doc_gia(t, tungdo);
	tungdo = 0;
	int ma;
	cout << "\nNhap ma doc gia: ";
	ma = nhap_so_nguyen();
	xoa_hien_thi_doc_gia(t);
	if (ma == -1) // ESC
		return -2;
	TREE p = tim_kiem_docgia_ma(t, ma);
	if (p == NULL)
	{
		BaoLoi("Ma doc gia khong ton tai.");
		return -1;
	}
	else
	{
		TextColor(15);
		if (xuat_sach_dang_muon(p, l) == 0) // độc giả không có sách mượn
		{
			BaoLoi("Doc Gia Khong Co Sach Muon");
			return -1;
		}
		string ma_sach;
		TextColor(7);
		cout << "Nhap ma sach can tra: ";
		ma_sach = nhap_ki_tu1();
		if (ma_sach == "-1") // ESC
			return -2;

		NODE_DMS* k = tim_kiem_sach(l, ma_sach); // lưu vị trí của sách trả về trong danh sách qua mã sách
		if (k == NULL)
		{
			BaoLoi("Ma sach khong ton tai");
			return -1;
		}
		else
		{
			Date n1;
			for (NODE_MT* q = p->data.mt.pHead; q != NULL; q = q->pNext)
			{
				if (q->data.masach == ma_sach)
				{
					k->data.trangthai = 0;// cập nhật lại sách cho mượn được 
					q->data.trangthai = 1; // cập nhật lại đọc giả đã trả sách
					thoi_gian_thuc(n1); // lấy thời gian hệ thống
					q->data.ngaytra.ngay_hien_tai = n1.ngay_hien_tai;
					q->data.ngaytra.thang_hien_tai = n1.thang_hien_tai;
					q->data.ngaytra.nam_hien_tai = n1.nam_hien_tai;
				}
			}
		}
	}
	return 1;
}

// ========================================= Qua Han =============================

// hàm trả về số ngày quá hạn. Tính số ngày chênh lệch giữa 2 mốc thời gian
int so_ngay_quahan(Date n1, Date n2)
{
	int tong_ngay = 0;
	// tính số ngày theo độ chênh lệch giữa 2 năm
	while (n1.nam_hien_tai < n2.nam_hien_tai)
	{
		if (kt_namnhuan(n2.nam_hien_tai) == true) // là năm nhuận
		{
			tong_ngay += 366;
		}
		else
		{
			tong_ngay += 365;
		}
		n2.nam_hien_tai--;
	}
	// tính số ngày theo độ chênh lệch giữa 2 tháng
	while (n1.thang_hien_tai < n2.thang_hien_tai)
	{
		if (n1.thang_hien_tai == 4 || n1.thang_hien_tai == 6 || n1.thang_hien_tai == 9 || n1.thang_hien_tai == 11)
		{
			tong_ngay += 30;
		}
		else if (n1.thang_hien_tai == 2)
		{
			if (kt_namnhuan(n1.nam_hien_tai) == true)
			{
				tong_ngay += 29;
			}
			else
			{
				tong_ngay += 28;
			}
		}
		else
		{
			tong_ngay += 31;
		}
		n1.thang_hien_tai++;
		return (tong_ngay - n1.ngay_hien_tai) + n2.ngay_hien_tai;
	}
	// tính số ngày chênh lệch giữa 2 ngày cùng tháng cùng năm
	if (n1.ngay_hien_tai < n2.ngay_hien_tai)
	{
		return tong_ngay = n2.ngay_hien_tai - n1.ngay_hien_tai;
	}
	return 0;
}

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
					l.ds_quahan[n - 1].so_ngay_quahan = so_ngay_quahan(p->data.ngaymuon, n1);
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
			cout << "Ma doc gia";
			gotoXY(65, 0);
			cout << "Ho va ten";
			gotoXY(95, 0);
			cout << "Phai";
			gotoXY(100, 0);
			cout << "Ma sach";
			gotoXY(120, 0);
			cout << "So ngay qua han";
			gotoXY(45, k + 1);
			cout << l.ds_quahan[k].ma_doc_gia;
			gotoXY(65, k + 1);
			cout << l.ds_quahan[k].ho << " " << l.ds_quahan[k].ten;
			gotoXY(95, k + 1);
			cout << l.ds_quahan[k].phai;
			gotoXY(100, k + 1);
			cout << l.ds_quahan[k].ma_sach;
			gotoXY(120, k + 1);
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
	TextColor(15);
	for (int k = 0; k < l.sl && k < 10; k++)
	{
		xuat_dau_sach(*l.ds_dausach[k],k+1);
	}
	TextColor(7);
}
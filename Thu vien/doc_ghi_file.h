#pragma once
#include "xulyde.h"
void them_node_vao_cay(TREE& t, docgia x);
NODE_DMS* tao_node_sach(danhmucsach& x);
void them_sach_vao_ds(LIST_DMS& l, NODE_DMS* p);
void them_vao_ds_dausach(LIST_DS& l, dausach data);
void khoi_tao_sach(LIST_DMS& l);
int tim_kiem_dau_sach_theo_ma(LIST_DS l, string ma);
TREE tim_kiem_docgia_ma(TREE& t, int ma_doc_gia);
void khoi_tao_muontra(LIST_MT& l);
void them_vao_ds_muontra(LIST_MT& l, NODE_MT* p);
NODE_MT* tao_node_muontra(muontra x);
int SoluongDG(TREE t);
void chuyen_cay_sang_mang(TREE t, docgia* arr, int& i);


void GhiFileDG(TREE t)
{
	int n = SoluongDG(t);
	docgia *arr = new docgia[n];
	int index = 0;
	chuyen_cay_sang_mang(t, arr, index);
	for (int j = 0; j < n; j++)
	{
		int temp = rand() % (n-1) + 1;
		hoandoi(arr[j], arr[temp]);
	}
	ofstream fileout("DOCGIA.txt");
	fileout << n << endl;
	for (int i = 0; i < n; i++)
	{
		fileout << arr[i].mathe << ',';
		fileout << arr[i].ho << ',';
		fileout << arr[i].ten << ',';
		fileout << arr[i].phai << ',';
		fileout << arr[i].trangthaithe << endl;
		fileout << arr[i].tongsosach << endl;
		if (arr[i].tongsosach > 0)
		{
			for (NODE_MT* p = arr[i].mt.pHead; p != NULL; p = p->pNext)
			{
				if (p->data.trangthai == 0) // chỉ ghi sách đang mượn chưa trả
				{
					fileout << p->data.masach << ',';
					fileout << p->data.trangthai << ',';
					fileout << p->data.ngaymuon.ngay << '/';
					fileout << p->data.ngaymuon.thang << '/';
					fileout << p->data.ngaymuon.nam << ',';
					fileout << p->data.ngaytra.ngay << '/';
					fileout << p->data.ngaytra.thang << '/';
					fileout << p->data.ngaytra.nam << endl;
				}
			}
		}
	}
	delete[] arr;
	fileout.close();
}

void LoadtuFile_DSDG(TREE& t)
{
	ifstream f("DOCGIA.txt", ios::in);
	muontra x;
	docgia s;
	int n = 0;
	f >> n;
	for (int j = 0; j < n; j++)
	{
		f >> s.mathe;
		f.ignore();
		getline(f, s.ho, ',');
		getline(f, s.ten, ',');
		getline(f, s.phai, ',');
		f >> s.trangthaithe;
		f.ignore();
		f >> s.tongsosach;
		f.ignore();
		them_node_vao_cay(t, s);
		TREE p = tim_kiem_docgia_ma(t, s.mathe);
		khoi_tao_muontra(p->data.mt);
		for (int i = 0; i < s.tongsosach; i++)
		{
			getline(f, x.masach, ',');
			f >> x.trangthai;
			f.ignore();
			f >> x.ngaymuon.ngay;
			f.ignore();
			f >> x.ngaymuon.thang;
			f.ignore();
			f >> x.ngaymuon.nam;
			f.ignore();
			f >> x.ngaytra.ngay;
			f.ignore();
			f >> x.ngaytra.thang;
			f.ignore();
			f >> x.ngaytra.nam;
			f.ignore();
			them_vao_ds_muontra(p->data.mt, tao_node_muontra(x));
		}
	}
	f.close();
}

void GhiFileDS(LIST_DS l)
{
	ofstream f("DAUSACH.txt");
	f << l.sl << endl;
	for (int i = 0; i < l.sl; i++)
	{
		f << l.ds_dausach[i]->ISBN << ',';
		f << l.ds_dausach[i]->tensach << ',';
		f << l.ds_dausach[i]->sotrang << ',';
		f << l.ds_dausach[i]->tacgia << ',';
		f << l.ds_dausach[i]->namxuatban << ',';
		f << l.ds_dausach[i]->theloai << ',';
		f << l.ds_dausach[i]->soluongmuon << endl;
		f << l.ds_dausach[i]->soluongsach << endl;
		if (l.ds_dausach[i]->soluongsach > 0)
		{
			for (NODE_DMS* p = l.ds_dausach[i]->dms.pHead; p != NULL; p = p->pNext)
			{
				f << p->data.masach << ',';
				f << p->data.trangthai << ',';
				f << p->data.vitri << endl;
			}
		}
	}
	f.close();
}

void LoadFileDS(LIST_DS& l)
{
	dausach data;
	danhmucsach x;
	ifstream f("DAUSACH.txt");
	int n;
	f >> n;
	f.ignore();
	for (int i = 0; i < n; i++)
	{
		getline(f, data.ISBN, ',');
		getline(f, data.tensach, ',');
		f >> data.sotrang;
		f.ignore();
		getline(f, data.tacgia, ',');
		f >> data.namxuatban;
		f.ignore();
		getline(f, data.theloai,',');
		f >> data.soluongmuon;
		f.ignore();
		f >> data.soluongsach;
		f.ignore();
		them_vao_ds_dausach(l, data);
		int vitri = tim_kiem_dau_sach_theo_ma(l, data.ISBN);
		khoi_tao_sach(l.ds_dausach[vitri]->dms);
		for (int i = 0; i < data.soluongsach; i++)
		{
			getline(f, x.masach, ',');
			f >> x.trangthai;
			f.ignore();
			getline(f, x.vitri);
			them_sach_vao_ds(l.ds_dausach[vitri]->dms, tao_node_sach(x));
		}
	}
	f.close();
}

void Ghi_file_quahan(TREE t,List_quahan l)
{
	int n = 0;
	TREE Stack[STACKSIZE];
	int top = -1;
	Date n1;
	thoi_gian_thuc(n1);
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
			if (t->data.tongsosach > 0)
			{
				for (NODE_MT* p = t->data.mt.pHead; p != NULL; p = p->pNext)
				{
					n++;
					l.ds_quahan[n - 1].ma_doc_gia = t->data.mathe;
					if (p->data.trangthai == 0) // đang mượn
						l.ds_quahan[n - 1].so_ngay_quahan = tinh_so_ngay(p->data.ngaymuon);
					else
					l.ds_quahan[n - 1].so_ngay_quahan = 0;
					l.ds_quahan[n - 1].ma_sach = p->data.masach;
					l.ds_quahan[n - 1].ho = t->data.ho;
					l.ds_quahan[n - 1].ten = t->data.ten;
					l.ds_quahan[n - 1].phai = t->data.phai;
				}
			}
			t = t->pRight;
		}
		else
			break;
	} while (1);
	l.sl = n;
	ofstream fileout("QUAHAN.txt", ios::out);
	fileout << l.sl << endl;
	for (int i = 0; i < l.sl; i++)
	{
		fileout << l.ds_quahan[i].ma_doc_gia << ',';
		fileout << l.ds_quahan[i].ho << ',';
		fileout << l.ds_quahan[i].ten << ',';
		fileout << l.ds_quahan[i].phai << ',';
		fileout << l.ds_quahan[i].ma_sach << ',';
		fileout << l.ds_quahan[i].so_ngay_quahan << endl;
	}
	fileout.close();
}

void Load_file_quahan(List_quahan& l)
{
	ifstream filein("QUAHAN.txt", ios::in);
	filein >> l.sl;
	filein.ignore();
	for (int i = 0; i < l.sl; i++)
	{
		filein >> l.ds_quahan[i].ma_doc_gia;
		filein.ignore();
		getline(filein, l.ds_quahan[i].ho, ',');
		getline(filein, l.ds_quahan[i].ten, ',');
		getline(filein, l.ds_quahan[i].phai, ',');
		getline(filein, l.ds_quahan[i].ma_sach,',');
		filein >> l.ds_quahan[i].so_ngay_quahan;
		filein.ignore();
	}
	filein.close();
}
#pragma once
#include "xulyde.h"
void Add_DG_VAO_CAY(TREE& t, docgia x);
NODE_DMS* TAO_NODE_SACH(danhmucsach& x);
void AddTail_DMS(LIST_DMS& l, NODE_DMS* p);
void ADDTail_DS(LIST_DS& l, dausach data);
void Init_DMS(LIST_DMS& l);
int TIM_KIEM_DS_THEO_MA(LIST_DS l, string ma);
TREE TIM_KIEM_DG_MA(TREE& t, int ma_doc_gia);
void Init_MT(LIST_MT& l);
void AddTail_MT(LIST_MT& l, NODE_MT* p);
NODE_MT* TAO_NODE_MT(muontra x);
int SoluongDG(TREE t);
void CAY_SANG_MANG(TREE t, docgia* arr, int& i);

void Ghifile_1_DG(TREE q,ofstream& fileout)
{
	if (q)
	{
		fileout << q->data.mathe << ',';
		fileout << q->data.ho << ',';
		fileout << q->data.ten << ',';
		fileout << q->data.phai << ',';
		fileout << q->data.trangthaithe << endl;
		fileout << q->data.tongsosach << endl;
		if (q->data.tongsosach > 0)
		{
			for (NODE_MT* p = q->data.mt.pHead; p != NULL; p = p->pNext)
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
		Ghifile_1_DG(q->pLeft,fileout);
		Ghifile_1_DG(q->pRight, fileout);
	}
}
void GHI_FILE_DS_DG(TREE t)
{
	ofstream fileout("DOCGIA.txt");
	int n = SoluongDG(t);
	fileout << n << endl;
	Ghifile_1_DG(t, fileout);
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
		Add_DG_VAO_CAY(t, s);
		TREE p = TIM_KIEM_DG_MA(t, s.mathe);
		Init_MT(p->data.mt);
		for (int i = 0; i < s.tongsosach; i++)
		{
			getline(f, x.masach, ',');
			f >> x.trangthai;      f.ignore();
			f >> x.ngaymuon.ngay;  f.ignore();
			f >> x.ngaymuon.thang; f.ignore();
			f >> x.ngaymuon.nam;   f.ignore();
			f >> x.ngaytra.ngay;   f.ignore();
			f >> x.ngaytra.thang;  f.ignore();
			f >> x.ngaytra.nam;    f.ignore();
			AddTail_MT(p->data.mt, TAO_NODE_MT(x));
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
		ADDTail_DS(l, data);
		int vitri = TIM_KIEM_DS_THEO_MA(l, data.ISBN);
		Init_DMS(l.ds_dausach[vitri]->dms);
		for (int i = 0; i < data.soluongsach; i++)
		{
			getline(f, x.masach, ',');
			f >> x.trangthai;
			f.ignore();
			getline(f, x.vitri);
			AddTail_DMS(l.ds_dausach[vitri]->dms, TAO_NODE_SACH(x));
		}
	}
	f.close();
}


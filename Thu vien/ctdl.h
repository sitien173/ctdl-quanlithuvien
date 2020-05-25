#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <conio.h>
#include <fstream>
#include <ctime>
using namespace std;
#define MAX 100
#define MAX_DG 1000 // mã thẻ ngẫu nhiên từ 1->1000
#define MAX_MASACH 1000 // tạo mã sách ngẫu nhiên 1->1000
const int STACKSIZE = 100; 
//==============danh muc sach================
struct danhmucsach {
	string masach;
	int trangthai; // =0 cho mượn được =1 đã có độc giả mượn =2 sách đã thanh lí
	string vitri;
};
struct node_danhmucsach
{
	danhmucsach data;
	node_danhmucsach* pNext;
};
typedef struct node_danhmucsach NODE_DMS;
struct list_danhmucsach
{
	NODE_DMS* pHead;
	NODE_DMS* pTail;
};
typedef struct list_danhmucsach LIST_DMS;

// =================Dau sach===================
struct dausach
{
	string ISBN; // mã sách theo chuẩn quốc tế
	string tensach;
	int sotrang;
	string tacgia;
	int namxuatban;
	string theloai;
	int soluongsach;
	int soluongmuon; // biến lưu trữ số lần mượn sách của độc giả
	LIST_DMS dms; // con trỏ trỏ đến các sách thuộc đầu sách tương ứng
};
struct list_dausach
{
	
	int sl;
	dausach* ds_dausach[MAX];
};
typedef struct list_dausach LIST_DS;
//==================Muon tra======================
struct Date
{
	int ngay_hien_tai;
	int thang_hien_tai;
	int nam_hien_tai;
};
struct muontra
{
	string masach;
	Date ngaymuon;
	Date ngaytra;
	int trangthai; // =0 đang mượn =1 đã trả =2 làm mất sách
};
struct node_muontra
{
	muontra data;
	node_muontra* pNext;
	node_muontra* pPrev;
};
typedef struct node_muontra NODE_MT;
struct list_muontra
{
	NODE_MT* pHead;
	NODE_MT* pTail;
};
typedef struct list_muontra LIST_MT;
//======================= The Doc Gia=============
struct docgia
{
	int mathe;
	string ho;
	string ten;
	string phai;
	int trangthaithe;
	int tongsosach;
	LIST_MT mt; // con trỏ sẽ trỏ đến danh sách các cuốn đã và đang mượn
};
struct node_docgia
{
	docgia data;
	node_docgia* pLeft;
	node_docgia* pRight;
};
typedef struct node_docgia NODE_DG;
typedef struct node_docgia* TREE;
//================== qua han===============
struct quahan
{
	int ma_doc_gia;
	string ho;
	string ten;
	string phai;
	string ma_sach;
	int so_ngay_quahan;
	
};
struct List_quahan
{
	quahan ds_quahan[100];
	int sl=0 ; // số lượng thực tế độc giả có trong danh sách quá hạn
};
typedef struct List_quahan LIST_QUAHAN;


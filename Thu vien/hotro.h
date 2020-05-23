#pragma once
#include "ctdl.h"
#include "lib.h"

TREE tim_kiem_docgia_ma(TREE& t, int ma_doc_gia);
void sap_xep_theo_theloai_dausach(LIST_DS& l);
int SoluongDG(TREE t);


void BaoLoi(string s) {
	TextColor(15);
	int n = s.length();
	int x = whereX(), y = whereY();
	gotoXY(3, 35);
	cout << s;
	Sleep(1000);
	for (int i = 0; i < n; i++)
	{
		gotoXY(3 + i, 35);
		cout << "    ";
	}
	gotoXY(x, y);
	TextColor(7);
}
void Button(int tungdo)
{
	gotoXY(50, tungdo + 3); TextColor(76); cout << "        ";
	gotoXY(50, tungdo + 4); TextColor(78); cout << "  CHON  ";
	gotoXY(50, tungdo + 5); TextColor(76); cout << "        ";
	gotoXY(50, tungdo + 6); TextColor(79); cout << "  Enter ";

	gotoXY(70, tungdo + 3); TextColor(76); cout << "        ";
	gotoXY(70, tungdo + 4); TextColor(78); cout << "  SUA   ";
	gotoXY(70, tungdo + 5); TextColor(76); cout << "        ";
	gotoXY(70, tungdo + 6); TextColor(79); cout << "   F3   ";

	gotoXY(90, tungdo + 3); TextColor(76); cout << "        ";
	gotoXY(90, tungdo + 4); TextColor(78); cout << "  TIM   ";
	gotoXY(90, tungdo + 5); TextColor(76); cout << "        ";
	gotoXY(90, tungdo + 6); TextColor(79); cout << "   F4   ";

	gotoXY(110, tungdo + 3); TextColor(76); cout << "        ";
	gotoXY(110, tungdo + 4); TextColor(78); cout << "  THEM  ";
	gotoXY(110, tungdo + 5); TextColor(76); cout << "        ";
	gotoXY(110, tungdo + 6); TextColor(79); cout << "   F1   ";

	gotoXY(130, tungdo + 3); TextColor(76); cout << "        ";
	gotoXY(130, tungdo + 4); TextColor(78); cout << "  XOA   ";
	gotoXY(130, tungdo + 5); TextColor(76); cout << "        ";
	gotoXY(130, tungdo + 6); TextColor(79); cout << "   F2   ";

	gotoXY(150, tungdo + 3); TextColor(76); cout << "        ";
	gotoXY(150, tungdo + 4); TextColor(78); cout << "  THOAT ";
	gotoXY(150, tungdo + 5); TextColor(76); cout << "        ";
	gotoXY(150, tungdo + 6); TextColor(79); cout << "   ESC  ";
	gotoXY(0,0);
	TextColor(7);
}

// ham chuyen doi so sang chuoi 
string so_sang_chuoi(int number)
{
	return to_string(number);
}

// ham chuyen doi chuỗi sang số nếu chuyển hết rt giá trị <> -1
int chuoi_sang_so(string x)
{
	string temp = x;
	for (int i = 0; i < temp.length(); i++)
	{
		// chuyển chữ hoa về chữ thường
		if (temp[0] >= 65 && temp[0] <= 90)
		{
			temp[i] += 32;
		}
	}
	int n = temp.length(); // chieu dai cua string
	int num = 0; //bien num dung de luu cac gia tri sau khi tach chuoi
	int temp1 = 0; // dùng để kiểm tra chuyển hết chuỗi có về hết số được ko
	for (int i = n - 1; i >= 0; --i)
	{
		if (temp[i] >= '0' && temp[i] <= '9') // neu tung phan tu la 0->9 thi xet tiep
		{
			temp1++;
			num += (int)(temp[i] - '0') * pow(10, n - 1 - i);
		}
	}
	if (temp1 == n) // chuoi chuyen ve so duoc het
		return num;
	else // chuoi chuyen khong het
		return -1;
}

// hàm kiểm tra dữ liệu của chuỗi nhập vào phải là các kí tự số hoặc kí tự chữ cái đsung true <> false
bool Kiem_Tra_Du_Lieu(char c)
{
	if ((c >= 48 && c <= 57) || c == 8) // nếu là số thì rt true <> false;
	{
		return true;
	}
	return false;
}

int nhap_so_nguyen() // Hàm nhập dữ liệu toàn số .
{
	// nếu nhập kí tự enter thì chuỗi hiểu đó là kí tự kết thúc chuỗi <=> length = 0, ko tính là 1 kí tự
	string str;
	bool KT;
	int length = 0; // biến cho con trỏ dịch đến cuối
	char c;
	do
	{
	Nhap:	c = _getch();
		while (c == 13)
		{
			BaoLoi("Khong duoc de trong");
			c = _getch();
		}
		while (int(c) != 13)
		{
			if (c == 27)
			{
				return -1;
			}
			if (Kiem_Tra_Du_Lieu(c) == false) // nếu nhập kí tự là chữ
			{
				BaoLoi("Chi duoc nhap so");
				c = _getch();
				continue;
			}
			if (int(c) == 8) // nếu ấn phím Backspace thì xóa 1 kí tự ở cuối
			{

				if (length > 0) // nếu như độ dài biến con trỏ dịch bằng 0 thì ko cho xóa tiếp
				{
					cout << "\b \b"; // khi bấm phím Backspace thì sẽ xóa từng kí tự của chuỗi kí tự hiện tại
					length--;
				}
				if (str.length() != 0) // xóa kí tự cuối trong chuỗi string 
				{
					str.erase(str.begin() + (str.length() - 1));
				}
			}
			else
			{
				cout << c;
				length++; // cập nhật vụ trí con trỏ chỉ vị
				str.push_back(c);
			}

			c = _getch();
		}
		while (str.length() == 0)
		{
			BaoLoi("Khong duoc de trong");
			goto Nhap;
		}
		KT = true;
	} while (KT == false);
	cout << endl;
	return atoi(str.c_str());
}

void chuan_hoa_chu(string& str)
{
	// xử lí khoảng trắng đầu

	while (str[0] == ' ')
	{
		str.erase(str.begin() + 0);
	}
	// xử lí khoảng trắng cuối
	while (str[str.length() - 1] == ' ')
	{
		str.erase(str.begin() + str.length() - 1);
	}
	// xử lí khoảng trắng giữa
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ' && str[i + 1] == ' ')
		{
			str.erase(str.begin() + i);
			i--;
		}
	}
	// chuan hóa kí tự chữ cái đầu viết hoa sau 
	if (str[0] >= 97 && str[0] <= 122)
	{
		str[0] -= 32;
	}
	for (int i = 1; i < str.length(); i++)
	{
		if (str[i] == ' ')
		{
			i++;
			if (str[i] >= 97 && str[i] <= 122)
			{
				str[i] -= 32;
			}
		}
		else
		{
			if (str[i] >= 65 && str[i] <= 90)
			{
				str[i] += 32;
			}
		}
	}
}

// ========================tạo mã độc giả không trùng================
int tao_ma_doc_gia(TREE t)
{
	int ma;
	TREE kt;
	do
	{
		ma = rand() % MAX_DG + 1;
		kt = tim_kiem_docgia_ma(t, ma);
	} while (kt != NULL);
	return ma;
}

bool kiem_tra_ma_sach(LIST_DMS& l, string ma)
{
	node_danhmucsach* p = l.pHead;
	while (p != NULL)
	{
		if (p->data.masach == ma)
			return true;
		p = p->pNext;
	}
	return false;
}

string tao_masach(LIST_DMS& l, string ma_dau_sach)
{
	string str = ma_dau_sach + "-";
	do
	{
		int ma = rand() % MAX_MASACH + 1;
		str += so_sang_chuoi(ma);
	} while (kiem_tra_ma_sach(l, str) != false);
	return str;
}

// =============================== giải phóng==================
void giaiphong_cay(TREE& t)
{
	if (t != NULL)
	{

		NODE_MT* p = t->data.mt.pHead;
		NODE_MT* q = NULL;
		while (p != NULL)
		{
			t->data.mt.pHead = p->pNext;
			if (p != t->data.mt.pTail)
			{
				p = p->pNext;
				q = p->pPrev;
				delete q;
			}
			else // p là node cuối mt
			{
				delete p;
				break;
			}
		}
		t->data.mt.pTail = NULL;
		giaiphong_cay(t->pRight);
		giaiphong_cay(t->pLeft);
		delete t;
		t = NULL;
	}
}
void giai_phong_vung_nho_dau_sach(LIST_DS& l)
{
	for (int i = 0; i < l.sl; i++)
	{
		NODE_DMS* p;
		while (l.ds_dausach[i]->dms.pHead != NULL)
		{
			p = l.ds_dausach[i]->dms.pHead;
			l.ds_dausach[i]->dms.pHead = p->pNext;
			l.ds_dausach[i]->dms.pHead = l.ds_dausach[i]->dms.pHead->pNext;
			delete p;
		}
		l.ds_dausach[i]->dms.pTail = NULL;
		delete l.ds_dausach[l.sl - 1];
		l.sl--;
	}
}


// kiểm tra 1 chuỗi có kí tự nào là số không nếu có trả về true <> false
bool Kiem_Tra_Ki_Tu_So(char c)
{
	if (c >= '0' && c <= '9')
		return true;
	return false;
}

// Hàm nhập dữ liệu toàn kí tự . VD: họ, tên, giới tính. Kí tự bắt đầu phải là kí tự 
string nhap_ki_tu()
{
	// nếu nhập kí tự enter thì chuỗi hiểu đó là kí tự kết thúc chuỗi <=> length = 0, ko tính là 1 kí tự
	string str;
	bool KT;
	int length = 0; // biến cho con trỏ dịch đến cuối
	char c;
	do
	{
	Nhap:		c = _getch();
		while (c == 13)
		{
			BaoLoi("Khong duoc de trong");
			c = _getch();
		}
		while (int(c) != 13)
		{
			if (c == 27)
			{
				return "-1";
			}
			if (Kiem_Tra_Ki_Tu_So(c) == true) // nếu nhập kí tự là số
			{
				BaoLoi("Khong duoc nhap so");
				c = _getch();
				continue;
			}
			if (int(c) == 8) // nếu ấn phím Backspace thì xóa 1 kí tự ở cuối
			{

				if (length > 0) // nếu như độ dài biến con trỏ dịch bằng 0 thì ko cho xóa tiếp
				{
					cout << "\b \b"; // khi bấm phím Backspace thì sẽ xóa từng kí tự của chuỗi kí tự hiện tại
					length--;
				}
				if (str.length() != 0) // xóa kí tự cuối trong chuỗi string 
				{
					str.erase(str.begin() + (str.length() - 1));
				}
			}
			else
			{
				cout << c;
				length++; // cập nhật vụ trí con trỏ chỉ vị
				str.push_back(c);
			}

			c = _getch();
		}
		while (str.length() == 0)
		{
			BaoLoi("Khong duoc de trong");
			goto Nhap;
		}
		KT = true;
	} while (KT == false);
	cout << endl;
	chuan_hoa_chu(str);
	return str;
}

// Hàm nhập dữ liệu kí tự và số dưới dạng kí tự.
string nhap_ki_tu1()
{
	// nếu nhập kí tự enter thì chuỗi hiểu đó là kí tự kết thúc chuỗi <=> length = 0, ko tính là 1 kí tự
	string str;
	bool KT;
	int length = 0; // biến cho con trỏ dịch đến cuối
	char c;
	do
	{
	Nhap1:	c = _getch();
		while (c == 13)
		{
			BaoLoi("Khong duoc de trong");
			c = _getch();
		}
		while (int(c) != 13)
		{
			if (c == 27)
			{
				return "-1";
			}
			if (int(c) == 8) // nếu ấn phím Backspace thì xóa 1 kí tự ở cuối
			{

				if (length > 0) // nếu như độ dài biến con trỏ dịch bằng 0 thì ko cho xóa tiếp
				{
					cout << "\b \b"; // khi bấm phím Backspace thì sẽ xóa từng kí tự của chuỗi kí tự hiện tại
					length--;
				}
				if (str.length() != 0) // xóa kí tự cuối trong chuỗi string 
				{
					str.erase(str.begin() + (str.length() - 1));
				}
			}
			else
			{
				cout << c;
				length++; // cập nhật vụ trí con trỏ chỉ vị
				str.push_back(c);
			}

			c = _getch();
		}
		while (str.length() == 0)
		{
			BaoLoi("Khong duoc de trong");
			goto Nhap1;
		}
		KT = true;
	} while (KT == false);
	cout << endl;
	chuan_hoa_chu(str);
	return str;
}

// ham co chuc nang cap nhat lai sach
void cap_nhat_sach(TREE& t, LIST_DS& l)
{
	if (t != NULL)
	{
		for (NODE_MT* p = t->data.mt.pHead; p != NULL; p = p->pNext)
		{
			for (int i = 0; i < l.sl; i++)
			{
				for (NODE_DMS* k = l.ds_dausach[i]->dms.pHead; k != NULL; k = k->pNext)
				{
					if (p->data.masach == k->data.masach)
					{
						if (p->data.trangthai == 1) // sách đã trả
						{
							k->data.trangthai = 0;
						}
						else if (p->data.trangthai == 0) // sách độc giả đang mượn
						{
							k->data.trangthai = 1; // cập nhật lại sách đã có người mượn
						}
						else if (p->data.trangthai == 2) // sách đã bị mất
						{
							k->data.trangthai = 2; // cập nhật lại sách đã thanh lí
						}
					}
				}
			}
		}
		cap_nhat_sach(t->pLeft, l);
		cap_nhat_sach(t->pRight, l);
	}

}

// hoán đổi vị trí 2 độc giả
void hoandoi(docgia& a, docgia& b)
{
	docgia temp = a;
	a = b;
	b = temp;
}

// lấy thời gian thực hệ thống
void thoi_gian_thuc(Date& x)
{
	time_t t = time(NULL);
	tm* now = localtime(&t);
	x.ngay_hien_tai = now->tm_mday;
	x.thang_hien_tai = now->tm_mon + 1;
	x.nam_hien_tai = now->tm_year + 1900;
}

// kiem tra nam nhuan
bool kt_namnhuan(int nam)
{
	if (nam % 4 == 0 && nam % 100 != 0 || nam % 400 == 0)
	{
		return true;
	}
	return false;
}

void xoa_hien_thi_doc_gia(TREE t)
{
	int x = whereX();
	int y = whereY();
	int n = SoluongDG(t);
	for (int i = 0; i <= n; i++)
	{
		gotoXY(45, i);
		cout << "                     ";
		gotoXY(65, i);
		cout << "                     ";
		gotoXY(90, i);
		cout << "                     ";
		gotoXY(100, i);
		cout << "                     ";
	}
	gotoXY(x, y);
}
void xoa_hien_thi_dausach(LIST_DS l)
{
	int x = whereX();
	int y = whereY();
	for (int i = 0; i <= l.sl; i++)
	{
		int x = whereX();
		int y = whereY();
		gotoXY(40, i);
		cout << "					    ";
		gotoXY(55, i);
		cout << "				       ";
		gotoXY(95, i);
		cout << "                      ";
		gotoXY(105, i);
		cout << "						";
		gotoXY(145, i);
		cout << "						";
		gotoXY(155, i);
		cout << "						";
	}
	gotoXY(x, y);
}
void xoa_hien_thi_sach(LIST_DS l)
{
	int x = whereX();
	int y = whereY();
	int tungdo = 1;
	for (int i = 0; i < l.sl; i++)
	{
		for (NODE_DMS* p = l.ds_dausach[i]->dms.pHead; p != NULL; p = p->pNext)
		{
			gotoXY(45, tungdo);
			cout << "                                  ";
			gotoXY(65, tungdo);
			cout << "                                   ";
			gotoXY(95, tungdo);
			cout << "                                   ";
			gotoXY(110, tungdo);
			cout << "                                    ";
			tungdo++;
		}
	}
	gotoXY(x, y);
}
void xoa_hien_thi_botton(int tungdo)
{
	int x = whereX();
	int y = whereY();
	gotoXY(50, tungdo + 3);  cout << "        ";
	gotoXY(50, tungdo + 4);  cout << "        ";
	gotoXY(50, tungdo + 5);  cout << "        ";
	gotoXY(50, tungdo + 6);  cout << "        ";

	gotoXY(70, tungdo + 3);  cout << "        ";
	gotoXY(70, tungdo + 4);  cout << "        ";
	gotoXY(70, tungdo + 5);  cout << "        ";
	gotoXY(70, tungdo + 6);  cout << "        ";

	gotoXY(90, tungdo + 3);  cout << "        ";
	gotoXY(90, tungdo + 4);  cout << "        ";
	gotoXY(90, tungdo + 5);  cout << "        ";
	gotoXY(90, tungdo + 6);  cout << "        ";

	gotoXY(110, tungdo + 3);  cout << "        ";
	gotoXY(110, tungdo + 4);  cout << "        ";
	gotoXY(110, tungdo + 5);  cout << "        ";
	gotoXY(110, tungdo + 6);  cout << "        ";

	gotoXY(130, tungdo + 3);  cout << "        ";
	gotoXY(130, tungdo + 4);  cout << "        ";
	gotoXY(130, tungdo + 5);  cout << "        ";
	gotoXY(130, tungdo + 6);  cout << "        ";

	gotoXY(150, tungdo + 3);  cout << "        ";
	gotoXY(150, tungdo + 4);  cout << "        ";
	gotoXY(150, tungdo + 5);  cout << "        ";
	gotoXY(150, tungdo + 6);  cout << "        ";
	gotoXY(x, y);
	TextColor(7);
}
void ve_khung()
{
	TextColor(7);
	for (int i = 0; i < 168; i++)
	{
		if (i < 40)
		{
			gotoXY(40, i);
			cout << char(176);
			gotoXY(i, 10);
			cout << char(205);
			gotoXY(167, i);
			cout << char(176);
		}
		gotoXY(i, 40);
		cout << char(205);
	}
}

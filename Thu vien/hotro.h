#pragma once
#include "ctdl.h"
#include "lib.h"
#include "hienthi.h"

TREE TIM_KIEM_DG_MA(TREE& t, int ma_doc_gia);
void SX_THELOAI_DS(LIST_DS& l);
int SoluongDG(TREE t);
int Kiem_tra_phim(char c);
int tinh_so_ngay(Date n1);
int TIM_KIEM_DS_THEO_MA(LIST_DS l, string ma);
void control_cursor(bool x);

enum TRANGTHAI { UP, DOWN, LEFT, RIGHT, ENTER, ESC };
// hàm có chức năng bắt phim vừa nhập để điều khiển menu
TRANGTHAI key(char c)
{
	if (c == -32)
		c = _getch();

	if (c == 72)
		return UP;
	if (c == 80)
		return DOWN;
	if (c == 77)
		return RIGHT;
	if (c == 75)
		return LEFT;
	if (c == 27)
		return ESC;
	if (c == 13)
		return ENTER;
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

// tách mã sách chỉ lấy mã đầu sách
string tach_ma_sach(string a)
{
	string temp;
	int n = a.length();
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == '-')
			dem = i;
	}
	temp = a.substr(0, dem);

	return temp;
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
	int n = atoi(temp.c_str());
	if (n != 0)
		return n;
	return -1;
}

// ************************NHAP***************************
// hàm kiểm tra dữ liệu của chuỗi nhập vào phải là các kí tự số hoặc kí tự chữ cái đsung true <> false
bool Kiem_Tra_Du_Lieu(char c)
{
	if ((c >= 48 && c <= 57) || c == 8) // nếu là số thì rt true <> false;
	{
		return true;
	}
	return false;
}
bool Kiem_Tra_Ki_Tu_So(char c)
{
	if (c >= '0' && c <= '9')
		return true;
	return false;
}
// ki tu so rt 2 <> ky tu dac biet rt 1 <> 0
int Kiem_tra_phim(char c)
{
	int arr[23] = { 44,46,47,39,59,91,93,92,61,33,64,35,36,37,94,38,40,42,41,95,96,126,9 };
	if (Kiem_Tra_Ki_Tu_So(c) == true) // so
		return 2;
	for (int i = 0; i < 23; i++)
		if (c == arr[i])
			return 1;

	return 0;
}
// Nhập số nguyên chỉ nhận 0 và 1 <> ESC RT -1
int nhap_so_nguyen1(int& n) {
	string str = so_sang_chuoi(n);
	int length = str.length();
	bool kt = false;
	char c;
	control_cursor(true);
	do
	{
		c = _getch();
		while (int(c) != 13)
		{
			if (c == 0 || c == -32)
			{
				BaoLoi("PHIM NHAP KHONG HOP LE");
				break;
			}
			if (c == 27)
			{
				control_cursor(false);
				return -1;
			}
			if (Kiem_Tra_Du_Lieu(c) == false) // nếu nhập kí tự là chữ
			{
				BaoLoi("CHI DUOC NHAP SO");
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
				TextColor(15);
				str.push_back(c);
				cout << c;
				length++;
			}
			c = _getch();
		}
		if (c == 13)
		{
			int dem = 1;
			int dem1 = 0;
			for (int i = 0; i < length; i++)
			{
				if ((int)str[i] == 32)
					dem++;
				else
					dem1++;
			}
			if (length == 0 || (dem >= 2 && dem1 == 0))
			{
				BaoLoi("KHONG DUOC DE TRONG");
				continue;
			}
			int i = atoi(str.c_str());
			if (i == 0 || i == 1)
			{
				kt = true;
				n = i;
			}
			else
			{
				BaoLoi("TRANG THAI CHI NHAN 1 HOAC 0");
				while (length > 0)
				{
					cout << "\b \b";
					str.pop_back();
					length--;
				}
			}

		}
	} while (kt == false);
	control_cursor(false);
}
int nhap_so_nguyen(int& n) // Hàm nhập dữ liệu toàn số .
{
	control_cursor(true);
	string str = "";
	str = so_sang_chuoi(n);
	// nếu nhập kí tự enter thì chuỗi hiểu đó là kí tự kết thúc chuỗi <=> length = 0, ko tính là 1 kí tự
	bool KT = false;

	if (str == "0") str = "";
	int length = str.length(); // biến cho con trỏ dịch đến cuối
	char c;
	do
	{
		c = _getch();
		while (int(c) != 13)
		{
			if (c == 0 || c == -32)
			{
				BaoLoi("PHIM NHAP KHONG HOP LE");
				break;
			}
			if (c == 27)
			{
				control_cursor(false);
				return -1;
			}
			if (Kiem_Tra_Du_Lieu(c) == false) // nếu nhập kí tự là chữ
			{
				BaoLoi("CHI DUOC NHAP SO");
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
				TextColor(15);
				str.push_back(c);
				cout << c;
				length++;

			}
			c = _getch();
		}
		if (c == 13)
		{
			int dem = 1;
			int dem1 = 0;
			for (int i = 0; i < length; i++)
			{
				if ((int)str[i] == 32)
					dem++;
				else
					dem1++;
			}
			if (length == 0 || (dem >= 2 && dem1 == 0))
			{
				BaoLoi("KHONG DUOC DE TRONG");
				KT = false;
			}
			else
			{
				if (chuoi_sang_so(str) <= 0)
				{
					BaoLoi("SO NHAP VAO PHAI LON > 0");
					continue;
				}
				chuan_hoa_chu(str);
				KT = true;
			}
		}
	} while (KT == false);
	cout << endl;
	n = atoi(str.c_str()); // chuyen doi chuoi sang so
	control_cursor(false);
}
//flag =0 nhap toan ki tu, flag=1 nhap ki tu va so, flag =2 nhap gioitinh,flag=3 nhap ki tu la so
int nhap_ki_tu(string& str, int flag)
{
	control_cursor(true);
	// nếu nhập kí tự enter thì chuỗi hiểu đó là kí tự kết thúc chuỗi <=> length = 0, ko tính là 1 kí tự
	bool KT = false;;
	int length = str.length(); // biến cho con trỏ dịch đến cuối
	char c;
	do
	{
		c = _getch();
		while (int(c) != 13)
		{
			if (c == 0 || c == -32)
			{
				BaoLoi("PHIM NHAP KHONG HOP LE");
				break;
			}
			if (c == 27)
			{
				control_cursor(false);
				return -1;
			}
			int k = Kiem_tra_phim(c);
			if (k == 1) // phím chức năng
			{
				BaoLoi("PHIM NHAP KHONG HOP LE");
				break;
			}
			if (flag == 3)
			{
				if (Kiem_Tra_Du_Lieu(c) == false) // nếu nhập kí tự là chữ
				{
					BaoLoi("CHI DUOC NHAP SO");
					break;
				}
			}
			if (k == 2 && (flag == 0 || flag == 2)) // nếu nhập kí tự là số
			{
				BaoLoi("KHONG DUOC NHAP SO");
				break;
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
				TextColor(15);
				str.push_back(c);
				if (Kiem_Tra_Ki_Tu_So(c) == true) // nếu số in ra
					cout << c;
				else if (length == 0) { // là chữ
					c = c - 32;
					cout << c;
				}
				else if (str[length - 1] == 32) // trước nó là khoảng cách
				{
					c = c - 32;
					cout << c;
				}
				else cout << c;
				length++;
			}
			break;
		}
		if (c == 13)
		{
			int dem = 1;
			int dem1 = 0;
			for (int i = 0; i < length; i++)
			{
				if ((int)str[i] == 32)
					dem++;
				else
					dem1++;
			}
			if (length == 0 || (dem >= 2 && dem1 == 0))
			{
				BaoLoi("KHONG DUOC DE TRONG");
				KT = false;
			}
			else if (flag == 0 || flag == 1)
				KT = true;
			else if (flag == 2)// flag=2 nhap gioi tinh
			{
				if (dem1 != 0)
				{
					chuan_hoa_chu(str);
					if (str == "Nam" || str == "Nu")
						KT = true;
					else
					{
						BaoLoi("GIOI TINH CHI NAM HOAC NU");
						while (length > 0)
						{
							cout << "\b \b";
							str.pop_back();
							length--;
						}
						KT = false;
					}
				}
			}
			else
				KT = true;

		}
	} while (KT == false);
	cout << endl;
	chuan_hoa_chu(str);
	control_cursor(false);
}


// ========================ĐỘC GIẢ================
// tạo 100000 mã độc giả 
void tao_ma_doc_gia()
{
	int* arr = new int[MAX_MATHE + 1];
	int i;
	int j = 0;
	for (i = 1; i < MAX_MATHE + 1; i++)
		arr[i] = i;
	for (i = 1; i < MAX_MATHE + 1; i++)
	{
		j = rand() % MAX_MATHE + i;
		swap(arr[i], arr[j]);
	}
	ofstream fileout("MADOCGIA.txt");
	for (i = 1; i < MAX_MATHE + 1; i++)
		fileout << arr[i] << endl;

	delete[] arr;
	fileout.close();
}
// duyệt cây copy dữ liệu vào mảng
// duyệt cây copy dữ liệu vào mảng
void CHUYEN_CAY_SANG_MANG(TREE t, docgia* arr, int& i)
{
	if (t != NULL)
	{
		CHUYEN_CAY_SANG_MANG(t->pLeft, arr, i);
		arr[i++] = t->data;
		CHUYEN_CAY_SANG_MANG(t->pRight, arr, i);
	}// nếu cây rỗng thoát hàm
	else
		return;
}
// hoán đổi vị trí 2 độc giả
void hoandoi(docgia& a, docgia& b)
{
	docgia temp = a;
	a = b;
	b = temp;
}
// sắp xếp độc giả theo tên + họ tăng dần
void SX_DG_TEN(docgia* arr, int n)
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
void TIM_KIEM_PT_THEMANG(TREE& p, TREE& q)
{
	// duyệt đến phần tử trái nhất của cây
	if (q->pLeft != NULL)
	{
		TIM_KIEM_PT_THEMANG(p, q->pLeft);
	}
	// đã tìm được phần tử thế mạng
	else
	{
		p->data = q->data;
		p = q;
		q = q->pRight;
	}
}
int Dem_Sach_CON_MUON_DUOC(LIST_DS l, string ISBN)
{
	int i = TIM_KIEM_DS_THEO_MA(l, ISBN);
	int n = 0;
	if (i != -1)
	{
		for (node_danhmucsach* p = l.ds_dausach[i]->dms.pHead; p != NULL; p = p->pNext)
			if (p->data.trangthai == 0)
				n++;
	}
	return n;
}
// rt true nếu độc giả đang mượn cuốn sách có đầu sách tương tự <> false
bool KT_SACH_DG_MUON(TREE p, string ma_sach)
{
	string s = tach_ma_sach(ma_sach);
	string temp;
	for (NODE_MT* q = p->data.mt.pHead; q != NULL; q = q->pNext)
	{
		if (q->data.trangthai == 0) // đang mượn sách
		{
			temp = tach_ma_sach(q->data.masach);
			if (temp == s) // đang mượn cuốn sách có đầu sách tương tự
				return true;
		}
	}
	return false;
}
// số lượng sách độc giả đã và đang mượn
int tong_so_sach_DG(docgia x)
{
	int n = 0;
	for (NODE_MT* p = x.mt.pHead; p != NULL; p = p->pNext)
		n++;
	return n;
}
// đếm số đọc giả trong cây
int SoluongDG(TREE t)
{
	int n = 1;
	if (t)
	{
		n += SoluongDG(t->pLeft);
		n += SoluongDG(t->pRight);
		return n;
	}
	else return 0;
}
// đếm số sách độc giả đang mượn dùng để kiểm tra điều kiện mượn sách 
int DEM_SACH_DG_MUON(TREE t)
{
	int so_sach_muon = 0;
	for (NODE_MT* p = t->data.mt.pHead; p != NULL; p = p->pNext)
	{
		if (p->data.trangthai == 0 || p->data.trangthai == 2) // sách chưa trả
			so_sach_muon++;
	}
	return so_sach_muon;
}
// kiem tra xem doc gia co muon sach qua han hay ko neu qua han rt true <> false
bool Dem_SN_QUAHAN(TREE p)
{
	int n = 0;
	for (NODE_MT* q = p->data.mt.pHead; q != NULL; q = q->pNext)
	{
		if (q->data.trangthai == 0) // dang muon sach
		{
			n = tinh_so_ngay(q->data.ngaymuon);
			if (n >= 7)
				return true;
		}
	}
	return false;
}
//================================ ĐẦU SÁCH ============================
// sắp xếp đầu sách theo thể loại
void SX_THELOAI_DS(LIST_DS& l)
{
	dausach* temp = NULL;
	//sap xep theo the loai
	for (int i = 0; i < l.sl - 1; i++)
		for (int j = i + 1; j < l.sl; j++)
		{
			if (l.ds_dausach[i]->theloai > l.ds_dausach[j]->theloai)
			{
				temp = l.ds_dausach[i];
				l.ds_dausach[i] = l.ds_dausach[j];
				l.ds_dausach[j] = temp;
			}
			else if (l.ds_dausach[i]->theloai == l.ds_dausach[j]->theloai)
			{
				if (l.ds_dausach[i]->tensach > l.ds_dausach[j]->tensach)
				{
					temp = l.ds_dausach[i];
					l.ds_dausach[i] = l.ds_dausach[j];
					l.ds_dausach[j] = temp;
				}
			}
		}
}
// đếm số lượng sách có thuộc 1 đầu sách
int tong_so_sach(dausach x)
{
	int n = 0;
	for (NODE_DMS* p = x.dms.pHead; p != NULL; p = p->pNext)
		n++;
	return n;
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
		giaiphong_cay(t->pLeft);
		giaiphong_cay(t->pRight);
		delete t;
		t = NULL;
	}
}
void giaiphong_dausach(LIST_DS& l)
{
	for (int i = 0; i < l.sl; i++)
	{
		NODE_DMS* p = NULL;
		while (l.ds_dausach[i]->dms.pHead != NULL)
		{
			p = l.ds_dausach[i]->dms.pHead;
			l.ds_dausach[i]->dms.pHead = l.ds_dausach[i]->dms.pHead->pNext;
			delete p;
		}
		l.ds_dausach[i]->dms.pTail = NULL;
		delete l.ds_dausach[i];
		l.sl--;
	}
}



// lấy thời gian thực hệ thống
void thoi_gian_thuc(Date& x)
{
	time_t t = time(NULL);
	tm* now = localtime(&t);
	x.ngay = now->tm_mday;
	x.thang = now->tm_mon + 1;
	x.nam = now->tm_year + 1900;
}
// tính ngày chênh lệch giữa 2 mốc thời gian
int tinh_so_ngay(Date n1)
{
	Date n2;
	thoi_gian_thuc(n2);
	int sum = 0;
	while (n2.nam >= n1.nam)
	{
		if (n1.nam == n2.nam && n2.thang == n1.thang)
		{
			sum += n2.ngay - n1.ngay;
			break;
		}
		else
		{
			// các tháng 4 6 9 11 có 30 ngày
			if (n1.thang == 4 || n1.thang == 6 || n1.thang == 9 || n1.thang == 11)
			{
				sum += 30 - n1.ngay;
			}
			if (n1.thang == 1 || n1.thang == 3 || n1.thang == 5 || n1.thang == 7 || n1.thang == 8 || n1.thang == 10 || n1.thang == 12)
			{
				sum += 31 - n1.ngay;
			}
			if (n1.thang == 2)
			{
				if (n1.nam % 4 == 0 && n1.nam % 100 != 0 || n1.nam % 400 == 0)
				{
					sum += 29 - n1.ngay;
				}
				else
					sum += 28 - n1.ngay;
			}
			n1.thang++; n1.ngay = 0;
			if (n1.thang == 13)
			{
				// tăng năm lên 1
				n1.nam++;
				n1.thang = 1;
			}
		}
	}
	return sum;
}




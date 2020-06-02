#pragma once
#include "ctdl.h"
#include "lib.h"

TREE tim_kiem_docgia_ma(TREE& t, int ma_doc_gia);
void sap_xep_theo_theloai_dausach(LIST_DS& l);
int SoluongDG(TREE t);
int Kiem_tra_phim(char c);
int tinh_so_ngay(Date n1);

void BaoLoi(string s) {
	TextColor(15);
	int n = s.length();
	int x = whereX(), y = whereY();
	gotoXY(3, 46);
	cout << s;
	Sleep(1500);
	for (int i = 0; i < n; i++)
	{
		gotoXY(3 + i, 46);
		cout << " ";
	}
	gotoXY(x, y);
	TextColor(7);
}
void Button()
{
	gotoXY(50, 44); TextColor(76); cout << "        ";
	gotoXY(50, 45); TextColor(78); cout << "  CHON  ";
	gotoXY(50, 46); TextColor(76); cout << "        ";
	gotoXY(50, 47); TextColor(79); cout << "  Enter ";

	gotoXY(70, 44); TextColor(76); cout << "        ";
	gotoXY(70, 45); TextColor(78); cout << "  SUA   ";
	gotoXY(70, 46); TextColor(76); cout << "        ";
	gotoXY(70, 47); TextColor(79); cout << "   F3   ";

	gotoXY(90, 44); TextColor(76); cout << "        ";
	gotoXY(90, 45); TextColor(78); cout << "  TIM   ";
	gotoXY(90, 46); TextColor(76); cout << "        ";
	gotoXY(90, 47); TextColor(79); cout << "   F4   ";

	gotoXY(110, 44); TextColor(76); cout << "        ";
	gotoXY(110, 45); TextColor(78); cout << "  THEM  ";
	gotoXY(110, 46); TextColor(76); cout << "        ";
	gotoXY(110, 47); TextColor(79); cout << "   F1   ";

	gotoXY(130, 44); TextColor(76); cout << "        ";
	gotoXY(130, 45); TextColor(78); cout << "  XOA   ";
	gotoXY(130, 46); TextColor(76); cout << "        ";
	gotoXY(130, 47); TextColor(79); cout << "   F2   ";

	gotoXY(150, 44); TextColor(76); cout << "        ";
	gotoXY(150, 45); TextColor(78); cout << "  THOAT ";
	gotoXY(150, 46); TextColor(76); cout << "        ";
	gotoXY(150, 47); TextColor(79); cout << "   ESC  ";
	gotoXY(0, 0);
	TextColor(7);
}
void ButtonNext()
{
	gotoXY(110, 42); TextColor(79); cout << "   ->   ";
	TextColor(7);
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
	bool KT=false;
	int length = 0; // biến cho con trỏ dịch đến cuối
	char c;
	do
	{
		c = _getch();
		if (c == 0 || c == -32)
			c = _getch();
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
				BaoLoi("Khong duoc de trong");
				KT = false;
			}
			else
				KT = true;

		}
	} while (KT == false);
	cout << endl;
	return atoi(str.c_str()); // chuyển kí tự sang số
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
// tạo 100000 mã độc giả 
void tao_ma_doc_gia()
{
	int* arr=new int[MAX_MATHE + 1];
	int i = 1;
	for (i; i <= 100000; i++)
	{
		arr[i] = i;
	}
	for (i = 1; i <= 100000; i+=2)
	{
		int j = rand() % 100000 + 1;
		swap(arr[i], arr[j]);
	}
	ofstream fileout("MADOCGIA.txt");
	for ( i = 1; i <= 100000; i++)
	{
		fileout << arr[i] << endl;
	}
	delete[] arr;
	fileout.close();
}


// =============================== giải phóng==================
void giaiphong_cay(TREE& t)
{
	if (t != NULL)
	{
		if (t->data.tongsosach > 0)
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
		}
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
			l.ds_dausach[i]->dms.pHead = p->pNext;
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
// phím chức năng rt 1 , số rt 2,Không thuộc cả 2 rt 0
int Kiem_tra_phim(char c)
{
	int arr[32] = { 72,75,77,80,81,73,44,46,59,39,47,93,91,92,61,82,83,79,71,122,123,68,67,66,65
	,64,63,62,61,60,59,96 };
	if (c >= '0' && c <= '9')
		return 2;
	// nhấn shift + key
	if (GetKeyState(VK_SHIFT) & 0x8000)
		return 1;
	for (int i = 0; i < 32; i++)
	{
		if (c == arr[i])
			return 1; 
	}
	return 0;
}

// Hàm nhập dữ liệu toàn kí tự . VD: họ, tên, giới tính. Kí tự bắt đầu phải là kí tự 
string nhap_ki_tu()
{
	// nếu nhập kí tự enter thì chuỗi hiểu đó là kí tự kết thúc chuỗi <=> length = 0, ko tính là 1 kí tự
	string str;
	bool KT = false;;
	int length = 0; // biến cho con trỏ dịch đến cuối
	char c;
	do
	{
		c = _getch();
		if (c == 0 || c == -32)
		{
			c = _getch();
		}
		while (int(c) != 13)
		{
			if (c == 27)
			{
				return "-1";
			}
			int k = Kiem_tra_phim(c);
			if (k == 1) // phím chức năng
			{
				BaoLoi("Phim Nhap Khong Hop Le");
				break;
			}
			if (k == 2) // nếu nhập kí tự là số
			{
				BaoLoi("Khong duoc nhap so");
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
				cout << c;
				length++; // cập nhật vụ trí con trỏ chỉ vị
				str.push_back(c);
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
				BaoLoi("Khong duoc de trong");
				KT = false;
			}
			else
				KT = true;

		}
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
	bool KT=false;
	int length = 0; // biến cho con trỏ dịch đến cuối
	char c;
	do
	{
		c = _getch();
		if (c == 0 || c == -32)
		{
			c = _getch();
		}
		while (int(c) != 13)
		{
			if (c == 27)
			{
				return "-1";
			}
			int k = Kiem_tra_phim(c);
			if (k == 1) // phím chức năng
			{
				BaoLoi("Phim Nhap Khong Hop Le");
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
				cout << c;
				length++; // cập nhật vụ trí con trỏ chỉ vị
				str.push_back(c);
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
				BaoLoi("Khong duoc de trong");
				KT = false;
			}
			else
				KT = true;

			}
	} while (KT == false);
	cout << endl;
	chuan_hoa_chu(str);
	return str;
}

string nhap_gioitinh()
{

	// nếu nhập kí tự enter thì chuỗi hiểu đó là kí tự kết thúc chuỗi <=> length = 0, ko tính là 1 kí tự
	string str;
	bool KT=false;
	int length = 0; // biến cho con trỏ dịch đến cuối
	char c;
	do
	{
		c = _getch();
		if (c == -32 || c==0) c = _getch();
		while (int(c) != 13)
		{
			if (c == 27)
			{
				return "-1";
			}
			if (Kiem_tra_phim(c) == 1)
			{
				BaoLoi("Phim Nhap Khong Hop Le");
				break;
			}
			if (Kiem_tra_phim(c) == 2) // nếu nhập kí tự là số
			{
				BaoLoi("Khong duoc nhap so");
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
				cout << c;
				length++; // cập nhật vụ trí con trỏ chỉ vị
				str.push_back(c);
			}
			break;
		}
		if(c==13)
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
			if (str.length() == 0 || (dem >= 2 && dem1 == 0))
			{
				BaoLoi("Khong duoc de trong");
				KT = false;
			}
			if (str.length() >= 1)
			{
				chuan_hoa_chu(str);
				if (str == "Nam" || str == "Nu")
				{
					KT = true;
				}
				else
				{
					BaoLoi("GIOI TINH CHI NAM HOAC NU");
					while (length > 0)
					{
						cout << "\b \b";
						str.pop_back();
						length--;
					}
				}
			}
		}
} while (KT == false);
cout << endl;
return str;
}

void cap_nhat_trangthaithe_DG(TREE& t)
{
	if (t != NULL)
	{
		for (NODE_MT* p = t->data.mt.pHead; p != NULL; p = p->pNext)
		{	
		int j = tinh_so_ngay(p->data.ngaymuon);
		if (j > 7) // nếu mượn sách quá hạn
		{
			t->data.trangthaithe = 0; // khóa thẻ
			break;
		}
		else if (p->data.trangthai == 2)// làm mất sách
		{
			t->data.trangthaithe = 0; // khóa thẻ
			break;
		}
		else
			t->data.trangthaithe = 1; // mở thẻ
		 }
		cap_nhat_trangthaithe_DG(t->pLeft);
		cap_nhat_trangthaithe_DG(t->pRight);
	}
}

int dem_so_sach_con_muonduoc(LIST_DS l,string ISBN)
{
	int sum = 0;
	for (int i = 0; i < l.sl; i++)
	{
		if (l.ds_dausach[i]->ISBN == ISBN)
		{
			for (NODE_DMS* p = l.ds_dausach[i]->dms.pHead; p != NULL; p = p->pNext)
			{
				if (p->data.trangthai == 0 )
					sum++;
			}
		}
	}
	return sum;
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

void xoa_hienthi_buttonNext()
{
	int x = whereX();
	int y = whereY();
	gotoXY(110, 42); cout << "           ";
	gotoXY(x, y);
}
void xoa_hien_thi_dausach()
{
	int x = whereX();
	int y = whereY();
	for (int i = 0; i <= 40; i++)
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
void xoa_hien_thi_sach()
{
	int x = whereX();
	int y = whereY();
	for (int i = 0; i <= 41; i++)
	{
		gotoXY(40, i);
		cout << "                                  ";
		gotoXY(55, i);
		cout << "                                   ";
		gotoXY(95, i);
		cout << "                                   ";
		gotoXY(110, i);
		cout << "                                    ";
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
void xoa_hien_thi_doc_gia()
{
	int x = whereX();
	int y = whereY();
	for (int i = 0; i <= 41; i++)
	{
		gotoXY(45, i);
		cout << "                     ";
		gotoXY(65, i);
		cout << "                         ";
		gotoXY(90, i);
		cout << "                          ";
		gotoXY(100, i);
		cout << "                        ";
	}
	gotoXY(x, y);
}
void huong_dan_su_dung()
{
	gotoXY(80, 2);
	TextColor(15);
	cout << "HUONG DAN SU DUNG";
	gotoXY(70, 4);
	cout << char(24);
	gotoXY(70, 6);
	cout << char(25);
	gotoXY(68, 5);
	cout << char(27);
	gotoXY(72, 5);
	cout << char(26);
	gotoXY(75, 5);
	TextColor(14);
	cout << "Su Dung 4 Phim Mui Ten De Di Chuyen";

	gotoXY(66, 8); TextColor(76); cout << "        ";
	gotoXY(66, 9); TextColor(78); cout << "  CHON  ";
	gotoXY(66, 10); TextColor(76); cout << "        ";
	gotoXY(66, 11); TextColor(79); cout << "  Enter ";
	gotoXY(75, 10); TextColor(14); cout << "Bam Phim Enter De Chon Thao Tac";

	gotoXY(66, 14); TextColor(76); cout << "        ";
	gotoXY(66, 15); TextColor(78); cout << "  THOAT ";
	gotoXY(66, 16); TextColor(76); cout << "        ";
	gotoXY(66, 17); TextColor(79); cout << "   ESC  ";
	gotoXY(75, 16); TextColor(14); cout << "Bam Phim ESC De Quay Lai Hoac Thoat";
	gotoXY(0, 0);
}
void xoa_hien_thi_huong_dan()
{
	int x = whereX();
	int y = whereY();
	TextColor(7);
	gotoXY(80, 2);
	cout << "                  ";
	gotoXY(70, 4);
	cout << "   ";
	gotoXY(70, 6);
	cout << "   ";
	gotoXY(68, 5);
	cout << "   ";
	gotoXY(72, 5);
	cout << "   ";
	gotoXY(75, 5);
	cout << "                                    ";

	gotoXY(66, 8);  cout << "        ";
	gotoXY(66, 9);  cout << "        ";
	gotoXY(66, 10);  cout <<"        ";
	gotoXY(66, 11); cout << "        ";
	gotoXY(75, 10); cout << "                               ";

	gotoXY(66, 14); cout << "        ";
	gotoXY(66, 15); cout << "        ";
	gotoXY(66, 16); cout << "        ";
	gotoXY(66, 17); cout << "        ";
	gotoXY(75, 16); cout << "                                   ";
	gotoXY(x, y);
}

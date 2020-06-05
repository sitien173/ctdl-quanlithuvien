#include "xulyde.h"
char thaotac[][50] =
{					"          DOC GIA                 ",
				    "          DAU SACH                ",
				    "          MUON SACH               ",
					"          TRA SACH                ",
					"         LAM MAT SACH             ",
				    "    TIM SACH DOC GIA DANG MUON    ",
				    "     DANH SACH DOC GIA QUA HAN    ",
				    "    TOP 10 SACH MUON NHIEU NHAT   ",
					"       THOAT CHUONG TRINH         "};
enum TRANGTHAI{UP,DOWN,LEFT,RIGHT,ENTER,ESC};
// hàm có chức năng bắt phim vừa nhập để điều khiển menu
TRANGTHAI key(char c)
{
	if (c == -32)
	{
		c = _getch();
	}
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
int menu_dong(char thaotac[][50],int n) // n là số lượng item
{
	int tt=0; // biến chỉ ra đang ở thao tác nào
	int mau[10];
	for (int i = 0; i < n; i++)
		mau[i] = 7;
	mau[0] = 14; // hiện đang ở trạng thái thứ nhất
	// lặp vô hạn cho đến khi trả về giá trị của hàm thì dừng
	clrscr();
	while (1) {
		huong_dan_su_dung();
		xoa_hien_thi_button();
		// in ra menu
		for (int i = 0; i < n; i++)
		{
			TextColor(mau[i]); // đổi màu chữ cho chữ chuẩn bị in ra
			cout  << char(4) << " " << thaotac[i] << " " << char(4) <<  endl;
		}
		char z = _getch();
		TRANGTHAI trangthai = key(z);
		switch (trangthai)
		{
		case UP:
		case LEFT:
		{
			if (tt == 0)
			{
				tt = n - 1;
			}
			else
				tt--;
			break;
		}
		case DOWN:
		case RIGHT:
		{
			if (tt == n - 1)
			{
				tt = 0;
			}
			else
				tt++;

			break;
		}
		case ESC:
		{
			return tt=27;
		}
		case ENTER:
		{
			xoa_hien_thi_huong_dan();
			return tt + 1;
		}
		}
		// reset lại màu sau khi đã chọn thao tác để in ra
		for (int i = 0; i < n; i++)
			mau[i] = 7;
		mau[tt] = 14;
	}
}
void menu_xuli()
{
	TREE t;
	LIST_DS l;
	LIST_QUAHAN l1;

	khoi_tao_cay(t);
	khoi_tao_dau_sach(l);
	LoadtuFile_DSDG(t);
	LoadFileDS(l);
	while (1)
	{
		clrscr();
		int tungdo = 0;
menu_chinh: 	int tt = menu_dong(thaotac, 9); // chọn thao tác với menu chính
		switch (tt)
		{
		// menu độc giả 
		case 1: 
		{
			char menu_docgia[6][50] = { "THEM DOC GIA      ",
										"XUAT DS DOC GIA   ",
										"TIM KIEM DOC GIA  ",
										"XOA DOC GIA       ",
										"HIEU CHINH DOC GIA",
										"THOAT             "
			};
menu_DG:	int chon = menu_dong(menu_docgia, 6); // chọn thao tác với menu độc giả
			// thêm độc giả
			if (chon == 1 ) // enter 
			{
				int i = them_doc_gia_vao_ds(t);
				if (i == -2) // ESC 
					goto menu_DG;
				else
				{
					BaoLoi("THEM THANH CONG");
					goto menu_DG;
				}
			} 
			// xuất danh sách độc giả
			if (chon == 2)
			{
menu_xuat:		char menu_xuat[3][50] = { "XUAT THEO MA DOC GIA","XUAT THEO HO TEN","THOAT" };
				int chon_1 = menu_dong(menu_xuat, 3); // chọn thao tác menu xuất
				if (chon_1 == 1)
				{
					if (t == NULL)
					{
						BaoLoi("DANH SACH TRONG");
						goto menu_xuat;
					}
					xuat_ds_thong_tin_doc_gia(t,tungdo);
					tungdo = 0;
					_getch();
					goto menu_xuat;
				}
				else if (chon_1 == 2)
				{
					int n; // khai báo biến đếm số lượng độc giả trong cây
					n = SoluongDG(t);
					docgia* arr = new docgia[n];
					chuyen_cay_sang_mang(t, arr,tungdo);
					tungdo = 0;
					sap_xep_doc_gia_theo_ten(arr, n);
					for (int i = 0; i < n;i++)
					{
						if (i < 40)
						{
							Xuat_Thong_Tin_Doc_Gia(arr[i], i + 1);
						}
						else
						{
							ButtonNext();
							char c = _getch();
							TRANGTHAI next = key(c);
							if (next == RIGHT)
							{
								xoa_hien_thi_doc_gia();
								for (int j = i; j < n; j++)
								{
									Xuat_Thong_Tin_Doc_Gia(arr[j], ++tungdo);
								}
								break;
							}
							else if (next == ESC)
							{
								xoa_hienthi_buttonNext();
								break;
							}
						}
					}
					tungdo = 0;
					delete[] arr;
					_getch();
					goto menu_xuat;
				}
				else
				{
					goto menu_DG;
				}
			}
			// TIM KIEM DOC GIA
			if (chon == 3 ) 
			{
				int k1 = 0;
				// in danh sách độc giả
				if (t != NULL)
					xuat_ds_thong_tin_doc_gia(t,tungdo);
				tungdo = 0;
				do
				{
					string temp="";
					gotoXY(1, 10);
					cout << "                                           ";
					gotoXY(1, 10);
					cout << "Nhap Doc Gia(Ten Hoac MA): ";
					k1 = nhap_ki_tu1(temp);
					if (k1 == -1) // ESC
						break;
					// chuyển đổi chuỗi về số
					int i = chuoi_sang_so(temp);
					// nếu temp là kí tự
					if (i == -1)
					{
						tungdo = 1;
						tim_kiem_ds_doc_gia_ten(t, temp,tungdo);
						tungdo = 0;
						_getch();
						break;
					}
					// temp là số
					else
					{
						TREE p = tim_kiem_docgia_ma(t, i);
						if (p == NULL)
						{
							BaoLoi("MA DOC GIA KHONG DUNG");
							continue;
						}
						else
						{
							// xóa hiển thị màn hình độc giả cũ
							xoa_hien_thi_doc_gia();
							Xuat_Thong_Tin_Doc_Gia(p->data, ++tungdo);
							tungdo = 0;
							_getch();
							break;
						}
					}
				} while (1);
				goto menu_DG;
			}
			// xóa độc giả
			if (chon == 4) 
			{
				int k1 = 0; // check ESC cua ham nhap
				do
				{
					if (t != NULL)
					xuat_ds_thong_tin_doc_gia(t, tungdo);
					tungdo = 0;
					int key=0;
					gotoXY(1, 10); cout << "                       ";
					gotoXY(1, 10); cout << "Nhap Ma Doc Gia: ";
					k1 = nhap_so_nguyen(key);
					if (k1 == -1) // nhập ESC
						break; 
					TREE p = tim_kiem_docgia_ma(t, key);
					if (p == NULL)
					{
						BaoLoi("MA DOC GIA KHONG DUNG");
						key = 0;
						continue;
					}
					else
					{
						int i=dem_sach_docgia_muon(p);
						if (i > 0)
						{
							BaoLoi("DOC GIA DANG MUON SACH KHONG THE XOA");
							continue;
						}
						xoa_theo_ma_doc_gia(t, key);
						break;
					}
				} while (1);
				goto menu_DG;
			}
			// Hiệu chỉnh 
			if (chon == 5 ) 
			{
				// in danh sách độc giả
				if (t != NULL)
					xuat_ds_thong_tin_doc_gia(t, tungdo);
				tungdo = 0;
				int i = sua_thong_tin_doc_gia(t);
				if (i == -2) // ESC
				goto menu_DG;
				else // i=1
				{
					BaoLoi("HIEU CHINH THANH CONG");
					break;
				}
			}
			// thoát || ESC
			if (chon == 6 || chon == 27)
				goto menu_chinh;
			break;
		}
		// menu đầu sách
		case 2:
		{
			char menu_dausach[6][50] = { "THEM DAU SACH      ",
										 "XUAT DAU SACH      ",
									     "TIM KIEM SACH      ",
									     "HIEU CHINH DAU SACH",
										 "THEM SACH          ",
									     "THOAT              " };
menu_DS:	int chon = menu_dong(menu_dausach, 6); // chọn thao tác trong menu đầu sách
			// Thêm đầu sách
			if (chon == 1 ) // Thêm Đầu Sách
			{
				dausach data;
				do
				{
					int i = nhap_DauSach(l, data);
					if (i == -2) // ESC
						break;
					else
					{
						them_vao_ds_dausach(l, data);
						BaoLoi("THEM THANH CONG");
						break;
					}
				} while (1);
				goto menu_DS;
			}
			// Xuất Đầu Sách
			if (chon == 2) // Xuất Đầu Sách
			{
				// in danh sách theo từng thể loại trong từng thể loại in  tăng dần theo tên
				xuat_ds_dausach(l);
				_getch();
				goto menu_DS;
			}
			// tìm kiếm sach
			if (chon == 3 ) 
			{
				int k1 = 0;
				string ten_sach="";
				string temp = "";
				int i = 0;
				do
				{
					xuat_ds_dausach(l);
					gotoXY(1, 11);
					cout << "                                 ";
					gotoXY(1, 10);
					cout << "NHAP TEN HOAC MA SACH CAN TIM:\n ";
					k1 = nhap_ki_tu1(ten_sach);
					if (k1 == -1) // ESC;
						break;
					temp = tach_ma_sach(ten_sach);
					i = tim_kiem_dau_sach_theo_ma(l, temp);
					if (i != -1) // tim thay sach
					{
						xoa_hien_thi_dausach();
						tim_kiem_dau_sach_theo_ten(l, l.ds_dausach[i]->tensach);
						_getch();
						break;
					}
					else // tim kiem theo ten
					{
						i = tim_kiem_dau_sach_theo_ten(l, ten_sach);
						if (i != -1) // không tìm thấy
						{
							_getch();
							break;
						}
						else
						{
							BaoLoi("KHONG TIM THAY");
							ten_sach = "";
							continue;
						}
					}
				} while (1);
				goto menu_DS;
			}
			// hieu chinh dau sach
			if (chon == 4 )
			{
			int i=sua_dau_sach(l);
				// sửa không thành công
			if (i == -2) // ESC
				break;
			else if(i==1)
			{
			 BaoLoi("HIEU CHINH THANH CONG");
			 break;
			}
				goto menu_DS;
			}
			// thêm sách
			if (chon == 5 )
			{
				xuat_ds_dausach(l); // in ra các đầu sách đang có
				do {
					int i = them_sach(l);
					if (i == -2) // ESC
					{
						break;
					}
					else if (i == -1) // mã đầu sách không tìm thấy
						continue;
					else // =1 thêm thành công
					{
						BaoLoi("THEM THANH CONG");
						break;
					}
				} while (1);
				goto menu_chinh;
			}
			// Thoat
			if (chon == 6) 
				goto menu_chinh;
			break;
		}
		// Mượn sách
		case 3:
		{
			int i = muonsach(t, l);
			if (i == -2) // ESC
				goto menu_chinh;
			else if (i == 1)
				BaoLoi("MUON THANH CONG");
			break;
		}
		// TRẢ SÁCH
		case 4:
		{
			do
			{
				int i=trasach(t, l);
				if (i == -2) // ESC
					break;
				else if (i == -1) // Trả Không Thành Công
					continue;
				else
				{
					BaoLoi("TRA THANH CONG");
					break;
				}
			} while (1);
			goto menu_chinh;
		}
		// Làm mất sách
		case 5:
		{
			int k1 = 0; // check ESC cua ham nhap
			TREE p = NULL;
			int ma_doc_gia=0;
			do
			{
				xuat_ds_thong_tin_doc_gia(t, tungdo);
				tungdo = 0;
				gotoXY(0, 10);
				cout << "                         ";
				gotoXY(0, 10);
				cout << "Nhap Ma Doc Gia: ";
				k1 = nhap_so_nguyen(ma_doc_gia);
				if (k1 == -1) // ESC
					break;
				p = tim_kiem_docgia_ma(t, ma_doc_gia);
				if (p == NULL)
				{
					BaoLoi("MA DOC GIA KHONG DUNG");
					ma_doc_gia = 0;
					continue;
				} 
				else // tìm thấy độc giả
				{
					int i=xuat_sach_dang_muon(p, l);
					if (i == 0)
					{
						BaoLoi("DOC GIA KHONG MUON SACH");
						ma_doc_gia = 0;
						continue;
					}
					else  // xuất các sách độc giả đang mượn
					{
						int k1 = 0;
						xoa_hien_thi_doc_gia();
						xuat_sach_dang_muon(p, l);
						string ma_sach="";
						NODE_DMS* dms=NULL;
						NODE_MT* mt = NULL;
						do
						{
							gotoXY(0, 10);
							cout << "                                  ";
							gotoXY(0, 10); 
							cout << "Nhap Ma Sach Bi Mat: ";
							k1= nhap_ki_tu1(ma_sach);
							if (k1 == -1) // ESC
								break;
							dms=tim_kiem_sach(l, ma_sach);
							// nếu không tìm thấy
							if (dms == NULL)
							{
								BaoLoi("MA SACH KHONG DUNG");
								ma_sach = "";
								continue;
							}
							else // nếu tìm thấy
							{
								for (mt = p->data.mt.pHead; mt != NULL; mt = mt->pNext)
								{
									if (mt->data.masach == dms->data.masach)
									{
										mt->data.trangthai = 2; // cap nhat trang thai muon tra
										dms->data.trangthai = 2; // cap nhat trang thai sach da mat
										p->data.trangthaithe = 0; // khoa the doc gia
										BaoLoi("CAP NHAT SACH THANH CONG");
										break;
									}
								}
								break;
							}
							break;
						} while (1);
					}
				}
				break;
			} while (1);
			break;
		}
		// Danh sách sách động giả đang mượn
		case 6:
		{
			int k1 = 0;//check ESC cua ham nhap
			int ma_doc_gia=0;
			xuat_ds_thong_tin_doc_gia(t, tungdo);
			tungdo = 0;
			do {
				gotoXY(1, 10);
				cout << "                                ";
				gotoXY(1, 10);
				cout << "Nhap Ma Doc Gia: ";
				k1 = nhap_so_nguyen(ma_doc_gia);
				if (k1 == -1) // ESC
					break;
				TREE p = tim_kiem_docgia_ma(t, ma_doc_gia);
				if (p == NULL)
				{
					BaoLoi("MA DOC GIA KHONG DUNG");
					ma_doc_gia = 0;
					continue;
				}
				else
				{
					xoa_hien_thi_doc_gia();
					if (xuat_sach_dang_muon(p, l) == 0) // độc giả không mượn sách
					{
						BaoLoi("DOC GIA KHONG MUON SACH");
						ma_doc_gia = 0;
						continue;
					}
					else
					{
						// dừng màn hinh chờ phím
						_getch();
						break;
					}
				}
			} while (1);
			goto menu_chinh;
		}
		// Danh sách độc giả quá hạn
		case 7:
		{
			ds_quahan(t, l1);
			_getch();
			goto menu_chinh;
		}
		// Top 10 Sách
		case 8:
		{
			top10sach(l);
			_getch();
			goto menu_chinh;
		}
		default:
		{
			GhiFileDG(t);
			GhiFileDS(l);
			giaiphong_cay(t);
			giaiphong_dausach(l);
			return;
		}
		}
	}
}
int main()
{
	// giả sử tối đa 100000 độc giả
	// tạo ngẫu nhiên 100000 mã thẻ ngẫu nhiên.chỉ chạy 1 lần khi file MADOCGIA rỗng
	// tao_ma_doc_gia();
	
	system("mode con COLS=700");
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	srand(time(NULL));
	menu_xuli();	
	return 0;
}
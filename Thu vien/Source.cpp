#include "xulyde.h"
char thaotac[][50] =
{					"DOC GIA                           ",
				    "DAU SACH                          ",
				    "DANH SACH SACH                    ",
				    "MUON SACH                         ",
					"TRA SACH                          ",
				    "DANH SACH SACH 1 DOC GIA DANG MUON",
				    "DANH SACH DOC GIA QUA HAN         ",
				    "TOP 10 SACH MUON NHIEU NHAT       ",
					"THOAT CHUONG TRINH                "};
enum TRANGTHAI{UP,DOWN,LEFT,RIGHT,ENTER,ESC,F1,F2,F3,F4};
// hàm có chức năng bắt phim vừa nhập để điều khiển menu
TRANGTHAI key(char c)
{
	while (c == -32)
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
		if (c == 59)
			return F1;
		if (c == 60)
			return F2;
		if (c == 61)
			return F3;
		if (c == 62)
			return F4;
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
		// 41 là tung độ mặc định của các botton
		Button(41);
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
		case F1:
		{
			TextColor(7);
			return tt = 59;
		}
		case F2: 
		{
			TextColor(7);
			return tt = 60;
		}
		case F3:
		{
			TextColor(7);
			return tt = 61;
		}
		case F4:
		{
			TextColor(7);
			return tt = 62;
		}
		case ESC:
		{
			TextColor(7);
			return tt=27;
		}
		case ENTER:
			return tt + 1;
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
	cap_nhat_sach(t, l);
	LoadtuFile_DSDG(t);
	LoadFileDS(l);
	Load_file_quahan(l1);
	while (1)
	{
		clrscr();
		int tungdo = 0;
	menu_chinh:	int tt = menu_dong(thaotac, 9); // chọn thao tác với menu chính
		switch (tt)
		{
		// menu độc giả 
		case 1: 
		{
			char menu_docgia[6][50] = { "THEM DOC GIA",
										"XUAT DS DOC GIA",
										"TIM KIEM DOC GIA",
										"XOA DOC GIA",
										"HIEU CHINH DOC GIA",
										"THOAT"
			};
menu_DG:	int chon = menu_dong(menu_docgia, 6); // chọn thao tác với menu độc giả
			// thêm độc giả
			if (chon == 1 || chon == 59) // enter || F1
			{
				int i = them_doc_gia_vao_ds(t);
				if (i == -2) // ESC 
					goto menu_DG;
				else
				{
					BaoLoi("Them Thanh Cong");
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
						BaoLoi("Danh sach rong");
						goto menu_xuat;
					}
					TextColor(15);
					xuat_ds_thong_tin_doc_gia(t,tungdo);
					tungdo = 0;
					TextColor(7);
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
						TextColor(15);
						Xuat_Thong_Tin_Doc_Gia(arr[i],i+1);
						TextColor(7);
					}
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
			if (chon == 3 || chon == 62) // enter || F4
			{
				// in danh sách độc giả
				if (t != NULL)
					xuat_ds_thong_tin_doc_gia(t,tungdo);
				tungdo = 0;
				do
				{
					string temp;
					cout << "\nNhap Doc Gia(Ten Hoac MA): ";
					temp = nhap_ki_tu1();
					if (temp == "-1") // ESC
						break;
					// chuyển đổi chuỗi về số
					int i = chuoi_sang_so(temp);
					// nếu temp là kí tự
					if (i == -1)
					{
						tim_kiem_ds_doc_gia_ten(t, temp,1);
						_getch();
						break;
					}
					// temp là số
					else
					{
						TREE p = tim_kiem_docgia_ma(t, i);
						if (p == NULL)
						{
							BaoLoi("Ma Doc Gia Khong Ton Tai");
							continue;
						}
						else
						{
							TextColor(14);
							// xóa hiển thị màn hình độc giả cũ
							xoa_hien_thi_doc_gia(t);
							Xuat_Thong_Tin_Doc_Gia(p->data, ++tungdo);
							tungdo = 0;
							TextColor(7);
							_getch();
							break;
						}
					}
				} while (1);
				goto menu_DG;
			}
			// xóa độc giả
			if (chon == 4 || chon == 60) // enter || F2
			{
				// in danh sách độc giả
				if (t != NULL)
					xuat_ds_thong_tin_doc_gia(t,tungdo);
				tungdo = 0;
				do
				{
					int key;
					cout << "\nNhap Ma Doc Gia: ";
					key = nhap_so_nguyen();
					if (key == -1) // nhập ESC
						break; 
					TREE p = tim_kiem_docgia_ma(t, key);
					if (p == NULL)
					{
						BaoLoi("Ma Doc Gia Khong Ton Tai");
						continue;
					}
					else
					{
						xoa_theo_ma_doc_gia(t, key);
						break;
					}
				} while (1);
				goto menu_DG;
			}
			// Hiệu chỉnh 
			if (chon == 5 || chon == 61) // enter || F3
			{
				// in danh sách độc giả
				if (t != NULL)
					xuat_ds_thong_tin_doc_gia(t, tungdo);
				tungdo = 0;
				int ma;
				do {
					cout << "\nNhap ma doc gia: ";
					ma = nhap_so_nguyen();
					if (ma == -1) // ESC
						break;
					int i = sua_thong_tin_doc_gia(t, ma);
					if (i == -2) // ESC
						break;
					else
					{
						BaoLoi("Sua Thanh Cong");
						continue;
					}
				} while (1);
				goto menu_DG;
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
									     "TIM KIEM DAU SACH  ",
									     "XOA DAU SACH       ",
									     "HIEU CHINH DAU SACH",
									     "THOAT" };
menu_DS:	int chon = menu_dong(menu_dausach, 6); // chọn thao tác trong menu đầu sách
			// Thêm đầu sách
			if (chon == 1 || chon == 62) // Thêm Đầu Sách
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
						BaoLoi("Them Thanh Cong");
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
			// tìm kiếm đầu sách
			if (chon == 3 || chon == 62) // 62 F4 
			{
				xuat_ds_dausach(l);
				string ten_sach;
				do
				{
					cout << "\nNhap Ten Sach Can Tim: ";
					ten_sach = nhap_ki_tu1();
					if (ten_sach == "-1") // ESC;
						break;
					int i = tim_kiem_dau_sach_theo_ten(l, ten_sach);
					if (i == -1) // không tìm thấy
					{
						BaoLoi("Khong Tim Thay");
						continue;
					}
					else
					{
						_getch();
						break;
					}
				} while (1);
				goto menu_DS;
			}
			// Xóa đầu sách
			if (chon == 4 || chon == 60)  // 60 là F2
			{
				do
				{
					xuat_ds_dausach(l);
					string ma_dau_sach;
					cout << "\nNhap Ma Dau Sach: ";
					ma_dau_sach = so_sang_chuoi(nhap_so_nguyen());
					if (ma_dau_sach == "-1") // ESC
					{
						goto menu_DS;
					}
					int temp = xoa_dau_sach(l, ma_dau_sach); // biến temp để dùng để kiểm tra điều kiện nếu xóa thành công temp =1 <> -1
					if (temp == -1) // Xóa Thất bại
					{
						BaoLoi("Ma Dau Sach Khong Ton Tai");
						continue;
					}
					else
					{
						BaoLoi("Xoa Thanh Cong");
						break;
					}
				} while (1);
				goto menu_DS;
			}
			// hieu chinh dau sach
			if (chon == 5 || chon == 61)
			{
				xuat_ds_dausach(l);
				string ma_dau_sach;
				do {
					int i=sua_dau_sach(l);
					// sửa không thành công
					if (i == -1)
						continue;
					else if (i == -2) // ESC
						break;
					else
					{
						BaoLoi("Sua Thanh Cong");
						break;
					}
				} while (1);
				goto menu_DS;
			}
			// Thoat
			if (chon == 6) 
				goto menu_chinh;
			break;
		}
		// menu Sach
		case 3:
		{
			char menu_sach[6][50] = { "THEM SACH    ",
									  "XUAT SACH    ",
									  "TIM KIEM SACH",
									  "XOA SACH     ",
									  "HIEU CHINH   ",
									  "THOAT        "
			};
menu_sach:		int chon = menu_dong(menu_sach, 6); // bien chon thao tac voi menu_sach
			// Them Sach
			if (chon == 1 || chon == 59)
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
						BaoLoi("Them Thanh Cong");
						break;
					}
				} while (1);
				goto menu_sach;
			}
			// Xuat Sach
			if (chon == 2)
			{
				xuat_ds_sach1(l);
				_getch();
				goto menu_sach;
			}
			// tim kiem sach
			if (chon == 3|| chon == 62)
			{
				string ten_sach;
				xuat_ds_sach1(l);
				do
				{
					cout << "\nNhap Ten Sach Can Tim: ";
					ten_sach = nhap_ki_tu1();
					if (ten_sach == "-1") // ESC
						break;
					if (tim_kiem_sach_ten(l, ten_sach) == -1)
					{
						BaoLoi("Ten Sach Khong Ton Tai");
						continue;
					}
					else
					{
						_getch();
						break;
					}
				} while (1);
				goto menu_sach;
			}
			// Xoa sach
			if (chon == 4 || chon == 60)
			{
				xuat_ds_sach1(l);
				string ma_sach;
				do
				{
					cout << "\nNhap Ma Sach: ";
					ma_sach = nhap_ki_tu1();
					if (ma_sach == "-1") // ESC
						break;
					if (xoa_sach(l, ma_sach) == 1)
					{
						BaoLoi("Xoa Thanh Cong");
						continue;
					}
					else
						continue;
				} while (1);
				goto menu_sach;
			}
			// Hiệu Chỉnh Sách
			if (chon == 5 || chon == 61)
			{
				string ma_sach;
				xuat_ds_sach1(l);
				do
				{
					cout << "\nNhap Ma Sach: ";
					ma_sach = nhap_ki_tu1();
					if (ma_sach == "-1") // ESC
						break;
					NODE_DMS* p = tim_kiem_sach(l, ma_sach);
					if (p == NULL) // Mã sách ko tìm thấy
					{
						BaoLoi("Ma Sach Khong Ton Tai");
						continue;
					}
					else
					{
						int i = hieu_chinh_sach(p->data, ma_sach);
						if (i == -2) // ESC
						{
							break;
						}
						else if (i == 1)
						{
							BaoLoi("Hieu Chinh Thanh Cong");
							break;
						}
					}

				} while (1);
				goto menu_sach;
			}
			if (chon == 6)
				goto menu_chinh;
			break;
		}
		// Mượn sách
		case 4:
		{
			do
			{
				int i = muonsach(t, l, l1);
				if (i == -2) // ESC
				{
					break;
				}
				else
				{
					if (i == -1) // Không thành công
					{
						continue;
					}
					else
					{
						BaoLoi("Muon Thanh Cong");
						break;
					}
				}
			} while (1);
			goto menu_chinh;
		}
		// TRẢ SÁCH
		case 5:
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
					BaoLoi("Tra Thanh Cong");
					break;
				}
			} while (1);
			goto menu_chinh;
		}
		// Danh sách sách động giả đang mượn
		case 6:
		{
			int ma_doc_gia;
			xuat_ds_thong_tin_doc_gia(t, tungdo);
			tungdo = 0;
			do {
				cout << "\nNhap Ma Doc Gia: ";
				ma_doc_gia = nhap_so_nguyen();
				if (ma_doc_gia == -1) // ESC
					break;
				TREE p = tim_kiem_docgia_ma(t, ma_doc_gia);
				if (p == NULL)
				{
					BaoLoi("Ma Doc Gia Khong Ton Tai");
					continue;
				}
				else
				{
					xoa_hien_thi_doc_gia(t);
					if (xuat_sach_dang_muon(p, l) == 0) // độc giả không mượn sách
					{
						BaoLoi("Doc Gia Khong Co Sach Muon");
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
			//Ghi_file_quahan(t, l1);
			giaiphong_cay(t);
			giai_phong_vung_nho_dau_sach(l);
			return;
		}
		}
	}
}
int main()
{
	resizeConsole(1390, 650);
	srand(time(NULL));
	menu_xuli();
	_getch();
	return 0;
}
#include "xulyde.h"
char thaotac[][50] =
{					"DOC GIA                    ",
				    "DAU SACH                   ",
				    "MUON SACH                  ",
					"TRA SACH                   ",
					"LAM MAT SACH               ",
				    "TIM SACH DOC GIA DANG MUON ",
				    "DANH SACH DOC GIA QUA HAN  ",
				    "TOP 10 SACH MUON NHIEU NHAT",
					"THOAT  CHUONG TRINH        "};

int menu_dong(char thaotac[][50],int n) // n là số lượng item
{
	control_cursor(false);
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
				tt = n - 1;
			else
				tt--;
			break;
		}
		case DOWN:
		case RIGHT:
		{
			if (tt == n - 1)
				tt = 0;
			else
				tt++;
			break;
		}
		case ESC:
		{

			return tt = 27;
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

	Init_TREE(t);
	Init_DS(l);
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
			if (chon == 1) // enter 
			{
				while (1)
				{
					docgia x;
					ifstream filein("MADOCGIA.txt");
					ofstream filetemp("Temp.txt");
					filein >> x.mathe;
					int i = NHAP_THONGTIN_DG(x);
					// ESC
					if (i == -2)  goto menu_DG;
					else
					{
						Add_DG_VAO_CAY(t, x);
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
						BaoLoi("THEM THANH CONG");
						GhiFileDG(t);
					}
				}
			}
			// xuất danh sách độc giả
			if (chon == 2)
			{
menu_xuat:		char menu_xuat[3][50] = { "XUAT THEO MA DOC GIA",
										"XUAT THEO HO TEN    ",
										"      THOAT         " };
				int chon_1 = menu_dong(menu_xuat, 3); // chọn thao tác menu xuất
				if (chon_1 == 1)
				{
					if (t == NULL)
					{
						BaoLoi("DANH SACH TRONG");
						goto menu_xuat;
					}
					XUAT_DS_DG(t,tungdo);
					tungdo = 0;
					_getch();
					goto menu_xuat;
				}
				else if (chon_1 == 2)
				{
					int n; // khai báo biến đếm số lượng độc giả trong cây
					n = SoluongDG(t);
					docgia* arr = new docgia[n];
					CAY_SANG_MANG(t, arr,tungdo);
					tungdo = 0;
					SX_DG_TEN(arr, n);
					for (int i = 0; i < n;i++)
					{
						if (i < 40)
							Xuat_Thong_Tin_Doc_Gia(arr[i], i + 1);
						else
						{
							ButtonNext();
							char c = _getch();
							TRANGTHAI next = key(c);
							if (next == RIGHT)
							{
								xoa_hien_thi_doc_gia();
								for (int j = i; j < n; j++)
									Xuat_Thong_Tin_Doc_Gia(arr[j], ++tungdo);
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
					goto menu_DG;
			}
			// TIM KIEM DOC GIA
			if (chon == 3 ) 
			{
				int k1 = 0;
				do
				{
					xoa_hien_thi_doc_gia();
					if (t != NULL)
						XUAT_DS_DG(t, tungdo);
					tungdo = 0;
					string temp="";
					Box_NHAP("NHAP DG(TEN HOAC MA)");
					k1 = nhap_ki_tu(temp,1);
					Xoa_hien_thi_Box_NHAP();	
					if (k1 == -1) // ESC
						break;
					
					// chuyển đổi chuỗi về số
					int i = chuoi_sang_so(temp);
					// nếu temp là kí tự
					if (i == -1)
					{
						tungdo = 1;
						TIM_KIEM_DG_TEN(t, temp,tungdo);
						_getch();
						tungdo = 0;
					}
					// temp là số
					else
					{
						TREE p = TIM_KIEM_DG_MA(t, i);
						if (p == NULL)
						{
							BaoLoi("KHONG TIM THAY DOC GIA");
							continue;
						}
						else
						{
							// xóa hiển thị màn hình độc giả cũ
							xoa_hien_thi_doc_gia();
							Xuat_Thong_Tin_Doc_Gia(p->data, ++tungdo);
							tungdo = 0;
							_getch();
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
					xoa_hien_thi_doc_gia();
					if (t != NULL)
					XUAT_DS_DG(t, tungdo);
					tungdo = 0;
					int key=0;
					Box_NHAP("MA DG");
					k1 = nhap_so_nguyen(key);
					Xoa_hien_thi_Box_NHAP();
					if (k1 == -1) // nhập ESC
						break; 
					TREE p = TIM_KIEM_DG_MA(t, key);
					if (p == NULL)
					{
						BaoLoi("MA DOC GIA KHONG DUNG");
						continue;
					}
					else
					{
						int i=DEM_SACH_DG_MUON(p);
						if (i > 0)
						{
							BaoLoi("DOC GIA DANG MUON SACH KHONG THE XOA");
							continue;
						}
						else
						{
							XOA_DG(t, key);
							GhiFileDG(t);
						}
					}
				} while (1);
				goto menu_DG;
			}
			// Hiệu chỉnh 
			if (chon == 5 ) 
			{
				int mathe;
				int k = 0;
				do
				{
					xoa_hien_thi_doc_gia();
					xoa_hien_thi_Box_NhapDG();
					mathe = 0;
					if (t != NULL)
						XUAT_DS_DG(t, tungdo);
					tungdo = 0;

					Box_NHAP("MA DG");
					k = nhap_so_nguyen(mathe);
					Xoa_hien_thi_Box_NHAP();
					if (k == -1) // ESC
						break;
					TREE p = TIM_KIEM_DG_MA(t, mathe);
					if (p == NULL) {
						BaoLoi("MA DOC GIA KHONG TON TAI");
						continue;
					}
					xoa_hien_thi_doc_gia();
					int i=HIEU_CHINH_DG(p);
					if (i == 1)
					{
						BaoLoi("HIEU CHINH THANH CONG");
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
									     "TIM KIEM SACH      ",
									     "HIEU CHINH DAU SACH",
										 "THEM SACH          ",
									     "THOAT              " };
menu_DS:	int chon = menu_dong(menu_dausach, 6); // chọn thao tác trong menu đầu sách
			// Thêm đầu sách
			if (chon == 1 ) // Thêm Đầu Sách
			{
				do
				{
					dausach data;
					int i = NHAP_DS(l, data);
					if (i == -2) // ESC
						break;
					else
					{
						ADDTail_DS(l, data);
						BaoLoi("THEM THANH CONG");
						GhiFileDS(l);
					}
				} while (1);
				goto menu_DS;
			}
			// Xuất Đầu Sách
			if (chon == 2) // Xuất Đầu Sách
			{
				// in danh sách theo từng thể loại trong từng thể loại in  tăng dần theo tên
				XUAT_DS_DAUSACH(l);
				_getch();
				goto menu_DS;
			}
			// tìm kiếm sach
			if (chon == 3 ) 
			{
				int k1 = 0;
				int i = 0;
				string ten_sach;
				string temp;
				do
				{
					ten_sach = "";
					temp = "";
					XUAT_DS_DAUSACH(l);
					Box_NHAP("NHAP TEN(MA) SACH");
					k1 = nhap_ki_tu(ten_sach,1);
					Xoa_hien_thi_Box_NHAP();
					if (k1 == -1) // ESC;
						break;
					temp = tach_ma_sach(ten_sach);
					i = TIM_KIEM_DS_THEO_MA(l, temp);
					if (i != -1) // tim thay sach
					{
						xoa_hien_thi_dausach();
						XUAT_THONGTIN_DS(l, *l.ds_dausach[i], 1);
						_getch();
						break;
					}
					else // tim kiem theo ten
					{
						i = TIM_KIEM_DS_THEO_TEN(l, ten_sach);
						if(i==-1)
						{
							BaoLoi("KHONG TIM THAY");
							continue;
						}
					}
				} while (1);
				goto menu_DS;
			}
			// hieu chinh dau sach
			if (chon == 4)
			{
				while (1)
				{
					int i = HIEU_CHINH_DS(l);
					if (i == -2) // ESC
						goto menu_DS;
					else if (i == 1)
					{
						BaoLoi("HIEU CHINH THANH CONG");
						GhiFileDS(l);
					}
				}
			}
			// thêm sách
			if (chon == 5 )
			{
				do {
					int i = THEM_SACH(l);
					if (i == -1) break;
					BaoLoi("THEM THANH CONG");
					GhiFileDS(l);
				} while (1);
				goto menu_DS;
			}
			// Thoat
			if (chon == 6) 
				goto menu_chinh;
			break;
		}
		// Mượn sách
		case 3:
		{
			while (1)
			{
				int i = MUON_SACH(t, l);
				if (i == -2) // ESC
					goto menu_chinh;
				else if (i == 1)
				{
					BaoLoi("MUON THANH CONG");
					GhiFileDG(t);
					GhiFileDS(l);
				}
			}
		}
		// TRẢ SÁCH
		case 4:
		{
			while (1)
			{
				int i = TRA_SACH(t, l);
				if (i == -2) // ESC
					break;
				else if(i==1)
				{
					BaoLoi("TRA THANH CONG");
					GhiFileDG(t);
					GhiFileDS(l);
				}
			}
			goto menu_chinh;
		}
		// Làm mất sách
		case 5:
		{
			TREE p = NULL;
			int tungdo;
			int ma;
			int k1;
			do
			{
				tungdo = 0;
				ma = 0;
				k1 = 0;
				XUAT_DS_DG(t, tungdo);
				Box_NHAP("NHAP MA DG");
				k1 = nhap_so_nguyen(ma);
				Xoa_hien_thi_Box_NHAP();
				if (k1 == -1) // ESC
					break;

				p = TIM_KIEM_DG_MA(t, ma);
				xoa_hien_thi_doc_gia();
				if (p == NULL)
				{
					BaoLoi("MA DOC GIA KHONG DUNG");
					continue;
				}
				else
				{
					do
					{
						int n = DEM_SACH_DG_MUON(p);
						muontra* arr = new muontra[n];
						int j = 0;
						bool check = false; // check xem doc gia co muon sach hay khong
						for (NODE_MT* q = p->data.mt.pHead; q != NULL; q = q->pNext)
						{
							if (q->data.trangthai == 0)
							{
								check = true;
								NODE_DMS* dms = TIM_KIEM_SACH(l, q->data.masach);
								string temp = tach_ma_sach(dms->data.masach);
								int i = TIM_KIEM_DS_THEO_MA(l, temp);
								if (i != -1)
								{
									XUAT_THONG_TIN_MT(q->data, l.ds_dausach[i]->tensach, j + 1);
									arr[j++] = q->data;
								}
							}
						}
						if (check == true)
						{
							control_cursor(false);
							int k = 1;
							bool check = false;
							while (check == false)
							{
								ToMau(45, k, arr[k - 1].masach, 14);
								gotoXY(59, k);
								char c = _getch();
								ToMau(45, k, arr[k - 1].masach, 15);
								TRANGTHAI tt = key(c);
								switch (tt)
								{
								case UP:
								case LEFT:
								{
									if (k == 1)
										k = j;
									else
										k--;
									break;
								}
								case DOWN:
								case RIGHT:
								{
									if (k == j)
										k = 1;
									else
										k++;
									break;
								}
								case ESC:
								{
									delete[] arr;
									goto menu_chinh;
								}
								case ENTER:
								{
									check = true;
									break;
								}
								}
							}
							NODE_DMS* dms1 = TIM_KIEM_SACH(l, arr[k - 1].masach);
							for (NODE_MT* MT = p->data.mt.pHead; MT != NULL; MT = MT->pNext)
							{
								if (MT->data.masach == dms1->data.masach)
								{
									dms1->data.trangthai = 2; // cap nhat sach da thanh li
									MT->data.trangthai = 2; // cap nhat lai doc gia da lam mat sach
									break;
								}
							}
							p->data.trangthaithe = 0; // khoa the doc gia
							BaoLoi("CAP NHAT THANH CONG");
							delete[] arr;
							xoa_hien_thi_dausach();
							GhiFileDG(t);
							GhiFileDS(l);
						}
						else
						{
							BaoLoi("DOC GIA KHONG MUON SACH");
							break;
						}

					} while (1);
				}
			} while (1);
			break;
		}
		// Danh sách sách động giả đang mượn
		case 6:
		{
			int k1 = 0;//check ESC cua ham nhap
			int ma_doc_gia;
			do {
				ma_doc_gia = 0;
				XUAT_DS_DG(t, tungdo);
				tungdo = 0;
				Box_NHAP("NHAP MA DG");
				k1 = nhap_so_nguyen(ma_doc_gia);
				Xoa_hien_thi_Box_NHAP();
				if (k1 == -1) // ESC
					break;
				TREE p = TIM_KIEM_DG_MA(t, ma_doc_gia);
				if (p == NULL)
				{
					BaoLoi("MA DOC GIA KHONG DUNG");
					continue;
				}
				else
				{
					xoa_hien_thi_doc_gia();
					if (XUAT_SACH_MUON(p, l) == 0) // độc giả không mượn sách
					{
						BaoLoi("DOC GIA KHONG MUON SACH");
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
			DS_QUAHAN(t, l1);
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
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE); // full screen
	srand(time(NULL));
	menu_xuli();	
	return 0;
}
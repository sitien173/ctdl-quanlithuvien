#pragma once
#pragma comment(lib, "winmm.lib")
#include "lib.h"
void Box_BaoLoi()
{
	int tungdo = 45;
	TextColor(14);
	gotoXY(86, tungdo - 1);
	cout << "THONG BAO";
	TextColor(76);
	gotoXY(boxx, tungdo); cout << char(201);
	for (int i = 1; i < boxs + 1; i++) cout << char(205);
	cout << char(187);
	gotoXY(boxx, tungdo + 1); cout << char(186);
	gotoXY(boxx + boxs + 1, tungdo + 1); cout << char(186);
	gotoXY(boxx, tungdo + 2); cout << char(186);
	gotoXY(boxx + boxs + 1, tungdo + 2); cout << char(186);
	gotoXY(boxx, tungdo + 3); cout << char(186);
	gotoXY(boxx + boxs + 1, tungdo + 3); cout << char(186);
	gotoXY(boxx, tungdo + 4); cout << char(186);
	gotoXY(boxx + boxs + 1, tungdo + 4); cout << char(186);
	gotoXY(boxx + 1, tungdo + 5);
	for (int i = 1; i <= boxs; i++) cout << char(205);
	gotoXY(boxx, tungdo + 5); cout << char(200);
	gotoXY(boxx + boxs + 1, tungdo + 5); cout << char(188);
	TextColor(7);
}
void xoa_hienthi_box_baoloi()
{
	int tungdo = 45;
	gotoXY(86, tungdo - 1);
	cout << "               ";
	TextColor(4);
	gotoXY(boxx, tungdo); cout << " ";
	for (int i = 1; i < boxs + 1; i++) cout << " ";
	cout << " ";
	gotoXY(boxx, tungdo + 1); cout << " ";
	gotoXY(boxx + boxs + 1, tungdo + 1); cout << " ";
	gotoXY(boxx, tungdo + 2);  cout << " ";
	gotoXY(boxx + boxs + 1, tungdo + 2); cout << " ";
	gotoXY(boxx, tungdo + 3);  cout << " ";
	gotoXY(boxx + boxs + 1, tungdo + 3); cout << " ";
	gotoXY(boxx, tungdo + 4); cout << " ";
	gotoXY(boxx + boxs + 1, tungdo + 4); cout << " ";
	gotoXY(boxx + 1, tungdo + 5);
	for (int i = 1; i <= boxs; i++) cout << " ";
	gotoXY(boxx, tungdo + 5); cout << " ";
	gotoXY(boxx + boxs + 1, tungdo + 5); cout << " ";
	TextColor(7);
}
void BaoLoi(string s) {
	control_cursor(false);
	int n = s.length();
	int x = whereX(), y = whereY();
	Box_BaoLoi();
	TextColor(15);
	gotoXY(boxx + 28, boxy + 42);
	cout << s;
	Sleep(1200);
	while (_kbhit()) // không nhận phím  khi đang ngủ
		_getch();

	for (int i = 0; i < n; i++)
	{
		gotoXY(boxx + 28 + i, boxy + 42);
		cout << " ";
	}
	xoa_hienthi_box_baoloi();
	gotoXY(x, y);
	TextColor(7);
	control_cursor(true);
}
void ButtonPrev()
{
	gotoXY(100, 42); cout << "<-";
}
void ButtonNext()
{
	gotoXY(110, 42); cout << "->";
}
void xoa_hienthi_buttonNext()
{
	int x = whereX();
	int y = whereY();
	gotoXY(110, 42); cout << "       ";
	gotoXY(x, y);
}
void XOA_HIEN_THI()
{
	int x = whereX();
	int y = whereY();
	for (int i = 0; i <= 40; i++) {
		ClearLine(40, i);
	}
	gotoXY(x, y);
}


void ButtonEnter(int hoanhdo, int tungdo)
{
	int x = whereX();
	int y = whereY();
	gotoXY(hoanhdo, tungdo); TextColor(76); cout << "        ";
	gotoXY(hoanhdo, tungdo + 1); TextColor(78); cout << "  CHON  ";
	gotoXY(hoanhdo, tungdo + 2); TextColor(76); cout << "        ";
	gotoXY(hoanhdo, tungdo + 3); TextColor(79); cout << "  Enter ";
	gotoXY(x, y);
}
void ButtonESC(int hoanhdo, int tungdo)
{
	int x = whereX(), y = whereY();
	gotoXY(hoanhdo, tungdo); TextColor(76); cout << "        ";
	gotoXY(hoanhdo, tungdo + 1); TextColor(78); cout << "  THOAT ";
	gotoXY(hoanhdo, tungdo + 2); TextColor(76); cout << "        ";
	gotoXY(hoanhdo, tungdo + 3); TextColor(79); cout << "   ESC  ";
	gotoXY(x, y);
}
void xoa_hien_thi_1_Button(int hoanhdo, int tungdo)
{
	int x = whereX(), y = whereY();
	gotoXY(hoanhdo, tungdo); TextColor(7); cout << "        ";
	gotoXY(hoanhdo, tungdo + 1); TextColor(7); cout << "        ";
	gotoXY(hoanhdo, tungdo + 2); TextColor(7); cout << "        ";
	gotoXY(hoanhdo, tungdo + 3); TextColor(7); cout << "        ";
	gotoXY(x, y);
}

void xoa_hien_thi_button()
{
	int x = whereX(), y = whereY();
	TextColor(7);

	gotoXY(boxx + boxs - 5, boxy + 15);  cout << "        ";
	gotoXY(boxx + boxs - 5, boxy + 16);  cout << "        ";
	gotoXY(boxx + boxs - 5, boxy + 17);  cout << "        ";
	gotoXY(boxx + boxs - 5, boxy + 18);  cout << "        ";

	gotoXY(boxx + boxs - 45, boxy + 15);  cout << "        ";
	gotoXY(boxx + boxs - 45, boxy + 16);  cout << "        ";
	gotoXY(boxx + boxs - 45, boxy + 17);  cout << "        ";
	gotoXY(boxx + boxs - 45, boxy + 18);  cout << "        ";

	gotoXY(boxx, boxy + 15);  cout << "        ";
	gotoXY(boxx, boxy + 16);  cout << "        ";
	gotoXY(boxx, boxy + 17);  cout << "        ";
	gotoXY(boxx, boxy + 18);  cout << "        ";
	gotoXY(x, y);
}
void huong_dan_su_dung()
{
	ifstream fo("input1.txt");
	string s;
	int i = 0;
	int j = 1;
	int x = 80;
	while (!fo.eof())
	{
		getline(fo, s);
		i = 10 + rand() % 6;
		gotoXY(x, j++);
		TextColor(i);
		cout << s;
	}
	fo.close();

	gotoXY(94, 20);
	TextColor(15);
	cout << "HUONG DAN SU DUNG";
	gotoXY(82, 24);
	cout << char(24);
	gotoXY(82, 26);
	cout << char(25);
	gotoXY(80, 25);
	cout << char(27);
	gotoXY(84, 25);
	cout << char(26);
	gotoXY(86, 25);
	TextColor(14);
	cout << "Su Dung 4 Phim Mui Ten De Di Chuyen";

	gotoXY(78, 28); TextColor(76); cout << "        ";
	gotoXY(78, 29); TextColor(78); cout << "  CHON  ";
	gotoXY(78, 30); TextColor(76); cout << "        ";
	gotoXY(78, 31); TextColor(79); cout << "  Enter ";
	gotoXY(87, 30); TextColor(14); cout << "Bam Phim Enter De Chon Thao Tac";

	gotoXY(78, 34); TextColor(76); cout << "        ";
	gotoXY(78, 35); TextColor(78); cout << "  THOAT ";
	gotoXY(78, 36); TextColor(76); cout << "        ";
	gotoXY(78, 37); TextColor(79); cout << "   ESC  ";
	gotoXY(87, 36); TextColor(14); cout << "Bam Phim ESC De Quay Lai Hoac Thoat";
	gotoXY(0, 0);
}
void xoa_hien_thi_huong_dan()
{
	int x = whereX();
	int y = whereY();
	TextColor(7);
	for (int i = 1; i <= 40; i++)
	{
		gotoXY(60, i); cout << "                                                                      ";
	}
	xoa_hien_thi_1_Button(78, 28);
	xoa_hien_thi_1_Button(78, 34);
	gotoXY(x, y);
}
void Box_NhapDG()
{
	ButtonEnter(boxx + boxs - 5, boxy + 15);
	ButtonESC(boxx, boxy + 15);
	TextColor(15);
	gotoXY(boxx, boxy); cout << char(201);
	for (int i = 1; i < boxs + 1; i++) cout << char(205);
	cout << char(187);
	gotoXY(boxx, boxy + 1); cout << char(186);
	gotoXY(boxx + boxs + 1, boxy + 1); cout << char(186);
	gotoXY(boxx, boxy + 2); cout << char(186) << " Ma DG: ";
	gotoXY(boxx + boxs + 1, boxy + 2); cout << char(186);
	gotoXY(boxx, boxy + 3); cout << char(186);
	gotoXY(boxx + boxs + 1, boxy + 3); cout << char(186);
	gotoXY(boxx, boxy + 4); cout << char(186) << " Nhap Ho: ";
	gotoXY(boxx + boxs + 1, boxy + 4); cout << char(186);
	gotoXY(boxx, boxy + 5); cout << char(186);
	gotoXY(boxx + boxs + 1, boxy + 5); cout << char(186);
	gotoXY(boxx, boxy + 6); cout << char(186) << " Nhap Ten: ";
	gotoXY(boxx + boxs + 1, boxy + 6); cout << char(186);
	gotoXY(boxx, boxy + 7); cout << char(186);
	gotoXY(boxx + boxs + 1, boxy + 7); cout << char(186);
	gotoXY(boxx, boxy + 8); cout << char(186) << " Nhap Phai: ";
	gotoXY(boxx + boxs + 1, boxy + 8); cout << char(186);
	gotoXY(boxx, boxy + 9); cout << char(186);
	gotoXY(boxx + boxs + 1, boxy + 9); cout << char(186);
	gotoXY(boxx, boxy + 10); cout << char(186) << " Trang thai the: ";
	gotoXY(boxx + boxs + 1, boxy + 10); cout << char(186);
	gotoXY(boxx, boxy + 11); cout << char(200);
	for (int i = 1; i < boxs + 1; i++) cout << char(205);
	cout << char(188);
}
void xoa_hien_thi_Box_NhapDG()
{
	int x = whereX(), y = whereY();
	TextColor(15);
	gotoXY(boxx, boxy); cout << " ";
	for (int i = 1; i < boxs + 1; i++) cout << " ";
	cout << " ";
	gotoXY(boxx, boxy + 1); cout << " ";
	gotoXY(boxx + boxs + 1, boxy + 1); cout << " ";
	gotoXY(boxx, boxy + 2); cout << "                                      ";
	gotoXY(boxx + boxs + 1, boxy + 2); cout << " ";
	gotoXY(boxx, boxy + 3); cout << " ";
	gotoXY(boxx + boxs + 1, boxy + 3); cout << " ";
	gotoXY(boxx, boxy + 4); cout << "                                      ";
	gotoXY(boxx + boxs + 1, boxy + 4); cout << " ";
	gotoXY(boxx, boxy + 5); cout << " ";
	gotoXY(boxx + boxs + 1, boxy + 5); cout << " ";
	gotoXY(boxx, boxy + 6); cout << "                                      ";
	gotoXY(boxx + boxs + 1, boxy + 6); cout << " ";
	gotoXY(boxx, boxy + 7); cout << " ";
	gotoXY(boxx + boxs + 1, boxy + 7); cout << " ";
	gotoXY(boxx, boxy + 8); cout << "                                      ";
	gotoXY(boxx + boxs + 1, boxy + 8); cout << " ";
	gotoXY(boxx, boxy + 9); cout << " ";
	gotoXY(boxx + boxs + 1, boxy + 9); cout << " ";
	gotoXY(boxx, boxy + 10); cout << "                                      ";
	gotoXY(boxx + boxs + 1, boxy + 10); cout << " ";
	gotoXY(boxx, boxy + 11); cout << " ";
	for (int i = 1; i < boxs + 1; i++) cout << " ";
	cout << " ";
	gotoXY(x, y);
}
void Box_NhapDS()
{
	ButtonEnter(boxx + boxs - 5, boxy + 15);
	ButtonESC(boxx, boxy + 15);
	TextColor(15);
	gotoXY(boxx, boxy); cout << char(201);
	for (int i = 1; i < boxs + 1; i++) cout << char(205);
	cout << char(187);
	gotoXY(boxx, boxy + 1); cout << char(186);
	gotoXY(boxx + boxs + 1, boxy + 1); cout << char(186);
	gotoXY(boxx, boxy + 2); cout << char(186) << " ISBN: ";
	gotoXY(boxx + boxs + 1, boxy + 2); cout << char(186);
	gotoXY(boxx, boxy + 3); cout << char(186);
	gotoXY(boxx + boxs + 1, boxy + 3); cout << char(186);
	gotoXY(boxx, boxy + 4); cout << char(186) << " Ten Sach: ";
	gotoXY(boxx + boxs + 1, boxy + 4); cout << char(186);
	gotoXY(boxx, boxy + 5); cout << char(186);
	gotoXY(boxx + boxs + 1, boxy + 5); cout << char(186);
	gotoXY(boxx, boxy + 6); cout << char(186) << " So Trang: ";
	gotoXY(boxx + boxs + 1, boxy + 6); cout << char(186);
	gotoXY(boxx, boxy + 7); cout << char(186);
	gotoXY(boxx + boxs + 1, boxy + 7); cout << char(186);
	gotoXY(boxx, boxy + 8); cout << char(186) << " Tac Gia: ";
	gotoXY(boxx + boxs + 1, boxy + 8); cout << char(186);
	gotoXY(boxx, boxy + 9); cout << char(186);
	gotoXY(boxx + boxs + 1, boxy + 9); cout << char(186);
	gotoXY(boxx, boxy + 10); cout << char(186) << " Nam XB: ";
	gotoXY(boxx + boxs + 1, boxy + 10); cout << char(186);
	gotoXY(boxx, boxy + 11); cout << char(186);
	gotoXY(boxx + boxs + 1, boxy + 11); cout << char(186);
	gotoXY(boxx, boxy + 12); cout << char(186) << " The Loai: ";
	gotoXY(boxx + boxs + 1, boxy + 12); cout << char(186);
	gotoXY(boxx, boxy + 13); cout << char(200);
	for (int i = 1; i < boxs + 1; i++) cout << char(205);
	cout << char(188);
}
void xoa_hien_thi_Box_NhapDS()
{
	int x = whereX(), y = whereY();
	TextColor(15);
	gotoXY(boxx, boxy); cout << " ";
	for (int i = 1; i < boxs + 1; i++) cout << " ";
	cout << " ";
	gotoXY(boxx, boxy + 1); cout << " ";
	gotoXY(boxx + boxs + 1, boxy + 1); cout << " ";
	gotoXY(boxx, boxy + 2); cout << "                                            ";
	gotoXY(boxx + boxs + 1, boxy + 2); cout << " ";
	gotoXY(boxx, boxy + 3); cout << " ";
	gotoXY(boxx + boxs + 1, boxy + 3); cout << " ";
	gotoXY(boxx, boxy + 4); cout << "                                            ";
	gotoXY(boxx + boxs + 1, boxy + 4); cout << " ";
	gotoXY(boxx, boxy + 5); cout << " ";
	gotoXY(boxx + boxs + 1, boxy + 5); cout << " ";
	gotoXY(boxx, boxy + 6); cout << "                                            ";
	gotoXY(boxx + boxs + 1, boxy + 6); cout << " ";
	gotoXY(boxx, boxy + 7); cout << " ";
	gotoXY(boxx + boxs + 1, boxy + 7); cout << " ";
	gotoXY(boxx, boxy + 8); cout << "                                            ";
	gotoXY(boxx + boxs + 1, boxy + 8); cout << " ";
	gotoXY(boxx, boxy + 9); cout << " ";
	gotoXY(boxx + boxs + 1, boxy + 9); cout << " ";
	gotoXY(boxx, boxy + 10); cout << "                                            ";
	gotoXY(boxx + boxs + 1, boxy + 10); cout << " ";
	gotoXY(boxx, boxy + 11); cout << " ";
	gotoXY(boxx + boxs + 1, boxy + 11); cout << " ";
	gotoXY(boxx, boxy + 12); cout << "                                            ";
	gotoXY(boxx + boxs + 1, boxy + 12); cout << " ";
	gotoXY(boxx, boxy + 13); cout << " ";
	for (int i = 1; i < boxs + 1; i++) cout << " ";
	cout << " ";
	gotoXY(x, y);
}
void Box_NhapSach()
{
	int boxtemp = boxs - 40;
	ButtonEnter(boxx + boxtemp - 5, boxy + 15);
	ButtonESC(boxx, boxy + 15);
	TextColor(15);
	gotoXY(boxx, boxy); cout << char(201);
	for (int i = 1; i < boxtemp + 1; i++) cout << char(205);
	cout << char(187);
	gotoXY(boxx, boxy + 1); cout << char(186);
	gotoXY(boxx + boxtemp + 1, boxy + 1); cout << char(186);
	gotoXY(boxx, boxy + 2); cout << char(186) << " MA SACH: ";
	gotoXY(boxx + boxtemp + 1, boxy + 2); cout << char(186);
	gotoXY(boxx, boxy + 3); cout << char(186);
	gotoXY(boxx + boxtemp + 1, boxy + 3); cout << char(186);
	gotoXY(boxx, boxy + 4); cout << char(186) << " VI TRI: ";
	gotoXY(boxx + boxtemp + 1, boxy + 4); cout << char(186);
	gotoXY(boxx, boxy + 5); cout << char(186);
	gotoXY(boxx + boxtemp + 1, boxy + 5); cout << char(186);
	gotoXY(boxx, boxy + 6); cout << char(200);
	for (int i = 1; i < boxtemp + 1; i++) cout << char(205);
	cout << char(188);
}
void xoa_hien_thi_Box_NhapSach()
{
	int x = whereX(), y = whereY();
	int boxtemp = boxs - 40;
	xoa_hien_thi_1_Button(boxx + boxtemp - 5, boxy + 15);
	xoa_hien_thi_1_Button(boxx, boxy + 15);
	TextColor(15);
	gotoXY(boxx, boxy); cout << " ";
	for (int i = 1; i < boxtemp + 1; i++) cout << " ";
	cout << " ";
	gotoXY(boxx, boxy + 1); cout << " ";
	gotoXY(boxx + boxtemp + 1, boxy + 1); cout << " ";
	gotoXY(boxx, boxy + 2); cout << "            ";
	gotoXY(boxx + boxtemp + 1, boxy + 2); cout << " ";
	gotoXY(boxx, boxy + 3); cout << " ";
	gotoXY(boxx + boxtemp + 1, boxy + 3); cout << " ";
	gotoXY(boxx, boxy + 4); cout << "          ";
	gotoXY(boxx + boxtemp + 1, boxy + 4); cout << " ";
	gotoXY(boxx, boxy + 5); cout << " ";
	gotoXY(boxx + boxtemp + 1, boxy + 5); cout << " ";
	gotoXY(boxx, boxy + 6); cout << " ";
	for (int i = 1; i < boxtemp + 1; i++) cout << " ";
	cout << " ";
	gotoXY(x, y);
}
// Boxx + 20 Boxy =15
void Box_NHAP(string x)
{
	int tungdo = 15;
	int boxtemp = 50;
	TextColor(252);
	gotoXY(boxx + 20, tungdo); cout << char(201);
	for (int i = 1; i < boxtemp + 1; i++) cout << char(205);
	cout << char(187);
	TextColor(252);
	gotoXY(boxx + 20, tungdo + 1); cout << "                                                    ";
	gotoXY(boxx + 20, tungdo + 1); cout << char(186);
	gotoXY(boxx + 20 + boxtemp + 1, tungdo + 1);  cout << char(186);
	gotoXY(boxx + 20, tungdo + 2); cout << "                                                    ";
	gotoXY(boxx + 20, tungdo + 2); cout << char(186); TextColor(249); cout << x << ": ";
	int x1 = whereX(), y1 = whereY();
	TextColor(252);
	gotoXY(boxx + 20 + boxtemp + 1, tungdo + 2); cout << char(186);
	gotoXY(boxx + 20, tungdo + 3); TextColor(252); cout << "          ENTER:CHON        ESC:THOAT               ";
	gotoXY(boxx + 20, tungdo + 3); cout << char(186);
	gotoXY(boxx + 20 + boxtemp + 1, tungdo + 3); cout << char(186);
	gotoXY(boxx + 20, tungdo + 4); cout << char(200);
	for (int i = 1; i < boxtemp + 1; i++) cout << char(205);
	cout << char(188);
	TextColor(15);
	gotoXY(x1, y1);
}
void Xoa_hien_thi_Box_NHAP()
{
	int x = whereX();
	int y = whereY();
	int tungdo = 15;
	int boxtemp = 50;
	TextColor(7);
	gotoXY(boxx + 20, tungdo); cout << " ";
	for (int i = 1; i < boxtemp + 1; i++) cout << " ";
	cout << " ";
	TextColor(7);
	gotoXY(boxx + 20, tungdo + 1); cout << "                                                    ";
	gotoXY(boxx + 20, tungdo + 1); cout << " ";
	gotoXY(boxx + 20 + boxtemp + 1, tungdo + 1);  cout << " ";
	gotoXY(boxx + 20, tungdo + 2); cout << "                                                    ";
	gotoXY(boxx + 20, tungdo + 2); cout << "                                                    ";
	gotoXY(boxx + 20 + boxtemp + 1, tungdo + 2); cout << " ";
	gotoXY(boxx + 20, tungdo + 3); cout << "                                                    ";
	gotoXY(boxx + 20, tungdo + 3); cout << " ";
	gotoXY(boxx + 20 + boxtemp + 1, tungdo + 3); cout << " ";
	gotoXY(boxx + 20, tungdo + 4); cout << " ";
	for (int i = 1; i < boxtemp + 1; i++) cout << " ";
	cout << " ";
	gotoXY(x, y);
}
void chay_chu(int x, int y, const char* s)
{
	int x1 = whereX(), y1 = whereY();
	int n = strlen(s);
	for (int i = x; i <= x + n && !_kbhit(); i++)
	{
		gotoXY(i, y); cout << s;
		Sleep(150);
		gotoXY(i, y); cout << " ";
		if (i == x + n) {
			i = x;
			ClearLine(i, y);
		}
	}
	gotoXY(x1, y1);
}
bool xac_nhan(int x, int y, const char* s, string temp)
{
	char c;
	Box_NHAP(s + temp);
	TextColor(249);
	gotoXY(x + 25, y + 2);
	cout << "CO";
	gotoXY(x + 30, y + 2);
	cout << "HUY";
	while (1)
	{
		gotoXY(x + 25, y + 2); TextColor(252); cout << "CO";
		gotoXY(x + 30, y + 2); TextColor(247); cout << "HUY";
		c = _getch();
		if (c == 13) {
			Xoa_hien_thi_Box_NHAP();
			return true;
		}
		else if (c == 27)
		{
			Xoa_hien_thi_Box_NHAP();
			return false;
		}
		if (c == -32) c = _getch();
		if (c == 77 || c == 75)
		{
			gotoXY(x + 25, y + 2); TextColor(247); cout << "CO";
			gotoXY(x + 30, y + 2); TextColor(252); cout << "HUY";
			c = _getch(); if (c == -32) c = _getch();
			if (c == 13 || c == 27) {
				Xoa_hien_thi_Box_NHAP();
				return false;
			}
		}
	}
}
void intro()
{
	control_cursor(false);
	ifstream fi("introduce.txt");
	string s;
	int y = 1;
	int j = 0;
	while (!fi.eof())
	{
		if (y < 18)
		TextColor(11);
		else 
		TextColor(15);
		getline(fi, s);
		gotoXY(50, y++);
		cout << s;
	}
	fi.close();
	gotoXY(70, 38); TextColor(10); cout << "HOC VIEN CONG NGHE BUU CHINH VIEN THONG HCM";
	for (int i = 0; i <= 100; i++)
	{
		if (i >= 85)
			j = 200 + rand() % 401;
		else j = i + 20;
		Sleep(j);
		TextColor(252);
		gotoXY(89, 40); cout << i << "%";
		TextColor(252);
		gotoXY(i + 43, 40);
		cout << " ";
	}
	for (int i = 0; i <= 100; i++)
	{
		TextColor(7);
		gotoXY(i + 40, 40); cout << "      ";
	}
	PlaySound(TEXT("1.wav"), GetModuleHandle(NULL), SND_FILENAME);
	while (!_kbhit())
	{
		Sleep(200);
		j = rand() % 15 + 1;
		TextColor(j);
		gotoXY(78, 42); cout << "PRESS ANY KEY TO CONTINUE";
	}
	while (_kbhit()) _getch();
}
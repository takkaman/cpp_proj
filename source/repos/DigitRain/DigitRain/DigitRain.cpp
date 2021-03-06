// DigitRain.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#include <Mmsystem.h>

#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "winmm.lib")

#define ID_TIMER    1
#define STRMAXLEN  25 //一个显示列的最大长度
#define STRMINLEN  8  //一个显示列的最小长度
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
typedef struct tagCharChain //整个当作屏幕的一个显示列,这是个双向列表
{
	struct tagCharChain *prev; //链表的前个元素
	TCHAR  ch;                  //一个显示列中的一个字符
	struct tagCharChain *next; //链表的后个元素
}CharChain, *pCharChain;
typedef struct tagCharColumn
{
	CharChain *head, *current, *point;
	int x, y, iStrLen; //显示列的开始显示的x,y坐标,iStrLen是这个列的长度
	int iStopTimes, iMustStopTimes; //已经停滞的次数和必须停滞的次数,必须停滞的次数是随机的
}CharColumn, *pCharColumn;
int main(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR szCmdLine, int iCmdShow)
{
	static TCHAR szAppName[] = TEXT("matrix");
	HWND            hwnd;
	MSG            msg;
	WNDCLASS    wndclass;
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szAppName;
	if (!RegisterClass(&wndclass))
	{
		MessageBox(NULL, TEXT("此程序必须运行在NT下!"), szAppName, MB_ICONERROR);
		return 0;
	}
	hwnd = CreateWindow(szAppName, NULL,
		WS_DLGFRAME | WS_THICKFRAME | WS_POPUP,
		0, 0,
		GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN),
		NULL, NULL, hInstance,
		NULL);
	ShowWindow(hwnd, SW_SHOWMAXIMIZED); //最大化显示
	UpdateWindow(hwnd);
	ShowCursor(FALSE); //隐藏鼠标光标

	srand((int)GetCurrentTime()); //初始化随机数发生器
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	ShowCursor(TRUE); //显示鼠标光标

	return msg.wParam;
}
TCHAR randomChar() //随机字符产生函数
{
	// TCHAR wc = L'这';
	return (TCHAR)(rand() % (126 - 33) + 33); //33到126之间
}

int init(CharColumn *cc, int cyScreen, int x) //初始化
{
	int j;
	// Leo hard code rain string
	// start time: 2017.5.7.18:00:00
	TCHAR rainStr[] = L"张诚 与 许玉萍 在一起的第333天09小时23分钟23秒      ";
	rainStr[14] = 5;
	cc->iStrLen = wcslen(rainStr); //显示列的长度(每段数字雨的长度）Leo hard code to target string length
	cc->x = x + 3;        //显示列的开始显示的x坐标
	cc->y = rand() % 3 ? rand() % cyScreen : 0; //显示列的开始显示的y坐标
	cc->iMustStopTimes = rand() % 6;
	cc->iStopTimes = 0;
	cc->head = cc->current =
		(pCharChain)calloc(cc->iStrLen, sizeof(CharChain)); //生成显示列
	for (j = 0; j<cc->iStrLen - 1; j++)
	{
		cc->current->prev = cc->point; //cc->point一个显示列的前个元素
		cc->current->ch = '\0';
		cc->current->next = cc->current + 1; //cc->current+1一个显示列的后个元素
		cc->point = cc->current++; //cc->point = cc->current; cc->current++;
	}
	cc->current->prev = cc->point; //最后一个节点
	cc->current->ch = '\0';
	cc->current->next = cc->head;
	cc->head->prev = cc->current; //头节点的前一个为此链的最后一个元素
	cc->current = cc->point = cc->head; //free掉申请的内存要用current当参数
	cc->head->ch = randomChar(); // 对链表头的元素填充
	return 0;
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC          hdc;
	//ctn 用来确定一个显示链是否 向下前进,如果等待次数超过必须等待的次数,ctn就代表要向下前进
	int i, j, temp, ctn; //j为一个显示链中除链表头外的在屏幕上显示的y坐标,temp绿色过度到黑色之用
	static  HDC hdcMem;
	// Leo hard code text content here
	const static int lineNum = 33, delayNum = 30;
	const static TCHAR *myName[] = { 
		L"  这是一个我特意为你准备的惊喜！", 
		L" ", 
		L"当我打开这个程序，按下编译的按钮！", 
		L"那么此时此刻,我的妻子许玉萍，肯定已经站在了我的对面！",
		L"当我再一次打开这个程序，按下编译的按钮！",
		L"我希望，那是在我生命快结束的时刻，到那时我会说，这一生能够遇到你真好！",
		L"爱情是神奇又美妙的，我是幸运又幸福的!",
		L"因为是你为我编织了它!",
		L"缘靠天定，分靠人为！因为缘分我们相遇了，也因为缘分我们相爱了！",
		L"我知道，你是我一辈子要爱的人，我会牵着你的手，走到满头白发的那一天！",
		L"我会守护你生命里的每一个精彩瞬间，并陪伴你一路精彩下去。",
		L"你的幸福快乐，是我一生的追求。",
		L"不论贫穷富贵，我都愿意为你遮风挡雨！",
		L"我会每一天都带着笑脸，和你说早安！",
		L"我也会每一晚，再入梦香前，与你道声晚安！",
		L"我会带你去所有你想去的地方，",
		L"陪着你闹，看着你笑！",
		L"历经你生命中所有的点点滴滴。",
		L"我期待这一生与你一起走过！",
		L"我期待与你慢慢变老！",
		L"等我们老到哪儿也去不了，",
		L"还能满载着一生的幸福快乐 ！",
		L"我会为我们的未来撑起一片天空，",
		L"为我们的将来担负起一生的责任，",
		L"所有我们经历的点点滴滴，都是我们一辈子最美的回忆。",
		L"我愿意爱你直到老去！",
		L" ",
		L"这是一个我为你精心编写的C语言程序！这个特殊的程序，我用VS2017在空闲的时间断断续续编写了近半年。",
		L"我很开心的是，这个程序在我们结婚前终于完成了！",
		L"它会记录下我们从刚认识的那一天开始，到今后我们在一起的每一分，每一秒！",
		L"不管记录的这段时间内我们是开心还是不开心！张诚都会向许玉萍和爸爸妈妈保证，张诚会用一辈子的时间来好好对待许玉萍！",
		L"我爱你，也因为爱是相互的，相信你也会一样的对我！",
		L"所以如果你也同样愿意的话，那么这个程序，就由你来启动吧！",
	};
	// Leo hard code rain string
	static TCHAR rainStr[] = L"秒32钟分32时小90天333第的起一在 萍玉许 与 诚张      ";

	static int k=0, l=0, txtLen = wcslen(myName[0]);
	static HFONT    hFontRain, hFontTxt;
	static  HBITMAP hBitmap;
	static  int cxScreen, cyScreen; //屏幕的宽度 高度.
	static  int iFontWidth = 10, iFontHeight = 15, iColumnCount; //字体的宽度 高度, 列数
	static  CharColumn *ccChain;
	static struct tm base, now;
	static struct tm *p, *q;   //tm结构指针
	static time_t t, diff_t;  //声明time_t类型变量
	static int day, hour, min, sec;
	static bool cont = true;
	
	switch (message)
	{
	case WM_CREATE:
		cxScreen = GetSystemMetrics(SM_CXSCREEN); //屏幕宽度
		cyScreen = GetSystemMetrics(SM_CYSCREEN);
		
		// SetTimer(hwnd, ID_TIMER, 1, NULL);
		SetTimer(hwnd, ID_TIMER, 250, NULL); // Leo: 这里设置文字部分的显示速度哦 把250调大，显示速度变慢
		hdc = GetDC(hwnd);
		hdcMem = CreateCompatibleDC(hdc);
		hBitmap = CreateCompatibleBitmap(hdc, cxScreen, cyScreen);
		SelectObject(hdcMem, hBitmap);
		ReleaseDC(hwnd, hdc);
		//k = txtLen + 2;
		//创建字体
		// Leo split font to 2 stages
		hFontRain = CreateFont(iFontHeight, iFontWidth - 5, 0, 0, FW_BOLD, 0, 0, 0,
			DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
			DRAFT_QUALITY, FIXED_PITCH | FF_SWISS, TEXT("Fixedsys"));
		// Leo：这里设置文字部分字体， 把第一个1.5调大，字体变高，第二个1.5调大，字体变宽
		hFontTxt = CreateFont(1.5*iFontHeight, 1.5*iFontWidth - 5, 0, 0, FW_BOLD, 0, 0, 0,
			DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
			DRAFT_QUALITY, FIXED_PITCH | FF_SWISS, TEXT("Fixedsys")); 
		//SelectObject(hdcMem, hFontRain);
		//DeleteObject(hFontRain);
		SetBkMode(hdcMem, TRANSPARENT); //设置背景模式为 透明
		iColumnCount = cxScreen / (iFontWidth * 3 / 2); //屏幕所显示字母雨的列数
		ccChain = (pCharColumn)calloc(iColumnCount, sizeof(CharColumn));
		for (i = 0; i<iColumnCount; i++)
		{
			init(ccChain + i, cyScreen, (iFontWidth * 3 / 2)*i);
		}
		// Leo added for sound playing
		PlaySoundW(TEXT("sound.wav"), NULL, SND_FILENAME | SND_ASYNC);
		// Leo 这里设置的是初始相遇时间，你应该不用改动
		// start time: 2017.5.7.18:00:00
		base.tm_year = 117;
		base.tm_mon = 4;
		base.tm_mday = 7;
		base.tm_hour = 18;
		base.tm_min = 0;
		base.tm_sec = 0;

		//now.tm_year += 1900;
		//now.tm_mon += 1;
		//printf("Year: %d, month: %d, day: %d\n", base.tm_year, base.tm_mon, base.tm_mday);
		//printf("Year: %d, month: %d, day: %d\n", now.tm_year, now.tm_mon, now.tm_mday);

		//printf("Now: %d\n", mktime(&now));
		//printf("Base: %d\n", mktime(&base));
		//printf("day: %d, hour: %d, min: %d, sec: %d", day, hour, min, sec);
		return 0;
	case WM_TIMER:
		time(&t);      //获取系统日期和时间
		localtime_s(&now, &t);
		diff_t = mktime(&now) - mktime(&base);
		printf("diff_t; %d", difftime);
		day = diff_t / 86400;
		hour = diff_t % 86400 / 3600;
		min = diff_t % 86400 % 3600 / 60;
		sec = diff_t % 86400 % 3600 % 60;

		rainStr[14] = day / 100 + '0';
		rainStr[13] = day % 100 / 10 + '0';
		rainStr[12] = day % 100 % 10 + '0';
		rainStr[10] = hour / 10 + '0';
		rainStr[9] = hour % 10 + '0';
		rainStr[6] = min / 10 + '0';
		rainStr[5] = min % 10 + '0';
		rainStr[2] = sec / 10 + '0';
		rainStr[1] = sec % 10 + '0';

		SelectObject(hdcMem, hFontRain);
		hdc = GetDC(hwnd);
		PatBlt(hdcMem, 0, 0, cxScreen, cyScreen, BLACKNESS); //将内存设备映像刷成黑色
		if (cont) {
			SetTimer(hwnd, ID_TIMER, 5, NULL);
			for (i = 0; i < iColumnCount; i++)
			{
				ctn = (ccChain + i)->iStopTimes++ > (ccChain + i)->iMustStopTimes;
				//
				(ccChain + i)->point = (ccChain + i)->head; //point用于遍历整个显示列

															//第一个字符显示为 白色
				SetTextColor(hdcMem, RGB(255, 255, 255));

				TextOut(hdcMem, (ccChain + i)->x, (ccChain + i)->y, &((ccChain + i)->point->ch), 1);
				j = (ccChain + i)->y;
				(ccChain + i)->point = (ccChain + i)->point->next;
				//遍历整个显示列,将这个显示列里的字符从下往上显示
				temp = 0; //temp白色过度到黑色之用
				while ((ccChain + i)->point != (ccChain + i)->head && (ccChain + i)->point->ch)
				{
					// Leo set the text color to all white and fade out to black
					SetTextColor(hdcMem, RGB(255 - (255 * (temp) / (ccChain + i)->iStrLen), 255 - (255 * (temp) / (ccChain + i)->iStrLen), 255 - (255 * (temp) / (ccChain + i)->iStrLen)));
					TCHAR output = rainStr[temp+1];
					TextOut(hdcMem, (ccChain + i)->x, j -= iFontHeight, &(output), 1);
					temp++;
					(ccChain + i)->point = (ccChain + i)->point->next;
				}
				if (ctn)
					(ccChain + i)->iStopTimes = 0;
				else continue;
				(ccChain + i)->y += iFontHeight; //下次开始显示的y坐标为当前的y坐标加上 一个字符的高度
												 //如果开始显示的y坐标减去 整个显示列的长度超过了屏幕的高度
				if ((ccChain + i)->y - (ccChain + i)->iStrLen*iFontHeight > cyScreen)
				{
					free((ccChain + i)->current);
					init(ccChain + i, cyScreen, (iFontWidth * 3 / 2)*i);
				}
				//链表的头 为此链表的前个元素,因为下次开始显示的时候 就相当与在整个显示列的开头添加个元素,然后在开始往上显示
				(ccChain + i)->head = (ccChain + i)->head->prev;
				(ccChain + i)->head->ch = rainStr[0];
				//int loc = 0;
				//tagCharChain *ptagCharChain = (ccChain + i)->head;
				//while (ptagCharChain->next != (ccChain + i)->head) {
				//	ptagCharChain->ch = rainStr[loc];
				//	loc++;
				//	ptagCharChain = ptagCharChain->prev;
				//}
			}
		}
		else {
			// Leo：这里设置文字部分每一行或者每几行的文字显示速度，l是行号，从0开始
			if (l == 1 || l == 26) {
				SetTimer(hwnd, ID_TIMER, 5, NULL);
			}
			else if (l < 6) {
				SetTimer(hwnd, ID_TIMER, 235, NULL);
			}
			else if (l >= 6 && l <=8) {
				SetTimer(hwnd, ID_TIMER, 270, NULL);
			}
			else if (l >= 9 && l <= 13) {
				SetTimer(hwnd, ID_TIMER, 260, NULL);
			}
			else if (l >= 14 && l <= 18) {
				SetTimer(hwnd, ID_TIMER, 255, NULL);
			}
			else if (l >= 19 && l <= 26) {
				SetTimer(hwnd, ID_TIMER, 230, NULL);
			}
			else if (l == 27) {
				SetTimer(hwnd, ID_TIMER, 270, NULL);
			}
			else if (l == 28) {
				SetTimer(hwnd, ID_TIMER, 275, NULL);
			}
			else if (l >= 29 && l <= 31) {
				SetTimer(hwnd, ID_TIMER, 290, NULL);
			}
			else if (l == 32) {
				SetTimer(hwnd, ID_TIMER, 260, NULL);
			}
			if (l < lineNum) {
				SelectObject(hdcMem, hFontTxt);
				SetTextColor(hdcMem, RGB(255, 255, 255));
				for (int n = 0; n < l; n++) {
					int len = wcslen(myName[n]);
					TextOut(hdcMem, 10, 10 + 32 * n, myName[n], len);
				}
				TextOut(hdcMem, 10, 10 + 32 * l, myName[l], k);
				k++;
				if (k > txtLen) {
					l++;
					k = 0;
					if (l < lineNum) {
						txtLen = wcslen(myName[l]);
					}
				}
			}
			else {
				// Leo set interval between text phase and rain phase
				SelectObject(hdcMem, hFontTxt);
				SetTextColor(hdcMem, RGB(255, 255, 255));
				for (int n = 0; n < lineNum; n++) {
					int len = wcslen(myName[n]);
					TextOut(hdcMem, 10, 10 + 32 * n, myName[n], len);
				}
			}
		}

		BitBlt(hdc, 0, 0, cxScreen, cyScreen, hdcMem, 0, 0, SRCCOPY);
		ReleaseDC(hwnd, hdc);
		return 0;
	case WM_RBUTTONDOWN:
		KillTimer(hwnd, ID_TIMER);
		return 0;
	case WM_RBUTTONUP:
		SetTimer(hwnd, ID_TIMER, 10, NULL);
		return 0;
		//处理善后工作
	case WM_KEYDOWN:
		switch (wParam) {
		case VK_SPACE: // Leo：按空格继续显示数字雨部分
			cont = true;
			break;
		}
		return 0;
	case WM_LBUTTONDOWN:
	case WM_DESTROY:
		KillTimer(hwnd, ID_TIMER);
		DeleteObject(hBitmap);
		DeleteDC(hdcMem);
		for (i = 0; i<iColumnCount; i++)
		{
			free((ccChain + i)->current);
		}
		free(ccChain);
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}


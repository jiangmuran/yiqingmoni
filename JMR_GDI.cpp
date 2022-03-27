#include <Windows.h>

HWND _hWnd; // 窗口句柄变量
HDC _hDc; // 窗口DC句柄变量




void JGetHandle() // 获得相关句柄，只在库内部使用，如果要使用本库中的大部分函数，都需要先执行此函数。
{
	_hWnd = GetConsoleWindow(); // 取得控制台句柄
	_hDc = GetDC(_hWnd); // 关联DC到控制台

}

HPEN JCreatePen(int PenWidth,COLORREF PenRGB) // 这个函数用来设置笔的宽度和颜色
{
     HPEN _hPen = CreatePen(0, PenWidth, PenRGB); // 创建一个画笔
     return _hPen;
}


HBRUSH JCreateBrush(COLORREF BrushRGB) // 这个函数用来设置笔刷的颜色.
{
 
    
    HBRUSH _hBrush = CreateSolidBrush(BrushRGB); // 创建一个笔刷
    return _hBrush;
}

void JBindOBJ(HGDIOBJ OBJ)
{
    SelectObject(_hDc, OBJ);
}


void JGetScreenXY(int& return_x, int& return_y) // 获得显示器的像素点长宽,由于直接传入用来接受的变量，所以不需要返回值。
{
	return_x = GetSystemMetrics(SM_CXSCREEN); // 调用WindowsAPI，获得屏幕长度
	return_y = GetSystemMetrics(SM_CYSCREEN); // 调用WindowsAPI，获得屏幕高度
	
}

void JFullScreen(int x_len, int y_len) // 本函数用来将窗口设为全屏，接受两个参数分别是显示器的长和宽（可参考get_screenxy函数）
{
    LONG I_WinStyle = GetWindowLong(_hWnd, GWL_STYLE); //获取当前窗口信息
    SetWindowLong(
        
        _hWnd,
        GWL_STYLE,
        (I_WinStyle | WS_POPUP | WS_MAXIMIZE)
        & ~WS_CAPTION & ~WS_THICKFRAME & ~WS_BORDER
    ); // 设置当前窗口去掉边框等
    SetWindowPos(_hWnd, HWND_TOP, 0, 0, x_len, y_len, 0); // 设置窗口大小
}



void JDrawCircle(int x,int y,int d) // 这个函数传入坐标和直径（像素点），就能画出一个正圆。
{
    Ellipse(_hDc, x, y, x + d, y + d);
}

void JDrawSmallPoint(int x, int y, COLORREF ColorRGB) // 画一个像素点，非常小。传入xy坐标和颜色。
{
    SetPixel(_hDc, x, y, ColorRGB); // 画一个点，没有别的
}

void JDrawFA(int x1, int y1, int x2, int y2) // 画一个四边形，传入两个对角的坐标
{
    Rectangle(_hDc, x1, y1, x2, y2);
}

void JDrawLine(int x1,int y1,int x2,int y2) // 画一条线段，给出两个顶点的坐标
{
    MoveToEx(_hDc, x1, y1, NULL); //设定画线起点
    LineTo(_hDc, x2, y2); //画线
}

/// <summary>
/// 这个函数设置文字背景颜色和文字本身颜色
/// </summary>
/// <param name="BackgrundColor">背景颜色</param>
/// <param name="TextColor">文字颜色</param>
void JSetTextColor(COLORREF BackgrundColor, COLORREF TextColor)
{
    SetTextColor(_hDc, TextColor); //设置字体颜色
    SetBkColor(_hDc, BackgrundColor); //设置文字背景色
}

/// <summary>
/// 这个函数用来显示文字。
/// </summary>
/// <param name="Text">文字内容</param>
/// <param name="TextLen">文字长度</param>
/// <param name="x">起始x坐标</param>
/// <param name="y">起始y坐标</param>
void JShowText(LPCWSTR Text, int TextLen, int x, int y) 
{
    TextOut(_hDc, x, y, Text, TextLen);
}


/// <summary>
/// 这个函数用来释放GDI耗费的资源
/// </summary>
void JDeleteDCScreen()
{
    DeleteObject(_hDc); // 删除dc句柄
}


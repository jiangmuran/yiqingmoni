#include <Windows.h>

HWND _hWnd; // ���ھ������
HDC _hDc; // ����DC�������




void JGetHandle() // �����ؾ����ֻ�ڿ��ڲ�ʹ�ã����Ҫʹ�ñ����еĴ󲿷ֺ���������Ҫ��ִ�д˺�����
{
	_hWnd = GetConsoleWindow(); // ȡ�ÿ���̨���
	_hDc = GetDC(_hWnd); // ����DC������̨

}

HPEN JCreatePen(int PenWidth,COLORREF PenRGB) // ��������������ñʵĿ�Ⱥ���ɫ
{
     HPEN _hPen = CreatePen(0, PenWidth, PenRGB); // ����һ������
     return _hPen;
}


HBRUSH JCreateBrush(COLORREF BrushRGB) // ��������������ñ�ˢ����ɫ.
{
 
    
    HBRUSH _hBrush = CreateSolidBrush(BrushRGB); // ����һ����ˢ
    return _hBrush;
}

void JBindOBJ(HGDIOBJ OBJ)
{
    SelectObject(_hDc, OBJ);
}


void JGetScreenXY(int& return_x, int& return_y) // �����ʾ�������ص㳤��,����ֱ�Ӵ����������ܵı��������Բ���Ҫ����ֵ��
{
	return_x = GetSystemMetrics(SM_CXSCREEN); // ����WindowsAPI�������Ļ����
	return_y = GetSystemMetrics(SM_CYSCREEN); // ����WindowsAPI�������Ļ�߶�
	
}

void JFullScreen(int x_len, int y_len) // ������������������Ϊȫ�����������������ֱ�����ʾ���ĳ��Ϳ��ɲο�get_screenxy������
{
    LONG I_WinStyle = GetWindowLong(_hWnd, GWL_STYLE); //��ȡ��ǰ������Ϣ
    SetWindowLong(
        
        _hWnd,
        GWL_STYLE,
        (I_WinStyle | WS_POPUP | WS_MAXIMIZE)
        & ~WS_CAPTION & ~WS_THICKFRAME & ~WS_BORDER
    ); // ���õ�ǰ����ȥ���߿��
    SetWindowPos(_hWnd, HWND_TOP, 0, 0, x_len, y_len, 0); // ���ô��ڴ�С
}



void JDrawCircle(int x,int y,int d) // ����������������ֱ�������ص㣩�����ܻ���һ����Բ��
{
    Ellipse(_hDc, x, y, x + d, y + d);
}

void JDrawSmallPoint(int x, int y, COLORREF ColorRGB) // ��һ�����ص㣬�ǳ�С������xy�������ɫ��
{
    SetPixel(_hDc, x, y, ColorRGB); // ��һ���㣬û�б��
}

void JDrawFA(int x1, int y1, int x2, int y2) // ��һ���ı��Σ����������Խǵ�����
{
    Rectangle(_hDc, x1, y1, x2, y2);
}

void JDrawLine(int x1,int y1,int x2,int y2) // ��һ���߶Σ������������������
{
    MoveToEx(_hDc, x1, y1, NULL); //�趨�������
    LineTo(_hDc, x2, y2); //����
}

/// <summary>
/// ��������������ֱ�����ɫ�����ֱ�����ɫ
/// </summary>
/// <param name="BackgrundColor">������ɫ</param>
/// <param name="TextColor">������ɫ</param>
void JSetTextColor(COLORREF BackgrundColor, COLORREF TextColor)
{
    SetTextColor(_hDc, TextColor); //����������ɫ
    SetBkColor(_hDc, BackgrundColor); //�������ֱ���ɫ
}

/// <summary>
/// �������������ʾ���֡�
/// </summary>
/// <param name="Text">��������</param>
/// <param name="TextLen">���ֳ���</param>
/// <param name="x">��ʼx����</param>
/// <param name="y">��ʼy����</param>
void JShowText(LPCWSTR Text, int TextLen, int x, int y) 
{
    TextOut(_hDc, x, y, Text, TextLen);
}


/// <summary>
/// ������������ͷ�GDI�ķѵ���Դ
/// </summary>
void JDeleteDCScreen()
{
    DeleteObject(_hDc); // ɾ��dc���
}


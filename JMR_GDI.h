// ��������ұ�д��һЩGDIͼ�ο�


#include <Windows.h>


void JGetHandle(); // �����ؾ����ֻ�ڿ��ڲ�ʹ�ã����Ҫʹ�ñ����еĴ󲿷ֺ���������Ҫ��ִ�д˺�����

HPEN JCreatePen(int PenWidth, COLORREF PenRGB); // ��������������ñʵĿ�Ⱥ���ɫ

HBRUSH JCreateBrush(COLORREF BrushRGB); // ��������������ñ�ˢ����ɫ.

void JBindOBJ(HGDIOBJ OBJ); // ��

void JGetScreenXY(int& return_x, int& return_y); // �����ʾ�������ص㳤��,����ֱ�Ӵ����������ܵı��������Բ���Ҫ����ֵ��

void JFullScreen(int x_len, int y_len); // ������������������Ϊȫ�����������������ֱ�����ʾ���ĳ��Ϳ��ɲο�get_screenxy������

void JDrawCircle(int x, int y, int d); // ����������������ֱ�������ص㣩�����ܻ���һ����Բ��

void JDrawSmallPoint(int x, int y, COLORREF ColorRGB); // ��һ�����ص㣬�ǳ�С������xy�������ɫ��

void JDrawFA(int x1, int y1, int x2, int y2); // ��һ���ı��Σ����������Խǵ�����

void JDrawLine(int x1, int y1, int x2, int y2); // ��һ���߶Σ������������������

void JSetTextColor(COLORREF BackgrundColor, COLORREF TextColor); // ��������������ֱ�����ɫ�����ֱ�����ɫ

void JShowText(LPCWSTR Text, int TextLen, int x, int y); // �������������ʾ���֡�

void JDeleteDCScreen(); // ������������ͷ�GDI�ķѵ���Դ


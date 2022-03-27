// 这个库是我编写的一些GDI图形库


#include <Windows.h>


void JGetHandle(); // 获得相关句柄，只在库内部使用，如果要使用本库中的大部分函数，都需要先执行此函数。

HPEN JCreatePen(int PenWidth, COLORREF PenRGB); // 这个函数用来设置笔的宽度和颜色

HBRUSH JCreateBrush(COLORREF BrushRGB); // 这个函数用来设置笔刷的颜色.

void JBindOBJ(HGDIOBJ OBJ); // 绑定

void JGetScreenXY(int& return_x, int& return_y); // 获得显示器的像素点长宽,由于直接传入用来接受的变量，所以不需要返回值。

void JFullScreen(int x_len, int y_len); // 本函数用来将窗口设为全屏，接受两个参数分别是显示器的长和宽（可参考get_screenxy函数）

void JDrawCircle(int x, int y, int d); // 这个函数传入坐标和直径（像素点），就能画出一个正圆。

void JDrawSmallPoint(int x, int y, COLORREF ColorRGB); // 画一个像素点，非常小。传入xy坐标和颜色。

void JDrawFA(int x1, int y1, int x2, int y2); // 画一个四边形，传入两个对角的坐标

void JDrawLine(int x1, int y1, int x2, int y2); // 画一条线段，给出两个顶点的坐标

void JSetTextColor(COLORREF BackgrundColor, COLORREF TextColor); // 这个函数设置文字背景颜色和文字本身颜色

void JShowText(LPCWSTR Text, int TextLen, int x, int y); // 这个函数用来显示文字。

void JDeleteDCScreen(); // 这个函数用来释放GDI耗费的资源


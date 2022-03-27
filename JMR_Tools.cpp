#include <cstdlib>
#include <ctime>


/// <summary>
/// 这个函数获得自程序运行以来，过去了多少秒。
/// </summary>
/// <returns>返回一个小数点后3为的浮点数，即当前秒数</returns>
float JGetNowSecond()
{
	return (float)((clock() + 1.0 - 1.0) / CLOCKS_PER_SEC);
}

/// <summary>
/// 这个函数可以让计算机等待多少秒，依赖GetNowSecond()函数
/// </summary>
/// <param name="second">这个参数是具体等待多少秒，可使用浮点</param>
void JTimeSleep(float second)
{
	float start = JGetNowSecond(); // 记录开始时间
	while (JGetNowSecond() - start <= second) // 计算距离开始过去的时间是否小于参数，如果大于则跳出循环并退出
	{ }
}

/// <summary>
/// 这个函数初始化碎句数种子为当前时间，在用函数JRanDint时，需要先运行此函数
/// </summary>
void JRandINIT() // 这个函数初始化随机数种子为当前时间
{
	srand((int)time(NULL));
}

/// <summary>
/// 这个函数用来生成一个范围随机数
/// 注意：
///		这个函数支持负数，也支持对0的全部操作
///		请勿用这个函数生成一个大于系统常量：RAND_MAX否则会出问题！
/// </summary>
/// <param name="a">左范围，需要小于等于范围b</param>
/// <param name="b">右范围，需要大于等于范围a</param>
/// <returns></returns>
int JRandint(int a, int b) // 这个函数生成一个从a到b的随机数
{
	if (a == b) { return a; }

	if (a < 0) // 如果a是负数
	{
		unsigned c = (0 - a) + b; // 算出来负数加整数一共有多少个
		int r = rand() % c; // 算出一共有多少个中的随机数
		r = r + a; // 由于a是负数，所以实际上是将有多少个的随机数减去标准线
		return r;
	}
	else // a不是负数
	{
		int r = rand() % (a - b) + a;
		return r;
	}
}

/// <summary>
/// 这个函数清除屏幕上的信息，仅可用于windows系统
/// </summary>
void JCleanScreen()
{
	system("cls");
}

/// <summary>
/// 这个函数用来交换两个数的位置如传入两个变量5和2，结束后两个变量就会变成2和5
/// </summary>
/// <param name="a">第一个变量</param>
/// <param name="b">第二个变量</param>
void swap(int& a, int& b)
{
	int c; c = a; a = b; b = c;
}

/// <summary>
/// 这个函数给定两个坐标，使用勾股定律求他们的距离
/// </summary>
/// <param name="x1">第一个点的x坐标</param>
/// <param name="y1">第一个点的y坐标</param>
/// <param name="x2">第二个点的x坐标</param>
/// <param name="y2">第二个点的y坐标</param>
/// <returns>返回点1和点2的距离</returns>
int JGG(int x1, int y1, int x2, int y2)
{
	int xc = abs(x1 - x2); // 算出他们的x距离相差
	int yc = abs(y1 - y2); // 算出他们的y距离相差
	double anwser = sqrt(xc * xc + yc * yc); // 求平方根
	return anwser; // 返回平方根
}
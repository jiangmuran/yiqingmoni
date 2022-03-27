 // 这个库是我编写的一些通用工具库

float JGetNowSecond(); // 这个函数获得自程序运行以来，过去了多少秒

void JTimeSleep(float second); // 这个函数可以让计算机等待second秒，依赖GetNowSecond()函数

void JRandINIT(); // 这个函数初始化随机数种子为当前时间

int JRandint(int a, int b); // 这个函数生成一个从a到b的随机数

void JCleanScreen(); // 这个函数用来清除屏幕上的信息

void swap(int& a, int& b); // 这个函数用来交换两个数

int JGG(int x1, int y1, int x2, int y2); // 这个函数给定两个坐标，求距离
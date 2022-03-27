#include <cstdlib>
#include <ctime>


/// <summary>
/// �����������Գ���������������ȥ�˶����롣
/// </summary>
/// <returns>����һ��С�����3Ϊ�ĸ�����������ǰ����</returns>
float JGetNowSecond()
{
	return (float)((clock() + 1.0 - 1.0) / CLOCKS_PER_SEC);
}

/// <summary>
/// ������������ü�����ȴ������룬����GetNowSecond()����
/// </summary>
/// <param name="second">��������Ǿ���ȴ������룬��ʹ�ø���</param>
void JTimeSleep(float second)
{
	float start = JGetNowSecond(); // ��¼��ʼʱ��
	while (JGetNowSecond() - start <= second) // ������뿪ʼ��ȥ��ʱ���Ƿ�С�ڲ������������������ѭ�����˳�
	{ }
}

/// <summary>
/// ���������ʼ�����������Ϊ��ǰʱ�䣬���ú���JRanDintʱ����Ҫ�����д˺���
/// </summary>
void JRandINIT() // ���������ʼ�����������Ϊ��ǰʱ��
{
	srand((int)time(NULL));
}

/// <summary>
/// ���������������һ����Χ�����
/// ע�⣺
///		�������֧�ָ�����Ҳ֧�ֶ�0��ȫ������
///		�����������������һ������ϵͳ������RAND_MAX���������⣡
/// </summary>
/// <param name="a">��Χ����ҪС�ڵ��ڷ�Χb</param>
/// <param name="b">�ҷ�Χ����Ҫ���ڵ��ڷ�Χa</param>
/// <returns></returns>
int JRandint(int a, int b) // �����������һ����a��b�������
{
	if (a == b) { return a; }

	if (a < 0) // ���a�Ǹ���
	{
		unsigned c = (0 - a) + b; // ���������������һ���ж��ٸ�
		int r = rand() % c; // ���һ���ж��ٸ��е������
		r = r + a; // ����a�Ǹ���������ʵ�����ǽ��ж��ٸ����������ȥ��׼��
		return r;
	}
	else // a���Ǹ���
	{
		int r = rand() % (a - b) + a;
		return r;
	}
}

/// <summary>
/// ������������Ļ�ϵ���Ϣ����������windowsϵͳ
/// </summary>
void JCleanScreen()
{
	system("cls");
}

/// <summary>
/// �����������������������λ���紫����������5��2�����������������ͻ���2��5
/// </summary>
/// <param name="a">��һ������</param>
/// <param name="b">�ڶ�������</param>
void swap(int& a, int& b)
{
	int c; c = a; a = b; b = c;
}

/// <summary>
/// ������������������꣬ʹ�ù��ɶ��������ǵľ���
/// </summary>
/// <param name="x1">��һ�����x����</param>
/// <param name="y1">��һ�����y����</param>
/// <param name="x2">�ڶ������x����</param>
/// <param name="y2">�ڶ������y����</param>
/// <returns>���ص�1�͵�2�ľ���</returns>
int JGG(int x1, int y1, int x2, int y2)
{
	int xc = abs(x1 - x2); // ������ǵ�x�������
	int yc = abs(y1 - y2); // ������ǵ�y�������
	double anwser = sqrt(xc * xc + yc * yc); // ��ƽ����
	return anwser; // ����ƽ����
}
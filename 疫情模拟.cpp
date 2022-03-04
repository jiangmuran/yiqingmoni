#include <iostream> // 基本输入输出库
#include <ctime> // 计时库,随机数种子需要用到
#include <cstdlib> // 基本函数库
#include <windows.h>


using namespace std;



struct people // 每个人的数据
{
    unsigned x; // 这个人的x坐标
    unsigned y; // 这个人的y坐标
    bool gr; // 是否被感染
    bool mask; // 是否带口罩
};

// 提供函数原型
int randint(int a, int b); // 这个函数是辅助函数，用来生成一个a~b的随机数
people* cre_city(people* peos, int how_many, int x_len, int y_len); // 这个函数用来创建这个虚拟城市中每个人的信息
void show(people* peos, unsigned how_many); // 这个函数打印出人员信息
void input(void); // 这个函数用来输入这个虚拟城市的基本信息
void start();
void close();
void show_point(int x, int y, COLORREF col, int big);
void wait(int second);

// 定义初始信息
unsigned int how_many = 1000; // 多少个人
unsigned int x_len = 1000; // x坐标轴 0~999
unsigned int y_len = 1000; // y坐标轴 0~999
unsigned int hr = 6;
unsigned int save = 0;
unsigned int masks = 1000;
int zero_mesks;

HWND hWnd = GetConsoleWindow();//取得控制台窗口句柄
HDC hDc = GetDC(hWnd); //关联DC到控制台窗口
 // 随机数种子 用时间

int main()
{
    start();
    
    

    input(); // 输入基本信息

    people* peos = new people[how_many]; // 生成一个存储这么多人的数组
    cre_city(peos, how_many, x_len, y_len); // 让这些人随机出现在各个角落和其他信息
    int days = 1;
    unsigned gr = 0;
    while (1)
    {
        
        
        int* grl = new int[how_many];
        for (int i = 0; i < how_many; i++)
        {
            show_point(peos[i].x, peos[i].y, RGB((peos[i].gr ? 255 : 0), (peos[i].gr ? 0 : 255), 0), 10);
        }
        cout << "Days: " << days << endl;
        cout << "Gr: " << gr << endl;
        if (gr == how_many)
        {
            break;
        }
        gr = 0;
        
        wait(1);
        days++;
        for (int i = 0; i < how_many; i++)
        {
            peos[i].x = (randint(0, 2) ? peos[i].x + randint(0, (hr + 1)) : peos[i].x - randint(0, (hr + 1)));
            peos[i].y = (randint(0, 2) ? peos[i].y + randint(0, (hr + 1)) : peos[i].y - randint(0, (hr + 1)));
            if (peos[i].x >= x_len || peos[i].y >= y_len)
            {
                peos[i].x = x_len/ randint(2, 7);
                peos[i].y = y_len/ randint(2, 7);
            }

            if (peos[i].gr)
            {
                grl[gr] = i;
                gr++;
            }
            
        }
        for (int i = 0; i <= gr; i++)
        {
            for (int j = 0; j < how_many; j++)
            {
                if ((peos[i].x) - save <= peos[j].x && (peos[i].x) + save >= peos[j].x && (peos[i].y) - save <= peos[j].y && (peos[i].y) + save >= peos[j].y)
                {
                    if (randint(0, 10) < 3.0)
                    {
                        peos[j].gr = true;
                    }
                    
                }
            }
        }
        
        system("cls");
    }
    

    
    close();
    cin.get();
    cin.get();
    return 0;
}

int randint(int a, int b) // 这个函数是辅助函数，用来生成一个a~b的随机数
{

    return (rand() % (a - b) + a);
}

people* cre_city(people* peos, int how_many, int x_len, int y_len) // 这个函数用来创建这个虚拟城市中每个人的信息
{

    for (int i = 0; i < how_many; i++)
    {
        peos[i].x = randint(0, x_len); // 把当前这个人的x坐标设为在地图上随机
        peos[i].y = randint(0, y_len); // 把当前这个人的y坐标设为在地图上随机
        peos[i].gr = false;
        peos[i].mask = false;
    };
    for (int i = 0; i < masks; i++)
    {
        peos[i].mask = true;
    };
    int r = randint(0, how_many);
    peos[r].gr = true;
    peos[r].mask = zero_mesks;
    return peos;
}

void show(people* peos, unsigned how_many) // 这个函数打印出人员信息
{
    cout << "++++++++++++++++++" << endl;
    for (int i = 0; (unsigned)i < how_many; i++)
    {
        cout << "id: " << i+1 << endl;
        cout << "x:    " << peos[i].x << endl;
        cout << "y:    " << peos[i].y << endl;
        cout << "++++++++++++++++++" << endl << endl;
    }
}

void input(void) // 这个函数用来输入这个虚拟城市的基本信息
{
    cout << "How many peoples in this city: \a"; // 输入这里有多少人
    cin >> how_many;
    cout << "How longth is this city(m): \a"; // 输入整个虚拟城市的长度,单位是米
    cin >> x_len;
    cout << "How width is this city(m): \a"; // 输入整个虚拟城市的宽度,单位是米
    cin >> y_len;
    cout << "What the hr: \a";
    cin >> hr;
    cout << "What the save: \a";
    cin >> save;
    cout << "How many people ware masks:___%\b\b\b\b \a";
    cin >> masks;
    masks = how_many / 100 * masks;
    if (masks > how_many)
    {
        masks = how_many;
    }
    cout << "Did zero ware the mesk?(0/1): \a";
    cin >> zero_mesks;
    system("cls");
    
}


void start()
{
    srand((int)time(NULL)); // 设定种子
    system("color F4");
    
}

void close()
{
    DeleteDC(hDc);
}

void show_point(int x, int y, COLORREF col,int big)
{
    HPEN hPen = CreatePen(0, 1, col); //创建新的画笔
    SelectObject(hDc, hPen); //绑定新画笔
    HBRUSH hBrush = CreateSolidBrush(col); //创建新的实心笔刷
    SelectObject(hDc, hBrush); //绑定新画笔
    Ellipse(hDc, x, y, x+big, y+big); //绘制椭圆或圆
    DeleteObject(hPen);
    DeleteObject(hBrush);

}

void wait(int second)
{
    clock_t start = clock();
    while (1)
    {
        while (clock() - start >= CLOCKS_PER_SEC)
        {
            return;
        }
    }
    
}



void dc()
{
    HWND hWnd = GetConsoleWindow();//取得控制台窗口句柄

    HDC hDc = GetDC(hWnd); //关联DC到控制台窗口


    system("color 3D"); //改变前景背景色

    MoveToEx(hDc, 50, 50, NULL); //设定画线起点


    HPEN hPen = CreatePen(0, 10, RGB(255, 0, 0)); //创建新的画笔

    SelectObject(hDc, hPen); //绑定新画笔

    HBRUSH hBrush = CreateSolidBrush(RGB(0, 255, 0)); //创建新的实心笔刷

    hBrush = CreateHatchBrush(4, RGB(0, 0, 255)); //创建新的风格笔刷

    SelectObject(hDc, hBrush); //绑定新笔刷


    Ellipse(hDc, 100, 100, 200, 200); //绘制椭圆或圆

    LineTo(hDc, 200, 200); //画线

    SetPixel(hDc, 100, 100, RGB(255, 0, 0)); //画点

    Rectangle(hDc, 200, 200, 400, 400); //画矩形或正方形


    DeleteObject(hPen); //释放画笔资源
    DeleteObject(hBrush); //释放笔刷资源
    DeleteDC(hDc); //释放DC句柄资源
}
#include <iostream> // 基本输入输出库
#include <cstdlib> // 其他的一些函数
#include <fstream>
#include "JMR_GDI.h" // 自己的GDI图形化库
#include "JMR_Tools.h" // 自己的系统和其他的一些实用组件库
#include "YQMZ2_Tools.h" // 这个项目的函数库



using namespace std; // 修改命名空间



int main() // 主函数，用来存储信息和调用其他函数
{
    //////////定义变量//////////
    int ScreenLenX; //整个显示屏的x轴像素长度变量
    int ScreenLenY; //整个显示屏的y轴像素长度变量
    int HMP; // 这个城市里有多少人，是How many people的简写
    int Activity; // 活跃度，即每人每天最多走多远
    int MNP; // 有多少人戴了口罩
    int Days = 0; // 过去的天数
    int CRS = 1; // 当前传染人数
    int FarGL = 20; // 出远门概率

    bool M0B = false; // 零号病人有没有戴口罩

    int ITmp; // int临时变量
    char CTmp; // char临时变量
    string STmp;


    //////////////////读配置/////////////////////
    int IP = 30; // 传染概率，即在危险距离内被传染的概率（百分制）
    int MIP = 15; // 在戴口罩且在危险距离内的情况下的传染概率,M=Mask
    int SafeLen = 20; // 危险距离，即在多远距离内有概率被传染
    int MSafeLen = 5; // 戴口罩的危险距离
    int MBDay = 200; // 达成目标的天数
    int PointB = 10; // 点大小

    ifstream sini;
    sini.open("./files/set.yqmnfile");
    if (sini.is_open())
    {
        sini >> STmp >> IP;
        sini >> STmp >> MIP;
        sini >> STmp >> SafeLen;
        sini >> STmp >> MSafeLen;
        sini >> STmp >> MBDay;
        sini >> STmp >> PointB;
    }
    




    //////////初始化////////////
    JRandINIT();
    //system("color F4"); // 修改背景颜色
    JGetHandle(); // 获取句柄，所有J开头orYZ开头的都是自己写的
    JGetScreenXY(ScreenLenX, ScreenLenY); // 获取屏幕分辨率
    JFullScreen(ScreenLenX, ScreenLenY); // 根据分辨率将窗口设为全屏


    //////////输入信息//////////
    cout << "欢迎来到疫情之下——都市模拟" << endl;
    cout << "请选择操作：" << endl;
    cout << "(c)开始创建你的实验领地" << endl;
    cout << "(q)退出程序" << endl;
    (cin >> CTmp).get();
    switch (CTmp)
    {
    case 'q':;
    case 'Q':
        exit(0);
    }

    JCleanScreen();

    
    cout << "这个城市里有多少人，请在输入完成后按下回车,鉴于个人电脑的算力，\n建议不要超过10000人。如果你想要测试你的电脑性能，上不封顶:  "; // 输入有多少人

    (cin >> HMP).get(); // 输入到变量HMP

    cout << endl;


    cout << "城市人口的活跃度是多少,建议在%7~%12之间: ___%\b\b\b\b";
    (cin >> Activity).get(); // 输入到变量Activity
    Activity *= 3;

    cout << endl;
    

    cout << "满城跑的人的比例（不受活跃度影响）,建议为20%: ___%\b\b\b\b";
    (cin >> FarGL).get(); // 传入到临时变量里，因为要计算有多少人戴了口罩
    if (FarGL >= 100) // 如果百分比大于100
    {
        FarGL = 100;
    }

    cout << endl;


    cout << "有百分之多少的人戴了口罩: ___%\b\b\b\b";
    (cin >> ITmp).get(); // 传入到临时变量里，因为要计算有多少人戴了口罩
    if (ITmp >= 100) // 如果百分比大于100
    {
        MNP = HMP; // 将其设为人数，因为就是100%
    }
    else
    {
        MNP = ((float)HMP / 100) * ITmp; // 计算有多少人要戴口罩

    }
    if (CRS != HMP)
    {
        ITmp++; // 因为要去掉第0个，这个是零号病人
    }
    cout << endl;
    
    cout << "零号传染病人是否戴口罩,请输入0或者1(0代表不戴，1代表戴了): ";
    (cin >> ITmp).get();
    if (ITmp) { M0B = true; MNP++; }
    cout << endl;
    if (HMP == -32767) // 暗号
    {
        cout << "暗号已触发" << endl;
        HMP = 300;
        Days = MBDay;
    }
    else if (HMP <= 2)
    {
        cout << "人数不能小于3！请按下Alt+F4关闭此程序" << endl;
        while (1) { }
    }
    
    
    
    //////////创建城市//////////
    cout << "开始创建城市，请稍后..." << endl;
    people * CityPeoples = new people[HMP]; // 创建一个结构数组，用来存储每一个人的信息
    int* crslist = new int[HMP];
    for (int i = 0; i < HMP; i++)
    {
        crslist[i] = 0;
    }
    YZCreateCity(CityPeoples, HMP, ScreenLenX, ScreenLenY, MNP, M0B); // 创建一个城市
    cout << "城市创建完成，按下Enter键开始模拟..." << endl;
    cin.get();
    JCleanScreen(); // 清空屏幕
    ITmp = 1;
    
    while (true) // 进入显示循环
    {
        

        YZShowScreenPeoples(CityPeoples,HMP,PointB); // 显示每个人
        cout << "*********************" << endl;
        cout << "天数:         " << Days << endl; // 显示信息
        cout << "总人数:       " << HMP <<endl; // 显示信息
        cout << "被传染人数:   " << CRS << endl; // 显示信息
        cout << "未被传染人数: " << HMP - CRS << endl; // 显示信息
        cout << "昨日新增:     " << CRS - ITmp << endl;
        cout << "*********************";
        ITmp = CRS;
        if (CRS == HMP) // 传染
        {
            cout << endl << "模拟已结束" << endl;
            cout << "按下Enter键播放疫情防控小贴士和制作信息：" << endl;
            cin.get();
            JCleanScreen();
            YZShowMassage();
            JDeleteDCScreen();
            while (1) {}
        }
        else if (Days >= MBDay && (0 || HMP/3 > CRS))
        {
            cout << endl << "恭喜！支援已到达，疫情已得到控制！" << endl;
            cout << "按下Enter键播放疫情防控小贴士和制作信息：" << endl;
            cin.get();
            JCleanScreen();
            YZShowMassage();
            JDeleteDCScreen();
            while (1) {}

        }
        JTimeSleep(1); // 等待1秒

        //////////////////开始计算///////////////////////
        YZMoveAllPeople(CityPeoples, HMP, Activity, ScreenLenX, ScreenLenY, FarGL); // 移动所有人

        YZUpDateCR(CityPeoples, HMP, SafeLen, MSafeLen, CRS, crslist, IP, MIP); // 判断是否有新传染者

        /////////////////准备开始新一轮/////////////////

        JCleanScreen(); // 清空屏幕

        Days++;
    }
    
    
}
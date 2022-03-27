// 这个库是专门对yqmz2项目的函数
#include "JMR_Tools.h" // 导入自己的工具库
#include "JMR_GDI.h" // 导入自己的GDI库
#include <iostream> // 基本输入输出库
#include <fstream>

using namespace std;




struct people // 每个人的数据
{
    int x; // 这个人的x坐标
    int y; // 这个人的y坐标
    bool cr; // 是否被传染
    bool mask; // 是否戴口罩


};

/// <summary>
/// 这个函数根据传入信息，创建每一个人的信息
/// </summary>
/// <param name="peoples">people结构数组，是每个人的信息</param>
/// <param name="HMP">有多少人，必须大于0</param>
/// <param name="ScreenLenX">屏幕的x坐标长度</param>
/// <param name="ScreenLenY">屏幕的y坐标长度</param>
/// <param name="MNP">戴口罩的人数 </param>
/// <param name="M0B">布尔值，第一个病人是否戴口罩</param>
void YZCreateCity(people* peoples, int HMP ,int ScreenLenX, int ScreenLenY,int MNP,bool M0B)
{
    int BFZ = HMP / 100,tmp = -1;
    BFZ = BFZ == 0 ? BFZ + 1 : BFZ;
    for (int i = 0; i < HMP; i++) // 重复每个人
    {
        peoples[i].x = JRandint(0, ScreenLenX); // 生成这个人的x坐标信息，以屏幕显示器为边界
        peoples[i].y = JRandint(0, ScreenLenY); // 生成这个人的y坐标信息，以屏幕显示器为边界
        peoples[i].cr = false; // 将这个人设置为未传染，因为最开始只有一个人被传染
        if (i < MNP) // 如果这个人数小于戴口罩人数
        {
            peoples[i].mask = true; // 将这个人设定为戴口罩
        }
        else // 否则
        {
            peoples[i].mask = false; // 将这个人设定为没戴口罩
        }
        if (i % BFZ == 0 && tmp <= 99) // 百分比
        {
            tmp++;
            // cout << tmp << "%" << endl; // 废弃的百分比显示
        }
    }
    peoples[0].cr = true; // 将第一个人设置为已传染（零号病人）
    peoples[0].mask = M0B; // 设置第一个人是否戴口罩
    for (; tmp <= 100; tmp++)
    {
        //cout << tmp << "%" << endl; // 废弃的百分比显示
    }
    

}

/// <summary>
/// 这个函数通过cout打印出每个人的信息，用来调试
/// </summary>
/// <param name="peos">people数组，每个人的信息</param>
/// <param name="how_many">有多少人</param>
void YZShowCityPeople(people* peos, unsigned how_many) // 这个函数打印出人员信息
{
    cout << "++++++++++++++++++" << endl; // 打印分隔符
    for (int i = 0; (unsigned)i < how_many; i++) // 循环每个人
    {
        cout << "id: " << i + 1 << endl; // 打印id
        cout << "x:    " << peos[i].x << endl; // 打印x坐标
        cout << "y:    " << peos[i].y << endl; // 打印y坐标
        cout << "mask: " << peos[i].mask << endl; // 打印这个人是否戴口罩
        cout << "cr:   " << peos[i].cr << endl; // 打印这个人是否被传染
        cout << "++++++++++++++++++" << endl << endl; // 打印分隔符
    }
}


/// <summary>
/// 使用GDI显示每个人的信息
/// </summary>
/// <param name="CityPeople">人口信息</param>
/// <param name="HMP">人数</param>
/// <param name="PointB">大小</param>
/// <param name="PointZB">零号传染者大小</param>
void YZShowScreenPeoples(people* CityPeople, int HMP,int PointB) // 显示每个人
{
    HPEN PRed = JCreatePen(1, RGB(255, 0, 0)); // 创建红色画笔
    HBRUSH BRed = JCreateBrush(RGB(255, 0, 0)); // 创建红色笔刷
    HPEN PGreen = JCreatePen(1, RGB(0, 255, 0)); // 创建绿色画笔
    HBRUSH BGreen = JCreateBrush(RGB(0, 255, 0)); // 创建绿色笔刷

    JBindOBJ(PGreen); // 绑定回绿色
    JBindOBJ(BGreen); // 绑定回绿色

    for (int i = 0; i < HMP; i++) // 重复每个人
    {
        if (!CityPeople[i].cr) // 如果这个人未被传染
        {

            JDrawCircle(CityPeople[i].x, CityPeople[i].y, PointB); // 画一个圆

        }
    }
    JBindOBJ(PRed); // 将屏幕绑定上红色
    JBindOBJ(BRed); // 将屏幕绑定上红色

    JDrawCircle(CityPeople[0].x, CityPeople[0].y, (int)PointB*1.6); // 画一个圆

    for (int i = 1; i < HMP; i++) // 重复每个人
    {
        if (CityPeople[i].cr) // 如果这个人被传染
        {

            JDrawCircle(CityPeople[i].x, CityPeople[i].y, PointB); // 画一个圆

            
            
        }

    }
    DeleteObject(PRed); // 释放红色画笔
    DeleteObject(BRed); // 释放红色笔刷
    DeleteObject(PGreen); // 释放绿色画笔
    DeleteObject(BGreen); // 释放绿色笔刷
}

/// <summary>
/// 移动所有人员
/// </summary>
/// <param name="CityPeoples">people数组，每个人的信息</param>
/// <param name="HMP">有多少人</param>
/// <param name="Activity">活跃度（每人每天最多走多远）</param>
/// <param name="ScreenLenX">屏幕长度</param>
/// <param name="ScreenLenY">屏幕宽度</param>
/// <param name="FarGL">出远门概率（百分制）</param>
void YZMoveAllPeople (people* CityPeoples, int HMP, int Activity, int ScreenLenX, int ScreenLenY,int FarGL)
{
    for (int i = 0; i < HMP; i++)
    {
        ////////////////////移动每个人///////////////////
        if (JRandint(0, 100) < FarGL) // 表示要出远门
        {
            CityPeoples[i].x = JRandint(0, ScreenLenX); // 将这个人的x坐标设置为随机
            CityPeoples[i].y = JRandint(0, ScreenLenY); // 将这个人的y坐标设置为随机
        }
        else
        {
            int rx, ry;
            rx = JRandint(-Activity, Activity);
            ry = JRandint(-Activity, Activity);
            CityPeoples[i].x = CityPeoples[i].x + rx; // 让这个人随机移动
            CityPeoples[i].y = CityPeoples[i].y + ry; // 让这个人随机移动
            // 是否出边界
            if (CityPeoples[i].x >= ScreenLenX || CityPeoples[i].y >= ScreenLenY || CityPeoples[i].x <= 0 || CityPeoples[i].y <=0)
            {
                CityPeoples[i].x += -rx * 2;
                CityPeoples[i].y += -ry * 2;
            }
            
        }
       
    }
}



/// <summary>
/// 这个函数根据位置检测是否被传染。
/// </summary>
/// <param name="CP">所有人的结构数组，是CityPeople的简写</param>
/// <param name="HMP">有多少人，是How Many People的简写</param>
/// <param name="SafeLen">安全距离，即在不戴口罩的情况下在多远距离内会有概率传染</param>
/// <param name="MSafeLen">戴口罩安全距离，即在戴口罩的情况下在多远距离内会有概率传染</param>
/// <param name="crs">这是一个引用变量，有多少人被传染</param>
/// <param name="crl">这个是所有被传染者的下标列表</param>
/// <param name="IP">戴口罩的传染概率</param>
/// <param name="MIP">不戴口罩的传染概率</param>
void YZUpDateCR(people* CP, int HMP, int SafeLen, int MSafeLen, int& crs, int* crl, int IP, int MIP)
{
    people pep, crp; // 两个临时结构，分别用来存储当前轮到的人和当前被传染的人
    int tmp = crs;
    for (int i = 0; i < tmp; i++) // 重复每个被传染者
    {
        crp = CP[crl[i]]; // 设置当前被传染者
        for (int j = 0; j < HMP; j++) // 在每个被传染者下面检测每个人
        {
            if (!CP[j].cr) // 确定这个人是未被传染的
            {
                pep = CP[j]; // 设置当前轮到的未传染者
                int Safe = (crp.mask || pep.mask ? MSafeLen : SafeLen); // 确定这个人是否戴口罩，推出他的危险距离
                if (!(crp.x - Safe <= pep.x && pep.x <= crp.x + Safe)){ continue; } // 确定在正方形内，x坐标满足被传染要求
                if (!(crp.y - Safe <= pep.y && pep.y <= crp.y + Safe)){ continue; } // 确定在正方形内，y坐标满足被传染要求
                if (JGG(crp.x, crp.y, pep.x, pep.y) <= Safe) // 最后通过沟谷定律确定一遍，是否在危险距离内
                {
                    if (JRandint(0, 100) <= (crp.mask || pep.mask ? IP : MIP)) // 确定是否满足传染距离
                    {
                        crl[crs] = j; // 添加
                        CP[j].cr = true;
                        crs++;
                    }
                }
            }
            
         }
                                 
            
        

    }

}


/// <summary>
/// 这个函数显示小贴士
/// </summary>
void YZShowMassage()
{
    int ts = 0;
    int CardNum = JRandint(6, 19);
    //////////疫情防控小贴士//////////
    ifstream note;
    string tmp;
    note.open("./files/note.yqmnfile");
    if (!note.is_open())
    {
        cout << "程序错误，原因：未找到note.yqmnfile文件，请确认程序是否完整..." << endl;
        return;
    }

    while (!note.eof())
    {
        note >> tmp;
        ts++;
    }
    
    string* tslist = new string[ts];

    note.close();

    note.open("./files/note.yqmnfile");

    for (int i = 0; i < ts; i++)
    {
        note >> tslist[i];
    }
    cout << "规则：你可以抽6~18张疫情卡片，告诉你一些有关于疫情的小知识。" << endl;
    cout << "会有隐藏款，神秘大奖等你拿（猜猜是啥？" << endl;
    cout << "按下enter按键，你会知道你能抽出几张卡片" << endl;
    cin.get();
    cout << "正在摇晃抽奖箱..." << endl;
    JTimeSleep(2.5f);
    cout << "正在随机抓取一张卡片..." << endl;
    JTimeSleep(3.0f);
    cout << "抓上来了！按下enter键打开小纸条..." << endl;
    cin.get();
    cout << "你可以抽" << CardNum << "张卡片！" << endl;
    for (int i = 0; i < CardNum; i++)
    {
        cout << "按下Enter键抽取第" << i + 1 << "张:";
        cin.get();
        cout << "抽取中...." << endl;
        JTimeSleep(0.4);
        cout << "你抽到了：" << endl << tslist[JRandint(0, ts)] << endl << endl;
    }

    cout << "按下Enter键播放制作信息：" << endl;
    cin.get();
    cout << "真的要走吗？" << endl;
    cin.get();
    cout << "真的真的要走吗？" << endl;
    JCleanScreen();
    cout << "姓名：姜睦然" << endl;
    cout << "学校班级：陈经纶中学分校小学部望馨花园校区四年级（4）班" << endl;
    cout << "微信：codejmr (请备注)" << endl;
    cout << "QQ：3391966290（请备注）" << endl;
    cout << "邮箱：wd.jiang@foxmail.com (主要邮箱) \nwd.jiang@outlook.com (次要邮箱)" << endl;
    cout << "如果你对本作品有任何意见/建议，请拜托一定要告诉我，谢谢。" << endl;
    cout << "该项目网站：https://github.com/jiangmuran/yiqingmoni/tree/New2.0" << endl;
    cout << "程序已结束，如要关闭，请按下按键Alt+F4";

}
#include <iostream> // �������������
#include <cstdlib> // ������һЩ����
#include <fstream>
#include "JMR_GDI.h" // �Լ���GDIͼ�λ���
#include "JMR_Tools.h" // �Լ���ϵͳ��������һЩʵ�������
#include "YQMZ2_Tools.h" // �����Ŀ�ĺ�����



using namespace std; // �޸������ռ�



int main() // �������������洢��Ϣ�͵�����������
{
    //////////�������//////////
    int ScreenLenX; //������ʾ����x�����س��ȱ���
    int ScreenLenY; //������ʾ����y�����س��ȱ���
    int HMP; // ����������ж����ˣ���How many people�ļ�д
    int Activity; // ��Ծ�ȣ���ÿ��ÿ������߶�Զ
    int MNP; // �ж����˴��˿���
    int Days = 0; // ��ȥ������
    int CRS = 1; // ��ǰ��Ⱦ����
    int FarGL = 20; // ��Զ�Ÿ���

    bool M0B = false; // ��Ų�����û�д�����

    int ITmp; // int��ʱ����
    char CTmp; // char��ʱ����
    string STmp;


    //////////////////������/////////////////////
    int IP = 30; // ��Ⱦ���ʣ�����Σ�վ����ڱ���Ⱦ�ĸ��ʣ��ٷ��ƣ�
    int MIP = 15; // �ڴ���������Σ�վ����ڵ�����µĴ�Ⱦ����,M=Mask
    int SafeLen = 20; // Σ�վ��룬���ڶ�Զ�������и��ʱ���Ⱦ
    int MSafeLen = 5; // �����ֵ�Σ�վ���
    int MBDay = 200; // ���Ŀ�������
    int PointB = 10; // ���С

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
    




    //////////��ʼ��////////////
    JRandINIT();
    //system("color F4"); // �޸ı�����ɫ
    JGetHandle(); // ��ȡ���������J��ͷorYZ��ͷ�Ķ����Լ�д��
    JGetScreenXY(ScreenLenX, ScreenLenY); // ��ȡ��Ļ�ֱ���
    JFullScreen(ScreenLenX, ScreenLenY); // ���ݷֱ��ʽ�������Ϊȫ��


    //////////������Ϣ//////////
    cout << "��ӭ��������֮�¡�������ģ��" << endl;
    cout << "��ѡ�������" << endl;
    cout << "(c)��ʼ�������ʵ�����" << endl;
    cout << "(q)�˳�����" << endl;
    (cin >> CTmp).get();
    switch (CTmp)
    {
    case 'q':;
    case 'Q':
        exit(0);
    }

    JCleanScreen();

    
    cout << "����������ж����ˣ�����������ɺ��»س�,���ڸ��˵��Ե�������\n���鲻Ҫ����10000�ˡ��������Ҫ������ĵ������ܣ��ϲ��ⶥ:  "; // �����ж�����

    (cin >> HMP).get(); // ���뵽����HMP

    cout << endl;


    cout << "�����˿ڵĻ�Ծ���Ƕ���,������%7~%12֮��: ___%\b\b\b\b";
    (cin >> Activity).get(); // ���뵽����Activity
    Activity *= 3;

    cout << endl;
    

    cout << "�����ܵ��˵ı��������ܻ�Ծ��Ӱ�죩,����Ϊ20%: ___%\b\b\b\b";
    (cin >> FarGL).get(); // ���뵽��ʱ�������ΪҪ�����ж����˴��˿���
    if (FarGL >= 100) // ����ٷֱȴ���100
    {
        FarGL = 100;
    }

    cout << endl;


    cout << "�аٷ�֮���ٵ��˴��˿���: ___%\b\b\b\b";
    (cin >> ITmp).get(); // ���뵽��ʱ�������ΪҪ�����ж����˴��˿���
    if (ITmp >= 100) // ����ٷֱȴ���100
    {
        MNP = HMP; // ������Ϊ��������Ϊ����100%
    }
    else
    {
        MNP = ((float)HMP / 100) * ITmp; // �����ж�����Ҫ������

    }
    if (CRS != HMP)
    {
        ITmp++; // ��ΪҪȥ����0�����������Ų���
    }
    cout << endl;
    
    cout << "��Ŵ�Ⱦ�����Ƿ������,������0����1(0��������1�������): ";
    (cin >> ITmp).get();
    if (ITmp) { M0B = true; MNP++; }
    cout << endl;
    if (HMP == -32767) // ����
    {
        cout << "�����Ѵ���" << endl;
        HMP = 300;
        Days = MBDay;
    }
    else if (HMP <= 2)
    {
        cout << "��������С��3���밴��Alt+F4�رմ˳���" << endl;
        while (1) { }
    }
    
    
    
    //////////��������//////////
    cout << "��ʼ�������У����Ժ�..." << endl;
    people * CityPeoples = new people[HMP]; // ����һ���ṹ���飬�����洢ÿһ���˵���Ϣ
    int* crslist = new int[HMP];
    for (int i = 0; i < HMP; i++)
    {
        crslist[i] = 0;
    }
    YZCreateCity(CityPeoples, HMP, ScreenLenX, ScreenLenY, MNP, M0B); // ����һ������
    cout << "���д�����ɣ�����Enter����ʼģ��..." << endl;
    cin.get();
    JCleanScreen(); // �����Ļ
    ITmp = 1;
    
    while (true) // ������ʾѭ��
    {
        

        YZShowScreenPeoples(CityPeoples,HMP,PointB); // ��ʾÿ����
        cout << "*********************" << endl;
        cout << "����:         " << Days << endl; // ��ʾ��Ϣ
        cout << "������:       " << HMP <<endl; // ��ʾ��Ϣ
        cout << "����Ⱦ����:   " << CRS << endl; // ��ʾ��Ϣ
        cout << "δ����Ⱦ����: " << HMP - CRS << endl; // ��ʾ��Ϣ
        cout << "��������:     " << CRS - ITmp << endl;
        cout << "*********************";
        ITmp = CRS;
        if (CRS == HMP) // ��Ⱦ
        {
            cout << endl << "ģ���ѽ���" << endl;
            cout << "����Enter�������������С��ʿ��������Ϣ��" << endl;
            cin.get();
            JCleanScreen();
            YZShowMassage();
            JDeleteDCScreen();
            while (1) {}
        }
        else if (Days >= MBDay && (0 || HMP/3 > CRS))
        {
            cout << endl << "��ϲ��֧Ԯ�ѵ�������ѵõ����ƣ�" << endl;
            cout << "����Enter�������������С��ʿ��������Ϣ��" << endl;
            cin.get();
            JCleanScreen();
            YZShowMassage();
            JDeleteDCScreen();
            while (1) {}

        }
        JTimeSleep(1); // �ȴ�1��

        //////////////////��ʼ����///////////////////////
        YZMoveAllPeople(CityPeoples, HMP, Activity, ScreenLenX, ScreenLenY, FarGL); // �ƶ�������

        YZUpDateCR(CityPeoples, HMP, SafeLen, MSafeLen, CRS, crslist, IP, MIP); // �ж��Ƿ����´�Ⱦ��

        /////////////////׼����ʼ��һ��/////////////////

        JCleanScreen(); // �����Ļ

        Days++;
    }
    
    
}
// �������ר�Ŷ�yqmz2��Ŀ�ĺ���
#include "JMR_Tools.h" // �����Լ��Ĺ��߿�
#include "JMR_GDI.h" // �����Լ���GDI��
#include <iostream> // �������������
#include <fstream>

using namespace std;




struct people // ÿ���˵�����
{
    int x; // ����˵�x����
    int y; // ����˵�y����
    bool cr; // �Ƿ񱻴�Ⱦ
    bool mask; // �Ƿ������


};

/// <summary>
/// ����������ݴ�����Ϣ������ÿһ���˵���Ϣ
/// </summary>
/// <param name="peoples">people�ṹ���飬��ÿ���˵���Ϣ</param>
/// <param name="HMP">�ж����ˣ��������0</param>
/// <param name="ScreenLenX">��Ļ��x���곤��</param>
/// <param name="ScreenLenY">��Ļ��y���곤��</param>
/// <param name="MNP">�����ֵ����� </param>
/// <param name="M0B">����ֵ����һ�������Ƿ������</param>
void YZCreateCity(people* peoples, int HMP ,int ScreenLenX, int ScreenLenY,int MNP,bool M0B)
{
    int BFZ = HMP / 100,tmp = -1;
    BFZ = BFZ == 0 ? BFZ + 1 : BFZ;
    for (int i = 0; i < HMP; i++) // �ظ�ÿ����
    {
        peoples[i].x = JRandint(0, ScreenLenX); // ��������˵�x������Ϣ������Ļ��ʾ��Ϊ�߽�
        peoples[i].y = JRandint(0, ScreenLenY); // ��������˵�y������Ϣ������Ļ��ʾ��Ϊ�߽�
        peoples[i].cr = false; // �����������Ϊδ��Ⱦ����Ϊ�ʼֻ��һ���˱���Ⱦ
        if (i < MNP) // ����������С�ڴ���������
        {
            peoples[i].mask = true; // ��������趨Ϊ������
        }
        else // ����
        {
            peoples[i].mask = false; // ��������趨Ϊû������
        }
        if (i % BFZ == 0 && tmp <= 99) // �ٷֱ�
        {
            tmp++;
            // cout << tmp << "%" << endl; // �����İٷֱ���ʾ
        }
    }
    peoples[0].cr = true; // ����һ��������Ϊ�Ѵ�Ⱦ����Ų��ˣ�
    peoples[0].mask = M0B; // ���õ�һ�����Ƿ������
    for (; tmp <= 100; tmp++)
    {
        //cout << tmp << "%" << endl; // �����İٷֱ���ʾ
    }
    

}

/// <summary>
/// �������ͨ��cout��ӡ��ÿ���˵���Ϣ����������
/// </summary>
/// <param name="peos">people���飬ÿ���˵���Ϣ</param>
/// <param name="how_many">�ж�����</param>
void YZShowCityPeople(people* peos, unsigned how_many) // ���������ӡ����Ա��Ϣ
{
    cout << "++++++++++++++++++" << endl; // ��ӡ�ָ���
    for (int i = 0; (unsigned)i < how_many; i++) // ѭ��ÿ����
    {
        cout << "id: " << i + 1 << endl; // ��ӡid
        cout << "x:    " << peos[i].x << endl; // ��ӡx����
        cout << "y:    " << peos[i].y << endl; // ��ӡy����
        cout << "mask: " << peos[i].mask << endl; // ��ӡ������Ƿ������
        cout << "cr:   " << peos[i].cr << endl; // ��ӡ������Ƿ񱻴�Ⱦ
        cout << "++++++++++++++++++" << endl << endl; // ��ӡ�ָ���
    }
}


/// <summary>
/// ʹ��GDI��ʾÿ���˵���Ϣ
/// </summary>
/// <param name="CityPeople">�˿���Ϣ</param>
/// <param name="HMP">����</param>
/// <param name="PointB">��С</param>
/// <param name="PointZB">��Ŵ�Ⱦ�ߴ�С</param>
void YZShowScreenPeoples(people* CityPeople, int HMP,int PointB) // ��ʾÿ����
{
    HPEN PRed = JCreatePen(1, RGB(255, 0, 0)); // ������ɫ����
    HBRUSH BRed = JCreateBrush(RGB(255, 0, 0)); // ������ɫ��ˢ
    HPEN PGreen = JCreatePen(1, RGB(0, 255, 0)); // ������ɫ����
    HBRUSH BGreen = JCreateBrush(RGB(0, 255, 0)); // ������ɫ��ˢ

    JBindOBJ(PGreen); // �󶨻���ɫ
    JBindOBJ(BGreen); // �󶨻���ɫ

    for (int i = 0; i < HMP; i++) // �ظ�ÿ����
    {
        if (!CityPeople[i].cr) // ��������δ����Ⱦ
        {

            JDrawCircle(CityPeople[i].x, CityPeople[i].y, PointB); // ��һ��Բ

        }
    }
    JBindOBJ(PRed); // ����Ļ���Ϻ�ɫ
    JBindOBJ(BRed); // ����Ļ���Ϻ�ɫ

    JDrawCircle(CityPeople[0].x, CityPeople[0].y, (int)PointB*1.6); // ��һ��Բ

    for (int i = 1; i < HMP; i++) // �ظ�ÿ����
    {
        if (CityPeople[i].cr) // �������˱���Ⱦ
        {

            JDrawCircle(CityPeople[i].x, CityPeople[i].y, PointB); // ��һ��Բ

            
            
        }

    }
    DeleteObject(PRed); // �ͷź�ɫ����
    DeleteObject(BRed); // �ͷź�ɫ��ˢ
    DeleteObject(PGreen); // �ͷ���ɫ����
    DeleteObject(BGreen); // �ͷ���ɫ��ˢ
}

/// <summary>
/// �ƶ�������Ա
/// </summary>
/// <param name="CityPeoples">people���飬ÿ���˵���Ϣ</param>
/// <param name="HMP">�ж�����</param>
/// <param name="Activity">��Ծ�ȣ�ÿ��ÿ������߶�Զ��</param>
/// <param name="ScreenLenX">��Ļ����</param>
/// <param name="ScreenLenY">��Ļ���</param>
/// <param name="FarGL">��Զ�Ÿ��ʣ��ٷ��ƣ�</param>
void YZMoveAllPeople (people* CityPeoples, int HMP, int Activity, int ScreenLenX, int ScreenLenY,int FarGL)
{
    for (int i = 0; i < HMP; i++)
    {
        ////////////////////�ƶ�ÿ����///////////////////
        if (JRandint(0, 100) < FarGL) // ��ʾҪ��Զ��
        {
            CityPeoples[i].x = JRandint(0, ScreenLenX); // ������˵�x��������Ϊ���
            CityPeoples[i].y = JRandint(0, ScreenLenY); // ������˵�y��������Ϊ���
        }
        else
        {
            int rx, ry;
            rx = JRandint(-Activity, Activity);
            ry = JRandint(-Activity, Activity);
            CityPeoples[i].x = CityPeoples[i].x + rx; // �����������ƶ�
            CityPeoples[i].y = CityPeoples[i].y + ry; // �����������ƶ�
            // �Ƿ���߽�
            if (CityPeoples[i].x >= ScreenLenX || CityPeoples[i].y >= ScreenLenY || CityPeoples[i].x <= 0 || CityPeoples[i].y <=0)
            {
                CityPeoples[i].x += -rx * 2;
                CityPeoples[i].y += -ry * 2;
            }
            
        }
       
    }
}



/// <summary>
/// �����������λ�ü���Ƿ񱻴�Ⱦ��
/// </summary>
/// <param name="CP">�����˵Ľṹ���飬��CityPeople�ļ�д</param>
/// <param name="HMP">�ж����ˣ���How Many People�ļ�д</param>
/// <param name="SafeLen">��ȫ���룬���ڲ������ֵ�������ڶ�Զ�����ڻ��и��ʴ�Ⱦ</param>
/// <param name="MSafeLen">�����ְ�ȫ���룬���ڴ����ֵ�������ڶ�Զ�����ڻ��и��ʴ�Ⱦ</param>
/// <param name="crs">����һ�����ñ������ж����˱���Ⱦ</param>
/// <param name="crl">��������б���Ⱦ�ߵ��±��б�</param>
/// <param name="IP">�����ֵĴ�Ⱦ����</param>
/// <param name="MIP">�������ֵĴ�Ⱦ����</param>
void YZUpDateCR(people* CP, int HMP, int SafeLen, int MSafeLen, int& crs, int* crl, int IP, int MIP)
{
    people pep, crp; // ������ʱ�ṹ���ֱ������洢��ǰ�ֵ����˺͵�ǰ����Ⱦ����
    int tmp = crs;
    for (int i = 0; i < tmp; i++) // �ظ�ÿ������Ⱦ��
    {
        crp = CP[crl[i]]; // ���õ�ǰ����Ⱦ��
        for (int j = 0; j < HMP; j++) // ��ÿ������Ⱦ��������ÿ����
        {
            if (!CP[j].cr) // ȷ���������δ����Ⱦ��
            {
                pep = CP[j]; // ���õ�ǰ�ֵ���δ��Ⱦ��
                int Safe = (crp.mask || pep.mask ? MSafeLen : SafeLen); // ȷ��������Ƿ�����֣��Ƴ�����Σ�վ���
                if (!(crp.x - Safe <= pep.x && pep.x <= crp.x + Safe)){ continue; } // ȷ�����������ڣ�x�������㱻��ȾҪ��
                if (!(crp.y - Safe <= pep.y && pep.y <= crp.y + Safe)){ continue; } // ȷ�����������ڣ�y�������㱻��ȾҪ��
                if (JGG(crp.x, crp.y, pep.x, pep.y) <= Safe) // ���ͨ�����ȶ���ȷ��һ�飬�Ƿ���Σ�վ�����
                {
                    if (JRandint(0, 100) <= (crp.mask || pep.mask ? IP : MIP)) // ȷ���Ƿ����㴫Ⱦ����
                    {
                        crl[crs] = j; // ���
                        CP[j].cr = true;
                        crs++;
                    }
                }
            }
            
         }
                                 
            
        

    }

}


/// <summary>
/// ���������ʾС��ʿ
/// </summary>
void YZShowMassage()
{
    int ts = 0;
    int CardNum = JRandint(6, 19);
    //////////�������С��ʿ//////////
    ifstream note;
    string tmp;
    note.open("./files/note.yqmnfile");
    if (!note.is_open())
    {
        cout << "�������ԭ��δ�ҵ�note.yqmnfile�ļ�����ȷ�ϳ����Ƿ�����..." << endl;
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
    cout << "��������Գ�6~18�����鿨Ƭ��������һЩ�й��������С֪ʶ��" << endl;
    cout << "�������ؿ���ش󽱵����ã��²���ɶ��" << endl;
    cout << "����enter���������֪�����ܳ�����ſ�Ƭ" << endl;
    cin.get();
    cout << "����ҡ�γ齱��..." << endl;
    JTimeSleep(2.5f);
    cout << "�������ץȡһ�ſ�Ƭ..." << endl;
    JTimeSleep(3.0f);
    cout << "ץ�����ˣ�����enter����Сֽ��..." << endl;
    cin.get();
    cout << "����Գ�" << CardNum << "�ſ�Ƭ��" << endl;
    for (int i = 0; i < CardNum; i++)
    {
        cout << "����Enter����ȡ��" << i + 1 << "��:";
        cin.get();
        cout << "��ȡ��...." << endl;
        JTimeSleep(0.4);
        cout << "��鵽�ˣ�" << endl << tslist[JRandint(0, ts)] << endl << endl;
    }

    cout << "����Enter������������Ϣ��" << endl;
    cin.get();
    cout << "���Ҫ����" << endl;
    cin.get();
    cout << "������Ҫ����" << endl;
    JCleanScreen();
    cout << "����������Ȼ" << endl;
    cout << "ѧУ�༶���¾�����ѧ��УСѧ����ܰ��԰У�����꼶��4����" << endl;
    cout << "΢�ţ�codejmr (�뱸ע)" << endl;
    cout << "QQ��3391966290���뱸ע��" << endl;
    cout << "���䣺wd.jiang@foxmail.com (��Ҫ����) \nwd.jiang@outlook.com (��Ҫ����)" << endl;
    cout << "�����Ա���Ʒ���κ����/���飬�����һ��Ҫ�����ң�лл��" << endl;
    cout << "����Ŀ��վ��https://github.com/jiangmuran/yiqingmoni/tree/New2.0" << endl;
    cout << "�����ѽ�������Ҫ�رգ��밴�°���Alt+F4";

}
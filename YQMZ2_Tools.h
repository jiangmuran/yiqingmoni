
struct people // ÿ���˵�����
{
    int x; // ����˵�x����
    int y; // ����˵�y����
    bool cr; // �Ƿ񱻴�Ⱦ
    bool mask; // �Ƿ������


};

void YZCreateCity(people* peoples, int HMP, int ScreenLenX, int ScreenLenY, int MNP, bool M0B); // ��������

void YZShowCityPeople(people* peos, unsigned how_many); // ���������ӡ����Ա��Ϣ

void YZShowScreenPeoples(people* CityPeople, int HMP, int PointB); // ��ʾÿ����

void YZMoveAllPeople(people* CityPeoples, int HMP, int Activity, int ScreenLenX, int ScreenLenY, int FarGL);// �ƶ�������Ա

void YZUpDateCR(people* CityPeoples, int HMP, int SafeLen, int MSafeLen, int& crs, int* crslist, int IP, int MIP); // �������������Ⲣ��Ⱦ

void YZShowMassage();


                                                       

                                                       

                                                       

                                                       
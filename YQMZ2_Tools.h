
struct people // 每个人的数据
{
    int x; // 这个人的x坐标
    int y; // 这个人的y坐标
    bool cr; // 是否被传染
    bool mask; // 是否戴口罩


};

void YZCreateCity(people* peoples, int HMP, int ScreenLenX, int ScreenLenY, int MNP, bool M0B); // 创建城市

void YZShowCityPeople(people* peos, unsigned how_many); // 这个函数打印出人员信息

void YZShowScreenPeoples(people* CityPeople, int HMP, int PointB); // 显示每个人

void YZMoveAllPeople(people* CityPeoples, int HMP, int Activity, int ScreenLenX, int ScreenLenY, int FarGL);// 移动所有人员

void YZUpDateCR(people* CityPeoples, int HMP, int SafeLen, int MSafeLen, int& crs, int* crslist, int IP, int MIP); // 这个函数用来检测并传染

void YZShowMassage();


                                                       

                                                       

                                                       

                                                       
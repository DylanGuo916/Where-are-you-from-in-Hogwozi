#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<windows.h>
#include<Mmsystem.h>
#include"MD5.h"
#include"Student.h"
using namespace std;
void PrintMessage(string s)//自定义打字机效果输出函数
{
    const char *p = s.c_str();
    while (true)
    {
        if (*p == '\0')
        {
            cout<<endl;
            break;
        }
        cout<<char(*p);
        fflush(stdout);
        Sleep(50);
        p++;
    }
}

int main()
{
    //开场白及人物设定
    PlaySound(TEXT("ChapterVIIofthenight.mp3"),NULL,SND_FILENAME | SND_ASYNC|SND_LOOP);//播放bgm
    srand(int(time(0))); //随机数设定

    const char *open1="----------------------------------------------------------------";
    PrintMessage(open1);

    const char *open2="---------------------霍格沃兹分院测试---------------------------";
    PrintMessage(open2);

    const char *open3="----------------------------------------------------------------";
    PrintMessage(open3);

    const char *begin1="霍格沃兹魔法学院共设四个分院，格兰芬多代表着勇敢，斯莱特林代表着高贵，拉文克劳代表着智慧，赫奇帕奇代表着正直，下面，请让分院帽决定你的性格所属吧！可别小看它，它可是充满智慧、会思想的魔帽，能看出你具备何种才能，从而将你分到适合的学院。";
    PrintMessage(begin1);

    const char *begin2="准备好了吗？分院测试开始啦！";
    PrintMessage(begin2);
	
    const char *begin3="首先，请告诉分院帽你的名字！";
    PrintMessage(begin3);

    char name1[50];
    cin>>name1;//输入人物名字

    const char *begin4="亲爱的";PrintMessage(begin4);const char *begin5=name1;PrintMessage(begin5); const char *begin6=",你的天赋属性为：";PrintMessage(begin6);

    Student a;//构造人物类a
    a.Set(name1);//调用参数设定函数
    a.Show();//调用参数展示函数

    const char *begin7="现在，请随分院帽前往第一站吧！（按下任意键及enter键确认进入）";
    PrintMessage(begin7);

    char key1;
    cin>>key1;//输入场景切换键

    system("cls");//清屏

//进入挑战第一关

    const char *test1="第一站:魔帽的考验";
    PrintMessage(test1);

    const char *test2="请仔细回答下面问题，千万不要在分院帽面前耍花招，它可是能够查知你内心深处最隐秘想法的魔帽！";
    PrintMessage(test2);

    a.Test();//调用第一关测试题函数

    const char *test3="恭喜你完成第一站“魔帽的考验 ”，你的当前属性为：";
    PrintMessage(test3);
    cout<<endl;
    a.Show();

    const char *test4="下面，请随分院帽前往第二站吧！（按下任意键及enter键确认进入）";
    PrintMessage(test4);

    char key2;
    cin>>key2;

    system("cls");


/////////////////////////////////////////////////////////////////////////////////////////////
////进入挑战第二关///////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////


    const char *exam1="第二站：智慧的角逐";
    PrintMessage(exam1);

    const char *exam2="学院史上最聪明的麻瓜女孩向你发出了挑战，只要你顺利回答下列问题，她就愿意承认你是一名合格的魔法师并协助你之后的学习，准备好迎接挑战了吗？那么，请仔细思考并回答下列问题，作弊传小纸条可能会惹怒她哦！";
    PrintMessage(exam2);

    a.Exam();//调用第二关测试题函数

    const char *exam3="经过两轮的测试，你的当前属性为：";
    PrintMessage (exam3);
    a.Show();

    const char *exam4="挑战愈发艰苦，准备好了吗？下面，就随分院帽前往第三站吧！（按下任意键及enter键确认进入）";
    PrintMessage(exam4);

    char key3;
    cin>>key3;

    system("cls");
//进入挑战第三关

    const char *fight1="第三站：魔法的较量";
    PrintMessage(fight1);

    const char *fight2="在这一站，你将与同为新生的夜猴侠进行对决，展现你们在这段时间里学习的魔法知识，友谊第一比赛第二，切记不要误伤观众哦！校长可在阁楼上看着你呢";
    PrintMessage(fight2);
  
    char name2[]="夜猴侠";
    Student b;//构造人物类b
    b.Set(name2);

    const char *fight3="准备好了吗？那就拿起魔杖，全力以赴吧！";
    PrintMessage(fight3);

    const char *fight33="（按下任意键及enter键确认进入战斗）";
    PrintMessage(fight33);

    char key33;
    cin>>key33;

    const char *fight4="战斗加载中...........................................................";
    PrintMessage(fight4);

    const char *fight5="---------------------------战斗开始----------------------------------";
    PrintMessage(fight5);
	
    int bl1,bl2;//a,b的实时血量
    while(true)
    {
        a.Attack(b);//a攻击b
        bl1=a.getBLOOD();//调用获得当前血量函数
        bl2=b.getBLOOD();
        if(bl1<=0||bl2<=0)break;//判定战斗是否结束
        Sleep(2000);

        b.Attack(a);//b攻击a
        bl1=a.getBLOOD();
        bl2=b.getBLOOD();
        if(bl1<=0||bl2<=0)break;
        Sleep(2000);
    }

    if(bl1<=0)cout<<name1<<"倒下，"<<name2<<"获胜！"<<endl;//判定获胜方
    if(bl2<=0)cout<<name2<<"倒下，"<<name1<<"获胜！"<<endl;

    const char *fight6="---------------------------战斗结束----------------------------------";
    PrintMessage(fight6);

    if(bl1<=0)
    {
        const char *fight7="很遗憾，你在对决中不敌夜猴侠，但是不要灰心，分院帽已经看出了你的潜力所在，接下来，就跟随它进入最终的分院仪式吧！";
        PrintMessage(fight7);
    }
    if(bl2<=0)
    {
        a.Buff();//调用获胜后勇敢buff加成函数
        const char *fight8="恭喜你在对决中成功打败夜猴侠，不过不要骄傲，在霍格沃兹你要学习的东西还很多，现在，赶紧随分院帽前往最终的分院仪式吧！";
        PrintMessage(fight8);
    }

    const char *fight9="（按下任意键及enter键确认进入）";
    PrintMessage(fight9);

    char key4;
    cin>>key4;

    system("cls");

//结束语

    PlaySound(TEXT("ChapterVIIofthenight.mp3"),NULL,SND_FILENAME | SND_ASYNC|SND_LOOP);//切换bgm

    const char *end1="亲爱的";PrintMessage(end1);const char *end2=name1;PrintMessage(end2); const char *end3="，根据分院帽的决意，你最终进入的学院是：";PrintMessage(end3);

    int d=a.Decide();//调用学院判定函数
    if(d==1)//格兰芬多
    {
        const char *end2="格兰芬多！";
        PrintMessage(end2);

        const char *end22="这里有埋藏在心底的勇敢，胆识、气魄和豪爽，使格兰芬多出类拔萃，愿你在格兰芬多开辟出新的天地！";
        PrintMessage(end22);
    }
    if(d==2)//斯莱特林
    {
        const char *end3="斯莱特林！";
        PrintMessage(end3);

        const char *end33="也许你在这里交上真诚的朋友，但那些狡诈阴险之辈却会不惜一切手段，去达到他们的目的，愿你在斯莱特林始终保留纯真";
        PrintMessage(end33);
    }
    if(d==3)//拉文克劳
    {
        const char *end4="拉文克劳！";
        PrintMessage(end4);

        const char *end44="头脑精明，睿智博学的人都汇聚在拉文克劳，你总会在这里遇见你的同道，愿你在拉文克劳收获更多魔法知识！";
        PrintMessage(end44);
    }
    if(d==4)//赫奇帕奇
    {
        const char *end5="赫奇帕奇！";
        PrintMessage(end5);

        const char *end55="这里的人正直忠诚，赫奇帕奇的学子们永远坚忍诚实，不畏惧艰辛的劳动，愿你在赫奇帕奇找到志同道合的伙伴";
        PrintMessage(end55);
    }

    const char *end6="当然，无论你属于哪个学院，你永远是霍格沃兹的学子，也请永远牢记霍格沃兹的校训，“永远不要逗弄一条沉睡的龙”，年轻的魔法师，未来可期，请用你手中的魔杖去创造，去守护，去战斗吧！";
    PrintMessage(end6);

    const char *end7="最后，请选择你最舒心的曲调，与我们一同唱起校歌，享受晚宴吧！";
    PrintMessage(end7);

    const char *end8="----------------------------------------------------------------";
    PrintMessage(end8);

    Sleep(2000);
    cout<<" "<<endl<<"Hogwarts,Hogwarts,Hoggy Warty Hogwarts"<<endl;
    Sleep(2000);
    cout<<" "<<endl<<"Teach us something please"<<endl;
    Sleep(2000);
    cout<<" "<<endl<<"Whether we be old and bald"<<endl;
    Sleep(2000);
    cout<<" "<<endl<<"Or young with scabby knees"<<endl;
    Sleep(2000);
    cout<<" "<<endl<<"Our heads could do with filling"<<endl;
    Sleep(2000);
    cout<<" "<<endl<<"With some interesting stuff"<<endl;
    Sleep(2000);
    cout<<" "<<endl<<"For now they are bare and full of air"<<endl;
    Sleep(2000);
    cout<<" "<<endl<<"Dead flies and bits of fluff"<<endl;
    Sleep(2000);
    cout<<" "<<endl<<"So teach us things worth knowing"<<endl;
    Sleep(2000);
    cout<<" "<<endl<<"Bring back what we have forgot"<<endl;
    Sleep(2000);
    cout<<" "<<endl<<"Just do your best,we'll do the rest"<<endl;
    Sleep(2000);
    cout<<" "<<endl<<"And learn until our brains all rot"<<" "<<endl;
    Sleep(2000);

    const char *end9="----------------------------------------------------------------";
    PrintMessage(end9);

    const char *end10="-------------------------------END------------------------------";
    PrintMessage(end10);

    return 0;
}

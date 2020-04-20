#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<windows.h>
#include<Mmsystem.h>
#include"MD5.h"
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
class Student//人物类
{
	private:
		char name[50];//姓名
		int blood;//血量
		int brave;//勇敢
		int noble;//高贵
		int wisdom;//智慧
		int integrity;//正直
	public:
		void Set(char name[50]);//人物参数设置
		void Show();//展示参数
		void Test();//第一关测试题函数
		void Exam();//第二关测试题函数
		void Attack(Student &s);//第三关战斗函数
		int getBLOOD();//获得当前血量函数
		void Buff();//胜利后勇敢Buff加成函数
		int Decide(); //学院判定函数
};

void Student::Set(char name[50])//人物参数设置
{
    for(int i=0;name[i]!='\0';i++)
        this->name[i]=name[i];
    blood = 300;
    string md5 = MD5(name).toString();
    double md5_sum[4] = {0, 0, 0, 0};
    double md5_point[4] = {0, 0, 0, 0};
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 8; j++)
            md5_sum[i] += int(md5[i * 8 + j]);
    for (int i = 0; i < 4; i++)
        md5_point[i] = floor(40 + (md5_sum[i] - 384) / 592 * 60 + 0.5);
    brave = md5_point[0];
    noble = md5_point[1];
    wisdom = md5_point[2];
    integrity = md5_point[3];
}

void Student::Show()//展示参数
{
    PrintMessage("血量："+to_string(blood));
    PrintMessage("勇敢："+to_string(brave));
    PrintMessage("高贵："+to_string(noble));
    PrintMessage("智慧："+to_string(wisdom));
    PrintMessage("正直："+to_string(integrity));
}

void Student::Test()//第一关测试题函数
{
    ifstream fin("test.txt");
    if (!fin)
    {
        cout<<"open failed"<<endl;
        return;
    }
    string question;
    string option;
    for (int i = 0;i < 10; ++i)
    {
        getline(fin, question);
        PrintMessage(question);
        getline(fin, option);
        PrintMessage(option);
        char anwser;
        cin >> anwser;
        if(anwser == 'a' || anwser == 'A') integrity += 3;
        if(anwser == 'b' || anwser == 'B') brave += 3;
        if(anwser == 'c' || anwser == 'C') noble += 3;
        if(anwser == 'd' || anwser == 'D') wisdom += 3;
    }
}

void Student::Exam()//第二关测试题函数
{
    int countOfRight = 0;
    ifstream fin("exam.txt");
    if (!fin)
    {
        cout<<"open failed"<<endl;
        return;
    }
    string question;
    string option;
    char* ans= "BBCAABDDA";
    for (int i = 0;i < 9; ++i)
    {
        getline(fin, question);
        PrintMessage(question);
        getline(fin, option);
        PrintMessage(option);
        char answer;
        cin>>answer;
        if(answer == ans[i] || answer == ans[i]-32)
        {
            wisdom += 5;
            countOfRight++;
            PrintMessage("恭喜你答对了！");
        } else
        {
            PrintMessage("很遗憾，答错了～");
            wisdom -= 5;
        }
    }
    if(countOfRight > 6)//第二关测试通过
        PrintMessage( "没想到你竟这么聪明，成功通过第二站“智慧的角逐 ”，日后你就可以到格兰芬多找赫敏.格兰杰，和她一同学习啦！");
    else//第二关测试没通过
        PrintMessage("现在有一个坏消息和一个好消息，坏消息是你答错的太多啦，好消息是你把她气走了，她并不会对你大打出手");
}

void Student::Attack(Student &s) //第三关战斗函数
{
    int attack;
    attack = rand() % 20 + 0.5 * brave - 0.1 * s.wisdom;//伤害值
    int k = rand() % 11;//十一种招式
    int j = rand() %2 ;//两种应对
    switch (k)
    {
        case 0:
            cout<<name<<"向"<<s.name<<"发起了[蛇蛇攻]，";
            if(j==0)//应对一
            {
                cout << s.name << "不堪毒蛇侵扰，受到了" << attack << "点伤害" << endl;
                s.blood-=attack;
            }
            if(j==1)//应对二
            {
                cout<<s.name<<"使出[幻影移行咒]巧妙躲闪，逃过一击"<<endl;
                s.wisdom+=3;
            }
            break;
        case 1:
            cout<<name<<"向"<<s.name<<"发起了[软腿咒]，";
            if(j==0)//应对一
            {
                cout << s.name << "变为软脚虾，随即遭受魔法连击，受到了" << attack << "点伤害" << endl;
                s.blood-=attack;
                noble-=5;
            }
            if(j==1)//应对二
            {
                cout << s.name << "使出[嘶嘶退]，" << name << "被逼后退，反被火花灼烧，受到" << attack << "点伤害" << endl;
                blood-=attack;
                s.wisdom+=3;
            }
            break;
        case 2:
            cout<<name<<"向"<<s.name<<"发起了[塔朗泰拉舞咒]，";
            if(j==0)//应对一
            {
                cout<<s.name<<"躲闪不及，疯狂地跳起踢踏舞，颜面扫地"<<endl;
                s.noble-=3;
            }
            if(j==1)//应对二
            {
                cout<<s.name<<"使出[咒立停]拦截了魔法"<<endl;
                s.wisdom+=3;
            }
            break;
        case 3:
            cout<<name<<"向"<<s.name<<"发起了[漂浮咒]，";
            if(j==0)//应对一
            {
                attack= 3 * attack;
                cout << name << "飞上前竟打出暴击，造成了" << attack << "点伤害" << endl;
                s.blood-=attack;
                brave+=5;
            }
            if(j==1)//应对二
            {
                cout << name << "飞上前打出连击，造成了" << attack << "点伤害" << endl;
                s.blood-=attack;
            }
            break;
        case 4:
            cout<<name<<"念错咒语，误用了[噗噗兰]，魔杖尖端冒出朵朵小花，";
            if(j==0)//应对一
            {
                cout << s.name << "抓住机会，使出[飞飞禽]，造成了" << attack << "点伤害" << endl;
                blood-=attack;
                wisdom-=5;
                noble+=5;
            }
            if(j==1)//应对二
            {
                cout << s.name << "被乱花迷了眼，一个不慎摔落在地，受到了" << attack << "点伤害" << endl;
                s.blood-=attack;
                wisdom-=5;
                noble+=5;
            }
            break;
        case 5:
            cout<<name<<"向"<<s.name<<"发起了[摄取魂念咒]，";
            if(j==0)//应对一
            {
                cout << s.name << "骤然失去神智，误伤自己，受到了" << attack << "点伤害" << endl;
                s.blood-=attack;
                integrity-=5;

            }
            if(j==1)//应对二
            {
                cout<<s.name<<"捂住耳朵大喊我不听我不听，逃过一击"<<endl;
                noble-=5;
                integrity-=5;
            }
            break;
        case 6:
            cout<<name<<"向"<<s.name<<"发起了[咧嘴呼啦啦]，银色光芒笼罩"<<s.name<<"，";
            if(j==0)//应对一
            {
                cout<<s.name<<"笑得无法动弹，错过了最佳反击时间"<<endl;
                s.noble-=2;
            }
            if(j==1)//应对二
            {
                cout<<s.name<<"使出[咒立停拦截了魔法]"<<endl;
                s.wisdom+=5;
            }
            break;
        case 7:
            cout<<name<<"向"<<s.name<<"发起了[熔熔沸]，";
            if(j==0)//应对一
            {
                cout << s.name << "手臂被击中，受到了" << attack << "点伤害" << endl;
                s.blood-=attack;
            }
            if(j==1)//应对二
            {
                cout<<s.name<<"使出[幻影移行咒]巧妙躲闪，不慎误伤观众"<<endl;
                s.integrity-=7;
            }
            break;
        case 8:
            cout<<name<<"使出了[快快复苏]，";
            if(j==0)//应对一
            {
                cout << "只见一道白光闪过，瞬间恢复了" << attack << "点血量" << endl;
                blood+=attack;
            }
            if(j==1)//应对二
            {
                cout << s.name << "使出[咒立停]阻碍了治疗，并追加拳击，造成了" << attack << "点伤害" << endl;
                blood-=attack;
            }
            break;
        case 9:
            cout<<name<<"使出了[呼呼移]，瞬间将大石头化作武器，";
            if(j==0)//应对一
            {
                attack= 3 * attack;
                cout << s.name << "闪避不及，被石头砸中，受到了暴击" << attack << "点伤害" << endl;
                s.blood-=attack;
            }
            if(j==1)//应对二
            {
                attack= 0.3 * attack;
                cout << s.name << "使出[四分五裂]，及时粉碎，只受到了" << attack << "点伤害" << endl;
                s.blood-=attack;
            }
            break;
        case 10:
            cout<<name<<"向"<<s.name<<"发起了[瓦迪瓦西咒]，";
            if(j==0)//应对一
            {
                cout << s.name << "被子弹击中，受到了" << attack << "点伤害" << endl;
                s.blood-=attack;
            }
            if(j==1)//应对二
            {
                cout << s.name << "使出[呼呼移]，将子弹扭转方向，" << name << "反受到了" << attack << "点伤害" << endl;
                blood-=attack;
            }
            break;
        default:
            break;
    }
}

int Student::getBLOOD()//获得当前血量函数
{
	return blood;
}

void Student::Buff()//胜利后勇敢Buff加成函数
{
	brave+=20;
}

int Student::Decide()//学院判定函数
{
	if(brave>=noble&&brave>=wisdom&&brave>=integrity)return 1;
	if(noble>brave&&noble>=wisdom&&noble>=integrity)return 2;
	if(wisdom>brave&&wisdom>noble&&wisdom>=integrity)return 3;
	if(integrity>brave&&integrity>noble&integrity>wisdom)return 4;
}

int main()
{
	//开场白及人物设定
	PlaySound(TEXT(".\\begin.wav"),NULL,SND_FILENAME | SND_ASYNC|SND_LOOP);//播放bgm
	srand(int(time(0))); //随机数设定

	const char *open1="----------------------------------------------------------------";
	Print(open1);
	cout<<endl;

	const char *open2="---------------------霍格沃兹分院测试---------------------------";
	Print(open2);
	cout<<endl;

	const char *open3="----------------------------------------------------------------";
	Print(open3);
	cout<<endl;

	const char *begin1="霍格沃兹魔法学院共设四个分院，格兰芬多代表着勇敢，斯莱特林代表着高贵，拉文克劳代表着智慧，赫奇帕奇代表着正直，下面，请让分院帽决定你的性格所属吧！可别小看它，它可是充满智慧、会思想的魔帽，能看出你具备何种才能，从而将你分到适合的学院。";
	Print(begin1);
	cout<<endl;

	const char *begin2="准备好了吗？分院测试开始啦！";
	Print(begin2);
	cout<<endl;

	const char *begin3="首先，请告诉分院帽你的名字！";
	Print(begin3);
	cout<<endl;

	char name1[50];
	cin>>name1;//输入人物名字

	const char *begin4="亲爱的";Print(begin4);const char *begin5=name1;Print(begin5); const char *begin6=",你的天赋属性为：";Print(begin6);
	cout<<endl;

	Student a;//构造人物类a
	a.Set(name1);//调用参数设定函数
	a.Show();//调用参数展示函数

	const char *begin7="现在，请随分院帽前往第一站吧！（按下任意键及enter键确认进入）";
	Print(begin7);
	cout<<endl;

	char key1;
	cin>>key1;//输入场景切换键

	system("cls");//清屏


/////////////////////////////////////////////////////////////////////////////////////////////
////进入挑战第一关///////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////


	const char *test1="第一站:魔帽的考验";
	Print(test1);
	cout<<endl;

	const char *test2="请仔细回答下面问题，千万不要在分院帽面前耍花招，它可是能够查知你内心深处最隐秘想法的魔帽！";
	Print(test2);
	cout<<endl;

	a.Test();//调用第一关测试题函数

	const char *test3="恭喜你完成第一站“魔帽的考验 ”，你的当前属性为：";
	Print(test3);
	cout<<endl;
	a.Show();

	const char *test4="下面，请随分院帽前往第二站吧！（按下任意键及enter键确认进入）";
	Print(test4);
	cout<<endl;

	char key2;
	cin>>key2;

	system("cls");


/////////////////////////////////////////////////////////////////////////////////////////////
////进入挑战第二关///////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////


	const char *exam1="第二站：智慧的角逐";
	Print(exam1);
	cout<<endl;

	const char *exam2="学院史上最聪明的麻瓜女孩向你发出了挑战，只要你顺利回答下列问题，她就愿意承认你是一名合格的魔法师并协助你之后的学习，准备好迎接挑战了吗？那么，请仔细思考并回答下列问题，作弊传小纸条可能会惹怒她哦！";
	Print(exam2);
	cout<<endl;

	a.Exam();//调用第二关测试题函数

	const char *exam3="经过两轮的测试，你的当前属性为：";
	Print (exam3);
	cout<<endl;
	a.Show();

	const char *exam4="挑战愈发艰苦，准备好了吗？下面，就随分院帽前往第三站吧！（按下任意键及enter键确认进入）";
	Print(exam4);
	cout<<endl;

	char key3;
	cin>>key3;

	system("cls");


/////////////////////////////////////////////////////////////////////////////////////////////
////进入挑战第三关///////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////


	const char *fight1="第三站：魔法的较量";
	Print(fight1);
	cout<<endl;

	const char *fight2="在这一站，你将与同为新生的夜猴侠进行对决，展现你们在这段时间里学习的魔法知识，友谊第一比赛第二，切记不要误伤观众哦！校长可在阁楼上看着你呢";
	Print(fight2);
	cout<<endl;

	char name2[]="夜猴侠";
	Student b;//构造人物类b
	b.Set(name2);

	const char *fight3="准备好了吗？那就拿起魔杖，全力以赴吧！";
	Print(fight3);
	cout<<endl;

	const char *fight33="（按下任意键及enter键确认进入战斗）";
	Print(fight33);
	cout<<endl;

    char key33;
	cin>>key33;

	const char *fight4="战斗加载中...........................................................";
	Print(fight4);
	cout<<endl;



	const char *fight5="---------------------------战斗开始----------------------------------";
	Print(fight5);
	cout<<endl;

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
	Print(fight6);
	cout<<endl;

	if(bl1<=0)
	{
		const char *fight7="很遗憾，你在对决中不敌夜猴侠，但是不要灰心，分院帽已经看出了你的潜力所在，接下来，就跟随它进入最终的分院仪式吧！";
		Print(fight7);
		cout<<endl;
	}
	if(bl2<=0)
	{
		a.Buff();//调用获胜后勇敢buff加成函数
		const char *fight8="恭喜你在对决中成功打败夜猴侠，不过不要骄傲，在霍格沃兹你要学习的东西还很多，现在，赶紧随分院帽前往最终的分院仪式吧！";
		Print(fight8);
		cout<<endl;
	}

	const char *fight9="（按下任意键及enter键确认进入）";
	Print(fight9);
	cout<<endl;

    char key4;
	cin>>key4;

	system("cls");


/////////////////////////////////////////////////////////////////////////////////////////////
////结束语///////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

    PlaySound(TEXT(".\\end.wav"),NULL,SND_FILENAME | SND_ASYNC|SND_LOOP);//切换bgm

	const char *end1="亲爱的";Print(end1);const char *end2=name1;Print(end2); const char *end3="，根据分院帽的决意，你最终进入的学院是：";Print(end3);
	cout<<endl;

	int d=a.Decide();//调用学院判定函数
	if(d==1)//格兰芬多
	{
		const char *end2="格兰芬多！";
		Print(end2);
		cout<<endl;

		const char *end22="这里有埋藏在心底的勇敢，胆识、气魄和豪爽，使格兰芬多出类拔萃，愿你在格兰芬多开辟出新的天地！";
		Print(end22);
		cout<<endl;
	}
	if(d==2)//斯莱特林
	{
		const char *end3="斯莱特林！";
		Print(end3);
		cout<<endl;

		const char *end33="也许你在这里交上真诚的朋友，但那些狡诈阴险之辈却会不惜一切手段，去达到他们的目的，愿你在斯莱特林始终保留纯真";
		Print(end33);
		cout<<endl;
	}
	if(d==3)//拉文克劳
	{
		const char *end4="拉文克劳！";
		Print(end4);
		cout<<endl;

		const char *end44="头脑精明，睿智博学的人都汇聚在拉文克劳，你总会在这里遇见你的同道，愿你在拉文克劳收获更多魔法知识！";
		Print(end44);
		cout<<endl;
	}
	if(d==4)//赫奇帕奇
	{
		const char *end5="赫奇帕奇！";
		Print(end5);
		cout<<endl;

		const char *end55="这里的人正直忠诚，赫奇帕奇的学子们永远坚忍诚实，不畏惧艰辛的劳动，愿你在赫奇帕奇找到志同道合的伙伴";
		Print(end55);
		cout<<endl;
	}

	const char *end6="当然，无论你属于哪个学院，你永远是霍格沃兹的学子，也请永远牢记霍格沃兹的校训，“永远不要逗弄一条沉睡的龙”，年轻的魔法师，未来可期，请用你手中的魔杖去创造，去守护，去战斗吧！";
	Print(end6);
	cout<<endl;

	const char *end7="最后，请选择你最舒心的曲调，与我们一同唱起校歌，享受晚宴吧！";
	Print(end7);
	cout<<endl;

	const char *end8="----------------------------------------------------------------";
	Print(end8);
	cout<<endl;

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
	Print(end9);
	cout<<endl;

	const char *end10="-------------------------------END------------------------------";
	Print(end10);
	cout<<endl;

	return 0;
}

#include<iostream>
#include<windows.h>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<Mmsystem.h>
#include<stdio.h>
#include<iostream>
#include<fstream>

using namespace std;

void Print(const char *p)//打字机效果输出
{
	while (1)
    {
        if (0==*p) break;
        printf("%c",*p);fflush(stdout);
        Sleep(50);
        p++;
    }

}
class Student//人物类
{
	private:
		char name[10000];//姓名
		int blood;//血量
		int brave;//勇敢
		int noble;//高贵
		int wisdom;//智慧
		int integrity;//正直
	public:
		void Set(char na[10000]);//人物参数设置
		void Show();//展示参数
		void Test();//第一关测试题函数
		void Exam();//第二关测试题函数
		void Attack(Student &s);//第三关战斗函数
		int getBLOOD();//获得当前血量函数
		void Buff();//胜利后勇敢Buff加成函数
		int Decide(); //学院判定函数
};

void Student::Set(char na[10000])//人物参数设置
{
	//int l=strlen(na);
	for(int i=0;na[i]!='\0';i++)
	name[i]=na[i];
	blood=300;
	brave=rand()%100;
	noble=rand()%100;
	wisdom=rand()%100;
	integrity=rand()%100;
}

void Student::Show()//展示参数
{
	cout<<"血量："<<blood<<endl<<"勇敢："<<brave<<endl<<"高贵："<<noble<<endl<<"智慧："<<wisdom<<endl<<"正直："<<integrity<<endl;
}

void Student::Test()//第一关测试题函数
{
	const char *T1="Q1:你最希望拥有的魔力是：";
	Print(T1);
	cout<<endl;
	const char *choose1="A.飞翔术 B.隐身术 C.变形术 D.超能量";
	Print(choose1);
	cout<<endl;
	char t1;
	cin>>t1;
	if(t1=='a'||t1=='A')integrity+=3;
	if(t1=='b'||t1=='B')brave+=3;
	if(t1=='c'||t1=='C')noble+=3;
	if(t1=='d'||t1=='D')wisdom+=3;

	const char *T2="Q2:你最想要以下哪个动物当宠物：";
	Print(T2);
	cout<<endl;
	const char *choose2="A.老鼠 B.猫头鹰 C.蛇 D.猴子";
	Print(choose2);
	cout<<endl;
	char t2;
	cin>>t2;
	if(t2=='a'||t2=='A')integrity+=3;
	if(t2=='b'||t2=='B')brave+=3;
	if(t2=='c'||t2=='C')noble+=3;
	if(t2=='d'||t2=='D')wisdom+=3;

	const char *T3="Q3:你最害怕的动物是：";
	Print(T3);
	cout<<endl;
	const char *choose3=" A.阴毒的蛇类 B.不明的神秘动物 C.凶恶的犬类 D.昆虫类动物 ";
	Print(choose3);
	cout<<endl;
	char t3;
	cin>>t3;
	if(t3=='a'||t3=='A')integrity+=3;
	if(t3=='b'||t3=='B')brave+=3;
	if(t3=='c'||t3=='C')noble+=3;
	if(t3=='d'||t3=='D')wisdom+=3;

	const char *T4="Q4:你最希望在魁地奇中扮演的角色是: ";
	Print(T4);
	cout<<endl;
	const char *choose4=" A.守门员 B.找球手 C.追球手 D.击球手 ";
	Print(choose4);
	cout<<endl;
	char t4;
	cin>>t4;
	if(t4=='a'||t4=='A')integrity+=3;
	if(t4=='b'||t4=='B')brave+=3;
	if(t4=='c'||t4=='C')noble+=3;
	if(t4=='d'||t4=='D')wisdom+=3;

	const char *T5="Q5:假如你在路上拾到一袋加隆金币，你会: ";
	Print(T5);
	cout<<endl;
	const char *choose5=" A.寻找失主归还 B.捐献 C.花掉 D.存起来 ";
	Print(choose5);
	cout<<endl;
	char t5;
	cin>>t5;
	if(t5=='a'||t5=='A')integrity+=3;
	if(t5=='b'||t5=='B')brave+=3;
	if(t5=='c'||t5=='C')noble+=3;
	if(t5=='d'||t5=='D')wisdom+=3;

	const char *T6="Q6:你最喜欢的魔法课程是: ";
	Print(T6);
	cout<<endl;
	const char *choose6=" A.魔药课 B.黑魔法防御课 C.变形术课 D.魔法史课 ";
	Print(choose6);
	cout<<endl;
	char t6;
	cin>>t6;
	if(t6=='a'||t6=='A')integrity+=3;
	if(t6=='b'||t6=='B')brave+=3;
	if(t6=='c'||t6=='C')noble+=3;
	if(t6=='d'||t6=='D')wisdom+=3;

	const char *T7="Q7:你深夜走在小巷里，忽然有一条巨蛇拦住你，你会：";
	Print(T7);
	cout<<endl;
	const char *choose7=" A.撒腿就跑 B.和它搏斗 C.静观其变 D.装死 ";
	Print(choose7);
	cout<<endl;
	char t7;
	cin>>t7;
	if(t7=='a'||t7=='A')integrity+=3;
	if(t7=='b'||t7=='B')brave+=3;
	if(t7=='c'||t7=='C')noble+=3;
	if(t7=='d'||t7=='D')wisdom+=3;

	const char *T8="Q8:如果让你保管魔法石，你把它藏在哪里: ";
	Print(T8);
	cout<<endl;
	const char *choose8=" A.浴室镜子后面 B.自己口袋里 C.马桶水箱里 D.书架的角落里 ";
	Print(choose8);
	cout<<endl;
	char t8;
	cin>>t8;
	if(t8=='a'||t8=='A')integrity+=3;
	if(t8=='b'||t8=='B')brave+=3;
	if(t8=='c'||t8=='C')noble+=3;
	if(t8=='d'||t8=='D')wisdom+=3;

	const char *T9="Q9:你希望在圣诞节吃到: ";
	Print(T9);
	cout<<endl;
	const char *choose9=" A.烤鸡翅 B.蛋糕 C.巧克力 D.香肠 ";
	Print(choose9);
	cout<<endl;
	char t9;
	cin>>t9;
	if(t9=='a'||t9=='A')integrity+=3;
	if(t9=='b'||t9=='B')brave+=3;
	if(t9=='c'||t9=='C')noble+=3;
	if(t9=='d'||t9=='D')wisdom+=3;

	const char *T10="Q10:你对穿衣打扮的态度是: ";
	Print(T10);
	cout<<endl;
	const char *choose10=" A.没要求有什么穿什么 B.实用，口袋多多 C.要名牌 D.穿着得体 ";
	Print(choose10);
	cout<<endl;
	char t10;
	cin>>t10;
	if(t10=='a'||t10=='A')integrity+=3;
	if(t10=='b'||t10=='B')brave+=3;
	if(t10=='c'||t10=='C')noble+=3;
	if(t10=='d'||t10=='D')wisdom+=3;

	const char *T11="Q11:如果有一天空闲的时间，你会: ";
	Print(T11);
	cout<<endl;
	const char *choose11=" A.体育锻炼 B.睡觉 C.和朋友聊天 D.独自看书，看电影 ";
	Print(choose11);
	cout<<endl;
	char t11;
	cin>>t11;
	if(t11=='a'||t11=='A')integrity+=3;
	if(t11=='b'||t11=='B')brave+=3;
	if(t11=='c'||t11=='C')noble+=3;
	if(t11=='d'||t11=='D')wisdom+=3;

	const char *T12="Q12:如果你受了某人的欺辱，你会：";
	Print(T12);
	cout<<endl;
	const char *choose12=" A.息事宁人 B.和他单挑 C.找人教训他 D.打得过就打，打不过就跑 ";
	Print(choose12);
	cout<<endl;
	char t12;
	cin>>t12;
	if(t12=='a'||t12=='A')integrity+=3;
	if(t12=='b'||t12=='B')brave+=3;
	if(t12=='c'||t12=='C')noble+=3;
	if(t12=='d'||t12=='D')wisdom+=3;

	const char *T13="Q13:你最厌恶哪种情况在你身上发生: ";
	Print(T13);
	cout<<endl;
	const char *choose13=" A.被怀疑 B.孤独寂寞 C.肮脏不堪 D.被嘲笑 ";
	Print(choose13);
	cout<<endl;
	char t13;
	cin>>t13;
	if(t13=='a'||t13=='A')integrity+=3;
	if(t13=='b'||t13=='B')brave+=3;
	if(t13=='c'||t13=='C')noble+=3;
	if(t13=='d'||t13=='D')wisdom+=3;

	const char *T14="Q14:你最不希望自己被分到哪个学院：";
	Print(T14);
	cout<<endl;
	const char *choose14=" A.拉文克劳 B.斯莱特林 C.格兰芬多 D.赫奇帕奇 ";
	Print(choose14);
	cout<<endl;
	char t14;
	cin>>t14;
	if(t14=='a'||t14=='A')integrity+=3;
	if(t14=='b'||t14=='B')brave+=3;
	if(t14=='c'||t14=='C')noble+=3;
	if(t14=='d'||t14=='D')wisdom+=3;

}

void Student::Exam()//第二关测试题函数
{
	int count=0;

	const char *E1="Q1:下面哪个不是霍格沃兹的校长：";
	Print(E1);
	cout<<endl;
	const char *a1=" A.邓布利多 B.汤布利伯 C.斯内普 D.麦格";
	Print(a1);
	cout<<endl;
	char e1;
	cin>>e1;
	if(e1=='b'||e1=='B')
	{
	    wisdom+=5;
	    count++;
	}
	else wisdom-=5;


	const char *E2="Q2:下面哪个不是不可饶恕咒: ";
	Print(E2);
	cout<<endl;
	const char *a2=" A.阿瓦达索命  B.瓦迪瓦西  C.魂魄出鞘  D.钻心剜骨 ";
	Print(a2);
	cout<<endl;
	char e2;
	cin>>e2;
	if(e2=='b'||e2=='B')
	{
	    wisdom+=5;
	    count++;
	}
	else wisdom-=5;

	const char *E3="Q3:前往霍格沃兹的站台名称是：";
	Print(E3);
	cout<<endl;
	const char *a3=" A.7又8分之5  B.8又7分之6  C.9又4分之3  D.都是 ";
	Print(a3);
	cout<<endl;
	char e3;
	cin>>e3;
	if(e3=='c'||e3=='C')
	{
	    wisdom+=5;
	    count++;
	}
	else wisdom-=5;

	const char *E4="Q4:蛇毒作为药用不具有下面哪一种功效? ";
	Print(E4);
	cout<<endl;
	const char *a4=" A.麻醉 B.促凝 C.镇痛 D.抗癌 ";
	Print(a4);
	cout<<endl;
	char e4;
	cin>>e4;
	if(e4=='a'||e4=='A')
	{
	    wisdom+=5;
	    count++;
	}
	else wisdom-=5;

	const char *E5="Q5:鱼有耳朵吗？";
	Print(E5);
	cout<<endl;
	const char *a5=" A.有 B.没有 ";
	Print(a5);
	cout<<endl;
	char e5;
	cin>>e5;
	if(e5=='a'||e5=='A')
	{
	    wisdom+=5;
	    count++;
	}
	else wisdom-=5;

	const char *E6="Q6:天然气主要成分是？";
	Print(E6);
	cout<<endl;
	const char *a6=" A.甲醛 B.甲烷 C.甲醇 D.乙醇 ";
	Print(a6);
	cout<<endl;
	char e6;
	cin>>e6;
	if(e6=='b'||e6=='B')
	{
	    wisdom+=5;
	    count++;
	}
	else wisdom-=5;

	const char *E7="Q7:sinx的导数是：";
	Print(E7);
	cout<<endl;
	const char *a7=" A.sinx B.1/sinx C.-cosx D.cosx ";
	Print(a7);
	cout<<endl;
	char e7;
	cin>>e7;
	if(e7=='d'||e7=='D')
	{
	    wisdom+=5;
	    count++;
	}
	else wisdom-=5;

	const char *E8="Q8:哪种维生素可促进钙的吸收：";
	Print(E8);
	cout<<endl;
	const char *a8=" A.维生素A B.维生素B C.维生素C D.维生素D ";
	Print(a8);
	cout<<endl;
	char e8;
	cin>>e8;
	if(e8=='d'||e8=='D')
	{
	    wisdom+=5;
	    count++;
	}
	else wisdom-=5;

	const char *E9="Q9:一个苹果最甜的地方是哪个部位？";
	Print(E9);
	cout<<endl;
	const char *a9=" A.顶部 B.中部 C.底部 D.都甜 ";
	Print(a9);
	cout<<endl;
	char e9;
	cin>>e9;
	if(e9=='a'||e9=='A')
	{
	    wisdom+=5;
	    count++;
	}
	else wisdom-=5;

	if(count>6)//第二关测试通过
	{
		const char *zhuan1="没想到你竟这么聪明，成功通过第二站“智慧的角逐 ”，日后你就可以到格兰芬多找赫敏.格兰杰，和她一同学习啦！";
		Print(zhuan1);
		cout<<endl;
	}
	if(count<=6)//第二关测试不通过
	{
		const char *zhuan2="现在有一个坏消息和一个好消息，坏消息是你答错的太多啦，好消息是你把她气走了，她并不会对你大打出手";
		Print(zhuan2);
		cout<<endl;
	}
}

void Student::Attack(Student &s) //第三关战斗函数
{
	int a1;
	a1=rand()%20+0.5*brave-0.1*s.wisdom;//伤害值
	int k=rand()%11;//十一种招式
	int j=rand()%2;//两种应对

    if(k==0)//招式一
    {
	        cout<<name<<"向"<<s.name<<"发起了[蛇蛇攻]，";
			if(j==0)//应对一
			{
				cout<<s.name<<"不堪毒蛇侵扰，受到了"<<a1<<"点伤害"<<endl;
				s.blood-=a1;
			}
			if(j==1)//应对二
			{
				cout<<s.name<<"使出[幻影移行咒]巧妙躲闪，逃过一击"<<endl;
				s.wisdom+=3;
			}
	}

	if(k==1)//招式二
	{
		cout<<name<<"向"<<s.name<<"发起了[软腿咒]，";
			if(j==0)//应对一
			{
				cout<<s.name<<"变为软脚虾，随即遭受魔法连击，受到了"<<a1<<"点伤害"<<endl;
				s.blood-=a1;
				noble-=5;
			}
			if(j==1)//应对二
			{
				cout<<s.name<<"使出[嘶嘶退]，"<<name<<"被逼后退，反被火花灼烧，受到"<<a1<<"点伤害"<<endl;
				blood-=a1;
				s.wisdom+=3;
			}

	}
	if(k==2)//招式三
    {
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
	}
	if(k==3)//招式四
    {
	        cout<<name<<"向"<<s.name<<"发起了[漂浮咒]，";
			if(j==0)//应对一
			{
				a1=3*a1;
				cout<<name<<"飞上前竟打出暴击，造成了"<<a1<<"点伤害"<<endl;
				s.blood-=a1;
				brave+=5;
			}
			if(j==1)//应对二
			{
				cout<<name<<"飞上前打出连击，造成了"<<a1<<"点伤害"<<endl;
				s.blood-=a1;
			}
	}
	if(k==4)//招式五
    {
	        cout<<name<<"念错咒语，误用了[噗噗兰]，魔杖尖端冒出朵朵小花，";
			if(j==0)//应对一
			{
				cout<<s.name<<"抓住机会，使出[飞飞禽]，造成了"<<a1<<"点伤害"<<endl;
				blood-=a1;
				wisdom-=5;
				noble+=5;
			}
			if(j==1)//应对二
			{
				cout<<s.name<<"被乱花迷了眼，一个不慎摔落在地，受到了"<<a1<<"点伤害"<<endl;
				s.blood-=a1;
				wisdom-=5;
				noble+=5;
			}
	}
	if(k==5)//招式六
    {
	        cout<<name<<"向"<<s.name<<"发起了[摄取魂念咒]，";
			if(j==0)//应对一
			{
				cout<<s.name<<"骤然失去神智，误伤自己，受到了"<<a1<<"点伤害"<<endl;
				s.blood-=a1;
				integrity-=5;

			}
			if(j==1)//应对二
			{
				cout<<s.name<<"捂住耳朵大喊我不听我不听，逃过一击"<<endl;
				noble-=5;
				integrity-=5;
			}
	}
	if(k==6)//招式七
    {
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
	}
	if(k==7)//招式八
    {
	        cout<<name<<"向"<<s.name<<"发起了[熔熔沸]，";
			if(j==0)//应对一
			{
				cout<<s.name<<"手臂被击中，受到了"<<a1<<"点伤害"<<endl;
				s.blood-=a1;
			}
			if(j==1)//应对二
			{
				cout<<s.name<<"使出[幻影移行咒]巧妙躲闪，不慎误伤观众"<<endl;
				s.integrity-=7;
			}
	}
	if(k==8)//招式九
    {
	        cout<<name<<"使出了[快快复苏]，";
			if(j==0)//应对一
			{
				cout<<"只见一道白光闪过，瞬间恢复了"<<a1<<"点血量"<<endl;
				blood+=a1;
			}
			if(j==1)//应对二
			{
				cout<<s.name<<"使出[咒立停]阻碍了治疗，并追加拳击，造成了"<<a1<<"点伤害"<<endl;
				blood-=a1;
			}
	}
	if(k==9)//招式十
    {
	        cout<<name<<"使出了[呼呼移]，瞬间将大石头化作武器，";
			if(j==0)//应对一
			{
				a1=3*a1;
				cout<<s.name<<"闪避不及，被石头砸中，受到了暴击"<<a1<<"点伤害"<<endl;
				s.blood-=a1;
			}
			if(j==1)//应对二
			{
				a1=0.3*a1;
				cout<<s.name<<"使出[四分五裂]，及时粉碎，只受到了"<<a1<<"点伤害"<<endl;
				s.blood-=a1;
			}
	}
	if(k==10)//招式十一
    {
	        cout<<name<<"向"<<s.name<<"发起了[瓦迪瓦西咒]，";
			if(j==0)//应对一
			{
				cout<<s.name<<"被子弹击中，受到了"<<a1<<"点伤害"<<endl;
				s.blood-=a1;
			}
			if(j==1)//应对二
			{
				cout<<s.name<<"使出[呼呼移]，将子弹扭转方向，"<<name<<"反受到了"<<a1<<"点伤害"<<endl;
				blood-=a1;
			}
	}
}

int Student::getBLOOD()//获得当前血量函数
{
	int bl=blood;
	return bl;
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
	/////////////////////////////////////////////////////////////////////////////////////////////
    ////开场白及人物设定///////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////
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

	char name1[10000];
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

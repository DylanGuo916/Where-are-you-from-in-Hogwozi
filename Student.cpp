#include "Student.h"
#include "MD5.h"
#include <iostream>
#include <string>
using namespace std;
void PrintMessage(string s)//自定义打字机效果输出函数
{
    const char *p = s.c_str();
    while (true)
    {
        if (*p == '\0')
        {
            std::cout<<std::endl;
            break;
        }
        std::cout<<char(*p);
        fflush(stdout);
        Sleep(50);
        p++;
    }
}
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
    PrintMessage("血量：" + to_string(blood));
    PrintMessage("勇敢：" + to_string(brave));
    PrintMessage("高贵：" + to_string(noble));
    PrintMessage("智慧：" + to_string(wisdom));
    PrintMessage("正直：" + to_string(integrity));
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
        std::cout<<"open failed"<<std::endl;
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

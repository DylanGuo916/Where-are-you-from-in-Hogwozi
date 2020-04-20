//
// Created by 郭喆 on 2020/4/20.
//

#ifndef Where-are-you-from-in-Hogwozi_STUDENT_H
#define Where-are-you-from-in-Hogwozi_STUDENT_H


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


#endif //Where-are-you-from-in-Hogwozi_STUDENT_H

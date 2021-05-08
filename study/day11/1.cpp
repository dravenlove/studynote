#include<iostream>
#include<ctime>

using namespace std;

struct Student  //定义学生结构体.
{
	string name;//结构体属性:姓名.
	int score;结构体属性:分数.
};
struct Teacher//定义老师结构体.
{
	string name;//定义属性:名字.
	Student sArray[5];//定义属性学生数组.
};

void allocateSpace(Teacher tArray[] , int len)  //定义一个存储数据的函数.
{
	string tName = "教师";
	string sName = "学生";
	string nameSeed = "ABCDE";//定义五个学生的编号.
	for (int i = 0; i < len; i++)//创建嵌套条件判断,给每个老师负责的学生姓名和分数赋值.
	{
		tArray[i].name = tName + nameSeed[i];
		
		for (int j = 0; j < 5; j++)
		{
			tArray[i].sArray[j].name = sName + nameSeed[j];
			tArray[i].sArray[j].score = rand() % 61 + 40;
		}
	}
}

void printTeachers(Teacher tArray[], int len)//创建一个打印数据的函数.
{
	for (int i = 0; i < len; i++)//嵌套条件判断输出每个老师的姓名以及名下的学生.
	{
		cout << tArray[i].name << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << "\t姓名：" << tArray[i].sArray[j].name << " 分数：" << tArray[i].sArray[j].score << endl;
		}
	}
}

int main() {//主函数创建.

	srand((unsigned int)time(NULL)); //随机数种子 头文件 #include <ctime>

	Teacher tArray[3]; //定义老师数组

	int len = sizeof(tArray) / sizeof(Teacher);//这个是将老师数组的长度赋值给len.

	allocateSpace(tArray, len); //创建数据

	printTeachers(tArray, len); //打印数据
	
	system("pause");

	return 0;
}
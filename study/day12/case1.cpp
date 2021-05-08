//通讯录管理系统

//1、菜单功能的实现.


#include<iostream>
#include<string>
#define MAX 1000 //定义全局变量MAX为1000.

using namespace std;

//1.1菜单显示功能。
void Menu()
{
    cout<<"******************************************"<<endl;
    cout<<"***************1、添加联系人***************"<<endl;
    cout<<"***************2、显示联系人***************"<<endl;
    cout<<"***************3、删除联系人***************"<<endl;
    cout<<"***************4、寻找联系人***************"<<endl;
    cout<<"***************5、修改联系人***************"<<endl;
    cout<<"***************6、清空联系人***************"<<endl;
    cout<<"***************0、退出通讯录***************"<<endl;
    cout<<"******************************************"<<endl;
}

//联系人结构体设计
struct Person
{
    string m_Name;//定义联系人属性:姓名.
    int m_Sex;//性别.
    int m_Age;//年龄.
    string m_Phone;//手机号码.
    string m_Address;//住址.

};

//通讯录结构体设计

struct Addressbooks
{
    struct Person personArray[MAX];//创建结构体数组方便管理联系人.
    int m_Size;
};
// 
//添加联系人函数.
        
void Addperson(Addressbooks *abs)
{
    if (abs->m_Size == MAX)
    {
        cout <<"通讯录太多人了,请删除不常联系的联系人后重试."<<endl;
        return;
        }
    else
    {
        string name;//定义一个name变量存储联系人名字.
        cout<<"请输入联系人的名字:"<<endl;
        cin>>name ;
        abs->personArray[abs->m_Size].m_Name = name;//访问创建的结构体abs的联系人数组,数值大小为abs的m_Size,访问数组的名字并赋值.

        cout<<"请输入联系人的性别:"<<endl;
        cout<<"1为男性，2为女性。"<<endl;
        
        int sex=0;//创建sex变量以定义性别.
        cin >> sex;
        switch (sex)
        {
            case 1:
                    abs->personArray[abs->m_Size].m_Sex =sex;//访问abs的联系人数组的m_Sex并赋值.
                    break;
            case 2:
                     abs->personArray[abs->m_Size].m_Sex =sex;
                    break;
            default:
                cout<<"输入错误请重新输入."<<endl;
                break;
        }
        cout<<"请输入联系人的年龄:"<<endl;
        int age =0;
        cin >> age;
        abs->personArray[abs->m_Size].m_Age =age;

        cout<<"请输入联系人的电话:"<<endl;
        string phone;
        cin >>phone;
        abs->personArray[abs->m_Size].m_Phone =phone;

        cout<<"请输入联系人的家庭地址:"<<endl;
        string address;
        cin>> address;
        abs->personArray[abs->m_Size].m_Address=address;

        abs->m_Size++;
        cout<<"添加联系人成功."<<endl;
        system("pause");
        system("cls");
    }
}

//显示联系人函数

void Showperson(Addressbooks *abs)
{
        if (abs->m_Size ==0)
        {
                cout<<"没有联系人."<<endl;
        }
        else 
        {
                for (int i=0;i< abs->m_Size;i++)
                {
                        cout<<"姓名:"<<abs->personArray[i].m_Name<<endl;
                        cout<<"性别:"<<abs->personArray[i].m_Sex<<endl;
                        cout<<"年龄:"<<abs->personArray[i].m_Age<<endl;
                        cout<<"电话:"<<abs->personArray[i].m_Phone<<endl;
                        cout<<"住址:"<<abs->personArray[i].m_Address<<endl;
                }
        }
        
        system("pause");
        system("cls");
}

        //删除联系人功能。
        //这个是判断联系人名字是否在通讯录.
        int Exist(Addressbooks *abs,string name)
        {
                for (int i=0;i< abs->m_Size;i++)
                {
                        if (abs->personArray[i].m_Name == name)
                        {
                                return i;
                        }
                }
                return -1;
        }


        //删除联系人函数

        void Deleteperson(Addressbooks *abs)
        {
                cout<<"请输入你要删除的联系人名称"<<endl;
                string name;
                cin >> name;

                int ret = Exist(abs,name);
                if (ret !=-1)
                {
                        for (int i=ret;i<abs->m_Size;i++)
                        {
                                abs->personArray[i]=abs->personArray[i+1];
                        }
                abs->m_Size--;
                        cout<<"删除成功"<<endl;
                }
                else 
                {
                        cout<<"找不到该联系人删除失败."<<endl;
                }
                
                system("pause");
                system("cls");
        }

        //查找指定联系人功能.

        void Searchperson(Addressbooks *abs)
        {
                cout<<"输入你要搜索的联系人的名称."<<endl;

                string name;

                cin>>name;
                
                int ret =Exist(abs,name);

                if (ret !=-1)
               {
                       cout<<"姓名:"<<abs->personArray[ret].m_Name<<endl;
                       cout<<"性别:"<<abs->personArray[ret].m_Sex<<endl;
                       cout<<"年龄:"<<abs->personArray[ret].m_Age<<endl;
                       cout<<"电话:"<<abs->personArray[ret].m_Phone<<endl;
                       cout<<"住址:"<<abs->personArray[ret].m_Address<<endl;
               }
               else
               {
                       cout<<"通讯里找不到这个联系人."<<endl;
               } 
        }

        //修改联系人信息
        void Changeperson(Addressbooks *abs)
        {
                cout<<"请输入你要修改的联系人名字"<<endl;
                string name;
                cin>> name;

                int ret=Exist(abs,name);
                if (ret != -1)
                {
                        string name;
                        cout<<"请输入要修改的联系人的姓名"<<endl;
                        cin >>name;
                        abs->personArray[ret].m_Name=name;

                        cout<<"请输入要修改联系人的性别"<<endl;
                        cout<<"1 -- 男"<<endl;
                        cout<<"2 -- 女"<<endl;

                        int sex=0;
                        while(true)
                        { 
                                cin>>sex;
                                if (sex ==1||sex==2)
                                {
                                        abs->personArray[ret].m_Sex=sex;
                                        break;
                                }
                        }
                        cout<<"输入有误请重新输入."<<endl;
                }

                cout<<"请输入要修改联系人的年龄"<<endl;
                int age =0;
                cin >>age;
                abs->personArray[ret].m_Age=age;

                cout<<"请输入要修改联系人的电话"<<endl;
                string phone ="";
                cin >> phone;
                abs->personArray[ret].m_Phone=phone;
        }

        //清空联系人功能。
        
        void Cleanperson(Addressbooks *abs)
        {
                abs->m_Size=0;
                cout<<"通讯录已清空."<<endl;
                system("pause");
                system("cls");

        }


int main()
{
        //创建结构体.
        Addressbooks abs;
        //初始化通讯录人数.
        abs.m_Size = 0;

        Menu();

        //给菜单添加选择功能。
    
        int select = 0;

        label: 


        cout <<"输入对应的数字使用对应功能."<<endl;
        cin >> select;
        
        


        switch  (select)
        {
            case 1:
            Addperson(&abs);
                   goto label;

            case 2:
            Showperson(&abs);
                   goto label;

            case 3:
            Deleteperson(&abs);
                    goto label;

            case 4:
            Searchperson(&abs);
                    goto label;

            case 5:
            Changeperson(&abs);
                    goto label;

            case 6:
            Cleanperson(&abs);
                    goto label;

            case 0:
                cout<<"退出通讯录菜单成功！"<<endl;
                    break;

            default:
                cout <<"对不起,你输入的数字有误,请输入正确的数字."<<endl;
                system("pause");
                    break ;
        }

        return 0;
}

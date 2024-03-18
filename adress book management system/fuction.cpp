#include <iostream>
#include <string>
using namespace std;
#define MAX 1000

struct person
{
    string m_name;
    int m_sex; // 1 man 2 woman
    int m_age;
    string m_adress;
    string m_phone;
};

struct personfiles
{
    person array[MAX]; // 创建person结构作为personfiles结构元素
    int m_size = 0;
};

void showmenu()
{
    cout << "$$$$$$$$$$$$$$$$$$$$$" << endl;
    cout << "$$$  1.添加联系人  $$$" << endl;
    cout << "$$$  2.显示联系人  $$$" << endl;
    cout << "$$$  3.删除联系人  $$$" << endl;
    cout << "$$$  4.查找联系人  $$$" << endl;
    cout << "$$$  5.修改联系人  $$$" << endl;
    cout << "$$$  6.清空联系人  $$$" << endl;
    cout << "$$$  0.退出联系人  $$$" << endl;
    cout << "$$$$$$$$$$$$$$$$$$$$$" << endl;
};

// 添加联系人
void addperson(struct personfiles *pdf)
{
    if (pdf->m_size == MAX)
        cout << "通讯录已满，若想输入请删除一些人员";
    else
    {
        string name;
        cout << "请输入姓名" << endl;
        cin >> name;
        pdf->array[pdf->m_size].m_name = name;
        // 输入姓名
        int sex;
        cout << "输入1或2,1是男,2是女。" << endl;
        cin >> sex;
        pdf->array[pdf->m_size].m_sex = sex;
        // 输入性别
        int age;
        cout << "请输入年龄" << endl;
        cin >> age;
        pdf->array[pdf->m_size].m_age = age;
        // 输入年龄
        string adress;
        cout << "请输入地址" << endl;
        cin >> adress;
        pdf->array[pdf->m_size].m_adress = adress;
        // 输入地址
        string phone;
        cout << "请输入电话号码" << endl;
        cin >> phone;
        pdf->array[pdf->m_size].m_phone = phone;
        // 输入电话号码
        pdf->m_size++;
    }
    cout << "添加成功" << endl;
    system("pause");
    system("cls");
};

// 显示整个通讯录的情况
void showperson(struct personfiles *pdf)
{
    if (pdf->m_size == 0)
    {
        cout << "通讯录为空" << endl;
    }
    else
    {
        for (int i = 0; i < pdf->m_size; i++)
        {
            cout << "姓名" << pdf->array[i].m_name << "\t";
            cout << "年龄" << pdf->array[i].m_age << "\t";
            cout << "性别" << (pdf->array[i].m_sex == 1 ? "男" : "女") << "\t";
            cout << "电话号码" << pdf->array[i].m_phone << "\t";
            cout << "地址" << pdf->array[i].m_adress << endl;
        }
    };
    system("pause");
    system("cls");
};

// 用来判断联系人在通讯录的情况，这个在多个函数可以调用
int isexit(personfiles *pdf, string name)
{
    for (int i = 0; i < pdf->m_size; i++)
    {
        if (pdf->array[i].m_name == name)
        {
            return i;
        }
    }
    return -1;
};

// 查找联系人
void seekperson(struct personfiles *pdf)
{
    string name;
    cout << "please enter the name that you want to seek" << endl;
    cin >> name;
    int total = isexit(pdf, name);
    if (total != -1) // 你不写if语句会造成访问索引的问题，因为total若是-1则会使得访问数组出现错误，因此最好加上total的情况
    {
        cout << "这是你想要查找的联系人:" << endl;
        cout << "姓名:    " << pdf->array[total].m_name << "\t";
        cout << "地址:   " << pdf->array[total].m_adress << "\t";
        cout << "年龄:   " << pdf->array[total].m_age << "\t";
        cout << "电话号码:" << pdf->array[total].m_phone << "\t";
        cout << "性别：   " << (pdf->array[total].m_sex == 1 ? "男" : "女") << endl;
    }
    else
        cout << "你查找的联系人不在通讯录" << endl;
    system("pause");
    system("cls");
};

// 删除联系人
void deleteperson(struct personfiles *pdf)
{
    cout << "please enter your name that you want to delete" << endl;
    string name;
    cin >> name;
    int result = isexit(pdf, name);
    for (int i = result; i < pdf->m_size - 1; i++)
    {
        if (result != -1)
        {
            pdf->array[i] = pdf->array[i + 1]; // 让后一个人不断覆盖前一个人的情况，以达到修改目的
        }
        else
            cout << "查无此人" << endl;
        /*pdf->array[i].m_adress=pdf->array[i+1].m_adress;
        pdf->array[i].m_name=pdf->array[i+1].m_name;
        pdf->array[i].m_sex=pdf->array[i+1].m_sex;
        pdf->array[i].m_phone=pdf->array[i+1].m_phone;
        pdf->array[i].m_age=pdf->array[i+1].m_age;
        这样反而麻烦，因为是数据一个一个覆盖，可以一整个数组覆盖*/
    }
    pdf->m_size--;
    cout << "删除成功" << endl;
    system("pause");
    system("cls");
};

// 修改联系人
void modifpreson(struct personfiles *pdf)
{
    cout << "请你输入想要修改的联系人的名字:" << endl;
    string name;
    cin >> name;
    int reslut = isexit(pdf, name);
    if (reslut != -1)
    {
        cout << "请你输入修改后联系人的年龄，电话号码，地址，性别:" << endl;
        pdf->array[reslut].m_name = name; // 修改姓名

        int age;
        cin >> age;
        pdf->array[reslut].m_age = age; // 修改年龄

        string phone;
        cin >> phone;
        pdf->array[reslut].m_phone = phone; // 修改电话号码

        string address;
        cin >> address;
        pdf->array[reslut].m_adress = address; // 修改地址

        int sex;
        cin >> sex;
        pdf->array[reslut].m_sex = sex; // 修改性别
    }
    else
        cout << "通讯录没有这个人" << endl;
    system("pause");
    system("cls");
};

// 清空联系人
void deleteall(struct personfiles *pdf)
{
    int number;
    cout << "请输入通讯录人员个数，以判断你是否误触此功能，以此避免删除所有联系人" << endl;
    cin >> number;
    if (number == pdf->m_size)
    {
        pdf->m_size = 0; // 名义上清空，这就是让他访问不了，即认为清空了
        cout << "通讯录已清空" << endl;
    }
    else
        cout << "你输入的不是通讯录所有人员个数，请重新输入" << endl;
    system("pause");
    system("cls");
};

int main()
{
    struct personfiles pdf; // 必要的，创建一个pdf的通讯录结构
    int select = 0;
    while (true) // 循环，所以每次都可以使用数字来选择功能
    {
        showmenu();
        cout << "please choose a number:" << endl;
        cin >> select;
        switch (select)
        {
        case 1: // 1.添加联系人
            addperson(&pdf);
            break;
        case 2: // 2.显示联系人A
            showperson(&pdf);
            break;
        case 3: // 3.删除联系人
            deleteperson(&pdf);
            break;
        case 4: // 4.查找联系人
            seekperson(&pdf);
            break;
        case 5: // 5.修改联系人
            modifpreson(&pdf);
            break;
        case 6: // 6.清空联系人
            deleteall(&pdf);
            break;
        case 0: // 0.退出联系人
            cout << "welcome to your next come" << endl;
            return 0; // 退出函数
        default:
            cout << "please choose a true number" << endl;
            break;
        }
    }
    return 0;
}
#include <iostream>
#include <string>
using namespace std;
//学生的结构体定义
struct student
{
    string name;
    int age;
    int score;
};
//老师的结构体定义
struct teacher
{
    string name;
    struct student arr2[5];//学生结构体数组，因为一个老师要带的学生也有信息,且数组一定要明确具体数量
};
//老师信息赋值函数
void inputer(struct teacher arr1[],int len)
{
    string character="ABCDE";
    for (int i=0;i<len;i++)
    {
            arr1[i].name="teacher_" ;
            arr1[i].name+=character[i];
            for(int j=0;j<5;j++) 
            {
                arr1[i].arr2[j].name="student_" ;
                arr1[i].arr2[j].name+=character[j];
                int random1=rand()%10+5;//生成一随机数，10代表0到9，加5就范围加5
                int random2=rand()%61+40;
                arr1[i].arr2[j].age=random1;
                arr1[i].arr2[j].score=random2;
            }
    }
};
//老师信息打印函数
void printer(struct teacher arr1[],int len)
{
    for(int i=0;i<len;i++)
    {
        cout<<arr1[i].name<<endl;
        for(int j=0;j<5;j++)
        {
            cout<<'\t'<<arr1[i].arr2[j].name;
            cout<<"  "<<arr1[i].arr2[j].age;
            cout<<"  "<<arr1[i].arr2[j].score;
            cout<<endl;
        }
    }
};
int main()
{
    struct teacher arr1[3];//创建数组结构
    int len=sizeof(arr1)/sizeof(arr1[0]);//数组元素个数
    inputer(arr1,len);//传数组地址到函数中
    printer(arr1,len);
    return 0;
}
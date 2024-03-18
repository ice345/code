#include <iostream>
using namespace std;
int main()
{
    //1.写出数组排序前的数，for循环不断输入
    cout<<"please enter  numbers";
    int arr[5];
    for(int i=0;i<5;i++)
    {
        cin>>arr[i];
    }
    //2.开始进行排序
    for(int j=1;j<=5-1;j++)
    {
        for(int k=0;k<5-j;k++)
        {
            if(arr[k]>arr[k+1])
            {
                int temp=0;
                temp=arr[k];
                arr[k]=arr[k+1];
                arr[k+1]=temp;
            }
        }
    }
    //输入排序后的数组
    for(int i=0;i<5;i++)
    {
        cout<<arr[i];
    }
    return 0;
}

#include <iostream>
#include <algorithm> // 包含 std::sort
#include <vector>
#include <string>
using namespace std;

int main() 
{
    const int size = 5;
    vector<string> strings(size);
    //vector<string> strings;

    cout << "Enter 10 strings:" << endl;
    for (int i = 0; i < size; ++i) 
    {
        cin >> strings[i];
        //string input;
        //cin>>input;
        //strings.push_back(input);
    }

    sort(strings.begin(), strings.end()); // 使用 std::sort 对字符串进行排序

    cout << "Sorted strings:" << endl;
    for (int i = 0; i < size; ++i) 
    {
        cout << strings[i] << endl;
    }

    return 0;
}

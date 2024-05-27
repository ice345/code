/**
 * @brief 职工管理系统类的具体实现
 * @details 有几个点值得注意，一个是new delete之间的操作，要慎重处理，避免悬挂指针，使指针成为野指针，造成内存泄漏；
 * @details 二是，你在第一次执行程序后，使文件有了数据，但第二次打开因为会重新构造函数，这时你要注意，如果你不将文件内的数据弄到数组上，那么你的数组就是空的，这时很多的访问涉及到数组的，你直接选某些功能会使得发生错误
 * @details 初步想法就是在get_EmpNum()函数中，将文件中的数据读取到数组中，这样就不会出现数组为空的情况
 * @details 以后就是有关指针的操作，要注意，不要出现悬挂指针，使指针成为野指针，造成内存泄漏，最后要使其变为空指针。并且在访问时什么的，要注意先用if判断是否为空，再进行操作
*/
#include "workerManager.h"
using namespace std;

void WorkerManager::test_1()
{
    if(this->m_EmpArray != NULL)
    {
        cout << "m_EmpArray不为空" << endl;
    }
    else
    {
        cout << "m_EmpArray为空" << endl;
    }
    for(int i=0;i<this->m_EmpNum;i++)
    {
        if(this->m_EmpArray[i] != NULL)
        {
            cout << "m_EmpArray[" << i << "]不为空" << endl;
        }
        else
        {
            cout << "m_EmpArray[" << i << "]为空" << endl;
        }
    }
}

// 构造函数初始化
WorkerManager::WorkerManager()
{
    ifstream ifs;
    ifs.open(DATA_FILENAME, ios::in);

    // 文件不存在
    if(!ifs.is_open())
    {
        cout<<"文件不存在"<<endl;
        // 初始化属性
        this->m_EmpArray = NULL;
        this->m_EmpNum = 0;
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }

    // 文件存在,但是数据为空
    char ch;
    ifs >> ch;
    if(ifs.eof())
    {
        cout<<"文件为空"<<endl;
        // 初始化属性
        this->m_EmpArray = NULL;
        this->m_EmpNum = 0;
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }
    // 文件存在，并且记录了数据
    else
    {
        this->m_FileIsEmpty = false;
        int num = this->get_EmpNum();
        cout<<"职工人数为："<<num<<endl;
        this->m_EmpNum = num;
        this->m_EmpArray = new Worker *[this->m_EmpNum];
        if(this->m_EmpArray == NULL)
        {
            cout<<"new失败"<<endl;
            cout<<"程序异常"<<endl;
            return;
        }
    }
    ifs.close();
}


// 析构函数，释放堆区开辟的空间
WorkerManager::~WorkerManager()
{
    if(this->m_EmpArray != NULL)
    {
        cout<<"释放职工系统中的所有职工"<<endl;
        for(int i=0;i<this->m_EmpNum;i++)
        {
            if(this->m_EmpArray[i] != NULL)
            {
                // 因为this->m_EmpArray[i] = worker;delete this->m_EmpArray[i]就是delete worker
                delete this->m_EmpArray[i];
                m_EmpArray[i] = NULL;
            }
        }
        delete[] this->m_EmpArray;
        this->m_EmpArray = NULL;
    }
}


// 展示菜单
void WorkerManager::showMenu()
{
    std::cout << "*********************************" << std::endl;
    std::cout << "*****  欢迎使用职工管理系统  ******" << std::endl;
    std::cout << "********  0.退出管理程序  ********" << std::endl;
    std::cout << "********  1.增加职工信息  ********" << std::endl;
    std::cout << "********  2.显示职工信息  ********" << std::endl;
    std::cout << "********  3.删除离职职工  ********" << std::endl;
    std::cout << "********  4.修改职工信息  ********" << std::endl;
    std::cout << "********  5.查找职工信息  ********" << std::endl;
    std::cout << "********  6.按照工号排序  ********" << std::endl;
    // std::cout << "********  7.显示文档内容  ********" << std::endl;
    std::cout << "********  7.清除文档内容  ********" << std::endl;
    std::cout << "*********************************" << std::endl;
    std::cout << std::endl;
}

// 退出系统，这个可以直接在case那里写就行了的，可以不用搞一个函数出来
void WorkerManager::exitSystem()
{
    std::cout<<"欢迎你的下次使用"<<std::endl;
    system("pause");
    system("cls");
    std::exit(0);
}

// 获取文件中的职工人数
int WorkerManager::get_EmpNum()
{
    ifstream ifs;
    ifs.open(DATA_FILENAME, ios::in);

    int id;
    char name[100];
    char deptName[100];

    int num=0;
    // 将文件中的数据读取到类的成员属性中以及数组中
    while(ifs>>deptName && ifs>>name && ifs>>id)
    {
        num++;
    }
    ifs.close();
    return num;
}

// 在初始打开程序时，将文件中的数据读取到数组中，避免打开使得数组为空导致错误
void WorkerManager::init_Emp()
{
    ifstream ifs;
    ifs.open(DATA_FILENAME, ios::in);

    int id;
    char name[100];
    char deptName[100];

    int index = 0;
    // 将文件中的数据读取到类的成员属性中以及数组中
    while(ifs>>deptName && ifs>>name && ifs>>id && this->m_EmpArray[index] == NULL)
    {
        Worker *worker = NULL;
        if(strcmp(deptName,"员工")==0)
        {
            worker = new Employee(deptName,name,id);
        }
        else if(strcmp(deptName,"经理")==0)
        {
            worker = new Manager(deptName,name,id);
        }
        else if(strcmp(deptName,"老板")==0)
        {
            worker = new Boss(deptName,name,id);
        }
        this->m_EmpArray[index] = worker;
        index++;
    }
    ifs.close();
}

// 判断职工是否存在
int WorkerManager::isExist(int id)
{
    int index = -1;
    for(int i=0;i<this->m_EmpNum;i++)
    {
        if(this->m_EmpArray[i]->m_Id == id)
        {
            index = i;
            break;
        }
    }
    return index;
}

/*
void WorkerManager::addEmp()
{
    cout<<"请输入添加职工数量"<<endl;

    int addNum = 0;
    cin>>addNum;

    if(addNum>0)
    {
        // 计算添加新空间大小
        int newSize = this->m_EmpNum + addNum;

        // 开辟新空间
        Worker **newSpace = new Worker *[newSize]; //这个是指针数组，newSpace是指向Worker *[newSize]的指针，元素数据类型是Worker *

        // 将原来空间下数据存放到新空间下
        if(this->m_EmpArray != NULL)
        {
            for(int i=0; i<this->m_EmpNum; i++)
            {
                newSpace[i] = this->m_EmpArray[i];
            }


            // 添加新数据
            for(int i=0;i<newSize;i++)
            {
                cout<<"请输入第"<<i+1<<"个新职工部门编号(普通员工，经理，老板)"<<endl;
                char deptName[100];
                cin>>deptName;

                cout<<"请输入第"<<i+1<<"个新职工姓名"<<endl;
                char name[100];
                cin>>name;

                cout<<"请输入第"<<i+1<<"个新职工编号"<<endl;
                int id;
                cin>>id;

                Worker *worker = NULL;

                int deselection = 0;
                cout<<"请选择职工类型"<<endl;
                cout<<"1.普通员工"<<endl;
                cout<<"2.经理"<<endl;
                cout<<"3.老板"<<endl;
                cin>>deselection;

                switch(deselection)
                {
                    case 1:
                        worker = new Employee(deptName,name,id);
                        break;
                    case 2:
                        worker = new Manager(deptName,name,id);
                        break;
                    case 3:
                        worker = new Boss(deptName,name,id);
                        break;
                    default:
                        break;
                }

                // 将创建职工职责保存到数组中
                newSpace[this->m_EmpNum+i] = worker;

                // 删除原有空间
                //delete[] this->m_EmpArray; 
                //这里要修改，因为原来你根本没有空间，你还删除，会造成错误。
                // 但是，程序运行了，windows没有什么报错就结束，但是linux会报错：free(): invalid pointer  Aboted。这就是表示正在尝试释放不是指向“可释放”内存地址的指针的内容

                // 更改新空间的指向
                this->m_EmpArray = newSpace;

                // 更新新的职工人数
                this->m_EmpNum = newSize;

                cout<<"成功添加"<<addNum<<"名新职工"<<endl;
                
                // 保存数据到文件中
                this->m_FileIsEmpty = false;
                this->save();
            }
        }
        else if(this->m_EmpArray == NULL)
        {
            for(int i=0;i<addNum;i++)
            {
                cout<<"请输入第"<<i+1<<"个新职工部门编号(普通员工，经理，老板)"<<endl;
                char deptName[100];
                cin>>deptName;

                cout<<"请输入第"<<i+1<<"个新职工姓名"<<endl;
                char name[100];
                cin>>name;

                cout<<"请输入第"<<i+1<<"个新职工编号"<<endl;
                int id;
                cin>>id;

                Worker *worker = NULL;

                int deselection = 0;
                cout<<"请选择职工类型"<<endl;
                cout<<"1.普通员工"<<endl;
                cout<<"2.经理"<<endl;
                cout<<"3.老板"<<endl;
                cin>>deselection;

                switch(deselection)
                {
                    case 1:
                        worker = new Employee(deptName,name,id);
                        break;
                    case 2:
                        worker = new Manager(deptName,name,id);
                        break;
                    case 3:
                        worker = new Boss(deptName,name,id);
                        break;
                    default:
                        break;
                }

                // 将创建职工职责保存到数组中
                newSpace[this->m_EmpNum+i] = worker;

                // 删除原有空间
                //delete[] this->m_EmpArray;

                // 更改新空间的指向
                this->m_EmpArray = newSpace;

                // 更新新的职工人数
                this->m_EmpNum = newSize;

                cout<<"成功添加"<<addNum<<"名新职工"<<endl;
                
                // 保存数据到文件中
                this->m_FileIsEmpty = false;
                this->save();
            }
        }
    }
    else
    {
        cout<<"输入数据有误"<<endl;
    }

    system("pause");
    system("cls");
}
*/

// 添加职工
void WorkerManager::addEmp()
{
    cout<<"请输入添加职工数量"<<endl;

    int addNum = 0;
    cin>>addNum;

    if(addNum>0)
    {
        // 考虑原本m_EmpArray为空的情况,不这样的话，你delete会导致删除原本没有指的内存，会报错
        if(this->m_EmpArray == NULL)
        {
            this->m_EmpArray = new Worker *[addNum];
            this->m_EmpNum = addNum;
            for(int i=0;i<this->m_EmpNum;i++)
            {
                Worker *worker = NULL;
                cout<<"请输入第"<<i+1<<"个新职工部门编号(员工，经理，老板)"<<endl;
                string deptName;
                cin>>deptName;

                cout<<"请输入第"<<i+1<<"个新职工姓名"<<endl;
                string name;
                cin>>name;

                cout<<"请输入第"<<i+1<<"个新职工编号"<<endl;
                int id;
                cin>>id;

                int deselection = 0;
                cout<<"请选择职工类型"<<endl;
                cout<<"1.员工"<<endl;
                cout<<"2.经理"<<endl;
                cout<<"3.老板"<<endl;
                cin>>deselection;

                switch(deselection)
                {
                    case 1:
                        worker = new Employee(deptName,name,id);
                        break;
                    case 2:
                        worker = new Manager(deptName,name,id);
                        break;
                    case 3:
                        worker = new Boss(deptName,name,id);
                        break;
                    default:
                        break;
                }

                // 将创建职工职责保存到数组中,这个worker本身也是一个数组
                this->m_EmpArray[i] = worker;
            }

            // 保存数据到文件中
            this->m_FileIsEmpty = false;
            this->save();
        }
        else
        {
            int newSize = this->m_EmpNum + addNum;
            Worker **newSpace = new Worker *[newSize];

            // 将原来空间下数据存放到新空间下
            for(int i=0;i<this->m_EmpNum;i++)
            {
                newSpace[i] = this->m_EmpArray[i];
            }

            // 添加新数据
            for(int i=0;i<addNum;i++)
            {
                Worker *worker = NULL;
                cout<<"请输入第"<<i+1<<"个新职工部门编号(员工，经理，老板)"<<endl;
                string deptName;
                cin>>deptName;

                cout<<"请输入第"<<i+1<<"个新职工姓名"<<endl;
                string name;
                cin>>name;

                cout<<"请输入第"<<i+1<<"个新职工编号"<<endl;
                int id;
                cin>>id;

                int deselection = 0;
                cout<<"请选择职工类型"<<endl;
                cout<<"1.员工"<<endl;
                cout<<"2.经理"<<endl;
                cout<<"3.老板"<<endl;
                cin>>deselection;

                switch(deselection)
                {
                    case 1:
                        worker = new Employee(deptName,name,id);
                        break;
                    case 2:
                        worker = new Manager(deptName,name,id);
                        break;
                    case 3:
                        worker = new Boss(deptName,name,id);
                        break;
                    default:
                        break;
                }
                // 将创建职工职责保存到数组中
                newSpace[this->m_EmpNum+i] = worker;
            }
            // 更新新的职工人数
            this->m_EmpNum = newSize;

            // 保存数据到文件中
            this->m_FileIsEmpty = false;
            if(this->m_EmpArray != NULL)
            {
                // 删除原有空间
                delete[] m_EmpArray;
            }
            m_EmpArray = newSpace;

            this->save();
        }
    }
    else
    {
        cout<<"输入数据有误"<<endl;
    }

    system("pause");
    system("cls");
}
/*
void WorkerManager::addEmp() 
{
    cout << "请输入添加职工数量" << endl;

    int addNum;
    cin >> addNum;

    if (addNum > 0) 
    {
        int temp_EmpNum;
        // Check if m_EmpArray is empty or needs reallocation
        if (this->m_EmpArray == NULL)
        {
            // Reallocate memory if necessary
            Worker **newSpace = new Worker*[this->m_EmpNum + addNum];

            // Copy existing data to new space
            for (int i = 0; i < this->m_EmpNum; ++i) 
            {
                newSpace[i] = this->m_EmpArray[i];
            }

            // Delete old array if not empty
            if (this->m_EmpArray != NULL) 
            {
                delete[] this->m_EmpArray;
            }

            // Update m_EmpArray and m_EmpSize
            this->m_EmpArray = newSpace;
            temp_EmpNum = this->m_EmpNum;
            this->m_EmpNum = this->m_EmpNum + addNum;
        }

        // Add new employees
        for (int i = temp_EmpNum; i < this->m_EmpNum + addNum; ++i) 
        {
            std::cout << "请输入第" << i + 1 << "个新职工部门编号(员工，经理，老板)" << endl;
            char deptName[100];
            cin >> deptName;

            cout << "请输入第" << i + 1 << "个新职工姓名" << endl;
            char name[100];
            cin >> name;

            cout << "请输入第" << i + 1 << "个新职工编号" << endl;
            int id;
            cin >> id;

            cout << "请选择职工类型" << endl;
            cout << "1.员工" << endl;
            cout << "2.经理" << endl;
            cout << "3.老板" << endl;
            int selection;
            cin >> selection;

            Worker *worker;
            switch (selection) {
                case 1:
                    worker = new Employee(deptName, name, id);
                    break;
                case 2:
                    worker = new Manager(deptName, name, id);
                    break;
                case 3:
                    worker = new Boss(deptName, name, id);
                    break;
                default:
                    break;
            }

            // Check if memory allocation was successful
            if (worker != NULL) 
            {
                this->m_EmpArray[i] = worker;
                this->m_EmpNum++;
            } else {
                cout << "内存分配失败" << endl;
            }
        }

        // Save data to file
        this->m_FileIsEmpty = false;
        this->save();
    } 
    else 
    {
        cout << "输入数据有误" << endl;
    }
}
*/

/*
void WorkerManager::showEmp()
{
    if(this->m_FileIsEmpty)
    {
        cout<<"文件不存在或者记录为空"<<endl;
    }
    else
    {
        for(int i=0;i<m_EmpNum;i++)
        {
            this->m_EmpArray[i]->showInfo();
        }
    }

    system("pause");
    system("cls");
}
*/

// 展示职工
void WorkerManager::showEmp() 
{
    ifstream ifs;
    ifs.open(DATA_FILENAME, ios::in);  // 打开文件

    if (!ifs.is_open()) 
    {
        cout << "文件读取失败" << endl;
        ifs.close();
        return;
    }

    if(this->m_FileIsEmpty)
    {
        cout<<"文件不存在或者记录为空"<<endl;
    }
    else
    {
        cout << "职务 姓名 编号" << endl;

        char ch[100]={0}; // 读取文件中的每一行
        while (ifs.getline(ch, sizeof(ch))) 
        {  
            cout << ch << endl;  // 显示每一行
        }
    }
    ifs.close();  // 关闭文件

    system("pause");
    system("cls");
}

// 删除职工
void WorkerManager::delEmp()
{
    if(this->m_FileIsEmpty)
    {
        cout<<"文件不存在或者记录为空"<<endl;
    }
    else
    {
        //init_Emp();  // 先将文件中的数据读取到数组中，避免打开使得数组为空导致错误
        cout<<"请输入要删除的职工编号"<<endl;
        int id;
        cin>>id;

        int index = this->isExist(id);

        if(index != -1)
        {
            if(this->m_EmpNum == 1)
            {
                delete this->m_EmpArray[index];
                this->m_EmpArray[index] = NULL;
                this->m_EmpNum = 0;
                this->m_FileIsEmpty = true;
            }
            else
            {
                // for(int i=index;i<this->m_EmpNum-1;i++)
                // {
                //     this->m_EmpArray[i] = this->m_EmpArray[i+1];//这个是把后面的元素往前移动进行覆盖
                // }
                delete this->m_EmpArray[index];
                this->m_EmpArray[index] = NULL;
                for(int i=index;i<this->m_EmpNum-1;i++)
                {
                    this->m_EmpArray[i] = this->m_EmpArray[i+1];//这个是把后面的元素往前移动进行覆盖
                }
            }
            // 更新职工人数
            this->m_EmpNum--;

            // 保存数组数据到文件中
            this->save();
            cout<<"删除成功"<<endl;
        }
        else
        {
            cout<<"删除失败，查无此人"<<endl;
        }
    }

    system("pause");
    system("cls");
}

// 修改职工
void WorkerManager::modEmp()
{
    if(this->m_FileIsEmpty)
    {
        cout<<"文件不存在或者记录为空"<<endl;
    }
    else
    {
        //init_Emp();  // 先将文件中的数据读取到数组中，避免打开使得数组为空导致错误
        cout<<"请输入要修改的职工编号"<<endl;
        int id;
        cin>>id;

        int ret = this->isExist(id);

        if(ret != -1)
        {
            delete this->m_EmpArray[ret];
            this->m_EmpArray[ret] = NULL;

            int newId = 0;
            string newName;
            string newDeptName;

            cout<<"查到："<<id<<"号职工，请输入新职工部门编号(员工，经理，老板)"<<endl;
            cin>>newDeptName;

            cout<<"请输入新职工姓名"<<endl;
            cin>>newName;

            cout<<"请输入新职工编号"<<endl;
            cin>>newId;

            Worker *worker = NULL;

            int deselection = 0;
            cout<<"请选择职工类型"<<endl;
            cout<<"1.员工"<<endl;
            cout<<"2.经理"<<endl;
            cout<<"3.老板"<<endl;
            cin>>deselection;

            switch(deselection)
            {
                case 1:
                    worker = new Employee(newDeptName,newName,newId);
                    break;
                case 2:
                    worker = new Manager(newDeptName,newName,newId);
                    break;
                case 3:
                    worker = new Boss(newDeptName,newName,newId);
                    break;
                default:
                    break;
            }

            // delete this->m_EmpArray[ret];(上面已经删除)
            // 更新数据到数组中
            this->m_EmpArray[ret] = worker;
            cout<<"修改成功"<<endl;

            // 保存数据到文件中
            this->save();
        }
        else
        {
            cout<<"修改失败，查无此人"<<endl;
        }
    }
    system("pause");
    system("cls");
}

// 查找职工
void WorkerManager::findEmp()
{
    if(this->m_FileIsEmpty)
    {
        cout<<"文件不存在或者记录为空"<<endl;
    }
    else
    {
        // init_Emp();  // 先将文件中的数据读取到数组中，避免打开使得数组为空导致错误
        cout<<"请输入你想要查找的职工的唯一的职工编号,以查找职工信息"<<endl;
        int id;
        cin>>id;

        int ret=this->isExist(id);
        if(ret != -1)
        {
            cout<<"查找成功，该职工信息如下："<<endl;
            this->m_EmpArray[ret]->showInfo();
        }
        else
        {
            cout<<"查找失败，查无此人"<<endl;
        }
    }

    system("pause");
    system("cls");
}

// 排序职工
void WorkerManager::sortEmp()
{
    if(this->m_FileIsEmpty)
    {
        cout<<"文件不存在或者记录为空"<<endl;
    }
    else
    {
        // init_Emp();  // 先将文件中的数据读取到数组中，避免打开使得数组为空导致错误
        cout<<"请选择排序方式"<<endl;
        cout<<"1.按照职工号进行升序"<<endl;
        cout<<"2.按照职工号进行降序"<<endl;

        int select = 0;
        cin>>select;
        
        for(int i=0;i<this->m_EmpNum;i++)
        {
            int minOrMax = i;
            if(select==1) // 升序
            {
                for(int j=i+1;j<this->m_EmpNum;j++)
                {
                    if(this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id) //这样操作就是回到本属于他的位置
                    {
                        minOrMax = j;
                    }
                }
            }
            else if(select==2) // 降序
            {
                for(int j=i+1;j<this->m_EmpNum;j++)
                {
                    if(this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id) //这样操作就是回到本属于他的位置
                    {
                        minOrMax = j;
                    }
                }
            }
            else
            {
                cout<<"输入有误"<<endl;
                break;
            }

            if(minOrMax != i)
            {
                Worker *temp = this->m_EmpArray[i];
                this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
                this->m_EmpArray[minOrMax] = temp;
            }
        }
        cout<<"排序成功"<<endl;
        this->save();
    }

    system("pause");
    system("cls");
}

// 保存数组数据到文件
void WorkerManager::save()
{
    ofstream ofs;
    ofs.open(DATA_FILENAME, ios::out);

    for(int i=0;i<this->m_EmpNum;i++)
    {
        if(this->m_EmpArray[i] != NULL)
        {
            ofs<<this->m_EmpArray[i]->m_DeptName<<" "
                <<this->m_EmpArray[i]->m_Name<<" "
                <<this->m_EmpArray[i]->m_Id<<endl;
        }
        else
        {
            cout << "警告：第 " << i << " 个职工信息为空，无法保存数据" << endl;
        }
    }
    ofs.close();
}

// 清空文件
void WorkerManager::cleanFile()
{
    // 先输入管理员账号密码，与adminFile.txt中的账号密码进行比对，如果正确，清空文件，否则，提示错误
    ifstream ifs;
    ifs.open(ADMIN_FILENAME, ios::in);

    if(ifs.eof())
    {
        cout<<"管理员文件为空"<<endl;
        ifs.close();
        return;
    }

    char account[100];
    char password[100];
    ifs>>account;
    ifs>>password;

    cout<<"你只有三次机会输入账号密码"<<endl;
    for(int i=0;i<3;i++)
    {
        // 输入管理员账号密码，与文件的进行比对
        char adminAccount[20]={0};
        char adminPassword[20]={0};
        cout<<"请输入管理员账号"<<endl;
        cin>>adminAccount;
        cout<<"请输入管理员密码"<<endl;
        cin>>adminPassword;
        if(strcmp(adminAccount,account) == 0 && strcmp(adminPassword,password) == 0)
        {
            cout<<"管理员账号密码正确"<<endl;
            ifs.close();
            ofstream ofs;
            // 如果文件存在先删除，再创建
            ofs.open(DATA_FILENAME, ios::trunc);
            ofs.close();
            if(this->m_EmpArray != NULL)
            {
                for(int i=0;i<this->m_EmpNum;i++)
                {
                    if(this->m_EmpArray[i] != NULL)
                    {
                        delete this->m_EmpArray[i];
                    }
                }
                delete[] this->m_EmpArray;
                this->m_EmpArray = NULL;
                this->m_EmpNum = 0;
                this->m_FileIsEmpty = true;
            }
            cout<<"清空文件成功"<<endl;
            break;
        }
        else
        {
            cout<<"管理员账号密码错误"<<endl;
        }
    }

    system("pause");
    system("cls");
}





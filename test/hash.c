#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 20 // 假设哈希表大小为 20

// 哈希表节点
struct Node 
{
    int key;//键
    int data;//数据
    struct Node* next;//next是一个指向下一个节点的指针，当哈希冲突发生时，允许在同一个哈希值位置上存储多个键值对。
};

struct Node* hashArray[SIZE]; // 哈希表数组

// 哈希函数：简单取余法
int hashCode(int key) 
{
    return key % SIZE;
}

// 插入数据到哈希表
void insert(int key, int data) 
{
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->data = data;
    newNode->next = NULL;

    int hashIndex = hashCode(key);

    // 如果该位置为空，直接插入新节点
    if (hashArray[hashIndex] == NULL) 
    {
        hashArray[hashIndex] = newNode;
    } 
    else 
    {
        // 如果该位置已经有节点，将新节点插入链表的末尾
        struct Node *temp = hashArray[hashIndex];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// 查找数据
int search(int key) 
{
    int hashIndex = hashCode(key);
    struct Node* temp = hashArray[hashIndex];

    // 在链表中查找对应的键值对
    while (temp != NULL) 
    {
        if (temp->key == key) 
        {
            return temp->data;
        }
        temp = temp->next;
    }

    return -1; // 若未找到对应键的数据，则返回 -1
}

int main() {
    memset(hashArray, 0, sizeof(hashArray)); // 初始化哈希表数组为空

    insert(1, 10);
    insert(2, 20);
    insert(3, 30);

    printf("Value for key 1: %d\n", search(1)); // 应输出 10
    printf("Value for key 3: %d\n", search(3)); // 应输出 30
    printf("Value for key 5: %d\n", search(5)); // 应输出 -1，因为键 5 不存在

    return 0;
}

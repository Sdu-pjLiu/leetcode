//
// Created by deepinsight on 2026/1/23.
// Author: lpj
//
#include <iostream> // 输入输出流库
using namespace std;

// =================== 1. 定义链表节点 ===================

// 链表节点结构体
struct ListNode {
    int val;          // 节点存储的数据（一个数字）
    ListNode *next;   // 指向下一个节点的指针

    // 构造函数：方便创建节点
    ListNode(int x) : val(x), next(nullptr) {}
    // 当创建一个节点时，只需要给值 x，它的 next 默认指向 nullptr
};

// =================== 2. 链表操作算法 ===================
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy_node = new ListNode(0); // 哑节点
        ListNode* current_node = dummy_node; // 当前链表

        int carry = 0;//进位变量
        // 当l1和l2节点不为空且进位不为0的时候
        while(l1 != nullptr || l2 != nullptr || carry != 0 ){
            int val1 = (l1 != nullptr)? l1 -> val : 0; // val1 的当前节点值
            int val2 = (l2 != nullptr)? l2 -> val : 0; // val2 的当前节点值
            int sum = val1 + val2 + carry; //当前节点值的和
            int res = sum % 10; // 当前节点的值
            carry = sum / 10; // 下一节点的进位
            current_node -> next = new ListNode(res); // 新建下一节点并存放值
            current_node = current_node -> next; // 移动到下一节点
            if (l1){ l1 = l1 -> next; } // 移动到下一节点
            if (l2){ l2 = l2 -> next; } // 移动到下一节点
        }
        return dummy_node -> next; // 返回哑节点之后的节点
    }
};
// =================== 3. 链表创建和打印 ===================

// 根据数组创建链表
ListNode* createList(int arr[], int n) {
    if (n == 0) return nullptr;            // 空数组返回空链表
    ListNode* head = new ListNode(arr[0]); // 创建头节点
    ListNode* tail = head;                 // tail 指向链表最后一个节点

    for (int i = 1; i < n; ++i) {
        tail->next = new ListNode(arr[i]); // 新节点接到尾巴
        tail = tail->next;                 // 更新尾指针
    }
    return head; // 返回链表头
}

// 打印链表
void printList(ListNode* head) {
    while (head) {                    // 遍历链表
        cout << head->val;            // 输出节点值
        if (head->next) cout << " -> "; // 输出箭头表示连接
        head = head->next;            // 移动到下一个节点
    }
    cout << endl;
}

// =================== 4. 主函数 ===================

int main() {
    // 创建两个测试链表
    int arr1[] = {2, 4, 3};           // l1 表示数字 342（倒序存储）
    int arr2[] = {5, 6, 4};           // l2 表示数字 465（倒序存储）

    ListNode* l1 = createList(arr1, 3); // 创建链表 l1
    ListNode* l2 = createList(arr2, 3); // 创建链表 l2

    Solution s;                        // 创建 Solution 对象
    ListNode* res = s.addTwoNumbers(l1, l2); // 调用函数得到结果链表

    cout << "结果链表: ";
    printList(res);                    // 打印结果链表 7 -> 0 -> 8

    return 0;                          // 程序结束
}

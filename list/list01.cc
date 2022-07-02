#define PATH 1
#if PATH == 1
#include "E:\GitStore\xb_algorithm\common\common.h"
#else
#include "G:\algorithm\xb_algorithm\common\common.h"
#endif
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/**
 * @brief 24. 两两交换链表中的节点
 * https://leetcode.cn/problems/swap-nodes-in-pairs/
 * 
 * 四指针
 * @param head 
 * @return ListNode* 
 */
ListNode* swapPairs(ListNode* head);
int main(){
    ListNode one(1), two(2), three(3);
    one.next = &two;
    two.next = &three;
    three.next = nullptr;
    ListNode* head = swapPairs(&one);
    while (head != nullptr){
        cout << head -> val << " ";
        head = head -> next;
    }
    cout << endl;
    return EXIT_SUCCESS;
}
ListNode* swapPairs(ListNode* head) {
    if (head == nullptr){
        return head;
    }
    ListNode *next = head -> next;
    if (next == nullptr){
        return head;
    }
    ListNode *now = head, *preNow, *preNext;
    head = next;
    while (next != nullptr){
        preNow = now;
        preNext = next;
        now = next -> next;
        next = now != nullptr ? now -> next : nullptr;
        preNext -> next = preNow;
        preNow -> next = next;
    }
    preNow -> next = now;
    return head;
}
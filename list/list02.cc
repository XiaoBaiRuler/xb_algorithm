#include "..//common/common.h"
/**
 * @brief 剑指 Offer 18. 删除链表的节点
 * https://leetcode.cn/problems/shan-chu-lian-biao-de-jie-dian-lcof/submissions/
 * 
 * @param head 
 * @param val 
 * @return ListNode* 
 */
ListNode* deleteNode(ListNode* head, int val);
int main(){
    cout << deleteNode(nullptr, 1) << endl;
    return EXIT_SUCCESS;
}
ListNode* deleteNode(ListNode* head, int val) {
    if (head == nullptr){
        return head;
    }
    if (head -> val == val){
        return head -> next;
    }
    ListNode *now = head -> next, *pre = head;
    while (now != nullptr && now -> val != val){
        now = now -> next;
        pre = pre -> next;
    }
    if (now != nullptr){
        pre -> next = now -> next;
    }
    return head;
}
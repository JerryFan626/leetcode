/*
2.  Add Two Numbers
题意：给你两个链表，每个节点的val为一位非负数，求两个链表对应节点值相加所形成的新的链表
思路：链表模拟就行了 注意下进位
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *L = (ListNode *)malloc(sizeof(ListNode));
        if(l1 == NULL && l2 == NULL){
            L->val = 0;
            return L;
        }
        while(l1 || l2){
            ListNode *tmp = (ListNode *)malloc(sizeof(ListNode));
            int val = 0;
            if(l1 != NULL) val += l1->val, l1 = l1->next;
            if(l2 != NULL) val += l2->val, l2 = l2->next;
            tmp->val = val;
            tmp->next = L->next;
            L->next = tmp;
        }
        return L->next;
    }

};
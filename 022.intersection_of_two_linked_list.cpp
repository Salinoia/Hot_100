#include <algorithm>
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr){}
};
class Solution{
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB){
        // 获取两个链表的长度
        ListNode* curA = headA;
        ListNode* curB = headB;
        int lenA = 0, lenB = 0;
        while(curA){
            curA = curA->next;
            lenA++;
        }
        while(curB){
            curB = curB->next;
            lenB++;
        }
        curA = headA;
        curB = headB;
        if(lenA < lenB){
            std::swap(lenA, lenB);
            std::swap(curA, curB);
        }
        int gap = lenA - lenB;
        while(gap--){ // 对齐长短链
            curA = curA->next;
        }
        while(curA){
            if(curA == curB){
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return nullptr;
    }
};

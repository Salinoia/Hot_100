struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode* next) : val(x), next(next){}
};
#include <stack>
class Solution {
public:
    ListNode* getMiddleNode(ListNode* node){
        ListNode* slow = node;
        ListNode* fast = node;
        while(node){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }    

    ListNode* reverseList(ListNode* head){
        ListNode* cur = head;
        ListNode* pre = nullptr;
        while(cur){
            ListNode* temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* mid = getMiddleNode(head);
        ListNode* tail = reverseList(mid->next);
        ListNode* front = head;
        ListNode* back = tail;
        while(front && back){
            if(front->val != back->val){
                return false;
            }
            front = front->next;
            back = back->next;
        }
        mid->next = reverseList(tail);
        return true;
    }
};
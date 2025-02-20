struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode* next) : val(x), next(next){}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* sentinel = new ListNode(-1);
        sentinel->next = head;
        ListNode* fast = sentinel;
        ListNode* slow = sentinel;
        n++;
        while(n-- && fast){
            fast = fast->next;
        }
        while(fast && slow){
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        return sentinel->next;
    }
};
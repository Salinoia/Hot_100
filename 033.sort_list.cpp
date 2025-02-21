struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // 链表长度为0或者1，直接返回
        if(!head || !head->next) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr;

        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        return merge(left, right);
    }
private:
    ListNode* merge(ListNode* left, ListNode* right){
        ListNode sentinel(-1);
        ListNode* tail = &sentinel;
        while(left && right){
            if(left->val < right->val){
                tail->next = left;
                left = left->next;
            }
            else{
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }
        tail->next = (left == nullptr) ? right : left;
        return sentinel.next;
    }
};
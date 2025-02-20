struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr){}
};

class Solution{
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        ListNode* sentinel = new ListNode(-1);
        ListNode* pre = sentinel;
        while (list1 && list2){
            if(list1->val < list2->val){
                pre->next = list1;
                list1 = list1->next;
            }
            else{
                pre->next = list2;
                list2 = list2->next;
            }
            pre = pre->next;
        }
        // 指向未合并完的链表
        pre->next = (list1 == nullptr) ? list2 : list1;

        return sentinel->next;
    }
};
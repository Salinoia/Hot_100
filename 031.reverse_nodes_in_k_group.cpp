struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode* next) : val(x), next(next){}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k == 1) return head;
        ListNode* sentinel = new ListNode(-1, head);
        ListNode* prev = sentinel, *cur = head;
        int count = 0;
        while(cur){
            cur = cur->next;
            count++;
        }

        cur = head;  // 重置 cur 指针
        while (count >= k) {
            ListNode* first = cur;  // 当前组的第一个节点
            ListNode* prev_local = nullptr;  // 用于局部翻转
            for (int i = 0; i < k; i++) {
                ListNode* temp = cur->next;
                cur->next = prev_local;
                prev_local = cur;
                cur = temp;
            }
            // 连接翻转后的组
            prev->next = prev_local;
            first->next = cur;
            prev = first;
            count -= k;
        }
        return sentinel->next;  // 返回新链表头
    }
};
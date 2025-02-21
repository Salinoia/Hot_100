struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#include <queue>
#include <vector>

using std::vector;
class Solution1 {
public:
    ListNode* mergeKListsHelper(vector<ListNode*>& lists, int left, int right){
        if(left == right) return lists[left];
        if(left > right) return nullptr;
        int mid = left + (right - left) / 2;
        ListNode* l1 = mergeKListsHelper(lists, left, mid);
        ListNode* l2 = mergeKListsHelper(lists, mid + 1, right);
        return mergeTwoLists(l1, l2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(!lists.size()){
            return nullptr;
        }    
        return mergeKListsHelper(lists, 0, lists.size() - 1);
    }
private:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2){
        if(!head1 || !head2) return head1 ? head1 : head2;
        ListNode sentinel(-1);
        ListNode* cur = &sentinel;
        while(head1 && head2){
            if(head1->val < head2->val){
                cur->next = head1;
                head1 = head1->next;
            }
            else{
                cur->next = head2;
                head2 = head2->next;
            }
            cur = cur->next;
        }
        cur->next = head1 ? head1 : head2;
        return sentinel.next;        
    }
};

class Solution2 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b){
            return a->val > b->val;
        };
        std::priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

        for(auto list : lists){
            if(list) pq.push(list);
        }

        ListNode sentinel(-1);
        ListNode* cur = &sentinel;
        while(!pq.empty()){
            ListNode* temp = pq.top();
            pq.pop();
            cur->next = temp;
            cur = cur->next;
            if(temp->next) pq.push(temp->next);
        }
        return sentinel.next;
    }
};
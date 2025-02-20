struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr){}
};
class Solution{
public:
    ListNode* detectCycle(ListNode* head){
        ListNode* SlowNode = head;
        ListNode* FastNode = head;
        while((FastNode != nullptr) && (FastNode->next!= nullptr)){
            SlowNode = SlowNode->next;
            FastNode = FastNode->next->next;
            if(FastNode == SlowNode){
                ListNode* FirstEncounter = FastNode;
                ListNode* EntranceNode = head;
                while(FirstEncounter != EntranceNode){
                    FirstEncounter = FirstEncounter->next;
                    EntranceNode = EntranceNode->next;
                }
                return EntranceNode;
            }
        }
        return nullptr;
    }
};
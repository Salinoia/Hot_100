class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

#include <unordered_map>
using std::unordered_map;
class Solution {
public:
    unordered_map<Node*, Node*> cachedNodes;
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return head;
        Node* cur = head;
        // 第一遍遍历：创建所有新节点，并建立映射关系
        while(cur){
            cachedNodes[cur] = new Node(cur->val);
            cur = cur->next;
        }

        cur = head;

        // 第二遍遍历：连接 next 和 random 指针
        while(cur){
            cachedNodes[cur]->next = cachedNodes[cur->next];
            cachedNodes[cur]->random = cachedNodes[cur->random];
            cur = cur->next;
        }
        return cachedNodes[head];
    }
};
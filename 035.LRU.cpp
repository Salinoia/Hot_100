/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
#include <unordered_map>
#include <list>

struct DoubleLinkedList{
    int key, value;
    DoubleLinkedList* prev;
    DoubleLinkedList* next;
    DoubleLinkedList() : key(0), value(0), prev(nullptr), next(nullptr){}
    DoubleLinkedList(int key, int value) : key(key), value(value), prev(nullptr), next(nullptr){}
};
class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity), size(0){
        dummyhead = new DoubleLinkedList();
        dummytail = new DoubleLinkedList();
        dummyhead->next = dummytail;
        dummytail->prev = dummyhead;
    }
    ~LRUCache(){
        DoubleLinkedList* cur = dummyhead->next;
        while(cur != dummytail){
            DoubleLinkedList* temp = cur;
            cur = cur->next;
            delete temp;
        }
        delete dummyhead;
        delete dummytail;
    }
    
    int get(int key) {
        if(!cache.count(key)){
            return -1;
        }
        DoubleLinkedList* node = cache[key];
        moveToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(!cache.count(key)){
            DoubleLinkedList* node = new DoubleLinkedList(key, value);
            cache[key] = node;
            addToHead(node);
            ++size;
            if(size > capacity){
                DoubleLinkedList* removed = removeTail();
                cache.erase(removed->key);
                delete removed;
                size--;
            }
        }
        else{
            DoubleLinkedList* node = cache[key];
            node->value = value;
            moveToHead(node);
        }
        return;
    }

    void addToHead(DoubleLinkedList* node){
        node->prev = dummyhead;
        node->next = dummyhead->next;
        dummyhead->next->prev = node;
        dummyhead->next = node;
        return;
    }

    void removeNode(DoubleLinkedList* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
        return;
    }
    void moveToHead(DoubleLinkedList* node){
        removeNode(node);
        addToHead(node);
        return;
    }
    DoubleLinkedList* removeTail(){
        DoubleLinkedList* node = dummytail->prev;
        removeNode(node);
        return node;
    }
private:
    int size, capacity;
    DoubleLinkedList* dummyhead;
    DoubleLinkedList* dummytail;
    std::unordered_map<int, DoubleLinkedList*> cache;
};

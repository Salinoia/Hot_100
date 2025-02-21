#include <list>
#include <unordered_map>
#include <stdexcept>
#include <optional>

template<typename K, typename V>
class LRUCache{
private:
    size_t capacity;
    std::list<K> lru_list;
    std::unordered_map<K, std::pair<V, typename std::list<K>::iterator>> cache;
public:
    LRUCache(size_t cap) : capacity(cap) {
        if(capacity == 0){
            throw std::invalid_argument("capacity must be positive");
        }
    }
    
    std::optional<V> get(const K& key){
        auto it = cache.find(key);
        if(it == cache.end()){
            return std::nullopt;
        }
        lru_list.splice(lru_list.begin(), lru_list, it->second.second);
        return &(it->second.first);
    }

    void put(const K& key, const V& value){
        auto it = cache.find(key);
        if(it != cache.end()){
            it->second.first = value;
            lru_list.splice(lru_list.begin(), lru_list, it->second.second);
            return;
        }

        if(cache.size() >= capacity){
            K lru_key = lru_list.back();
            cache.erase(lru_key);
            lru_list.pop_back();
        }

        lru_list.push_front(key);
        cache[key] = {value, lru_list.begin()};
    }
};
#include <iostream>
int main(){
    LRUCache<int, int> LRU(3);
    LRU.put(1, 3);
    LRU.put(2, 3);
    LRU.put(3, 3);
    LRU.put(2, 4);
    std::cout << *LRU.get(2) << std::endl;
    return 0;
}
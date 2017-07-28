class LRUCache {
  public:
    LRUCache(int capacity) : _capacity(capacity) {}

    int get(int key) {
      auto result = cache.find(key);
      if(result == cache.end())   return -1;
      else{
        update(result);
        return result->second.first;
      }
    }

    void put(int key, int value) {
      auto result = cache.find(key);
      if(result == cache.end()){
        if(cache.size() == _capacity){
          cache.erase(used.back());
          used.pop_back();
        }
        used.push_front(key);
      }
      else    update(result);
      cache[key] = make_pair(value, used.begin());
    }

  private:

    void update(unordered_map<int, pair<int, list<int>::iterator>>::iterator it) {
      used.erase(it->second.second);
      used.push_front(it->first);
      it->second.second = used.begin();
    }

    unordered_map<int, pair<int, list<int>::iterator>> cache;
    list<int> used;
    int _capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

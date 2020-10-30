#include<bits/stdc++.h>
using namespace std;// Linked list operations
// void add_at_tail(int val)
// void delete_node(ListNode* node)
// void delete_from_head()
// void delete_from_tail()
// ListNode* get_head()
// void set_head(ListNode* node)
// ListNode* get_tail()
// void set_tail(ListNode* node)

// simple single threaded LRUCache
class LRUCache {

  unordered_set<int> cache;

  // each entry in linked list is the value of the element
  list cache_vals;
  int capacity; // total capacity
public:

  LRUCache(int capacity) {
    this->capacity = capacity;
  }
  
  ~LRUCache() {
    cache.clear();
  }

  ListNode* get(int val) {
    auto p = cache.find(val);
    if (p == cache.end()) {
      return nullptr;
    }
    else{
      ListNode* i = cache_vals.get_head();
      while(i != nullptr){
        if (i->value == val){
          return i;
        }
        i = i->next;
      }
    }
  }

  void set(int value) {
    ListNode* check = get(value);
    if(check == nullptr){
      if(cache.size() >= capacity){
        cache_vals.add_at_tail(value);
        int head_val = cache_vals.get_head()->value;
        cache.erase(head_val);
        cache_vals.delete_from_head();
      }
      else{
        cache_vals.add_at_tail(value);
        cache.insert(value);
      }
    }
    else{
      if(check == cache_vals.get_tail()){
        return;
      }
      if(check == cache_vals.get_head()){
        cache_vals.add_at_tail(check->value);
        cache_vals.delete_from_head();
        return;
      }
      if(check->prev != nullptr){
        check->prev->next = check->next;
      }
      if(check->next != nullptr){
        check->next->prev = check->prev;
      }
      cache_vals.add_at_tail(check->value);
      delete check;
    }
  }

  void print() {
    ListNode* i = cache_vals.get_head();
      while(i != nullptr){
        cout << i->value << ", ";
        i = i ->next;
      }
    cout << endl;
  }
};

int main(int argc, char const *argv[])
{
  LRUCache cache(4);
  cache.set(1);
  cache.print();

  cache.set(2);
  cache.print();

  cache.set(3);
  cache.print();

  cache.set(4);
  cache.print();

  cache.set(5);
  cache.print();

  cache.set(2);
  cache.print();

  return 0;
}
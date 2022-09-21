/*
 * Starter code (Node/Cache/Main): Hackerrank.com
 * LRUCache Author: Justin Cromer
 * Date: 09/21/2022
 */
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache : public Cache {
private:
    /**
     * remove(): Removes target node from the map as well as linked list.
     * @lru: Pointer to least recently used node.
     *
     * Removes node from doubly-linked list first, O(1), then removes node and
     * key from map, also O(1).
     */
    void remove(Node *lru) {
        lru->prev->next = lru->next;
        lru->next->prev = lru->prev;
        this->mp.erase(lru->key);
        delete(lru);
    }

public:
    /**
     * set(): Adds a node to the list and map.
     * @p_key: Key for the new node.
     * @p_val: Value for the new node.
     *
     * If adding a new node would cause the map to cache to exceed its capacity,
     * calls remove() on the least recently used node. After adding the new node,
     * it is moved to the front of the doubly-linked list to indicate it was the 
     * most recently used node.
     */
    void set(int p_key, int p_val) {
        Node * temp;
        map<int,Node*>::iterator it = this->mp.find(p_key);
        if (it != this->mp.end()) {
            temp = it->second;
            this->mp.erase(it);
            delete(temp);
        }
        
        if (this->mp.size() == this->cp) {
            this->remove(this->tail->prev);
        }
        temp = new Node(this->head, this->head->next, p_key, p_val);
        this->head->next->prev = temp;
        this->head->next = temp;
        this->mp.insert(pair<int,Node*>(p_key, temp));
    }
    
    /**
     * get(): Checks if key exists in cache.
     * @p_key: Key to search cache for.
     *
     * Returns: Coresponding value if key exists in cache, else -1.
     */
    int get(int p_key) {
        int rv = -1;
        map<int,Node*>::iterator it = this->mp.find(p_key);
        if (it != this->mp.end()) {
            this->set(p_key, it->second->value);
            rv = it->second->value;
        }
        return rv;
    }
    
    LRUCache(int c) { 
        // problem parameters state this is the largest size for the cache
        const int MAX_SIZE = 500000;
        this->cp = c;  

        // begin by allocating memory for the map, else the growth of the map
        // destroys efficiency of large use-cases.
        this->mp.get_allocator().allocate(MAX_SIZE);

        // set up the linked list with head/tail as dummy nodes
        this->head = new Node(0, 0); 
        this->tail = new Node(0, 0);
        this->head->next = this->tail;
        this->tail->prev = this->head;
    };
    
    ~LRUCache() {
        for (auto &i: this->mp) {
            delete(i.second);
        }
        delete(this->head);
        delete(this->tail);
    }
};

// Driver class
int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}

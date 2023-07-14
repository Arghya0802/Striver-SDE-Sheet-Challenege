// LeetCode Link:  https://leetcode.com/problems/lru-cache/description/
// ---------------------------------------------------------------------

#include<bits/stdc++.h>

struct ListNode 
{
    int key ; int val ;

    ListNode *next ;  ListNode *prev ;

    ListNode(int x , int y)
    {
        key = x ;  val = y ;

        prev = NULL ; next = NULL ;
    }
};

class LRUCache
{
    private:
    ListNode *head , *tail ;
    unordered_map<int , ListNode *> map ;
    int maxCap ;

    public:
    LRUCache(int capacity)
    {
        head = new ListNode(-1 , -1) ;  tail = new ListNode(-1 , -1) ;

        maxCap = capacity ; 

        head -> next = tail ;  tail -> prev = head ;
    }

    void deleteNode(ListNode *node)
    {
        ListNode *prevNode = node -> prev ;  ListNode *nextNode = node -> next ;

        prevNode -> next = nextNode ;  nextNode -> prev = prevNode ;

        return ;
    }

    void insertAfterHead(ListNode *node)
    {
        ListNode *tempNode = head -> next ;

        head -> next = node ;  node -> next = tempNode ;
        node -> prev = head ;  tempNode -> prev = node ;

        return ;
    }

    int get(int key)
    {
        if(map.find(key) == map.end() )  return -1 ;

        auto *node = map[key] ;  

        deleteNode(node) ;  insertAfterHead(node) ;

        return node -> val ;
    }

    void put(int key, int value)
    {
        if(map.find(key) != map.end() ) 
        {
            auto *node = map[key] ;  node -> val = value ;

            deleteNode(node) ;  insertAfterHead(node) ;

            map[key] = node ;  return ;
        }

        if(map.size() < maxCap)
        {
            ListNode *node = new ListNode(key , value) ;

            insertAfterHead(node) ;  map[key] = node ;

            return ;
        }

        ListNode *LRU = tail -> prev ;  map.erase(LRU -> key) ;

        deleteNode(LRU) ;

        LRU -> key = key ;  LRU -> val = value ;

        insertAfterHead(LRU) ;  map[key] = LRU ;

        return ;
    }
};


// Time Complexity:  O(1) [On average for put() and get() functions ]
// Space Complexity: O(N) [Builiding a Doubly LinkedList and using Map]

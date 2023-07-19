// LeetCode Link:  https://leetcode.com/problems/lfu-cache/
// ---------------------------------------------------------

#include <bits/stdc++.h> 
struct Node 
{
    int key, value, cnt ;
    Node *next ; 
    Node *prev ;

    Node(int _key, int _value) 
    {
        key = _key ;  value = _value ; 
        cnt = 1 ; 

        prev = NULL ; next = NULL ;
    }
}; 

struct List 
{
   int size; 
   Node *head ; Node *tail ;

   List() 
   {
        head = new Node(0, 0) ; tail = new Node(0,0) ; 
        
        head -> next = tail ; tail -> prev = head; 
        
        size = 0;
   }
   
   void insertAfterHead(Node *node) 
   {
        Node* tempNode = head -> next;
       
        node -> next = tempNode ;  head -> next = node ;
        tempNode -> prev = node ;  node -> prev = head ;

        size++ ; 
   }
   
   void deleteNode(Node *node) 
   {
        Node* prevNode = node -> prev ; Node* nextNode = node -> next ;
        prevNode -> next = nextNode ;  nextNode -> prev = prevNode ;
        
        size-- ; 
   }
   
   
   
};

class LFUCache 
{
    unordered_map<int, Node*> keyNode ; 
    unordered_map<int, List*> freqListMap ; 
    int maxSizeCache ;
    int minFreq ; int curSize ;

public:
    LFUCache(int capacity) 
    {
        maxSizeCache = capacity ; 
        minFreq = 0 ;
        curSize = 0 ; 
    }

    void updateFreqListMap(Node *node) 
    {
        keyNode.erase(node -> key) ; freqListMap[node -> cnt] -> deleteNode(node) ; 

        if(node -> cnt == minFreq && freqListMap[node->cnt] -> size == 0) minFreq++ ;
        
        List* nextHigherFreqList = new List();
        
        if(freqListMap.find(node -> cnt + 1) != freqListMap.end())  nextHigherFreqList = freqListMap[node -> cnt + 1] ;

        node ->cnt += 1 ; 
        nextHigherFreqList->insertAfterHead(node) ; 

        freqListMap[node->cnt] = nextHigherFreqList ; 

        keyNode[node->key] = node;
    }
    
    int get(int key) 
    {
        if(keyNode.find(key) != keyNode.end()) 
        {
            Node* node = keyNode[key] ; int val = node->value; 
            
            updateFreqListMap(node) ; return val ; 
        }

        return -1 ; 
    }
    
    void put(int key, int value) 
    {
        if (maxSizeCache == 0)  return ;
        
        if(keyNode.find(key) != keyNode.end()) 
        {
            Node *node = keyNode[key] ; node -> value = value ; 
            
            updateFreqListMap(node) ; 
        }

        else 
        {
            if(curSize == maxSizeCache) 
            {
                List* list = freqListMap[minFreq] ; keyNode.erase(list -> tail -> prev -> key) ;

                freqListMap[minFreq] -> insertAfterHead(list -> tail -> prev) ;
                curSize-- ; 
            }

            curSize++ ; minFreq = 1 ;

            List* listFreq = new List(); 
            if(freqListMap.find(minFreq) != freqListMap.end()) listFreq = freqListMap[minFreq] ; 

            Node* node = new Node(key, value) ; listFreq->insertAfterHead(node) ;
            
            keyNode[key] = node ; freqListMap[minFreq] = listFreq ; 
        }
    }
};

// Time Complexity:  O(1) [For get() and put() functions on average]
// Space Complexity: O(N) [Storing all the Nodes and using Maps]

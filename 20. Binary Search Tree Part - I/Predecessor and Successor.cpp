// GFG Link:  https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1
// ----------------------------------------------------------------------------------

#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/
void findPredecessor(BinaryTreeNode<int> *root , int key , int &predecessor)
{
    while(root)
    {
        if(root -> data < key)
        {
            predecessor = root -> data ;

            root = root -> right ;
        }

        else  root = root -> left ;
    }

    return ;
}

void findSuccessor(BinaryTreeNode<int> *root , int key , int &successor)
{
    while(root)
    {
        if(root -> data > key)
        {
            successor = root -> data ;

            root = root -> left ;
        }

        else  root = root -> right ;
    }

    return ;
}

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    pair<int , int> ansPair ;

    int predecessor = -1 ; int successor = -1 ;

    findPredecessor(root , key , predecessor) ;

    findSuccessor(root , key , successor) ;

    ansPair.first = predecessor ;  ansPair.second = successor ;

    return ansPair ;    
}


// Time Complexity:  O(2 * Log N)
// Space Complexity: O(1)

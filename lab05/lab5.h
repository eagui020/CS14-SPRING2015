///
//  Eric Aguirre
//  861174273
//  5/12/15
//  1. Use DFS to search through and see if child is not selected parent is for
//  both sides
//  2. Use buffer[0] as bool with 0 and 1 and if returns 1 print the path
//  3. Traverse then create the sum for the vertical index if not found else 
//  add to it
///

#ifndef LAB5_H
#define LAB5_H
#include <cassert>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <map>
#include <list>
#include <math.h>
using namespace std;
#define nil 0

// #define Value int // restore for testing.
template <typename Value>
class BST
{   
    private:
        class Node { // binary tree node
            public:
                Node* left;
                Node* right;
                Value value;
                bool selected;
                Node( const Value v = Value() ) 
                    : left(nil), right(nil), value(v), selected(false) {}
                Value& content() { return value; }
                
                bool isInternal() { return left != nil && right != nil; }
                bool isExternal() { return left != nil || right != nil; }
                bool isLeaf() { return left == nil && right == nil; }
                int height() 
                {
                    // returns the height of the subtree rooted at this node
                    // FILL IN
                    if (isLeaf()) return 0;
                    else
                    {
                        if (isInternal())
                        {
                            int leftHeight = left.height();
                            int rightHeight = right.height();
                            if (leftHeight > rightHeight)
                            {
                                return leftHeight + 1;
                            }
                            else
                            {
                                return rightHeight + 1;
                            }
                        }
                        else
                        {
                            if (left == nil)
                            {
                                return right.height() + 1;
                            }
                            else
                            {
                                return left.height() + 1;
                            }
                        }
                    }
                }
                int size() 
                {
                    // returns the size of the subtree rooted at this node,
                    // FILL IN
                    if (isLeaf()) return 1;
                    else
                    {
                        if (isInternal())
                        {
                            int leftSize = left->size();
                            int rightSize = right->size();
                            return leftSize + rightSize + 1;
                        }
                        else
                        {
                            if (left == nil)
                            {
                                return right->size() + 1;
                            }
                            else
                            {
                                return left->size() + 1;
                            }
                        }
                    }
                }
        }; // Node
        // const Node* nil; // later nil will point to a sentinel node.
        int count;
        
    public:
        Node* root;
        int size() 
        {
            // size of the overall tree.
            // FILL IN
            if (root == nil) return 0;
            return root->size();
        }
        bool empty() { return size() == 0; }
        void print_node( const Node* n ) const
        {
            // Print the node’s value.
            // FILL IN
            cout << n->value << endl;
            return;
        }
        bool search ( Value x ) 
        {
            // search for a Value in the BST and return true iff it was found
            // FILL IN
            if (empty()) return false;
            if (size() == 1)
            {
                return (x == root->value) ? true : false;
            }
            else
            {
                Node *temp = root;
                while (temp != nil)
                {
                    if (temp->value == x) return true;
                    if (x > temp->value) temp = temp->right;
                    else if (x < temp->value) temp = temp->left;
                }
                return false;
            }
        }
        void preorderHelp(Node* n) const
        {
            if (n != nil)
            {
                print_node(n);
                preorderHelp(n->left);
                preorderHelp(n->right);
            }
        }
        void preorder() const 
        {
            // Traverse and print the tree one Value per line in preorder.
            // FILL IN
            Node *temp = root;
            if (temp == nil)
            {
                cout << "Empty tree." << endl;
                return;
            }
            cout << "Preorder: ";
            preorderHelp(temp);
        }
        void postorderHelp(Node* n) const
        {
            if (n != nil)
            {
                postorderHelp(n->left);
                postorderHelp(n->right);
                print_node(n);
            }
        }
        void postorder()const 
        {
            // Traverse and print the tree one Value per line in postorder.
            // FILL IN
            Node *temp = root;
            if (temp == nil)
            {
                cout << "Empty tree." << endl;
                return;
            }
            cout << "Postorder: ";
            postorderHelp(temp);
        }
        void inorderHelp(Node* n) const
        {
            if (n != nil)
            {
                inorderHelp(n->left);
                print_node(n);
                inorderHelp(n->right);
            }
        }
        void inorder()const 
        {
            // Traverse and print the tree one Value per line in inorder.
            // FILL IN
            Node *temp = root;
            if (temp == nil)
            {
                cout << "Empty tree." << endl;
                return;
            }
            cout << "Inorder: ";
            inorderHelp(temp);
        }
        void inorderSearch(Node* curr, int &n, Node* &result)
        {
            if (curr == nil || n < -1) return;
            inorderSearch(curr->left, n, result);
            --n;
            if (n == -1)
            {
                result = curr;
                return;
            }
            inorderSearch(curr->right, n, result);
        }
        Value& operator[] (int n) 
        {
            // returns reference to the value field of the n-th Node.
            // FILL IN
            assert (size() > n && n >= 0);
            Node *temp = root;
            Node *result = nil;
            inorderSearch(temp, n, result);
            return result->value;
        }
        BST() : count(0), root(nil) {}
        void insert( Value X ) 
        { 
            root = insert( X, root );
        }
        Node* insert( Value X, Node* T )
        {
            // The normal binary-tree insertion procedure ...
            if ( T == nil )
            {
                T = new Node( X ); // the only place that T gets updated.
            } 
            else if ( X < T->value )
            {
                T->left = insert( X, T->left );
            } 
            else if ( X > T->value )
            {
                T->right = insert( X, T->right );
            } 
            else 
            {
                T->value = X;
            }
            // later, rebalancing code will be installed here
            return T;
        }
        void remove( Value X ) { root = remove( X, root ); }
        Node* remove( Value X, Node*& T ) 
        {
            // The normal binary-tree removal procedure ...
            // Weiss’s code is faster but way more intricate.
            if ( T != nil ) 
            {
                if ( X > T->value ) 
                {
                    T->right = remove( X, T->right );
                } 
                else if ( X < T->value ) 
                {
                    T->left = remove( X, T->left );
                } 
                else 
                {
                    // X == T->value
                    if ( T->right != nil ) 
                    {
                        Node* x = T->right;
                        while ( x->left != nil ) x = x->left;
                        T->value = x->value; // successor’s value
                        T->right = remove( T->value, T->right );
                    } 
                    else if ( T->left != nil ) 
                    {
                        Node* x = T->left;
                        while ( x->right != nil ) x = x->right;
                        T->value = x->value; // predecessor’s value
                        T->left = remove( T->value, T->left );
                    } 
                    else 
                    { // *T is external
                        delete T;
                        T = nil; // the only updating of T
                    }
                }
            }
            // later, rebalancing code will be installed here
            return T;
        }
        void okay( ) { okay( root ); }
        // void okay( Node* T ) 
        // {
        //     // diagnostic code can be installed here
        //     return;
        // }

        void DFS(Node *x)
        {
            if (x == nil) return;
            DFS(x->left);
            DFS(x->right);
            if (x->isExternal())
            {
                /* if child is not selected as a vertex for minimum selected cover then
                select the parent */
                if (x->isInternal())
                {
                    if(!((x->left->selected) && (x->right->selected)))
                    {
                        x->selected = true;
                    }
                }
                else
                {
                    if (x->left != nil)
                    {
                        if (!(x->left->selected)) x->selected = true;
                    }
                    else
                    {
                        if (!(x->right->selected)) x->selected = true;
                    }
                }
            }
        }
        
        void minCover()
        {
            if (empty()) return;
            DFS(root->left);
            DFS(root->right);
        }
        
        void inorderMinCover(Node* n, int &count) const
        {
            if (n != nil)
            {
                inorderMinCover(n->left, count);
                if (n->selected)
                {
                    count++;
                    cout << n->value << " ";
                }
                inorderMinCover(n->right, count);
            }
        }
        
        void displayMinCover()
        {
            int n = 0;
            minCover();
            cout << "Part 1" << endl;
            inorderMinCover(root, n);
            cout << endl;
            cout << n << endl;
        }
        
        void findSumPath(Node* n, int sum, int buffer[])
        {
            // Subtract value from sum when recurring
            // and check to see if the sum is 0 when done
            static int i = 1;
            if(n == nil)
            {
                if (sum == 0)
                {
                    buffer[0] = 1;
                    for (int j = i - 1; j > 0; --j)
                    {
                        cout << buffer[j] << " ";
                    }
                    cout << endl;
                    return;
                }
                return;
            }
            else
            {
                int currSum = sum - n->value;
                if(currSum < 0) return;
                buffer[i] = n->value;
                ++i;
                if ( currSum == 0 && n->isLeaf() )
                {
                    findSumPath(n->left, currSum, buffer);
                }
                if(n->left) findSumPath(n->left, currSum, buffer);
                if(n->right) findSumPath(n->right, currSum, buffer);
            }
        }
        void printSumPath(Node* n, int sum, int buffer[])
        {
            cout << "Part 2" << endl;
            findSumPath(n, sum, buffer);
            if (buffer[0] == 0)
            {
                cout << "0" << endl;
            }
        }
        
        void vertSum(Node* node, int hd, map<int, int>& m)
        {
            if(node==NULL) return;
        	m[hd]+=node->value;
        	vertSum(node->left, hd-1, m);
        	vertSum(node->right, hd+1, m);
        }
        
        void printVertSum(Node* node, int hd, map<int, int>& m)
        {
            vertSum(node, hd, m);
            cout << "Part 3" << endl;
            for (map<int, int>::iterator it = m.begin(); it!=m.end(); ++it)
            {
                cout << it->second << " ";
            }
            cout << endl;
        }

}; // BST

#endif
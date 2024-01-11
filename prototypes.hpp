#ifndef PROTOTYPES_HPP
#define PROTOTYPES_HPP
#include <iostream>

class Node
{
    public:
    int value;
    Node* left;
    Node* right;
    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};


class BinarySearchTree
{
    private:
    Node* root;

    private:
    Node* insertHelper(Node* node , int val);                       //done
    void inorderHelper(Node* node);                                 //done
    void preorderHelper(Node* node);                                //done
    void postorderHelper(Node* node);                               //done
    Node* removeHelper(Node* node , int val);                       //done
    Node* searchHelper(Node* node, int val);                        //done
    Node* find_minHelper(Node* node);                               //done
    Node* find_maxHelper(Node* node);                               //done            
    int sizeHelper(Node* node);                                     //done
    int heightHelper(Node* node);                                   //done
    void clearHelper(Node* &node);                                  //done  
    void serializeHelper(Node* node , std::vector<int>& result);    //done
    void levelorderHelper(Node* node, int level);                   //done  
    Node* successorHelper(Node* node, Node* &succ , int val);       //done
    Node* predecessorHelper(Node* node, Node* &succ , int val);     //done
    Node* copyHelper(Node* node);                                   //done
    bool is_validHelper(Node* node);                                //done



    public:
    BinarySearchTree();                                             //done
    ~BinarySearchTree();                                            //done
    void insert(int val);                                           //done  
    void remove(int val);                                           //
    void inorder();                                                 //done
    void preorder();                                                //done
    void postorder();                                               //done
    bool search(int val);                                           //done
    int find_min();                                                 //done
    int find_max();                                                 //done
    int size();                                                     //done
    int height();                                                   //done
    void clear();                                                   //done
    std::vector<int> serialize();                                   //done
    void range_query(int start, int end);                           //done
    void levelorder();                                              //done
    void print_tree();                                              //done
    int successor(int val);                                         //done
    int predecessor(int val);                                       //done
    void update(int val , int new_val);                             //done
    Node* copy();                                                   //done
    int kth_smallest(int k);                                        //done
    int kth_largest(int k);                                         //done
    bool is_valid();                                                //
    Node* find(int val);                                            //done
    
    void setRoot(Node* node)                                        
    {
        this -> root = node;
    }
};

#endif 
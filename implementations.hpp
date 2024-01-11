#include "prototypes.hpp"

//CONSTRUCTOR
BinarySearchTree::BinarySearchTree() : root(nullptr) {}

//DESTRUCTOR
BinarySearchTree::~BinarySearchTree()
{
    clear();
}

//INSERT HELPER FOR RECURSION
Node* BinarySearchTree::insertHelper(Node* node , int val)
{
    if(!node)
    {
        return new Node(val);           //if there is no root, make a new root with given value
    }

    if (val < node -> value) 
    {
        node -> left = insertHelper(node -> left, val);   //add node for right subtree
    } 
    
    else if (val > node-> value)                        
    {               
        node -> right = insertHelper(node -> right, val);  //add node for right subtree
    }

    return node;
}

//INSERT
void BinarySearchTree::insert(int val)
{
    root = insertHelper(root,val);
}

//INORDER HELPER FOR RECURSION    left, root, right
void BinarySearchTree::inorderHelper(Node* node)
{
    if(node != nullptr)
    {
        inorderHelper(node -> left);
        std::cout << node -> value << " ";     
        inorderHelper(node -> right);
    }
}

//INORDER
void BinarySearchTree::inorder()
{
    inorderHelper(root);
    std::cout << std::endl;
}

//PREORDER HELPER FOR RECURSION     root, left, right
void BinarySearchTree::preorderHelper(Node* node)
{
    if(node != nullptr)
    {
        std::cout << node -> value << " ";
        preorderHelper(node -> left);
        preorderHelper(node -> right);
    }
}

//PREORDER
void BinarySearchTree::preorder()
{
    preorderHelper(root);
    std::cout << std::endl;
}

//POSTORDER HELPER FOR RECURSION    left,right,root
void BinarySearchTree::postorderHelper(Node* node)
{
    if(node != nullptr)
    {
        postorderHelper(node -> left);
        postorderHelper(node -> right);
        std::cout << node -> value << " ";
    }
}

//POSTORDER
void BinarySearchTree::postorder()
{
    postorderHelper(root);
    std::cout << std::endl;
}

//REMOVE HELPER FOR RECURSION
Node* BinarySearchTree::removeHelper(Node* node , int val)
{
    if(!node)
    {
        return nullptr;                             //nothing to remove
    }

    if(val < node -> value)
    {
        node -> left = removeHelper(node -> left, val);         //serach in left subtree
    }

    if(val > node -> value)
    {
        node -> right = removeHelper(node -> right, val);       //search in right subtree
    }

    if(val == node -> value)                                    //node was found
    {
        if(node -> left == nullptr)                             //if node has no left subtree, insert right subtree in its place
        {
            Node* tmp = node -> right;
            delete node;
            return tmp;
        }

        else if(node -> right == nullptr)                       //if node has no right subtree, insert left subtree in its place
        {
            Node* tmp = node -> left;
            delete node;
            return tmp;
        }

        Node* tmp = find_minHelper(node -> right);                  //if node has two subtrees, we must find the successor of that node
        node -> value = tmp -> value;                               //after finding the successor, we assign its value to the node we want to remove
        node -> right = removeHelper(node -> right,node -> value);  //remove the successor by the same function
    }
    return node;
}

//REMOVE
void BinarySearchTree::remove(int val)
{
    root = removeHelper(root,val);
}

//SEARCH HELPER FOR RECURSION
Node* BinarySearchTree::searchHelper(Node* node, int val)
{
    if(!node)
    {
        return nullptr;                         
    }

    if(node -> value == val)                //searchable node was found
    {
        return node;
    }

    if(val < node -> value)                 //if searchable node exists, it is in left subtree
    {
        return searchHelper(node -> left, val);
    }

    else // (val > node -> value)           //if searchable node exists, it is in right subtree
    {
        return searchHelper(node -> right, val);
    }
}

//SEARCH
bool BinarySearchTree::search(int val)
{
    if(searchHelper(root,val))              //if the returned pointer wasn't nullptr, searchable node was found
    {
        return true;
    }

    return false;
}

//FIND_MIN HELPER FOR RECURSON 
Node* BinarySearchTree::find_minHelper(Node* node)
{
    if(!node)
    {
        return nullptr;
    }

    if(node -> left)
    {
        while(node -> left)
        {
            node = node -> left;            //minimum node is the most left located node
        }
    }
    return node;
}

//FIND_MIN
int BinarySearchTree::find_min()
{
    Node* tmp = find_minHelper(root);
    
    if (tmp) 
    {
       return tmp -> value;             
    }
    return -1;
}

//FIND_MAX HELPER FOR RECURSION
Node* BinarySearchTree::find_maxHelper(Node* node)
{
    if(!node)
    {
        return nullptr;
    }

    if(node -> right)
    {
        while(node -> right)
        {
            node = node -> right;  //maximum node is the most right located node         
        }
    }
    return node;
}

//FIND_MAX 
int BinarySearchTree::find_max()
{
    Node* tmp = find_maxHelper(root);
    
    if (tmp) 
    {
       return tmp -> value;
    }
    return -1;
}

//SIZE HELPER FOR RECURSION
int BinarySearchTree::sizeHelper(Node* node)
{
    if (node == nullptr)
    {
        return 0;
    }

    int leftSize = sizeHelper(node->left);              
    int rightSize = sizeHelper(node->right);            
    
    return leftSize + rightSize + 1;            //+1 is for the root node 
}

//SIZE
int BinarySearchTree::size()
{
    return sizeHelper(root);
}

//HEIGHT HELPER FOR RECURSION
int BinarySearchTree::heightHelper(Node* node) 
{
    if (node == nullptr) 
    {
        return 0;
    }

    int leftHeight = heightHelper(node->left);
    int rightHeight = heightHelper(node->right);
    //if even in one subtree there is a node, height += 1

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);  //+1 is for root node
    
}

//HEIGHT
int BinarySearchTree::height()
{
    return heightHelper(root);
}

//CLEAR HELPER FOR RECURSION
void BinarySearchTree::clearHelper(Node* &node)
{
    if(!node)
    {   
        return;
    }

    clearHelper(node -> left);    //reach to the most left node and delete from there node by node
    clearHelper(node -> right);
    delete node;
    node = nullptr;  
}

//CLEAR
void BinarySearchTree::clear()
{
    clearHelper(root);
}

//SERIALIZE HELPER FOR RECURSION
void BinarySearchTree::serializeHelper(Node* node, std::vector<int>& result)
{ 
    if (node != nullptr) 
    {
        serializeHelper(node->left, result);
        result.push_back(node->value);                  //collect vector in ascending order, using inorder traversal method
        serializeHelper(node->right, result);
    }
}        

//SERIALIZE
std::vector<int> BinarySearchTree::serialize()
{
    std::vector<int> result;
    serializeHelper(root, result);
    return result;
}

//RANGE_QUERY
void BinarySearchTree::range_query(int start, int end)
{
    for(int i = start; i <= end; ++i)               //if the node with value from that range is found, print it
    {
        if(search(i))
        {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
}

//FIND
Node* BinarySearchTree::find(int val)
{
    return searchHelper(root,val);
}

//LEVEL_ORDER HELPER FOR RECURSION
void BinarySearchTree::levelorderHelper(Node* node, int level)
{
    if(node == nullptr)
    {
        return;
    }

    if(level == 1)
    {
        std::cout << node -> value << " ";  //if its the lowest level, print 
    }

    else if(level > 1)
    {
        levelorderHelper(node -> left, level - 1);   
        levelorderHelper(node -> right , level - 1);
    }
}

//LEVEL_ORDER
void BinarySearchTree::levelorder()
{
    int h = heightHelper(root);  //to print by levels, we need the height of tree
    for(int i = 1 ; i <= h ; ++i)
    {
        levelorderHelper(root,i);  //call for the function, to print each level 
    }
    std::cout << std::endl;
}

//PRINT_TREE
void BinarySearchTree::print_tree()
{
    int h = heightHelper(root);             //same as level order
    for(int i = 1 ; i <= h ; ++i)
    {
        levelorderHelper(root,i);
        std::cout <<  std::endl;
    }
    std::cout << std::endl;
}

//SUCCESSOR HELPER FOR RECURSION
Node* BinarySearchTree::successorHelper(Node* node, Node* &succ , int val)
{
    if(!node)
    {
        return nullptr;             
    }

    if(val == node -> value)                    //if the node was found and it has right subtree, the minimum element of right subtree node is its successor
    {
        if(node -> right)
        {
            Node* tmp = find_minHelper(node -> right);
            succ = tmp;
        }
    }

    else if(val < node -> value)                // this condition means that the successor is over and not under the searchable node
    {
        succ = node;                            //every time we met a node with larger value than the node, we assume it is the successor
        return successorHelper(node -> left , succ, val);
    }

    else
    {
        return successorHelper(node -> right , succ , val);
    }

    return node;
}

//SUCCESSOR
int BinarySearchTree::successor(int val)
{
    if(!search(val))
    {
        std::cout << "Node doesn't exist: " << std::endl;
        exit(0);
    }

    Node* succ = nullptr;
    if(successorHelper(root , succ , val))
    {
        return succ -> value;
    }

    else
    {
        std::cout << "Successor of node doesn't exist: " << std::endl;
        exit(0);
    }
}

//PREDECESSOR HELPER FOR RECURSION
Node* BinarySearchTree::predecessorHelper(Node* node, Node* &succ , int val)
{
    if(!node)
    {
        return nullptr;
    }

    if(val == node -> value)
    {
        if(node -> left)
        {
            Node* tmp = find_maxHelper(node -> left);  //if the node was found and it has left subtree, the maximum element of right left subtree is its predecessor
            succ = tmp;
        }
    }

    else if(val > node -> value)            // this condition means that the successor is over and not under the searchable node
    {
        succ = node;                     //every time we met a node with smaller value than the node, we assume it is the predecessor
        return predecessorHelper(node -> right , succ, val);
    }

    else
    {
        return predecessorHelper(node -> left , succ , val);
    }

    return node;
}

//PREDECESSOR
int BinarySearchTree::predecessor(int val)
{
    if(!search(val))
    {
        std::cout << "The Node doesn't exist: " << std::endl;
        exit(0);
    }

    Node* succ = nullptr;
    if(predecessorHelper(root , succ , val))
    {
        return succ -> value;
    }

    else
    {
        std::cout << "Successor doesn't exist: " << std::endl;
        exit(0);
    }
}

//UPDATE
void BinarySearchTree::update(int val , int new_val)
{
    if(!search(val))
    {
        std::cout << "Node doesn't exist: " << std::endl;
        return;
    }

    remove(val);
    insert(new_val);
}

//COPY HELPER FOR RECURSION
Node* BinarySearchTree::copyHelper(Node* node) 
{
    if (node == nullptr) 
    {
        return nullptr;
    }

    Node* newRoot = new Node(node -> value);                    //copy the given root

    newRoot->left = copyHelper(node -> left);                   //recursively copy its right and left subtrees
    newRoot->right = copyHelper(node -> right);

    return newRoot;
}

//COPY
Node* BinarySearchTree::copy()
{
    return copyHelper(root);
}

//KTH SMALLEST
int BinarySearchTree::kth_smallest(int k)
{
    if(!root || k <= 0 || k > this -> size())
    {
        std::cout << "Unvalid operation: " <<std::endl;
        return -1;
    }

    BinarySearchTree tmp_tree;
    Node* new_root = this -> copy();            //copy the given tree
    tmp_tree.setRoot(new_root);

    for(int i = 0; i < k - 1; ++i)
    {
        tmp_tree.remove(tmp_tree.find_min());       //k times delete the minimum element of copy tree
    }

    int result = tmp_tree.find_min();               //the last minimum elemnt of copy tree is kth smallest element of original tree
    tmp_tree.clear();
    return result;
}

//KTH LARGEST
int BinarySearchTree::kth_largest(int k )
{
    if(!root || k <= 0 || k > this -> size())
    {
        std::cout << "Unvalid operation: " <<std::endl;
        return -1;
    }

    BinarySearchTree tmp_tree;
    Node* new_root = this -> copy();                    //copy the given tree
    tmp_tree.setRoot(new_root);

    for(int i = 0; i < k - 1; ++i)
    {
        tmp_tree.remove(tmp_tree.find_max());           //k times delete the maximum element of copy tree
    }

    int result = tmp_tree.find_max();               //the last maximum elemnt of copy tree is kth largest element of original tree
    tmp_tree.clear();
    return result;
}

//IS_VALID HELPER FOR RECURSION
bool BinarySearchTree::is_validHelper(Node* node)
{
    if(!node)
    {
        return true;
    }

    if(node -> left != nullptr && node -> left -> value > node -> value)        //if nodes value is smaller then the value of its left, the tree is unvalid
    {
        return false;                                           
    }

    if(node -> right != nullptr && node -> right -> value < node -> value)      //if nodes value is larger then the value of its right, the tree is unvalid
    {
        return false;
    }

    bool left = is_validHelper(node -> left);
    bool right = is_validHelper(node -> right);

    if(left && right)                   //if both subtrees are valid, tree is valid
    {
        return true;
    }
    return false;
}

bool BinarySearchTree::is_valid()
{
    return is_validHelper(root);
}



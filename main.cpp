#include "implementations.hpp"

int main()
{
    BinarySearchTree BST;
    BST.insert(8);                                                              //insert
    BST.insert(3);
    BST.insert(10);
    BST.insert(1);
    BST.insert(6);
    BST.insert(4);
    BST.insert(7);
    BST.insert(13);
    BST.insert(14);
    BST.insert(17);
    BST.insert(20);

    std::cout << "Tree in Inorder Traversal: "; 
    BST.inorder();                                                              //inorder traversal       
    std::cout << std::endl;

    std::cout << "Tree in Preorder Traversal: "; 
    BST.preorder();                                                             //preorder traversal
    std::cout << std::endl;

    std::cout << "Tree in Postorder Traversal: "; 
    BST.postorder();                                                            //postorder traversal   
    std::cout << std::endl;

    int searched_value = 3;                                                     //search
    if(BST.search(searched_value))
    {
        std::cout << "Element " << searched_value <<" was found:" << std::endl;
    }
    else
    {
        std::cout << "Element " << searched_value<<" was NOT found:" << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Smallest element of tree is: ";                                   //find_min
    if(BST.find_min() != -1)
    {
        std::cout << BST.find_min() << std::endl;
    }
    std::cout << "Unvalid operation: "<<std::endl;
    std::cout << std::endl;


    std::cout << "Largest element of tree is: ";                                    //find_max
    if(BST.find_max() != -1)
    {
        std::cout << BST.find_max() << std::endl;
    }
    std::cout << "Unvalid operation: "<<std::endl;
    std::cout << std::endl;


    std::cout << "Vector of tree: ";                                                //serialize
    std::vector<int> tmp = BST.serialize();                        
    for(int i = 0; i < tmp.size(); ++i)
    {
        std::cout << tmp[i] << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Nodes in range [10;20]: ";                                        //range_query
    BST.range_query(10,20); 
    std::cout << std::endl;

    std::cout << "Tree in Levelorder Traversal: ";                
    BST.levelorder();                                                               //levelorder traversal
    std::cout << std::endl;

    std::cout<<"Size of tree is: " << BST.size() << std::endl;                      //size;
    std::cout << std::endl;

    std::cout<<"Height of tree is: " << BST.height() << std::endl;                  //height
    std::cout << std::endl;

    std::cout << "Tree printed: " << std::endl;                                     //print_tree
    BST.print_tree(); 

    std::cout << "Successor of node 7 is: " << BST.successor(7) << std::endl;       //successor
    std::cout << std::endl;

    std::cout << "Predecessor of node 14 is: " << BST.predecessor(14) << std::endl; //predecessor
    std::cout <<std::endl;

    std::cout << "Remove node 8: ";                                                 //remove
    BST.remove(8);
    BST.inorder();
    std::cout << std::endl;

    std::cout << "Copy of tree: ";                                                  //copy
    BinarySearchTree obj;
    Node* copy_tree = BST.copy();
    obj.setRoot(copy_tree);
    obj.inorder();
    std::cout << std::endl;


    std::cout << "Update 8 to 10: " ;                                               //update
    BST.update(10,80);
    BST.inorder(); 
    std::cout << std::endl;
    
    std::cout << "2nd smallest element is: ";                                       //kth_smallest                               
    if(BST.kth_smallest(2) != -1)
    {
        std::cout << BST.kth_smallest(2) << std::endl; 
    }
    std::cout << std::endl;

    std::cout << "2nd largest element is: ";                                        //kth_largest              
    if(BST.kth_largest(2) != -1)
    {
        std::cout << BST.kth_largest(2) << std::endl; 
    }
    std::cout << std::endl;

    if(BST.is_valid())                                                             //is_valid
    {
        std::cout << "Current tree is valid BST: " << std::endl;
        std::cout << std::endl;
    }
    else
    {
        std::cout << "Current tree is unvalid BST: " << std::endl;
        std::cout << std::endl;
    }

    BST.clear();                                                                     //clear
    std::cout<<"Size after clean: " << BST.size() << std::endl;    
    std::cout << std::endl; 
    std::cout<<"Height after clean: " << BST.height() << std::endl;
    std::cout << std::endl; 
}
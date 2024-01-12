# Binary-Search-Tree-Implementation

In computer science, a **binary search tree (BST)**, also called an ordered or sorted binary tree, is a rooted binary tree data structure with the key of each internal node being greater than all the keys in the respective node's left subtree and less than the ones in its right subtree. The time complexity of operations on the binary search tree is linear with respect to the height of the tree. <br>
<br>

Binary Search Tree data structure has the following properties:
* The left subtree of a node contains only nodes with keys lesser than the node’s key.
* The right subtree of a node contains only nodes with keys greater than the node’s key.
* The left and right subtree each must also be a binary search tree.

![Binary_search_tree_example](https://github.com/anush-hambardzumyan/Binary-Search-Tree-Implementation/assets/66312436/c03317f6-9f16-467c-a7ac-af411cf80680)
____
The complexity analysis of BST shows that, on average, the insert, delete and search takes O(logn) for n nodes. In the worst case, they degrade to that of a singly linked list: O(n)

| Operation | Average | Worst Case |
| :----: | :----: | :----: |
| Search | O(log n) | O(n) |
| Insert | O(log n) | O(n) |
| Delete | O(log n) | O(n) |
__________

**This implementation includes following methods**
- [x] Constructor
- [x] Destructor
- [x] Insert
- [x] Remove
- [x] Inorder Traversal
- [x] Preorder Traversal
- [x] Postorder Traversal
- [x] Level-order Traversal
- [x] Search
- [x] Find_Min
- [x] Find_Max
- [x] Size
- [x] Height
- [x] Clear
- [x] Serialize
- [x] Range_Query
- [x] Successor
- [x] Predecessor
- [x] Update
- [x] Copy
- [x] Kth_Largest
- [x] Kth_Smallest
- [x] Is_Valid

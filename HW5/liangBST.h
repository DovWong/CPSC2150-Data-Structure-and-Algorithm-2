#ifndef BST_H
#define BST_H

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <fstream>
using namespace std;

class TreeNode
{
public:
    int element; // Element contained in the node
    TreeNode* left; // Pointer to the left child
    TreeNode* right; // Pointer to the right child

    TreeNode() // default constructor
    {
        element = 0;
        left = nullptr;
        right = nullptr;
    }

    TreeNode(const int& e) // defined constructor
    {
        this->element = e;
        left = nullptr;
        right = nullptr;
    }
};

class BST
{
public:

    int DIGIT_LENGTH;
    int BETWEEN_SPACE;

    BST() // default constructor
    {
        root = nullptr;
        size = 0;
        DIGIT_LENGTH = 3;
        BETWEEN_SPACE = 5;
    }

    BST(int *elements, int arraySize, bool balanced) // defined constructor
    {
        root = nullptr;
        size = 0;
        DIGIT_LENGTH = 3;
        BETWEEN_SPACE = 5;

        if (balanced) {
            int* arr = new int[arraySize];

            for (int i = 0; i < arraySize; i++)
                arr[i] = elements[i];

            sort(arr, arr + arraySize);

            BinaryInsert(arr, 0, arraySize - 1);

            delete []arr;
            arr = nullptr;
        } else {
            for (int i = 0; i < arraySize; i++)
                insert(elements[i]);
        }
    }

    /* Copy constructor */
    BST(const BST& tree)
    {
        root = nullptr;
        size = 0;
        DIGIT_LENGTH = 3;
        BETWEEN_SPACE = 5;
        copy(tree.root); // Recursively copy nodes to this tree
    }

    void BinaryInsert(int* arr, int left, int right) {
        if (left > right)
            return;

        int mid = (left + right) / 2;

        insert(arr[mid]);
        BinaryInsert(arr, left, mid - 1);
        BinaryInsert(arr, mid + 1, right);
    }

/////EXERCISE
    /* Copies the element from the specified tree to this tree */
    void copy(const TreeNode* root)
    {
        if(!root)
            return;

        insert(root->element);
        copy(root->left);
        copy(root->right);
    }

    /* Destructor */
    ~BST()
    {
        clear();
    }

    void SaveTree(TreeNode* someNode, ofstream& myFile) {

        if (!someNode) return;

        myFile << someNode->element << "\n";
        SaveTree(someNode->left, myFile);
        SaveTree(someNode->right, myFile);

    }

    void SaveTree(string fileName) {

        ofstream myFile;
        myFile.open(fileName);

        if (root)
            SaveTree(root, myFile);

        myFile.close();
    }

    void LoadTree(string fileName) {

        ifstream myFile(fileName);
        string line;

        while (getline(myFile, line))
            insert(stoi(line));

    }

/////EXERCISE
    /* Return the address of the node if the element is in the tree; returns nullptr otherwise */
    TreeNode* search(const int& e) const
    {
        TreeNode* current = root;

        while (current != nullptr) {
            if (e < current->element)
                current = current->left;
            else if (e > current->element)
                current = current->right;
            else
                return current;
        }

        return nullptr;
    }

    TreeNode* createNewNode(const int& e)
    {
        return new TreeNode(e);
    }

    // Insert element e into the binary tree
    // Return true if the element is inserted successfully
    // Return false if the element is already in the list
    bool insert(const int& e)
    {
        if (root == nullptr)
            root = createNewNode(e); // Create a new root
        else
        {
            // Locate the parent node
            TreeNode* parent = nullptr;
            TreeNode* current = root;
            while (current != nullptr)
                if (e < current->element)
                {
                    parent = current;
                    current = current->left;
                }
                else if (e > current->element)
                {
                    parent = current;
                    current = current->right;
                }
                else
                    return false; // Duplicate node not inserted

            // Create the new node and attach it to the parent node
            if (e < parent->element)
                parent->left = createNewNode(e);
            else
                parent->right = createNewNode(e);
        }

        size++;
        return true; // Element inserted
    }

    /* Inorder traversal */
    void inorder() const
    {
        inorder(root);
        cout << endl;
    }

    /* Inorder traversal from a subtree */
    void inorder(const TreeNode* someNode) const
    {
        if (someNode == nullptr) return;

        inorder(someNode->left); // process all nodes in left sub-tree of someNode
        cout << someNode->element << " "; // process someNode
        inorder(someNode->right); // process all nodes in right sub-tree of someNode
    }

    /* Postorder traversal */
    void postorder() const
    {
        postorder(root);
        cout << endl;
    }

/////EXERCISE
    /** Inorder traversal from a subtree */
    void postorder(const TreeNode* someNode) const
    {
        if (!someNode) return;

        postorder(someNode->left);
        postorder(someNode->right);
        cout << someNode->element << " ";
    }

    /* Preorder traversal */
    void preorder() const
    {
        preorder(root);
        cout << endl;
    }

/////EXERCISE
    /* Preorder traversal from a subtree */
    void preorder(const TreeNode* someNode) const
    {
        if (!someNode) return;

        cout << someNode->element << " ";
        preorder(someNode->left);
        preorder(someNode->right);
    }

    /* Get the number of nodes in the tree */
    int getSize() const
    {
        return size;
    }

/////EXERCISE
    /* Remove all nodes from the tree */
    void clear(TreeNode* someNode) {
        if (!someNode) return;

        clear(someNode->left);
        clear(someNode->right);

        someNode->left = nullptr;
        someNode->right = nullptr;
        delete someNode;
        someNode = nullptr;
    }

    void clear()
    {
        clear(root);
        root= nullptr;
    }

/////EXERCISE
    /* Return a path from the root leading to the specified element.
    If specified element does not exist in the tree then add a nullptr
    to the end.*/
    vector<TreeNode*>* path(const int& e) const
    {
        vector<TreeNode*>* path = new vector<TreeNode*>;
        TreeNode* current = root;

        while (current) {

            path->push_back(current);

            if (e < current->element)
                current = current->left;
            else if (e > current->element)
                current = current->right;
            else
                return path;
        }

        path->push_back(nullptr);
        return path;
    }

    /* Delete an element e from the binary tree.
     * Return true if the element is deleted successfully
     * Return false if the element is not in the tree */
    bool remove(const int& e)
    {
        // Locate the node to be deleted and also locate its parent node
        TreeNode* parent = nullptr;
        TreeNode* current = root;
        while (current != nullptr)
        {
            if (e < current->element)
            {
                parent = current;
                current = current->left;
            }
            else if (e > current->element)
            {
                parent = current;
                current = current->right;
            }
            else
                break; // Element e is in the tree pointed by current
        }

        if (current == nullptr)
            return false; // Element e is not in the tree

        // Case 1: current has no left children
        if (current->left == nullptr)
        {
            // Connect the parent with the right child of the current node
            if (parent == nullptr)
            {
                root = current->right;
            }
            else
            {
                if (e < parent->element)
                    parent->left = current->right;
                else
                    parent->right = current->right;
            }

            delete current; // Delete current
        }
        else
        {
            // Case 2: The current node has a left child
            // Locate the rightmost node in the left subtree of
            // the current node and also its parent
            TreeNode* parentOfRightMost = current;
            TreeNode* rightMost = current->left;

            while (rightMost->right != nullptr)
            {
                parentOfRightMost = rightMost;
                rightMost = rightMost->right; // Keep going to the right
            }

            // Replace the element in current by the element in rightMost
            current->element = rightMost->element;

            // Eliminate rightmost node
            if (parentOfRightMost->right == rightMost)
                parentOfRightMost->right = rightMost->left;
            else
                // Special case: parentOfRightMost->right == current
                parentOfRightMost->left = rightMost->left;

            delete rightMost; // Delete rightMost
        }

        size--;
        return true; // Element inserted
    }

/////ADDITIONAL EXERCISES/////

    // returns the height of the tree
    int GetHeight() const {
        if(root == nullptr){
            return 0;
        }
        else{
            return GetHeight(root);
        }
    }

/////EXERCISE
    // returns the height of someNode
    int GetHeight(TreeNode* someNode) const {
        if (!someNode) return 0;

        int leftHeight = GetHeight(someNode->left);
        int rightHeight = GetHeight(someNode->right);

        if (leftHeight > rightHeight)
            return leftHeight + 1;

        return rightHeight + 1;
    }

    int GetSize() {
        return size;
    }

    // Increment each node's value by 1
    void IncrementByOne(){
        InorderIncrementByOne(root);
    }

/////EXERCISE
    // Increment each node (that is part of the tree rooted at someNode) by 1
    void InorderIncrementByOne(TreeNode* someTreeNode){
        if (!someTreeNode) return;

        someTreeNode->element++;

        InorderIncrementByOne(someTreeNode->left);
        InorderIncrementByOne(someTreeNode->right);
    }

    // returns the number of nodes in the tree
    int NodeCount(){
        return InOrderNodeCount(root);
    }

/////EXERCISE
    // returns the number of nodes in the tree rooted at someNode
    int InOrderNodeCount(TreeNode* someNode){
        if (!someNode) return 0;

        return InOrderNodeCount(someNode->left) + InOrderNodeCount(someNode->right) + 1;
    }

    // returns the number of nodes in the tree with odd values
    int NodesWithOddValues(){
        return InOrderNodesWithOddValues(root);
    }

/////EXERCISE
    // returns the number of nodes in the tree rooted at someNode with odd values
    int InOrderNodesWithOddValues(TreeNode* someNode){
        if (!someNode) return 0;

        if (someNode->element % 2 == 1)
            return InOrderNodesWithOddValues(someNode->left) + InOrderNodesWithOddValues(someNode->right) + 1;

        return InOrderNodesWithOddValues(someNode->left) + InOrderNodesWithOddValues(someNode->right);
    }

    // level order display
    void LevelOrderDisplay(){
        LevelOrderDisplay(root);
    }

/////EXERCISE
    // level order display of the tree rooted at someNode
    void LevelOrderDisplay(TreeNode* someNode){
        // use a queue, STL queue is fine
        if (!someNode) return;

        queue<TreeNode*>* tree = new queue<TreeNode*>;

        tree->push(someNode);
        int height = GetHeight(someNode);

        LevelOrderDisplay(tree, height);
        delete tree;
        tree = nullptr;
    }

    void LevelOrderDisplay(queue<TreeNode*>* treeQueue, int height) {
        if (height == 0) return;

        int firstSpace = 0;
        int increment = BETWEEN_SPACE;
        for (int i = 1; i < height; i++) {
            firstSpace += increment;
            increment *= 2;
        }

        for (int i = 0; i < firstSpace; i++)
            cout << " ";

        TreeNode* current;
        int size = treeQueue->size();
        int betweenSpace = pow(2, height) * BETWEEN_SPACE;

        for (int i = 0; i < size; i++) {

            current = treeQueue->front();
            PrintTreeNode(current);

            if (current) {
                treeQueue->push(treeQueue->front()->left);
                treeQueue->push(treeQueue->front()->right);
            } else {
                treeQueue->push(nullptr);
                treeQueue->push(nullptr);
            }

            for (int j = 0; j < betweenSpace - DIGIT_LENGTH; j++)
                cout << " ";

            treeQueue->pop();
        }

        cout << endl;
        LevelOrderDisplay(treeQueue, height - 1);
    }

    void PrintTreeNode(TreeNode* someNode){
        int space;

        if (!someNode)
            space = 0;
        else if (someNode->element > 0)
            space = (int)log10(someNode->element) + 1;
        else
            space = (int)log10(someNode->element * -1);

        if (someNode)
            cout << someNode->element;

        while (space < DIGIT_LENGTH) {
            cout << " ";
            space++;
        }
    }

    // display tree like a tree horizontally
    void DisplayTreeHorizontally(){
        DisplayTreeHorizontally(root, 0);
    }

    // display the tree rooted at someNode like a tree, horizontally
    void DisplayTreeHorizontally(TreeNode* someNode, int space){
        if(someNode == nullptr){
            return;
        }
        else{
            space += 10;

            DisplayTreeHorizontally(someNode->right, space);

            cout << endl;
            for(int i = 10; i < space; i++){
                cout << " ";
            }
            cout << someNode->element << endl;

            DisplayTreeHorizontally(someNode->left, space);
        }
    }

    TreeNode* kthSmallest(TreeNode* someNode, int& k) const
    {
        if (!someNode) return nullptr;

        TreeNode* leftNode = kthSmallest(someNode->left, k);

        if (k == 1) {
            k -= 1;
            return someNode;
        }

        k -= 1;

        if (leftNode)
            return leftNode;

        return kthSmallest(someNode->right, k);
    }

    TreeNode* kthSmallest(int k) {
        if (k < 1 || k > size)
            return nullptr;

        return kthSmallest(root, k);
    }

    TreeNode* ClosestCommonAncestor(TreeNode* node1, TreeNode* node2) {

        if(!node1 || !node2 || !root || !search(node1->element) || !search(node2->element))
            return nullptr;

        TreeNode* prev = nullptr;
        TreeNode* current = root;

        while (current) {

            if (node1->element < current->element && node2->element < current->element) {
                prev = current;
                current = current->left;
            }
            else if (node1->element > current->element && node2->element > current->element) {
                prev = current;
                current = current->right;
            }
            else {
                if (node1->element == current->element || node2->element == current->element) // Node itself cannot be its ancestor
                    return prev;
                else
                    return current;
            }
        }

        return nullptr;
    }

    bool operator== (const BST& tree) const {
        if (size != tree.size || GetHeight() != tree.GetHeight() || !root)
            return false;

        return compareNode(root, tree.root);
    }

    bool compareNode (TreeNode* node1, TreeNode* node2) const {

        if (!node1 && !node2)
            return true;

        if ((!node1 && node2) || (node1 && !node2) || node1->element != node2->element)
            return false;

        if (!compareNode(node1->left, node2->left) || !compareNode(node1->right, node2->right))
            return false;

        return true;
    }

    BST& operator= (const BST& tree) {

        if (*this == tree)
            return *this;

        if (this->root)
            delete this;

        this->copy(tree.root);
        return *this;
    }

    void printInformation() {

        if (!root) {
            cout << "There is no elements in this tree\n";
            return;
        }

        cout << "Size: " << size << "; Height:" << GetHeight() << endl << endl;

        LevelOrderDisplay();
    }

    TreeNode* GetRoot() {
        if (root)
            return root;
    }

    void RotateRight(TreeNode* someNode) {

        TreeNode* node = search(someNode->element);

        if (!someNode || !node)
            return;

        if (node->left) {
            TreeNode* temp = node->left;
            node->left = nullptr;
            temp->right = node;

            if (node == root)
                root = temp;
            else {
                TreeNode *parent = ClosestCommonAncestor(node, node);
                parent->left = temp; // assuming it will be new left child
            }
        }
    }



private:
    TreeNode* root;
    int size;
};

#endif

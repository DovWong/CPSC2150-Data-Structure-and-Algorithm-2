#ifndef AVLTREE_H
#define AVLTREE_H

#include <vector>
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

class AVLTreeNode
{
public:
    int element;        // Element contained in the node
    int height;         // height of the node
    AVLTreeNode *left;  // Pointer to the left child
    AVLTreeNode *right; // Pointer to the right child

    AVLTreeNode(int element)
    {
        this->element = element;
        height = 0;
        left = nullptr;
        right = nullptr;
    }
};

class AVLTree
{
public:
    AVLTree()
    {
        root = nullptr;
        size = 0;
        height = 0;
    }

    AVLTree(int elements[], int arraySize)
    {
        root = nullptr;
        size = 0;

        for (int i = 0; i < arraySize; i++)
        {
            insert(elements[i]);
        }
    }

    /* Inorder traversal */
    void inorder() const
    {
        inorder(root);
    }

    /* Inorder traversal from a subtree */
    void inorder(const AVLTreeNode *root) const
    {
        if (root == nullptr)
            return;
        inorder(root->left);
        cout << root->element << " ";
        inorder(root->right);
    }

///////EXERCISE////////
    // return a queue of nodes in level order
    queue<AVLTreeNode *> LevelOrderNodes(AVLTreeNode *someNode)
    {
        queue<AVLTreeNode*> tempQueue;
        queue<AVLTreeNode*> resultQueue;

        if (!someNode)
            return resultQueue;

        AVLTreeNode* cur = root;
        tempQueue.push(cur);
        resultQueue.push(cur);

        while (!tempQueue.empty()) {
            if (cur->left) {
                tempQueue.push(cur->left);
                resultQueue.push(cur->left);
            }

            if (cur->right) {
                tempQueue.push(cur->right);
                resultQueue.push(cur->right);
            }

            tempQueue.pop();
            cur = tempQueue.front();
        }

        return resultQueue;
    }

///////EXERCISE////////
    // display tree with level indices
    void DisplayTreeWithLevelIndices(queue<AVLTreeNode *> q)
    {
        if (!q.front())
            return;

        int count;

        for (int i = 0; !q.empty(); i++) {

            cout << "level " << i << ": ";
            count = CountNodesAtLevel(i);

            while (count > 0) {
                cout << q.front()->element << " ";
                q.pop();
                count--;
            }

            cout << endl;
        }
    }

    // level order display
    void LevelOrderDisplay()
    {
        if (root == nullptr)
        {
            cout << "Tree is empty." << endl;
        }
        else
        {
            queue<AVLTreeNode *> q = LevelOrderNodes(root);
            DisplayTreeWithLevelIndices(q);
        }
    }

    // display tree like a tree, horizontally
    void DisplayTreeHorizontally()
    {
        cout << "==========tree/horizontal view==========\n";
        DisplayTreeHorizontally(root, 0);
    }

    // display the tree rooted at someNode like a tree, horizontally
    void DisplayTreeHorizontally(AVLTreeNode *someNode, int space)
    {
        if (someNode == nullptr)
        {
            return;
        }
        else
        {
            space += 10;

            DisplayTreeHorizontally(someNode->right, space);

            cout << endl;
            for (int i = 10; i < space; i++)
            {
                cout << " ";
            }
            cout << someNode->element << endl;

            DisplayTreeHorizontally(someNode->left, space);
        }
    }

    /* Get the number of nodes in the tree */
    int getSize() const
    {
        return size;
    }

    // Insert element e into the binary tree
    // Return true if the element is inserted successfully
    // Return false if the element is already in the list
    bool binaryTreeInsert(const int &e)
    {
        if (root == nullptr)
            root = createNewNode(e); // Create a new root
        else
        {
            // Locate the parent node
            AVLTreeNode *parent = nullptr;
            AVLTreeNode *current = root;
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

    // Return a path from the root leading to the specified element
    vector<AVLTreeNode *> *path(const int &e) const
    {
        vector<AVLTreeNode *> *v = new vector<AVLTreeNode *>();
        AVLTreeNode *current = root;

        while (current != nullptr)
        {
            v->push_back(current);
            if (e < current->element)
                current = current->left;
            else if (e > current->element)
                current = current->right;
            else
                break;
        }

        return v;
    }

    // insert element into AVLTree
    bool insert(int element)
    {
        bool successful = binaryTreeInsert(element);
        if (!successful)
            return false; // element is already in the tree
        else
            // Balance from element to the root if necessary
            balancePath(element);

        return true; // element is inserted
    }

    // remove element from AVLTree
    bool remove(int element)
    {
        if (root == nullptr)
            return false; // Element is not in the tree

        // Locate the node to be deleted and also locate its parent node
        AVLTreeNode *parent = nullptr;
        AVLTreeNode *current = root;
        while (current != nullptr)
        {
            if (element < current->element)
            {
                parent = current;
                current = current->left;
            }
            else if (element > current->element)
            {
                parent = current;
                current = current->right;
            }
            else
                break; // Element is in the tree pointed by current
        }

        if (current == nullptr)
            return false; // Element is not in the tree

        // Case 0: current is a leaf
        if(current->left == nullptr && current->right == nullptr){
            if (parent == nullptr)
            {
                root = nullptr;
            }
            else
            {
                if (element < parent->element)
                    parent->left = nullptr;
                else
                    parent->right = nullptr;
            }

            delete current; // Delete current
        }
            // Case 1: current has no left children
        else if (current->left == nullptr)
        {
            // Connect the parent with the right child of the current node
            if (parent == nullptr)
                root = current->right;
            else
            {
                if (element < parent->element)
                    parent->left = current->right;
                else
                    parent->right = current->right;

                // Balance the tree if necessary
                balancePath(parent->element);
            }

            delete current; // Delete current
        }
        else
        {
            // Case 2: The current node has a left child
            // Locate the rightmost node in the left subtree of
            // the current node and also its parent
            AVLTreeNode *parentOfRightMost = current;
            AVLTreeNode *rightMost = current->left;

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
                // Special case: parentOfRightMost is current
                parentOfRightMost->left = rightMost->left;

            // Balance the tree if necessary
            balancePath(parentOfRightMost->element);

            delete rightMost; // Delete rightMost
        }

        size--;
        return true; // Element inserted
    }

///////EXERCISE////////
    /* Return the address of the node if the element is in the tree; returns nullptr otherwise */
    AVLTreeNode *search(const int &e) const
    {
        if (!root) return nullptr;

        return search(root, e);
    }

    AVLTreeNode *search(AVLTreeNode* someNode, const int &e) const
    {
        if (!someNode) return nullptr;

        int value = someNode->element;

        if (value == e) return someNode;

        if (value < e) return search(someNode->right, e);

        return search(someNode->left, e);
    }

    // create a new AVLTreeNode
    AVLTreeNode *createNewNode(int element)
    {
        return new AVLTreeNode(element);
    }

///////EXERCISE////////
    /** Balance the nodes in the path from the specified node to the root if necessary */
    void balancePath(int element)
    {
        vector<AVLTreeNode *> *p = path(element);
        for (int i = p->size() - 1; i >= 0; i--)
        {
            AVLTreeNode *A = (*p)[i];
            AVLTreeNode *parentOfA = (A == root) ? nullptr : (*p)[i - 1];

            updateHeight(A); // ensure that height is updated first

            int balanceFactorOfA = balanceFactor(A);
            int balanceFactorOfALeft = balanceFactor(A->left);
            int balanceFactorOfARight = balanceFactor(A->right);

            if (balanceFactorOfA == -2) {
                if (balanceFactorOfALeft == -1 || balanceFactorOfALeft == 0)
                    balanceLL(A, parentOfA);
                else if (balanceFactorOfALeft == 1)
                    balanceLR(A, parentOfA);
            } else if (balanceFactorOfA == 2) {
                if (balanceFactorOfARight == 1 || balanceFactorOfARight == 0)
                    balanceRR(A, parentOfA);
                else if (balanceFactorOfARight == -1)
                    balanceRL(A, parentOfA);
            }
        }
    }

    /** Update the height of a specified node */
    void updateHeight(AVLTreeNode *node)
    {
        if (node->left == nullptr && node->right == nullptr) // node is a leaf
            node->height = 0;
        else if (node->left == nullptr) // node has no left subtree
            node->height = 1 + (*(node->right)).height;
        else if (node->right == nullptr) // node has no right subtree
            node->height = 1 + (*(node->left)).height;
        else
            node->height = 1 + max((*(node->right)).height, (*(node->left)).height);
    }

///////EXERCISE////////
    /** Return the balance factor of the node */
    int balanceFactor(AVLTreeNode *node)
    {
        if (!node)
            return 0;

        if (node->left && node->right)
            return node->right->height - node->left->height;

        if (node->left)
            return -node->left->height;

        if (node->right)
            return node->right->height;

        return 0;
    }

    /** Balance LL */
    void balanceLL(AVLTreeNode *A, AVLTreeNode *parentOfA)
    {
        AVLTreeNode *B = A->left; // A is left-heavy and B is left-heavy

        if (A == root)
            root = B;
        else if (parentOfA->left == A)
            parentOfA->left = B;
        else
            parentOfA->right = B;

        A->left = B->right; // Make T2 the left subtree of A
        B->right = A;       // Make A the left child of B
        updateHeight(A);
        updateHeight(B);
    }

    /** Balance LR */
    void balanceLR(AVLTreeNode *A, AVLTreeNode *parentOfA)
    {
        AVLTreeNode *B = A->left;  // A is left-heavy
        AVLTreeNode *C = B->right; // B is right-heavy

        if (A == root)
            root = C;
        else if (parentOfA->left == A)
            parentOfA->left = C;
        else
            parentOfA->right = C;

        A->left = C->right; // Make T3 the left subtree of A
        B->right = C->left; // Make T2 the right subtree of B
        C->left = B;
        C->right = A;

        // Adjust heights
        updateHeight(A);
        updateHeight(B);
        updateHeight(C);
    }

///////EXERCISE////////
    /** Balance RR */
    void balanceRR(AVLTreeNode *A, AVLTreeNode *parentOfA)
    {
         AVLTreeNode *B = A->right;

         if (A == root)
           root = B;
         else if (parentOfA->left == A)
           parentOfA->left = B;
         else
           parentOfA->right = B;

         A->right = B->left;
         B->left = A;
         updateHeight(A);
         updateHeight(B);
    }

///////EXERCISE////////
    /** Balance RL */
    void balanceRL(AVLTreeNode *A, AVLTreeNode *parentOfA)
    {
         AVLTreeNode *B = A->right;
         AVLTreeNode *C = B->left;

         if (A == root)
           root = C;
         else if (parentOfA->left == A)
           parentOfA->left = C;
         else
           parentOfA->right = C;

         A->right = C->left;
         B->left = C->right;
         C->left = A;
         C->right = B;

         // Adjust heights
         updateHeight(A);
         updateHeight(B);
         updateHeight(C);
    }

    // returns the number of nodes at level level in the tree
    int CountNodesAtLevel(int level)
    {
        int count = 0;
        CountNodesAtLevel(root, level, count);
        return count;
    }

///////EXERCISE////////
    // helper function for CountNodesAtLevel
    void CountNodesAtLevel(AVLTreeNode *someNode, int level, int &count)
    {
        if (!someNode)
            return;

        if (level == 0) {
            count++;
            return;
        }

        CountNodesAtLevel(someNode->left, level - 1, count);
        CountNodesAtLevel(someNode->right, level - 1, count);
    }

    // returns the number of nodes in the tree that are between min and max (inclusive)
    int Count(int min, int max)
    {
        int count = 0;
        Count(root, min, max, count);
        return count;
    }

///////EXERCISE////////
    // helper function for Count
    void Count(AVLTreeNode *someNode, int min, int max, int &count)
    {
        if (!someNode)
            return;

        if (someNode->element >= min && someNode->element <= max)
            count++;

        //Don't need to check left nodes if cur value is less than min because values of all small nodes should be smaller
        if (someNode->element > min)
            Count(someNode->left, min, max, count);

        //Don't need to check right nodes if cur value is larger than max because values of all right nodes should be larger
        if (someNode->element < max)
            Count(someNode->right, min, max, count);
    }

///////EXERCISE////////
    // right rotates the tree at node someNode if possible (if someNode is nullptr or someNode->left is nullptr, no rotation is performed)
    void RotateRight(AVLTreeNode *someNode)
    {
        if (!someNode || !someNode->left)
            return;

        AVLTreeNode* oldLeftChild = someNode->left;
        AVLTreeNode* rightChildOfOldLeftChild = oldLeftChild->right; //won't be crashed as confirmed someNode has left child

        oldLeftChild->right = someNode;
        someNode->left = rightChildOfOldLeftChild;

        if (someNode == root) {
            root = oldLeftChild;
        } else {
            AVLTreeNode *parent = FindParent(someNode);

            if (parent->right == someNode)
                parent->right = oldLeftChild;
            else
                parent->left = oldLeftChild;
        }

        updateHeight(someNode);
        updateHeight(oldLeftChild);
    }

///////EXERCISE////////
    // left rotates the tree at node someNode if possible (if someNode is nullptr or someNode->right is nullptr, no rotation is performed)
    void RotateLeft(AVLTreeNode *someNode)
    {
        if (!someNode || !someNode->right)
            return;

        AVLTreeNode* oldRightChild = someNode->right;
        AVLTreeNode* leftChildOfOldRightChild = oldRightChild->left; //won't be crashed as confirmed someNode has left child

        oldRightChild->left = someNode;
        someNode->right = leftChildOfOldRightChild;

        if (someNode == root) {
            root = oldRightChild;
        } else {
            AVLTreeNode *parent = FindParent(someNode);

            if (parent->right == someNode)
                parent->right = oldRightChild;
            else
                parent->left = oldRightChild;
        }

        updateHeight(someNode);
        updateHeight(oldRightChild);
    }

    // returns the diameter of the tree
    // diameter is the number of nodes along the longest path between any two leaves in the tree
    // see https://leetcode.com/problems/diameter-of-binary-tree/
    int Diameter()
    {
        return Diameter(root);
    }

///////EXERCISE////////
    // helper function for Diameter
    int Diameter(AVLTreeNode *someNode)
    {
        if (!someNode || (!someNode->left && !someNode->right))
            return 0;

        if (!someNode->left)
            return someNode->right->height + 1;

        if (!someNode->right)
            return someNode->left->height + 1;

        return someNode->left->height + someNode->right->height + 2;
    }

    AVLTreeNode* FindParent(AVLTreeNode* someNode) {

        if (!someNode || someNode == root)
            return nullptr;

        int value = someNode->element;
        AVLTreeNode* cur = root;
        AVLTreeNode* parent;

        while (cur) {
            if (value < cur->element) {
                parent = cur;
                cur = cur->left;
            } else if (value > cur->element) {
                parent = cur;
                cur = cur->right;
            } else {
                return parent;
            }
        }

        return nullptr;
    }

    void LevelOrderDisplay(AVLTreeNode* someNode){
        // use a queue, STL queue is fine
        if (!someNode) return;

        queue<AVLTreeNode*>* tree = new queue<AVLTreeNode*>;

        tree->push(someNode);

        LevelOrderDisplay(tree, someNode->height + 1);
        delete tree;
        tree = nullptr;
    }

    void LevelOrderDisplay(queue<AVLTreeNode*>* treeQueue, int h) {
        if (h == 0) return;

        int firstSpace = 0;
        int increment = 5;
        for (int i = 1; i < h; i++) {
            firstSpace += increment;
            increment *= 2;
        }

        for (int i = 0; i < firstSpace; i++)
            cout << " ";

        AVLTreeNode* current;
        int size = treeQueue->size();
        int betweenSpace = pow(2, h) * 5;

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

            for (int j = 0; j < betweenSpace - 3; j++)
                cout << " ";

            treeQueue->pop();
        }

        cout << endl;
        LevelOrderDisplay(treeQueue, h - 1);
    }

    void PrintTreeNode(AVLTreeNode* someNode){
        int space;

        if (!someNode)
            space = 0;
        else if (someNode->element > 0)
            space = (int)log10(someNode->element) + 1;
        else
            space = (int)log10(someNode->element * -1);

        if (someNode)
            cout << someNode->element;

        while (space < 3) {
            cout << " ";
            space++;
        }
    }

    AVLTreeNode* GetRoot() const {
        return root;
    }


private:
    AVLTreeNode *root;
    int size;
    int height;
    vector<AVLTreeNode*> backups;
};

#endif

#include <iostream>
#include "liangBST.h"
#include <vector>
#include <iomanip>

using namespace std;

int main() {

//    BST test0;
//    test0.insert(20);
//    test0.insert(30);
//    test0.insert(10);
//    test0.insert(5);
//    test0.insert(3);
//    test0.insert(8);
//
//    test0.LevelOrderDisplay();
//
//    test0.RotateRight(test0.search(5));
//    test0.LevelOrderDisplay();



    int* list = new int[7]{4, 3, 7, 1, 2, 6, 5};
    cout << "\n********************Using array of {4, 3, 7, 1, 2, 6, 5} to build the BST********************\n\n";
    cout << "\n********************Normal constructor for test1********************\n\n";
    BST test1(list, 7, false);
    test1.printInformation();

    cout << "\n********************Binary Insert constructor for test2********************\n\n";
    BST test2(list, 7, true);
    test2.printInformation();

    test2.insert(8);
    cout << "\n********************Test2 after insert(8)********************\n\n";
    test2.printInformation();
    cout << "\n********************Test2 after remove(8)********************\n\n";
    test2.remove(8);
    test2.printInformation();
    cout << "\n********************Test2 after remove(6)********************\n\n";
    test2.remove(6);
    test2.printInformation();
    cout << "\n********************Test2 after remove(9)********************\n\n";
    test2.remove(9);
    test2.printInformation();
    cout << "\n********************Test2 after remove(2)********************\n\n";
    test2.remove(2);
    test2.printInformation();
    cout << "\n********************Test2 after remove(4)********************\n\n";
    test2.remove(4);
    test2.printInformation();

    cout << "\n********************Using copy constructor to copy test2 to test3********************\n\n";
    BST test3(test2);
    test3.printInformation();

    cout << "\n********************Using assignment operator to copy test2 to test4********************\n\n";
    BST test4 = test2;
    test4.printInformation();

    cout << "\n********************Testing operator =********************\n\n";
    cout << boolalpha;
    cout << "\ntest1 = test2: " << (test1 == test2) << "; test2 = test3: " << (test2 == test3);
    cout << "; test3 = test4: " << (test3 == test4) << "; test4 = test1: " << (test4 == test1) << endl;

    cout << "\n********************Removed 3 from test3 and 1 from test4********************\n\n";
    test3.remove(3);
    test4.remove(1);
    cout << "\n********************test3********************\n\n";
    test3.printInformation();
    cout << "\n********************test4********************\n\n";
    test4.printInformation();
    cout << "\n********************Check test2 after some remove from test3 and test4********************\n\n";
    test2.printInformation();


    cout << "\n********************Create a BST and insert 7, 3, 15, 4, 2, 34, 45, 36, 23, 1, 13, 24, 24********************\n\n";
    BST test5;
    test5.insert(7);
    test5.insert(3);
    test5.insert(15);
    test5.insert(4);
    test5.insert(2);
    test5.insert(34);
    test5.insert(45);
    test5.insert(36);
    test5.insert(23);
    test5.insert(1);
    test5.insert(13);
    test5.insert(24);
    test5.insert(24);
    test5.printInformation();

    cout << "\n********************Save and Load from file********************\n\n";
    string fileName = "test.txt";
    test5.SaveTree(fileName);
    BST test6;
    test6.LoadTree(fileName);
    test6.printInformation();

    cout << "\n********************Print it inorder********************\n\n";
    test5.inorder();

    cout << "\n********************Print it preorder********************\n\n";
    test5.preorder();

    cout << "\n********************Print it postorder********************\n\n";
    test5.postorder();

    cout << "\n********************Testing for search, count and count odd node********************\n\n";
    int testList[] = {6, 8, 14, 3, 0, -31, 46, 99};

    for (int i = 0; i < sizeof(testList) / sizeof(int); i++) {
        cout << "Searching " << testList[i] << ": ";

        if (test5.search(testList[i]))
            cout << "On list; ";
        else
            cout << "Not on list; ";

        if ((i + 1) % 5 == 0)
            cout << endl;
    }

    cout << endl;
    cout << "No. of odd value node: " << test5.InOrderNodesWithOddValues(test5.GetRoot()) << endl;
    cout << "No. of node: " << test5.InOrderNodeCount(test5.GetRoot()) << endl;

    cout << "\n********************After increment all node by 1********************\n\n";
    test5.InorderIncrementByOne(test5.GetRoot());
    test5.printInformation();


    cout << "\n********************Testing for search, count and count odd node after increment********************\n\n";

    for (int i = 0; i < sizeof(testList) / sizeof(int); i++) {
        cout << "Searching " << testList[i] << ": ";

        if (test5.search(testList[i]))
            cout << "On list; ";
        else
            cout << "Not on list; ";

        if ((i + 1) % 5 == 0)
            cout << endl;
    }

    cout << endl;
    cout << "No. of odd value node: " << test5.InOrderNodesWithOddValues(test5.GetRoot()) << endl;
    cout << "No. of node: " << test5.InOrderNodeCount(test5.GetRoot()) << endl;

    cout << "\n********************Testing for path to 2, 6, 27 and 37********************\n\n";
    int testList2[] = {2, 6, 27, 37};
    vector<TreeNode*>* path;

    for (int i = 0; i < sizeof(testList2) / sizeof(int); i++) {

        cout << "Path for " << testList2[i] << endl;
        path = test5.path(testList2[i]);

        for (int j = 0; j < path->size(); j++) {
            if ((*path)[j]) {
                cout << (*path)[j]->element;

                if (j != path->size() - 1) {
                    cout << " -> ";
                }
            } else
                cout << "end";
        }

        cout << endl;
    }

    cout << "\n********************Testing for kthSmallest from root********************\n\n";
    int testList3[] = {4, 8, 2, 14, 0};

    for (int i = 0; i < sizeof(testList3) / sizeof(int); i++) {

        cout << "Looking for " << testList3[i] << "th smallest node: ";

        TreeNode* temp = test5.kthSmallest(test5.GetRoot(), testList3[i]);

        if (temp)
            cout << temp->element << endl;
        else
            cout << "Out of index" << endl;
    }

    cout << "\n********************Testing for kthSmallest from right node of root********************\n\n";
    int testList5[] = {4, 8, 2, 14, 0};

    for (int i = 0; i < sizeof(testList5) / sizeof(int); i++) {

        cout << "Looking for " << testList5[i] << "th smallest node: ";

        TreeNode* temp = test5.kthSmallest(test5.GetRoot()->right, testList5[i]);

        if (temp)
            cout << temp->element << endl;
        else
            cout << "Out of index" << endl;
    }

    cout << "\n********************Testing for ClosestCommonAncestor********************\n\n";
    for (int i = 0; i < sizeof(testList) / sizeof(int) - 1; i++) {
        int testList4[] = {2, 5, 4, 1, 2, 25, 37, 23, 45, 24, 46};

        cout << "Checking Closest Common Ancestor of " << testList4[i] << " and " << testList4[i + 1] << ": ";

        TreeNode* tempNode1 = new TreeNode(testList4[i]);
        TreeNode* tempNode2 = new TreeNode(testList4[i + 1]);
        TreeNode* commonAncestorNode = test5.ClosestCommonAncestor(tempNode1, tempNode2);

        if (commonAncestorNode)
            cout << commonAncestorNode->element << endl;
        else
            cout << "No common Ancestor" << endl;

        delete tempNode1;
        tempNode1 = nullptr;
        delete tempNode2;
        tempNode2 = nullptr;
    }


    delete []list;
    list = nullptr;

    return 0;
}
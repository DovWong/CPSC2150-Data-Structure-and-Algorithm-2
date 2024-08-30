#include <iostream>
#include "liangAVLTree.h"
using namespace std;

int main()
{


//    int numbers[] = {25, 20, 5};
//    AVLTree tree(numbers, 3);
//
//     cout << "After inserting 25, 20, 5:" << endl;
//     tree.LevelOrderDisplay();
//
//    tree.insert(22);
//    tree.insert(2);
//    tree.insert(1);
//    tree.insert(30);
//    tree.LevelOrderDisplay(tree.GetRoot());
//    cout << endl;
//    cout << endl;
//
//    queue<AVLTreeNode*> list = tree.LevelOrderNodes(tree.search(25));
//
//    while (list.front()) {
//        cout << list.front()->element << " ";
//        list.pop();
//    }
//
//    cout << endl;
//
//    cout << endl;
//    tree.LevelOrderDisplay();
//    cout << endl;
//    cout << "\nMin: 0 & max: 31: " << tree.Count(0 , 31) << endl;
//    cout << "Min: 1 & max: 30: " << tree.Count(1 , 30) << endl;
//    cout << "Min: 6 & max: 43: " << tree.Count(6 , 43) << endl;
//    cout << "Min: 21 & max: 22: " << tree.Count(21 , 22) << endl;
//    cout << "Min: 2 & max: 24: " << tree.Count(2 , 24) << endl;
//
//    cout << "\nParent of 1: " << tree.FindParent(tree.search(1))->element << endl;
//    cout << "Parent of 2: " << tree.FindParent(tree.search(2))->element << endl;
//    cout << "Parent of 5: " << tree.FindParent(tree.search(5))->element << endl;
//    cout << "Parent of 25: " << tree.FindParent(tree.search(25))->element << endl;
//    cout << "Parent of 22: " << tree.FindParent(tree.search(22))->element << endl;
//    cout << "Parent of 30: " << tree.FindParent(tree.search(30))->element << endl;
//    cout << "Parent of 20: ";
//    if( !tree.FindParent(tree.search(20))) cout << "none";
//    cout << endl;
//    cout << "Parent of 31: ";
//    if( !tree.FindParent(tree.search(31))) cout << "none";
//    cout << endl;
//
//    tree.RotateRight(tree.search(25));
//    tree.LevelOrderDisplay(tree.GetRoot());
//    cout << endl << endl;
//
//    tree.RotateRight(tree.search(20));
//    tree.LevelOrderDisplay(tree.GetRoot());
//    cout << endl << endl;
//
//    tree.RotateLeft(tree.search(5));
//    tree.LevelOrderDisplay(tree.GetRoot());
//    cout << endl << endl;
//
//    tree.RotateLeft(tree.search(22));
//    tree.LevelOrderDisplay(tree.GetRoot());
//    cout << endl << endl;
//
//    //cout << tree.search(30) <<endl << tree.search(34) << endl << tree.search(33) << endl;
//    // cout << tree.balanceFactor(tree.search(20)) << endl;
//    // cout << tree.balanceFactor(tree.search(25)) << endl;
//
//
//
//    int numbers2[] = {20, 25, 5};
//    AVLTree tree2(numbers2, 3);
//
//    tree2.insert(3);
//    tree2.insert(7);
//    tree2.LevelOrderDisplay(tree2.search(20));
//
//    tree2.insert(2);
//    tree2.LevelOrderDisplay(tree2.search(5));
//    cout << endl << endl;

    AVLTree tree3;
    tree3.insert(6);
    tree3.insert(2);
    tree3.LevelOrderDisplay(tree3.GetRoot());
    cout << "diameter: " << tree3.Diameter() << endl;

    tree3.insert(1);
    tree3.insert(3);
    tree3.LevelOrderDisplay(tree3.GetRoot());
    cout << "diameter: " << tree3.Diameter() << endl;

    tree3.insert(8);
    tree3.LevelOrderDisplay(tree3.GetRoot());
    cout << "diameter: " << tree3.Diameter() << endl;

    tree3.insert(7);
    tree3.LevelOrderDisplay(tree3.GetRoot());
    cout << "diameter: " << tree3.Diameter() << endl;

    tree3.insert(9);
    tree3.LevelOrderDisplay(tree3.GetRoot());
    cout << "diameter: " << tree3.Diameter() << endl;

    tree3.insert(10);
    tree3.LevelOrderDisplay(tree3.GetRoot());
    cout << "diameter: " << tree3.Diameter() << endl;

    return 0;
}

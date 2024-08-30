#include <iostream>
#include "Graph.h"
using namespace std;

int main(){
    // bool mat1[2][2] = { {0,1},
    //                     {1,0}
    //                     };

//    bool mat1[4][4] = { {0,1,0,1},
//                        {1,0,1,0},
//                        {0,1,0,1},
//                        {1,0,1,0}
//                        };
//
//    int sizeOfRow = 4;
//    int sizeOfCol = 4;
//
//    Graph graph1(mat1, 4);
//
//    graph1.ShowVertices();
//    graph1.ShowAdjacencyList();
//    graph1.ShowEdgeList();
//
//    cout << "Vertices count: " << graph1.VertexCount() << endl;
//
//    for (int i = 0; i < sizeOfRow; i++)
//        graph1.ShowNeighbors(i);
//
//    graph1.ShowDegrees();
//
//    cout << endl;
//
//    for (int i = 0; i < sizeOfRow; i++) {
//        for (int j = 0; j < sizeOfCol; j++) {
//            cout << "Testing HasEdge of " << i << " and " << j << ": " << graph1.HasEdge(i, j) << endl;
//        }
//    }
//
//    cout << "Testing IsDirected: " << graph1.IsDirected() << endl;
//




//
//    bool mat2[8][8];
//
//    bool mat2[8][8] = {{0, 1, 1, 1, 0, 0, 0, 1},
//                       {0, 0, 1, 0, 0, 1, 0, 0},
//                       {0, 0, 0, 0, 0, 1, 0, 0},
//                       {1, 0, 0, 0, 1, 1, 1, 0},
//                       {1, 1, 1, 0, 0, 1, 0, 0},
//                       {1, 1, 0, 1, 0, 0, 1, 0},
//                       {1, 0, 0, 1, 0, 0, 0, 1},
//                       {1, 0, 1, 1, 0, 1, 1, 0}};
//
//    srand(time(0));
//
//    int sizeOfRow2 = 8;
//    int sizeOfCol2 = 8;
//
//    for (int i = 0; i < sizeOfRow2; i++) {
//        for (int j = 0; j < sizeOfCol2; j++) {
//            if (i == j) {
//                mat2[i][j] = 0;
//                continue;
//            }
//            mat2[i][j] = (rand() % 2 == 0);
//        }
//    }
//
//    for (int i = 0; i < sizeOfRow2; i++) {
//        for (int j = 0; j < sizeOfCol2; j++) {
//            cout << mat2[i][j] << ", ";
//        }
//
//        cout << endl;
//    }
//
//    Graph graph2(mat2, 8);
//
//    graph2.ShowVertices();
//    graph2.ShowAdjacencyList();
//    graph2.ShowEdgeList();

//    cout << "Vertices count: " << graph2.VertexCount() << endl;
//
//    for (int i = 0; i < sizeOfRow2; i++)
//        graph2.ShowNeighbors(i);
//
//    graph2.ShowDegrees();
//
//    cout << endl;
//
//    for (int i = 0; i < sizeOfRow2; i++) {
//        for (int j = 0; j < sizeOfCol2; j++) {
//            cout << "Testing HasEdge of " << i << " and " << j << ": " << graph2.HasEdge(i, j) << endl;
//        }
//    }
//
//    cout << "Testing IsDirected: " << graph2.IsDirected() << endl;
//
//    cout << "Path: " << graph2.Path(0, 4) << endl << endl;
//
//    graph2.ShowCycles();

//    bool mat5[4][4] = {{0, 1, 0, 0},
//                       {0, 0, 0, 0},
//                       {0, 0, 0, 1},
//                       {1, 0, 0, 0}};
//
//    Graph graph5(mat5, 4);
//    cout << "Graph5 has cycle: " << graph5.HasCycle() << endl;





//    cout << "\n\n\n**********************************************************************************\n\n";
//
//    bool mat4[8][8];
//
//
//    int sizeOfRow4 = 8;
//    int sizeOfCol4 = 8;
//
//    bool zero2 = true;
//
//    for (int i = 0; i < sizeOfRow4; i++) { // making a directed graph
//        for (int j = 0; j < sizeOfCol4; j++) {
//            if (zero2) {
//                mat4[i][j] = 0;
//                zero2 = false;
//            } else {
//                mat4[i][j] = 1;
//                zero2 = true;
//            }
//        }
//
//        if (zero2)
//            zero2 = false;
//        else
//            zero2 = true;
//    }
//
//    for (int i = 0; i < sizeOfRow4; i++) {
//        for (int j = 0; j < sizeOfCol4; j++) {
//            cout << mat4[i][j] << ", ";
//        }
//
//        cout << endl;
//    }
//
//    Graph graph4(mat4, 8);
//
//    graph4.ShowVertices();
//    graph4.ShowAdjacencyList();
//
//
//    cout << "Graph3 is directed: " << graph4.IsDirected() << endl << endl;
//
//    graph4.ShowCycles();





//    cout << "\n\n\n**********************************************************************************\n\n";
//
//    bool mat4[4][4];
//
//
//    int sizeOfRow4 = 4;
//    int sizeOfCol4 = 4;
//
//    bool zero2 = true;
//
//    for (int i = 0; i < sizeOfRow4; i++) { // making a directed graph
//        for (int j = 0; j < sizeOfCol4; j++) {
//            if (zero2) {
//                mat4[i][j] = 0;
//                zero2 = false;
//            } else {
//                mat4[i][j] = 1;
//                zero2 = true;
//            }
//        }
//
//        if (zero2)
//            zero2 = false;
//        else
//            zero2 = true;
//    }
//
//    for (int i = 0; i < sizeOfRow4; i++) {
//        for (int j = 0; j < sizeOfCol4; j++) {
//            cout << mat4[i][j] << ", ";
//        }
//
//        cout << endl;
//    }
//
//    Graph graph4(mat4, 4);
//
//    graph4.ShowVertices();
//    graph4.ShowAdjacencyList();
//
//
//    cout << "Graph4 is directed: " << graph4.IsDirected() << endl << endl;
//
//    graph4.ShowCycles();

    srand(time(0));
    int TEST_TIME = 10;
    bool isDirected;
    bool testMat[4][4];
    int testSizeOfRow = 4, testSizeOfCol = 4;

    for (int n = 0; n < TEST_TIME; n++) {

        isDirected = (rand() % 2 == 0);

        cout << "\n\n***************************************************";

        if (isDirected)
            cout << "Testing a Directed Graph";
        else
            cout << "Testing a Undirected Graph";

        cout << "***************************************************\n\n";

        //Creating a random adjacency matrix
        if (isDirected) {

            for (int i = 0; i < testSizeOfRow; i++) {
                for (int j = 0; j < testSizeOfRow; j++) {
                    if (i == j) {
                        testMat[i][j] = 0;
                    } else {
                        bool tmp = (rand() % 2 == 0);
                        testMat[i][j] = tmp;
                    }
                }
            }

        } else {

            for (int i = 0; i < testSizeOfRow; i++) {
                for (int j = i; j < testSizeOfRow; j++) {
                    if (i == j) {
                        testMat[i][j] = 0;
                    } else {
                        bool tmp = (rand() % 2 == 0);
                        testMat[i][j] = tmp;
                        testMat[j][i] = tmp;
                    }
                }
            }

        }

        Graph testGraph(testMat, testSizeOfRow);

        //Display the matrix
        cout << "\nAdjacency Matrix:\n";
        for (int i = 0; i < testSizeOfRow; i++) {
            for (int j = 0; j < testSizeOfCol; j++) {
                cout << testMat[i][j] << ", ";
            }

            cout << endl;
        }


        testGraph.ShowVertices();
        testGraph.ShowAdjacencyList();
        testGraph.ShowDegrees();
        testGraph.ShowEdgeList();

        if (testGraph.IsDirected())
            cout << "The graph is directed\n";
        else
            cout << "The graph is not directed\n";


        //Test of ShowNeighbor
        for (int i = 0; i < testSizeOfRow; i++)
            testGraph.ShowNeighbors(i);

        //Test of HasEdge
        for (int i = 0; i < testSizeOfRow; i++) {
            for (int j = 0; j < testSizeOfCol; j++) {
                if (i != j) {
                    cout << "Vertex " << i << " and vertex " << j;

                    if (testGraph.HasEdge(i, j))
                        cout << " has edge between them.\n";
                    else
                        cout << " has not edge between them.\n";
                }
            }
        }

        //Test of Path
        for (int i = 0; i < testSizeOfRow; i++) {
            for (int j = 0; j < testSizeOfCol; j++) {
                if (i != j)
                    cout << "The length of the path from vertex " << i << " to vertex " << j << " is " << testGraph.Path(i, j) << endl;
            }
        }


        if (testGraph.HasCycle()) {
            cout << "The graph has cycle, here are the cycles:\n";
            testGraph.ShowCycles();
        } else {
            cout << "The graph has not cycle.\n";
        }

    }

    return 0;
}

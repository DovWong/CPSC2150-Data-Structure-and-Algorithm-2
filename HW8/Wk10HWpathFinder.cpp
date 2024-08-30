#include <iostream>
#include "Graph.h"

using namespace std;

int main(){

    srand(time(0));

    int totalTestTime = 20, testPathTime = 10;
    bool isSquare;
    int row, col;
    const int MAX_ROW = 15, MAX_COL = 15, MIN_ROW = 2, MIN_COL = 2;
    const string ERROR_MESSAGE = "\n********************************************************************************************************************************"
                                 "YOU ARE WRONG!!!!!!********************************************************************************************************************************\n";

    for (int i = 0; i < totalTestTime; i++) {

        cout << "\n*************************************************";
        cout << i + 1 << "th Testing*************************************************\n";

//        **********For error check**********
//        row = 2;
//        col = 2;
//        unsigned int** maze = new unsigned int*[2];
//
//        for (int j = 0; j < row; j++) {
//            maze[j] = new unsigned int[col];
//            for (int k = 0; k < col; k++) {
//                maze[j][k] = 1;
//            }
//        }
//
//        maze[1][0] = 0;

        isSquare = (rand() % 2 == 0); // flip coin to decide is it a square maze
        row = (rand() % (MAX_ROW - MIN_ROW + 1) + MIN_ROW);

        if (isSquare)
            col = row;
        else
            col = (rand() % (MAX_COL - MIN_COL + 1) + MIN_COL);

        unsigned int** maze = new unsigned int*[row];

        // initialize the maze
        for (int j = 0; j < row; j++) {
            maze[j] = new unsigned int[col];
            for (int k = 0; k < col; k++) {
                maze[j][k] = (rand() % 4);
            }
        }

        cout << "\n********************************Maze********************************\n";
        // display the maze
        for (int j = 0; j < row; j++) {
            for (int k = 0; k < col; k++) {
                cout << maze[j][k] << " ";
            }
            cout << endl;
        }

        Graph testGraph(maze, row, col);

        cout << "\n********************************Information********************************\n";

        testGraph.ShowVertices();
        cout << endl;

        testGraph.ShowAdjacencyList();
        cout << endl;

        testGraph.ShowEdgeList();
        cout << endl;

        cout << "Vertex Count: " << testGraph.VertexCount() << endl;
        cout << "Row Count: " << testGraph.GetRow() << endl;
        cout << "Col Count: " << testGraph.GetCol() << endl;

        // display the maze again by using "1" and "0"
        cout << "\n\n      ";

        for (int j = 0; j < col; j++) {
            cout << j;

            if (j < 10)
                cout << "  ";
            else
                cout << " ";
        }

        cout << endl << endl;

        for (int j = 0; j < row; j++) {

            cout << j;

            if (j < 10)
                cout << "     ";
            else
                cout << "    ";

            for (int k = 0; k < col; k++) {
                if (maze[j][k] == 0)
                    cout << 0;
                else
                    cout << 1;

                cout << "  ";
            }

            cout << endl;
        }

        cout << "\n********************************Test the path********************************\n";

        // Test from top left to bottom right
        // Test by DFS
        cout << "There is ";
        if (!testGraph.FindPath(true))
            cout << "no ";
        else
            cout << "at least a ";

        cout << "path by DFS from start point(0, 0) to ";
        cout << "end point(" << row - 1 << ", " << col - 1 << ").\n";

        // Test by BFS
        cout << "There is ";
        if (!testGraph.FindPath(false))
            cout << "no ";
        else
            cout << "at least a ";

        cout << "path by BFS from start point(0, 0) to ";
        cout << "end point(" << col - 1 << ", " << row - 1 << ").\n";

        int startRow, startCol, endRow, endCol;

        for (int j = 0; j < testPathTime; j++) {
            startRow = rand() % row;
            startCol = rand() % col;
            endRow = rand() % row;
            endCol = rand() % col;
            bool DFSPath = testGraph.FindPath(startRow, startCol, endRow, endCol, true);
            bool BFSPath = testGraph.FindPath(startRow, startCol, endRow, endCol, false);

            // For simple error checking
            if (DFSPath != BFSPath) cerr << ERROR_MESSAGE;
            if (maze[startRow][startCol] == 0 || maze[endRow][endCol] == 0) {
                if (DFSPath || BFSPath) cerr << ERROR_MESSAGE;
            }

            // Test by DFS
            cout << "There is ";
            if (!DFSPath)
                cout << "no ";
            else
                cout << "at least a ";

            cout << "path by DFS from start point(" << startRow << ", " << startCol << ") to ";
            cout << "end point(" << endRow << ", " << endCol << ").\n";

            // Test by BFS
            cout << "There is ";
            if (!BFSPath)
                cout << "no ";
            else
                cout << "at least a ";

            cout << "path by BFS from start point(" << startRow << ", " << startCol << ") to ";
            cout << "end point(" << endRow << ", " << endCol << ").\n";
        }



        // Delete the array

        for (int j = 0; j < row; j++) {
            delete[] maze[j];
            maze[j] = nullptr;
        }

        delete []maze;
        maze = nullptr;
    }


    return 0;
}
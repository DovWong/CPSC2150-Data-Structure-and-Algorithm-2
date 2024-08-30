#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Vertex {
public:

    int row;
    int col;

    Vertex() {
        row = -1; // invalid row
        col = -1; // invalid col
    }

    Vertex(int x, int y){
        row = x;
        col = y;
    }
};


class Edge{
public:

    Vertex u;
    Vertex v;

    Edge() {
        u = Vertex(-1, - 1); // invalid vertex
        v = Vertex(-1, -1); // invalid vertex
    }

    Edge(Vertex _u, Vertex _v){
        u = _u;
        v = _v;
    }
};

class Graph{
private:
    vector<Vertex> vertices;
    vector<vector<Vertex>> adjacencyList;
    vector<Edge> edgeList;

public:
    Graph(){
    }

    Graph(unsigned int** maze, int noRow, int noCol){

        BuildVertices(noRow, noCol);
        BuildAdjacencyList(maze, noRow, noCol);
        BuildEdgeList(maze, noRow, noCol);
    }

    void BuildVertices(int noRow, int noCol) {

        Vertex cur;

        for (int i = 0; i < noRow; i++) {
            for (int j = 0; j < noCol; j++) {
                cur = Vertex(i, j);
                vertices.push_back(cur);
            }
        }
    }

    void BuildAdjacencyList(unsigned int** maze, int noRol, int noCol) {
        for (int a = 0; a < noRol * noCol; a++) {

            Vertex tmp;
            vector<Vertex> list;
            adjacencyList.push_back(list);

            int i = a / noCol; // row;
            int j = a % noCol; // col

            if (maze[i][j] == 0)
                continue;

            if (i - 1 >= 0 && maze[i - 1][j] != 0) {
                tmp = Vertex(i - 1, j);
                adjacencyList[a].push_back(tmp);
            }

            if (i + 1 < noRol && maze[i + 1][j] != 0) {
                tmp = Vertex(i + 1, j);
                adjacencyList[a].push_back(tmp);
            }

            if (j - 1 >= 0 && maze[i][j - 1] != 0) {
                tmp = Vertex(i, j - 1);
                adjacencyList[a].push_back(tmp);
            }

            if (j + 1 < noCol && maze[i][j + 1] != 0) {
                tmp = Vertex(i, j + 1);
                adjacencyList[a].push_back(tmp);
            }
        }
    }

    void BuildEdgeList(unsigned int** maze, int noRow, int noCol) {

        Vertex cur;
        Vertex next;
        Edge tmp;

        for (int i = 0; i < noRow; i++) {
            
            for (int j = 0; j < noCol; j++) {
                if (maze[i][j] == 0)
                    continue;

                cur = Vertex(i ,j);

                if (i - 1 >= 0 && maze[i - 1][j] != 0) {
                    next = Vertex(i - 1, j);
                    tmp = Edge(cur, next);
                    edgeList.push_back(tmp);
                }

                if (i + 1 < noRow && maze[i + 1][j] != 0) {
                    next = Vertex(i + 1, j);
                    tmp = Edge(cur, next);
                    edgeList.push_back(tmp);
                }

                if (j - 1 >= 0 && maze[i][j - 1] != 0) {
                    next = Vertex(i, j - 1);
                    tmp = Edge(cur, next);
                    edgeList.push_back(tmp);
                }

                if (j + 1 < noCol && maze[i][j + 1] != 0) {
                    next = Vertex(i, j + 1);
                    tmp = Edge(cur, next);
                    edgeList.push_back(tmp);
                }
            }  
        }
    }

    void ShowVertices() const{
        // display all vertices
    cout << "Vertices:\n";

        for (int i = 0; i < vertices.size(); i++) {
            cout << "(" << vertices[i].row << ", " << vertices[i].col << ")";


            if (i != vertices.size() - 1)
                cout << ", ";

            if ((i + 1) % 10 == 0)
                cout << endl;
        }

        cout << endl;
    }

    void ShowAdjacencyList() const{
        // display adjacency list
        cout << "Adjacency list:\n";

        for (int i = 0; i < vertices.size(); i++) {

            cout << "Vertex " << "(" << vertices[i].row << ", " << vertices[i].col << "): ";

            for (int j = 0; j < adjacencyList[i].size(); j++) {

                cout << "(" << adjacencyList[i][j].row << ", " << adjacencyList[i][j].col << ")";

                if (j != adjacencyList[i].size() - 1)
                    cout << ", ";
            }

            cout << endl;
        }
    }

    void ShowEdgeList(){
        
        cout << "Edge list:\n";

        for (int i = 0; i < edgeList.size(); i++) {
            cout << "(" << edgeList[i].u.row << ", " << edgeList[i].u.col << "), ";
            cout << "(" << edgeList[i].v.row << ", " << edgeList[i].v.col << ")";

            if (i != edgeList.size() - 1)
                cout << "; ";

            if ((i + 1) % 10 == 0)
                cout << endl;
        }
    }

    int VertexCount(){
        // returns the number of vertices in the graph
        return vertices.size();
    }

    int EdgeCount(){
        // returns the number of edges in the graph
        return edgeList.size();
    }

    int GetRow() {
        // returns no. of row of the maze
        return vertices[VertexCount() - 1].row + 1;
    }

    int GetCol() {
        // returns no. of column of the maze
        return vertices[VertexCount() - 1].col + 1;
    }

    bool IsValidRowNum(int num) {
        return num >= 0 && num < GetRow();
    }

    bool IsValidColNum(int num) {
        return num >= 0 && num < GetCol();
    }

    bool FindPath(bool isDFS = true) {
        vector<bool> isVisited(VertexCount(), false);

        if (adjacencyList[0].size() == 0 || adjacencyList[GetRow() * GetCol() - 1].size() == 0) // check the entrance and exit
            return false;

        if (isDFS)
            return DFS(0, 0, GetRow() - 1, GetCol() - 1, isVisited);

        return BFS(0, 0, GetRow() - 1, GetCol() - 1, isVisited);
    }

    bool FindPath(int startRow, int startCol, int endRow, int endCol, bool isDFS = true) {
        if (!IsValidRowNum(startRow) || !IsValidRowNum(endRow) || !IsValidColNum(startCol) || !IsValidColNum(endCol))
            return false;

        if (adjacencyList[startRow * GetCol() + startCol].size() == 0 || adjacencyList[endRow * GetCol() + endCol].size() == 0) // check the entrance and exit
            return false;

        if (startRow == endRow && startCol == endCol) return true;

        vector<bool> isVisited(VertexCount(), false);

        if (isDFS)
            return DFS(startRow, startCol, endRow, endCol, isVisited);

        return BFS(startRow, startCol, endRow, endCol, isVisited);
    }

    bool DFS(int curRow, int curCol, int endRow, int endCol, vector<bool>& isVisited) {
        if (curRow == endRow && curCol == endCol)
            return true;

        int curIndex = curRow * GetCol() + curCol;

        //cout << "curRow: " << curRow << ", curCol: " << curCol << ", curIndex: " << curIndex << endl; // for debug

        if (isVisited[curIndex])
            return false;

        isVisited[curIndex] = true;

        for (int i = 0; i < adjacencyList[curIndex].size(); i++) {
            if (DFS(adjacencyList[curIndex][i].row, adjacencyList[curIndex][i].col, endRow, endCol, isVisited))
                return true;
        }

        return false;
    }

    bool BFS(int curRow, int curCol, int endRow, int endCol, vector<bool>& isVisited) {

        queue<int> curNode;
        int curIndex = curRow * GetCol() + curCol, nextIndex, endIndex = endRow * GetCol() + endCol;
        curNode.push(curIndex);
        isVisited[curIndex] = true;

        while (!curNode.empty()) {

            for (int i = 0; i < adjacencyList[curIndex].size(); i++) {

                nextIndex = adjacencyList[curIndex][i].row * GetCol() + adjacencyList[curIndex][i].col;

                if (nextIndex == endIndex) return true;

                if (!isVisited[nextIndex]) {
                    curNode.push(nextIndex);
                    isVisited[nextIndex] = true;
                }
            }

            curNode.pop();
            curIndex = curNode.front();
        }

        return false;
    }

    //TODO showPath? testCase? differnt szie
};



#endif
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

    Graph(unsigned int maze[4][4], int n){

        BuildVertices(n);
        BuildAdjacencyList(maze, n);
        BuildEdgeList(maze, n);
    }

    void BuildVertices(int n) {

        Vertex cur;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cur = Vertex(i, j);
                vertices.push_back(cur);
            }
        }
    }

    void BuildAdjacencyList(unsigned int maze[4][4], int n) {
        for (int a = 0; a < n * n; a++) {

            Vertex tmp;
            vector<Vertex> list;
            adjacencyList.push_back(list);

            int i = a / n; // row;
            int j = a % n; // col

            if (maze[i][j] == 0)
                continue;

            if (i - 1 > 0 && maze[i - 1][j] != 0) {
                tmp = Vertex(i - 1, j);
                adjacencyList[a].push_back(tmp);
            }

            if (i + 1 < n && maze[i + 1][j] != 0) {
                tmp = Vertex(i + 1, j);
                adjacencyList[a].push_back(tmp);
            }

            if (j - 1 > 0 && maze[i][j - 1] != 0) {
                tmp = Vertex(i, j - 1);
                adjacencyList[a].push_back(tmp);
            }

            if (j + 1 < n && maze[i][j + 1] != 0) {
                tmp = Vertex(i, j + 1);
                adjacencyList[a].push_back(tmp);
            }
        }
    }

    void BuildEdgeList(unsigned int maze[4][4], int n) {

        Vertex cur;
        Vertex next;
        Edge tmp;

        for (int i = 0; i < n; i++) {
            
            for (int j = 0; j < n; j++) {
                if (maze[i][j] == 0)
                    continue;

                cur = Vertex(i ,j);

                if (i - 1 > 0 && maze[i - 1][j] != 0) {
                    next = Vertex(i - 1, j);
                    tmp = Edge(cur, next);
                    edgeList.push_back(tmp);
                }

                if (i + 1 < n && maze[i + 1][j] != 0) {
                    next = Vertex(i + 1, j);
                    tmp = Edge(cur, next);
                    edgeList.push_back(tmp);
                }

                if (j - 1 > 0 && maze[i][j - 1] != 0) {
                    next = Vertex(i, j - 1);
                    tmp = Edge(cur, next);
                    edgeList.push_back(tmp);
                }

                if (j + 1 < n && maze[i][j + 1] != 0) {
                    next = Vertex(i, j + 1);
                    tmp = Edge(cur, next);
                    edgeList.push_back(tmp);
                }
            }  
        }
    }

    void ShowVertices() const{
        // display all vertices
    cout << "Vertices: ";

        for (int i = 0; i < vertices.size(); i++) {
            cout << "(" << vertices[i].row << ", " << vertices[i].col << ")";

            if (i != vertices.size() - 1)
                cout << ", ";
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
            cout << "(" << edgeList[i].v.row << ", " << edgeList[i].v.col << ")\n";
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

//    void ShowNeighbors(int v){
//        // display neighbors of vertex v
//        if (v < vertices.size()) {
//            cout << "Neighbors of " << vertices[v] << ": ";
//
//            if (adjacencyList[v].size() == 0) {
//                cout << "There is no neighbor.";
//            } else {
//                for (int i = 0; i < adjacencyList[v].size(); i++)
//                    cout << adjacencyList[v][i] << ", ";
//            }
//        }
//
//        cout << endl;
//    }
//
//    int Degree(int x, int y, int n) const{
//        // return the degree of vertex (x, y)
//        int v = x * n + y;
//        if (x < 0 || y < 0 || x >= n || y >= n)
//            return -1;
//
//        return adjacencyList[v].size();
//    }

//    void ShowDegrees(){
//        // display degrees of all vertices
//        for (int i = 0; i < vertices.size(); i++) {
//            cout << "Degree of " << vertices[i] << ": " << Degree(i) << endl;
//        }
//    }
//
//    bool HasEdge(int v1, int v2){
//        // returns true if there is an edge between vertices v1 n v2; false otherwise
//        if (v1 < vertices.size() && v2 < vertices.size()) {
//
//            for (int i = 0; i < adjacencyList[v1].size(); i++) {
//                if (adjacencyList[v1][i] == v2)
//                    return true;
//            }
//
//            for (int j = 0; j < adjacencyList[v2].size(); j++) {
//                if (adjacencyList[v2][j] == v1)
//                    return true;
//            }
//        }
//
//        return false;
//    }
//


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

    bool FindPath(int startX, int startY, int endX, int endY, bool isDFS = true) {
        if (!IsValidRowNum(startX) || !IsValidRowNum(endX) || !IsValidColNum(startY) || !IsValidColNum(endY))
            return false;

        if (adjacencyList[startX * GetCol() + startY].size() == 0 ||  adjacencyList[GetRow() * GetCol() - 1].size() == 0) // check the entrance and exit
            return false;

        if (startY == endX && startY == endY) return true;

        vector<bool> isVisited(VertexCount(), false);

        if (isDFS)
            return DFS(startX, startY, endX, endY, isVisited);

        return BFS(startX, startY, endX, endY, isVisited);
    }

    bool DFS(int curX, int curY, int endX, int endY, vector<bool>& isVisited) {
        if (curX == endX && curY == endY)
            return true;

        int curIndex = curX * GetCol() + curY;

        cout << "curX: " << curX << ", curY: " << curY << ", curIndex: " << curIndex << endl;

        if (isVisited[curIndex])
            return false;

        isVisited[curIndex] = true;

        for (int i = 0; i < adjacencyList[curIndex].size(); i++) {
            if (DFS(adjacencyList[curIndex][i].row, adjacencyList[curIndex][i].col, endX, endY, isVisited))
                return true;
        }

        return false;
    }

    bool BFS(int curX, int curY, int endX, int endY, vector<bool>& isVisited) {

        queue<int> curNode;
        int curIndex = curX * GetCol() + curY, nextIndex, endIndex = endX * GetCol() + endY;
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
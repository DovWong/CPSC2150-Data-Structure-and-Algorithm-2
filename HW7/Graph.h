#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Edge{
public:
    // assume u and v are two vertices 
    // vertices are zero-indexed
    int u;
    int v;

    Edge(){
        u = -1; // invalid vertex index
        v = -1; // invalid vertex index
    }

    Edge(int _u, int _v){
        u = _u;
        v = _v;
    }
};

class Graph{
private:
    vector<int> vertices;
    vector<vector<int>> adjacencyList;
    vector<Edge> edgeList;

public:
    Graph(){
    }

    Graph(bool adjacencyMatrix[4][4], int n){
        // adjacencyMatrix has dimension n x n with zeroes along the main diagonal
        // assume row 0 is for vertex 0, row 1 is for vertex 1 and so on
        // vertex i contains i as its data

        // TASKS: add methods to do the following:
        // build vertices, adjacencyList, edgeList using adjacencyMatrix.
        BuildVertices(n);
        BuildAdjacencyList(adjacencyMatrix, n);
        BuildEdgeList(adjacencyMatrix, n);
    }

    Graph(bool adjacencyMatrix[8][8], int n){
        // adjacencyMatrix has dimension n x n with zeroes along the main diagonal
        // assume row 0 is for vertex 0, row 1 is for vertex 1 and so on
        // vertex i contains i as its data

        // TASKS: add methods to do the following:
        // build vertices, adjacencyList, edgeList using adjacencyMatrix.
        BuildVertices(n);
        BuildAdjacencyList(adjacencyMatrix, n);
        BuildEdgeList(adjacencyMatrix, n);
    }

    void BuildVertices(int n) {
        for (int i = 0; i < n; i++)
            vertices.push_back(i);
    }

    void BuildAdjacencyList(bool adjacencyMatrix[4][4], int n) {
        for (int i = 0; i < n; i++) {
            vector<int> inAjList;
            adjacencyList.push_back(inAjList);

            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;

                if (adjacencyMatrix[i][j])
                    adjacencyList[i].push_back(j);
            }  
        }
    }

    void BuildAdjacencyList(bool adjacencyMatrix[8][8], int n) {
        for (int i = 0; i < n; i++) {
            vector<int> inAjList;
            adjacencyList.push_back(inAjList);

            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;

                if (adjacencyMatrix[i][j]) //TODO [j][i]?
                    adjacencyList[i].push_back(j);
            }
        }
    }

    void BuildEdgeList(bool adjacencyMatrix[4][4], int n) {

        for (int i = 0; i < n; i++) {
            
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;

                if (adjacencyMatrix[i][j]) {
                    Edge edge(i, j);
                    edgeList.push_back(edge);
                }
            }  
        }
    }

    void BuildEdgeList(bool adjacencyMatrix[8][8], int n) {

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;

                if (adjacencyMatrix[i][j]) {
                    Edge edge(i, j);
                    edgeList.push_back(edge);
                }
            }
        }
    }

    void ShowVertices() const{
        // display all vertices
    cout << "Vertices: ";

        for (int i = 0; i < vertices.size(); i++)
            cout << vertices[i] << ", ";

        cout << endl;
    }

    void ShowAdjacencyList() const{
        // display adjacency list
    cout << "Adjacency list:\n";

        for (int i = 0; i < adjacencyList.size(); i++) {

            cout << "Vertex " << vertices[i] << ": ";

            for (int j = 0; j < adjacencyList[i].size(); j++)
                cout << adjacencyList[i][j] << ", ";

            cout << endl;
        }
    }

    void ShowEdgeList(){
        
        cout << "Edge list:\n";

        for (int i = 0; i < edgeList.size(); i++)
            cout << edgeList[i].u << ", " << edgeList[i].v << endl;

    }

    int VertexCount(){
        // returns the number of vertices in the graph
        return vertices.size();
    }

    int EdgeCount(){
        // returns the number of edges in the graph
        return edgeList.size();
    }

    void ShowNeighbors(int v){
        // display neighbors of vertex v
        if (v < vertices.size()) {
            cout << "Neighbors of " << vertices[v] << ": ";

            if (adjacencyList[v].size() == 0) {
                cout << "There is no neighbor.";
            } else {
                for (int i = 0; i < adjacencyList[v].size(); i++)
                    cout << adjacencyList[v][i] << ", ";
            }
        }

        cout << endl;
    }

    int Degree(int v) const{
        // return the degree of vertex v
        if (v >= adjacencyList.size())
            return -1;

        return adjacencyList[v].size();
    }

    bool IsDirected(){
        // returns true if the graph is directed; false otherwise
        bool flag = false;

        for (int i = 0; i < vertices.size(); i++) {
            for (int j = 0; j < adjacencyList[i].size(); j++) {

                int vertex1 = vertices[i];
                int vertex2 = adjacencyList[i][j];

                for (int k = 0; k < adjacencyList[vertex2].size(); k++) {
                    if (adjacencyList[vertex2][k] == vertex1) {
                        flag = true;
                        break;
                    }
                }

                if (!flag)
                    return true;

                flag = false;
            }
        }

        return false;
    }

    void ShowDegrees(){
        // display degrees of all vertices
        for (int i = 0; i < vertices.size(); i++) {
            cout << "Degree of " << vertices[i] << ": " << Degree(i) << endl;
        }
    }

    bool HasEdge(int v1, int v2){
        // returns true if there is an edge between vertices v1 n v2; false otherwise
        if (v1 < vertices.size() && v2 < vertices.size()) {

            for (int i = 0; i < adjacencyList[v1].size(); i++) {
                if (adjacencyList[v1][i] == v2)
                    return true;
            }

            for (int j = 0; j < adjacencyList[v2].size(); j++) {
                if (adjacencyList[v2][j] == v1)
                    return true;
            }
        }

        return false;
    }

    /**
     * Try DFS but there some errors
     * @param v1
     * @param v2
     * @return
     */
//    int Path(int v1, int v2){
//        // returns the length of the path (number of edges) if there is a path from vertex v1 to vertex v2; otherwise returns 0
//
//        vector<int> reachList;
//        if (!Path(v1, v2, reachList))
//            return 0;
//
//        cout << endl << endl;
//
//        for (int i = 0; i < reachList.size(); i++) {
//
//            cout << reachList[i];
//
//            if (i != reachList.size() - 1)
//                cout << " -> ";
//            else
//                cout << endl;
//        }
//
//        cout << endl;
//
//        return reachList.size() - 1;
//    }
//
//    bool Path(int v1, int v2, vector<int>& reachList) {
//
//        if (v1 == v2) {
//            reachList.push_back(v1);
//
//            for (int i = 0; i < reachList.size(); i++) {
//
//                cout << reachList[i];
//
//                if (i != reachList.size() - 1)
//                    cout << " -> ";
//                else
//                    cout << endl;
//            }
//            return true;
//        }
//
//        for (int i = 0; i < reachList.size(); i++) {
//            if (reachList[i] == v1) {
//                cout << "end here: ";
//
//                for (int i = 0; i < reachList.size(); i++) {
//
//                    cout << reachList[i];
//
//                    cout << " -> ";
//
//                }
//
//                cout << v1 << endl;
//
//                return false;
//            }
//        }
//
//        reachList.push_back(v1);
//        vector<int> finalReachList = reachList;
//        vector<int> tempReachList = reachList;
//        int shortestPath = vertices.size(); //Longest path is size - 1;
//
//        for (int i = 0; i < adjacencyList[v1].size(); i++) { //check is there direct path first
//
//           // cout << "Checking " << v1 << " and " << adjacencyList[v1][i] << endl;
//
//            if (Path(adjacencyList[v1][i], v2, reachList)) {
//                if (reachList.size() < shortestPath) {
//                    shortestPath = reachList.size();
//                    finalReachList = reachList;
//                    reachList = tempReachList;
//                }
//            }
//        }
//
//        if (shortestPath < vertices.size()) {
//            reachList = finalReachList;
//            return true;
//        }
//
//        reachList.pop_back();
//        return false;
//    }

//    int Path(int v1, int v2){ //TODO minimum?
//        // returns the length of the path (number of edges) if there is a path from vertex v1 to vertex v2; otherwise returns 0
//
//        int size = vertices.size();
//
//        if (v1 < 0 || v2 < 0 || v1 >= size || v2 >= size)
//            return 0;
//
//        vector<bool> visitedList(size, false); //Hashing for recording the visited node
//        queue<int> nextNode;
//        nextNode.push(v1);
//        int nextStep = 1;
//        int nextNextStep = 0;
//        int length = 0;
//
//        while (visitedList.size() == size) {
//
//            int curNode = nextNode.front();
//
//            for (int i = 0; i < adjacencyList[curNode].size(); i++) {
//
//                if (adjacencyList[curNode][i] == v2) { //check visited? or in the quene
//                    //print to see
//                    return length + 1; //not true return num
//                } else if (visitedList[adjacencyList[curNode][i]]) { //infinite loop?
//                    continue;
//                } else {
//                    nextNode.push(adjacencyList[curNode][i]);
//                    nextNextStep++;
//                }
//            }
//
//            nextStep--;
//
//            if (nextStep == 0) {
//                length++;
//                nextStep = nextNextStep;
//                nextNextStep = 0;
//            }
//
//            visitedList[curNode] = true;
//            nextNode.pop();
//        }
//
//        return 0;
//    }

    int Path(int v1, int v2){ //BFS
        // returns the length of the path (number of edges) if there is a path from vertex v1 to vertex v2; otherwise returns 0
        int size = vertices.size();

        if (v1 < 0 || v2 < 0 || v1 >= size || v2 >= size)
            return 0;

        vector<bool> visitedList(size, false); //Hashing for recording the visited node
        queue<int> nextNode;
        nextNode.push(v1);
        int nextStep = 1, nextNextStep = 0, length = 0;

        while (!nextNode.empty()) {

            int curNode = nextNode.front();

            for (int i = 0; i < adjacencyList[curNode].size(); i++) {

                if (adjacencyList[curNode][i] == v2) { //check visited? or in the quene
                    //print to see
                    return length + 1; //not true return num
                } else if (!visitedList[adjacencyList[curNode][i]]) { //infinite loop?
                    nextNode.push(adjacencyList[curNode][i]);
                    nextNextStep++;
                }
            }

            nextStep--;

            if (nextStep == 0) {
                length++;
                nextStep = nextNextStep;
                nextNextStep = 0;
            }

            visitedList[curNode] = true;
            nextNode.pop();
        }

        return 0;
    }


    bool HasCycle(){
        // return true if graph has a cycle (starting from a node we follow edges to return back to the same vertex); false otherwise
        if (VertexCount() <= 1 || EdgeCount() == 0)
            return false;

        if (!IsDirected())
            return true;

        vector<bool> isVisited(VertexCount(), false);

        for (int i = 0; i < vertices.size(); i++) {
            if (DFSForHasCycle(vertices[i], vertices[i], isVisited))
                return true;
        }

        return false;
    }

    bool DFSForHasCycle(int cur, int end, vector<bool>& isVisited) {

        if (isVisited[end] != 0 && cur == end)
            return true;

        if (isVisited[cur])
            return false;

        isVisited[cur] = true;

        for (int i = 0; i < adjacencyList[cur].size(); i++) {

            int next = adjacencyList[cur][i];
            if (DFSForHasCycle(next, end, isVisited))
                return true;
        }

        isVisited[cur] = false;
        return false;
    }

    void ShowCycles(){
        // displays all cycles (if any)
        // each cycle should begin and end with the same vertex
        if (!HasCycle())
            return;

        vector<int> path;

        if (!IsDirected()) {
            vector<int> visitedCount(VertexCount(), 0);

            for (int i = 0; i < VertexCount(); i++)
                DFSForUnDirectedShowCycles(vertices[i], visitedCount, path);
        } else {
            vector<bool> isVisited(VertexCount(), false);

            for (int i = 0; i < VertexCount(); i++)
                DFSForDirectedShowCycles(vertices[i], isVisited, path);
        }
    }

    void DFSForDirectedShowCycles(int cur, vector<bool>& isVisited, vector<int>& path) {

        if (path.size() != 0 && path[0] == cur) {
            for (int j = 0; j < path.size(); j++) {
                cout << path[j] << " - > ";

                if (j == path.size() - 1)
                    cout << cur << endl;
            }

            return;
        }

        if (isVisited[cur])
            return;

        isVisited[cur] = true;
        path.push_back(cur);

        for (int i = 0; i < adjacencyList[cur].size(); i++) {

            int next = adjacencyList[cur][i];
            DFSForDirectedShowCycles(next, isVisited, path);
        }

        isVisited[cur] = false;
        path.pop_back();
        return;
    }

    void DFSForUnDirectedShowCycles(int cur, vector<int>& visitedCount, vector<int>& path) {

        if (path.size() != 0 && path[0] == cur) {
            for (int j = 0; j < path.size(); j++) {
                cout << path[j] << " - > ";

                if (j == path.size() - 1)
                    cout << cur << endl;

            }
            return;
        }

        if (visitedCount[cur] >= 2)
            return;

        visitedCount[cur]++;
        path.push_back(cur);

        for (int i = 0; i < adjacencyList[cur].size(); i++) {

            int next = adjacencyList[cur][i];
            DFSForUnDirectedShowCycles(next, visitedCount, path);
        }

        visitedCount[cur]--;
        path.pop_back();
        return;
    }

};



#endif
#include <bits/stdc++.h>
using namespace std;

int NO_PARENT = -1;
vector<string> direction;
void printPath(int nVertices, int currentVertex, vector<int> parents)
{
    string ch[nVertices] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "P1", "P2", "P3"};
    if (currentVertex == NO_PARENT)
    {
        return;
    }
    printPath(nVertices, parents[currentVertex], parents);
    direction.push_back(ch[currentVertex]);
}

void printSolution(int startVertex, vector<int> distances, vector<int> parents, int endVertex)
{
    int nVertices = distances.size();
    vector<string> direction;
    for (int vertexIndex = 0; vertexIndex < nVertices; vertexIndex++)
    {
        if (vertexIndex != startVertex && vertexIndex == endVertex)
        {
            printPath(nVertices, vertexIndex, parents);
        }
    }
}

void dijkstra(vector<vector<int>> adjacencyMatrix, int startVertex, int endVertex)
{
    int nVertices = adjacencyMatrix[0].size();
    vector<int> shortestDistances(nVertices);
    vector<bool> added(nVertices);
    for (int vertexIndex = 0; vertexIndex < nVertices; vertexIndex++)
    {
        shortestDistances[vertexIndex] = INT_MAX;
        added[vertexIndex] = false;
    }
    shortestDistances[startVertex] = 0;
    vector<int> parents(nVertices);
    parents[startVertex] = NO_PARENT;
    for (int i = 1; i < nVertices; i++)
    {
        int nearestVertex = -1;
        int shortestDistance = INT_MAX;
        for (int vertexIndex = 0; vertexIndex < nVertices; vertexIndex++)
        {
            if (!added[vertexIndex] && shortestDistances[vertexIndex] < shortestDistance)
            {
                nearestVertex = vertexIndex;
                shortestDistance = shortestDistances[vertexIndex];
            }
        }
        added[nearestVertex] = true;
        for (int vertexIndex = 0; vertexIndex < nVertices; vertexIndex++)
        {
            int edgeDistance = adjacencyMatrix[nearestVertex][vertexIndex];
            if (edgeDistance > 0 && ((shortestDistance + edgeDistance) < shortestDistances[vertexIndex]))
            {
                parents[vertexIndex] = nearestVertex;
                shortestDistances[vertexIndex] = shortestDistance + edgeDistance;
            }
        }
    }
    printSolution(startVertex, shortestDistances, parents, endVertex);
}
int main()
{
    vector<vector<int>> adjacencyMatrix

        = {
            {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, // 0
            {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 1
            {0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 2
            {0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, // 3
            {0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 4
            {0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 5
            {0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, // 6
            {0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 7
            {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 8
            {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 9
            {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, // 10
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0}, // 11
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, // 12
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, // 13
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0}, // 14
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, // 15
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, // 16
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1}, // 17
            {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}  // 18
        };

    int source, destination;

    source = 15;
    destination = 7;

    dijkstra(adjacencyMatrix, source, destination);
    int n = direction.size();
    for (int i = 0; i < n; i++)
    {
        if ((direction[i] == "G" && direction[i + 1] == "H") || (direction[i] == "D" && direction[i + 1] == "K") || (direction[i] == "A" && direction[i + 1] == "N"))
        {
            cout << direction[i] << " ---> Hold\n";
        }
        else if ((direction[i] == "G" && direction[i - 1] == "H") || (direction[i] == "D" && direction[i - 1] == "K") || (direction[i] == "A" && direction[i - 1] == "N"))
        {
            cout << direction[i] << " ---> Hold\n";
        }
        else
        {
            cout << direction[i] << "\n";
        }
    }
    return 0;
}
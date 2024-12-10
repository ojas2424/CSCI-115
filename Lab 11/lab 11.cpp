#include<iostream>
#include <list>
#include <bits/stdc++.h>


using namespace std;


class Graph
{
    int V;

    list<int>* adj;
public:
    Graph(int V);
    void edgeBFS(int v, int w);
    void BFS(int s);

    map<int, bool> visited;

    void edgeDFS(int v, int w);

    void DFS(int v);

};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::edgeBFS(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::edgeDFS(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::BFS(int s)
{
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    list<int> queue;

    visited[s] = true;
    queue.push_back(s);


    list<int>::iterator i;

    while (!queue.empty())
    {
        s = queue.front();
        cout << s << " ";
        queue.pop_front();


        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

void Graph::DFS(int v)
{

    visited[v] = true;
    cout << v << " ";

    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i);
}


int main()
{
    Graph g(4);
    g.edgeBFS(0, 1);
    g.edgeBFS(0, 2);
    g.edgeBFS(1, 2);
    g.edgeBFS(2, 0);
    g.edgeBFS(2, 3);
    g.edgeBFS(3, 3);

    cout << " BFS ";
    g.BFS(2);

    cout << endl;
    cout << endl;

    Graph g1(4);
    g1.edgeDFS(0, 1);
    g1.edgeDFS(0, 2);
    g1.edgeDFS(1, 2);
    g1.edgeDFS(2, 0);
    g1.edgeDFS(2, 3);
    g1.edgeDFS(3, 3);

    cout << " DFS ";
    g1.DFS(2);

    return 0;

}
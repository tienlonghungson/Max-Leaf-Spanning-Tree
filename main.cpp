#include<bits/stdc++.h>
#include"DegreeProbAlgorithm.cpp"

using namespace std;

int main(){
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);


    AbstractAlgorithm* algorithm = new DegreeProbAlgorithm(g);

    algorithm->execute();
    return 0;
}
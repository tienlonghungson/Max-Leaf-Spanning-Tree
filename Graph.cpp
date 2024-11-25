#include<bits/stdc++.h>
using namespace std;

class Graph{
    private:
        int n;
        vector<vector<int>> list;
    public:
        Graph(int N){
            n = N;
            list = vector<vector<int>>(n);
        }

        Graph() {}

        void addEdge(int u, int v){
            list[u].push_back(v);
            list[v].push_back(u);
        }

        int size(){
            return n;
        }
};
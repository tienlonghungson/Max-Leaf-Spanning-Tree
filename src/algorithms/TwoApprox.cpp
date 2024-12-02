#include "../AbstractAlgorithm.h"
#include "../SpanningTree.h"
#include <cstdio>
#include <list>
#include <map>
#include <utility>
#include <vector>

using namespace std;

const int N = 100;

class TwoApprox: public AbstractAlgorithm{
private:
    vector<int> T; // current tree's vertices
    vector<pair<int, int> > edges; // edges in T
    list<int> W2, W1, W0;

    list<int> unSpannedNeighbor[100];
    map<int, list<int>::iterator > lIter[100];

    void expand(int u){
        for (int v : unSpannedNeighbor[u]) {
            printf("Iterate at %d, neighbor of %d\n",v,u);
            W2.push_back(v);
            T.push_back(v);
            edges.push_back({u,v});

            for (int w : unSpannedNeighbor[v]) {
                if (w!=u){
                    printf("Remove %d from neighbor list of %d\n",v, w);
                    unSpannedNeighbor[w].erase(lIter[w][v]);
                }
            }
            printf("Remove Done for %d\n",v);
        }
        for (auto it = unSpannedNeighbor[u].begin();it != unSpannedNeighbor[u].end();){
            it = unSpannedNeighbor[u].erase(it);
        }
        printf("Remove Done\n");
    }

    void createUandLIter(int n, const vector<vector<int> >& adjacentList){
        for (int i=0;i<n;++i){
            for (int v: adjacentList[i]){
                unSpannedNeighbor[i].push_back(v);
                lIter[i][v] = --unSpannedNeighbor[i].end();
            }
        }
    }


public:
    TwoApprox(Graph g): AbstractAlgorithm(g){}
    void initiate(Graph st){}

    Graph* execute(){
        int n = graph.size();
        vector<vector<int> > adjacentList = graph.getAdjacentList();
        createUandLIter(n, adjacentList);
        
        printf("Start 1\n");

        // find a vertex with maximum degree
        int max_deg = adjacentList[0].size();
        int v = 0;
        
        for (int i=1;i<n-1;++i){
            if (max_deg < adjacentList[i].size()){
                max_deg = adjacentList[i].size();
                v = i;
            }
        }

        printf("Start 2\n");

        T.push_back(v);
        for (int w : unSpannedNeighbor[v]) {
            printf("Remove %d from neighbor list of %d\n",v, w);
            unSpannedNeighbor[w].erase(lIter[w][v]);
        }
        
        expand(v);

        printf("create neighborOutsideT\n");
        int neighborOutsideT;
        printf("create neighborOutsideT\n");

        printf("Start 3\n");
        while (T.size()<n) {
            if (!W2.empty()) {
                v = W2.front();
                W2.pop_front();

                if (unSpannedNeighbor[v].size()==1) {
                    W1.push_back(v);
                } else {
                    expand(v);
                }
            } else if (!W1.empty()) {
                v = W1.front();
                W1.pop_front();

                neighborOutsideT = unSpannedNeighbor[v].front();
                if (unSpannedNeighbor[neighborOutsideT].size() == 1) {
                    W0.push_back(v);
                } else {
                    expand(v);
                }
            } else if (!W0.empty()) {
                v = W0.back();
                W0.pop_back();

                expand(v);
            }
        }

        Graph* sp = new SpanningTree(n);
        for (pair<int, int> edge : edges) {
            sp->addEdge(edge.first, edge.second);
        }
        return sp;

    }

};

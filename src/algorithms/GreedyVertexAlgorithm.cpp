#include <vector>
#include "../AbstractAlgorithm.h"
#include "../SpanningTree.h"

using namespace std;

const int IS_LEAF = 0;
const int IS_INNER = 1;
const int NOT_VISITED = 2;

class GreedyVertexAlgorithm : public AbstractAlgorithm{
public:
    GreedyVertexAlgorithm(Graph g): AbstractAlgorithm(g){}

    void initiate(Graph st){

    }

    Graph* execute(){
        vector<vector<int> > adjacentList = graph.getAdjacentList();
        int n = graph.size();
        int max_deg = 0;
        int nextVer = 0;
        vector<int> deg (n,0);

        for (int i=0; i<n; ++i){
            deg[i] = adjacentList[i].size();
            if (max_deg < deg[i]) {
                max_deg = deg[i]; 
                nextVer = i;
            }
        }


        Graph*  sp = new SpanningTree(n);
        int curN = 1 + adjacentList[nextVer].size();
        vector<int> status(n,NOT_VISITED);

        for (int v: adjacentList[nextVer]){
            status[v] = IS_LEAF;
            sp->addEdge(nextVer,v);

            for (int w : adjacentList[v]) {
                if (status[w] != NOT_VISITED) {
                    deg[w]--;
                    deg[v]--;
                }
            }
        }


        while (curN<n) {
            max_deg = -1;
            for (int i=0; i<n; ++i) {
                if (status[i] == IS_LEAF){
                    if (max_deg<deg[i]) {
                        max_deg = deg[i];
                        nextVer = i;
                    }
                }
            }

            status[nextVer] = IS_INNER;
            for (int v : adjacentList[nextVer]) {
                if (status[v] == NOT_VISITED) {
                    status[v] = IS_LEAF;
                    sp->addEdge(nextVer, v);
                    curN ++;

                    for (int w : adjacentList[v]) {
                        if (status[w] != NOT_VISITED) {
                            deg[w]--;
                            deg[v]--;
                        }
                    }
                }
            }

        }

        return sp;

    }
};

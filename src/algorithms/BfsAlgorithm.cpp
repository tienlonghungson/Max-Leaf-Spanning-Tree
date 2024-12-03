#include <vector>
#include <queue>
#include "../AbstractAlgorithm.h"
#include "../SpanningTree.h"

using namespace std;

class BfsAlgorithm : public AbstractAlgorithm{
public:
    BfsAlgorithm(Graph g): AbstractAlgorithm(g){}

    void initiate(Graph st){

    }

    Graph* execute(){
        SpanningTree* st = new SpanningTree(graph.size());

        queue<int> q;
        q.push(0);
        auto list = graph.getAdjacentList();

        vector<bool> visited(graph.size());
        visited[0] = true;

        while(!q.empty())
        {
            int u = q.front();
            q.pop();

            for(auto v : list[u]){
                if (!visited[v]){
                    st->addEdge(u, v);
                    visited[v] = true;

                    q.push(v);
                }
            }
        }

        return st;
    }
};

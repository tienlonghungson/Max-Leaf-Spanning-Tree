#include <vector>
#include <queue>
#include "../AbstractAlgorithm.h"
#include "../SpanningTree.h"
#include "LocalSearchAlgorithm.cpp"

using namespace std;

class BfsAlgorithm : public AbstractAlgorithm{
private:
    AbstractAlgorithm* localSearch;

public:
    BfsAlgorithm(Graph g): AbstractAlgorithm(g){
        localSearch = new LocalSearchAlgorithm(g);
    }

    ~BfsAlgorithm(){
        delete localSearch;
    }

    void initiate(Graph st){
    }

    SpanningTree* RunLocalSearchOnBfs(int source)
    {
        SpanningTree* st = new SpanningTree(graph.size());

        queue<int> q;
        q.push(source);
        auto list = graph.getAdjacentList();

        vector<bool> visited(graph.size());
        visited[source] = true;

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

        localSearch->initiate(*st);
        SpanningTree* tree = (SpanningTree* )localSearch->execute();
        delete st;

        return tree;
    }

    Graph* execute(){
        SpanningTree* st = nullptr;

        for (int i = 0; i < graph.size(); i++){
            SpanningTree * st2 = RunLocalSearchOnBfs(i);
            if (st == nullptr){
                st = st2;
            }else{
                if (st->getLeavesCount() < st2->getLeavesCount()){
                    swap(st, st2);
                }

                delete st2;
            }
        }
        return st;
    }
};

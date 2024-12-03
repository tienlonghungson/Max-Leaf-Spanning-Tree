#include <algorithm>
#include <iostream>
#include "../AbstractAlgorithm.h"
#include "../SpanningTree.h"

using namespace std;
#ifndef LOCALSEARCHALGORITHM_H
#define LOCALSEARCHALGORITHM_H

class LocalSearchAlgorithm : public AbstractAlgorithm{
    private:
        Graph spanningTree;

        void getFreeEdges(
            vector<pair<int, int>> &freeEdges,
            vector<vector<int>> &treeList,
            vector<vector<int>> &graphList)
        {
            for(int i = 0; i < graphList.size(); i++){
                for(int j = 0; j < graphList[i].size(); j++){
                    int u = i;
                    int v = graphList[i][j];

                    auto iter = lower_bound(treeList[u].begin(), treeList[u].end(), v);

                    if (iter == treeList[u].end() || *iter != v)
                    {
                        freeEdges.push_back({u, v});
                    }
                }
            }
        }

        bool increaseLeaves(
            vector<pair<int, int>> &freeEdges,
            vector<vector<int>> &treeList,
            vector<vector<int>> &graphList,
            pair<int, int> edge)
        {
            bool increased = false;

            int u = edge.first;
            int v = edge.second;

            int previousLeaves = (treeList[u].size() == 1) + (treeList[v].size() == 1);

            if (previousLeaves == 2){
                return false;
            }

            vector<int> path;
            vector<int> visited(graph.size());
            getPath(u, v, path, visited);
            vector<int> degrees(path.size());

            for(int i = 0; i < path.size(); i++){
                degrees[i] = treeList[path[i]].size();
            }

            degrees[0]++; degrees[(int)degrees.size() - 1]++;

            for(int i = 0; i < (int)path.size() - 1; i++){
                int leavesIncrease = (degrees[i] == 2) + (degrees[i+1] == 2);
                if(leavesIncrease > previousLeaves){
                    increased = true;

                    spanningTree.addEdge(u, v);
                    spanningTree.removeEdgeSorted(path[i], path[i+1]);
                    break;
                }
            }

            return increased;
        }

    public:
        LocalSearchAlgorithm(Graph g) : AbstractAlgorithm(g) {}

        void initiate(Graph st){
            spanningTree = st;
        }

        bool getPath(int source, int dest, vector<int> &path, vector<int> &visited){
            visited[source] = true;
            path.push_back(source);

            if(source == dest){
                return true;
            }

            bool found = false;

            for(auto v: spanningTree.getAdjacentList()[source]){
                if(!visited[v]){
                    found = found || getPath(v, dest, path, visited);
                }
            }

            if (!found){
                path.pop_back();
            }

            return found;
        }

        Graph* execute(){
            bool localOptima = false;

            while(!localOptima){
                vector<vector<int>> treeList = spanningTree.getAdjacentList();
                vector<vector<int>> graphList = graph.getAdjacentList();

                vector<pair<int, int>> freeEdges;
                for (int i = 0; i < treeList.size(); i++){
                    sort(treeList[i].begin(), treeList[i].end());
                }

                getFreeEdges(freeEdges, treeList, graphList);
                bool increased = false;
                
                for (auto edge: freeEdges){
                    increased = increaseLeaves(freeEdges, treeList, graphList, edge);
                    
                    if (increased){
                        break;
                    }
                }

                localOptima = !increased;
            }

            return new SpanningTree(spanningTree);
        }
};


#endif
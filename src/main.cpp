#include "AbstractAlgorithm.h"
#include "algorithms/GreedyVertexAlgorithm.cpp"
#include "algorithms/LocalSearchAlgorithm.cpp"
#include "algorithms/TwoApprox.cpp"
#include "algorithms/BfsAlgorithm.cpp"
#include "SpanningTree.h"
#include <iostream>
#include <vector>

using namespace std;

SpanningTree * run(AbstractAlgorithm* algorithm, Graph g){
    SpanningTree * tree = (SpanningTree *)algorithm->execute();

    AbstractAlgorithm* localSearch = new LocalSearchAlgorithm(g);
    localSearch->initiate(*tree);

    SpanningTree * output = (SpanningTree *)localSearch->execute();

    delete tree;

    return output;
}

SpanningTree* run(Graph g){
    SpanningTree * ans;
    SpanningTree * cur;

    AbstractAlgorithm* algorithm;
    algorithm = new TwoApprox(g);
    ans = run(algorithm, g);

    algorithm = new BfsAlgorithm(g);
    cur = run(algorithm, g);

    if(cur->getLeavesCount() > ans->getLeavesCount()){
        delete ans;
        ans = cur;
    }else{
        delete cur;
    }

    algorithm = new GreedyVertexAlgorithm(g);
    run(algorithm, g);
    cur = run(algorithm, g);

    if(cur->getLeavesCount() > ans->getLeavesCount()){
        delete ans;
        ans = cur;
    }else{
        delete cur;
    }

    if (ans->verify(g) == false){
        cout << "Somethign error!!!!!!!!!!!!\n";

        exit(0);
    }

    return ans;
}

void output(SpanningTree *st){
    cout << st->getLeavesCount() << " " << (st->size() - 1) << "\n";
    vector<pair<int, int>> edges;

    auto adjacentList = st->getAdjacentList();

    for(int i = 0; i < adjacentList.size(); i++){
        int u = i;
        for(auto v : adjacentList[i]){
            if(u < v){
                edges.push_back({u, v});
            }
        }
    }

    sort(edges.begin(), edges.end());

    for(auto edge: edges){
        cout << edge.first << " " << edge.second << "\n";
    }

}

void solve(){
    int n, m;
    cin >> n >> m;

    Graph g(n);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    SpanningTree* tree = run(g);
    
    output(tree);

    delete tree;
}

int main(){
    freopen("InputOutputs/all-hard.in","r",stdin);
    freopen("InputOutputs/all-hard.out","w",stdout);
    int k=0;

    while(1){
        solve();

        k++;
        cerr<<"Solved instance "<<k<<"\n";
        
        if (cin.eof()) {
            break;
        }
    }

    return 0;
}

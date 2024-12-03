#include "AbstractAlgorithm.h"
#include "Graph.h"
#include "algorithms/GreedyVertexAlgorithm.cpp"
#include "algorithms/LocalSearchAlgorithm.cpp"
#include "algorithms/TwoApprox.cpp"
#include "algorithms/BfsAlgorithm.cpp"
#include "SpanningTree.h"
#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    // int n, m, a, b;
    //
    // scanf("%d %d",&n, &m);
    // Graph g(n);
    // for (int i=0;i<m;++i){
    //     scanf("%d %d", &a, &b);
    //     g.addEdge(a,b);
    // }

    freopen("input.txt","r",stdin);

    int n, m;
    cin >> n >> m;

    Graph g(n);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    AbstractAlgorithm* bfs = new BfsAlgorithm(g);
    AbstractAlgorithm* greedyAlg = new GreedyVertexAlgorithm(g);
    AbstractAlgorithm* twoApprox = new TwoApprox(g);
    AbstractAlgorithm* localSearch = new LocalSearchAlgorithm(g);

    SpanningTree * answer;
    int leavesOfAnswer = -1;
    int leavesOfTmpAnswer;


    // BFS 
    SpanningTree * tmpAnswer = (SpanningTree *)bfs->execute();
    answer = tmpAnswer;
    leavesOfTmpAnswer = tmpAnswer->getLeavesCount();
    leavesOfAnswer = leavesOfTmpAnswer;

    cout<<"Solution of BFS\n";
    tmpAnswer->printGraph();

    cout << "Is tree?" << tmpAnswer->verify(g) << "\n";
    cout << "Leaves Count" << leavesOfTmpAnswer << "\n";

    localSearch->initiate(*tmpAnswer);
    tmpAnswer = (SpanningTree *)localSearch->execute();
    leavesOfTmpAnswer = tmpAnswer->getLeavesCount();

    cout<<"Solution of localSearch\n";
    tmpAnswer->printGraph();

    cout << "Is tree?" << tmpAnswer->verify(g) << "\n";
    cout << "Leaves Count" << leavesOfTmpAnswer << "\n";

    if (leavesOfAnswer<leavesOfTmpAnswer) {
        answer = tmpAnswer;
        leavesOfAnswer = leavesOfTmpAnswer;
    }

    // GreedyVertexAlgorithm
    tmpAnswer = (SpanningTree*) greedyAlg->execute();
    cout<<"Solution of Greedy\n";
    tmpAnswer->printGraph();

    localSearch->initiate(*tmpAnswer);
    tmpAnswer = (SpanningTree*) localSearch->execute();
    leavesOfTmpAnswer = tmpAnswer->getLeavesCount();

    cout<<"Solution of localSearch\n";
    tmpAnswer->printGraph();

    cout << "Is tree?" << tmpAnswer->verify(g) << "\n";
    cout << "Leaves Count" << leavesOfTmpAnswer << "\n";

    if (leavesOfAnswer<leavesOfTmpAnswer) {
        answer = tmpAnswer;
        leavesOfAnswer = leavesOfTmpAnswer;
    }

    // TwoApprox
    tmpAnswer = (SpanningTree*) twoApprox->execute();

    cout<<"Solution of TwoApprox\n";
    tmpAnswer->printGraph();

    localSearch->initiate(*tmpAnswer);
    tmpAnswer = (SpanningTree*) localSearch->execute();
    leavesOfTmpAnswer = tmpAnswer->getLeavesCount();

    cout<<"Solution of localSearch\n";
    tmpAnswer->printGraph();

    cout << "Is tree?" << tmpAnswer->verify(g) << "\n";
    cout << "Leaves Count" << leavesOfTmpAnswer << "\n";

    if (leavesOfAnswer<leavesOfTmpAnswer) {
        answer = tmpAnswer;
        leavesOfAnswer = leavesOfTmpAnswer;
    }

    cout<<"Answer\n";
    cout<<"leavesOfAnswer = "<<leavesOfAnswer<<"\n";
    answer->printGraph();

    return 0;
}


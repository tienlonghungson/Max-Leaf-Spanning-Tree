#include <iostream>
#include"../AbstractAlgorithm.h"

using namespace std;

class DegreeProbAlgorithm : public AbstractAlgorithm{
    public:
        DegreeProbAlgorithm(Graph g) : AbstractAlgorithm(g) {}

        void initiate(Graph st){
        }

        Graph* execute(){
            std::cout << "Executing...\n";
            return NULL;
        }
};

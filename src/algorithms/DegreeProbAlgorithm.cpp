#include <iostream>
#include"../AbstractAlgorithm.cpp"

using namespace std;

class DegreeProbAlgorithm : public AbstractAlgorithm{
    public:
        DegreeProbAlgorithm(Graph g) : AbstractAlgorithm(g) {}

        void initiate(Graph st){
        }

        void execute(){
            std::cout << "Executing...\n";
        }
};

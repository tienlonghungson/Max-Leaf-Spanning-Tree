#include"AbstractAlgorithm.cpp"

class DegreeProbAlgorithm : public AbstractAlgorithm{
    public:
        DegreeProbAlgorithm(Graph g) : AbstractAlgorithm(g) {}

        void initiate(Graph st){
        }

        void execute(){
            cout << "Executing...\n";
        }
};
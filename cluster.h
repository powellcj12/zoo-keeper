#include "animals.h"
#include <cfloat>

using namespace std;

class cluster
{
public:
	cluster();
	cluster(char* filename);
	void init(char* filename);
	void performClustering(int metric, int maxClusters);
	void print();

private:
	vector<AnimalSet*> animalSets;
};
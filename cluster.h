#include "animals.h"

using namespace std;

class cluster
{
public:
	cluster();
	cluster(char* filename);
	void init(char* filename);
	void performClustering(int metric, int maxClusters);

private:
	vector<AnimalSet*> animalSets;
};
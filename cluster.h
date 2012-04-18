#include "animals.h"

using namespace std;

class cluster
{
public:
	cluster();
	cluster(char* filename);
	void init(char* filename);
	void performCluster();

private:
	vector<AnimalSet*> animalSets;
};
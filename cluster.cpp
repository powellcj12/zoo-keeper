#include "cluster.h"

using namespace std;

cluster::cluster()
{
}

cluster::cluster(char* filename)
{
	init(filename);
}

void cluster::init(char* filename)
{
	ifstream inFile;
	inFile.open(filename, ifstream::in);

	while(inFile.good())
	{
		AnimalSet* temp = new AnimalSet(new animal(inFile));
		animalSets.push_back(temp);
	}
}

void cluster::performClustering(int maxClusters)
{

}
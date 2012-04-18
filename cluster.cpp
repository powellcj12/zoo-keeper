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

void cluster::performClustering(int metric, int maxClusters)
{
	float minDist;
	int index1, index2;

	while((int)animalSets.size() > maxClusters)
	{
		minDist = FLT_MAX;

		for(unsigned long i = 0; i < animalSets.size() - 1; i++)
		{
			for(unsigned long j = i+1; j < animalSets.size(); j++)
			{
				float distTest;

				switch(metric)
				{
					case 1:
						distTest = AnimalSet::minDistance(animalSets[i], animalSets[j]);
						break;
					case 2:
						distTest = AnimalSet::maxDistance(animalSets[i], animalSets[j]);
						break;
					case 3:
						distTest = AnimalSet::avgDistance(animalSets[i], animalSets[j]);
				}

				if(distTest < minDist)
				{
					minDist = distTest;
					index1 = i;
					index2 = j;
				}
			}
		}

		AnimalSet* newSet = AnimalSet::unionSets(animalSets[index1], animalSets[index2]);
		animalSets.erase(animalSets.begin()+index2);
		animalSets.erase(animalSets.begin()+index1);
		animalSets.push_back(newSet);
	}
}

void cluster::print()
{
	for(unsigned long i = 0; i < animalSets.size(); i++)
	{
		cout << "Cluster " << i+1 << ":\n";
		animalSets[i] -> print();
	}
}
#include <iostream>
#include "cluster.h"

using namespace std;

int main(int argc, char** argv)
{
	if(argc != 4)
	{
		cout << "Please specify a data file followed by the metric and number of clusters desired.\n";
		exit(1);
	}
	else
	{
		cluster* c = new cluster(argv[1]);
		c -> performClustering(atoi(argv[2]), atoi(argv[3]));
		c -> print();
	}

	return 0;
}
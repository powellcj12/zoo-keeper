#include "animals.h"

using namespace std;

animal::animal(ifstream &file)
{
	file >> name;

	float temp;
	for(int i = 0; i < NUM_ATTRIBUTES; i++)
	{
		file >> temp;
		attributes.push_back(temp);
	}
}

float animal::getAttribute(int num)
{
	if(num >= 0 && num < NUM_ATTRIBUTES)
		return attributes[num];
	else
		return 0.0;
}

float animal::distance(animal* a, animal* b)
{
	float sum = 0.0;

	for(int i = 0; i < NUM_ATTRIBUTES; i++)
		sum += pow(a -> getAttribute(i) - b -> getAttribute(i), 2);

	return pow(sum, (float)0.5); //Cast to avoid warnings
}

AnimalSet::AnimalSet(animal* a)
{
	addAnimal(a);
}

void AnimalSet::addAnimal(animal* a)
{
	animals.push_back(a);
}

AnimalSet* AnimalSet::unionSets(AnimalSet* a, AnimalSet* b)
{

}

float AnimalSet::distance(int metric, AnimalSet* a, AnimalSet* b)
{
	switch(metric)
	{
		case 1:
			return minDistance(a,b);
			break;
		case 2:
			return maxDistance(a,b);
			break;
		default:
			return avgDistance(a,b);
	}
}

float AnimalSet::minDistance(AnimalSet* a, AnimalSet* b)
{

}

float AnimalSet::maxDistance(AnimalSet* a, AnimalSet* b)
{

}

float AnimalSet::avgDistance(AnimalSet* a, AnimalSet* b)
{

}
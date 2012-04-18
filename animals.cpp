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

string animal::getName()
{
	return name;
}

float animal::distance(animal* a, animal* b)
{
	float sum = 0.0;

	for(int i = 0; i < NUM_ATTRIBUTES; i++)
		sum += pow(a -> getAttribute(i) - b -> getAttribute(i), 2);

	return pow(sum, (float)0.5); //Cast to avoid warnings
}

AnimalSet::AnimalSet()
{
}

AnimalSet::AnimalSet(animal* a)
{
	addAnimal(a);
}

void AnimalSet::addAnimal(animal* a)
{
	animals.push_back(a);
}

int AnimalSet::setSize()
{
	return (int)animals.size();
}

animal* AnimalSet::animalAtIndex(int index)
{
	if(index >= 0 && index < (int)animals.size())
		return animals[index];
	else
		return NULL;
}

void AnimalSet::print()
{
	for(unsigned long i = 0; i < animals.size(); i++)
		cout << animals[i] -> getName() << endl;
}

AnimalSet* AnimalSet::unionSets(AnimalSet* a, AnimalSet* b)
{
	AnimalSet* newSet = new AnimalSet();

	for(int i = 0; i < a -> setSize(); i++)
		newSet -> addAnimal(a -> animalAtIndex(i));

	for(int i = 0; i < b -> setSize(); i++)
		newSet -> addAnimal(b -> animalAtIndex(i));

	return newSet;
}

float AnimalSet::minDistance(AnimalSet* a, AnimalSet* b)
{
	float dist = FLT_MAX;

	for(int i = 0; i < a -> setSize(); i++)
	{
		for(int j = 0; j < b -> setSize(); j++)
		{
			float distTest = animal::distance(a -> animalAtIndex(i), b -> animalAtIndex(j));

			if(distTest < dist)
				dist = distTest;
		}
	}

	return dist;
}

float AnimalSet::maxDistance(AnimalSet* a, AnimalSet* b)
{
	float dist = FLT_MIN;

	for(int i = 0; i < a -> setSize(); i++)
	{
		for(int j = 0; j < b -> setSize(); j++)
		{
			float distTest = animal::distance(a -> animalAtIndex(i), b -> animalAtIndex(j));

			if(distTest > dist)
				dist = distTest;
		}
	}

	return dist;
}

float AnimalSet::avgDistance(AnimalSet* a, AnimalSet* b)
{
	float dist = 0.0;
	int numAnimals = 0;

	for(int i = 0; i < a -> setSize(); i++)
	{
		for(int j = 0; j < b -> setSize(); j++)
		{
			dist += animal::distance(a -> animalAtIndex(i), b -> animalAtIndex(j));
			numAnimals++;
		}
	}

	return dist/numAnimals;
}
#include <fstream>
#include <vector>
#include <cmath>
#include <cfloat>
#include <iostream>

using namespace std;

const int NUM_ATTRIBUTES = 16; //Does not include name

class animal
{
public:
	animal(ifstream &file);
	float getAttribute(int num);
	string getName();

	static float distance(animal* a, animal* b);

private:
	string name;
	vector<float> attributes;
};

class AnimalSet
{
public:
	AnimalSet();
	AnimalSet(animal* a);

	void addAnimal(animal* a);
	int setSize();
	animal* animalAtIndex(int index);
	void print();

	static AnimalSet* unionSets(AnimalSet* a, AnimalSet* b);
	static float minDistance(AnimalSet* a, AnimalSet* b);
	static float maxDistance(AnimalSet* a, AnimalSet* b);
	static float avgDistance(AnimalSet* a, AnimalSet* b);

private:
	vector<animal *> animals;
};
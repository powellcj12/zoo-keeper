#include <fstream>
#include <vector>
#include <cmath>
#include <cfloat>

using namespace std;

const int NUM_ATTRIBUTES = 16; //Does not include name

class animal
{
public:
	animal(ifstream &file);
	float getAttribute(int num);
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
	static AnimalSet* unionSets(AnimalSet* a, AnimalSet* b);
	static float distance(int metric, AnimalSet* a, AnimalSet* b);

private:
	vector<animal *> animals;

	static float minDistance(AnimalSet* a, AnimalSet* b);
	static float maxDistance(AnimalSet* a, AnimalSet* b);
	static float avgDistance(AnimalSet* a, AnimalSet* b);
};
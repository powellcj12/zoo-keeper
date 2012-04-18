#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

const int NUM_ATTRIBUTES = 16; //Does not include name

class animal
{
public:
	animal(ifstream &file);
	float getAttribute(int num);
	float distance(animal* other);

private:
	string name;
	vector<float> attributes;
};

class AnimalSet
{
public:
	AnimalSet();
	AnimalSet(animal* a);


private:
	vector<animal *> animals;
};
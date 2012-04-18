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

float animal::distance(animal* other)
{
	float sum = 0.0;

	for(int i = 0; i < NUM_ATTRIBUTES; i++)
		sum += pow(attributes[i] - (other -> getAttribute(i)), 2);

	return pow(sum, (float)0.5); //Cast to avoid warnings
}

AnimalSet::AnimalSet()
{

}
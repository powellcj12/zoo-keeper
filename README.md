# Zoo Keeper

## Introduction
Clusters animals together based on a variety of their characteristics using a metric specified by the user upon execution.

## Usage
	make
	./zoo *data_file* *metric* *number_of_clusters*

## Execution
### data_file
Upon execution, the user must specify the data file to use which contains the name and characteristics of all the animals. Each animal should be on its own line and has 17 characteristics including its name. The traits are:

	1. animal name:			Unique string for each instance
	2. has hair	 			Boolean
	3. has feathers	 		Boolean
	4. lays eggs	 		Boolean
	5. produces milk		Boolean
	6. is airborne	 		Boolean
	7. is aquatic	 		Boolean
	8. is a predator		Boolean
	9. is toothed	 		Boolean
	10. has a backbone		Boolean
	11. breathes	 		Boolean
	12. is venomous	 		Boolean
	13. has fins	 		Boolean
	14. number of legs		Numeric (set of values: {0,2,4,5,6,8})
	15. has a tail	 		Boolean
	16. is domestic	 		Boolean
	17. is catsize	 		Boolean

Here is an excerpt from the sample data file provided in the repository:

	kiwi     0 1 1 0 0 0 1 0 1 1 0 0 2 1 0 0
	gnat     0 0 1 0 1 0 0 0 0 1 0 0 6 0 0 0
	crab     0 0 1 0 0 1 1 0 0 0 0 0 4 0 0 0
	sole     0 0 1 0 0 1 0 1 1 0 0 1 0 1 0 0
	scorpion 0 0 0 0 0 0 1 0 0 1 1 0 8 1 0 0
	bear     1 0 0 1 0 0 1 1 1 1 0 0 4 0 0 1
	bass     0 0 1 0 0 1 1 1 1 0 0 1 0 1 0 0
	...etc...

### metric
The user is required to specify how to determine "closeness" of animals to cluster. An n-dimensional distance algorithm is implemented, but there are a variety of ways on how to use this result to cluster animals. Metric is specified as follows:

	1 - **minimum**: distance between two sets is the distance between the two closets elements
	2 - **maximum**: distance between two sets is the distance between the two farthest elements
	3 - **average**: the distance between two sets is the average distance between all pairs of items in the two sets

### number_of_clusters
Lastly, the user must identify how many clusters the animals should end up in.

The clusters are printed to stdout after the program is finished.

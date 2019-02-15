#pragma once
#include <vector>
#include "time.h"

using std::vector;

class Utils {

public:
	template <class T> static vector<T> shuffle(vector<T> input) {
		vector<T> values;
		vector<int> indexes;
		for (int i = 0; i < input.size(); i++) {
			indexes.push_back(i);
		}

		//Seed the random number
		srand(static_cast<unsigned int>(time(NULL)));
		while(!indexes.empty()) {
			//Gets a random index from the currently unused indexes for the input.
			int index = rand() % indexes.size();
			int location = indexes.at(index);

			//Adds the value of the input at the randomly generated location to the new values.
			values.push_back(input.at(location));

			//remove chosen index from the list
			indexes.erase(indexes.begin() + index);
		}

		return values;
	}
};

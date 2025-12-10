#include "day1.h"

const int startPosition = 50;
const int maximumPosition = 100;

struct actionValues {
	bool direction;
	int magnitude;
};

static actionValues actionStringToValues(std::string action) {
	actionValues values;

	values.direction = action.at(0) == 'R' ? true : false;
	values.magnitude = stoi(action.substr(1));

	return values;
}

static int decipherPassword(list<string> actionList) {
	int password = 0;
	int position = startPosition;

	for (string action : actionList) {
		actionValues values = actionStringToValues(action);

		if (values.direction) {
			position = (position + values.magnitude) % maximumPosition;
		}
		else {
			position = (position - values.magnitude) % maximumPosition;
		}

		if (position == 0)
		{
			password++;
		}
	}
	return password;
}

static int RunDay1Challenge(string filePath) {
	ifstream inputFile(filePath);

	if (!inputFile.is_open()) {
		cerr << "Failed to open the file!" << endl;
		return 1;
	}

	list<string> actionList;
	string line;
	while (getline(inputFile, line)) {
		actionList.push_back(line);
	}

	int password = decipherPassword(actionList);
	return password;
}
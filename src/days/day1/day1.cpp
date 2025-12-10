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

static int decipherPassword(list<string> actionList, bool countMidSpinZeros) {
	int password = 0;
	int position = startPosition;

	for (string action : actionList) {
		int originalPosition = position;
		actionValues values = actionStringToValues(action);

		if (values.direction) {
			position = (position + values.magnitude);
		}
		else {
			position = (position - values.magnitude);
		}

		if (countMidSpinZeros) { 
			if (values.direction && position > maximumPosition)
			{
				password++;
				password += floor((float)values.magnitude / (float)(maximumPosition));  //Not sure if this is correct
			}
			else if (!values.direction && position <= 0) {
				password++;
				password += floor((float)values.magnitude / (float)(maximumPosition));
			}
		}


		position %= maximumPosition;

		if (position == 0)
		{
			password++;
		}
	}
	return password;
}

static list<string> actionListFromFile(string filePath) {
	ifstream inputFile(filePath);

	if (!inputFile.is_open()) {
		throw runtime_error("File not found");
	}

	list<string> actionList;
	string line;
	while (getline(inputFile, line)) {
		actionList.push_back(line);
	}

	return actionList;
}

static int RunDay1Challenge1(string filePath) {
	list<string> actionList = actionListFromFile(filePath);

	int password = decipherPassword(actionList, false);
	return password;
}

static int RunDay1Challenge2(string filePath) {
	list<string> actionList = actionListFromFile(filePath);

	int password = decipherPassword(actionList, true);
	return password;
}
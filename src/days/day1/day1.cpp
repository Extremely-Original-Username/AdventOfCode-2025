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

        int magnitude = values.magnitude;
        int direction = values.direction ? +1 : -1;

        int movement = direction * magnitude;

        if (countMidSpinZeros) {
            int steps = abs(movement);
            int stepDir = (movement > 0 ? 1 : -1);

            for (int i = 1; i <= steps; ++i) {
                int intermediate = (originalPosition + stepDir * i) % maximumPosition;
                if (intermediate < 0) intermediate += maximumPosition;

                if (intermediate == 0) {
                    password++;
                }
            }
        }

        position = originalPosition + movement;
        position %= maximumPosition;
        if (position < 0) position += maximumPosition;

        // If final resting position is 0, count that as well
        if (position == 0) {
            //password++;
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
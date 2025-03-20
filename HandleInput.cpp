#include "HandleInput.h"
#include <stdexcept>
#include <cstring>
#include <iostream>

using namespace std;

vector<vector<char>> handleInput(const string& mydata, int &height, int &width) {
	//convert mydata to a char array
	char cstr[mydata.size()+1];
	mydata.copy(cstr, mydata.size()+1);
	cstr[mydata.size()] = '\0';

	//get height and width
	//use different pointer to split the H/W part and the text part
	//because same pointer in the first strtok will truncate the whole string
	char *header = strtok(cstr, "\n");
	char *commaPos = strchr(header, ',');

	// situation that there is no comma in H/W part
	if (!commaPos) {
		throw runtime_error("Invalid Header Format!");
	}

	//make comma be \0 to stop the stoi pointer
	*commaPos = '\0';
	height = stoi(header);
	width = stoi(commaPos + 1);

	vector<vector<char>> matrix;

	if (width > 0 && height > 0) {
		matrix.resize(height, vector<char>(width));
		for (int i = 0; i < height; i++) {
			char *line = strtok(nullptr, "\n");

			//situation that lack rows.
			if (!line) {
				throw runtime_error("Num of Row not Match!");
			}

			//situation that a row has less than expected elements.
			if (strlen(line) != width) {
				throw runtime_error("Incorrect Width at some row!");
			}

			for (int j = 0; j < width; j++) {
				matrix[i][j] = line[j];
			}
		}
	}else {
		throw runtime_error("Invalid Width or Height!");
	}
	return matrix;
}

char** convertToCharArray(const vector<vector<char>>& matrix) {
	if (matrix.empty()) return nullptr;
	int height = matrix.size();
	int width = matrix[0].size();

	char** arr = new char*[height];
	for (int i = 0; i < height; ++i) {
		if (matrix[i].size() != width) {
			for (int j = 0; j < i; ++j) delete[] arr[j];
			delete[] arr;
			throw runtime_error("Inconsistent row width");
		}
		arr[i] = new char[width];
		copy(matrix[i].begin(), matrix[i].end(), arr[i]);
	}
	return arr;
}

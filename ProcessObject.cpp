#include "ProcessObject.h"
#include <sstream>
#include <iomanip>
#include <vector>
#include <iostream>

using namespace std;
void visit(const int Height, const int Width, char **arr, int x, int y, const char P, Object &obj) {
	//basecase: out of bounds
	if (x<0 || x>=Width || y<0 || y>=Height) return;
	//basecase: not an object
	if (arr[y][x]!= 'T') return;

	arr[y][x] = P;
	obj.size ++;
	obj.centerX += x; //x+1 to represent the actual row number
	obj.centerY += y;

	visit(Height, Width, arr, x + 1, y, P, obj);  //right visit
	visit(Height, Width, arr, x - 1, y, P, obj);	 //left visit
	visit(Height, Width, arr, x, y + 1, P, obj);  //down visit
	visit(Height, Width, arr, x, y - 1, P, obj);	 //up visit
}

string ProcessObject(const int Height, const int Width, char **arr, int& objNum) {

	//an object vector to store objects
	vector<Object> objects;
	int objectId = 1;

	//this is for output, I want to generate a integrated string for <pre> output because it easier
	string ObjectInfo;

	//append the height and width to the Info
	ObjectInfo.append("height: " + to_string(Height) + ", width: " + to_string(Width) + "\n");

	//append the original matrix(with T) to the Info
	for (int y = 0; y < Height; y++) {
		for (int x = 0; x < Width; x++) {
			ObjectInfo.push_back(arr[y][x]);
		}
		ObjectInfo.push_back('\n');
	}

	ObjectInfo.append("\n");

	//iterate the matrix, if found T then start visit
	for (int y = 0; y < Height; y++) {

		for (int x = 0; x < Width; x++) {
			if (arr[y][x] == 'T') {
				Object obj{};
				obj.size = 0;
				obj.centerX = 0;
				obj.centerY = 0;
				obj.startX = x;
				obj.startY = y;
				obj.objectId = objectId;

				//visit here, use a conversion int --> char to represent (char)ID
				visit(Height, Width, arr, x, y, ('0'+objectId) , obj);

				obj.centerX = obj.centerX / obj.size;
				obj.centerY = obj.centerY / obj.size;

				objects.push_back(obj);
				objectId++;


			}
		}
	}

	objNum = objects.size();

	//append each object's data to the info
	for (Object obj : objects) {
		ostringstream oss;
		oss << fixed << setprecision(3); // three decimal place
		oss << "Object id " << obj.objectId <<
			   " starts at (" << obj.startX << "," << obj.startY << "), " <<
			   "size: " << obj.size << " chars, " <<
			   "center at (" << obj.centerX << "," << obj.centerY << ")\n";
		ObjectInfo.append(oss.str());
	}

	//append the number of objects to the info
	ObjectInfo.append("Total number of objects: " + to_string(objNum) + "\n");

	ObjectInfo.append("\n");

	//append the processed matrix(with objectIDs) to the info
	for (int y = 0; y < Height; y++) {
		for (int x = 0; x < Width; x++) {
			ObjectInfo.push_back(arr[y][x]);
		}
		ObjectInfo.push_back('\n');
	}

	return ObjectInfo;
}



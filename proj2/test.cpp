#include <cstring>
#include "HandleInput.cpp"
#include "ProcessObject.cpp"

int main() {
	try {
		int height = 0;
		int width = 0;
		string data = "6,7\nBBBBBBB\nBTTBBTB\nBBBBBBB\nBBBTBBB\nBTTTBBB\nBBBBBBB";
		vector<vector<char>> testMatrix = handleInput(data,height,width);
		for (vector<char> c : testMatrix) {
			for (char d: c) {
				cout << d;
			}
			cout << endl;
		}
		cout << "Height is " << height << endl;
		cout << "Width is " << width << endl;

		char** arr = convertToCharArray(testMatrix);

		ProcessObject(height,width,arr);

		if (arr) {
			for (int i = 0; i < height; ++i) {
				delete[] arr[i];
			}
			delete[] arr;
		}


	}catch (runtime_error &e) {
		cerr << e.what() << endl;
	}


}
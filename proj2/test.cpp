#include <cstring>
#include "HandleInput.cpp"
#include "ProcessObject.cpp"
#include "OtherInfo.cpp"

int main() {
	try {
		int height = 0;
		int width = 0;
		int objNum = 0;
		string data = "6,7\nBBBBBBB\nBTTBBTB\nBBBBBBB\nBBBTBBB\nBTTTBBB\nBBBBBBB";
		vector<vector<char>> testMatrix = handleInput(data,height,width);
		char** arr = convertToCharArray(testMatrix);
		cout << data << endl;
		cout << ProcessObject(height,width,arr, objNum) << endl;
		cout << objNum << endl;



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
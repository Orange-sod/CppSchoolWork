#include <cstring>
#include "HandleInput.cpp"
int main() {
	try {
		int height = 0;
		int width = 0;
		string data = "3,4\nAABB\nABAB\nABBA";
		vector<vector<char>> testMatrix = handleInput(data,height,width);
		for (vector<char> c : testMatrix) {
			for (char d: c) {
				cout << d;
			}
			cout << endl;
		}
		cout << "Height is " << height << endl;
		cout << "Width is " << width << endl;
	}catch (runtime_error &e) {
		cerr << e.what() << endl;
	}

}
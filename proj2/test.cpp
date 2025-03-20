#include <cstring>
#include <iostream>
#include "HandleInput.h"
#include "ProcessObject.h"
#include "OtherInfo.h"
#include "HTMLGenerator.h"


using namespace std;
int main() {
	try {
		int height1 = 0;
		int width1 = 0;
		int objNum1 = 0;

		int height2 = 0;
		int width2 = 0;
		int objNum2 = 0;

		string data1 = "6,7\nBBBBBBB\nBTTBBTB\nBBBBBBB\nBBBTBBB\nBTTTBBB\nBBBBBBB";
		vector<vector<char>> testMatrix1 = handleInput(data1,height1,width1);
		char** arr1 = convertToCharArray(testMatrix1);
		string msg1;
		msg1 =  ProcessObject(height1,width1,arr1, objNum1);

		string data2 = "6,8\nBBBBBBBB\nBTTBBTBB\nBBBBBBBB\nBBBTBBBB\nBTTTBBBB\nBBBBBTBB";
		vector<vector<char>> testMatrix2 = handleInput(data2,height2,width2);
		char** arr2 = convertToCharArray(testMatrix2);
		string msg2;
		msg2 =  ProcessObject(height2,width2,arr2, objNum2);

		string testAddr = "C:/Users/Du/CLionProjects/CppSchoolWork/proj2/out.html";
		GenerateHeaders(testAddr);
		string Time = getCurrentDateTime();
		string ip = getUserIP();
		string agent = getUserAgent();
		GenerateSystemInfo(testAddr,Time,ip,agent);
		GenerateOutput(testAddr, objNum1 , objNum2, msg1, msg2);
		GenerateFooters(testAddr, objNum1, objNum2);

		if (arr1) {
			for (int i = 0; i < height1; ++i) {
				delete[] arr1[i];
			}
			delete[] arr1;
		}

		if (arr2) {
			for (int i = 0; i < height2; ++i) {
				delete[] arr2[i];
			}
			delete[] arr2;
		}

	}catch (runtime_error &e) {
		cerr << e.what() << endl;
	}


}
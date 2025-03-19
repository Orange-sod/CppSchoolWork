#include <string>
#include "ProcessObject.h"
#include <iostream>
#include <fstream>

using namespace std;
void GenerateHeaders(const string& outputUrl){//output first, use ios::out
	fstream outputFile(outputUrl,ios::out);
	if (!outputFile.is_open()) {
		throw runtime_error("Error opening output file at Headers");
	}
	outputFile << "<html>\n";
	outputFile << "<head>\n";
	outputFile << "<title>CPS 3525 Project2 Output File Xize Du</title>\n";
	outputFile << "</head>\n";
	outputFile << "<body>\n";
	outputFile << "<h2>CPS 3525 Project2 Output File</h2>\n";
}
void GenerateSystemInfo(const string& outputUrl, const string& date, const string& IP, const string& Agent) {
	fstream outputFile(outputUrl,ios::app);
	if (!outputFile.is_open()) {
		throw runtime_error("Error opening output file at System Info");
	}
	outputFile << "current Date: " << date << "\n<br>";
	outputFile << "User Information from the browser\n<br>";
	outputFile << "IP Address: " << IP << "\n<br>";
	outputFile << "browser/OS: " << Agent << "\n<br>";
}

void GenerateOutput(const string& outputUrl,
					const string& firstInput, const string& secondInput,
					const int& firstCount, const int& secondCount,
					const string& firstMsg, const string& secondMsg) {


}

void GenerateFooters(const string& outputUrl);


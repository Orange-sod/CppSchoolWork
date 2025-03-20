#include <string>
#include <iostream>
#include <fstream>
#include "HTMLGenerator.h"

using namespace std;
void GenerateHeaders(const string& outputUrl){//output first, use ios::out
	cout << outputUrl << endl;
	fstream outputFile(outputUrl,ios::out);
	if (!outputFile.is_open()) {
		throw runtime_error("Error opening output file at Headers");
	}
	outputFile << "<html>\n";
	outputFile << "<head>\n";
	outputFile << "<title>CPS 3525 Project2 Output File Xize Du</title>\n";
	outputFile << "</head>\n";
	outputFile << "<body>\n";
	outputFile << "<h2>CPS 3525 Project2 Output File Xize Du</h2>\n";
	cout << "okay here 1 ";
	outputFile.close();
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
	outputFile.close();
}

void GenerateOutput(const string& outputUrl,
					const int& firstCount, const int& secondCount,
					const string& firstMsg, const string& secondMsg) {
	fstream outputFile(outputUrl,ios::app);
	if (!outputFile.is_open()) {
		throw runtime_error("Error opening output file at System Info");
	}
	outputFile << "The First Text Area: \n<br>";\

	outputFile << "<pre>" << firstMsg << "</pre>\n<br>";

	outputFile << "The Second Text Area: \n<br>";\

	outputFile << "<pre>" << secondMsg << "</pre>\n<br>";



	outputFile.close();
}

void GenerateFooters(const string& outputUrl, const int& firstCount, const int& secondCount) {
	fstream outputFile(outputUrl,ios::app);
	if (!outputFile.is_open()) {
		throw runtime_error("Error opening output file at System Info");
	}

	outputFile << "The first textarea has " << firstCount << " objects, ";
	outputFile << "The second textarea has " << secondCount << " objects. ";
	if (firstCount == secondCount) {
		outputFile << "They have same num of objects\n";
	} else if (firstCount > secondCount) {
		outputFile << "The first textarea has more objects\n";
	}else {
		outputFile << "The second textarea has more objects\n";
	}

	outputFile << "</body>\n";
}


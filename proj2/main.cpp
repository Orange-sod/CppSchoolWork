#include <cstring>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include "HandleInput.h"
#include "ProcessObject.h"
#include "OtherInfo.h"
#include "HTMLGenerator.h"

#include <cgicc/CgiDefs.h>
#include <cgicc/Cgicc.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>
using namespace std;
using namespace cgicc;

int main() {
    string Addr = "../output/output.html";
    Cgicc cgi;
    cout << "Content-type:text/html\r\n\r\n";
    cout << "<html>\n";
    cout << "<head>\n";
    cout << "<title>CPS 3525 Return Web For Project 2</title>\n";
    cout << "</head>\n";
    cout << "<body>\n";

    string firstObj = cgi("firstObject");
    string secondObj = cgi("secondObject");
    
    firstObj.erase(std::remove(firstObj.begin(), firstObj.end(), '\r'), firstObj.end());
    secondObj.erase(std::remove(secondObj.begin(), secondObj.end(), '\r'), secondObj.end());
    

    int height1 = 0;
    int width1 = 0;
    int objNum1 = 0;
    string msg1;

    int height2 = 0;
    int width2 = 0;
    int objNum2 = 0;
    string msg2;
   
    string Time = getCurrentDateTime();
    string ip = getUserIP();
    string agent = getUserAgent();

    try {
        vector<vector<char>> testMatrix1 = handleInput(firstObj,height1,width1);
        char** arr1 = convertToCharArray(testMatrix1);
        msg1 =  ProcessObject(height1,width1,arr1, objNum1);

        vector<vector<char>> testMatrix2 = handleInput(secondObj,height2,width2);
        char** arr2 = convertToCharArray(testMatrix2);
        msg2 =  ProcessObject(height2,width2,arr2, objNum2);

        GenerateHeaders(Addr);
        GenerateSystemInfo(Addr,Time,ip,agent);
        GenerateOutput(Addr, objNum1 , objNum2, msg1, msg2);
        GenerateFooters(Addr, objNum1, objNum2);

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
        cerr << "Runtime error: " << e.what() << endl;
        cerr << e.what() << endl;
    }catch (const exception &e) {
        cerr << "General error: " << e.what() << endl;
        cout << e.what() << "</p>";
    }

    cout << "Process the two textareas and saved successfully\n";

    try {
        int chmodResult = system("chmod 777 /home/student/xdu/public_html/output/output.html");
        if (chmodResult != 0) {
            throw runtime_error("Failed to change file permissions.");
        }
        cout << "<p>File permissions changed successfully for " + Addr + "</p>\n";
    } catch (const exception &e) {
        cerr << "Chmod failed: " << e.what() << endl;
        cout << "<p>Error changing file permissions: " << e.what() << "</p>\n";
    }

    cout << "You can see the output file and message at";
    cout << "<a href = https://obi.kean.edu/~xdu@kean.edu/output/output.html> here </a>\n";
    cout << "</body>\n";
}



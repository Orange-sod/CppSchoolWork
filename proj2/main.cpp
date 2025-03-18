#include <iostream>
#include <fstream>
#include <string>

#include <cgicc/CgiDefs.h>
#include <cgicc/Cgicc.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>
using namespace std;
using namespace cgicc;

int main() {
    string outputUrl = "/home/student/xdu/public_html/output/output.html";
    Cgicc cgi;
    cout << "Content-type:text/html\r\n\r\n";
    cout << "<html>\n";
    cout << "<head>\n";
    cout << "<title>CPS 3525 web form test</title>\n";
    cout << "</head>\n";
    cout << "<body>\n";


    fstream outputFile;

    cout << "You can see the output file and message at";
    cout << "<a href = /home/student/xdu/public_html/output/output.html> here </a>\n";
    cout << "</body>\n";
}



#include <chrono>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <string>
#include <cgicc/CgiDefs.h>
#include <cgicc/Cgicc.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>

using namespace cgicc;
using namespace std;
int main() {
    // output html header
    cout << "Content-type:text/html\r\n\r\n";
    cout << "<html> <head> </head>";

    cout << "<body>";
    cout << "<h1> CPS 3525 project 1 Xize Du </h1><br><br>";

    // restore all the content from HTML as variables
    Cgicc cgi;
    string userName = cgi("name");
    string userGender = cgi("gender");
    //if age is not numbers output error.
    int userAge = 0;
    try {
        userAge = stoi(cgi("age"));
    }catch(const exception &e){
        cout << "<span style = 'color:red'>Error! Your age input is not only numbers! </span>" << endl;
    }
    string dob = cgi("birthday");

    //for courses check them one by one with a vector array
    string courses[] = {"CPS1231","CPS2231","CPS2232","CPS3250"};
    vector<string> classes;
    for(string course : courses) {
       if(cgi(course) == "ON")
           classes.push_back(course);
    }
    string userTown = cgi("town");
    string userData = cgi("mydata");

    //output name, gender, age, birthday
    cout << "<br>Input information" << endl;
    cout << "<br>Name : " << userName << endl;
    cout << "<br>Gender : " << userGender << endl;
    cout << "<br>Age : " << userAge << endl;
    if( userAge > 100 || userAge < 0 )
        cout << "<span style = 'color:red'>Error! age should > 0 and < 100 </span>"<< endl;

    cout << "<br>Birthday : " << dob << endl;
    //check for errors that
    //1: birthday doesn't match age: output the correct age
    //2: birthday 100 years ago: are you more than 100 years old?
    //3: birthday ahead of time : are you from future?

    int yearsBirth = 0;
    int monthsBirth = 0;
    int daysBirth = 0;
    try {
        size_t firstSlash = dob.find_first_of('-');
        size_t lastSlash = dob.find_last_of('-');

        yearsBirth = stoi(dob.substr(0,firstSlash));
        monthsBirth = stoi(dob.substr(firstSlash+1,lastSlash-firstSlash-1));
        daysBirth = stoi(dob.substr(lastSlash+1));

    }catch(const std::exception& e) {
        std::cout << "<span style='color:red'>Error! Invalid birthday format: " << e.what() << "</span><br>"<< endl;
    }


    int yearOld = 2023 - yearsBirth;
    if(yearsBirth <  1923||
            (yearsBirth == 1923 && monthsBirth < 10)||
            (yearsBirth == 1923 && monthsBirth == 10&& daysBirth < 22)) {
        cout << "<br><span style = 'color:red'> Error! Are you more than 100 years old? </span>" << endl;
    }else if(yearsBirth >  2023||
            (yearsBirth == 2023 && monthsBirth > 10)||
            (yearsBirth == 2023 && monthsBirth == 10&& daysBirth > 22)) {
        cout << "<br><span style = 'color:red'> Error! Are you from future? </span>" << endl;
    }else if(userAge != yearOld) {
        cout << "<br><span style = 'color:red'> Error! Your age is not correct!" << endl;
        cout << "It should be: " << yearOld << ", Not "<< userAge << endl ;
        cout << "</span>"<< endl;
    }else{}

    //iterate output class taken
    cout << "<br>Courses selected: "<< endl;
    cout << "<br>";
    for(string aClass : classes) {
        cout << "<li>" << aClass << "</li>"<< endl;
    }

    cout << "<br>Township: " << userTown<< endl;

    cout << "<br> Input String: " << userData << endl;
    //analyzing the string:
    //using for to iterate all characters and store them in a map as key (automatically ordered by ascii)
    //if duplicate the value +=1
    std::map<char,int> dataMap;
    for(int i =0; i < userData.size(); i++) {
        dataMap[userData[i]] ++;
    }

    //output the ascii table
    cout << "<br>"<< endl;
    cout << "<table border='1'>"<< endl;
    cout << "<thead><tr>"<< endl;
    cout << "<th>ASCII #</th><th>Char</th><th>Count</th></tr>"<< endl;
    cout << "</thead>"<< endl;

    cout << "<tbody>";
    //create minOcc, maxOcc for outputing them. determine it in for loop.
    int minOcc = 40; //since the max length of it is 40.
    int maxOcc = 0;
    for(const std::pair<const char, int>& pair : dataMap) {
        char key = pair.first;
        int value = pair.second;
        if(value < minOcc)
            minOcc = value;
        if(value > maxOcc)
            maxOcc = value;
        cout << "<tr>";
        cout << "<td>" << (int)key << "</td>"; //trans to ascii
        cout << "<td>" << key << "</td>";
        cout << "<td>" << value << "</td>";
        cout << "</tr>"<< endl;
    }
    cout << "</table>" << endl;

    cout << "<br> Character:"<< endl;
    for(const std::pair<const char, int>& pair : dataMap) {
        char key = pair.first;
        int value = pair.second;
        if(value == maxOcc)
            cout << key << " ";
    }
    cout << "has maximum count " << maxOcc<< endl;

    cout << "<br> Character:"<< endl;
    for(const std::pair<const char, int>& pair : dataMap) {
        char key = pair.first;
        int value = pair.second;
        if(value == minOcc)
            cout << key << " ";
    }
    cout << "has minimum count " << minOcc<< endl;

    return 0;
}

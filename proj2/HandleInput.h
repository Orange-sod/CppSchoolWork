#ifndef HANDLEINPUT_H
#define HANDLEINPUT_H

#include <vector>
#include <string>

using namespace std;

vector<vector<char>> handleInput(const string& mydata, int &height, int &width);
char** convertToCharArray(const vector<vector<char>>& matrix);
#endif // HANDLEINPUT_H

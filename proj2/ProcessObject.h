
#ifndef PROCESSOBJECT_H
#define PROCESSOBJECT_H
#include <string>

struct Object {
	float centerX;
	float centerY;
	int startX;
	int startY;
	int size;
	int objectId;
};


std::string ProcessObject(const int Height, const int Width, char **arr, int& objNum);

void visit(const int Width, const int Height, char **arr, int x, int y, const char P, Object &obj);

#endif //PROCESSOBJECT_H

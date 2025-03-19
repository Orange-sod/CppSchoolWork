
#ifndef PROCESSOBJECT_H
#define PROCESSOBJECT_H

struct Object {
	float centerX;
	float centerY;
	int startX;
	int startY;
	int size;
	int objectId;
};


string ProcessObject(const int Width, const int Height, char **arr);

void visit(const int Width, const int Height, char **arr, int x, int y, const char P, Object &obj);

#endif //PROCESSOBJECT_H

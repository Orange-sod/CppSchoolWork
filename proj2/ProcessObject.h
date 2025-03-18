
#ifndef PROCESSOBJECT_H
#define PROCESSOBJECT_H

struct Object {
	double centerX;
	double centerY;
	int size;
	int objectId;
};

void ProcessObject(int Widthm, int Height, char** arr);

void visit(const int Width, const int Height, char **arr, int x, int y, const char P, Object &obj);

#endif //PROCESSOBJECT_H

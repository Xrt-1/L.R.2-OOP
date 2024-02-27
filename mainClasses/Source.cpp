#include <iostream>
#include "Class.h"
int main() {
	//Создание векторов
	setlocale(LC_ALL, "rus");
	Vector a(5);
	a.RandomFill();
	Vector b(a);
	b.ReadVector();
	Vector* c = new Vector(5);
	c->ZerosFill();
	c->ReadVector();
	delete c;
	//////////////////////////////////
	Matrix as(5, 2);
	as.ReadMatrix();
	return 0;
}
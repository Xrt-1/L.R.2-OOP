#include "Class.h"

int main() {
	setlocale(LC_ALL, "rus");
	Vector a(5);
	a.RandomFill();
	Vector b(a);
	b.ReadVector();
	Vector* c = new Vector(5);
	c->FillVector();
	c->ReadVector();
	delete c;
	return 0;
}
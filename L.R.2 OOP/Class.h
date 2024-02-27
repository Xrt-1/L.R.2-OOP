#pragma once
#include <iostream>
#include <ctime>

// Сделать класс матриц, рассматривая матрицу как набор векторов. Взаимодействие с классом представить через GUI

class Vector { // добавить метод рандомного заполнения вектора, выборочного заполнения
private:
	int size;
	int* vector;
public:
	Vector() {
		size = 0;
		vector = new int[size];
		printf("Vector()\n");
	}
	Vector(const int size) : size(size) { 
		vector = new int[size];
		printf("Vector(int size)\n"); 
	}
	Vector(const Vector& other) {
		size = other.size;
		vector = new int[size];
		for (int i = 0; i < size; i++) {
			vector[i] = other.vector[i];
		}
		printf("Vector(const Vector& other)\n");
	}
	void FillVector() {

	}
	void RandomFill() {
		srand(time(NULL));
		for (int i = 0; i < size; i++) {
			vector[i] = rand();
		}
		printf("RandomFill(int* & vector)\n");
	}
	~Vector() {
		delete[] vector;
		printf("~Vector()\n");
	}
};

class Matrix {
public:
	int width, high;
	Matrix() : width(0), high(0){
		printf("Matrix()\n");
	}
	Matrix(int w, int h) : width(w), high(h) {
		printf("Matrix(int w, int h)\n");
	}

};
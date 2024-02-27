#pragma once
#include <iostream>
#include <ctime>

// Сделать класс матриц, рассматривая матрицу как набор векторов.

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
	void ZerosFill() {
		for (int i = 0; i < size; i++) {
			vector[i] = 0;
		}
	}
	void RandomFill() {
		srand(time(NULL));
		for (int i = 0; i < size; i++) {
			vector[i] = rand() % 100;
		}
		printf("RandomFill(int* & vector)\n");
	}
	int* GetVector() {
		return vector;
	}
	void ReadVector() {
		std::cout << "[";
		for (int i = 0; i < size; i++) {
			std::cout << vector[i];
			if (i < size - 1) {
				std::cout << ' ';
			}
		}
		std::cout << "]\n";
	}
	~Vector() {
		delete[] vector;
		printf("~Vector()\n");
	}
};


class Matrix {
protected:
	int row, column;
	Vector** matrx;
public:
	//добавить конструктор копирования
	Matrix() : row(1), column(0){
		printf("Matrix()\n");
		matrx = new Vector*[row];
		ZerosFill();
	}
	Matrix(int r, int c) : row(r), column(c) {
		matrx = new Vector*[row];
		printf("Matrix(int r, int c)\n");
		ZerosFill();
	}
	int GetWidth() {
		return row;
	}
	int GetHigh() {
		return column;
	}
	// Что-то не так
	void ReadMatrix() {
		for (int i = 0; i < column; i++) {
			matrx[i]->ReadVector();
 		}
	}
	void ZerosFill() {
		for (int i = 0; i < column; i++) {
			matrx[i]->ZerosFill();
		}
	}
	virtual void RandomFill() {
		for (int i = 0; i < column; i++) {
			matrx[i]->RandomFill();
		}
	}
	~Matrix() {
		printf("~Matrix()\n");
		delete[] matrx;
	}
};

class Square_matrix : public Matrix {
public:
	Square_matrix(){
		printf("Square_matrix()\n");
		row = 1;
		column = 1;
	}
	Square_matrix(int dimension) {
		row = column = dimension;
		printf("Square_matrix(int dimension)\n");
	}
	
	void RandomFill() {
		for (int i=0; i < column; i++) {
		}
	}
};


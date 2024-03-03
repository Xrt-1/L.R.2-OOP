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
		srand(time(NULL));
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
		for (int i = 0; i < size; i++) {
			vector[i] = rand() % 100;
		}
		printf("RandomFillVector()\n");
	}
	int GetValue(int position) {
		return vector[position];
	}
	void SetValue(int position, int value) {
		vector[position] = value;
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
	Matrix() : row(1), column(0){
		printf("Matrix()\n");
		AllocateMemory();
		ZerosFill();
		printf("Matrix()\n");
	}
	Matrix(int r, int c) : row(r), column(c) {
		printf("Matrix(int r, int c)\n");
		AllocateMemory();
		ZerosFill();
		printf("Matrix(int r, int c)\n");
	}
	
	Matrix(Matrix& other) {
		row = other.row;
		column = other.column;
		AllocateMemory();
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				matrx[i]->SetValue(j, (other.matrx[i])->GetValue(j));
			}
		}
		printf("Matrix(Matrix& other)\n");
	}
	int GetWidth() {
		return row;
	}
	int GetHigh() {
		return column;
	}
	void AllocateMemory() {
		matrx = new Vector * [row];
		for (int i = 0; i < row; i++) {
			matrx[i] = new Vector(column);
		}
	}
	void ReadMatrix() {
		for (int i = 0; i < row; i++) {
			matrx[i]->ReadVector();
 		}
	}
	void ZerosFill() {
		for (int i = 0; i < row; i++) {
			matrx[i]->ZerosFill();
		}
	}
	virtual void RandomFill() {
		for (int i = 0; i < row; i++) {
			matrx[i]->RandomFill();
		}
	}
	~Matrix() {
		printf("~Matrix()\n");
		for (int i = 0; i < row; i++) {
			delete matrx[i];
		}
		delete[] matrx;
	}
};


class Square_matrix : public Matrix {
public:
	Square_matrix(){
		printf("Square_matrix()\n");
		row = column = 1;
		AllocateMemory();
		ZerosFill();
	}
	Square_matrix(int dimension) {
		row = column = dimension;
		AllocateMemory();
		ZerosFill();
		printf("Square_matrix(int dimension)\n");
	}
	int GetSum() {
		int sum = 0;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				sum += (matrx[i]->GetVector())[j];
			}
		}
		return sum;
	}
	void RandomFill() override {
		printf("RandomFill() override\n");
	}
	~Square_matrix() {
		printf("~Square_matrix()\n");
	}
	
};


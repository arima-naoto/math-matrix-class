#include "Calculation.h"
#include <Novice.h>

static const int kRowHeight = 20;
static const int kcolumnWidth = 60;

Calculation::Calculation()
{
	m1_ = {
		1.0f,2.0f,
		3.0f,4.0f
	};

	m2_ = {
		5.0f,6.0f,
		7.0f,8.0f,
	};

	v_ = { 10,20 };

	resultAdd_ = {};
	resultSubtract_ = {};
	resultMultiply_ = {};
	resultVector_ = {};

}

void Calculation::MatrixScreenPrintf(int x,int y,Matrix2x2 matrix)
{
	for(int row = 0; row < 2; row++)
	{
		for (int column = 0; column < 2; column++)
		{
			Novice::ScreenPrintf(x + column * kcolumnWidth, y + row * kRowHeight, "%.02f", matrix.m[row][column]);
		}
	}
}

void Calculation::VectorScreenPrintf(int x,int y,Vector2 vector)
{
	Novice::ScreenPrintf(x, y, "%.02f", vector.x);
	Novice::ScreenPrintf(x + kcolumnWidth, y, "%.02f", vector.y);


}

Matrix2x2 Calculation::Add(Matrix2x2 matrix1, Matrix2x2 matrix2) {
	Matrix2x2 result{};
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			result.m[i][j] = matrix1.m[i][j] + matrix2.m[i][j];
		}
	}
	return result;
}

Matrix2x2 Calculation::Subtract(Matrix2x2 matrix1, Matrix2x2 matrix2) {
	Matrix2x2 result{};
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			result.m[i][j] = matrix1.m[i][j] - matrix2.m[i][j];
		}
	}
	return result;
}

Matrix2x2 Calculation::Multiply(Matrix2x2 matrix1, Matrix2x2 matrix2) {
	Matrix2x2 result{};

	result.m[0][0] = matrix1.m[0][0] * matrix2.m[0][0] + matrix1.m[0][1] * matrix2.m[1][0];
	result.m[0][1] = matrix1.m[0][0] * matrix2.m[0][1] + matrix1.m[0][1] * matrix2.m[1][1];
	result.m[1][0] = matrix1.m[1][0] * matrix2.m[0][0] + matrix1.m[1][1] * matrix2.m[1][0];
	result.m[1][1] = matrix1.m[1][0] * matrix2.m[0][1] + matrix1.m[1][1] * matrix2.m[1][1];

	return result;
}

Vector2 Calculation::Multiply(Vector2 vector, Matrix2x2 matrix) {
	Vector2 result{};

	result.x = vector.x * matrix.m[0][0] + vector.y * matrix.m[1][0];
	result.y = vector.x * matrix.m[0][1] + vector.y * matrix.m[1][1];

	return result;

}

void Calculation::Update()
{
	resultAdd_ = Calculation::Add(m1_, m2_);
	resultSubtract_ = Calculation::Subtract(m1_, m2_);
	resultMultiply_ = Calculation::Multiply(m1_, m2_);
	resultVector_ = Calculation::Multiply(v_, m1_);
}

void Calculation::Draw()
{
	Calculation::MatrixScreenPrintf(10, kRowHeight * 0, resultAdd_);
	Calculation::MatrixScreenPrintf(10, kRowHeight * 2 + 10, resultSubtract_);
	Calculation::MatrixScreenPrintf(10, kRowHeight * 4 + 20, resultMultiply_);
	Calculation::VectorScreenPrintf(10, kRowHeight * 6 + 30, resultVector_);

}
#pragma once
#include "Struct.h"

class Calculation
{
public://メンバ関数

	/// <summary>
	/// コンストラクタ
	/// </summary>
	Calculation();

	/// <summary>
	/// 行列の値を表示するメンバ関数
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <param name="matrix"></param>
	void MatrixScreenPrintf(int x, int y, Matrix2x2 matrix);
	
	/// <summary>
	/// ベクトルの値を表示するメンバ関数
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <param name="vector"></param>
	void VectorScreenPrintf(int x, int y, Vector2 vector);

	Matrix2x2 Add(Matrix2x2 matrix1, Matrix2x2 matrix2);
	Matrix2x2 Subtract(Matrix2x2 matrix1, Matrix2x2 matrix2);
	Matrix2x2 Multiply(Matrix2x2 matrix1, Matrix2x2 matrix2);
	Vector2 Multiply(Vector2 vector, Matrix2x2 matrix);

	void Update();

	void Draw();

public://メンバ変数

	Matrix2x2 m1_;
	Matrix2x2 m2_;
	Vector2 v_;

	Matrix2x2 resultAdd_;
	Matrix2x2 resultSubtract_;
	Matrix2x2 resultMultiply_;
	Vector2   resultVector_;

};


#if !defined(_MSC_VER)
#define CODING_VS_CODE
#endif
#include <iostream>
#include<cassert>
#include <array>
#include <math.h>
#if !defined(CODING_VS_CODE)
	#include <clocale>
#endif


using namespace std;

class Triangle {
private:
	double side_a;
	double side_b;
	double side_c;
	unsigned int color;


public:
	void setColor(unsigned int color) {
		assert(color >= 0 && "Color must be greater or equal than 0");
		this->color = color;
	}

	void set3Sides(double side_a, double side_b, double side_c)
	{
		assert((side_a > 0 && side_b > 0 && side_c > 0) && "sides triangle must be a positive numbers");
		
		assert(((side_a + side_b) > side_c) && ((side_a + side_c) > side_b) && ((side_c + side_b) > side_a) && "The sum of the lengths of any two sides of a triangle is greater than the length of the remaining side");
		this->side_a = side_a;
		this->side_b = side_b;
		this->side_c = side_c;



		/*if (side_a > 0 && side_b > 0 && side_c > 0)
		{
			if ((side_a == side_b) && (side_a == side_c))
			{
				this->side_a = side_a;
				this->side_b = side_b;
				this->side_c = side_c;
			}
			else
			{
				double fewerNumber1(side_b);
				double fewerNumber2(side_c);
				double max = side_a;
				
				

				if (max > side_b)
				{
					if (max < side_c)
					{
						max = side_c;
						fewerNumber1 = side_a;
						fewerNumber2 = side_b;
					}
					else
					{
						fewerNumber1 = side_b;
						fewerNumber2 = side_c;
					}
				}
				else
				{
					if (side_b > side_c)
					{
						max = side_b;
						fewerNumber1 = side_a;
						fewerNumber2 = side_c;
					}
					else
					{
						max = side_c;
						fewerNumber1 = side_a;
						fewerNumber2 = side_b;
					}
				}

				cout << "max = " << max << "\n";

				assert(fewerNumber1 + fewerNumber2 > max && "triangle with this sides cannot exist");
				
				if ((fewerNumber1 + fewerNumber2) > max)
				{
					this->side_a = side_a;
					this->side_b = side_b;
					this->side_c = side_c;
				}
				
			}
		}
		else
		{
			assert("sides triangle must be a positive numbers");
		}*/
	}

	unsigned int getColor() {
		return this->color;
	}

	void get3Sides(array<double, 3> &myArray)
	{
		myArray[0] = side_a;
		myArray[1] = side_b;
		myArray[2] = side_c;
	}



	void Init(double side_a, double side_b, double side_c, unsigned int color) {
		setColor(color);
		set3Sides(side_a, side_b, side_c);
	}

	Triangle() : side_a(1.0), side_b(1.0), side_c(1.0), color(0) {};

	Triangle(double side_a, double side_b, double side_c, unsigned int color) {
		Init(side_a, side_b, side_c, color);
	}

	Triangle(double side_a) : Triangle(side_a, 1.0, 1.0, 0) {};
	Triangle(double side_a, double side_b) : Triangle(side_a, side_b, 1.0, 0) {};
	Triangle(double side_a, double side_b, double side_c) : Triangle(side_a, side_b, side_c, 0) {};

	double halfPerimeter() {
		return (this->side_a + this->side_b + this->side_c) / 2;
	}

	double area() {
		double p = halfPerimeter();
		return sqrt(p * ((p - side_a) * (p - side_b) * (p - side_c)));
	}

	double perimeter() {
		return side_a + side_b + side_c;
	}


	void showInfoAboutTriangle() {
		cout << "--------------------\n\tColor = " << this->color << "\n";
		cout << "Sides:\n\tside 1 = " << this->side_a <<
			"\n\tside 2 = " << this->side_b <<
			"\n\tside 3 = " << this->side_c <<
			"\n--------------------\n";
	}


};


int mainExample11(){

	cout << "TASK 1.5 class Rectangle\n";

	cout << endl << "Triangle triangle1(2.0, 5.0, 6.0, 7);\n";
	Triangle triangle1(2.0, 5.0, 6.0, 7);

	cout << "triangle.area()       = " << triangle1.area() << "\n";

	cout << "triangle1.perimeter() = " << triangle1.perimeter() << "\n";

	array<double, 3> myArray;
	triangle1.get3Sides(myArray);
	cout << "Used method : get3Sides(): \n";
	cout << "Sides:\n";
	for (const auto &element : myArray)
	{
		cout << element << " ";
	}

	cout << "\n";

	cout << "Used method : showInfoAboutTriangle()\n";
	triangle1.showInfoAboutTriangle();
	return 1;
}

enum STATE {
	OK, ZERO_VECTOR, NEGATIVE_SIZE, BAD_INIT, BAD_DIV, OUT_OF_RANGE
};


class longVector {
	long quantityElements;
	long *vector;
	int state;
	static int countObject;

public:
	longVector() : vector(nullptr), quantityElements(0), state(ZERO_VECTOR) { countObject++; };
	longVector(int quantityElements);
	longVector(int quantityElements, long& value);
	longVector(int quantityElements, long* InputVector);
	longVector(const longVector& copy);
	longVector& operator=(const longVector& assign);
	~longVector() {
		cout << "\n(DESTRUCTOR)delete vector\n";
		if (vector) {
			delete[] vector;
		}
		--countObject;

	}

	
	void setValueVectorByIndex(int indexVector,const long &element);
	void output();
	void input();

	long getValueVectorByIndex(int indexVector);
	long countLengthOfTheVector(const longVector&);

	bool checkQuantityElements(int quantityElements);
	bool isIndexIncludedVector(int indexVector);
	bool isEmptyVector(const longVector* object);
	

	bool isEqual(const longVector&);
	bool isSmaller(const longVector&);
	bool isGreater(const longVector&);

	longVector add(longVector& inputVector);
	longVector subtract(longVector& inputVector);
	longVector multiplyVectorOnUnsignedInt(unsigned int number);

	static int getCountObject() {
		return countObject;
	}
};
 
 int longVector::countObject = 0;



longVector::longVector(int quantityElements) {
	if(checkQuantityElements(quantityElements))
	{
		vector = new long[quantityElements];
		for (int i = 0; i < quantityElements; i++)
		{
			vector[i] = 0;
		}
	}
		countObject++;
	
//	fill_n(0, quantityElements, 0);
}

longVector::longVector(int quantityElements, long& value) {
	if (checkQuantityElements(quantityElements))
	{
		vector = new long[quantityElements];
		for (int i = 0; i < quantityElements; i++)
		{
			vector[i] = value;
		}
	}
	countObject++;
	
}

longVector::longVector(int quantityElements, long* inputVector) {
	if (quantityElements <= 0 || (inputVector == nullptr))
	{
		vector = nullptr;
		quantityElements = 0;
		state = ZERO_VECTOR;
		cout << "Vector was not created: quantity <= 0";
	}
	else
	{
		this->quantityElements = quantityElements;
		state = OK;
	}

	
	vector = new long[quantityElements];
	for (int i = 0; i < quantityElements; i++)
	{
		vector[i] = inputVector[i];
	}

	countObject++;
}

longVector::longVector(const longVector& inputCopy) {
	this->quantityElements = inputCopy.quantityElements;
	vector = new long[quantityElements];
	
	for (int i = 0; i < quantityElements; i++)
	{
		vector[i] = inputCopy.vector[i];
	}

	state = OK;

	countObject++;
}

longVector& longVector::operator= (const longVector& assign) {
	if (quantityElements != assign.quantityElements)
	{
		if (vector)
		{
			delete[] vector;
		}
		quantityElements = assign.quantityElements;
		vector = new long[quantityElements];
		state = OK;
	}

	for (int i = 0; i < quantityElements; i++)
	{
		vector[i] = assign.vector[i];
	}
	
	return *this;
}

bool longVector::checkQuantityElements(int quantityElements)
{
	if (quantityElements <= 0)
	{
		vector = nullptr;
		this->quantityElements = 0;
		state = ZERO_VECTOR;
		cout << "Vector was not created(nullptr): quantity <= 0";
		return false;
	}
	else
	{
		this->quantityElements = quantityElements;
		state = OK;
		return true;
	}
}

bool longVector::isEmptyVector(const longVector* object) {
	if (object->quantityElements <= 0)
	{
		cout << "!ERROR: Array is empty\n";
		return true;
	}
	else
	{
		return false;
	}
}

bool longVector::isIndexIncludedVector(int indexVector) {
	if ((indexVector >= 0) && (indexVector <= this->quantityElements - 1))
	{
		return true;
	}
	else
	{
		state = OUT_OF_RANGE;
		cout << "!ERROR: Array index is out of range\n";
		return false;
	}
}


bool longVector::isEqual(const longVector& vec1) {
	return (countLengthOfTheVector(vec1) == countLengthOfTheVector(*this));
}

bool longVector::isSmaller(const longVector& vec1) {
	return (countLengthOfTheVector(vec1) < countLengthOfTheVector(*this));
}

bool longVector::isGreater(const longVector& vec1) {
	return (countLengthOfTheVector(vec1) > countLengthOfTheVector(*this));
}


void longVector::setValueVectorByIndex(int indexVector, const long& element)
{
	if (isIndexIncludedVector(indexVector) && !isEmptyVector(this))
	{
		vector[indexVector] = element;
	}
	else
	{
		cout << "Incorrect index\n";
	}

}


void longVector::input() {
	if (vector)
	{
		delete[] vector;
	}
	do
	{
		cout << "Input non-zero size the VECTOR:\n";
		cin >> quantityElements;
	} while (quantityElements <= 0);

	vector = new long[quantityElements];

	for (int i = 0; i < quantityElements; i++)
	{
		cout << "Input a long element the vector[" << i << "]: ";
		cin >> vector[i];
		cout << "\n";
	}
}

long longVector::getValueVectorByIndex(int indexVector)
{
	if (isIndexIncludedVector(indexVector) && !isEmptyVector(this))
	{
		return vector[indexVector];
	}
	else
	{
		cout << "Returned 0\n";
		return 0;
	}
}

void longVector::output() {
	cout << "Information about vector:\n";
	if (quantityElements != 0)
	{
		for (int i = 0; i < quantityElements; i++)
		{
			cout << "\tElement vector[" << i << "] = " << vector[i] << "\n";
		}
	}
	else
	{
		cout << "\tEmpty vector\n";
	}
}

long longVector::countLengthOfTheVector(const longVector& vector1) {
	long suma = 0;
	for (int i = 0; i < vector1.quantityElements; i++)
	{
		suma += vector1.vector[i];
	}
	return suma;
}


longVector longVector::add(longVector& inputVector) {
	int leastQuantityOfVectors = quantityElements < inputVector.quantityElements ? quantityElements : inputVector.quantityElements;
	if (leastQuantityOfVectors >= 0)
	{
		longVector total(leastQuantityOfVectors);
		total.quantityElements = leastQuantityOfVectors;
		for (int i = 0; i < leastQuantityOfVectors; i++)
		{
			total.vector[i] = vector[i] + inputVector.vector[i];
		}
		return total;
	}
	else
	{
		cout << "Returned empty vector\n";
		return longVector(0);
	}
}

longVector longVector::subtract(longVector& inputVector) {
	int leastQuantityOfVectors = quantityElements < inputVector.quantityElements ? quantityElements : inputVector.quantityElements;
	if (leastQuantityOfVectors >= 0)
	{
		longVector total(leastQuantityOfVectors);
		for (int i = 0; i < leastQuantityOfVectors; i++)
		{
			total.vector[i] = vector[i] - inputVector.vector[i];
		}
		return total;
	}
	else
	{
		cout << "Returned empty vector\n";
		return longVector(0);
	}
}

longVector longVector::multiplyVectorOnUnsignedInt(unsigned int number)
{
	if (!isEmptyVector(this))
	{
		longVector temp(quantityElements);
		for (int i = 0; i < quantityElements; i++)
		{
			temp.vector[i] = vector[i] * number;
		}
		return temp;
	}
	else
	{
		cout << "Returned empty vector\n";
		return longVector(0);
	}
	
}


int mainExample22() {
	cout << "\nTASK 2.5:\n";
	long value1 = 4;
	long value2 = 7;

	cout << endl << "longVector vector1(3, 4);" << endl;
	longVector vector1(3, value1);
	vector1.output();
	
	cout << endl << "longVector vector2(7, 7);" << endl;
	longVector vector2(7, value2);
	vector2.output();

	cout << endl << "long long_arr[4] = {32,2,10,-2};\nlongVector vector3(4, long_arr);" << endl;
	long long_arr[4] = {32,2,10,-2};
	longVector vector3(4, long_arr);
	vector3.output();

	cout << endl << "longVector vectorAdd = vector1.add(vector2);" << endl;
	longVector vectorAdd = vector1.add(vector2);
	vectorAdd.output();

	cout << endl << "longVector vectorSubtract = vector1.subtract(vector2);" << endl;
	longVector vectorSubtract = vector1.subtract(vector2);
	vectorSubtract.output();

	cout << endl << "longVector multiply = vector2.multiplyVectorOnUnsignedInt(2);" << endl;
	longVector multiply = vector2.multiplyVectorOnUnsignedInt(2);
	multiply.output();
	
	cout << endl << "vector1.setValueVectorByIndex(2, 23)" << endl;
	vector1.setValueVectorByIndex(2, 23);
	vector1.output();

	cout << endl << "vector1.getValueVectorByIndex(2)" << endl;
	cout << vector1.getValueVectorByIndex(2);

	cout << endl << "count objects : "<< longVector::getCountObject();
	cout << endl << "vector1.isEqual(vector2);" << endl;
	if (vector1.isEqual(vector2))
	{
		cout << "TRUE";
	}
	else
	{
		cout << "FALSE";
	}

	cout << endl << "vector1.isEqual(vector1);" << endl;
	if (vector1.isEqual(vector1))
	{
		cout << "TRUE";
	}
	else
	{
		cout << "FALSE";
	}


	cout << endl << "vector1.isGreater(vector2);" << endl;
	if (vector1.isGreater(vector2))
	{
		cout << "TRUE";
	}
	else
	{
		cout << "FALSE";
	}

	
	cout << endl << "vector1.isSmaller(vector2);" << endl;
	if (vector1.isSmaller(vector2))
	{
		cout << "TRUE";
	}
	else
	{
		cout << "FALSE";
	}

	

	//cout << "TASK 1.5 class Rectangle\n";

	//cout << "triangle.area()       = " << triangle1.area() << "\n";

	//cout << "triangle1.perimeter() = " << triangle1.perimeter() << "\n";

	//array<double, 3> myArray;
	//triangle1.get3Sides(myArray);
	//cout << "Used method : get3Sides(): \n";
	//cout << "Sides:\n";
	//for (const auto& element : myArray)
	//{
	//	cout << element << " ";
	//}

	//cout << "\n";

	//cout << "Used method : showInfoAboutTriangle()\n";
	//triangle1.showInfoAboutTriangle();
	return 1;
}



class Matrix {
private:
	int** matrix = nullptr;
	int row;
	int col;

public:
	Matrix();
	Matrix(int size);
	Matrix(int row, int col, int value);
	Matrix(const Matrix& copy);
	Matrix& operator=(const Matrix& assign);
	Matrix operator+(const Matrix& addition);
	Matrix operator-(const Matrix&);
	Matrix operator*(const Matrix&);
	Matrix operator*(const short scalar);
	~Matrix() {
		cout << "DESTRUCT" << endl;
		for (int count = 0; count < row; ++count)
		{
			delete[] matrix[count];
		}
		delete[] matrix;
	}

	int getElementMatrix(int row, int col);

	bool isIndexIncludedMatrix(int row, int col);

	void setElementMatrix(int row, int col, int value);
	void showInfoAboutMatrix();
};

Matrix::Matrix(): Matrix(3, 3, 0) {}
Matrix::Matrix(int size): Matrix(size, size, 0) {
	assert(size >= 0 && "size must be > 0");
}

Matrix::Matrix(int row, int col, int value) {
	assert((row > 0  || col > 0) && "row, col must be > 0");

	this->row = row;
	this->col = col;
	matrix = new int* [row];
	for (int count = 0; count < row; ++count)
	{
		matrix[count] = new int[col];
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			matrix[i][j] = value;
		}
	}

}

Matrix::Matrix(const Matrix& copy)
{
	if (this == &copy) return;
	row = copy.row;
	col = copy.col;
	matrix = new int* [row];
	for (int count = 0; count < row; ++count)
	{
		matrix[count] = new int[col];
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			matrix[i][j] = copy.matrix[i][j];
		}
	}
}

Matrix& Matrix::operator=(const Matrix& assign) {
	if (row != assign.row || col != assign.col)
	{
		for (int count = 0; count < row; ++count)
		{
			delete[] matrix[count];
		}
		delete[] matrix;

		row = assign.row;
		col = assign.col;
		matrix = new int* [row];
		for (int count = 0; count < row; ++count)
		{
			matrix[count] = new int[col];
		}
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			matrix[i][j] = assign.matrix[i][j];
			cout << this->matrix[i][j] << " ";
		}
	}

	return *this;
}

Matrix Matrix::operator+(const Matrix& addition) {
	if (row == addition.row && col == addition.col)
	{
		Matrix temp(row, col, 0);

		for (int i = 0; i < temp.row; i++)
		{
			for (int j = 0; j < temp.col; j++)
			{
				temp.matrix[i][j] = matrix[i][j] + addition.matrix[i][j];
			}
		}
		return temp;
	}
	else
	{
		cout << endl << "Matriсes have different sizes" << endl;
		cout << "will be returned zero matrix[1][1]" << endl;
		Matrix zeroMatrix(1);
		return zeroMatrix;
	}
}

Matrix Matrix::operator-(const Matrix& subtract) {
	if (row == subtract.row && col == subtract.col)
	{
		Matrix temp(row, col, 0);

		for (int i = 0; i < temp.row; i++)
		{
			for (int j = 0; j < temp.col; j++)
			{
				temp.matrix[i][j] = matrix[i][j] + subtract.matrix[i][j];
			}
		}
		return temp;

	}
	else
	{
		cout << endl << "Matriсes have different sizes" << endl;
		cout << "will be returned zero matrix[1][1]" << endl;
		Matrix zeroMatrix(1);
		return zeroMatrix;
	}
}

Matrix Matrix::operator*(const Matrix& multiply) {
	if (col == multiply.row)
	{
		Matrix temp(row, multiply.col, 0);

		for (int i = 0; i < temp.row; i++)
		{
			for (int j = 0; j < temp.col; j++)
			{
				for (int inner = 0; inner < col; inner++)
				{
					temp.matrix[i][j] += matrix[i][inner] * multiply.matrix[inner][j];
				}
				
			}
		}
		return temp;

	}
	else
	{
		cout << endl << "Matriсes cannot be multiply" << endl;
		cout << "will be returned zero matrix[1][1]" << endl;
		Matrix zeroMatrix(1);
		return zeroMatrix;
	}
}


Matrix Matrix::operator*(const short scalar) {
	Matrix temp(row, col, 0);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			temp.matrix[i][j] += matrix[i][j] * scalar;
		}
	}
	return temp;
 }

bool Matrix::isIndexIncludedMatrix(int row, int col) {
	if ( (row >= 0) && ( row < this->row ) && (col >= 0) && (col < this->col) )
	{
		return true;
	}
	else
	{
		cout << endl << "!ERROR: Array index is out of range\n";
		return false;
	}
}

void Matrix::setElementMatrix(int row, int col, int value = 0) {
	if (isIndexIncludedMatrix(row, col))
	{
		matrix[row][col] = value;
	}
}

int Matrix::getElementMatrix(int row, int col) {
	assert(isIndexIncludedMatrix(row, col));
	return matrix[row][col];
}



void Matrix::showInfoAboutMatrix() {
	for (int i = 0; i < row; i++)
	{	
		cout << endl;
		for (int j = 0; j < col; j++)
		{
			cout << matrix[i][j] << " ";
		}
	}
	cout << endl;
}

int mainExample33(){
	cout << "\tStart TASK 3.5\n";
	cout << endl << "Matrix defaultMatrix; /// defaultMatrix.showInfoAboutMatrix();";	
	Matrix defaultMatrix;
	defaultMatrix.showInfoAboutMatrix();

	cout << endl << "Matrix matrix1(2,3,5);\nmatrix1.showInfoAboutMatrix();";
	Matrix matrix1(2,3,5);
	matrix1.showInfoAboutMatrix();

	cout << endl << "Matrix matrix2(3,2,2);\nmatrix1.showInfoAboutMatrix();";
	Matrix matrix2(3,2,2);
	matrix2.showInfoAboutMatrix();

	matrix1.setElementMatrix(1, 0, 3);
	cout << endl << "matrix1.setElementMatrix(1, 0, 3);\nmatrix1.showInfoAboutMatrix()";
	matrix1.showInfoAboutMatrix();

	cout << endl << "/// defaultMatrix.getElementMatrix(2,1) -> ";
	cout << matrix1.getElementMatrix(1, 0) << endl;


	cout << endl << "Matrix assign = matrix1;\nassign1.showInfoAboutMatrix(); ";
	Matrix assign = matrix1;
	assign.showInfoAboutMatrix();

	cout << endl << "Matrix addition = assign + matrix1;\naddition.showInfoAboutMatrix();";
	Matrix addition = assign + matrix1;
	addition.showInfoAboutMatrix();

	cout << endl << "Matrix multiply = matrix1 * matrix2;\multiply.showInfoAboutMatrix();";
	Matrix multiply = matrix1 * matrix2;
	multiply.showInfoAboutMatrix();

	cout << endl << "Matrix multiplyScalar = matrix1 * 2;;\multiplyScalar.showInfoAboutMatrix();";
	Matrix multiplyScalar = matrix1 * 3;
	multiplyScalar.showInfoAboutMatrix();

	return 1;
}

////////////////////////////////////////////////

//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused


class MatrixRow {

private:
	int *elements;

public:
	MatrixRow(int n);
	~MatrixRow();

	int& operator[](int);

};


MatrixRow::MatrixRow(int n) {
	elements = new int [n];
}

MatrixRow::~MatrixRow() {
	delete [] elements;
}

int& MatrixRow::operator[](int i) {
	return elements[i];
}




class Matrix {


private:

	MatrixRow **matrixRows;
	int rows,cols;


	
public:

	// CONSTRUCTOR and DISTRUCTOR
	Matrix(int rows, int cols);
	~Matrix();


	// Members
	MatrixRow& operator[](int);

};

Matrix::Matrix(int rrows, int ccols) {

	rows = rrows;
	cols = ccols;

	#ifdef MatrixDebug
		cout << "Matrix::Matrix(int rrows, int ccols)" << endl;
	#endif

	matrixRows = new MatrixRow * [rows];
	for(register int i=0 ; i < rows ; i++)
		matrixRows[i] = new MatrixRow(cols);
}

Matrix::~Matrix() {

	#ifdef MatrixDebug
		cout << "Matrix::~Matrix()" << endl;
	#endif

	for(register int i= rows - 1 ; i>=0 ; i--)
		delete matrixRows[i];

	delete [] matrixRows;
}

MatrixRow& Matrix::operator[](int i) {
	return *matrixRows[i];
}


int main(int argc, char* argv[])
{
	return 0;
}
//---------------------------------------------------------------------------

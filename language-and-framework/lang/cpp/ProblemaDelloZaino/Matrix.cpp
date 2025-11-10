//---------------------------------------------------------------------------


#pragma hdrstop

#include "Matrix.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)



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

// DEBUG
void Matrix::dump(char *msg) {
	cout << endl << "*** Class Matrix: " << msg << endl;
	for (int i = 0; i < rows; i++) {
		cout << "[" << i << "]\t";
		for (int j = 0; j < cols; j++) {
			cout << (*matrixRows[i])[j] << "\t";
		}
		cout << endl;
	}
	cout << "******" << endl << endl;
}


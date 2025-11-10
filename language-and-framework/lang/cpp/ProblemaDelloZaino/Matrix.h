//---------------------------------------------------------------------------

#ifndef MatrixH
#define MatrixH

#undef MatrixDebug


#include <iostream.h>

#include "MatrixRow.h"

//---------------------------------------------------------------------------



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


	// DEBUG
	void dump(char *msg = "");

};



#endif

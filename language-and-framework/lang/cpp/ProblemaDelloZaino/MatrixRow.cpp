//---------------------------------------------------------------------------


#pragma hdrstop

#include "MatrixRow.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

MatrixRow::MatrixRow(int n) {
	elements = new int [n];
}

MatrixRow::~MatrixRow() {
	delete [] elements;
}

int& MatrixRow::operator[](int i) {
	return elements[i];
}


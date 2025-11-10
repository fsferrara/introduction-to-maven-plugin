//---------------------------------------------------------------------------

#ifndef MatrixRowH
#define MatrixRowH
//---------------------------------------------------------------------------


class MatrixRow {

private:
	int *elements;

public:
	MatrixRow(int n);
	~MatrixRow();

	int& operator[](int);

};

#endif

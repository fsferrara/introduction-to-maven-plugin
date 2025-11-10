//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <iostream.h>

//---------------------------------------------------------------------------

#pragma argsused

void delimts()
{
	cout << endl
		 << "=========================================="
		 << endl;
}

int main(int argc, char* argv[])
{
	delimts();

	char c;
	cout << "sizeof(char) = " << sizeof(c) << endl;
	cout << "CHAR_BIT: " << CHAR_BIT << endl;
	cout << "SCHAR_MIN: " << SCHAR_MIN << endl;
	cout << "SCHAR_MAX: " << SCHAR_MAX << endl;
	delimts();

	unsigned char cu;
	cout << "sizeof(unsigned char) = " << sizeof(cu) << endl;
	cout << "CHAR_BIT: " << CHAR_BIT << endl;
	cout << "UCHAR_MAX: " << UCHAR_MAX << endl;
	delimts();

	int i;
	cout << "sizeof(int) = " << sizeof(i) << endl;
	cout << "INT_MIN: " << INT_MIN << endl;
	cout << "INT_MAX: " << INT_MAX << endl;
	delimts();

	unsigned int iu;
	cout << "sizeof(unsigned int) = " << sizeof(iu) << endl;
	cout << "UINT_MAX: " << UINT_MAX << endl;
	delimts();

	short int is;
    short iis; // is the same of short int
	cout << "sizeof(short int) = " << sizeof(is) << endl;
	cout << "SHRT_MIN: " << SHRT_MIN << endl;
	cout << "SHRT_MAX: " << SHRT_MAX << endl;
	delimts();

	unsigned short int isu;
	unsigned short iisu; // is the same of unsigned short int
	cout << "sizeof(unsigned short int) = " << sizeof(isu) << endl;
	cout << "USHRT_MAX: " << USHRT_MAX << endl;
	delimts();

	long int il;
	long iil; // is the same of long int
	cout << "sizeof(long int) = " << sizeof(il) << endl;
	cout << "LONG_MIN: " << LONG_MIN << endl;
	cout << "LONG_MAX: " << LONG_MAX << endl;
	delimts();

	unsigned long int ilu;
	unsigned long iilu;
	cout << "sizeof(unsigned long int) = " << sizeof(ilu) << endl;
	cout << "ULONG_MAX: " << ULONG_MAX << endl;
	delimts();

	float f;
	cout << "sizeof(float) = " << sizeof(f) << endl;
	delimts();

	double d;
	cout << "sizeof(double) = " << sizeof(d) << endl;
	delimts();

	long double dl;
	cout << "sizeof(long double) = " << sizeof(dl) << endl;
	delimts();


	return 0;
}
//---------------------------------------------------------------------------

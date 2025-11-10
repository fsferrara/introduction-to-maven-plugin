//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <iostream.h>
#include "FooLibrary.cpp"
//---------------------------------------------------------------------------

// Global variable
int global = 0;

#pragma argsused
int main(int argc, char* argv[])
{
	global = 22;
	cout << "Before global = " << global << endl;

	foo();

	cout << "After global = " << global << endl;

	return 0;
}
//---------------------------------------------------------------------------

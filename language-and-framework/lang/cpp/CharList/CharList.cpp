//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <iostream.h>

//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
	static int COLS = 3;


	int currentCol = COLS;
	for (int i=0; i <= 128; i++) {
		if ((i != 10) && (i != 9)) {
			cout << "\t[" << i << "]\t" << char(i);
			currentCol--;

			if (currentCol <= 0) {
				cout << endl;
				currentCol = COLS;
			}
			else {
				cout << "\t";
			}
		}
	}
	
	return 0;
}
//---------------------------------------------------------------------------

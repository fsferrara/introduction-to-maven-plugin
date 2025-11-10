#include <stdio.h>
#include <fftw3.h>


int main(int argc, char *argv[]) {

	fftw_plan p;
	fftw_complex *in;
	fftw_complex *out;
	int n=7;
	int i;

	
	in = fftw_malloc(n * sizeof(fftw_complex));
	out = fftw_malloc(n * sizeof(fftw_complex));

	in[0][0] = 36;
	in[1][0] = -4;
	in[2][0] = -4;
	in[3][0] = -4;
	in[4][0] = -4;
	in[5][0] = -4;
	in[6][0] = -4;
	in[0][1] = 0;
	in[1][1] = -9.6569;
	in[2][1] = -4;
	in[3][1] = -1.6569;
	in[4][1] = 1.6569;
	in[5][1] = 4;
	in[6][1] = 9.6569;
	
	p = fftw_plan_dft_1d(n, in, out, FFTW_FORWARD, FFTW_ESTIMATE);
	fftw_execute(p);
	fftw_destroy_plan(p);

	printf("\nStampa del primo risultato : \n");
	for (i=0 ; i<n ; i++) {
		printf("%lf , %lf * i\n", out[i][0], out[i][1]);
		in[i][0] = in[i][0] * 2;
		in[i][1] = in[i][1] * 2;
	}
	
	
	p = fftw_plan_dft_1d(n, in, out, FFTW_FORWARD, FFTW_ESTIMATE);
	fftw_execute(p);
	fftw_destroy_plan(p);

	printf("\n\nStampa del secondo risultato : \n");
	for (i=0 ; i<n ; i++) {
		printf("%lf , %lf * i\n", out[i][0], out[i][1]);
	}
	

	
	fftw_free(in);
	fftw_free(out);
}


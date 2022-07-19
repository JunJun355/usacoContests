/*
ID: 06jajun
TASK: kimbits
LANG: C
*/
// stolen from their analysis
// !! look back at this cus it's faster but idk why !!
// Theirs is recursive but mine is iterative. That might be why.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

FILE *fout;

/* calculate binomial coefficient (n choose k) */
double sizeofset[33][33];

void
initsizeofset(void)
{
	int i, j;

	for(j=0; j<=32; j++)
		sizeofset[0][j] = 1;

	for(i=1; i<=32; i++)
	for(j=0; j<=32; j++)
		if(j == 0)
			sizeofset[i][j] = 1;
		else
			sizeofset[i][j] = sizeofset[i-1][j-1] + sizeofset[i-1][j];
}

void
printbits(int nbits, int nones, double index)
{
	double s;

	if(nbits == 0)
		return;

	s = sizeofset[nbits-1][nones];
	if(s <= index) {
		fprintf(fout, "1");
		printbits(nbits-1, nones-1, index-s);
	} else {
		fprintf(fout, "0");
		printbits(nbits-1, nones, index);
	}
}

void
main(void)
{
	FILE *fin;
	int nbits, nones;
	double index;

	fin = fopen("kimbits.in", "r");
	fout = fopen("kimbits.out", "w");
	assert(fin != NULL && fout != NULL);

	initsizeofset();
	fscanf(fin, "%d %d %lf", &nbits, &nones, &index);
	printbits(nbits, nones, index-1);
	fprintf(fout, "\n");

	exit(0);
}

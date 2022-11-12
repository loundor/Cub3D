#include <stdio.h>
#include <math.h>

int main(void)
{
	float f = 860.423423;
	float  i = ((int)f >> 1)<<1;
	printf("%f\n", i);
	i = (((int)f >> 1)<<1) / 1; //1
	printf("1 - %f\n", i);
	i = (((int)f >> 2) << 2) / 1; //2
	printf("2 - %f\n", i);
	i = (((int)f >> 3) << 3) / 1; // 4
	printf("3 - %f\n", i);
	i = (((int)f >> 4) << 4) / 1; // 8
	printf("4 - %f\n", i);
	i = (((int)f >> 5) << 5) / 1; // 16
	printf("5 - %f\n", i);
	i = (((int)f >> 6) << 6) / 1; // 32
	printf("6 - %f\n", i);
	i = (((int)f >> 7) << 7) / 1; //64
	printf("7 - %f\n", i);
	return 0;
}
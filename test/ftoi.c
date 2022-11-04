#include <stdio.h>
#include <math.h>

int main(void)
{
	float f = 128.000;
	float  i = (int)f >> 6;

	printf("%f\n", i);
	return 0;
}
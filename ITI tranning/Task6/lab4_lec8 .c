#include <stdio.h>
#include "STD_TYPES.h"

int main()
{
	typedef struct
	{
		u16  x;
		u32  y;
		u16  z;
		u32  k;
	}mystruct;
	
	printf("Size of sturct is %d", sizeof(mystruct));
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>



#define GET_CLK_EN(reg) (reg & 0x03)
#define SET_CLK_EN(reg, x) reg = (reg & (0x03)) | (x & (0x03))

#define GET_CLK_PRE(reg)   ((reg>>2)&6)
#define SET_CLK_PRE(reg,x) reg=(reg&(~0x7FFF<<2))|((x&0x7FFF) << 2)


#define GET_CLK_SRC(reg)   ((reg>>17)&0x7FFF)
#define SET_CLK_SRC(reg,x) reg=(reg&(~0x7FFF<<17))|((x&0x7FFF) << 17)

#define TYPE_CLK 8
#define BIT 1
#define BYTE 8
int32_t CLK = 0;

int32_t displayBit(int32_t input, int32_t count)
{
	int32_t countBit_1 = 0;

	for(int i = 0; i < count; i++)
	{
		if((input >> (31 & count ) - 1 - i) & (0x1))
		{
			printf ("1");
			countBit_1++;
		}
		else
		{
			printf ("0");
		}
	}

	printf("\n***************************\n");
	return countBit_1;
}

void countBit1

void swap(int32_t pInput, int32_t mode)
{
	int32_t tempInput;
	for(int i = 0 ;i < 32/mode; i++)
	{
 		tempInput = tempInput | (pInput >> (mode * i))&(~(0xFFFFFFFF << mode)));
 		if(i == 32/mode -1 )
 		{
 			pInput = tempInput;
 			return pInput;
 		}
 		else
 		{
 			tempInput <<= mode;
 		}
	}
}


int main()
{	

	int32_t CLK = 0;
	int32_t countBit_1;
	displayBit(CLK, TYPE_CLK);
	SET_CLK_PRE(CLK, 3);
	countBit_1 = displayBit(CLK,TYPE_CLK);
	printf("countbit %d\n", countBit_1);


	return 0;
}
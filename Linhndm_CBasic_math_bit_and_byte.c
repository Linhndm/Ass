#include <stdio.h>
#include <stdint.h>

#define BIT 1
#define BYTE 8

#define DEBUG 0

#if defined(DEBUG) && (DEBUG)
	#define PRINTF  printf
#else
	#define PRINTF
#endif

#define GET_CLK_EN(reg)     (reg & 0x03)
#define SET_CLK_EN(reg, x)    reg = (reg & (~0x03)) | (x &0x03)

#define GET_CLK_PRE(reg)    ((reg >> 2) & 0x7fff)
#define SET_CLK_PRE(reg, x)   reg = (reg & ~(0x7fff << 2)) | ((x & 0x7fff) << 2)

#define GET_CLK_SRC(reg)    ((reg >> 17) & 0x7fff)
#define SET_CLK_SRC(reg, x)   reg = (reg & ~(0x7fff << 17)) | ((x & 0x7fff) << 17)

int32_t dislayBit(int32_t input, int32_t count)
{
	printf("0b");
	int i = 0;
	int32_t countBit1 = 0;
	for (i = 0; i < count; ++i)
	{
		if ((input >> ((count & 31) - 1 - i))&1)/*deo hieu cho nay*/
		{
			printf("1");
			countBit1++;
		}
		else
		{
			printf("0");
		}
	}
	printf("\n");
	return countBit1;
}

int32_t countBit(int32_t input)
{

}
int32_t swap(int32_t input, int32_t mode)
{
	int32_t tempInput = 0;
	for (int i = 0; i < (32/mode); ++i)
	{
		//PRINTF("bit: %d ",( (*input >> (mode*i))  & ( ~(0xffffffff << mode) ) ) );
		tempInput |= ( (input >> (mode*i)) & ( ~(0xffffffff << mode) ) );
		//PRINTF("tempInput: %d\n",tempInput);
		if(i == ((32/mode) - 1) )
		{
			return tempInput;
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
	int32_t count = 0;
	printf("this is printf\n");
	PRINTF("this is macro\n");

	//dislayBit(CLK,32);
	SET_CLK_EN(CLK,3);
	GET_CLK_EN(CLK);
	//dislayBit(CLK,32);

	SET_CLK_PRE(CLK,255);
	GET_CLK_PRE(CLK);
	//dislayBit(CLK,32);

	SET_CLK_SRC(CLK,255);
	GET_CLK_SRC(CLK);
	printf("swap bit\n");
	dislayBit(CLK,32);
	CLK = swap(CLK,BIT);
	printf("sau swap\n");
	dislayBit(CLK,32);
	printf("swap byte\n");
	dislayBit(CLK,32);
	CLK = swap(CLK,BYTE);
	printf("sau swap\n");
	dislayBit(CLK,32);
	return 0;
}
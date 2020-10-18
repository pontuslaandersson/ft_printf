#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//holds one bit
struct sbit 
{ 
	unsigned b : 1; 
};
typedef struct sbit BIT;

double				ft_pow(double n, long pow)
{
	return (pow ? n * ft_pow(n, pow - 1) : 1);
}

float getMantissa(BIT *mantissa)
{
	int i;
	float sum = 1; //implied 2^0
	//sum from n = 0 to 22 bn^(-(n+1))
	for (i = 22; i > -1; i--)
		sum += (ft_pow(2,i-23)*(int)(mantissa[i].b));
	return sum;//*4; //2^2
}
int getExponent(BIT *expo)
{
	int i;
	float sum = 0;
	//convert binary char to int
	for (i = 7; i > -1; i--)
		sum += (ft_pow(2,i)*(int)(expo[i].b));
	return (int)(sum-127); //adjust
}
int main()
{
	BIT *bit;
	BIT *mantissa;
	BIT *expo;
	BIT *sign;
	int isign;
	float data;
	int dataBits;
	int i;
	//allocate 32 bits of memory (same as a float)
	bit = (BIT*) calloc (32,sizeof(BIT));
	//allocate 23 bits for the mantissa
	mantissa = (BIT*) calloc (23,sizeof(BIT));
	//allocate 8 bits for the exponent
	expo = (BIT*) calloc(8,sizeof(BIT));
	//1 bit sign
	sign = (BIT*) calloc(1,sizeof(BIT));
	scanf("%f",&data);
	//convert the data float to an int to allow bit manip
	dataBits = *(int*)&data;
	//put the floating point bits into the bit struct
	for (i = 0; i < 32; i++)
		//overflow the right hand side unneeded bits
		bit[i].b = (dataBits << (32-(i+1))) >> 31;
	//print floating point bits (must be backwards)
	printf("Floating point: \t");
	for (i = 31; i > -1; i--)
		printf("%d",(int)(bit[i].b));
	printf("\n");
	//extract mantissa
	printf("Mantissa: \t\t");
	for (i = 0; i < 23; i++)
		mantissa[i].b = (dataBits << (32-(i+1))) >> 31;
	//print mantissa
	for (i = 22; i > -1; i--)
		printf("%d",(int)(mantissa[i].b));
	//get exponent
	printf("\nExponent: \t\t");
	for (i = 23; i < 31; i++)
		expo[i-23].b = (dataBits << (32-(i+1))) >> 31;
	//print expo
	for (i = 30; i > 22; i--)
		printf("%d",(int)(expo[i-22].b));
	//read sign
	printf("\nSign:\t\t\t");
	sign[0].b = dataBits >> 31;
	printf("%d\n",(int)(sign[0].b));
	//get the sign as an integer
	isign = ((int)sign[0].b == 1) ? -1 : 1;
	printf("\n%f = %d * %.16f * 2^%d\n", data, isign, getMantissa(mantissa),   getExponent(expo));
	return 0;
}
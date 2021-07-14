#include <stdio.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS

//declaring a struct 
struct number
{
	float coeff;
	int power;
};

//divide function prototype
int divide(struct number Fdividend[10], struct number Fdivisor[10], int FDdivisor, struct number Fquotient[10], int counter);


void main()
{
	//declaring degrees of dividend and divisor
	int Ddividend = 0, Ddivisor = 0;

	//getting degree of dividend
	printf("Please Enter the degree of dividend:");
	scanf_s("%d", &Ddividend);

	//getting degree of divisor
	printf("Please Enter the degree of divisor:");
	scanf_s("%d", &Ddivisor);

	//checking for error
	if (Ddividend < Ddivisor)
	{
		printf("ERROR : Degree of Dividend is smaller than that of Divisor\r\n");
		return 0;
	}

	//calculating degree of quotient
	int Dquotient = Ddividend - Ddivisor;

	//declaring arrays of numbers
	struct number dividend[10], divisor[10], quotient[10];

	//getting dividend
	for (int i = 0; i <= Ddividend; i++)
	{
		dividend[i].power = Ddividend - i;
		printf("Please enter the Dividend's coefficient of x^%d :", Ddividend - i);
		scanf_s("%f", &dividend[i].coeff);
	}

	//getting divisor
	for (int i = 0; i <= Ddivisor; i++)
	{
		divisor[i].power = Ddivisor - i;
		printf("Please enter the Divisor's coefficient of x^%d :", Ddivisor - i);
		scanf_s("%f", &divisor[i].coeff);
	}

	//assigning powers to quotient
	for (int i = 0; i <= Dquotient; i++)
	{
		quotient[i].power = Dquotient - i;
	}

	//counter to be used for determining number of steps in division
	int counter = 0;

	//using the function
	divide(dividend, divisor, Ddivisor, quotient, counter);


	printf("\r\nQuotient = ");

	//printing quotient
	for (int i = 0; i <= Dquotient; i++)
	{
		//excluding terms of 0 coefficients
		if (quotient[i].coeff == 0 && quotient[i].power != 0)
		{
			continue;
		}
		else if (quotient[i].power == 0)
		{
			printf("(%0.2f) \r\n", quotient[i].coeff);
		}
		else
		{
			printf("(%0.2f X^%d)", quotient[i].coeff, quotient[i].power);

			if (quotient[i].power != 0)
			{
				printf(" + ");
			}
		}
	}

	printf("\r\nRemainder = ");

	//printing remainder
	for (int i = 0; i <= Ddividend; i++)
	{
		if (dividend[i].coeff == 0 && dividend[i].power != 0)
		{
			continue;
		}
		else if (dividend[i].power == 0)
		{
			printf("(%0.2f) \r\n", dividend[i].coeff);
		}
		else
		{
			printf("(%0.2f X^%d)", dividend[i].coeff, dividend[i].power);

			if (dividend[i].power != 0)
			{
				printf(" + ");
			}
		}
	}
}


int divide(struct number Fdividend[10], struct number Fdivisor[10], int FDdivisor, struct number Fquotient[10], int counter)
{
	//checking if remainder is reached
	if (Fdividend[counter].power >= Fdivisor[0].power)
	{
		//getting quotient
		Fquotient[counter].power = Fdividend[counter].power - Fdivisor[0].power;
		Fquotient[counter].coeff = Fdividend[counter].coeff / Fdivisor[0].coeff;

		//declaring product of multiplying divisor by quotient
		struct number Fproduct[10];

		//multiplication
		for (int i = 0; i <= FDdivisor; i++)
		{
			Fproduct[i].power = Fquotient[counter].power + Fdivisor[i].power;
			Fproduct[i].coeff = Fquotient[counter].coeff * Fdivisor[i].coeff;

			//subtraction 
			Fdividend[counter + i].coeff = Fdividend[counter + i].coeff - Fproduct[i].coeff;
		}
		//change the start of operations to the following dividend term
		counter++;

		//recursion
		divide(Fdividend, Fdivisor, FDdivisor, Fquotient, counter);
	}
	else
		return 0;
}


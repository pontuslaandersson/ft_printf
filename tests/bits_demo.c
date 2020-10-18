#include <stdio.h>

enum {
	TRANSPORTER,
	WARP,
	SHIELDS,
	PHASERS
};

int bit_test(char bit, char byte)
{
	bit = 1 << bit;
	return(bit & byte);
}

void show_status(char s)
{
	if( bit_test(TRANSPORTER,s) )
		printf("\tTransporter is working.\n");
	else
		printf("\tTransporter is down!\n");

	if( bit_test(WARP,s) )
		printf("\tWarp engines online.\n");
	else
		printf("\tWarp drive is offline!\n");
	
	if( bit_test(SHIELDS,s) )
		printf("\tShields up.\n");
	else
		printf("\tThis shields are down!\n");

	if( bit_test(PHASERS,s) )
		printf("\tPhasers available.\n");
	else
		printf("\tPhasers are not operational!\n");
}

void bit_set(char bit, char *byte)
{
	bit = 1 << bit;
	*byte = *byte | bit;
}

void bit_reset(char bit, char *byte)
{
	bit = 1 << bit;
	bit ^= 0xff;
	*byte = *byte & bit;
}

int main()
{
	char status = 0x0;

	/* Setup the ship */
	puts("Stardate 41616");
	bit_set(TRANSPORTER,&status);		/* Transporter available */
	bit_set(WARP,&status);			/* Warp drive on */
	bit_set(SHIELDS,&status);		/* Shields up */
	bit_set(PHASERS,&status);		/* Phasers active */
	show_status(status);

	puts("The Klingons are attacking!");
	bit_reset(SHIELDS,&status);		/* Take down the shields */
	show_status(status);

	return(0);
}

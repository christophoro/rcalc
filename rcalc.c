/* rcalc.c */

/*
 *  rcalc : roman calculator. Simple calculator wich adds, subtracts,
 *  multiplies and divides numbers written in roman numeric system.
 *  Output also is given in latin numerals.
 *
 *  Krzysztof Uminski <s167971@student.pg.gda.pl>
 *  May 2017
 *
 */

#include <stdio.h>
#include <rcalc.h>

#define MAXNUMLEN 40



int main(int argc, char **argv) {
	int dec, num1, num2;
	char rom[MAXNUMLEN];
	char *r;
	char op;

	if (argc < 4 || argc > 4) {
		errOut(1);
		return 1;
	}

	num1 = romanToDec(argv[1]);
	op   = *argv[2];
	num2 = romanToDec(argv[3]);

	if (!num1 || !num2) {
		errOut(2);
		return 2;
	}

	switch (op) {
		case '+':
			dec = num1 + num2;
			break;
		case '-':
			if (num1 > num2)
				dec = num1 - num2;
			else if (num1 == num2) {
				errOut(2);
				return 2;
			}
			else if (num1 < num2) {
				errOut(3);
				return 3;
			}
			break;
		case 'x':
			dec = num1 * num2;
			break;
		case '/':
			dec = num1 / num2;
			break;
		default:
			errOut(4);
			return 4;
	}
	
	decToRoman(dec, rom);

	r = rom;
	while (*r) {
		printf("%c", *r);
		r++;
	}
	printf("\n");
	return 0;
}

/* EOF */

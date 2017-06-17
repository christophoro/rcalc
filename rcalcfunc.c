/* rcalcfunc.c */

#include <stdio.h>

int romanToDec(char *r) {
	int dec = 0;
	while (*r) {
		switch (*r) {
			case 'M': 
				dec += 1000;
				break;
			case 'D':
				dec += 500;
				break;
			case 'C': 
				switch (*(r + 1)) {
					case 'M': 
						dec += 900;
						r++;
						break;
					case 'D': 
						dec += 400;
						r++;
						break;
					default: 
						dec += 100;
				}
				break;
			case 'L': 
				dec += 50;
				break;
			case 'X': 
				switch (*(r + 1)) {
					case 'C':
						dec += 90;
						r++;
						break;
					case 'L':
						dec += 40;
						r++;
						break;
					default:
						dec += 10;
				}
				break;
			case 'V':
				dec += 5;
				break;
			case 'I':
				switch (*(r + 1)) {
					case 'X':
						dec += 9;
						r++;
						break;
					case 'V':
						dec += 4;
						r++;
						break;
					default:
						dec++;
				}
		}
		r++;
	}
	return dec;
}



void decToRoman(int dec, char *r) {
	while (dec >= 1000) {
		dec -= 1000; *r = 'M'; r++;
	}
	if (dec >= 900) {
		dec -= 900; *r = 'C'; r++; *r = 'M'; r++;
	}
	if (dec >= 500) {
		dec -= 500; *r = 'D'; r++;
	}
	if (dec >= 400) {
		dec -= 400; *r = 'C'; r++; *r = 'D'; r++;
	}
	while (dec >= 100) {
		dec -= 100; *r = 'C'; r++;
	}
	if (dec >= 90) {
		dec -= 90; *r = 'X'; r++; *r = 'C'; r++;
	}
	if (dec >= 50) {
		dec -= 50; *r = 'L'; r++;
	}
	if (dec >= 40) {
		dec -= 40; *r = 'X'; r++; *r = 'L'; r++;
	}
	while (dec >= 10) {
		dec -= 10; *r = 'X'; r++;
	}
	if (dec >= 9) {
		dec -= 9; *r = 'I'; r++; *r = 'X'; r++;
	}
	if (dec >= 5) {
		dec -= 5; *r = 'V'; r++;
	}
	if (dec >= 4) {
		dec -= 4; *r = 'I'; r++; *r = 'V'; r++;
	}
	while (dec >= 1) {
		dec--; *r = 'I'; r++;
	}
	*r = '\0';
}



void errOut(int err) {
	switch (err) {
		case 1:
			printf("Usage: rcalc NUMBER_1 OPERATOR NUMBER_2\n \
				NUMBER_1 and NUMBER_2 are numbers \
			        in roman numeric system\n \
				OPERATOR could be one of: \
				'+', '-', 'x', '/'\n");
			break;
		case 2: 
			printf("rcalc: zero is not defined \
				in roman numeric system\n");
			break;
		case 3:	
			printf("rcalc: negative values are not defined \
				in roman numeric system\n");
			break;
		case 4: 
			printf("rcalc: unrecognized operator\n");
			break;
		default:
			printf("rcalc: unknown error\n");
	}
}

/* EOF */

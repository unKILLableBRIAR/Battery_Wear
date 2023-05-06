#include <stdio.h>
#include "print.h"

void print_condition(double wear) {
	if (wear >= 100) {
		printf("ERROR\n");
	}
	else if (wear <= 5) {
		printf("Your Battery is Excellent!!\nYour Battery is like New one!\n");
	}
	else if (wear <= 10) {
		printf("Your Battery is Very Nice!!\n");
	}
	else if (wear <= 20) {
		printf("Your Battery is Nice!\n");
	}
	else if (wear <= 30) {
		printf("Your Battery is bad.\nI recommend replacing battery with new one.\n");
	}
}
#include <stdio.h>
#include "calc_c.h"

double calc_battery(double design, double current) {
	return current / design * 100;
}
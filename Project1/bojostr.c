#include <stdio.h>
#include <string.h>
#include "bojostr.h"

int atoi_dev(char* str) {
	int tmp, i = 0, result = 0;
	while (str[i]) {
		//int cnt = 0;
		if (str[i] >= 48 && str[i] <= 57) {
			result *= 10;
			tmp = (int)str[i] - 48;
			result += tmp;
		}
		i++;
	}
	return result;
}

int capacity_check(int battery) {
	if (battery >= 100000) {
		int cnt = 0;
		int tmp = battery;
		while (tmp > 10) {
			tmp /= 10;
			cnt++;
		}
		for (int i = 0; i < cnt; i++) {
			tmp *= 10;
		}
		return battery - tmp;
	}
	else
		return battery;
}

char* strend_slice(char* ori, char* cpy, int n) {
	n -= 1;
	int cnt = strlen(ori);
	for (int i = 0; i < n; i++) {
		cpy[i] = ori[cnt - n + i];
	}
	cpy[n] = '\0';
	return cpy;
}
/*
Battery_Wear_Check V1.05.06
This program made by Joonhyeong the Captain Dochi(hedge hog)
If you have trouble until using this program, please visit my blog (blog.naver.com/wnsgud3590)
*/

#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include "bojostr.h"
#include "calc_c.h"
#include "print.h"

int main() {
	system("powercfg batteryreport output ./battery-report.txt");
	system("cls");
	FILE* fp;
	char tmp[200];
	char battery_1[15];
	char battery_2[15];
	char mwh[5] = "mWh";

	errno_t err;
	err = fopen_s(&fp, "battery-report.txt", "r");
	if (err) {
		printf("Fail to open file.\n");
		return 0;
	}
	int i = 1;
	while (i<=2) {
		fgets(tmp, sizeof(tmp), fp);
		if(i == 1 && strstr(tmp,mwh)!='\0') {
			//strcpy_s(battery_1, sizeof(battery_1), tmp);
			strend_slice(tmp, battery_1, 15);
			i++;
		}
		else if (i == 2 && strstr(tmp, mwh) != '\0') {
			//strcpy_s(battery_2, sizeof(battery_2), tmp);
			strend_slice(tmp, battery_2, 15);
			break;
		}
	}
	fclose(fp);

	double designed_battery = capacity_check(atoi_dev(battery_1)); //designed full chargable capacity 
	double current_battery = capacity_check(atoi_dev(battery_2)); //current full chargable capacity
	printf("designed_battery : %d,%0.3dmWh\ncurrent_full_battery : %.d,%0.3dmWh\n", (int)designed_battery / 1000, (int)designed_battery % 1000, (int)current_battery % 1000, (int)current_battery / 1000);
	//for print battery_capacity with comma
	double battery_proportion = calc_battery(designed_battery, current_battery); //calculate battery_proportion
	double battery_wear = 100 - battery_proportion;
	printf("battery_proportion : %.1f%%\nbattery_wear : %.1f%%\n", battery_proportion, battery_wear); 
	print_condition(battery_wear);
	system("del battery-report.txt");
	printf("\nPress Any key to Exit.");

	getch();
	return 0;
}
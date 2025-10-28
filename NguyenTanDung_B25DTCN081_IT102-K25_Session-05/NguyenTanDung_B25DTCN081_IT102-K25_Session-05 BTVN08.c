#include<stdio.h>

int main() {
    float v;       
    float money;    
	const float WATER_USAGE_FEES_LV_1 = 6000, WATER_USAGE_FEES_LV_2 = 7000, WATER_USAGE_FEES_LV_3 = 8500, WATER_USAGE_FEES_LV_4 = 10000;

    printf("Enter the volume of water consumed per month: ");
    scanf("%f", &v);

    if (v < 0) {
        printf("Invalid volume number error!\n");
    } else if (v <= 10) {
        money = v * WATER_USAGE_FEES_LV_1;
    } else if (v <= 20) {
        money = 10 * WATER_USAGE_FEES_LV_1 + (v - 10) * WATER_USAGE_FEES_LV_2;
    } else if (v <= 30) {
        money = 10 * WATER_USAGE_FEES_LV_1 + 10 * WATER_USAGE_FEES_LV_2 + (v - 20) * WATER_USAGE_FEES_LV_3;
    } else {
        money = 10 * WATER_USAGE_FEES_LV_1 + 10 * WATER_USAGE_FEES_LV_2 + 10 * WATER_USAGE_FEES_LV_3 + (v - 30) * WATER_USAGE_FEES_LV_4;
    }

   
        printf("Total water bill payable: %.0f VND\n", money);

    return 0;
}


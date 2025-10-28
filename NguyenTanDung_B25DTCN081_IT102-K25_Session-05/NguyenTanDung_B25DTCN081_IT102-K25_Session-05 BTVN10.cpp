#include<stdio.h>

int main() {
    float kwh;             
    int householdtype;            
    float stairsmoney = 0, surcharge = 0, electricitybill = 0;
    const float UNIT_PRICE_LV_1 = 1500, UNIT_PRICE_LV_2 = 2000, UNIT_PRICE_LV_3 = 2500, UNIT_PRICE_LV_4 = 3000;

    
    printf("Enter electricity consumption (kWh): ");
    scanf("%f", &kwh);
    printf("Enter type of consumer (1: Family, 2: Business, 3: Production): ");
    scanf("%d", &householdtype);

    
    if (kwh < 0) {
        printf("Error: Invalid electricity number!\n");
        return 0;
    }
    if (householdtype < 1 || householdtype > 3) {
        printf("Error: Invalid householdtype!\n");
        return 0;
    }

   
    if (kwh <= 50) {
        stairsmoney = kwh * UNIT_PRICE_LV_1;
    } else if (kwh <= 100) {
        stairsmoney = 50 * UNIT_PRICE_LV_1 + (kwh - 50) * UNIT_PRICE_LV_2;
    } else if (kwh <= 200) {
        stairsmoney = 50 * UNIT_PRICE_LV_1 + 50 * UNIT_PRICE_LV_2 + (kwh - 100) * UNIT_PRICE_LV_3;
    } else {
        stairsmoney = 50 * UNIT_PRICE_LV_1 + 50 * UNIT_PRICE_LV_2 + 100 * UNIT_PRICE_LV_3 + (kwh - 200) * UNIT_PRICE_LV_4;
    }

   
    switch (householdtype) {
        case 1:
            surcharge = stairsmoney * 0.05; 
            break;
        case 2:
            surcharge = stairsmoney * 0.10; 
            break;
        case 3:
            surcharge = stairsmoney * 0.08; 
            break;
    }

   
    electricitybill = stairsmoney + surcharge;

  
    printf("\n---Electricity bill ---\n");
    printf("Amount of electricity consumed: %.2f kWh\n", kwh);
    printf("Householdtype: %s\n", (householdtype == 1) ? "Family" :
                             (householdtype == 2) ? "Business" : "Production");
    printf("Stairsmoney: %.0f VND\n", stairsmoney);
    printf("Surcharge: %.0f VND\n", surcharge);
    printf("Total electricity bill: %.0f VND\n", electricitybill);

    return 0;
}


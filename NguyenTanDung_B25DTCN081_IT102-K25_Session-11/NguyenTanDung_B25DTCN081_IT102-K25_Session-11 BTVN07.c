#include <stdio.h>

int main() {
    int n,i;
    printf("Nhap so thang: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("Loi: Can it nhat 2 thang de co the ban.\n");
        return 0;
    }

    int price[n];
    printf("Nhap gia co phieu tung thang:\n");
    for (i = 0; i < n; i++) {
        printf("Thang %d: ", i + 1);
        scanf("%d", &price[i]);
    }

    int buy_price = price[0];
    int min_loss = 0;
    int best_month = 1;

    for (i = 1; i < n; i++) {
        int diff = price[i] - buy_price;

        if (diff >= 0) {
            printf("Nen ban vao thang %d de co lai hoac khong lo (lai %d).\n", i + 1, diff);
            return 0;
        }

        if (diff > min_loss || i == 1) {
            min_loss = diff;
            best_month = i + 1;
        }
    }

    printf("Nen ban vao thang %d de lo it nhat: %d (gia mua %d -> gia ban %d)\n",
           best_month, min_loss, buy_price, price[best_month - 1]);

    return 0;
}


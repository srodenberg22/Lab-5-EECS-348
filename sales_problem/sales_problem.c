#include <stdio.h>
#include <string.h>

int main() {
    FILE *file;
    double sales[12];
    char months[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int i;

    //Open the file
    file = fopen("sales.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    //Read sales numbers from the file
    for (i = 0; i < 12; i++) {
        fscanf(file, "%lf", &sales[i]);
    }

    //Close the file
    fclose(file);

    //Display the sales numbers
    printf("Sales numbers:\n\n");
    for (i = 0; i < 12; i++) {
        printf("%.2f\n", sales[i]);
    }

    //Display monthly sales report
    printf("\nMonthly sales report for 2022:\n\n");
    printf("Month       Sales\n\n");
    for (i = 0; i < 12; i++) {
        printf("%-10s  %.2f\n", months[i], sales[i]);
    }

    //Display sales summary (min, max, avg)
    printf("\nSales summary:\n\n");
    double avg, min, max;
    double length = sizeof(sales)/sizeof(sales[0]);
    //min
    min = sales[0];
    int min_index = 0;
    for (int i = 0; i < length; i++) {
        if(sales[i] < min){
            min = sales[i];
            min_index = i;
        }
    }
    printf("Minimum sales: %.2f", min); printf("    (%s)\n", months[min_index]);
    //max
    max = sales[0];
    int max_index = 0;
    for (int i = 0; i < length; i++) {
        if(sales[i] > max){
            max = sales[i];
            max_index = i;
        }
    }
    printf("Maximum sales: %.2f", max); printf("    (%s)\n", months[max_index]);
    //avg
    avg = (sales[0] + sales[1] + sales[2] + sales[3] + sales[4] + sales[5] + sales[6] + sales[7] + sales[8] + sales[9] + sales[10] + sales[11]) / 12;
    printf("Average sales: %.2f\n\n", avg);

    //Moving average
    printf("Six-month Moving Average Report:\n\n");
    for (int i = 0; i <= length - 6; i++) {
        double sum = 0;
        for (int j = i; j < i + 6; j++) {
            sum += sales[j];
        }
        printf("%-8s - %-10s $%.2f\n", months[i], months[i + 5], sum / 6);
    }

    //Sales report
    printf("Sales Report (Highest to Lowest):\n\n");
    printf("  Month     Sales\n\n"); 
    double t = 0;
    char tm[10];
    for (int i = 0; i < length; i++) { 
        for (int j = i + 1; j < length; j++) { 
            if (sales[i] < sales[j]) { 
                t = sales[i]; 
                sales[i] = sales[j]; 
                sales[j] = t;

                strcpy(tm, months[i]);
                strcpy(months[i], months [j]);
                strcpy(months[j], tm);
            }
        }
    }
    for (i = 0; i < length; i++) {
        printf("%-10s %.2f\n", months[i], sales[i]);
    }
    return 0;
}

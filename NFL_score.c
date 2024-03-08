#include <stdio.h>

int main() {
    int score;

    while (1) {
        printf("Enter the NFL score: ");
        scanf("%d", &score);
        //Check loop condition
        if (score <= 1) {
            printf("Enter 0 or 1 to STOP\n");
            break;
        }
        printf("Possible combinations of scoring plays:\n");
        //Loop through touchdown + 2 pt conversions
        for (int touchdowns_with_2pt = 0; touchdowns_with_2pt * 8 <= score; touchdowns_with_2pt++) {
            //Loop through touchdown + extra point
            for (int touchdowns_with_1pt = 0; touchdowns_with_1pt * 7 <= score; touchdowns_with_1pt++) {
                //Loop through touchdowns
                for (int touchdowns = 0; touchdowns * 6 <= score; touchdowns++) {
                    //Loop through field goals
                    for (int fieldgoals = 0; fieldgoals * 3 <= score - touchdowns * 6; fieldgoals++) {
                        //Loop through safeties
                        for (int safeties = 0; safeties * 2 <= score - touchdowns * 6 - fieldgoals * 3; safeties++) {
                            //Calculate total score
                            int total_score = touchdowns_with_2pt * 8 + touchdowns_with_1pt * 7 + touchdowns * 6 + fieldgoals * 3 + safeties * 2;
                            //Check if total score same as input
                            if (total_score == score) {
                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", touchdowns_with_2pt, touchdowns_with_1pt, touchdowns, fieldgoals, safeties);
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}


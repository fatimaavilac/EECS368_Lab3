/*
 * Program2.cpp
 *
 *  Created on: Feb 10, 2023
 *      Author: Fatima Avila
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    while(1)
    {
        int score = 0; // stores user's input

        printf("\n");
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: "); // prompt user for value
        scanf("%d", &score); // store int in 'score'

        // if user enters value 1 or less, program ends
        if(score <= 1)
            break;

        printf("\npossible combinations of scoring plays:\n");

        int combos = 0; // counts number of combinations

        // iterate through score by each point value
        for(int TDp2 = 0; TDp2 <= score / 8; TDp2++) // TD + 2pts (8 points)
        {
            int score_minus_TDp2 = score - TDp2 * 8; // score minus the number of TD+2
            for(int TDp1 = 0; TDp1 <= score_minus_TDp2 / 7; TDp1++) // TD + 1pt (7 points)
            {
                int score_minus_TDp2_TDp1 = score_minus_TDp2 - TDp1 * 7; // score minus TD+2 and TD+1
                for(int TD = 0; TD <= score_minus_TDp2_TDp1 / 6; TD++) // TD (6 points)
                {
                    int score_minus_TDp2_TDp1_TD = score_minus_TDp2_TDp1 - TD * 6; // score minus TD+2, TD+1, and TD
                    for(int FG = 0; FG <= score_minus_TDp2_TDp1_TD / 3; FG++) // FG (3 points)
                    {
                        int safety = (score_minus_TDp2_TDp1_TD - FG * 3) / 2; // safety (2 points) = (score minues TD+2, TD+1, TD, and FG) / 2
                        if(TDp2*8 + TDp1*7 + TD*6 + FG*3 + safety*2 == score) // only print if point values add up to exact score
                        {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                                TDp2, TDp1, TD, FG, safety);
                            combos++; // increment num of combinations
                        }
                    }
                }
            }
        }

        printf("\n%d possible combinations\n", combos); // print number of combinations
    }

    return 0;
}
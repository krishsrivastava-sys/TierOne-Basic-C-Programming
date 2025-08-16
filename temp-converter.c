# include <stdio.h>
# include <string.h>
# include <stdlib.h>

int main() {
    int temp;
    int convertto;
    double ttemp; // temperature as double for decimal precision

    printf("Enter the Temperature: ");
    scanf("%lf", &ttemp);

    printf("Choose the Initial Temperature Scale:\n1. Celsius (°C)\n2. Fahrenheit (°F)\n3. Kelvin (K)\n4. Rankine (°R)\n5. Réaumur (°Re)\n6. Delisle (°De)\n");
    printf("Enter (1-6): ");
    scanf("%d", &temp);

    printf("Choose the Final Temperature Scale:\n1. Celsius (°C)\n2. Fahrenheit (°F)\n3. Kelvin (K)\n4. Rankine (°R)\n5. Réaumur (°Re)\n6. Delisle (°De)\n");
    printf("Enter (1-6): ");
    scanf("%d", &convertto);

    if (temp > 0 && temp < 7) {
        double answervalue = 0;
        char scale[50];

        if (temp == 1) {
            // Celsius;
            switch (convertto) {
                case 1: answervalue = ttemp; break;
                case 2: answervalue = (ttemp * 9.0/5.0) + 32; break;
                case 3: answervalue = ttemp + 273.15; break;
                case 4: answervalue = (ttemp + 273.15) * 9.0/5.0; break;
                case 5: answervalue = ttemp * 4.0/5.0; break;
                case 6: answervalue = (100 - ttemp) * 3.0/2.0; break;
                default: printf("Enter a Valid Value."); exit(0);
            }
        }

        else if (temp == 2) {
            // Fahrenheit;
            switch (convertto) {
                case 1: answervalue = (ttemp - 32) * 5.0/9.0; break;
                case 2: answervalue = ttemp; break;
                case 3: answervalue = (ttemp - 32) * 5.0/9.0 + 273.15; break;
                case 4: answervalue = (ttemp + 459.67); break;
                case 5: answervalue = (ttemp - 32) * 4.0/9.0; break;
                case 6: answervalue = (212 - ttemp) * 5.0/6.0; break;
                default: printf("Enter a Valid Value."); exit(0);
            }
        }

        else if (temp == 3) {
            // Kelvin;
            switch (convertto) {
                case 1: answervalue = ttemp - 273.15; break;
                case 2: answervalue = (ttemp - 273.15) * 9.0/5.0 + 32; break;
                case 3: answervalue = ttemp; break;
                case 4: answervalue = ttemp * 9.0/5.0; break;
                case 5: answervalue = (ttemp - 273.15) * 4.0/5.0; break;
                case 6: answervalue = (373.15 - ttemp) * 3.0/2.0; break;
                default: printf("Enter a Valid Value."); exit(0);
            }
        }

        else if (temp == 4) {
            // Rankine;
            switch (convertto) {
                case 1: answervalue = (ttemp - 491.67) * 5.0/9.0; break;
                case 2: answervalue = ttemp - 459.67; break;
                case 3: answervalue = ttemp * 5.0/9.0; break;
                case 4: answervalue = ttemp; break;
                case 5: answervalue = (ttemp - 491.67) * 4.0/9.0; break;
                case 6: answervalue = (671.67 - ttemp) * 5.0/6.0; break;
                default: printf("Enter a Valid Value."); exit(0);
            }
        }

        else if (temp == 5) {
            // Reaumur;
            switch (convertto) {
                case 1: answervalue = ttemp * 5.0/4.0; break;
                case 2: answervalue = ttemp * 9.0/4.0 + 32; break;
                case 3: answervalue = ttemp * 5.0/4.0 + 273.15; break;
                case 4: answervalue = (ttemp * 5.0/4.0 + 273.15) * 9.0/5.0; break;
                case 5: answervalue = ttemp; break;
                case 6: answervalue = (80 - ttemp) * 15.0/8.0; break;
                default: printf("Enter a Valid Value."); exit(0);
            }
        }

        else if (temp == 6) {
            // Delisle;
            switch (convertto) {
                case 1: answervalue = 100 - ttemp * 2.0/3.0; break;
                case 2: answervalue = 212 - ttemp * 6.0/5.0; break;
                case 3: answervalue = 373.15 - ttemp * 2.0/3.0; break;
                case 4: answervalue = (373.15 - ttemp * 2.0/3.0) * 9.0/5.0; break;
                case 5: answervalue = (100 - ttemp * 2.0/3.0) * 4.0/5.0; break;
                case 6: answervalue = ttemp; break;
                default: printf("Enter a Valid Value."); exit(0);
            }
        }

        if (convertto == 1) strcpy(scale, "Celsius");
        else if (convertto == 2) strcpy(scale, "Fahrenheit");
        else if (convertto == 3) strcpy(scale, "Kelvin");
        else if (convertto == 4) strcpy(scale, "Rankine");
        else if (convertto == 5) strcpy(scale, "Réaumur");
        else if (convertto == 6) strcpy(scale, "Delisle");

        printf("Successfully converted %.2lf to %.2lf %s.", ttemp, answervalue, scale);
    }
    else {
        printf("Enter a Valid Temperature Scale.");
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESERVATIONS 1000

typedef struct {
    char name[100];
    char phone[100];
    char datetime[100];
    char clock[100];
} Reservation;

int main(void) {
    int a, b;
    int l = 0;

    // Array of strings to store time values
    const char* dailytime[13] = {"9", "10", "11", "12", "13", "14", "15",
                                 "16", "17", "18", "19", "20", "21"};

    char tell[100], n[100], date[100], time[100];
    Reservation* reservations = (Reservation*)malloc(MAX_RESERVATIONS * sizeof(Reservation));
    if (reservations == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Hello world\n");

    while (1) {
        printf("\033[1;34mReservation System\n");
        printf("\033[1;34m======Menu======\n");
        printf("\033[1;34m1. Add Reservation\n");
        printf("\033[1;34m2. Modify Reservation\n");
        printf("\033[1;34m3. Cancel Reservation\n");
        printf("\033[1;34m4. View Reservation\n");
        printf("\033[0m====================\n");

        // Enter the function
        printf("\033[1;34mPlease enter the function you want.\n");
        scanf("%d", &a);

        switch (a) // Enter data
        {
            case 1: {
                printf("Please enter your name:");
                scanf("%s", n);
                printf("Please enter your phone number:");
                scanf("%s", tell);

                // Check if reservation already exists
                int found = 0;
                for (int i = 0; i < l; i++) {
                    if (strcmp(tell, reservations[i].phone) == 0) {
                        found = 1;
                        break;
                    }
                }

                if (found) {
                    printf("Reservation already exists\n");
                    printf("Your information is as follows\n");
                    for (int i = 0; i < l; i++) {
                        if (strcmp(tell, reservations[i].phone) == 0) {
                            printf("Name: %s\n", reservations[i].name);
                            printf("Phone number: %s\n", reservations[i].phone);
                            printf("Reservation date: %s\n", reservations[i].datetime);
                            printf("Reservation time: %s o'clock\n", reservations[i].clock);
                        }
                    }
                } else {
                    strcpy(reservations[l].phone, tell);
                    strcpy(reservations[l].name, n);
                    printf("Please enter the date:");
                    scanf("%s", date);
                    printf("Please enter the time:");
                    scanf("%s", time);

                    int found2 = 0;
                    for (int j = 0; j < l; j++) {
                        if (strcmp(time, reservations[j].clock) == 0 && strcmp(date, reservations[j].datetime) == 0) {
                            found2 = 1;
                            break;
                        }
                    }

                    if (found2) {
                        printf("Fully booked\n");
                        printf("Here are some available times\n");
                        for (int k = 0; k < 13; k++) {
                            printf("Time: %s\n", dailytime[k]);
                        }
                    } else {
                        strcpy(reservations[l].datetime, date);
                        strcpy(reservations[l].clock, time);
                        l++;
                        printf("Reservation added\n");
                    }
                }
                break;
            }

            case 2: {
                printf("Please enter your name:");
                scanf("%s", n);
                printf("Please enter your phone number:");
                scanf("%s", tell);

                int found3 = 0;
                int p = -1; // Used to save the matching index
                for (int i = 0; i < l; i++) {
                    if (strcmp(reservations[i].phone, tell) == 0 && strcmp(reservations[i].name, n) == 0) {
                        found3 = 1;
                        p = i;
                        break;
                    }
                }

                if (found3) {
                    printf("Do you want to change the date? (1 yes / 0 no)\n");
                    scanf("%d", &b);
                    if (b == 1) {
                        printf("Please enter the new date:");
                        scanf("%s", date);
                        strcpy(reservations[p].datetime, date); // Modify the date
                    }

                    printf("Please enter the new time:");
                    scanf("%s", time);

                    int found4 = 0;
                    for (int m = 0; m < l; m++) {
                        if (strcmp(time, reservations[m].clock) == 0 && strcmp(date, reservations[m].datetime) == 0) {
                            found4 = 1;
                            break;
                        }
                    }

                    if (found4) {
                        printf("Fully booked\n");
                        printf("Here are some available times\n");
                        for (int k = 0; k < 13; k++) {
                            printf("Time: %s\n", dailytime[k]);
                        }
                    } else {
                        strcpy(reservations[p].clock, time); // Modify the time
                        printf("Modified\n");
                    }
                } else {
                    printf("No matching record found\n");
                }
                break;
            }

            case 3: {
                printf("Please enter your name:");
                scanf("%s", n);
                printf("Please enter your phone number:");
                scanf("%s", tell);

                int found5 = 0;
                for (int q = 0; q < l; q++) {
                    if (strcmp(reservations[q].phone, tell) == 0 && strcmp(reservations[q].name, n) == 0) {
                        found5 = 1;
                        for (int r = q; r < l - 1; r++) {
                            reservations[r] = reservations[r + 1];
                        }
                        l--;
                        break;
                    }
                }

                if (found5) {
                    printf("Cancelled\n");
                } else {
                    printf("No matching record found\n");
                }
                break;
            }

            case 4: {
                printf("Please enter your phone number:");
                scanf("%s", tell);

                int found6 = 0;
                for (int s = 0; s < l; s++) {
                    if (strcmp(reservations[s].phone, tell) == 0) {
                        found6 = 1;
                        printf("Name: %s\n", reservations[s].name);
                        printf("Phone number: %s\n", reservations[s].phone);
                        printf("Reservation date: %s\n", reservations[s].datetime);
                        printf("Reservation time: %s o'clock\n", reservations[s].clock);
                        break;
                    }
                }

                if (!found6) {
                    printf("No matching record found\n");
                }
                break;
            }

            default: {
                printf("Invalid option\n");
                break;
            }
        }
    }

    free(reservations);
    return 0;
}

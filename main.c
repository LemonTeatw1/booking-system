#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "booking_system.h"


int main(void) {
	char tell[BUFFER_SIZE_SMALL], n[BUFFER_SIZE_SMALL], date[BUFFER_SIZE_SMALL], time[BUFFER_SIZE_SMALL];
	int opts, b;
	int l = 0;

	while (1) {
		printf("\033[1;34mReservation System\n");
		printf("\033[1;34m======Menu======\n");
		printf("\033[1;34m1. Add Reservation\n");
		printf("\033[1;34m2. Modify Reservation\n");
		printf("\033[1;34m3. Cancel Reservation\n");
		printf("\033[1;34m4. View Reservation\n");
		printf("\033[0m====================\n");

		printf("\033[1;34mPlease enter the function you want.\n");
		scanf(" %d", &opts);

		switch (opts) {
		unsigned int found;

		case ADD_RESV:
		{
			unsigned int i;
			found = 0;

			printf("Please enter your name:");
			scanf(" %" STR(SMALL_BUFFER_SIZE) "s", &n);
			printf("Please enter your phone number:");
			scanf(" %" STR(SMALL_BUFFER_SIZE) "s", &tell);

			/* check if reservation exist */
			for (i = 0; i < l; i++) {
				if (!strcmp(tell, reservations[i].phone)) {
					found = 1;
					break;
				}
			}

			if (found) {
				printf("Reservation already exists\n");
				printf("Your information is as follows\n");
				for (i = 0; i < l; i++) {
					if (!strcmp(tell, reservations[i].phone)) {
						printf("Name: %s\n", reservations[i].name);
						printf("Phone number: %s\n", reservations[i].phone);
						printf("Reservation date: %s\n", reservations[i].datetime);
						printf("Reservation time: %s o'clock\n", reservations[i].clock);
					}
				}
			} else {
				strcpy(reservations[l].phone, &tell);
				strcpy(reservations[l].name, &n);
				printf("Please enter the date:");
				scanf(" %" STR(SMALL_BUFFER_SIZE) "s", &date);
				printf("Please enter the time:");
				scanf(" %" STR(SMALL_BUFFER_SIZE) "s", &time);

				found = 0;
				for (i = 0; i < l; i++) {
					if (!strcmp(time, reservations[i].clock) && !strcmp(date, reservations[i].datetime)) {
						found = 1;
						break;
					}
				}

				if (found) {
					printf("Fully booked\n");
					printf("Here are some available times\n");
					for (i = 0; i < 13; i++) {
						printf("Time: %s\n", dailytime[i]);
					}
				} else {
					strcpy(reservations[l].datetime, &date);
					strcpy(reservations[l].clock, &time);
					l++;
					printf("Reservation added\n");
				}
			}
			break;
		}
		case MODIFY_RESV:
		{
			unsigned int i;
			unsigned int matched_idx, if_change_data;
			found = 0;

			printf("Please enter your name:");
			scanf(" %" STR(SMALL_BUFFER_SIZE) "s", &n);
			printf("Please enter your phone number:");
			scanf(" %" STR(SMALL_BUFFER_SIZE) "s", &tell);

			for (i = 0; i < l; i++) {
				if (!strcmp(reservations[i].phone, &tell) && !strcmp(reservations[i].name, &n)) {
					found = 1;
					matched_idx = i;
					break;
				}
			}

			if (found) {
				printf("Do you want to change the date? (1 yes / 0 no)\n");
				scanf(" %d", &if_change_data);
				if (if_change_data == 1) {
					printf("Please enter the new date:");
					scanf(" %" STR(SMALL_BUFFER_SIZE) "s", &date);
					strcpy(reservations[matched_idx].datetime, &date);
				}

				printf("Please enter the new time:");
				scanf(" %" STR(SMALL_BUFFER_SIZE) "s", &time);

				for (i = 0; i < l; i++) {
					if (!strcmp(time, reservations[i].clock) && !strcmp(date, reservations[i].datetime)) {
						found = 1;
						break;
					}
				}

				if (found) {
					printf("Fully booked\n");
					printf("Here are some available times\n");
					for (i = 0; i < 13; i++) {
						printf("Time: %s\n", dailytime[i]);
					}
				} else {
					strcpy(reservations[matched_idx].clock, &time);
					printf("Modified\n");
				}
			} else {
				printf("No matching record found\n");
			}
			break;
		}

		case CANCEL_RESV:
		{
			unsigned int i, j;
			found = 0;

			printf("Please enter your name:");
			scanf(" %" STR(SMALL_BUFFER_SIZE) "s", &n);
			printf("Please enter your phone number:");
			scanf(" %" STR(SMALL_BUFFER_SIZE) "s", &tell);

			for (i = 0; i < l; i++) {
				if (!strcmp(reservations[i].phone, &tell) && !strcmp(reservations[i].name, &n)) {
					found = 1;
					for (j = i; j < l - 1; j++) {
						reservations[j] = reservations[j + 1];
					}
					l--;
					break;
				}
			}

			if (found) {
				printf("Cancelled\n");
			} else {
				printf("No matching record found\n");
			}
			break;
		}

		case VIEW_RESV:
		{
			unsigned int i;
			found = 0;

			printf("Please enter your phone number:");
			scanf(" %" STR(SMALL_BUFFER_SIZE) "s", &tell);

			for (i = 0; i < l; i++) {
				if (!strcmp(reservations[i].phone, &tell)) {
					found = 1;
					break;
				}
			}

			if (found) {
				printf("Name: %s\n", reservations[i].name);
				printf("Phone number: %s\n", reservations[i].phone);
				printf("Reservation date: %s\n", reservations[i].datetime);
				printf("Reservation time: %s o'clock\n", reservations[i].clock);

			} else {
				printf("No matching record found\n");
			}
			break;
		}
		default:
		{
			printf("Invalid option\n");
			break;
		}

		}
	}

	return 0;
}

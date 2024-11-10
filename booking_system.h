#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR(X) #X
#define MAX_RESERVATIONS 1000
#define BUFFER_SIZE_SMALL 100

#define ADD_RESV 1
#define MODIFY_RESV 2
#define CANCEL_RESV 3
#define VIEW_RESV 4

struct reservation {
	char name[BUFFER_SIZE_SMALL];
	char phone[BUFFER_SIZE_SMALL];
	char datetime[BUFFER_SIZE_SMALL];
	char clock[BUFFER_SIZE_SMALL];
};
typedef struct reservation resv_t;


resv_t reservations[MAX_RESERVATIONS];
/* time values */
const char* dailytime[13] = {"9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21"};

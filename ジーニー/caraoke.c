#include <stdio.h>
#include <string.h>

#define MAX_RECORDS 1000

typedef struct {
    char time[9];
    char type[10];
    int value1;
    int value2;
} Record;

int calculateRoomCharge(char timeType[], char drinkCourse[]) {
    if (strcmp(timeType, "free_time") == 0) {
        if (strcmp(drinkCourse, "one_drink") == 0) {
            return 1000;
        } else if (strcmp(drinkCourse, "free_refills") == 0) {
            return 1500;
        } else if (strcmp(drinkCourse, "alcohol_free_refills") == 0) {
            return 2500;
        }
    } else if (strcmp(timeType, "time_based") == 0) {
        if (strcmp(drinkCourse, "one_drink") == 0) {
            return 1500;
        } else if (strcmp(drinkCourse, "free_refills") == 0) {
            return 2000;
        } else if (strcmp(drinkCourse, "alcohol_free_refills") == 0) {
            return 4000;
        }
    }
    return -1; 
}

int calculateExtensionCharge(char timeType[], char drinkCourse[]) {
    if (strcmp(timeType, "free_time") == 0) {
        if (strcmp(drinkCourse, "one_drink") == 0) {
            return 100;
        } else if (strcmp(drinkCourse, "free_refills") == 0) {
            return 200;
        } else if (strcmp(drinkCourse, "alcohol_free_refills") == 0) {
            return 300;
        }
    } else if (strcmp(timeType, "time_based") == 0) {
        if (strcmp(drinkCourse, "one_drink") == 0) {
            return 400;
        } else if (strcmp(drinkCourse, "free_refills") == 0) {
            return 500;
        } else if (strcmp(drinkCourse, "alcohol_free_refills") == 0) {
            return 650;
        }
    }
    return -1; 
}

int main() {
    Record records[MAX_RECORDS];
    int numRecords = 0;
    int totalEntrants = 0;
    int totalLeavers = 0;
    int totalDrinksOrdered = 0;
    int totalEntrantsInSession = 0;
    int roomCharge = 0;
    int extensionCharge = 0;

    while (scanf("%8s %9s %d %d", records[numRecords].time, records[numRecords].type,
                 &records[numRecords].value1, &records[numRecords].value2) != EOF) {
        numRecords++;

        if (strcmp(records[numRecords - 1].type, "enter") == 0) {
            totalEntrants += records[numRecords - 1].value1;
            totalEntrantsInSession += records[numRecords - 1].value1;
        } else if (strcmp(records[numRecords - 1].type, "leave") == 0) {
            totalLeavers += records[numRecords - 1].value1;

            if (totalLeavers > totalEntrants) {
                printf("{\"code\": 99}\n");
                return 0;
            }
        } else if (strcmp(records[numRecords - 1].type, "drink") == 0) {
            totalDrinksOrdered += records[numRecords - 1].value2;
        }

        if (totalEntrants > 1000) {
            printf("{\"code\": 999}\n");
            return 0;
        }
    }

    if (strcmp(records[0].type, "header") == 0 && strcmp(records[0].type, "one_drink") == 0 &&
        totalDrinksOrdered < totalEntrantsInSession) {
        int price = calculateRoomCharge("free_time", "one_drink") * totalEntrantsInSession;
        printf("{\"code\": 1, \"price\": %d, \"drink\": %d}\n", price, totalEntrantsInSession - totalDrinksOrdered);
        return 0;
    }

    for (int i = 0; i < numRecords; i++) {
        if (strcmp(records[i].type, "header") == 0) {
            int charge = calculateRoomCharge(records[i].time, records[i].type);
            if (charge == -1) {
                printf("{\"code\": 999}\n");
                return 0;
            }
            roomCharge += charge * totalEntrantsInSession;
        } else if (strcmp(records[i].type, "footer") == 0) {
            printf("{\"code\": 0, \"price\": %d}\n", roomCharge + extensionCharge);
            return 0;
        } else if (strcmp(records[i].type, "drink") == 0) {
            if (strcmp(records[i].type, "one_drink") != 0) {
                extensionCharge += calculateExtensionCharge(records[i].time, records[i].type) * records[i].value2;
            }
        }
    }

    return 0;
}

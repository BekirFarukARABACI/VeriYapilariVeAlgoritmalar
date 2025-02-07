#include <stdio.h>
#include <time.h>

struct DateTime {
    int year, month, day, hour, minute, second;
};

time_t convertToEpoch(struct DateTime dt) {
    struct tm timeStruct = {0};
    timeStruct.tm_year = dt.year - 1900; 
    timeStruct.tm_mon = dt.month - 1;    
    timeStruct.tm_mday = dt.day;
    timeStruct.tm_hour = dt.hour;
    timeStruct.tm_min = dt.minute;
    timeStruct.tm_sec = dt.second;
    return mktime(&timeStruct);
}

int main() {
    struct DateTime dt1, dt2;
    
    printf("Ýlk tarihi girin (YYYY MM DD HH MM SS): ");
    scanf("%d %d %d %d %d %d", &dt1.year, &dt1.month, &dt1.day, &dt1.hour, &dt1.minute, &dt1.second);
    
    printf("Ýkinci tarihi girin (YYYY MM DD HH MM SS): ");
    scanf("%d %d %d %d %d %d", &dt2.year, &dt2.month, &dt2.day, &dt2.hour, &dt2.minute, &dt2.second);
    
    time_t epoch1 = convertToEpoch(dt1);
    time_t epoch2 = convertToEpoch(dt2);
    
    if (epoch1 == -1 || epoch2 == -1) {
        printf("Hatalý tarih girdiniz!\n");
        return 1;
    }

    double diff = difftime(epoch2, epoch1);
    
    printf("Ýki tarih arasýndaki fark: %.0f saniye\n", diff);

    return 0;
}


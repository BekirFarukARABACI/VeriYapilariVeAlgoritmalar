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
    struct DateTime meeting;
    
    printf("Toplantý tarihini girin (YYYY MM DD HH MM SS): ");
    scanf("%d %d %d %d %d %d", &meeting.year, &meeting.month, &meeting.day, &meeting.hour, &meeting.minute, &meeting.second);
    
    time_t meetingTime = convertToEpoch(meeting);
    time_t currentTime;
    time(&currentTime);

    if (meetingTime == -1) {
        printf("Hatalý tarih girdiniz!\n");
        return 1;
    }

    double diff = difftime(meetingTime, currentTime);

    if (diff < 0) {
        printf("? Bu toplantý tarihi geçti.\n");
    } else if (diff <= 3600) {
        printf("?? Toplantýya az kaldý! (%.0f saniye)\n", diff);
    } else {
        printf("? Toplantýya daha zaman var: %.0f saniye\n", diff);
    }

    return 0;
}


#include <iostream>

int isLeapYear(int year) {
    if (year == 2000 || year % 100 == 0 || year % 4) {
        return 0;
    }
    return 1;
}

int getDaysInMonth(int month, int year) {
    switch(month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 2:
            return isLeapYear(year) ? 29 : 28;
        default:
            return 30;
    }
}

int calculateDaysSince2000(int date, int month, int year) {
    int totalDays = 0;

    for (int i = 2000; i < year; i++) {
        totalDays += isLeapYear(i) ? 366 : 365;
    }

    for (int i = 1; i < month; i++) {
        totalDays += getDaysInMonth(i, year);
    }

    totalDays += date;
    return totalDays;
}

int main() {
    int date, month, year;

    int daysOfInput, daysOfEvent = calculateDaysSince2000(22, 12, 2023);

    std::scanf("%d-%d-%d", &date, &month, &year);
    daysOfInput = calculateDaysSince2000(date, month, year);

    int diffInDates = daysOfEvent - daysOfInput;

    std::cout << diffInDates << std::endl;
    return 0;
}
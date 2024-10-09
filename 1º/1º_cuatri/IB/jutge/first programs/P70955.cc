#include <iostream>

int main() {
    int year{0}, day{0}, hour{0}, minute{0}, seconds{0};
    std::cin >> year >> day >> hour >> minute >> seconds;
    std::cout << year * 31536000 + day * 86400 + hour * 3600 + minute * 60 + seconds << std::endl;

    minute = minute * 60;
    hour = hour * 60 * minute;
    day = day * 24 * hour;
    year = year * 365 * day;
    std::cout << year + day + hour + minute + seconds;
    return 0;
}
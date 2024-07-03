#include "Moment.h"
#include "Interval.h"

Moment::Moment() {
    time_t currentTime;
    time(&currentTime);
    localtime_s(&timeInfo, &currentTime);
}

Moment::Moment(int year, int month, int day, int hour, int min, int sec){

    timeInfo.tm_year = year - 1900; 
    timeInfo.tm_mon = month - 1;    
    timeInfo.tm_mday = day;
    timeInfo.tm_hour = hour;
    timeInfo.tm_min = min;
    timeInfo.tm_sec = sec;

}

std::string Moment::toISOString() const{

    std::stringstream ss;
    ss << std::put_time(&timeInfo, "%Y-%m-%dT%H:%M:%S");
    return ss.str();

}

Moment Moment::operator+(const Interval& interval) const{

    std::tm newTimeInfo = timeInfo;
    newTimeInfo.tm_year += interval.years;
    newTimeInfo.tm_mon += interval.months;
    newTimeInfo.tm_mday += interval.days;
    newTimeInfo.tm_hour += interval.hours;
    newTimeInfo.tm_min += interval.minutes;
    newTimeInfo.tm_sec += interval.seconds;

    mktime(&newTimeInfo);

    return Moment(newTimeInfo.tm_year + 1900, newTimeInfo.tm_mon + 1, newTimeInfo.tm_mday, newTimeInfo.tm_hour, newTimeInfo.tm_min, newTimeInfo.tm_sec);

}

Moment Moment::operator-(const Interval& interval) const{

    std::tm newTimeInfo = timeInfo;
    newTimeInfo.tm_year -= interval.years;
    newTimeInfo.tm_mon -= interval.months;
    newTimeInfo.tm_mday -= interval.days;
    newTimeInfo.tm_hour -= interval.hours;
    newTimeInfo.tm_min -= interval.minutes;
    newTimeInfo.tm_sec -= interval.seconds;

    return Moment(newTimeInfo.tm_year + 1900, newTimeInfo.tm_mon + 1, newTimeInfo.tm_mday, newTimeInfo.tm_hour, newTimeInfo.tm_min, newTimeInfo.tm_sec);

}

Interval Moment::operator-(const Moment& otherMoment) const{

    std::tm diff;
    std::memset(&diff, 0, sizeof(diff));
    time_t time1 = std::mktime(const_cast<std::tm*>(&otherMoment.timeInfo));
    time_t time2 = std::mktime(const_cast<std::tm*>(&timeInfo));
    int difference = std::difftime(time2, time1);

    if (difference < 0){

        difference = -difference;

    }

    int years = difference / (365 * 24 * 60 * 60);
    difference %= (365 * 24 * 60 * 60);
    int months = difference / (30 * 24 * 60 * 60);
    difference %= (30 * 24 * 60 * 60);
    int days = difference / (24 * 60 * 60);
    difference %= (24 * 60 * 60);
    int hours = difference / (60 * 60);
    difference %= (60 * 60);
    int minutes = difference / 60;
    difference %= 60;
    int seconds = difference;

    return Interval(years, months, days, hours, minutes, seconds);

}

Moment& Moment::operator+=(const Interval& interval){

    timeInfo.tm_year += interval.years;
    timeInfo.tm_mon += interval.months;
    timeInfo.tm_mday += interval.days;
    timeInfo.tm_hour += interval.hours;
    timeInfo.tm_min += interval.minutes;
    timeInfo.tm_sec += interval.seconds;
    std::mktime(&timeInfo); 
    return *this;

}

Moment& Moment::operator-=(const Interval& interval){

    timeInfo.tm_year -= interval.years;
    timeInfo.tm_mon -= interval.months;
    timeInfo.tm_mday -= interval.days;
    timeInfo.tm_hour -= interval.hours;
    timeInfo.tm_min -= interval.minutes;
    timeInfo.tm_sec -= interval.seconds;
    std::mktime(&timeInfo);
    return *this;

}

std::istream& operator>>(std::istream& is, Moment& moment){

    std::string input;
    is >> input;
    std::tm timeInfo = {};
    std::istringstream ss(input);
    ss >> std::get_time(&timeInfo, "%Y-%m-%dT%H:%M:%S");
    moment = Moment(timeInfo.tm_year + 1900, timeInfo.tm_mon + 1, timeInfo.tm_mday, timeInfo.tm_hour, timeInfo.tm_min, timeInfo.tm_sec);

    return is;

}

#include "Interval.h"

Interval::Interval() : years(0), months(0), days(0), hours(0), minutes(0), seconds(0) {}

Interval::Interval(int y, int m, int d, int h, int min, int sec)
    : years(y), months(m), days(d), hours(h), minutes(min), seconds(sec) {}

std::string Interval::toISOString() const{

    std::stringstream ss;
    ss << std::setfill('0') << std::setw(2) << years << "-" << std::setw(2) << months << "-" << std::setw(2) << days
        << " " << std::setw(2) << hours << ":" << std::setw(2) << minutes << ":" << std::setw(2) << seconds;

    return ss.str();

}

Interval Interval::operator+(const Interval& other) const{

    return Interval(years + other.years, months + other.months, days + other.days,
        hours + other.hours, minutes + other.minutes, seconds + other.seconds);

}

Interval Interval::operator-(const Interval& other) const{

    return Interval(years - other.years, months - other.months, days - other.days,
        hours - other.hours, minutes - other.minutes, seconds - other.seconds);

}

Interval Interval::operator*(double factor) const{

    int totalSeconds = years * 365 * 24 * 60 * 60 + months * 30 * 24 * 60 * 60 + days * 24 * 60 * 60 +
        hours * 60 * 60 + minutes * 60 + seconds;
    totalSeconds *= factor;
    int y = totalSeconds / (365 * 24 * 60 * 60);
    totalSeconds %= (365 * 24 * 60 * 60);
    int m = totalSeconds / (30 * 24 * 60 * 60);
    totalSeconds %= (30 * 24 * 60 * 60);
    int d = totalSeconds / (24 * 60 * 60);
    totalSeconds %= (24 * 60 * 60);
    int h = totalSeconds / (60 * 60);
    totalSeconds %= (60 * 60);
    int min = totalSeconds / 60;
    totalSeconds %= 60;
    int sec = totalSeconds;

    return Interval(y, m, d, h, min, sec);

}

Interval Interval::operator/(double divisor) const{

    return Interval(years / divisor, months / divisor, days / divisor,
        hours / divisor, minutes / divisor, seconds / divisor);

}

Interval& Interval::operator+=(const Interval& other){

    years += other.years;
    months += other.months;
    days += other.days;
    hours += other.hours;
    minutes += other.minutes;
    seconds += other.seconds;

    return *this;

}

Interval& Interval::operator-=(const Interval& other){

    years -= other.years;
    months -= other.months;
    days -= other.days;
    hours -= other.hours;
    minutes -= other.minutes;
    seconds -= other.seconds;

    return *this;

}

std::istream& operator>>(std::istream& is, Interval& interval){

    is >> interval.years >> interval.months >> interval.days >> interval.hours >> interval.minutes >> interval.seconds;
    return is;

}

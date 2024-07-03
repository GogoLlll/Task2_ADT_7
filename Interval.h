#pragma once

#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>

class Moment;

class Interval{

public:
    int years;
    int months;
    int days;
    int hours;
    int minutes;
    int seconds;

    Interval();
    Interval(int y, int m, int d, int h, int min, int sec);

    std::string toISOString() const;

    Interval operator+(const Interval& other) const;
    Interval operator-(const Interval& other) const;
    Interval operator*(double factor) const;
    Interval operator/(double divisor) const;
    Interval& operator+=(const Interval& other);
    Interval& operator-=(const Interval& other);

};

std::istream& operator>>(std::istream& is, Interval& interval);

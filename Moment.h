#ifndef MOMENT_H
#define MOMENT_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>

class Interval; 

class Moment{
private:
    std::tm timeInfo;

public:
    Moment();
    Moment(int year, int month, int day, int hour, int min, int sec);
    std::string toISOString() const;
    Moment operator+(const Interval& interval) const;
    Moment operator-(const Interval& interval) const;
    Interval operator-(const Moment& otherMoment) const;
    Moment& operator+=(const Interval& interval);
    Moment& operator-=(const Interval& interval);

};

std::istream& operator>>(std::istream& is, Moment& moment);

#endif

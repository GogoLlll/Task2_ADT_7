#include <iostream>
#include "Moment.h"
#include "Interval.h"

int main(){
    
    Moment currentMoment;
    std::cout << "Current moment: " << currentMoment.toISOString() << std::endl;

    Interval interval1(2, 1, 15, 0, 5, 0);
    std::cout << "Interval 1: " << interval1.toISOString() << std::endl;

    Interval interval2(1, 0, 1, 0, 0, 0);
    std::cout << "Interval 2: " << interval2.toISOString() << std::endl;

    Moment newMoment = currentMoment + interval1;
    std::cout << "New moment after interval 1: " << newMoment.toISOString() << std::endl;

    Interval diff = newMoment - currentMoment;
    std::cout << "Difference between new moment and current moment: " << diff.toISOString() << std::endl;

    Interval sum = interval1 + interval2;
    std::cout << "Sum of interval 1 and interval 2: " << sum.toISOString() << std::endl;

    Interval scaledInterval = interval1 * 2.5;
    std::cout << "Scaled interval 1 by factor 2.5: " << scaledInterval.toISOString() << std::endl;

    Interval dividedInterval = interval1 / 2.0;
    std::cout << "Divided interval 1 by 2.0: " << dividedInterval.toISOString() << std::endl;

    Moment unixTimestampMoment(2023, 3, 27, 12, 0, 0);
    std::cout << "Unix timestamp moment: " << unixTimestampMoment.toISOString() << std::endl;

    Interval unixTimestampInterval = unixTimestampMoment - currentMoment;
    std::cout << "Interval from current moment to Unix timestamp moment: " << unixTimestampInterval.toISOString() << std::endl;

    Interval interval3(1, 0, 0, 0, 0, 0);
    interval3 += interval1;
    std::cout << "Interval 3 after adding interval 1: " << interval3.toISOString() << std::endl;

    interval3 -= interval2;
    std::cout << "Interval 3 after subtracting interval 2: " << interval3.toISOString() << std::endl;

    newMoment += interval1;
    std::cout << "New moment after adding interval 1: " << newMoment.toISOString() << std::endl;

    newMoment -= interval1;
    std::cout << "New moment after subtracting interval 1: " << newMoment.toISOString() << std::endl;

    Moment inputMoment;
    std::cout << "Enter a moment in format YYYY-MM-DDTHH:MM:SS: ";
    std::cin >> inputMoment;
    std::cout << "You entered: " << inputMoment.toISOString() << std::endl;

    Interval inputInterval;
    std::cout << "Enter an interval in format years months days hours minutes seconds: ";
    std::cin >> inputInterval;
    std::cout << "You entered: " << inputInterval.toISOString() << std::endl;

    return 0;
}

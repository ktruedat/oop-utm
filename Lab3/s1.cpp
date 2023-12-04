#include <iostream>

class Date {
private:
    int day, month, year;

public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    Date operator+(int days) const {
        Date result = *this;
        result.day += days;
        if (result.month == 2 && result.day > 28) {
            if ((result.year % 4 == 0 && result.year % 100 != 0) || (result.year % 400 == 0)) {
                result.day = 29; 
            } else {
                result.day = 28; 
            }
        }
        return result;
    }

    Date operator-(int days) const {
        Date result = *this;
        result.day -= days;
        if (result.month == 2 && result.day <= 0) {
            if ((result.year % 4 == 0 && result.year % 100 != 0) || (result.year % 400 == 0)) {
                result.day = 29; 
            } else {
                result.day = 28; 
            }
        }
        return result;
    }


    friend Date& operator++(Date& date);       // Prefix ++
    friend Date operator++(Date& date, int);   // Postfix ++
    friend Date& operator--(Date& date);       // Prefix --
    friend Date operator--(Date& date, int);   // Postfix --
    friend std::ostream& operator<<(std::ostream& os, const Date& date);
};

Date& operator++(Date& date) {
    date = date + 1;
    return date;
}

Date operator++(Date& date, int) {
    Date result = date;
    ++date;
    return result;
}

Date& operator--(Date& date) {
    date = date - 1;
    return date;
}

Date operator--(Date& date, int) {
    Date result = date;
    --date;
    return result;
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << date.day << "." << date.month << "." << date.year;
    return os;
}

int main (){
    Date current(19, 11, 2023);
    std::cout<<current - 9<<std::endl;
    std::cout<<current + 9<<std::endl;
    current++;
    std::cout<<current<<std::endl;
    current--;
    std::cout<<current<<std::endl;

    return 0;
}
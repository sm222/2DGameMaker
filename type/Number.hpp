#ifndef NUMBER_HPP
#define NUMBER_HPP

#include <iostream>
#include <limits>
#include <stdexcept>

extern "C" {
    #include "../C_tools/inc/C_tool.h" 
}

class Number {
private:
    double value;

    // Helper function to check and handle overflow
    static double handleOverflow(double result);

public:
    Number();
    Number(double val);
    Number(float val);
    Number(int val);

    // Overload assignment operator
    Number& operator=(double val);
    Number& operator=(float val);
    Number& operator=(int val);

    // Overload addition operator
    Number operator+(const Number& other) const;
    Number operator+(double val) const;
    Number operator+(float val) const;
    Number operator+(int val) const;

    // Overload subtraction operator
    Number operator-(const Number& other) const;
    Number operator-(double val) const;
    Number operator-(float val) const;
    Number operator-(int val) const;

    // Overload multiplication operator
    Number operator*(const Number& other) const;
    Number operator*(double val) const;
    Number operator*(float val) const;
    Number operator*(int val) const;

    // Overload division operator
    Number operator/(const Number& other) const;
    Number operator/(double val) const;
    Number operator/(float val) const;
    Number operator/(int val) const;

    // Overload addition assignment operator
    Number& operator+=(const Number& other);
    Number& operator+=(double val);
    Number& operator+=(float val);
    Number& operator+=(int val);

    // Overload subtraction assignment operator
    Number& operator-=(const Number& other);
    Number& operator-=(double val);
    Number& operator-=(float val);
    Number& operator-=(int val);

    // Overload multiplication assignment operator
    Number& operator*=(const Number& other);
    Number& operator*=(double val);
    Number& operator*=(float val);
    Number& operator*=(int val);

    // Overload division assignment operator
    Number& operator/=(const Number& other);
    Number& operator/=(double val);
    Number& operator/=(float val);
    Number& operator/=(int val);

    // Overload increment operators
    Number& operator++(); // Prefix
    Number operator++(int); // Postfix

    // Overload decrement operators
    Number& operator--(); // Prefix
    Number operator--(int); // Postfix

    // Overload equality operator
    bool operator==(const Number& other) const;
    bool operator==(double val) const;
    bool operator==(float val) const;
    bool operator==(int val) const;

    // Overload inequality operator
    bool operator!=(const Number& other) const;
    bool operator!=(double val) const;
    bool operator!=(float val) const;
    bool operator!=(int val) const;

    // Overload less than operator
    bool operator<(const Number& other) const;
    bool operator<(double val) const;
    bool operator<(float val) const;
    bool operator<(int val) const;

    // Overload greater than operator
    bool operator>(const Number& other) const;
    bool operator>(double val) const;
    bool operator>(float val) const;
    bool operator>(int val) const;

    // Overload less than or equal to operator
    bool operator<=(const Number& other) const;
    bool operator<=(double val) const;
    bool operator<=(float val) const;
    bool operator<=(int val) const;

    // Overload greater than or equal to operator
    bool operator>=(const Number& other) const;
    bool operator>=(double val) const;
    bool operator>=(float val) const;
    bool operator>=(int val) const;

    // Overload output stream operator
    friend std::ostream& operator<<(std::ostream& os, const Number& r);

    // Overload input stream operator
    friend std::istream& operator>>(std::istream& is, Number& r);

    // Conversion operators
    operator double() const;
    operator float() const;
    operator int() const;
};


struct Vector2N{
    Number x;
    Number y;
};

#endif // NUMBER_HPP

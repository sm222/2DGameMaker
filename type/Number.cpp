#include "Number.hpp"

// Helper function to handle overflow
double Number::handleOverflow(double result) {
    if (result > std::numeric_limits<double>::max()) {
        LOG_MSG("class::Number numeric limits double max");
        return std::numeric_limits<double>::max();
    }
    if (result < std::numeric_limits<double>::lowest()) {
        LOG_MSG("class::Number numeric limits double lowest");
        return std::numeric_limits<double>::lowest();
    }
    return result;
}

// Default constructor
Number::Number() : value(0) {}

// Parameterized constructors
Number::Number(double val) : value(val) {}
Number::Number(float val) : value(val) {}
Number::Number(int val) : value(val) {}

// Overload assignment operator
Number& Number::operator=(double val) {
    value = val;
    return *this;
}

Number& Number::operator=(float val) {
    value = val;
    return *this;
}

Number& Number::operator=(int val) {
    value = val;
    return *this;
}

// Overload addition operator
Number Number::operator+(const Number& other) const {
    return Number(handleOverflow(value + other.value));
}

Number Number::operator+(double val) const {
    return Number(handleOverflow(value + val));
}

Number Number::operator+(float val) const {
    return Number(handleOverflow(value + val));
}

Number Number::operator+(int val) const {
    return Number(handleOverflow(value + val));
}

// Overload subtraction operator
Number Number::operator-(const Number& other) const {
    return Number(handleOverflow(value - other.value));
}

Number Number::operator-(double val) const {
    return Number(handleOverflow(value - val));
}

Number Number::operator-(float val) const {
    return Number(handleOverflow(value - val));
}

Number Number::operator-(int val) const {
    return Number(handleOverflow(value - val));
}

// Overload multiplication operator
Number Number::operator*(const Number& other) const {
    return Number(handleOverflow(value * other.value));
}

Number Number::operator*(double val) const {
    return Number(handleOverflow(value * val));
}

Number Number::operator*(float val) const {
    return Number(handleOverflow(value * val));
}

Number Number::operator*(int val) const {
    return Number(handleOverflow(value * val));
}

// Overload division operator
Number Number::operator/(const Number& other) const {
    if (other.value == 0) {
        LOG_MSG("class::Number number divide by 0 return nan");
        return Number(std::numeric_limits<double>::quiet_NaN());
    }
    return Number(value / other.value);
}

Number Number::operator/(double val) const {
    if (val == 0) {
        LOG_MSG("class::Number double divide by 0 return nan");
        return Number(std::numeric_limits<double>::quiet_NaN());
    }
    return Number(value / val);
}

Number Number::operator/(float val) const {
    if (val == 0) {
        LOG_MSG("class::Number float divide by 0 return nan");
        return Number(std::numeric_limits<double>::quiet_NaN());
    }
    return Number(value / val);
}

Number Number::operator/(int val) const {
    if (val == 0) {
        LOG_MSG("class::Number int divide by 0 return nan");
        return Number(std::numeric_limits<double>::quiet_NaN());
    }
    return Number(value / val);
}

// Overload addition assignment operator
Number& Number::operator+=(const Number& other) {
    value = handleOverflow(value + other.value);
    return *this;
}

Number& Number::operator+=(double val) {
    value = handleOverflow(value + val);
    return *this;
}

Number& Number::operator+=(float val) {
    value = handleOverflow(value + val);
    return *this;
}

Number& Number::operator+=(int val) {
    value = handleOverflow(value + val);
    return *this;
}

// Overload subtraction assignment operator
Number& Number::operator-=(const Number& other) {
    value = handleOverflow(value - other.value);
    return *this;
}

Number& Number::operator-=(double val) {
    value = handleOverflow(value - val);
    return *this;
}

Number& Number::operator-=(float val) {
    value = handleOverflow(value - val);
    return *this;
}

Number& Number::operator-=(int val) {
    value = handleOverflow(value - val);
    return *this;
}

// Overload multiplication assignment operator
Number& Number::operator*=(const Number& other) {
    value = handleOverflow(value * other.value);
    return *this;
}

Number& Number::operator*=(double val) {
    value = handleOverflow(value * val);
    return *this;
}

Number& Number::operator*=(float val) {
    value = handleOverflow(value * val);
    return *this;
}

Number& Number::operator*=(int val) {
    value = handleOverflow(value * val);
    return *this;
}

// Overload division assignment operator
Number& Number::operator/=(const Number& other) {
    if (other.value == 0) {
        LOG_MSG("class::Number number divide equal by 0 return nan");
        value = std::numeric_limits<double>::quiet_NaN();
    } else {
        value /= other.value;
    }
    return *this;
}

Number& Number::operator/=(double val) {
    if (val == 0) {
        LOG_MSG("class::Number double divide equal by 0 return nan");
        value = std::numeric_limits<double>::quiet_NaN();
    } else {
        value /= val;
    }
    return *this;
}

Number& Number::operator/=(float val) {
    if (val == 0) {
        LOG_MSG("class::Number float divide equal by 0 return nan");
        value = std::numeric_limits<double>::quiet_NaN();
    } else {
        value /= val;
    }
    return *this;
}

Number& Number::operator/=(int val) {
    if (val == 0) {
        LOG_MSG("class::Number int divide equal by 0 return nan");
        value = std::numeric_limits<double>::quiet_NaN();
    } else {
        value /= val;
    }
    return *this;
}

// Overload increment operators
Number& Number::operator++() {
    value = handleOverflow(value + 1);
    return *this;
}

Number Number::operator++(int) {
    Number temp = *this;
    value = handleOverflow(value + 1);
    return temp;
}

// Overload decrement operators
Number& Number::operator--() {
    value = handleOverflow(value - 1);
    return *this;
}

Number Number::operator--(int) {
    Number temp = *this;
    value = handleOverflow(value - 1);
    return temp;
}

// Overload equality operator
bool Number::operator==(const Number& other) const {
    return value == other.value;
}

bool Number::operator==(double val) const {
    return value == val;
}

bool Number::operator==(float val) const {
    return value == val;
}

bool Number::operator==(int val) const {
    return value == val;
}

// Overload inequality operator
bool Number::operator!=(const Number& other) const {
    return value != other.value;
}

bool Number::operator!=(double val) const {
    return value != val;
}

bool Number::operator!=(float val) const {
    return value != val;
}

bool Number::operator!=(int val) const {
    return value != val;
}

// Overload less than operator
bool Number::operator<(const Number& other) const {
    return value < other.value;
}

bool Number::operator<(double val) const {
    return value < val;
}

bool Number::operator<(float val) const {
    return value < val;
}

bool Number::operator<(int val) const {
    return value < val;
}

// Overload greater than operator
bool Number::operator>(const Number& other) const {
    return value > other.value;
}

bool Number::operator>(double val) const {
    return value > val;
}

bool Number::operator>(float val) const {
    return value > val;
}

bool Number::operator>(int val) const {
    return value > val;
}

// Overload less than or equal to operator
bool Number::operator<=(const Number& other) const {
    return value <= other.value;
}

bool Number::operator<=(double val) const {
    return value <= val;
}

bool Number::operator<=(float val) const {
    return value <= val;
}

bool Number::operator<=(int val) const {
    return value <= val;
}

// Overload greater than or equal to operator
bool Number::operator>=(const Number& other) const {
    return value >= other.value;
}

bool Number::operator>=(double val) const {
    return value >= val;
}

bool Number::operator>=(float val) const {
    return value >= val;
}

bool Number::operator>=(int val) const {
    return value >= val;
}

// Overload output stream operator
std::ostream& operator<<(std::ostream& os, const Number& r) {
    os << r.value;
    return os;
}

// Overload input stream operator
std::istream& operator>>(std::istream& is, Number& r) {
    is >> r.value;
    return is;
}

// Conversion operators
Number::operator double() const {
    return value;
}

Number::operator float() const {
    if (value > std::numeric_limits<float>::max()) {
        return std::numeric_limits<float>::max();
    }
    if (value < std::numeric_limits<float>::lowest()) {
        return std::numeric_limits<float>::lowest();
    }
    return static_cast<float>(value);
}

Number::operator int() const {
    if (value > std::numeric_limits<int>::max()) {
        return std::numeric_limits<int>::max();
    }
    if (value < std::numeric_limits<int>::lowest()) {
        return std::numeric_limits<int>::lowest();
    }
    return static_cast<int>(value);
}


int main() {
    Number a = 0;
    double b = 0;

    a / 0;

    {
        TIME_START;
        while (b < 2000000000.0) {
            b += 1.10;
        }
        std::cout << TIME_STOP << "\n";
    }
    {
        TIME_START;
        while (a < 2000000000.0) {
            a += 1.10;
        }
        std::cout << TIME_STOP << "\n";
    }
    return 0;
}
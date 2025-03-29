#pragma once

#include <iostream>

enum class Currency : unsigned int{
    RUB,
    USD,
    EUR
};

namespace std{
    std::string to_string(Currency currency){
        switch(currency){
            case Currency::RUB:
                return "RUB";
            case Currency::USD:
                return "USD";
            case Currency::EUR:
                return "EUR";
        }
        throw std::runtime_error("Unknown currency!");
    }
}

class Credit{
    std::string name;
    unsigned long amount;
    Currency currency;
    float percent;
public:
    Credit(const std::string& name = "", unsigned long amount = 0, Currency currency = Currency::RUB, float percent = 0.f) : 
                            name(name), amount(amount), currency(currency), percent(percent) {}
    
    Credit(const Credit&) = default;
    Credit& operator=(const Credit&) = default;

    Credit(Credit&&) = default;
    Credit& operator=(Credit&&) = default;

    friend std::ostream& operator<<(std::ostream&, const Credit&);

    bool operator==(const Credit& other) const{
        return percent == other.percent;
    }
    bool operator!=(const Credit& other) const {
        return percent != other.percent;
    }
    bool operator<(const Credit& other) const {
        return percent < other.percent;
    }
    bool operator<=(const Credit& other) const {
        return (*this < other) || (*this == other);
    }
    bool operator>(const Credit& other) const {
        return other < *this;
    }
    bool operator>=(const Credit& other) const {
        return other <= *this;
    }
};


std::ostream& operator<<(std::ostream& out, const Credit& credit){
    out << credit.name << " " << credit.amount << " " << std::to_string(credit.currency) << " " << credit.percent;
    return out;
}
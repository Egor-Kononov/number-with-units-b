#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <utility>

namespace ariel{

    static std::unordered_map<std::string,std::unordered_map<std::string,double>> data;

    class NumberWithUnits
    {
    private:
        double val;
        std::string unit;
    public:
        NumberWithUnits(double value,const std::string& units);
        static void read_units(std::ifstream& units_file);
      
        NumberWithUnits& operator--();
        NumberWithUnits operator--(int);
        NumberWithUnits& operator++();
        NumberWithUnits operator++(int);

        friend NumberWithUnits operator*(const NumberWithUnits& n, double num);
        friend NumberWithUnits operator*(double num,const NumberWithUnits& n);

        NumberWithUnits& operator+=(const NumberWithUnits& other);
        NumberWithUnits& operator-=(const NumberWithUnits& other);
        NumberWithUnits operator + (const NumberWithUnits& other)const;
        NumberWithUnits operator + ()const;
        NumberWithUnits operator - (const NumberWithUnits& other)const;
        NumberWithUnits operator - ()const;


        friend bool operator==(const NumberWithUnits& a, const NumberWithUnits& b);
        friend bool operator!=(const NumberWithUnits& a, const NumberWithUnits& b);
        friend bool operator>(const NumberWithUnits& a, const NumberWithUnits& b);
        friend bool operator>=(const NumberWithUnits& a, const NumberWithUnits& b);
        friend bool operator<(const NumberWithUnits& a, const NumberWithUnits& b);
        friend bool operator<=(const NumberWithUnits& a, const NumberWithUnits& b);


        friend std::ostream& operator << (std::ostream& os, const NumberWithUnits& num);
        friend std::istream& operator >> (std::istream& is, NumberWithUnits& num);
    };     
}

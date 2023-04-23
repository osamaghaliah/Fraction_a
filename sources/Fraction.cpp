#include <iostream>
#include "Fraction.hpp"

using namespace std;

namespace ariel {
    static Fraction TmpNull(0, 1);

    // Constructors.
    Fraction::Fraction(int complete) {

    }

    Fraction::Fraction(int numerator, int denominator) {
    
    }

    // Getters & Setters.
    int Fraction::getNumerator() {
        
        return 0;
    }

    int Fraction::getDenominator() {
        
        return 0;
    }

    void Fraction::setNumerator (int numerator) {
        
    }

    void Fraction::setDenominator(int denominator) {

    }


    // Operators.
    Fraction& operator + (const Fraction& fraction1, const Fraction& fraction2) {
        
        return TmpNull;
    }

    Fraction& operator + (const Fraction& fraction2, const float& fraction1) {
        
        return TmpNull;
    }

    Fraction& operator + (const float& fraction1, const Fraction& fraction2) {
        
        return TmpNull;
    }


    Fraction& operator - (const Fraction& fraction1, const Fraction& fraction2) {

        return TmpNull;
    }

    Fraction& operator - (const Fraction& fraction1, const float& fraction2) {

        return TmpNull;
    }

    Fraction& operator - (const float& fraction1, const Fraction& fraction2) {

        return TmpNull;
    }

    Fraction& operator / (const Fraction& fraction1, const Fraction& fraction2) {

        return TmpNull;
    }

    Fraction& operator * (const Fraction& fraction1, const Fraction& fraction2) {

        return TmpNull;
    }

    Fraction& operator * (const float& fraction1, const Fraction& fraction2) {
        
        return TmpNull;
    }

    Fraction& operator ++ (Fraction& fraction) {

        return TmpNull;
    }

    Fraction& operator ++ (Fraction& fraction, int) {

        return TmpNull;
    }

    Fraction& operator -- (Fraction& fraction) {

        return TmpNull;
    }

    Fraction& operator -- (Fraction& fraction, int) {

        return TmpNull;
    }

    bool operator < (const Fraction& fraction1, const Fraction& fraction2) {

        return true;
    }

    bool operator > (const Fraction& fraction1, const Fraction& fraction2) {

        return true;
    }

    bool operator > (const Fraction& fraction1, const float& fraction2) {

        return true;
    }


    bool operator <= (const Fraction& fraction1, const Fraction& fraction2) {

        return true;
    }

    bool operator >= (const Fraction& fraction1, const Fraction& fraction2) {

        return true;
    }

    bool operator == (const Fraction& fraction1, const Fraction& fraction2) {
        
        return true;
    }

    bool operator == (const Fraction& fraction1, const float& fraction2) {
        
        return true;
    }
    
    
    bool operator == (const float& fraction2, const Fraction& fraction1) {

        return true;
    }

    ostream& operator << (ostream& output, Fraction& fraction) {

        return cout;
    }

    ostream& operator << (Fraction& fraction, ostream& output) {

        return cout;
    }

    ostream& operator >> (istream& output, Fraction& fraction) {

        return cout;
    }

    // Printing & Calculations.
    string Fraction::details() {

        return "";
    }

    int Fraction::getGCF() {
        
        return 0;
    }
    void Fraction::simplify() {

    }
}
#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>

using namespace std;

namespace ariel {
    
    class Fraction {
        private:
            int numerator;
            int denominator;
        
        public:
            // Constructors.
            Fraction(int complete);
            Fraction(int numerator, int denominator);

            // Getters & setters.
            int getNumerator();
            int getDenominator();
            void setNumerator (int numerator);
            void setDenominator(int denominator);

            // Operators.
            friend Fraction& operator + (const Fraction& fraction1, const Fraction& fraction2);
            friend Fraction& operator + (const Fraction& fraction1, const float& fraction2);
            friend Fraction& operator + (const float& fraction1, const Fraction& fraction2);
            friend Fraction& operator - (const Fraction& fraction1, const Fraction& fraction2);
            friend Fraction& operator - (const Fraction& fraction1, const float& fraction2);
            friend Fraction& operator - (const float& fraction1, const Fraction& fraction2); 
            friend Fraction& operator / (const Fraction& fraction1, const Fraction& fraction2); 
            friend Fraction& operator * (const Fraction& fraction1, const Fraction& fraction2);
            friend Fraction& operator * (const float& fraction1, const Fraction& fraction2);
            friend Fraction& operator ++ (Fraction& fraction);
            friend Fraction& operator ++ (Fraction& fraction, int);
            friend Fraction& operator -- (Fraction& fraction);
            friend Fraction& operator -- (Fraction& fraction, int);

            friend bool operator < (const Fraction& fraction1, const Fraction& fraction2);
            friend bool operator > (const Fraction& fraction1, const Fraction& fraction2);
            friend bool operator > (const Fraction& fraction1, const float& fraction2);
            friend bool operator <= (const Fraction& fraction1, const Fraction& fraction2);
            friend bool operator >= (const Fraction& fraction1, const Fraction& fraction2);
            friend bool operator == (const Fraction& fraction1, const Fraction& fraction2);
            friend bool operator == (const Fraction& fraction1, const float& fraction2);
            friend bool operator == (const float& fraction2, const Fraction& fraction1);


            friend ostream& operator << (ostream& output, Fraction& fraction);
            friend ostream& operator << (Fraction& fraction, ostream& output);
            friend ostream& operator >> (istream& output, Fraction& fraction);
            
            // Printing & Calculations.
            string details();
            int getGCF();
            void simplify();
    };
};

#endif
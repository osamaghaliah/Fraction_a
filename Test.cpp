#include "doctest.h"
#include "sources/Fraction.hpp"
#include <vector>
#include <sstream>

using namespace ariel;

TEST_CASE("Fractions Initializations & Retrieving Correctness") {
    // Diversity of initializations.
    CHECK_NOTHROW(Fraction(1, 3));
    CHECK_NOTHROW(Fraction(2, 10));
    CHECK_NOTHROW(Fraction(0, 5) = Fraction(0));
    CHECK_NOTHROW(Fraction(1) = Fraction(1, 1));
    CHECK_NOTHROW(Fraction(4) = Fraction(8, 2));
    CHECK_THROWS(Fraction(5, 0)); // Denominator is zero.
    CHECK_THROWS(Fraction(999, 0)); // Denominator is zero.
    CHECK(Fraction(10, 5) == Fraction(2));
    
    Fraction f1(1, 3);
    Fraction f2(2, 10);

    CHECK(f1.getNumerator() == 1);
    CHECK(f1.getDenominator() == 3);
    CHECK_THROWS(f1.setDenominator(0));

    CHECK(f2.getNumerator() == 2);
    CHECK(f2.getDenominator() == 10);
    CHECK_THROWS(f2.setNumerator(0));
}

TEST_CASE("Simplification Of Fractions Correctness") {
    // Initialization setup.
    Fraction f1(8, 6);
    Fraction f2(16, 12);

    // Before any simplification.
    CHECK(f1 == f2);

    // Finding the greatest common factor between numerators and denominators.
    // Then, simplfying the two fractions accordingly.
    CHECK(f1.getGCF() == 2);
    CHECK(f2.getGCF() == 4);
    CHECK_NOTHROW(f1.simplify());
    CHECK_NOTHROW(f2.simplify());

    // After simplifying the two fractions.
    CHECK(f1 == f2);

    // Double-checking
    CHECK((f1.getNumerator() == 4 && f2.getNumerator() == 4));
    CHECK((f1.getDenominator() == 3 && f2.getDenominator() == 3));
    CHECK(f1 == Fraction(4, 3));
    CHECK(f2 == Fraction(4, 3));
}

TEST_CASE("PLUS (+) Operator Correctness") {
    // Extreme cases.
    SUBCASE("Extreme Cases") {
        CHECK_THROWS(Fraction(15, 0) + Fraction(15, 0) = Fraction(30, 0));
        CHECK_THROWS(Fraction(0, 0) + Fraction(0, 7) = Fraction(0, 0));
        CHECK_THROWS(Fraction(-1, 5) + Fraction(1, 5) = Fraction(0, 0));
        CHECK_NOTHROW(Fraction(-1, 5) + Fraction(1, 5) = Fraction(0));
        CHECK_NOTHROW(Fraction(0, 777) + Fraction(0, 888) = Fraction(0, 999));
    }

    // Adding two fractions as objects.
    SUBCASE("Adding Two Fractions As Objects") {
        CHECK(Fraction(3, 5) + Fraction(1, 1) == Fraction(8, 5));
        CHECK(Fraction(0, 5) + Fraction(1, 2) == Fraction(1, 2));
        CHECK(Fraction(8, 6) + Fraction(16, 12) == Fraction(8, 3));
    }
    
    // Adding two fractions such that - the first addend is in a double form and the second addend is as an object.
    SUBCASE("Adding Two Fractions As A Double & An Object") {
        CHECK(0.6 + Fraction(3, 5) == Fraction(6, 5));
        CHECK(1.3 + Fraction(13, 10) == Fraction(13, 5));
    }

    // Adding two fractions such that - the first addend is in a double form and the second addend is as an object.
    SUBCASE("Adding Two Fractions As An Object & A Double") {
        CHECK(Fraction(3, 5) + 0.6 == Fraction(6, 5));
        CHECK(Fraction(13, 10) + 1.3 == Fraction(13, 5));
    }
}

TEST_CASE("MINUS (-) Operator Correctness") {
    // Extreme cases
    SUBCASE("Extreme Cases") {
        CHECK_THROWS(Fraction(7, 0) - Fraction(7, 0) = Fraction(0, 0));
        CHECK_NOTHROW(Fraction(7, 0) - Fraction(7, 0) = Fraction(0));
        CHECK_NOTHROW(Fraction(5, -10) - Fraction(1, -2) = Fraction(0));
    }

    // Subtracting two fractions as objects.
    SUBCASE("Subtracting Two Fractions As Objects") {
        CHECK(Fraction(3, 5) - Fraction(1, 1) == Fraction(-2, 5));
        CHECK(Fraction(0, 5) - Fraction(1, 2) == Fraction(1, -2));
        CHECK(Fraction(8, 6) - Fraction(16, 12) == Fraction(0));
    }
    
    // Subtracting two fractions such that - the first minued is in a double form and the second minued is as an object.
    SUBCASE("Subtracting Two Fractions As A Double & An Object") {
        CHECK(0.6 - Fraction(3, 5) == Fraction(0));
        CHECK(1.3 - Fraction(12, 10) == Fraction(1, 10));
    }

    // Subtracting two fractions such that - the first minued is in a double form and the second minued is as an object.
    SUBCASE("Subtraction Two Fractions As An Object & A Double") {
        CHECK(Fraction(3, 5) - (-0.6) == Fraction(6, 5));
        CHECK(Fraction(13, 10) - (-70) == Fraction(713, 10));
    }
}

TEST_CASE("MULTIPLICATION (*) Operator Correctness") {
    // Initialization setup.
    Fraction f1(4, 8), f2(1, 2), f3(3, 18), f4(1, 6);

    // Making sure that the multiplication operator successfully multiplies two legal fractions.
    // Then, making sure it fails to multiply two illegal fractions.
    SUBCASE("Multiplication Operator Attempt") {
        CHECK_NOTHROW(f1 * f2);
        CHECK_NOTHROW(f3 * f4);
        CHECK_NOTHROW(0.25 * f1);
        CHECK_NOTHROW(0.789 * f4);
        CHECK_THROWS(f1 * Fraction(0, 0));
        CHECK_THROWS(2.75 * Fraction(7, 0));
    }

    // Multiplying two fractions as objects.
    SUBCASE("Multiplying Two Fractions As Objects") {
        CHECK(f1 * f2 == Fraction(1, 4));
        CHECK(f3 * f4 == Fraction(1, 36));
    }

    // Multipyling two fractions as a double and an object.
    SUBCASE("Multiplying Two Fractions As A Double & An Object") {
        CHECK(0.5 * f2 == Fraction(1, 4));
        CHECK(0.167 * f4 == Fraction(1, 36));
    }
}

TEST_CASE("DIVISION (/) Operator Correctness") {
    // Initialization setup.
    Fraction f1(1, 2), f2(7, 8), f3(5, 7), f4(2, 3);

    // Making sure that the division operator successfully divides two legal fractions.
    // Then, making sure it fails to divide two illegal fractions.
    SUBCASE("Division Operator Attempt") {
        CHECK_NOTHROW(Fraction(0) / f2);
        CHECK_NOTHROW(f1 / f2);
        CHECK_NOTHROW(f3 / f4);
        CHECK_NOTHROW(f2 / f3);
        CHECK_NOTHROW(f4 / f1);
        CHECK_THROWS(f1 / Fraction(0));
        CHECK_THROWS(f2 / Fraction(7, 0));
    }
    
    // Dividing two fractions as objects.
    SUBCASE("Dividing Two Fractions As Objects") {
        CHECK(f1 / f2 == Fraction(4, 7));
        CHECK(f3 / f4 == Fraction(15, 14));
        CHECK(Fraction(0) / f1 == Fraction(0));
    }
}

TEST_CASE("INCREMENT (++) Operator Correctness") {
    // Initialization setup.
    Fraction f1(0), f2(1, 2), f3(2, 4), f4(8, 8);
    vector <Fraction> fracs {f1, f2, f3, f4};

    // Performing the increment operator on all fractions.
    for (size_t i = 0; i < fracs.size(); i++) {
        CHECK_NOTHROW(fracs[i]++);
    }

    // Making sure that the increment operator has successfully increased the whole fractions by 1.
    CHECK(f1 == Fraction(1));
    CHECK(f2 == Fraction(3, 2));
    CHECK(f3 == Fraction(3, 2));
    CHECK(f4 == Fraction(2));
}

TEST_CASE("DECREMENT (--) Operator Correctness") {
    // Initialization setup.
    Fraction f1(0), f2(1, 2), f3(2, 4), f4(8, 8);
    vector <Fraction> fracs {f1, f2, f3, f4};

    // Performing the decrement operator on all fractions.
    for (size_t i = 0; i < fracs.size(); i++) {
        CHECK_NOTHROW(fracs[i]--);
    }

    // Making sure that the decrement operator has successfully decreased the whole fractions by 1.
    CHECK(f1 == Fraction(-1));
    CHECK(f2 == Fraction(-1, 2));
    CHECK(f3 == Fraction(-1, 2));
    CHECK(f4 == Fraction(0));
}

TEST_CASE("RELATIONAL Operators Correctness") {
    // Initialization setup.
    Fraction f1(4, 6), f2(2, 3), f3(1, 10);

    // Testing binary asserts.
    CHECK(f2 > f3);
    CHECK_FALSE(f2 < f3);
    CHECK(f3 < f2);
    CHECK_FALSE(f3 > f2);
    CHECK(f1 == f2);
    CHECK(0.1 == f3);

    f3++;

    CHECK(f3 > 0.1);
    CHECK(f3 == 1.1);
    CHECK(f3 >= f1);
    CHECK_FALSE(f3 <= f1);
}

TEST_CASE("PUT-TO Operator Correctness") {
    Fraction f1(1, 5);
    ostringstream output;

    // Making sure that the content of the object has been successfully written.
    CHECK_NOTHROW(output << f1 << endl);

    CHECK(output.str() == "1/5\n");
}

TEST_CASE("GET-FROM Operator Correctness") {
    Fraction f1(1, 5);
    istringstream input;

    // Making sure that the content of the object has been successfully read.
    CHECK_NOTHROW(input >> f1);

    CHECK(input.str() == "1/5");
}

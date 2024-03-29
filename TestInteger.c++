// --------------------------------
// projects/integer/TestInteger.c++
// Copyright (C) 2014
// Glenn P. Downing
// --------------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

/*
Google Test Libraries:
    % ls -al /usr/include/gtest/
    ...
    gtest.h
    ...

    % locate libgtest.a
    /usr/lib/libgtest.a

    % locate libpthread.a
    /usr/lib/x86_64-linux-gnu/libpthread.a
    /usr/lib32/libpthread.a

    % locate libgtest_main.a
    /usr/lib/libgtest_main.a

To compile the test:
    % g++-4.7 -fprofile-arcs -ftest-coverage -pedantic -std=c++11 -Wall Integer.c++ TestInteger.c++ -o TestInteger -lgtest -lgtest_main -lpthread

To run the test:
    % valgrind TestInteger

To obtain coverage of the test:
    % gcov-4.7 -b Integer.c++ TestInteger.c++
*/

// --------
// includes
// --------

#include <algorithm> // equal
#include <cstring>   // strcmp
#include <sstream>   // ostringstream
#include <stdexcept> // invalid_argument
#include <string>    // ==

#include "gtest/gtest.h"

#include "Integer.h"

// // -----------
// // TestInteger
// // -----------

// // -----------------
// // shift_left_digits
// // -----------------

TEST(Integer, shift_left_digits) {
    const int a[] = {2, 3, 4};
    const int b[] = {2, 3, 4, 0, 0};
          int x[10];
    const int* p = shift_left_digits(a, a + 3, 2, x);
    ASSERT_EQ(5, p - x);
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, b));}

TEST(Integer, shift_left_digits_2) {
    int a[3] = {1,3,4};
    int x[10];
    const int *p = shift_left_digits(a, a + 1, 2, x);
    ASSERT_EQ(3, p-x);
}

TEST(Integer, shift_left_digits_3){
    const int a[] = {2, 3, 4};
    const int b[] = {2, 3, 4};
          int x[10];
    const int* p = shift_left_digits(a, a + 3, 0, x);
    ASSERT_EQ(3, p - x);
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, b));
}

// TEST(Integer, shift_left_digits_4){
//     const vector<int> a = {2, 3, 4};
//     const vector<int> b = {2, 3, 4};
//           vector<int> x(4,0);
//     const auto p = shift_left_digits(a.begin(), a.end(), 1, x.begin());
//     // for(int i = 0; i < x.size(); ++i)
//     //     cout<<x[i]<<" ";
//     // cout<<endl;
//     ASSERT_EQ(4, x.size());
//     ASSERT_TRUE(0 == x[3]);
// }

// ------------------
// shift_right_digits
// ------------------

TEST(Integer, shift_right_digits) {
    const int a[] = {2, 3, 4};
    const int b[] = {2};
          int x[10];
    const int* p = shift_right_digits(a, a + 3, 2, x);
    ASSERT_EQ(1, p - x);
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, b));}

TEST(Integer, shift_right_digits_2){
    const int a[] = {2, 3, 4};
    const int b[] = {2, 3, 4};
          int x[10];
    const int* p = shift_right_digits(a, a +3, 0, x);
    ASSERT_EQ(3, p - x);
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, b));
}

// TEST(Integer, shift_right_digits_3){
//     const int a[] = {2,3,4};
//     const int b[] = {0};
//           int x[10];
//     const int *p = shift_right_digits(a, a+3, 3, x);
//     ASSERT_EQ(0, x[0]);
// }

// -----------
// plus_digits
// -----------

TEST(Integer, plus_digits) {
    const int a[] = {2, 3, 4};
    const int b[] = {5, 6, 7};
    const int c[] = {8, 0, 1};
          int x[10];
    const int* p = plus_digits(a, a + 3, b, b + 3, x);
    ASSERT_EQ(3, p - x);
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}

TEST(Integer, plus_digits1) {
    const int a[] = {0,0,0,0,0,0};
    const int b[] = {1,6,3,8};
    const int c[] = {0,0,1,6,3,8};
          int x[10];
    const int* p = plus_digits(a, a + 6, b, b + 4, x);
    ASSERT_EQ(6, p - x);
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}



TEST(Integer, plus_digits2) {
    const int a[] = {9, 9, 5};
    const int b[] = {9, 9, 5};
    const int c[] = {1, 9, 9, 0};
          int x[10];
    const int* p = plus_digits(a, a + 3, b, b + 3, x);
    ASSERT_EQ(4, p - x);
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}

TEST(Integer, plus_digits3) {
    const int a[] = {5};
    const int b[] = {9, 9, 5};
    const int c[] = {1, 0, 0, 0};
          int x[10];
    const int* p = plus_digits(a, a + 1, b, b + 3, x);
    ASSERT_EQ(4, p - x);
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}

TEST(Integer, plus_digits4) {
    const int a[] = {5};
    const int b[] = {9, 9, 5};
    const int c[] = {1, 0, 0, 0};
          int x[10];
    const int* p = plus_digits(b, b + 3, a, a + 1, x);
    ASSERT_EQ(4, p - x);
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}

// // ------------
// // minus_digits
// // ------------

TEST(Integer, minus_digits) {
    const int a[] = {8, 0, 1};
    const int b[] = {5, 6, 7};
    const int c[] = {2, 3, 4};
          int x[10];
    const int* p = minus_digits(a, a + 3, b, b + 3, x);
    // for(int i =0; i < 3; i++)
    //     cout<<x[i] << " ";
    // cout<<endl;
    ASSERT_EQ(3, p - x);
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}

TEST(Integer, minus_digits2) {
    const int a[] = {8, 0, 1};
    const int b[] = {6, 1};
    const int c[] = {7, 4, 0};
          int x[10];
    const int* p = minus_digits(a, a + 3, b, b + 2, x);
    // for(int i =0; i < 3; i++)
    //     cout<<x[i] << " ";
    // cout<<endl;
    ASSERT_EQ(3, p - x);
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}

TEST(Integer, minus_digits3) {
    const int a[] = {9};
    const int b[] = {9};
    const int c[] = {0};
          int x[10];
    const int* p = minus_digits(a, a + 1, b, b + 1, x);
    // for(int i =0; i < 3; i++)
    //     cout<<x[i] << " ";
    // cout<<endl;
    ASSERT_EQ(1, p - x);
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}

// -----------------
// multiplies_digits
// -----------------

TEST(Integer, multiplies_digits) {
    const int a[] = {2, 3, 4};
    const int b[] = {5, 6, 7};
    const int c[] = {1, 3, 2, 6, 7, 8};
          int x[10];
    const int* p = multiplies_digits(a, a + 3, b, b + 3, x);
    ASSERT_EQ(6, p - x);
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}

TEST(Integer, multiplies_digits2) {
    const int a[] = { 4};
    const int b[] = { 7};
    const int c[] = {2, 8};
          int x[10];
    const int* p = multiplies_digits(a, a + 1, b, b + 1, x);

    ASSERT_EQ(2, p - x);
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}

// // --------------
// // compare
// // --------------
TEST(Integer, compare) {
    const int a[] = { 8};
    const int b[] = { 7};

    ASSERT_FALSE(compare(a, a+1, b, b + 1));}

TEST(Integer, compare1) {
    const int a[] = { 8};
    const int b[] = { 8};

    ASSERT_TRUE(compare(a, a+1, b, b + 1));}

TEST(Integer, compare2) {
    const int a[] = { 8, 1};
    const int b[] = { 8, 0};

    ASSERT_FALSE(compare(a, a+2, b, b + 2));}


// --------------
// divides_digits
// --------------
TEST(Integer, divides_digits) {
    const int a[] = {2, 5, 0};
    const int b[] = {1,2};
    const int c[] = {0};
          int x[10];
    const int* p = divides_digits(a, a + 3, b, b + 2, x);
    ASSERT_EQ(1, p - x);
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}

TEST(Integer, divides_digits1) {
    const int a[] = {2, 5, 0};
    const int b[] = {1,2};
    const int c[] = {2,3};
          int x[10];
    const int* p = divides_digits( b, b + 2, a, a + 3, x);
    ASSERT_EQ(2, p - x);
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}

// -----------
// constructor
// -----------

TEST(Integer, constructor_1) {
    try {
        const Integer<int> x("abc");
        ASSERT_TRUE(false);}
    catch (std::invalid_argument& e) {
        ASSERT_STREQ("Integer()", e.what());}}

TEST(Integer, constructor_2) {
    try {
        const Integer<int> x("2");}
    catch (std::invalid_argument& e) {
        ASSERT_TRUE(false);}}

TEST(Integer, constructor_3) {
    try {
        const Integer<int> x(2);}
    catch (std::invalid_argument& e) {
        ASSERT_TRUE(false);}}

TEST(Integer, constructor_4) {
    try {
        const Integer<int> x(250);
    }catch (std::invalid_argument& e){
        ASSERT_TRUE(false);}
}

TEST(Integer, constructor_5) {
    try {
        const Integer<int> x(-250);
    }catch (std::invalid_argument& e){
        ASSERT_TRUE(false);
    }
}

TEST(Integer, constructor_6) {
    try {
        const Integer<int> x(0);
    }catch (std::invalid_argument& e){
        ASSERT_TRUE(false);
    }
}

// // ---
// // abs
// // ---

// TEST(Integer, abs_1) {
//     try {
//         Integer<int>  x = -98765;
//         Integer<int>& y = x.abs();
//         ASSERT_EQ(98765, x);
//         ASSERT_EQ(&x,    &y);}
//     catch (std::invalid_argument& e) {
//         ASSERT_TRUE(false);}}

// TEST(Integer, abs_2) {
//     try {
//         const Integer<int> x = -98765;
//         const Integer<int> y = abs(x);
//         ASSERT_EQ(-98765, x);
//         ASSERT_EQ( 98765, y);}
//     catch (std::invalid_argument& e) {
//         ASSERT_TRUE(false);}}

// // --------
// // equal_to
// // --------

// TEST(Integer, equal_to) {
//     try {
//         const Integer<int> x = 98765;
//         const Integer<int> y = 98765;
//         ASSERT_EQ(      x, y);
//         ASSERT_EQ(      x, 98765);
//         ASSERT_EQ(  98765, x);}
//     catch (std::invalid_argument& e) {
//         ASSERT_TRUE(false);}}

// // --------
// // negation
// // --------

// TEST(Integer, negation) {
//     try {
//         const Integer<int> x = 98765;
//         const Integer<int> y = -x;
//         ASSERT_EQ(-98765, y);}
//     catch (std::invalid_argument& e) {
//         ASSERT_TRUE(false);}}

// // ------
// // output
// // ------

// TEST(Integer, output) {
//     try {
//         const Integer<int> x = 98765;
//         std::ostringstream out;
//         out << x;
//         ASSERT_EQ("98765", out.str());}
//     catch (std::invalid_argument& e) {
//         ASSERT_TRUE(false);}}

// // ---
// // pow
// // ---

// TEST(Integer, pow_1) {
//     try {
//         Integer<int>       x = 98765;
//         const int          e =  9867;
//         Integer<int>&      y = x.pow(e);
//         ASSERT_EQ(9867,  e);
//         ASSERT_EQ(   0,  x);
//         ASSERT_EQ(  &x, &y);}
//     catch (std::invalid_argument& e) {
//         ASSERT_TRUE(false);}}

// TEST(Integer, pow_2) {
//     try {
//         const Integer<int> x = 98765;
//         const int          e =  9867;
//         const Integer<int> y = pow(x, e);
//         ASSERT_EQ(98765, x);
//         ASSERT_EQ( 9867, e);
//         ASSERT_EQ(    0, y);}
//     catch (std::invalid_argument& e) {
//         ASSERT_TRUE(false);}}

// TEST(Integer, plus_equals){
//     Integer<int> a =(-25);
//     Integer<int> b = (1325);
//     a += b;
//     cout<<a<<endl<<endl;
//     ASSERT_TRUE(a == 1300);
// }

// TEST(Integer, plus_equals2){
//     Integer<int> a =(13);
//     Integer<int> b = (-25);
//     a += b;
//     ASSERT_TRUE(a == -12);
// }

// TEST(Integer, plus_equals3){
//     Integer<int> a =(-13);
//     Integer<int> b = (25);
//     a += b;
//     ASSERT_TRUE(a == 12);
// }

// TEST(Integer, plus_equals4){
//     Integer<int> a =(13);
//     Integer<int> b = (13);
//     a += b;
//     ASSERT_TRUE(a == 26);
// }

// TEST(Integer, plus_equals5){
//     Integer<int> a =(-13);
//     Integer<int> b = (-25);
//     a += b;
//     ASSERT_TRUE(a == -38);
// }

// TEST(Integer, plus_equals6){
//     Integer<int> a =(0);
//     Integer<int> b = (0);
//     a += b;
//     ASSERT_TRUE(a == 0);
// }

// TEST(Integer, plus_equals7){
//     Integer<int> a =(0);
//     Integer<int> b = (1);
//     a += b;
//     ASSERT_TRUE(a == 1);
// }

// TEST(Integer, plus_equals8){
//     Integer<int> a =(-1);
//     Integer<int> b = (1);
//     a += b;
//     cout<<a<<endl;
//     ASSERT_TRUE(a == 0);
// }

// TEST(Integer, plus_equals9){
//     Integer<int> a =(-1300);
//     Integer<int> b = (25);
//     a += b;
//     ASSERT_TRUE(a == -1325);
// }

// // -------------------
// // less than operator 
// // -------------------

// TEST(Integer, less_than){
//     Integer<int> a = (-25);
//     Integer<int> b = 1325;
//     ASSERT_TRUE(a < b);
// }

// TEST(Integer, less_than2){
//     Integer<int> a = (25);
//     Integer<int> b = 1325;
//     ASSERT_TRUE(a < b);
// }

// TEST(Integer, less_than3){
//     Integer<int> a = (25);
//     Integer<int> b = 25;
//     ASSERT_TRUE(! (a < b));
// }

// TEST(Integer, less_than4){
//     Integer<int> a = (0);
//     Integer<int> b = 0;
//     ASSERT_TRUE(!(a < b));
// }
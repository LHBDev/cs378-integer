// --------------------------
// projects/integer/Integer.h
// Copyright (C) 2014
// Glenn P. Downing
// --------------------------

#ifndef Integer_h
#define Integer_h

// --------
// includes
// --------

#include <cassert>   // assert
#include <iostream>  // ostream
#include <stdexcept> // invalid_argument
#include <string>    // string
#include <vector>    // vector
#include <algorithm> // reverse


using namespace std;
// -----------------
// shift_left_digits
// -----------------

/**
 * @param b an iterator to the beginning of an input  sequence (inclusive)
 * @param e an iterator to the end       of an input  sequence (exclusive)
 * @param x an iterator to the beginning of an output sequence (inclusive)
 * @return  an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the shift left of the input sequence into the output sequence
 * ([b, e) << n) => x
 */
template <typename II, typename OI>
OI shift_left_digits (II b, II e, int n, OI x) {
    // <your code>
    return x;}

// ------------------
// shift_right_digits
// ------------------

/**
 * @param b an iterator to the beginning of an input  sequence (inclusive)
 * @param e an iterator to the end       of an input  sequence (exclusive)
 * @param x an iterator to the beginning of an output sequence (inclusive)
 * @return  an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the shift right of the input sequence into the output sequence
 * ([b, e) >> n) => x
 */
template <typename II, typename OI>
OI shift_right_digits (II b, II e, int n, OI x) {
    // <your code>
    return x;}

// -----------
// plus_digits
// -----------

/**
 * @param b  an iterator to the beginning of an input  sequence (inclusive)
 * @param e  an iterator to the end       of an input  sequence (exclusive)
 * @param b2 an iterator to the beginning of an input  sequence (inclusive)
 * @param e2 an iterator to the end       of an input  sequence (exclusive)
 * @param x  an iterator to the beginning of an output sequence (inclusive)
 * @return   an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the sum of the two input sequences into the output sequence
 * ([b1, e1) + [b2, e2)) => x
 */
template <typename II1, typename II2, typename OI>
OI plus_digits (II1 b1, II1 e1, II2 b2, II2 e2, OI x) {
    // <your code>
    return x;}

// ------------
// minus_digits
// ------------

/**
 * @param b  an iterator to the beginning of an input  sequence (inclusive)
 * @param e  an iterator to the end       of an input  sequence (exclusive)
 * @param b2 an iterator to the beginning of an input  sequence (inclusive)
 * @param e2 an iterator to the end       of an input  sequence (exclusive)
 * @param x  an iterator to the beginning of an output sequence (inclusive)
 * @return   an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the difference of the two input sequences into the output sequence
 * ([b1, e1) - [b2, e2)) => x
 */
template <typename II1, typename II2, typename OI>
OI minus_digits (II1 b1, II1 e1, II2 b2, II2 e2, OI x) {
    // <your code>
    return x;}

// -----------------
// multiplies_digits
// -----------------

/**
 * @param b  an iterator to the beginning of an input  sequence (inclusive)
 * @param e  an iterator to the end       of an input  sequence (exclusive)
 * @param b2 an iterator to the beginning of an input  sequence (inclusive)
 * @param e2 an iterator to the end       of an input  sequence (exclusive)
 * @param x  an iterator to the beginning of an output sequence (inclusive)
 * @return   an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the product of the two input sequences into the output sequence
 * ([b1, e1) * [b2, e2)) => x
 */
template <typename II1, typename II2, typename OI>
OI multiplies_digits (II1 b1, II1 e1, II2 b2, II2 e2, OI x) {
    // <your code>
    return x;}

// --------------
// divides_digits
// --------------

/**
 * @param b  an iterator to the beginning of an input  sequence (inclusive)
 * @param e  an iterator to the end       of an input  sequence (exclusive)
 * @param b2 an iterator to the beginning of an input  sequence (inclusive)
 * @param e2 an iterator to the end       of an input  sequence (exclusive)
 * @param x  an iterator to the beginning of an output sequence (inclusive)
 * @return   an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the division of the two input sequences into the output sequence
 * ([b1, e1) / [b2, e2)) => x
 */
template <typename II1, typename II2, typename OI>
OI divides_digits (II1 b1, II1 e1, II2 b2, II2 e2, OI x) {
    // <your code>
    return x;}




// -------
// Integer
// -------

template < typename T, typename C = std::vector<T> >
class Integer {
    // -----------
    // operator ==
    // -----------

    /**
     * <your documentation>
     */
    friend bool operator == (const Integer& lhs, const Integer& rhs) {
        if(lhs._positive != rhs._positive || lhs._x.size() != rhs._x.size())
            return false;

        auto lit = lhs._x.begin();
        auto rit = rhs._x.begin();

        while(lit != lhs._x.end()){
            if(*lit++ != *rit++)
                return false;
        }
        return true;}

    // -----------
    // operator !=
    // -----------

    /**
     * <your documentation>
     */
    friend bool operator != (const Integer& lhs, const Integer& rhs) {
        return !(lhs == rhs);}

    // ----------
    // operator <
    // ----------

    /**
     * <your documentation>
     */
    friend bool operator < (const Integer& lhs, const Integer& rhs) {
        
        if(rhs._positive && !lhs._positive)
            return true;
        
        else if(!rhs._positive && lhs._positive)
            return false;

        else if(rhs._positive){
            if(rhs._x.size() > lhs._x.size())
                return true;

            else if(rhs._x.size() < lhs._x.size())
                return false;

            else{    
                auto lit = lhs._x.begin();
                auto rit = rhs._x.begin();

                while(lit != lhs._x.end()){
                    if(*lit < *rit)
                        return true;
                    else if(*lit > *rit)
                        return false;
                    ++lit;
                    ++rit;
                }   
            }
        }else{
            // Comparing negattive numbers...
            if(rhs._x.size() < lhs._x.size())
                return true;
            else if (rhs._x.size() > lhs._x.size())
                return false;
            else{

                auto lit = lhs._x.begin();
                auto rit = rhs._x.begin();

                while(lit != lhs._x.end()){
                    if(*lit > *rit)
                        return true;
                    else if(*lit < *rit)
                        return false;
                    ++lit;
                    ++rit;
                } 
            }

        }

        return false;}

    // -----------
    // operator <=
    // -----------

    /**
     * <your documentation>
     */
    friend bool operator <= (const Integer& lhs, const Integer& rhs) {
        return !(rhs < lhs);}

    // ----------
    // operator >
    // ----------

    /**
     * <your documentation>
     */
    friend bool operator > (const Integer& lhs, const Integer& rhs) {
        return (rhs < lhs);}

    // -----------
    // operator >=
    // -----------

    /**
     * <your documentation>
     */
    friend bool operator >= (const Integer& lhs, const Integer& rhs) {
        return !(lhs < rhs);}

    // ----------
    // operator +
    // ----------

    /**
     * <your documentation>
     */
    friend Integer operator + (Integer lhs, const Integer& rhs) {
        return lhs += rhs;}

    // ----------
    // operator -
    // ----------

    /**
     * <your documentation>
     */
    friend Integer operator - (Integer lhs, const Integer& rhs) {
        return lhs -= rhs;}

    // ----------
    // operator *
    // ----------

    /**
     * <your documentation>
     */
    friend Integer operator * (Integer lhs, const Integer& rhs) {
        return lhs *= rhs;}

    // ----------
    // operator /
    // ----------

    /**
     * <your documentation>
     * @throws invalid_argument if (rhs == 0)
     */
    friend Integer operator / (Integer lhs, const Integer& rhs) {
        return lhs /= rhs;}

    // ----------
    // operator %
    // ----------

    /**
     * <your documentation>
     * @throws invalid_argument if (rhs <= 0)
     */
    friend Integer operator % (Integer lhs, const Integer& rhs) {
        return lhs %= rhs;}

    // -----------
    // operator <<
    // -----------

    /**
     * <your documentation>
     * @throws invalid_argument if (rhs < 0)
     */
    friend Integer operator << (Integer lhs, int rhs) {
        return lhs <<= rhs;}

    // -----------
    // operator >>
    // -----------

    /**
     * <your documentation>
     * @throws invalid_argument if (rhs < 0)
     */
    friend Integer operator >> (Integer lhs, int rhs) {
        return lhs >>= rhs;}

    // -----------
    // operator <<
    // -----------

    /**
     * <your documentation>
     */
    friend std::ostream& operator << (std::ostream& lhs, const Integer& rhs) {
        if(!rhs._positive)
            lhs << "-";
        
        for(auto it = (rhs._x).begin(); it != (rhs._x).end(); ++it){
            lhs << *it;
        }
        return lhs;}

    // ---
    // abs
    // ---

    /**
     * absolute value
     * <your documentation>
     */
    friend Integer abs (Integer x) {
        return x.abs();}

    // ---
    // pow
    // ---

    /**
     * power
     * <your documentation>
     * @throws invalid_argument if ((x == 0) && (e == 0)) || (e < 0)
     */
    friend Integer pow (Integer x, int e) {
        return x.pow(e);}

    private:
        // ----
        // data
        // ----

        C _x; // the backing container
        // <your data>
        bool _positive;
        unsigned int _lenth;

    private:
        // -----
        // valid
        // -----

        bool valid () const { // class invariant
            // <your code>
            bool isValid = true;

            for(int i = 0; i < (int)_x.size() && isValid; ++i){
                if((_x[i] > 9 ||  _x[i] < 0)){
                    isValid =  false;
                }
            }
            return isValid;}

    public:
        // ------------
        // constructors
        // ------------

        /**
         * <your documentation>
         */
        Integer (int value) {
            // <your code>
            if(value == 0){
                _positive = true;
                _x.push_back(0);
            }
            else{
                if(value > 0)
                    _positive = true;
                else{
                    _positive = false;
                    value = -1 * value;
                }

                while(value > 0){
                    _x.push_back(value%10);
                    value = value / 10;
                    ++_lenth;
                }
                std::reverse(_x.begin(), _x.end());
            }
            assert(valid());
        }

        /**
         * <your documentation>
         * @throws invalid_argument if value is not a valid representation of an Integer
         */
        explicit Integer (const std::string& value) {
            
            if (!valid())
                throw std::invalid_argument("Integer::Integer()");

            string::const_iterator number = value.cbegin();
            string::const_iterator endNumber = value.cend();

            while(number != endNumber){ 
                if(!(*number >= '0' && *number <= '9'))
                    throw std::invalid_argument("Integer()");
                ++number;
            }

            Integer(atoi(value.c_str()));
        }

        // Default copy, destructor, and copy assignment.
        // Integer (const Integer&);
        // ~Integer ();
        // Integer& operator = (const Integer&);

        // ----------
        // operator -
        // ----------

        /**
         * <your documentation>
         */
        Integer operator - () const {
            // <your code>
            Integer x = *this;
            x._positive = !x._positive;
            return x;}

        // -----------
        // operator ++
        // -----------

        /**
         * <your documentation>
         */
        Integer& operator ++ () {
            *this += 1;
            return *this;}

        /**
         * <your documentation>
         */
        Integer operator ++ (int) {
            Integer x = *this;
            ++(*this);
            return x;}

        // -----------
        // operator --
        // -----------

        /**
         * <your documentation>
         */
        Integer& operator -- () {
            *this -= 1;
            return *this;}

        /**
         * <your documentation>
         */
        Integer operator -- (int) {
            Integer x = *this;
            --(*this);
            return x;}

        // -----------
        // operator +=
        // -----------

        /**
         * <your documentation>
         */
        Integer& operator += (const Integer& rhs) {
            // <your code>
            Integer lhs = *this;
            Integer crhs = rhs;
            Integer& bigger = *this;
            Integer& smaller = crhs;
            

            if(lhs._x.size() < crhs._x.size()){
                bigger = crhs;
                smaller = lhs;
            }

            unsigned int diff = bigger._x.size() - smaller._x.size();
            cout<<"DIFF: " << diff<<endl;

            reverse(smaller._x.begin(), smaller._x.end());
            for(;diff > 0; --diff)
                smaller._x.push_back(0);
            reverse(smaller._x.begin(), smaller._x.end());
            
            if(crhs._positive == !lhs._positive){
                
                if(crhs._positive){
                    Integer& pos = crhs;
                    Integer& neg = *this;
                    (*this)._positive = true;
                    if(!((*this) <= crhs))
                        (*this)._positive = false;
                    pos = crhs;
                    neg = *this;
                    auto posit = pos._x.end();
                    auto negit = neg._x.end();
                    --posit;
                    --negit;

                    while(posit >= pos._x.begin() && negit >= neg._x.begin()){
                        cout << "N: " << *negit << " P: " << *posit <<endl;
                        *negit -= *posit;
                        cout << "N: " << *negit << " P: " << *posit <<endl;

                        if(*negit < 0)
                            *negit *= -1;
                        --negit;
                        --posit;
                    }
                }
                else{
                    
                    Integer& pos = *this;
                    Integer neg = crhs;
                    (*this)._positive = false;
                    if((*this) < crhs)
                        (*this)._positive = true;
                    auto posit = pos._x.end();
                    auto negit = neg._x.end();
                    --posit;
                    --negit;

                    while(posit >= pos._x.begin() && negit >= neg._x.begin()){
                        cout << "N: " << *negit << " P: " << *posit <<endl;
                        *posit -= *negit;
                        cout << "N: " << *negit << " P: " << *posit <<endl;

                        if(*posit < 0)
                            *posit *= -1;
                        --negit;
                        --posit;
                    }

                }
            }
            else if(crhs._positive == lhs._positive){
                cout<<"HEHREHHREKNLGHSAHFGHL:GH"<<endl;
                auto thisit = (*this)._x.end();
                auto rit = crhs._x.end();
                --thisit;
                --rit;

                bool carry = false;
                while(thisit >= (*this)._x.begin()){
                    int i = 0;
                    if(carry){
                        carry = false;
                        i = 1;
                    }
                    *thisit += *rit + i;
                    if(*thisit > 9){
                        *thisit = *thisit % 10;
                        carry = true;
                    }
                    --thisit;
                    --rit;
                }


            }
            return *this;}

        // -----------
        // operator -=
        // -----------

        /**
         * <your documentation>
         */
        Integer& operator -= (const Integer& rhs) {
            // <your code>
            return *this;}

        // -----------
        // operator *=
        // -----------

        /**
         * <your documentation>
         */
        Integer& operator *= (const Integer& rhs) {
            // <your code>
            return *this;}

        // -----------
        // operator /=
        // -----------

        /**
         * <your documentation>
         * @throws invalid_argument if (rhs == 0)
         */
        Integer& operator /= (const Integer& rhs) {
            // <your code>
            return *this;}

        // -----------
        // operator %=
        // -----------

        /**
         * <your documentation>
         * @throws invalid_argument if (rhs <= 0)
         */
        Integer& operator %= (const Integer& rhs) {
            // <your code>
            return *this;}

        // ------------
        // operator <<=
        // ------------

        /**
         * <your documentation>
         */
        Integer& operator <<= (int n) {
            // <your code>
            return *this;}

        // ------------
        // operator >>=
        // ------------

        /**
         * <your documentation>
         */
        Integer& operator >>= (int n) {
            // <your code>
            return *this;}

        // ---
        // abs
        // ---

        /**
         * absolute value
         * <your documentation>
         */
        Integer& abs () {
            if(!this->_positive){
                this->_positive = true;
            }
            return *this;}

        // ---
        // pow
        // ---

        /**
         * power
         * <your documentation>
         * @throws invalid_argument if ((this == 0) && (e == 0)) or (e < 0)
         */
        Integer& pow (int e) {
            // <your code>
            return *this;}};

#endif // Integer_h

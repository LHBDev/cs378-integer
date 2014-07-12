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
#include <deque>


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

    x = copy(b, e, x);
    OI y = x;
    advance(y, n);
    fill(x, y, typename iterator_traits<II>::value_type());
    return y;
}

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
    unsigned int  dist = distance(b, e);

    if(n >= dist){
        *x++ = 0;
        return x;
    }

    x =copy(b, e-n, x);
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
    OI y = x;

    --e1;
    --e2;
    bool carry = false;
    while(e1 >= b1 && e2 >= b2){
        int sum = 0;
        if(carry){
            carry = false;
            sum += 1;}

        sum += *e1-- + *e2--;
        if(sum > 9){
            sum = sum %10;
            carry = true;}
        *x++ = sum;}

    while(e1 >= b1){
        int sum = 0;

        if(carry){
            carry = false;
            sum += 1;}

        sum += *e1--;
         if(sum > 9){
            sum = sum %10;
            carry = true;}
        *x++ = sum;}

    while(e2 >= b2){
        int sum = 0;
        if(carry){
            carry = false;
            sum += 1;}

        sum += *e2--;
         if(sum > 9){
            sum = sum %10;
            carry = true;}
        *x++ = sum;
    }

    if(carry)
        *x++ = 1;
    reverse(y, x);
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
    OI y = x;

    --e1;
    --e2;
    bool carry = false;
    while(e1 >= b1 && e2 >= b2){
        int sum = 0;
        if(carry && *e1 != 0){
            carry = false;
            sum -= 1;
        }
        else if(carry && *e1 == 0)
            sum += 9;
        if(*e1 + sum < *e2){
            carry = true;
            sum += 10;
        }
        // cout<<sum<<endl;
        // cout<<*e1<<" "<<*e2<<endl;
        sum += *e1-- - *e2--;
        // cout<<sum<<endl;
        *x++ = sum;
    }

    while(e1 >= b1)
    {
        int sum = 0;
        if(carry && *e1 != 0){
            carry = false;
            sum -= 1;
        }
        else if(carry && *e1 == 0){
            sum += 9;
        }
        *x++ = sum + *e1--;
    }

    while(e2 >= b2)
    {
        int sum = 0;
        if(carry && *e2 != 0){
            carry = false;
            sum -=1;
        }
        else{
            sum +=9;
        }
        *x++ = sum + *e2--;
    }

    reverse(y,x);
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
 void printVector(const vector<int>& v);

template <typename II1, typename II2, typename OI>
OI multiplies_digits (II1 b1, II1 e1, II2 b2, II2 e2, OI x) {
   
    vector<vector<int> >  cache;
    vector<int> original;
    
    II1 copyTemp = b1;
    while(copyTemp != e1)
        original.push_back(*copyTemp++);
    reverse(original.begin(), original.end());

    vector<int> zero;
    zero.push_back(0);
    cache.push_back(zero);

    for(int i = 1; i < 10; ++i){
        auto temp = original.begin();
        vector<int> tempInt;
        int carry = 0;

        while(temp != original.end()){
            int product = 0;
            if(carry > 0){
                product += carry;
                carry = 0;
            }

            product += *temp * i;
            if(product > 9){
                carry = product / 10;
                product = product % 10;
            }

            tempInt.push_back(product);
            ++temp;
        }
        while(carry > 0){
            int leftover = carry % 10;
            carry = carry / 10;
            tempInt.push_back(leftover);
        }
        reverse(tempInt.begin(), tempInt.end());
        cache.push_back(tempInt);
        // printVector(tempInt);
    }

    // cout<<"END CACHE: "<<endl;

    unsigned long distance1 = distance(b1, e1);
    unsigned long distance2 = distance(b2, e2);
    unsigned long distance = distance1 + distance2;

    vector<int> runningProduct(distance, 0);

    int shifts = 0;
    --e2;

    while(e2 >= b2){
        // cout<<*e2<<endl;
        // cout<<shifts<<endl;
        vector<int> tempMulti = cache[*e2--];
        vector<int> multi(tempMulti.size() + shifts,0);
        vector<int> tempProd(distance);
        printVector(tempMulti);
        OI y = shift_left_digits(tempMulti.begin(), tempMulti.end(),
            shifts++, &multi[0]);
        printVector(multi);
        printVector(runningProduct);
        int *p = multi.data();
        int *q = runningProduct.data();
        OI z = plus_digits(p, p + multi.size(),q,
            q + runningProduct.size(), &tempProd[0]);
        runningProduct = tempProd;
        printVector(runningProduct);
    }
    cout<<"Size: "<< runningProduct.size()<<endl;
    OI y = x;
    for(int i = runningProduct.size() -1; i<=0; --i)
        *y++ = runningProduct[i];


    return y;}


void printVector(const vector<int>& v){
    for(int i = 0; i < (int)v.size(); ++i){
        cout << v[i] << " ";
    }
    cout << endl;
}
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
            if(!_positive)
                cout<<"-";
            for(auto it : _x)
                    cout << it;
            cout<<endl;
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

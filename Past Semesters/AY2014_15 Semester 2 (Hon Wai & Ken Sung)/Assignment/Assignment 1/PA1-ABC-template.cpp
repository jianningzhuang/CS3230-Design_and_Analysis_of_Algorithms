/**
    This is a CPP template for CS3230 - Programming Assignment 1 - Part 1
    (January-2015)

    You are not required to follow the template. Feel free to modify any part.

    Comment your code!
**/


#include <iostream>
//your include
using namespace std;
#define     FORE(i,s,e)     for(int (i) = (s); (i) <= (e); ++(i))


const string    Digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char      RADIX_POINT = '.';


inline int valueOf(char x){ // integer value of a digit
    if ('0' <= x and x <= '9') return x - '0';
    if ('A' <= x and x <= 'Z') return x - 'A' +10;
    return 255;
};

inline char digitOf(int val){ // val must be < base <= 36
    return Digits[val];
};


typedef int     digitType;


//Trim leading and trailing zeros, and radixpoint
string trim(string aStr){
    string X = aStr;
    //leading zeros:
    while(X.length()>1 and X[0] == '0'and X[1] != RADIX_POINT) X.erase(0,1); //000.001

    //trailing zeros and radix point:
    if (X.find(RADIX_POINT) != string::npos){
        while(X.length()>=1 and X[X.length()-1] =='0')
            X.erase(X.length()-1,1);//0.010; 1.000
        if   (X.length()>=1 and X[X.length()-1] == RADIX_POINT)
            X.erase(X.length()-1);//123.
        if (X[0] == RADIX_POINT)
            X = "0" + X; // insert "0" into ".123"
    };
    if (X == "") X = "0";
    return X;
};


void convertStr2Arr( YOUR_PARAMs){
//Your code:
};

string convertArr2Str( YOUR_PARAMs ){
    string S = "";
    //Your code:

    S = trim(S);
    return S;
};


//YOUR ALGORITHM



int main()
{
    int T;
    cin >>T;
    int base;
    string V, M, P;
    FORE(t,1,T){
        cin>>base;
        cin>>V;
        cin>>M;
        convertStr2Arr(V, );
        convertStr2Arr(M, );

        //your algorithm:
        P = V * M;

        P = convertArr2Str(P, );
        cout <<P<<endl;
    };

    return 0;


//Test correctness:
//================

    return 0;
}

#ifndef CALCULATOR_H
#define CALCULATOR_H

/*#include <QtGui>
#include <QVariant>
#include <QRegExp>*/

#include <map>
#include <string>
#include <vector>

using namespace std;

/**
  * Used to parse and evaluate each R expression.
  */
class Calculator {

    protected:
        /** The string representing the current expression */
        string form;
        /** Stores the value of each parameter. The index of a given parameter
          is found in paraID. */
        vector<int> paraValue;
    public:
        /** Stores the parameters */
        vector<string> parameter;
        /** A parameter -> index map, for the variable's index in paraValue */
        map<string, int> paraID;
        /** A parameter -> value map */
        static vector<string> paraNames;    /* todo: paramap */
        static map<string, int> paraMap;    /* todo: paramap */

        /* Functions, defined in .cpp file */
        Calculator(vector<int> paraValue) : paraValue(paraValue) { }
        static bool isOperator(string s);
        static vector<string> tokenize(string s);
        static bool isNumber(string s);
        static bool isDouble(string s);
        int parseOperand(string s);
        static int _parseOperand(string s); /* todo: paramap*/
        static int toNumber(string s);
        static double toDouble(string s);
        double evaluate(int n, vector<int>& R, vector<string> s, bool anchor, int anchorValue, signed int n_0);
        double evaluate(int n, vector<int>& R, vector<string> s);
        int stringEvaluate(int n, vector<int>& R, string expression, bool anchor, int achorValue, signed int n_0);
        int algebraEvaluate(string expression);
        static string toString(int n);
        static string toString(double n);
        /*static*/ void saveParameters(string s);
        static string stripSpaces(string s);
        static void createMap(vector<int> v);
        static void init();
        static vector<string> getParameterNames(string s);

        /* Functions for detecting Overflow and Underflow */
        bool addition_is_safe(int a, int b);
        bool multiplication_is_safe(long a, long b);
        bool exponentiation_is_safe(long a, long b);
        size_t log(long a);

};

#endif // CALCULATOR_H

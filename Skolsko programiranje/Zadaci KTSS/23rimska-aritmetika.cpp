// STATUS: zavrsen
// IZVOR: KTSS-2015

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int toNumeral(string roman) {
    int result = 0;

    for (int i = 0; i < roman.length(); i++) {
        if(roman[i] == 'M') {
            result+=1000;
        } else if(roman[i] == 'D') {
            result+=500;
        } else if(roman[i] == 'C') {
            if(roman[i + 1] == 'D') {
                result+=400;
                i++;
            } else if (roman[i + 1] == 'M') {
                result+=900;
                i++;
            } else {
                result+=100;
            }
        } else if(roman[i] == 'L') {
            result+=50;
        } else if(roman[i] == 'X') {
            if(roman[i + 1] == 'L') {
                result+=40;
                i++;
            } else if (roman[i + 1] == 'C') {
                result+=90;
                i++;
            } else {
                result+=10;
            }
        } else if(roman[i] == 'V') {
            result+=5;
        } else if(roman[i] == 'I') {
            if(roman[i + 1] == 'V') {
                result+=4;
                i++;
            } else if (roman[i + 1] == 'X') {
                result+=9;
                i++;
            } else {
                result+=1;
            }
        }
    }
    return result;
}

string toRoman(int number) {
    string romanNumber = "";
    vector<int> values = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
    vector<string> letters = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    int i = 12;
    while(number > 0) {
        int div = number/values[i];
        number = number%values[i];
        while(div--) {
            romanNumber+=letters[i];
        }
        i--;
    }
    
    return romanNumber;
}

string solve(string expression) {
    string roman1, roman2;
    bool foundOperator = false;
    char arithmeticOperator;
    for (int i = 0; i < expression.length(); i++)
    {
        if(expression[i] != '+' && expression[i] != '-' && expression[i] != '*' && expression[i] != '/' && expression[i] != '%' && expression[i] != '^') {
            if(!foundOperator)
                roman1 += expression[i];
            else
                roman2 += expression[i];
        } else {
            foundOperator = true;
            arithmeticOperator = expression[i];
        }
    }
    int num1 = toNumeral(roman1);
    int num2 = toNumeral(roman2);
    int numeralResult;

    switch(arithmeticOperator) {
        case '+': {
            numeralResult = num1 + num2;
            break;
        }
        case '-': {
            numeralResult = num1 - num2;
            break;
        }
        case '*': {
            numeralResult = num1 * num2;
            break;
        }
        case '/': {
            numeralResult = num1 / num2;
            break;
        }
        case '%': {
            numeralResult = num1 % num2;
            break;
        }
        case '^': {
            numeralResult = pow(num1, num2);
            break;
        }
    }

    return toRoman(numeralResult);
}

int main() {
    vector<string> expressions = {"XXVII+CXXIII", "C-I", "L%III", "XVI^II"};
    
    // int n;
    // cin >> n;

    // for (int i = 0; i < n; i++) {
    //     string expression;
    //     cin >> expression;
    //     expressions.push_back(expression);
    // }
    
    for (int i = 0; i < expressions.size(); i++) {
        cout << solve(expressions[i]) << "\n";
    }
    

    return 0;
}
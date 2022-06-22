//
#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

#include "j863l378_myStack.h"

using namespace std;

class myInfixCalculator
{
public:
    myInfixCalculator(){}
    ~myInfixCalculator(){}

    void tokenize(const std::string & s, std::vector<std::string> &tokens)
    {
        int numBegin = -1;
        int numEnd = -1;
        for ( int i = 0; i < s.length(); i++ )
        {
            if ( s[i] == '(' )
            {
                //tokenizing previous number
                if( i>0 && isdigit(s[i-1]) )
                {
                    numEnd = i-1;
                    for(int j = numBegin; j <= numEnd; j++)
                    {
                        //add number to tokens
                    }
                    tokens.push_back("num");
                }
                tokens.push_back("(");
            }

            else if ( s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' )
            {
                //tokenizing previous number
                if( i>0 && isdigit(s[i-1]) )
                {
                    numEnd = i-1;
                    for(int j = numBegin; j <= numEnd; j++)
                    {
                        //add number to tokens
                    }
                    tokens.push_back("num");
                }
                if(s[i] == '+')
                {
                    tokens.push_back("+");
                }
                else if(s[i] == '-')
                {
                    tokens.push_back("-");
                }
                else if(s[i] == '*')
                {
                    tokens.push_back("*");
                }
                else if(s[i] == '/')
                {
                    tokens.push_back("/");
                }
            }

            else if ( s[i] == ')' )
            {
                //tokenizing previous number
                if( i>0 && isdigit(s[i-1]) )
                {
                    numEnd = i-1;
                    for(int j = numBegin; j <= numEnd; j++)
                    {
                        //add number to tokens
                    }
                    tokens.push_back("num");
                }
                tokens.push_back(")");
            }

            else if( isdigit( s[i] ) )
            {
                //making sure to not walk off beginning of array
                if( i == 0 )
                {
                    numBegin = 0;
                }
                //if prev entry isn't part of the number or a decimal
                else if( (!isdigit(s[i-1])) && (s[i-1] != '.') )
                {
                    numBegin = i;
                }

                if( i == s.length()-1 )
                {
                    tokens.push_back("num");
                }
            }
        }
    }

    // bool isOperator(std::string & s)
    // {

    // }

    // bool isNumeric(std::string & s)
    // {

    // }

    std::string infixToPostfix(const std::string & s)
    {
        myStack<char> stack(s.length());
        std::string postfix = "";

        for(int i = 0; i < s.length(); i++)
        {
            if(isdigit( s[i] ) || s[i] == '.')
            {
                postfix += s[i];
                if(i < s.length() - 1 && !isdigit( s[i+1] ) && s[i+1] != '.')
                {
                    postfix += ' ';
                }
            }
    
            else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
            {
                if(stack.empty())
                {
                    //
                }
                else
                {
                    while( (priority(s[i]) <= priority(stack.top()))
                                && ( stack.top() != '(' && stack.top() != ')' ) )
                    {
                        postfix += stack.top();
                        postfix += ' ';
                        stack.pop(); 
                    }
                }
                stack.push(s[i]);
            }

            else if(s[i] == '(')
            {
                stack.push(s[i]);
            }

            else if(s[i] == ')')
            {
                while(!stack.empty() && stack.top() != '(')
                {
                    postfix += stack.top();
                    postfix += ' ';
                    stack.pop();
                }
                stack.pop();
            }
        }
        // Pop all the remaining elements from the stack
        while(!stack.empty())
        {
            if(postfix.back() != ' ')
            {
                postfix += ' ';
            }
            if(stack.top() != '(' && stack.top() != ')')
            {
                postfix += stack.top();
            }
            stack.pop();
        }
        return postfix;
    }

    int priority (char a)
    {
        if(a == '(' || a == ')')
        {
            return 3;
        }
        else if(a == '*' || a=='/')
        {
            return 2;
        }
        else if(a == '+' || a == '-')
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }


    double calculatePostfix(const std::string & s)
    {
        double value1;
        double value2;
        myStack<double> stack(s.length());
        // return 999;

        for ( int i = 0; i < s.length(); i++ )
        {
            std::string num = "";
            // i < s.length() - 1 && !isdigit( s[i+1] ) && s[i+1] != '.'
            if( isdigit(s[i]) )
            {
                while ( isdigit( s[i] ) || s[i] == '.')
                {
                    num += s[i];
                    // stack.push( s[i] );
                    i++;
                }
                // std::cout << "\nFinal number: " << stod(num);
                stack.push( stod(num) );
            }
            else if ( s[i] == '+' )
            {
                value1 = stack.top();
                stack.pop();
                value2 = stack.top();
                stack.pop();
                stack.push( value1 + value2 );
                // std::cout << "\nValue pushed to stack: " << (value1 + value2);
            }
            else if ( s[i] == '-' )
            {
                value1 = stack.top();
                stack.pop();
                value2 = stack.top();
                stack.pop();
                stack.push( value2 - value1 );
                // std::cout << "\nValue pushed to stack: " << (value2 - value1);
            }
            else if ( s[i] == '*' )
            {
                value1 = stack.top();
                stack.pop();
                value2 = stack.top();
                stack.pop();
                stack.push( value1 * value2 );
                // std::cout << "\nValue pushed to stack: " << (value1 * value2);
            }
            else if ( s[i] == '/' )
            {
                value1 = stack.top();
                stack.pop();
                value2 = stack.top();
                stack.pop();
                stack.push( value2 / value1 );
                // std::cout << "\nValue pushed to stack: " << (value2 / value1);
            }
        }
        return stack.top();
    }
};
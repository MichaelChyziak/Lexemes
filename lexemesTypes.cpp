/*
 * lexemesTypes.cpp
 *
 * Created on: Oct 27, 2014
 *
 */

#include "lexemesTypes.h"

namespace ensc251{

  //***Complete the implementation of the following functions: ***

  //This function returns TRUE if the input is identifier else FALSE
  bool isIdentifier(const string &lexeme) {
    //TO DO
  }

  //This function returns TRUE if the input is one of the operators defined in the variable
  //"tableOfOperators" in "lexemesTypes.h" else it returns FALSE
  bool isOperator(const string &lexeme) {
    string temp = lexeme; //create a temporary string to hold the string of lexeme parameter
    
    //check if the string temp is equal to any of the operators in variable "tableOfOperators" in "LexemesTypes.h"
    //if they match return true, otherwise false
    for (int i = 0; i < tableOfOperators.size(); i++) { 
      if (temp == tableOfOperators[i]) {
        return true;
      }
    }
    return false;
  }

  //This function returns TRUE if the input is one of the punctuators defined in the variable
  //"tableOfPunctuators" in "lexemesTypes.h" else it returns FALSE
  bool isPunctuator(char lexeme) { 
    string temp = lexeme; //create a temporary string to hold the string of lexeme parameter
    
    //check if the string temp is equal to any of the operators in variable "tableOfPunctuators" in "LexemesTypes.h"
    //if they match return true, otherwise false
    for (int i = 0; i < tableOfPunctuators.size(); i++) { 
      if (temp == tableOfPunctuators[i]) {
        return true;
      }
    }
    return false;
  }

  //This function returns TRUE if the input is one of the keywords defined in the variable
  //"tableOfKeywords" in "lexemesTypes.h" else it returns FALSE
  bool isKeyword(const string &lexeme) { 
    string temp = lexeme; //create a temporary string to hold the string of lexeme parameter
    
    //check if the string temp is equal to any of the operators in variable "tableOfKeywords" in "LexemesTypes.h"
    //if they match return true, otherwise false
    for (int i = 0; i < tableOfKeywords.size(); i++) { 
      if (temp == tableOfKeywords[i]) {
        return true;
      }
    }
    return false;
  }

  //This function returns TRUE if the input is one of the boolean defined in the variable
  //"booleanValues" in "lexemesTypes.h" else it returns FALSE
  bool isBooleanValue(const string &lexeme) { 
    string temp = lexeme; //create a temporary string to hold the string of lexeme parameter
    
    //check if the string temp is equal to any of the operators in variable "booleanValues" in "LexemesTypes.h"
    //if they match return true, otherwise false
    for (int i = 0; i < booleanValues.size(); i++) { 
      if (temp == booleanValues[i]) {
        return true;
      }
    }
    return false;
  }
  }

  //This function returns TRUE if the input is integer literal else FALSE
  bool isIntegerLiteral(const string &lexeme) { 
    //http://en.cppreference.com/w/cpp/language/integer_literal
    //http://en.cppreference.com/w/cpp/language/expressions#Primary_expressions
    string temp = lexeme; //create a temporary string to hold the string of lexeme parameter
    int counter = 0;
    const char naturalNumbers = {0,1,2,3,4,5,6,7,8,9};
    const char hexadecimalLetters = {a,A,b,B,c,C,d,D,e,E,f,F};
    const char integerSuffix = {u,U,l,L};
    const char singleQuote = {'\''}; // OPTIONAL ????????????????????????????????????????
    

  }

  //This function returns TRUE if the input is float literal else FALSE
  bool isFloatLiteral(const string &lexeme) { 
    //TO DO
  }

  //This function returns TRUE if the input is string literal else FALSE
  bool isStringLiteral(const string &lexeme) { 
    //TO DO
  }
}



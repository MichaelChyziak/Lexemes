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
		string temp = lexeme; //creates a temporary string variable to hold the value of lexeme
		return false;
	}

	//This function returns TRUE if the input is one of the operators defined in the variable
	//"tableOfOperators" in "lexemesTypes.h" else it returns FALSE
	bool isOperator(const string &lexeme) { 
		string temp = lexeme; //creates a temporary string variable to hold the value of lexeme
		int sizeOfOperators = sizeof(tableOfOperators) / sizeof(tableOfOperators[0]);

		//compares the temporary string to all of the strings from "tableOfOperators" in "lexemesTypes.h"
		//returns true if the string matches to one of the strings in the array, false otherwise
		for (int i = 0; i < temp.length(); i++) {
			for (int j = 0; j < sizeOfOperators; j++) {
				if (temp == tableOfOperators[j]) {
					return true;
				}
			}
		}
		return false;
	}

	//This function returns TRUE if the input is one of the punctuators defined in the variable
	//"tableOfPunctuators" in "lexemesTypes.h" else it returns FALSE
	bool isPunctuator(char lexeme) {
		char temp = lexeme; //creates a temporary char variable to hold the value of lexeme
		int sizeOfPunctuators = sizeof(tableOfPunctuators) / sizeof(tableOfPunctuators[0]);

		//compares the temporary character to all of the characters from "tableOfPunctuators" in "lexemesTypes.h"
		//returns true if the character matches to one of the characters in the array, false otherwise
		for (int i = 0; i < sizeOfPunctuators; i++) {
			if (temp == tableOfPunctuators[i]) {
				return true;
			}
		}
		return false;

	}

	//This function returns TRUE if the input is one of the keywords defined in the variable
	//"tableOfKeywords" in "lexemesTypes.h" else it returns FALSE
	bool isKeyword(const string &lexeme) {
		string temp = lexeme; //creates a temporary string variable to hold the value of lexeme
		int sizeOfKeywords = sizeof(tableOfKeywords) / sizeof(tableOfKeywords[0]);

		//compares the temporary string to all of the strings from "tableOfKeywords" in "lexemesTypes.h"
		//returns true if the string matches to one of the strings in the array, false otherwise
		for (int i = 0; i < temp.length(); i++) {
			for (int j = 0; j < sizeOfKeywords; j++) {
				if (temp == tableOfKeywords[j]) {
					return true;
				}
			}
		}
		return false;
	}

	//This function returns TRUE if the input is one of the boolean defined in the variable
	//"booleanValues" in "lexemesTypes.h" else it returns FALSE
	bool isBooleanValue(const string &lexeme) { 
		string temp = lexeme; //creates a temporary string variable to hold the value of lexeme
		int sizeOfBoolValues = sizeof(booleanValues) / sizeof(booleanValues[0]);

		//compares the temporary string to all of the strings from "booleanValues" in "lexemesTypes.h"
		//returns true if the string matches to one of the strings in the array, false otherwise
		for (int i = 0; i < temp.length(); i++) {
			for (int j = 0; j < sizeOfBoolValues; j++) {
				if (temp == booleanValues[j]) {
					return true;
				}
			}
		}
		return false;
	}

	//This function returns TRUE if the input is integer literal else FALSE
	bool isIntegerLiteral(const string &lexeme) {
		string temp = lexeme; //creates a temporary string variable to hold the value of lexeme

		//http://en.cppreference.com/w/cpp/language/integer_literal
		bool isDecimal = false;
		bool isOctal = false;
		bool isHex = false;
		bool isBinary = false;

		const char naturalNumbers[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
		int sizeOfNaturalNumbers = 10;
		const char hexLetters[] = { 'x', 'X', 'a', 'A', 'b', 'B', 'c', 'C', 'd', 'D', 'e', 'E', 'f', 'F' };
		int sizeOfHexLetters = 14;
		const char integerSuffix[] = { 'u', 'U', 'l', 'L' };
		int sizeOfIntegerSuffix = 4;

		//checks if the string is 1 character long, if it is and that 1 character is a number from 0-9 then the string is a decimal, turn decimal to true
		if (temp.length() == 1) {
			for (int i = 0; i < sizeOfNaturalNumbers; i++) {
				if (temp.at(0) == naturalNumbers[i]) {
					isDecimal = true;
				}
			}
		}

		//checks if the strings lenght is greater than one (so we can access the 2nd position of the string, since an integer greater than 1 guarantees 2 as a posibility)
		if (temp.length() > 1) {

			//checks if the strings 2nd character hints that it is a decimal number (starts with a non-zero number)
			for (int i = 1; i < sizeOfNaturalNumbers; i++) {
				if (temp.at(0) == naturalNumbers[i]) {
					isDecimal = true;
					break;
				}
			}

			//checks if the string starts with zero
			if (temp.at(0) == naturalNumbers[0]) {

				//checks if the strings 2nd character hints that it is an octal number (2nd char is from 0-7)
				for (int i = 0; i < (sizeOfNaturalNumbers - 2); i++) {
					if (temp.at(1) == naturalNumbers[i]) {
						isOctal = true;
						break;
					}
				}

				//checks if the strings 2nd character hints that it is a hexadecimal number (2nd char is an 'x' or 'X')
				for (int i = 0; i < (sizeOfHexLetters - 12); i++) {
					if (temp.at(1) == hexLetters[i]) {
						isHex = true;
						break;
					}
				}

				//checks if the strings 2nd character hints that it is a binary number (2nd char is a 'b' or 'B')
				for (int i = 4; i < (sizeOfHexLetters - 8); i++) {
					if (temp.at(1) == hexLetters[i]) {
						isBinary = true;
						break;
					}
				}
			}

			//checks if the strings 2nd character hints that we are at its suffix (2nd char is an 'u', 'U', 'l', or 'L')
			//if it is, checks if there is another character, if not then return true
			//if there is still another character, check that that character is also a suffix (string size is at least 3 now)
			//if there are no more characters than return true, otherwise false
			if (!isBinary && !isHex && !isOctal && !isDecimal)
				for (int i = 0; i < sizeOfIntegerSuffix; i++) {
				if (temp.at(1) == integerSuffix[i]) {
					if (temp.length() > 2) {
						for (int j = 0; j < sizeOfIntegerSuffix; j++) {
							if ((temp.at(2) == integerSuffix[j]) && (temp.length() == 3)) {
								return true;
							}
						}
					}
					else {
						return true;
					}
				}
			}
		}

		//if the string is hinted to be a decimal make sure all values are a decimal (0-9) until the end of string (excluding suffix)
		//if it is a decimal value keep isDecimal equal as true, if not make isDecimal equal to false
		if (isDecimal) {
			isDecimal = false;
			int offset = 2;
			for (; offset < temp.length(); offset++) {
				for (int j = 0; j < sizeOfNaturalNumbers; j++) {
					if (temp.at(offset) == naturalNumbers[j]) {
						break;
					}
				}
			}
			if (offset == temp.length()) {
				isDecimal = true;
			}
		}


		return false;
	}

	//This function returns TRUE if the input is float literal else FALSE
	bool isFloatLiteral(const string &lexeme) {
		string temp = lexeme; //creates a temporary string variable to hold the value of lexeme
		return false;
	}

	//This function returns TRUE if the input is string literal else FALSE
	bool isStringLiteral(const string &lexeme) {
		string temp = lexeme; //creates a temporary string variable to hold the value of lexeme
		return false;
	}
}


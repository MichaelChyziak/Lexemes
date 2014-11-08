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
		//http://msdn.microsoft.com/en-us/library/565w213d.aspx
		//create an array of possible identifier characters and natural numbers, as well as the arrays sizes
		const char identifierChars[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
			'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '_' };
		const char naturalNumbers[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
		int sizeofIdentifierChars = 53;
		int sizeOfNaturalNumbers = 10;
		int offset = 0;
		//if the string is a keyword or boolean value, return false (since is not identifier)
		if (isKeyword(lexeme) || isBooleanValue(lexeme)) {
			return false;
		}
		//checks that our string starts with an allowed character (identifierChars), if it is then increase offset by 1
		if (lexeme.length() > 0) {
			for (int i = 0; i < sizeofIdentifierChars; i++) {
				if (lexeme.at(0) == identifierChars[i]) {
					offset++;
					break;
				}
			}
		}
		//checks if our string is "__" or "_" + a capital letter since those are reserved for the for C++ implementations
		//if it is, return false
		if (lexeme.length() > 1) {
			if (lexeme.at(0) == '_' && lexeme.at(1) == '_') {
				return false;
			}
			if (lexeme.at(0) == '_') {
				for (int i = 26; i < (sizeofIdentifierChars - 1); i++) {
					if (lexeme.at(1) == identifierChars[i]) {
						return false;
					}
				}
			}
		}
		//checks that the other characters past the first are all allowed characters (letters, numbers, and underscores)
		//if they are then increase offset by 1
		for (int i = 1; i < lexeme.length(); i++) {
			for (int j = 0; j < sizeofIdentifierChars; j++) {
				if (lexeme.at(i) == identifierChars[j]) {
					offset++;
					break;
				}
			}
			for (int j = 0; j < sizeOfNaturalNumbers; j++) {
				if (lexeme.at(i) == naturalNumbers[j]) {
					offset++;
					break;
				}
			}
		}
		//returns true if the offset equals the length of the string
		if (offset > 0 && offset == lexeme.length()) {
			return true;
		}
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
		const char hexLetters[] = { 'x', 'X', 'a', 'A', 'b', 'B', 'c', 'C', 'd', 'D', 'e', 'E', 'f', 'F' };
		const char integerSuffix[] = { 'u', 'U', 'l', 'L' };
		int sizeOfNaturalNumbers = 10;
		int sizeOfHexLetters = 14;
		int sizeOfIntegerSuffix = 4;
		return false;
	}
	//This function returns TRUE if the input is float literal else FALSE
	bool isFloatLiteral(const string &lexeme) {
		string temp = lexeme; //creates a temporary string variable to hold the value of lexeme
		//http://msdn.microsoft.com/en-us/library/tfh6f0w2.aspx
		int numbercount = 0;
		//counts the number of numbers in a string
		int ecount = 0;
		//counts the number of E,e, and . characters

		int sizeOfNaturalNumbers = 10;
		const char naturalNumbers[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
		//this gets used for alot of funtions perhaps put it in a namespace?

		for (int i = 0; i < temp.length(); i++) {
			for (int j = 0; j < sizeOfNaturalNumbers; j++) {
				if (temp.at(i) == naturalNumbers[j] ) {
					numbercount++;
				}
			}
			if (temp.at(i) == 'e' || temp.at(i) =='E'|| temp.at(i) =='.') {
					ecount++;
				}
		}
		//gets all the counts 
		
		//this statement checks if you actually have . and e characters in the string 
		//then it checks to see if the string is fully composed of numbers and . and e characters
		//if this is true then you have yourself a float literal 
		if(ecount >  0){
           if((ecount + numbercount) == temp.length())
		   {
		     return true;
		   }
		}

		return false;
	}
	//This function returns TRUE if the input is string literal else FALSE
	bool isStringLiteral(const string &lexeme) {
		string temp = lexeme; //creates a temporary string variable to hold the value of lexeme
         //http://msdn.microsoft.com/en-us/library/69ze775t.aspx <- this lists the different types of string literals
		if (temp.length() > 2){
			if( temp.at(0) == '"' && temp.at(temp.length()-1) == '"' ){  
				return true;
			}}
		// if the token is a narrow string variable the token length must be atleast 2 and have a quotation mark at the begining or end of the string


		/*
		if (temp.length() > 3){
			if( (temp.at(0) == 'L' || temp.at(0) == 'R')&&  temp.at(1) == '"' && temp.at(temp.length()-1) == '"' ){  
				return true;
			}}
		// if the token is a wide non-raw literal  or a narrow raw literal you must have atleast  3 terms i.e 1 L or R, a quotation marks preceding this and ending quotation mark
		if (temp.length() > 4){
			if( (temp.at(0) == 'L' ) && (temp.at(1) == 'R' ) && temp.at(2) == '"' && temp.at(temp.length()-1) == '"' ){  
				return true;
			}}
		// if the token is a wide raw literal you must have atleast  4 terms i.e LR" and a quotation mark at the end of the string.
	    */  // This covers a lexical case that only microsoft considers.

		return false;
	}
}

/* Defines functions for converting characters between tabs and spaces.
 * CSC 357, Assignment 1
 * Given code, Spring '24. */

#include "chars.h"
#include <stdio.h>
/* istext: Checks whether or not a character is plain text.
 * NOTE: Do not alter this function. It returns 1 if "c" has an ASCII code in
 *       the ranges [0x08, 0x0D] or [0x20, 0x7E], and 0 otherwise. */
int istext(char c) {
    return (c >= 0x08 && c <= 0x0D) || (c >= 0x20 && c <= 0x7E);
}

/* ttos: Converts a character from tabs to spaces.
 * TODO: Implement this function. It should return the number of characters
 *       placed into "str": 1 to 8 spaces if "next" is a tab (depending on the
 *       current line length), and "next" otherwise. Use "dflt" instead if
 *       "next" is not plain text, and do nothing if neither is plain text.
 *       See also the given unit tests. */
int charCheck(char next, char str[]);

int ttos(char next, char str[], char dflt) {
	int numChar = 0;
	if (istext(next) == 1) {
		numChar = charCheck(next, str);
		return numChar;	
	}	
	else {	
            	if (istext(dflt) == 1) {
			numChar = charCheck(dflt, str);
			return numChar;
		}
		else {
			str[0] = '\0';
			return 0;
		}
	}
}

int charCounter = 0;
/*helper for ttos*/
int charCheck(char c, char str[]) {
	if (c == '\t'){
        	int i = 0;
		int numSpaces = 8 - (charCounter % 8);
                for (i = 0; i < numSpaces; i++) {
                        str[i] = ' ';
                        }
		charCounter = 0;
                str[numSpaces] = '\0';
                return numSpaces;
                }
        else {
                if (c == '\n') {
			charCounter = 0;
                        str[0] = '\n';
			str[1] = '\0';
                        return 1; }                
                else {
			charCounter++;
                        str[0] = c;
                        str[1] = '\0';
                        return 1;
                }
        }
}

/* stot: Converts a character from spaces to tabs.
 * TODO: Implement this function. It should return the number of characters
 *       placed into "str": a tab or nothing if "next" is a space (depending on
 *       the current line length), and 0 to 7 spaces followed by "next"
 *       otherwise. Use "dflt" instead if "next" is not plain text, and do
 *       nothing if neither is plain text. See also the given unit tests. */
int stotHelp (char next, char str[]);
int spaceCntr = 0;
int stotCharCntr = 0;
int stot(char next, char str[], char dflt) {
	int numChar = 0;
	if (istext(next) == 1) {
		numChar = stotHelp(next, str);
		return numChar;
	} else {
		if (istext(dflt) == 1) {
			numChar = stotHelp(dflt, str);
			return numChar;
		} else {
			str[0] = '\0';
			return 0;
			}
	}
	return 0;
}

int stotHelp (char next, char str[]) {
	if (next == ' ') {
		spaceCntr++;
		if (spaceCntr == (8-(stotCharCntr % 8))) {
			str[0] = '\t';
                        str[1] = '\0';
                        spaceCntr = 0;
                        stotCharCntr = 0;
                        return 1;
                } else {
                        str[0] = '\0';
                        return 0;
                  }
       } else {
                 if (next == '\n') {
                         spaceCntr = 0;
                         stotCharCntr = 0;
                         str[0] = '\n';
                         str[1] = '\0';
                         return 1;
                 } else {
                         if (next == '\t') {
			 	int k = 0;
				int nut = 0;
				nut = 8 - ((stotCharCntr + spaceCntr)%8);
				for (k = 0; k < nut; k++){
					str[k] = ' ';
				}
				str[nut] = '\t';
				str[nut+1] = '\0';
				spaceCntr = 0;
				stotCharCntr = 0;
				return nut+1; 
			 } else {
			 	if (spaceCntr > 0) {
                 	        	int i = 0;
                        		for ( i = 0; i < spaceCntr; i++) {
             	                           str[i] = ' ';
                	                }
                        	        str[spaceCntr] = next;
                	                str[spaceCntr+1] = '\0';
					i = spaceCntr + 1;
                                	stotCharCntr = stotCharCntr + spaceCntr + 1;
        	                        spaceCntr = 0;
   	        	                return i;
                        	} else {
                                	str[0] = next;
                          	        str[1] = '\0';
                                	stotCharCntr++;
                                	return 1;
                                }
                        }
                }
	return 0;
	}
}

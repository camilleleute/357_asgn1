/* Defines functions for converting characters between tabs and spaces.
 * CSC 357, Assignment 1
 * Given code, Spring '24. */

#include "chars.h"

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
int ttos(char next, char str[], char dflt) {
	if (istext(next) == 1) {

	}
	else {
		if (istext(dflt) == 1) {
		}
		else {
			return 0
		}
	}
}

/* stot: Converts a character from spaces to tabs.
 * TODO: Implement this function. It should return the number of characters
 *       placed into "str": a tab or nothing if "next" is a space (depending on
 *       the current line length), and 0 to 7 spaces followed by "next"
 *       otherwise. Use "dflt" instead if "next" is not plain text, and do
 *       nothing if neither is plain text. See also the given unit tests. */
int stot(char next, char str[], char dflt) {
    return 0;
}

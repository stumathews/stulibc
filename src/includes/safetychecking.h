/**
 * @file safetychecking.h
 * @brief Safety checking library prototypes.
 * @author Stuart Mathews
 * @date 19 July 2013
 *
 * This header contains the function and type declarations for dealing with safety functionality in the library.
 * This includes ensuring bounds are not overflowed, and that where restrictions are enforced, these are upheld.
 * @see http://devel.stuartmathews.com/stulibc
 */

/** \page safetychecking Safety
bounds checking on data structures and other sanity checks
\include safetychecking.h
*/

#ifndef SAFETY_CHECKING_H
#define SAFETY_CHECKING_H

#include <files.h>
#include <stdlib.h> // exit()
#include <stdio.h>  // sprintf()

/** \brief A pointer to a function that represents a routine that will fix/change the provided int value
 */
typedef void (*FixIntRoutine)(int*);
/** \brief A pointer to a function that represents a routine that will check that the value is valid
 */
typedef bool (*IsIntValidRoutine)(int*);

enum StringChecks {IS_NOT_EMPTY = 2, CHARS_ONLY = 4, ALL_LOWER = 8};

/**
 * Checks to see if the string meets all the validation requirements
 * @param string the string under inspection
 * @param checks the validation requirements (StringChecks enum can be &'ed together)
 * @param functionName The function name that this was called under
 */
#define CHECK_STRING( string, checks ) do { \
	CHK_str( (char*)(string), (checks), (char*)__func__); \
} while (0)

/**
 * Checks to see if the string is not empty and is only alphabetic characters
 * @param string the string under inspection
 * @param checks the validation requirements (StringChecks enum can be &'ed together)
 * @param functionName The function name that this was called under
 */
#define CHECK_STRING_BASICS( string ) do { \
	CHK_str( (string), IS_NOT_EMPTY | CHARS_ONLY, (char*)__func__); \
} while (0)

/** \brief Runs a prefedined check on a string
 * \param string char* The string that needs to be checked
 * \param checks enum StringChecks the check you'd liked performed
 * \param functionName char* the function that this check is being called from
 * \remark Exists the application if the checks fail validation
 */
LIBRARY_API void CHK_str( const char* string, enum StringChecks checks, const char* functionName);

/** \brief Runs a provided data validation routine and its fix routine on provided data
 *
 * \param func_IsDataValid IsDataValid pointer to function that will inspect data for validity
 * \param data int* the int data to be checked for validity
 * \param data_label char* a title for the data to be validated
 * \param func_FixData FixIntRoutine the routine that will attempt to fix the data if the validation routine fails
 * \return LIBRARY_API void
 *
 */
LIBRARY_API void CHK_int(IsIntValidRoutine func_IsDataValid, int* data, char* data_label, FixIntRoutine func_FixData);

/** \brief Aborts the program, printing a provided message (with additional context message)
 *
 * \param condition int
 * \param message char*
 * \param resultContext char*
 * \return void
 *
 */
LIBRARY_API void CHK_ExitIf(int condition, char* message, char* resultContext);
#define ExitIf CHK_ExitIf


#endif

/**
 * @file testing.h
 * @brief Testing library prototypes.
 * @author Stuart Mathews
 * @date 19 July 2013
 *
 * This header contains the function and type declarations for dealing testing functionality in the library.
 * This includes assertions, unit testing functionality etc..
 * @see http://devel.stuartmathews.com/stulibc
 */

/** \page testing Testing
Contains the function and type declarations for dealing testing functionality in the libraryto implement generic unit testing and generic assertions etc..
\include testing.h
*/


#ifndef STULIBC_TESTING_H
#define STULIBC_TESTING_H
#include <constants.h>
#include <assert.h>
#include <debugging.h>

#define RUN_TESTS( tests ) do {\
run_tests( (tests), sizeof((tests))/sizeof(tests[0])); \
} while (0) 
#define TEST(name) name, #name

/** \brief Represents a function to run to test something indicated by name
 */
struct TestDefinition
{
  void (*function)(void);
  char* name;
};

/** \brief Runs each of the tests(test functions) provided, printing the name of the test before running the associated test function
 *
 * \param tests struct TestDefinition* the tests to be run
 * \param num_tests int the number of tests to be run
 * \return void
 *
 */
void run_tests(struct TestDefinition* tests, int num_tests);



#endif // STULIBC_TESTING_H

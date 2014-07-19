/**
 * @file debugging.h
 * @brief Debugging library prototypes.
 * @author Stuart Mathews
 * @date 19 July 2013
 *
 * This header contains the function and type declarations for dealing with debugging functionality in the library.
 * This includes tracing to logs, and reporting.
 * @see http://devel.stuartmathews.com/stulibc
 */

 #ifndef STULIBC_DEBUGGING_H
 #define STULIBC_DEBUGGING_H

 // Debugging functionality like writing to trace files, log files etc.
 enum Severity { MINOR, NORMAL, CRITICAL  };


/** @brief Writes a debug line to file.
 *
 * @param message char* message to write
 * @param filename char* file to write it to
 * @param severity enum Severity the severity of the debug line
 * @return void
 * @remarks The current date and time is prepended to message.
 */
void DBG_WriteLine(char* message, char* filename, enum Severity severity);

 /** @brief Writes a message to a file.
  *
  * @param prefix char* A prefix to tag the message if any or null
  * @param message char* the message to write
  * @param suffix char* the suffix to add to the message or null
  * @param filename char* the file to write the message to
  * @param severity SEVERITY An indication of the error
  * @return void
  * @remarks Adds the date and time to all messages. And appends to the end of @param filename
  *
  */
 void DBG_WriteLineExtra(char* prefix, char* message,char* suffix, char* filename, enum Severity severity);


 #endif // STULIBC_DEBUGGING_H

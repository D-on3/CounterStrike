#ifndef COUNTER_STRIKE_ERRORHANDLING_H
#define COUNTER_STRIKE_ERRORHANDLING_H

#define CURRENT_FUNC_NAME __func__


typedef enum error {
    INVALID_TEAM = -1, NO_ERROR = 0, NULL_PARAMETER, ALLOCATION_ERROR
}Error;


/**
 * Print type of error
 * @param int error type
 * @param char name of current function
 */
void printError(const Error typeOfError, const char *funcName);


/**
 * Check for eventual errors
 * @param pointer to void pointer
 * @param int error type
 * @param current funcName
 * return type of error or NO_ERROR
 */
Error checkForError(const void * const ptrToCheck, const Error typeOfError, const char *funcName);


#endif //COUNTER_STRIKE_ERRORHANDLING_H

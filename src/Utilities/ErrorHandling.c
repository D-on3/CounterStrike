#include "Utilities/ErrorHandling.h"
#include <stdio.h>

Error checkForError(const void * const ptrToCheck, const Error typeOfError, const char *funcName)
{
    Error err = NO_ERROR;

    if(ptrToCheck == NULL)
    {
        err = typeOfError;
        printError(typeOfError, funcName);
    }

    return err;
}

void printError(const Error typeOfError, const char *funcName)
{
    const char *errors[] = {"NO_ERROR" , "NULL_PARAMETER", "ALLOCATION_ERROR", "INVALID_INPUT"};

    fprintf(stderr,"%s function failed.%s found!", funcName, errors[typeOfError]);
}



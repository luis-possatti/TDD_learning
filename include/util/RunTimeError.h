#ifndef __RUN_TIME_ERROR_
#define __RUN_TIME_ERROR_

void RuntimeError(const char * message, int parameter, const char *file, int line);

#define RUN_TIME_ERRROR(description, parameter) \
    RuntimeError(description, parameter, __FILE__, __LINE__)

#endif
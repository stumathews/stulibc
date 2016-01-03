/*
 * threading.c
 *
 *  Created on: 3 Jan 2016
 *      Author: stuart
 */

#include <threading.h>
#include <errors.h>
#include <safetychecking.h>

int THREAD_RunAndForget(threadfunc func, void* threadparam)
{
#ifdef __linux__

	CHK_ExitIf(func == (void*)0, "thread function cannot be null", "THREAD_RunAndForget");

	pthread_t thread;
	int rc = pthread_create(&thread, NULL, func, threadparam);

	if(rc) {
		ERR_Print("Could not create thread.\n", YES);
		return rc;
	} else { return 0; };

#endif

#ifdef _win32
	return -1;
#endif
}




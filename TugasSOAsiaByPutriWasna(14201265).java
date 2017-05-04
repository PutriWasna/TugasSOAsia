#include <stdio.h>
#include <windows.h>

/* by Putri Ade Wasna (14201265) */

int main (void)
{
	printf("by Putri Ade Wasna (14201265)");
	
	
	STARTUPINFO si;
	PROCESS_INFORMATION pi ;
	
	/* allocate memory */
	ZeroMemory (&si , sizeof (si)) ;
	si.cb = sizeof (si);
	
	/* create child process */
	if (!CreateProcess(NULL , /* use command line */
		"C: \\ WINDOWS \\ system32 \\ mspaint.exe", /* command */
		NULL , 	/* don't inherit process handle */
		NULL , 	/* don't inherit thread handle */
		FALSE , /* disable handle inheritance */
		0, /* no creation flags */
		NULL, /* use parent's environment block */
		NULL, /* use parent's existing directory  */
		&si,
	&pi ))
	
	{
		fprintf(stderr, "Create Process Failed") ;
		return -1 ;
	}
	
	/* parent will wait for the child to complete */
	WaitForSingleObject(pi.hProcess, INFINITE);
	printf("Child Complete");
	
	/*close handles */
	CloseHandle(pi.hProcess);
	Closehandle(pi.hThread);
}

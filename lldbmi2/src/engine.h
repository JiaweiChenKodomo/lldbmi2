#ifndef ENGINE_H
#define ENGINE_H

#include "lldbmi2.h"


#define MAX_ARGS 20


typedef struct {
	int sequence;
	char arguments[LINE_MAX];		// must be the same size as cdtline in fromcdt
	int argc;
	const char *argv[MAX_ARGS];
	char threadgroup[NAME_MAX];
	int  thread;
	int  frame;
	int  available;
	int  all;
} CDT_COMMAND;


int         fromcdt      (STATE *pstate, char *line, int linesize);
void        initializeSB (STATE *pstate);
void        terminateSB  ();
int         evalcdtline  (STATE *pstate, const char *cdtline, CDT_COMMAND *cdt_command);
int         scanargs     (CDT_COMMAND *cdt_command);


#endif // ENGINE_H

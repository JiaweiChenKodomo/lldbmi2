
#ifndef LLDBMIG_H
#define LLDBMIG_H

#include </usr/include/sys/syslimits.h>
#include <lldb/API/LLDB.h>
using namespace lldb;

// use system constants
// PATH_MAX = 1024
// LINE_MAX = 2048
// NAME_MAX = 255


#define WAIT_DATA  0
#define MORE_DATA  1

#define FALSE 0
#define TRUE  1

#define THREADS_MAX 50
#define FRAMES_MAX  50

#define VALUE_MAX (NAME_MAX<<1)
#define BIG_VALUE_MAX (NAME_MAX<<2)
#define BIG_LINE_MAX (LINE_MAX<<3)

#define ENV_ENTRIES 100

typedef struct {
	int  lockcdt;
	int  ptyfd;
	bool istest;
	int frames_max;
	int walk_depth_max;
	int change_depth_max;
	bool eof;
	bool isrunning;
	const char *envp[ENV_ENTRIES];
	int  envpentries;
	char envs[BIG_LINE_MAX];
	char *envspointer;
	char cdtbuffer[LINE_MAX];
	char cdtptyname[NAME_MAX];
	char logfilename[PATH_MAX];
	char logbuffer[BIG_LINE_MAX];
	const char *gdbPrompt;
	char lldbmi2Prompt[NAME_MAX];
	char threadgroup[NAME_MAX];
	SBDebugger debugger;
	SBProcess process;
	SBListener listener;
	int threadids[THREADS_MAX];
} STATE;


const char *getTestCommand (int *idTestCommand);
void        writetocdt     (const char *line);
void        cdtprintf      (const char *format, ... );
void        signalHandler (int vSigno);

#endif	// LLDBMIG_H

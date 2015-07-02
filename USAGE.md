# Debug with LLDBMI2

Once LLDBMI2 is installed, 2 steps must be done to debug an application :

1. In "Run / Debug configurations...", create a new "C/C++ Application" and change the GDB debugger (in Debugger tab) from GDB to LLDBMI2. Options to LLDMI2 may be set there. Something like "/usr/local/bin/lldbmi2 --log".
2. In project's properties (or best in Eclipse preferences), "C/C++ Build" tab, "Environment" section, set the LLDB's framework or dynamic library path which is required by LLDBMI2. It can be done with environment variable DYLD_FRAMEWORK_PATH.
3. In project's properties (or best in Eclipse preferences), "C/C++ Build" tab, "Environment" section, set the path for DEBUGSERVER which is required by LLDB's library. It can be done with environment variable DEBUGSERVER_PATH.

Note: If the environment is set in Eclipse preference, it will bet set for all projects once.
In my case it looks like:

    LLDB_DEBUGSERVER_PATH: /Applications/Xcode.app/Contents/SharedFrameworks/LLDB.framework/Resources/debugserver
    DYLD_FRAMEWORK_PATH:   /Applications/Xcode.app/Contents/SharedFrameworks

Two launch configurations are provided with a sample Hello test application.
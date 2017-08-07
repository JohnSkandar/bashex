# Introduction
Bash Extended call utility for Windows Linux Subsystem (WSL).
Calls a Linux command on the WSL Bash by translating Windows paths into Linux paths.

# Getting Started
Usage: `bashex.exe linux_command arguments`
- arguments with spaces must be put between `" "`
- files in the working directory must be referred with `.\`
 
Outcome: `calls bash.exe -c "linux_command arguments"`, where arguments that are paths are translated to Linux paths and put between `' '`.
Arguments that are not paths are left unchanged. 
Works also from 32-bit shell, as it calls `C:\Windows\sysnative\bash.exe`.

# Examples
`bashex.exe vi "E:\My documents\my file.txt"`
translates to:
`bash -c "vi '/mnt/e/My documents/my file.txt'"`
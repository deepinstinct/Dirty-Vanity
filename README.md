# Dirty Vanity
A POC for the new injection technique, abusing windows fork API to evade EDRs.

### Usage 
DirtyVanity.exe [TARGET_PID_TO_REFLECT]

### Runtime steps
  * Allocate and write shellcode to [TARGET_PID_TO_REFLECT]
  * Fork [TARGET_PID_TO_REFLECT] to a new process
  * Set the forked process's start address to the cloned shellcode
  
### Shellcode
The reflected shellcode works with ntdll API. It is generated from the included generation project `shellcode_template`, 
curtesy of https://github.com/rainerzufalldererste/windows_x64_shellcode_template

### Shellcode customization
To customize the shellcode with ease:
* Edit the `shellcode_template` function inside the `shellcode_template` project, according to the instructions in https://github.com/rainerzufalldererste/windows_x64_shellcode_template 
* Compile it 
* Crop the `shellcode_template` function bytes using your faivorite PE parsing tool (eg IDA)
* Those bytes are position independet shellcode. place them in `DirtyVanity.cpp`
* Execute DirtyVanity to watch them get Reflected




@echo Compiling: %1
@ascompiler.exe --Server %1 -p prep.txt -d __SERVER
@if not exist donotpause @pause
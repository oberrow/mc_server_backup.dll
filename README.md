#					                	How to use
------------------------------------------------------------------------------
## dll:

### 1st step, inital setup
link the .lib file to the executable (I'm assuming you already know how) and download the dll file                                                                                                

### 2nd step, basic setup
### you can do these steps in any order
backup::backup::showTime is type bool it can be true or false if it's set to true it will print the time onto the console ( eg. `backup::backup::showTime = true;`)

backup::backup::dir1 is a variable of type std::string put the directory you want to backup here ( eg. `backup::backup::dir1 = "%userprofile%\\Downloads\\dir1;"`)

backup::backup::dir2 is a variable of type std::string put the directory of were the backup will be made ( eg. `backup::backup::dir2 = "%userprofile%\\Downloads\\dir2;"`)

backup::backup::interval is variable of type backup::AUTO with a template argument of int which is just an integer assign this to how long it has to wait before backing up ( eg. `backup::backup::interval = 60`)
  
backup::backup::file is what the log file name is going to be ( eg. `backup::backup::file = "log.txt"`)

### the last step

just put in `backup::backup make_backup;` or another name for the object
  
### last step, 
  
## demo program
### 1st step: inital setup
download the exe file and the dll (make sure they are in the same directory)

### How to use the exe
open cmd in the directory that the exe is in and enter `demo "" ""` with the first "" being the directory you want to backup (copy) and the second "" is where the directory is going to be copyed to.
#                              Features
------------------------------------------------------------------------------
Timestamp on the folder when backed up,
copy's all subdirectory's,
you can make it backup after a [] amount of minutes (put it in a loop and you'll have auto backup)

#                            Known issues
------------------------------------------------------------------------------
1. if you want to have 2 objects that backup different directories than you can't without having to change the variables again
2. the log class can only print one thing to the file

and that's it

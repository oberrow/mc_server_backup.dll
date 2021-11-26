#					                	How to use
------------------------------------------------------------------------------
## dll:

### 1st step, inital setup
link the .lib file to the executable (I'm assuming you already know how) and download the dll file                                                                                                

### 2nd step, basic setup
in the code put `using namespace backup` or use the function `backup::make_backup` this function has 3 parameters one of type `int` the others of type `std::string`

### 3rd step, setting the parameters
first parameter: is how long (in minutes) until it makes the backup this parameter is type int 

second parameter: is the directory (folder) you want to backup ( eg. `backup::make_backup(1, "C:\\Users\\My user\\Documents\dir")` )

third parameter: is the directory (folder) you want the backup to be in (eg. `backup::make_backup(1, "C:\\Users\\My user\\Documents\dir", "C:\\DIR_BACKUP")` )

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

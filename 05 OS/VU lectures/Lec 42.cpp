/*
File Concept:
. Contiguous logical address space
Types:
Data
    . Numeric
    . Character
    . Binary
Program
*/

/*
File Structure:
. None - sequence of words, bytes
. Simple record structure
    . Lines
    . Fixed length
    . Variable length
. Complex Structures
    . Formatted document (.doc etx)
    . Relocatable load file (if .exe is relocatable then this info and which kind of this exe etc are in this file)


Who decides this file structure?
    . OS
        . DOS/Windows
        . exe, .com, .bat
    . program
        . Unix/ Linux
    NOTE: Linux do not have the extension. It just have the consecutive bytes. Even some device also has file.
    Whenever the device has to read or write then we use its file.
*/


/*
File Attributes:
. Name  . Type . Location . Size . Protection . Owner .Time and date created
. Time and date last updated . Read/Write pointer value (the value which is set in file whenever read request for example read 240 bytes then it would start from that pointer and goes till 240 and now pointer next time starts from 240 )


Where attributes are stored?
. In the directory structure, as part of the directory entry for the file -- DOS, windows
. In a separate data structure; in UNIX/Linux this structure is known as the inode for the file.
*/

/*
Directory Entry:
DOS/ Windows: File name and attributes
UNIX/Linux: File name and inode number
    . Namce can be upto 255 chars in BSD UNIX compliant systems
    . inode number --- used to access file's inode.
*/

/*
File Types in UNIX/Linux:
Linux do not have the extensions. But it has the file types:
. Ordinary file
. Directory
. Block-special file
. Character-special file
. Link file(ln -s)
. FIFO (mkfifo or mknode)
In only BSD UNIX compilant systems is also contain:
. Socket (in BSD-compliant systems --- socket)
*/


/*
File Access
. Sequential Access
    . read next
    . write next
    . reset
. Direct Access (Like CD has media files so we can do randomly access)
    . read n (n =  relative block number)
    . write n
    . position to n
        . read next
        . write next
*/

/*
Directory Structure:
A collection of directory entries
    Directory  contains sub- directories and files.
Efficient Searching
Naming -- convenient to users
    . 2 users can have same name for different files
    . The same file can have several different names
. Grouping -- logical grouping of files by properties. 
    Example: All java programs, games
*/

/*
Single-level directory:
A single directory for all users
-- Naming problem
-- Grouping problem
*/

/*
Two-level directory:
Separate directory for each user
-- Pathname
-- Can have same file name for different users
-- Efficient searching because each user has different directory 
-- No grouping capability because each user directory can not have more sub-directories
*/

/*
Tree Directory:
Root
child

Efficient searching 
Grouping capability
Root Directory
Home Directory --- where from the  each user screen show is known as home which is after root.
Current/ Working Directory 


Linux:
    . Root Directory (/)
    . Home Directory
        . ~ , $ HOME, $home
        . cd ~
        . cd
    . Current/Working directory(.)
        .pwd
    . Parent of current directory (..)

Absolute pathname
    . Starts with the root directory
    . /etc, /bin, /usr/bin, /etc/passwd, /home/students/ibraheem 
    SO this is root
Relative pathname:
    . Starts with the current directory or a user's home directory.
    . ~/courses/cs604, ./a.out
*/
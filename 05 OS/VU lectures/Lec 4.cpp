/*

IMPLEMENTATION AND DESIGN GOALS:

Design Goals

User:
operating system should be
convenient to use , easy to learn , reliable ,
safe , and fast .

System designer and administrator:
operating system should be easy to design ,
implement , and maintain , as well as
flexible , reliable error free and efficient.


Maintaining For Flexibility:

Separation of mechanism and policy
is important for flexibility .

Mechanism : determine how to do
something.

Policy : determine what will be done.

Most commonly we give control of policy to admin.
e.g; CPU give to process. Time and specific interval help us to release CPU from one process and assign to other process.
This is mechanism
But for how much time we fix in the mechanism is policy so we give access of it to user.



Implementation in :

1) Assembly language

2) Higher level languages :
   Easier to code
   Compact code
   Easier to port

Nowadays OS are written most of the time in the HIGH LEVEL LANGUAGES including drivers of OS which communicate with hardware controllers.
*/


/*
File System in UNIX/Linux:

UNIX has a hierarchical file system
structure consisting of a root directory
with other directories and files hanging
under it

In a command - line user interface , typed
commands are used to navigate the
system

Directories and files are specified by
filenames
Examples:
 1)cs604 / assignments / assign1.c // This is here we are already in a folder where  cs604 is a folder
 2) / home / students / haroon / courses / cs604 // here start from / and this is root directory





Browsing Directory Structure
     The root directory is the directory
 /   that contains all other directories .
     When a directory structure is
     displayed as a tree , the root
     directory is at the top .
     
 / bin 
     This directory holds binary
executable files that are essential
for correct operation of the system.
 / boot
     
     This directory includes essential
     system boot files including the
     kernel image . 

 / dev
        This directory contains the devices
        available to on the machine
/ etc
       Linux uses this directory to store
       system configuration files
/ home 
    This is where every user on a Linux
       system has a personal directory

/ lib
        Shared libraries and kernel
        modules are stored in this
        directory

/ root The home directory for the
       superuser
/ sbin Utilities used for system
       administration ( halt , ifconfig .
       f=disk , etc. ) are stored in this
       directory

/ tmp
       Used for storing temporary
       files . Similar to C : Windows


/ usr
      Typically a shareable , read - only
      directory . Contains user
      applications and supporting
      files for those applications .
/ var
     This directory contains variable
     data files such as logs ( / var / log ) .
     mail ( / var / mail ) , and spools
     ( / var / spool ) among other things.



Conclusion: / is the root and in that we make home dir where we have multiple directories for our users.
Whenever user login we navigate to home of the user like student, faculty etc.
*/
/*
FIFO making using mknod:

int mknod (const char *path, mode_t mode,
   dev_t dev);
1) path where to make the FIFO in disk
2) 'mode' should be permission mode
3) 'dev' is set to 0 for a FIFO so that this command understands that we are not making device file but FIFO



mknod fails:
  =>  File with the given name exists
  =>  Pathname too long
  => A component in the pathname not    
  => searchable, non-existent, or non-directory
  =>  Destination directory is read-only
  =>  Not enough memory space available
  =>  Signal caught during mknod


*/



/*
Make FIFO using the mkfifo library call:

int mkfifo(const char *path, mode_t mode):
1) path where to make the FIFO in disk
2)'mode' sets permission on FIFO
Every library call, call the system call in order to perform the kernal some operations. library calls are just for the developer use.
Here this library call,   Calls mknod system call in order to make the FIFO in disk.


Same reasons to fail which are for the mknod system call above .

*/


/*
Now we are going to make the client server system using the FIFO.
Server will make the 2 FIFO with name FIFO1 and FIFO2.
Server will read from the FIFO1 and write to FIFO2.
Client will write to FIFO1 and read from FIFO2.
If client do not write anything yet to the FIFO1 then server read call to FIFO1 will block until client write.
If server do not write anything yet to the FIFO2 then client read call to FIFO1 will block until client write.

CODE:
In short code:
Server:
if ((mknod (FIFO1, S_IFIFO I PERMS, 0) < 0)
            && (errno != EEXIST)) (
   perror ("mknod FIFO1"):
   exit (1);
with name FIFO1 and S_IFIFO telling that not device file but FIFO making. and saying that if error is that FIFO already exists then its ok otherwise show error.


if (mkfifo(FIFO2, PERMS) < 0) { // make FIFO2 
   unlink (FIFO1); // If fail then remove FIFO1 also
   perror("mknod FIFO2"):
   exit (1):
Y
 if (readfd - open[FIFO1, ()) // storing file descriptor in readfd using open in FIFO1
   perror ("open FIFO1"):
   exit (1):
}
 if ((writefd - open(FIFO2, 1)<<0) // storing file descriptor in writefd open in FIFO2
   perror ("apen FIFO2"):
   exit (1):

Then by usign these file descriptor for making read and write commands.
At the end we remove the readfd and writefd file descriptor.




CLIENT:
 Similarly make read and write file descriptors for FIFO2 and FIFO1 respectively.
 Then make read and write commands.
 Remove the readfd and writefd file descriptor.
 End process should also close the FIFO which was created. SO here client is the last so it will close the both FIFO's
*/



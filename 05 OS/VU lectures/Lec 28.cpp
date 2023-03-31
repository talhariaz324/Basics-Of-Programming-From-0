/*
Deadlock Avoidance Continue:
Let's see what the Deadlock Avoidance do when the process require the
resources which have single instance type and multi instance type.

Resource Allocation Graph:
New term:
    Claim edge: Pi-->Rj indicates that process Pi may request an instance of
    resource Rj; represented by a dashed line.

    Claim edge converts to request edge when a process requests a resource.
    When a resource is assigned to a process, request edge reconverts to
    an assignment edge.

    When a resource is released by a process, assignment edge reconverts to
    a claim edge.

    Claim edges is dotted line.

    Resources must be claimed a priori in the system (Tell which resource type will be require).

For single type resource Deadlock Avoidance make the RAG
Make the claim edges for the processes and when the process require the
resource, the claim edge converts into the request and then assignment.
If by making assignment it make the cycle then it means there must be a
deadlock so Deadlock Avoidance reconverts to claim edge and wait.
If no cycle found then it proceed to assignment line.

So this is single type resource allocation.
*/

/*
For Multi Type Resource Allocation we use the most famous alogorithm
which is Banker's Algorithm (known as banker because its working like banks, banks take check on each transection like here we are doing in this algo)
Banker's Algorithm:
Multiple instances of resources.
Each process must a priori claim maximum use. (Tell max use of resources)
When a process requests a resource it may have to wait.
When a process gets all its resources it must return in a finite amount
of time.

Data Structure for the Banker 's Algorithm

n = number of processes
m = number of resources types
available: Vector of length m. If available[j] = k, there are k instances
of resources type Rj available.

Max: n * m matrix: If Max[i,j] = k then process Pi may request at most
k instances of resource type Rj.

Allocation: n * m  matrix: If Allocation[i,j] = k then Pi is currently 
allocated k instances of Rj.

Need: n * m matrix: If Need[i,j] = k then Pi may need k more instances of
Rj to complete its task. (Resources which may need to complete.  have some resources already)

Need[i,j] = Max[i,j] - Allocation[i,j]


Safety Algorithm:
Let Work and Finish be vectors of length m and n respectively.
Step 1:
Work = Available where; Available is local variable of available resources
Finish[i] = false; 

Find the process i such that the both conditions:
Step 2:
a) Finish[i] = false
b) NeedOfi <= Work
if no such i exists, goto to step 4.
If satisfy,
Step 3:
Work = Work  + Allocation
Finish[i] = true and goto step 2 again for other processes checking.

Step 4: If Finish[i]  ==true for all i, then the system is in a safe state.


Here ends the Safety Algorithm, now see what it do on process arrival.


Resource Request Algorithm for Pi

Requesti = request vector for Pi
If Request[j] = k then process Pi wants k instances of resource type Rj.
    1- If Requesti <= Needi goto step 2
    Otherwise, report error since process has exceed its maximum claim.
    2- If Requesti <= Available, goto step 3 
        Otherwise Pi must wait, since resources are not available.
    3- Pretend to allocate requested resources to Pi by modifying the state as follows:
    Available  = Available - Requesti;
    Allocationi = Allocationi + Requesti;
    Needi = Needi - Requesti;
    If safe => the resources are allocated Pi
    If unsafe => Pi must wait, and the old resource allocation state is restored.
*/

/*
Summary:
Process requests.
2 conditions check
    1- Requesti <= Needi
    2- Requesti <= Available
If true then it grant the request and send to the safety alogorithm.
safety alogorithm check weather state would be safe or not after granting
this resiurce request. If not, then it undone or wait. If yes, then resource is given.
*/

/*
See Example of safety algorithm from 46mint.
*/ 
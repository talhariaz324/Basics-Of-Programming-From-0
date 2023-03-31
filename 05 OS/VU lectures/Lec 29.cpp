/*
DeadLock Detection:
Allow system to enter a deadlock state
Detection algorithm
Recovery scheme
*/

/*
Detection algorithm for single instance of each resource type:
Maintain a wait-for graph
    Nodes are processes
    Pi --> Pj if Pi is waiting for Pj

What is wait-for graph?
Wait-for graph is get from the Resource Allocation Graph
How?
We just remove the resource and then make 1 arrow as it is where it is going.
Then you will find one process is connecting to the other process. 

Periodically invoke an algo that searches for a cycle in the wait-for graph.
The algorithm is expensive--- It requires an order of n^2 operation. where
n is the number of vertices in the graph.

If algo find the cycle in the wait-for graph then deadlock otherwise not.
*/

/*
Multiple Instance of each resource type:
More similar to Banker's algorithm but here we check 1 time and at the end 
if no process is left then deadlock. If at the end some process is still need
resources then we check that at the work resources are able to fulfil that process
then fulfill it and no deadlock but if not able then deadlock because all processes not satisfied.


Available: A vector of length m indicates the number of available resources
of each type.

Allocation: An n*m matrix defines the number of resources iof each type currently
allocated to each process.

Request: An n*m matrix indicates the current request of each process. If
Request[i,j] = k then process Pi is requesting k more instances of resource
type Pi.

Let Work and Finish be vectors of length m and n respectively initialize.
Step 1:
Work = Available
if Allocationi != 0
then 
Finish[i]  = false;
else
Finish[i] = true;

Means, when pi allocation is not 0 then it is not finish yet.
Step 2:

Find an index i such that both:
a) Finish[i] == false
b) Requesti <= Work
if no such i exists, goto step 4

Step 3:
Work = Work + Allocationi
Finish[i] = true
goto step 2 and check other processes as well.

Step 4:
If Finish[i] == false for some i, 1<=i<=n, then the system is in deadlock
state. Moreover, if Finish[i] == false, then Pi is deadlock.

Example 32:11 video
*/

/*
How often should the detection algorithm be invoked?
    Every time a request for allocation cannot be granted immediately,
    Make check of deadlock and then give resource.
    which is expensive but process causing the deadlock is identified,
    along with processes involved in deadlock.

    Periodically (time base) or based on the CPU utilization

    Arbitrarily- there may be many cycles in the resource graph and we would
    not be able to tell which of the many deadlocked processes "caused" the deadlock.
*/

/*
Recovery from the deadlock:
1- Process termination
2- Resource Preemption


Process termination:
-> Abort all deadlocked processes
-> Abort one process at a time until the deadlock cycle is eliminated

In which order should we choose to abort processes?
Priority of a process
How long the process has computed. and how much longer to completion
Resources the process has used
Resources the process needs to complete
How many processes will need to be terminated
Is the process interactive or batch
*/

/*
Resource Preemption:
Step 1:
Selecting a victim for taking its all resources and give to other process -- minimize cost
Step 2:
RollBack -- return to some safe state, restart process from that state.
Step 3:
Starvation -- same process may always be picked as victim; include number of
rollbacks  in cost factor.
*/
/*
Deadlock Handling:
-> Ensure that the system will never enter a 
deadlock state.
-> Allow the system to enter a deadlock
state and then recover.
-> Ignore the problem and pretend that
deadlocks never occur in the system.

3 Methods:
1) Deadlock Prevention
2) Deadlock Avoidance
3) Deadlock detection and recovery
*/

/*
Deadlock Prevention:
Restrain the ways resource allocation requests can be made to ensure that
at least one of the four necessary conditions is violated.
Means Violate at least 1 condition which are necessary for deadlock.

Mutual Exclusion:
Cannot be prevented for all resources. Some resources are inherently
non-shareable because their states cannot be saved and restored without
ill effects, such as printer.
Mean it is not possible for all resources.

Hold and wait: 
We must guarantee that whenever a process requests a resource, it does
not hold any other resources.

Require a process to request and be allocated all its resources before it
begins execution OR allow a process to request resources only when
the process has none.

Low resource utilization; starvation possible.

No Preemption:
If a process that a is holding some resources requests another resource
that cannot be immediately allocated to it, then all resources currently
being held by it are released.

Preempted resources are added to the list of resources for which the
process is waiting for.

Process will be restated only when it can regain its old resources as
well as the new ones that it has requested.


Circular Wait: impose a total ordering of all resources types, and require
that each process requests resources in an increasing order of enumeration.

We assign a unique number to each resource type by using function F: R->N F is function, R is resource, N is number
and make sure that processes request resources in an increasing order of enumeration

For example, tape drive = 1, disk drive = 5, printer = 12
if process has tape then it can have disk and printer
but if process has disk then it cant have tape because resource allocation
should be increasing order of enumeration.

Proof:
Suppose the cycle last process is Pk
and starting process is p0.
then pk should link to p0.
So,
p0 -> p1 -> p2 -> pk -> p0
R0 -> R1 -> R2 -> Rk -> R0
This mean
F(R0) < F(R1) and F(R1) < F(R2) because of increasing order of enumeration
In this way, F(R0) < F(R0) which is impossible
There can be no circular wait.
*/



/*
Deadlock Avoidance:
Requires that the system has additional a priori information available
about the use of resources by processes.

Simplest and most useful model requires that each process declare the 
maximum number of resources of each type that it mat need.


The deadlock-avoidance algorithm dynamically examines the resource-allocation
state to ensure that there can never be a circular wait condition.

Resource Allocation state is defined by the number of available and
allocated resources, and the maximum demands of the processes.

Safe State:
Safe state mean all the processes can execute (in some order).
When a process requests an available resource, system must decide if
immediate allocation leaves the system in a safe state. 

System is in a safe state if there exists a safe sequence of all processes.

Sequence <P1, P2, ..., Pn> is safe if for each Pi, the resources that Pi
can still request can be satisfied by the currently available resources,
plus the resources held by all the Pi, with j<i. In other words, a safe
sequence specifies the order in which processes can be finished.    

If Pi resource need are not immediately available, then Pi can wait until
all Pi have finished.

When Pi are finished, Pi can obtain needed resources, execute, return
allocated resources, and terminate.

When Pi terminates, Pi+1 can obtain its needed resources and so on.

Basic Facts:
If a system is in safe state => No Deadlock
If a system is in unsafe state => Possibility of deadlock due to the 
behaviour of processes.

Avoidance => ensure that a system never enters an unsafe state.


*/
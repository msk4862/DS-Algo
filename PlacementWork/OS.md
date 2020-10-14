# Introduction to OS

An operating system acts as an intermediary between the user of a computer and computer hardware. The purpose of an operating system is to provide an environment in which a user can execute programs in a convenient and efficient manner.

* __Components__ of OS
    - UI: responsible for ease of use
    - Kernel: responsible for resource sharing in effcient manner

* Computer consists of ![BasicComputer](https://media.geeksforgeeks.org/wp-content/uploads/os.png)
    - User
    - System and Application programes
    - OS
    - Hardware
        - CPU
            - Control Unit
            - ALU
        - I/O devices
        - Storage Devices

* __System Programmes:__ That can create other programes e.g. compilers, loaders, assemblers,etc.
* __Application Programmes:__ User programs, database programs, text editors, Excel, etc.

* OS is designed to serve two basic **purposes**:
    1. It controls the **allocation** and use of the computing System’s **resources** among the various user and tasks.
    2. It provides an **interface** between the computer hardware and the user that simplifies and makes feasible for coding, creation, debugging of application programs.


# Functions of OS

1. Security
2. Control over system performance
3. Memory, Process, Device, File Managements
4. Job Scheduling
5. Error detection and Handling

# Multiprogramming, multitasking, multithreading and multiprocessing

1. __Multi programming (Single CPU):__ 

    - In a multi-programmed system, as soon as one job goes for an I/O task, the Operating System interrupts that job, chooses another job from the job pool (waiting queue), gives CPU to this new job and starts its execution.
    
    -  The previous job keeps doing its I/O operation while this new job does CPU bound tasks.

    - As soon as a job completes its I/O operation and comes back for CPU bound tasks, the CPU is allocated to it.

    - Hence CPU is not __idle__ waiting for an I/O opertation to complete.

2. __Multiprocessing (Multiple CPUs):__
    
    - Multiprocessing is the use of **two or more CPUs** (processors) within a single Computer system.

    -  With the help of multiprocessing, many processes can be executed simultaneously on multi processors.

3. __Multitasking:__

    - multi programming works solely on the concept of context switching whereas multitasking is based on time sharing alongside the concept of context switching.

    - each process is assigned some specific quantum of time for which a process is meant to execute. Say there are 4 processes P1, P2, P3, P4 ready to execute. So each of them are assigned some time quantum for which they will execute e.g time quantum of 5 nanoseconds (5 ns). As one process begins execution (say P2), it executes for that quantum of time (5 ns). After 5 ns the CPU starts the execution of the other process (say P3) for the specified quantum of time.

    - Here also basically a context switch is occurring but it is occurring so fast that the user is able to interact with each program separately while it is running.
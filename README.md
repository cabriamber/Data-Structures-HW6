*******************************************************
* Name : Cabri Chamberlin
* Student ID: 101051122
* Class : CSCI 2421
* HW# : 6
* Due Date : July 22, 2024
*******************************************************
Read Me
*******************************************************
* Description of the program
*******************************************************
The program contains a simulation for a car wash. It will read information
from an input file to determine the arrival times of cars to the car wash. 
It will then calculate the time waited and time departed for each car, as well 
as the overall statistics for the car washes performance that day. 
*******************************************************
* Source files
*******************************************************
* Name: main.cpp
Main program. This is the driver program that calls sub-functions
to create instances of cars, which arrive at a car wash at staggered times, 
and must wait in line to get a car wash.
* Name: Car.h
Contains the definition for the class Car. 
* Name: Car.cpp
Contains the implementation of the Car class defined in Car.h. Car objects 
are able to store their arrival time, departure time, and calculate their wait time, 
as well as total time spent at the car wash. 
*******************************************************
* Circumstances of programs
*******************************************************
The program runs successfully.
The program was developed and tested on Apple clang version 15.0.0 
(clang-1500.1.0.2.5)
*******************************************************
* How to build and run the program
*******************************************************
1. Uncompress the zip file 
2. Open the src folder in the your code editor
3. compile all .cpp files in the src folder
   (either g++ *.cpp or g++ main.cpp Car.cpp)
4. run the executable file and view the output in the terminal window
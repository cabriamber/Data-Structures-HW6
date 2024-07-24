/********************************************
* Car.h contains the definition for the Car class. 
* car objects represent arrivals to a car wash. They are 
* able to track their arrival time, car wash start time, and 
* departure time, as well as calculate their time spent waiting, 
* and total time at the car wash. Car objects can be displayed to 
* the terminal window using <<.  
* 
*
* Author: Cabri Chamberlin
* Version: July 22, 2024 
*********************************************/
#ifndef CAR_H
#define CAR_H

#include <ostream> 

class Car {

    friend std::ostream& operator << (std::ostream&, Car&);

public: 

    Car(); 
    Car(int); 

    int getCarCount(); 
    int getArrivalTime(); 
    int calculateWaitTime(); 
    int getWaitTime(); 
    int getStartTime(); 
    int getDepartTime(); 
    void calculateTotalTime(); 
    int getTotalTime(); 

    void setArrivalTime(int); 
    void setStartTime(int); 
    void setDepartTime(int);

private: 
    static int carCount; 
    int arrivalTime; 
    int waitTime; 
    int startTime; 
    int departTime; 
    int totalTime; 

};


#endif 
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
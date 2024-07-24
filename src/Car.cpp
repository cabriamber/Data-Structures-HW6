#include "Car.h"
#include <iostream> 
#include <iomanip>
    using std::setw; 

int Car::carCount = 0; 

std::ostream& operator << (std::ostream& output, Car& aCar) {
    output << setw(0) 
    << aCar.getArrivalTime() << setw(13) 
    << aCar.getStartTime() << setw(13)
    << aCar.getWaitTime() << setw(11)
    << aCar.getDepartTime() << setw(12)
    << aCar.getTotalTime() << setw(12)
    <<std::endl; 
}

Car::Car(int theArrivalTime) {
    arrivalTime = theArrivalTime; 
    waitTime = 0; 
    startTime = -100; 
    departTime = 0; 
    carCount++; 
} 

int Car::getCarCount() {
    return carCount; 
}
int Car::getArrivalTime() {
    return this->arrivalTime; 
}
int Car::calculateWaitTime() {
    waitTime = startTime - arrivalTime; 
}
int Car::getWaitTime() {
    return this->waitTime; 
}
int Car::getStartTime() {
    return this->startTime; 
}
int Car::getDepartTime() {
    return this->departTime; 
}

void Car::setArrivalTime(int theArrivalTime) {
    arrivalTime = theArrivalTime; 
}
void Car::setStartTime(int theStart) {
    startTime = theStart; 
}
void Car::setDepartTime(int depTime) {
    departTime = depTime; 
}
void Car::calculateTotalTime() {
    totalTime = departTime - arrivalTime; 
}
int Car::getTotalTime() {
    return this->totalTime; 
} 

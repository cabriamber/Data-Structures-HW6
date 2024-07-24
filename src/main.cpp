#include "Car.h"
#include <string> 
    using std::string; 
#include <iostream> 
    using std::cin; 
    using std::cout; 
    using std::endl; 
#include <fstream> 
#include <vector>
    using std::vector; 

//note: My algorithm produced slightly different results than the example, because 
//I wrote it with the assumption that two events cannot occur simultaneously. For example, 
//if one car departs at time = 4, the next car in the queue will enter the car wash at time = 5, 
//not at time = 4. Because of that, there are a few numbers in my output table that are 1-2 minutes
//larger than the solution in the example. 
int main() {
    // array of cars to hold all cars that will come to the car wash
    vector<Car*> carVector; 

    //array to manage the queue at the car wash 
    vector<Car*> carQueue; 

    //open input file 
    std::ifstream inputFile("../data/arrivals.txt"); 
    string newArrivalString; 
    int newArrivalInt; 
    int amount = 0; 

    //create new cars with arrival times given in input file 
    while(getline(inputFile, newArrivalString)) {
        // cout << "newArrivalString: " << newArrivalString << endl; 
        newArrivalInt = std::stoi(newArrivalString); 
        // cout << "newArrivalInt: " << newArrivalInt << endl; 
        carVector.push_back(new Car(newArrivalInt)); 
        amount++; 
    }

    //confirm that cars were added to array 
    // for (int i = 0; i < amount; i++) {
    //     cout << i << endl; 
    //     cout << carVector[i]->getArrivalTime() << endl; 
    // }

    //run simulation on cars 
    int minutesElapsed = 0; 
    int carsInQueue = 0; // total number of cars in queue
    int currentCar = 0; // index number of the car currently first in line
    for (int i = 1; i <= 540; i++) {
        //cout << i << endl; 
        minutesElapsed = i; 
        //add cars to the queue when they arrive
        for (int x = 0; x < amount; x++) {
            if (carVector[x]->getArrivalTime() >= 540) {
                cout << "The car arrived after closing time and was not serviced" << endl; 
            }
            //cout << carVector[x]->getArrivalTime() << endl; 
            // cout << "inside nested for loop" << endl; 
            if (carVector[x]->getArrivalTime() == i) {
                // cout << "inside arrival time if statement" << endl; 
                 carQueue.push_back(carVector[x]); 
                carsInQueue++; 
                // cout << "number of cars in queue " << carQueue.size() << endl; 
            }
        }//end of inner for loop 
        // cout << "exited nested for loop" << endl; 
        // cout << "current car number " << currentCar << endl; 
        // cout << "current queue number " << carQueue.size() << endl; 
        // cout << carQueue[currentCar] << endl; 
        // // cout << carQueue[currentCar]->getStartTime() << endl; 
        // cout << "If we make it to this line, that wasn't the problem" << endl; 
        //if there is only one car in line send them into the car wash
        if (currentCar < carQueue.size()) {
            if (carQueue[currentCar]->getStartTime() == -100) {
                carQueue[currentCar]->setStartTime(minutesElapsed); 
            }
        }
        //when a car is done with the car wash, move down the list
        if (currentCar < carQueue.size()) {
            if ((carQueue[currentCar]->getStartTime() + 3) == minutesElapsed) {
                // cout << "inside car is done if statement" << endl; 
                //cout << carQueue.size() << endl; 
                // cout << "Current car is index: " << currentCar << endl; 
                carQueue[currentCar]->setDepartTime(minutesElapsed); 
                carQueue[currentCar]->calculateWaitTime();
                carQueue[currentCar]->calculateTotalTime(); 
                currentCar++;  
                carsInQueue--; 
            }
        }


    }//end of time control for loop 

    //display results for each car in simulation 
    cout << "Results:" << endl; 
    cout << "Arrival Time|Start Time|Wait Time|Depart Time|Total Time" << endl; 
    for (int i = 0; i < amount; i++) {
        cout << *carVector[i]; 
    }

    //calculate and display statistics 
    int totalWaitTime = 0; 
    float averageWaitTime = 0.0; 
    int totalWashUse = 0; 
    float percentageCarWashUsed = 0.0; 
    //total time waited 
    for (int i = 0; i < amount; i++) {
        totalWaitTime += carVector[i]->getWaitTime(); 
    }
    //average time waited 
    averageWaitTime = totalWaitTime / amount; 
    //total number of minutes car wash was in use 
    totalWashUse = amount * 3; 
    //percentage of time car wash was in use 
    percentageCarWashUsed = (totalWashUse * 100) / 540; 

    cout << endl; 
    cout << "Car Wash Statistics: " << endl; 
    cout << "Total Time Waited: " << totalWaitTime << " minutes" << endl;
    cout << "Average amount of time waited: " << averageWaitTime << " minutes" << endl;  
    cout << "Total Time car wash was in use: " << totalWashUse << " minutes" << endl; 
    cout << "Percentage of the time car wash was in use: " << percentageCarWashUsed << " percent" << endl; 


}
// name(s) and Perm 
// This is the only file to submit.

#include "car.hpp"
#include <cstddef>
#include <cstring>
#include <iostream>
using namespace std;

Car::Car() { 
    manufacturer = nullptr;
    model = nullptr;
    zeroToSixtyNs = 0;
    headonDragCoeff = 0;
    horsepower = 0;
    backseatDoors = None;
    seatCount = 0;
}

Car::Car(char const* const manufacturerName, char const* const modelName, PerformanceStats perf, uint8_t numSeats, DoorKind backseatDoorDesign) {
    manufacturer = new char[sizeof(manufacturerName)]; //declare an array of the size of the array the pointer is pointing to
    strcpy(manufacturer,manufacturerName);
    
    
    model = new char[sizeof(modelName)];
    strcpy(model,modelName);
    
    zeroToSixtyNs = perf.zeroToSixtyNs;
    headonDragCoeff = perf.headonDragCoeff;
    horsepower = perf.horsepower;
    seatCount = numSeats;  
    backseatDoors = backseatDoorDesign;
     
}
Car::Car(Car const& o) {
    this->manufacturer = o.manufacturer;
    this->model = o.model;
    this->zeroToSixtyNs = o.zeroToSixtyNs;
    this->headonDragCoeff = o.headonDragCoeff;
    this->horsepower = o.horsepower;
    this->backseatDoors = o.backseatDoors;
    this->seatCount = o.seatCount;
}

Car& Car::operator=(Car const& o) {
    this->manufacturer = o.manufacturer;
    this->model = o.model;
    this->zeroToSixtyNs = o.zeroToSixtyNs;
    this->headonDragCoeff = o.headonDragCoeff;
    this->horsepower = o.horsepower;
    this->backseatDoors = o.backseatDoors;
    this->seatCount = o.seatCount;
    return *this;
}

Car::~Car() {
    delete[] manufacturer;
    delete[] model;
}

char const* Car::getManufacturer() const {
    if (this->manufacturer == nullptr) {
        return "NULL"; 
    }
    else {
        return this->manufacturer;  
    }  
}

char const* Car::getModel() const {
    if (this->model == nullptr) {
        return "NULL"; 
    }
    else {
        return this->model;  
    }  
}

PerformanceStats Car::getStats() const {
    return PerformanceStats(this->horsepower,this->zeroToSixtyNs,this->headonDragCoeff);
}

uint8_t Car::getSeatCount() const {
    return this->seatCount;
}

DoorKind Car::getBackseatDoors() const {
    return this->backseatDoors;
}

void Car::manufacturerChange(char const* const newManufacturer) {
    free(this->manufacturer);
    this->manufacturer = new char[sizeof(newManufacturer)];
    strcpy(manufacturer,newManufacturer);
}

void Car::modelNameChange(char const* const newModelName) {
    free(this->model);
    this->model = new char[sizeof(newModelName)];
    strcpy(this->model,newModelName);
}

void Car::reevaluateStats(PerformanceStats newStats) {
    this->zeroToSixtyNs = newStats.zeroToSixtyNs;
    this->headonDragCoeff = newStats.headonDragCoeff;
    this->horsepower = newStats.horsepower;
}

void Car::recountSeats(uint8_t newSeatCount) { 
    this->seatCount = newSeatCount;
}

void Car::reexamineDoors(DoorKind newDoorKind) {
    this->backseatDoors = newDoorKind;
}
/*
Car(Car const& o);
Car& operator=(Car const& o);
~Car();
char const* getManufacturer() const;
char const* getModel() const;
PerformanceStats getStats() const;
uint8_t getSeatCount() const;
DoorKind getBackseatDoors() const;
void manufacturerChange(char const* const newManufacturer);
void modelNameChange(char const* const newModelName);
void reevaluateStats(PerformanceStats newStats);
void recountSeats(uint8_t newSeatCount);
void reexamineDoors(DoorKind newDoorKind);
*/

int main() {
    Car* defaultCar = new Car();

    Car* startingCar = new Car("Honda","Civic",PerformanceStats(10,11,12),4,None);

    Car* testCar = new Car(*startingCar); 

    cout << startingCar << endl; 
    cout << testCar << endl; 
    cout << testCar->getManufacturer() << endl;
    testCar->manufacturerChange("Dodge");
    cout << testCar->getManufacturer() << endl;

    testCar = defaultCar; 
    cout << testCar << endl;
    cout << testCar->getManufacturer() << endl;

}
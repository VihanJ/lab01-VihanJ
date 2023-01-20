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
    manufacturer = o.manufacturer;
    model = o.model;
    zeroToSixtyNs = o.zeroToSixtyNs;
    headonDragCoeff = o.headonDragCoeff;
    horsepower = o.horsepower;
    backseatDoors = o.backseatDoors;
    seatCount = o.seatCount;
}

Car::~Car() {
    delete manufacturer;
    delete model;
}

char const* Car::getManufacturer() const {
    if (this->manufacturer == nullptr) {
        return nullptr; 
    }
    else {
        return this->manufacturer;  
    }  
}

char const* Car::getModel() const {
    if (this->model == nullptr) {
        return nullptr; 
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

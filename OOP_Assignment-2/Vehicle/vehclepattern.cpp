#include <iostream>
#include <string>

// Abstract base class
class Vehicle {
private:
    int vehicleId;
    std::string vehicleName;

public:
    Vehicle(int id, const std::string& name) : vehicleId(id), vehicleName(name) {}

    // Getter and Setter for vehicleId
    int getVehicleId() const {
        return vehicleId;
    }

    void setVehicleId(int id) {
        vehicleId = id;
    }

    // Getter and Setter for vehicleName
    const std::string& getVehicleName() const {
        return vehicleName;
    }

    void setVehicleName(const std::string& name) {
        vehicleName = name;
    }

    // Pure virtual functions
    virtual void startEngine() = 0;
    virtual void displayInformation() = 0;
};

// Derived class Car
class Car : public Vehicle {
private:
    int numberOfDoors;

public:
    Car(int id, const std::string& name, int doors) 
    : Vehicle(id, name), numberOfDoors(doors) {}

    // Getter and Setter for numberOfDoors
    int getNumberOfDoors() const {
        return numberOfDoors;
    }

    void setNumberOfDoors(int doors) {
        numberOfDoors = doors;
    }

    // Override startEngine() for Car
    void startEngine() override {
        std::cout << "Car Engine Sound Started" << std::endl;
    }

    // Override displayInformation() for Car
    void displayInformation() override {
        std::cout << "Car Information:\n";
        std::cout << "ID: " << getVehicleId() << "\n CarName: " << getVehicleName() << "\nNumber of Doors: " << numberOfDoors << std::endl;
    }
};

// Derived class Motorcycle
class Motorcycle : public Vehicle {
private:
    std::string type;
    double engineDisplacement;

public:
    Motorcycle(int id, const std::string& name, const std::string& bikeType, double displacement)
        : Vehicle(id, name), type(bikeType), engineDisplacement(displacement) {}

    // Getter and Setter for type
    const std::string& getType() const {
        return type;
    }

    void setType(const std::string& bikeType) {
        type = bikeType;
    }

    // Getter and Setter for engineDisplacement
    double getEngineDisplacement() const {
        return engineDisplacement;
    }

    void setEngineDisplacement(double displacement) {
        engineDisplacement = displacement;
    }

    // Override startEngine() for Motorcycle
    void startEngine() override {
        std::cout << "Motorcycle Engine Started" << std::endl;
    }

    // Override displayInformation() for Motorcycle
    void displayInformation() override {
        std::cout << "Motorcycle Information:\n";
        std::cout << "ID: " << getVehicleId() << "\nMotorCycle Name: " << getVehicleName() << "\nType: " << type
                  << "\nEngine Displacement: " << engineDisplacement << " cc" << std::endl;
    }
};

int main() {
    // Create objects
    Car car(1, "Audi", 4);
    Motorcycle motorcycle(2, "Harley Davidson", "Sport", 700.0);

    // Use polymorphism
    Vehicle* vehicle1 = &car;
    Vehicle* vehicle2 = &motorcycle;

    // Start engines
    vehicle1->startEngine();
    vehicle2->startEngine();

    // Display information
    vehicle1->displayInformation();
    std::cout << "\n";
    vehicle2->displayInformation();

    return 0;
}

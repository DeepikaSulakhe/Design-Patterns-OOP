#include <iostream>
// interface class
class TransportVehicle {
public:
    virtual void loadCargo() = 0;
    virtual void startJourney() = 0;
    virtual ~TransportVehicle() {}
};

enum class VehicleType {
    TRUCK,
    SHIP,
    AIRPLANE
};

// Concrete classes
class Truck : public TransportVehicle {
public:
    void loadCargo() override {
        std::cout<<"Loading cargo onto Truck"<<std::endl;
    }

    void startJourney() override {
        std::cout<<"Starting journey on the Truck"<<std::endl;
    }
};

class Ship: public TransportVehicle {
public:
    void loadCargo() override {
        std::cout<<"Loading cargo onto Ship"<<std::endl;
    }

    void startJourney() override {
        std::cout<<"Starting journey on the Ship"<<std::endl;
    }
};

class Airplane: public TransportVehicle {
public:
    void loadCargo() override {
        std::cout<<"Loading cargo onto Airplane"<<std::endl;
    }

    void startJourney() override {
        std::cout<<"Starting journey on the Airplane"<<std::endl;
    }
};

// Factory class
class TransportVehicleFactory {
public:
    TransportVehicle* createTransportVehicle(VehicleType vehicleType) {
        TransportVehicle *vehicle = nullptr;
        switch(vehicleType) {
            case VehicleType::TRUCK:
                vehicle = (TransportVehicle*) new Truck();
                break;
            case VehicleType::SHIP:
                vehicle = (TransportVehicle*) new Ship();
                break;
            case VehicleType::AIRPLANE:
                vehicle = (TransportVehicle*) new Airplane();
                break;
        }
        return vehicle;
    }
};

int main() {
    TransportVehicleFactory transportVehicleFactory;
    TransportVehicle *vehicle = nullptr;
    std::cout<<std::endl<<"Creating Truck transport:"<<std::endl;
    vehicle = transportVehicleFactory.createTransportVehicle(VehicleType::TRUCK);
    vehicle->loadCargo();
    vehicle->startJourney();
    delete vehicle;
    vehicle = nullptr;

    std::cout<<std::endl<<"Creating Ship transport:"<<std::endl;
    vehicle = transportVehicleFactory.createTransportVehicle(VehicleType::SHIP);
    vehicle->loadCargo();
    vehicle->startJourney();
    delete vehicle;
    vehicle = nullptr;

    std::cout<<std::endl<<"Creating Airplane transport:"<<std::endl;
    vehicle = transportVehicleFactory.createTransportVehicle(VehicleType::AIRPLANE);
    vehicle->loadCargo();
    vehicle->startJourney();
    delete vehicle;
    vehicle = nullptr;

    return 0;
}
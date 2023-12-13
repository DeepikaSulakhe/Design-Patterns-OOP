#include <iostream>
#include <string>

// Component Interface
class Cake {
public:
    virtual std::string getName() const = 0;
    virtual int cost() const = 0;
    virtual ~Cake() {}
};

// Concrete Component
class RegularCake : public Cake {
public:
    std::string getName() const override {
        return "Cake";
    }

    int cost() const override {
        return 15;
    }
};

// Decorator Base Class
class CakeDecorator : public Cake {
protected:
    Cake* cake;

public:
    CakeDecorator(Cake* baseCake) : cake(baseCake) {}

    std::string getName() const override {
        return cake->getName();
    }

    int cost() const override {
        return cake->cost();
    }
};

// Concrete Decorator: MultiLayeredCakeDecorator
class MultiLayeredCakeDecorator : public CakeDecorator {
public:
    MultiLayeredCakeDecorator(Cake* baseCake) : CakeDecorator(baseCake) {}

    std::string getName() const override {
        return cake->getName() + " Multi-layered";
    }

    int cost() const override {
        return cake->cost() + 10; // Additional cost for layers
    }
};

// Concrete Decorator: SprinklesDecorator
class SprinklesDecorator : public CakeDecorator {
public:
    SprinklesDecorator(Cake* baseCake) : CakeDecorator(baseCake) {}

    std::string getName() const override {
        return cake->getName() + " with sprinkles";
    }

    int cost() const override {
        return cake->cost() + 5; // Additional cost for sprinkles
    }
};

// Concrete Decorator: SayingDecorator
class SayingDecorator : public CakeDecorator {
private:
    std::string saying;

public:
    SayingDecorator(Cake* baseCake, const std::string& saying) : CakeDecorator(baseCake), saying(saying) {}

    std::string getName() const override {
        return cake->getName() + " with writing: " + saying;
    }

    int cost() const override {
        return cake->cost() + 2;
    }
};

// New Cake Type: StrawberryCake
class StrawberryCake : public Cake {
public:
    std::string getName() const override {
        return "Strawberry Cake";
    }

    int cost() const override {
        // Twice the cost of a regular cake
        return 2 * RegularCake().cost(); 
    }
};

int main() {
    // Client Code
    Cake* order = new RegularCake();
    order = new MultiLayeredCakeDecorator(order);
    order = new SprinklesDecorator(order);
    order = new SayingDecorator(order, "Happy Birthday Dimpi!");

    std::cout << "Order Details: " << order->getName() << ", Cost: $" << order->cost() << std::endl;

    // Adding a StrawberryCake to the order
    Cake* strawberryCake = new StrawberryCake();
    std::cout << "Strawberry Cake Details: " << strawberryCake->getName() << ", Cost: $" << strawberryCake->cost() << std::endl;

    delete order;
    delete strawberryCake;

    return 0;
}
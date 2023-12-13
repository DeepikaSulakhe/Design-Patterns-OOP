#include <iostream>
#include <string>

// Pizza interface
class Pizza {
public:
    virtual std::string getDescription() const = 0;
    virtual double cost() const = 0;
    virtual ~Pizza() = default;
};

// Concrete implementation of ThinCrustPizza
class ThinCrustPizza : public Pizza {
public:
    std::string getDescription() const override {
        return "Thin crust pizza";
    }

    double cost() const override {
        return 8.0; // Base cost for a thin crust pizza
    }
};

// Concrete implementation of ThickCrustPizza
class ThickCrustPizza : public Pizza {
public:
    std::string getDescription() const override {
        return "Thick crust pizza";
    }

    double cost() const override {
        return 10.0; // Base cost for a thick crust pizza
    }
};

// Decorator for pizza toppings
class ToppingDecorator : public Pizza {
public:
    ToppingDecorator(Pizza* pizza) : pizza(pizza) {}

    std::string getDescription() const override {
        return pizza->getDescription();
    }

    double cost() const override {
        return pizza->cost();
    }

protected:
    Pizza* pizza;
};

// Concrete topping classes
class Cheese : public ToppingDecorator {
public:
    Cheese(Pizza* pizza) : ToppingDecorator(pizza) {}

    std::string getDescription() const override {
        return pizza->getDescription() + ", Cheese";
    }

    double cost() const override {
        return pizza->cost() + 2.0; // Additional cost for cheese
    }
};

class Olives : public ToppingDecorator {
public:
    Olives(Pizza* pizza) : ToppingDecorator(pizza) {}

    std::string getDescription() const override {
        return pizza->getDescription() + ", Olives";
    }

    double cost() const override {
        return pizza->cost() + 1.5; // Additional cost for olives
    }
};

class Peppers : public ToppingDecorator {
public:
    Peppers(Pizza* pizza) : ToppingDecorator(pizza) {}

    std::string getDescription() const override {
        return pizza->getDescription() + ", Peppers";
    }

    double cost() const override {
        return pizza->cost() + 1.0; // Additional cost for peppers
    }
};

int main() {
    // Creating a thin crust pizza with cheese and olives
    Pizza* thinPizza = new ThinCrustPizza();
    thinPizza = new Cheese(thinPizza);
    thinPizza = new Olives(thinPizza);

    std::cout << "Description: " << thinPizza->getDescription() << std::endl;
    std::cout << "Cost: $" << thinPizza->cost() << std::endl;

    // Creating a thick crust pizza with cheese and peppers
    Pizza* thickPizza = new ThickCrustPizza();
    thickPizza = new Cheese(thickPizza);
    thickPizza = new Peppers(thickPizza);

    std::cout << "\nDescription: " << thickPizza->getDescription() << std::endl;
    std::cout << "Cost: $" << thickPizza->cost() << std::endl;

    // Cleanup
    delete thinPizza;
    delete thickPizza;

    return 0;
}

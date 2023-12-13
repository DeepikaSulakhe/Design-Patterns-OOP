#include <iostream>
#include <string>

// Product: Meal
class Meal {
public:
    void setBurger(const std::string& burger) {
        this->burger = burger;
    }

    void setDrink(const std::string& drink) {
        this->drink = drink;
    }

    void setDessert(const std::string& dessert) {
        this->dessert = dessert;
    }

    void display() const {
        std::cout << "Burger: " << burger << "\n";
        std::cout << "Drink: " << drink << "\n";
        std::cout << "Dessert: " << dessert << "\n";
    }

private:
    std::string burger;
    std::string drink;
    std::string dessert;
};

// Builder Interface: MealBuilder
class MealBuilder {
public:
    virtual void buildBurger() = 0;
    virtual void buildDrink() = 0;
    virtual void buildDessert() = 0;
    virtual Meal getMeal() const = 0;
};

// Concrete Builder: VegMealBuilder
class VegMealBuilder : public MealBuilder {
public:
    void buildBurger() override {
        meal.setBurger("Veg Patty Burger");
    }

    void buildDrink() override {
        meal.setDrink("Cold Ice Tea");
    }

    void buildDessert() override {
        meal.setDessert("Cinammon Roll");
    }

    Meal getMeal() const override {
        return meal;
    }

private:
    Meal meal;
};

// Concrete Builder: NonVegMealBuilder
class NonVegMealBuilder : public MealBuilder {
public:
    void buildBurger() override {
        meal.setBurger("Nashville Hot Burger");
    }

    void buildDrink() override {
        meal.setDrink("Coke");
    }

    void buildDessert() override {
        meal.setDessert("Churros");
    }

    Meal getMeal() const override {
        return meal;
    }

private:
    Meal meal;
};

// Director: MealDirector
class MealDirector {
public:
    Meal constructMeal(MealBuilder& builder) {
        builder.buildBurger();
        builder.buildDrink();
        builder.buildDessert();
        return builder.getMeal();
    }
};

int main() {
    // Client code
    MealDirector director;

    VegMealBuilder vegMealBuilder;
    NonVegMealBuilder nonVegMealBuilder;

    Meal vegMeal = director.constructMeal(vegMealBuilder);
    Meal nonVegMeal = director.constructMeal(nonVegMealBuilder);
    std::cout << "Welcome to Starbird!\n";
    std::cout << "Veg Meal:\n";
    vegMeal.display();

    std::cout << "\nNon-Veg Meal:\n";
    nonVegMeal.display();

    return 0;
}
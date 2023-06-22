#include <iostream>
#include <string>

class Pizza {
public:
    void setDough(const std::string& dough) {
        dough_ = dough;
    }

    void setSauce(const std::string& sauce) {
        sauce_ = sauce;
    }

    void setTopping(const std::string& topping) {
        topping_ = topping;
    }

    void serve() const {
        std::cout << "Pizza con masa " << dough_ << ", salsa " << sauce_ << " y topping " << topping_ << std::endl;
    }

private:
    std::string dough_;
    std::string sauce_;
    std::string topping_;
};

class PizzaBuilder {
public:
    virtual void buildDough() = 0;
    virtual void buildSauce() = 0;
    virtual void buildTopping() = 0;
    virtual Pizza* getPizza() = 0;
};

class HawaiianPizzaBuilder : public PizzaBuilder {
public:
    HawaiianPizzaBuilder() {
        pizza_ = new Pizza();
    }

    void buildDough() override {
        pizza_->setDough("suave");
    }

    void buildSauce() override {
        pizza_->setSauce("dulce");
    }

    void buildTopping() override {
        pizza_->setTopping("jamon y pinia");
    }

    Pizza* getPizza() override {
        return pizza_;
    }

private:
    Pizza* pizza_;
};

class SpicyPizzaBuilder : public PizzaBuilder {
public:
    SpicyPizzaBuilder() {
        pizza_ = new Pizza();
    }

    void buildDough() override {
        pizza_->setDough("crujiente");
    }

    void buildSauce() override {
        pizza_->setSauce("picante");
    }

    void buildTopping() override {
        pizza_->setTopping("pepperoni y jalapenios");
    }

    Pizza* getPizza() override {
        return pizza_;
    }

private:
    Pizza* pizza_;
};

class Chef {
public:
    void setPizzaBuilder(PizzaBuilder* builder) {
        builder_ = builder;
    }

    Pizza* getPizza() {
        return builder_->getPizza();
    }

    void constructPizza() {
        builder_->buildDough();
        builder_->buildSauce();
        builder_->buildTopping();
    }

private:
    PizzaBuilder* builder_;
};

int main() {
    Chef chef;

    // Construir una pizza hawaiana
    HawaiianPizzaBuilder hawaiianBuilder;
    chef.setPizzaBuilder(&hawaiianBuilder);
    chef.constructPizza();
    Pizza* hawaiianPizza = chef.getPizza();
    hawaiianPizza->serve();

    // Construir una pizza picante
    SpicyPizzaBuilder spicyBuilder;
    chef.setPizzaBuilder(&spicyBuilder);
    chef.constructPizza();
    Pizza* spicyPizza = chef.getPizza();
    spicyPizza->serve();

    delete hawaiianPizza;
    delete spicyPizza;

    return 0;
}

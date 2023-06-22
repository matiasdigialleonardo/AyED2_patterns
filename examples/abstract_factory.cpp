#include <iostream>

// Abstract products
class Character {
public:
    virtual void display() const = 0;
};

class Weapon {
public:
    virtual void display() const = 0;
};

// Warrior character family
class WarriorCharacter : public Character {
public:
    void display() const override {
        std::cout << "I`m a warrior." << std::endl;
    }
};

class WarriorWeapon : public Weapon {
public:
    void display() const override {
        std::cout << "I`m the warrior`s weapon" << std::endl;
    }
};

// Mage character family
class MageCharacter : public Character {
public:
    void display() const override {
        std::cout << "I`m a mage" << std::endl;
    }
};

class MageWeapon : public Weapon {
public:
    void display() const override {
        std::cout << "I`m the mage`s weapon" << std::endl;
    }
};

// Abstract factory
class CharacterFactory {
public:
    virtual Character* createCharacter() const = 0;
    virtual Weapon* createWeapon() const = 0;
};

// Warrior concrete factory
class WarriorFactory : public CharacterFactory {
public:
    Character* createCharacter() const override {
        return new WarriorCharacter();
    }

    Weapon* createWeapon() const override {
        return new WarriorWeapon();
    }
};

// Mage concrete factory
class MageFactory : public CharacterFactory {
public:
    Character* createCharacter() const override {
        return new MageCharacter();
    }

    Weapon* createWeapon() const override {
        return new MageWeapon();
    }
};

// Client
int main() {
    CharacterFactory* wFactory = new WarriorFactory();

    // Crear personaje y arma utilizando la fábrica seleccionada
    Character* character = wFactory->createCharacter();
    Weapon* weapon = wFactory->createWeapon();

    // Mostrar detalles del personaje y arma
    character->display();
    weapon->display();

    // Liberar memoria
    delete character;
    delete weapon;
    delete wFactory;

    return 0;
}

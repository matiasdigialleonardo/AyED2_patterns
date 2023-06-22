#include <iostream>

class Singleton {
    
    private:
        static Singleton* instance;
        int value;

        Singleton() {
            value = 0;
        }

    public:
        static Singleton* getInstance() {
            if (instance == nullptr) {
                instance = new Singleton();
            }
            return instance;
        }

        int getValue() const {
            return value;
        }

        void setValue(int newValue) {
            value = newValue;
        }
};

Singleton* Singleton::instance = nullptr;

int main() {
    Singleton* instance1 = Singleton::getInstance();
    Singleton* instance2 = Singleton::getInstance();

    // Both instances are the same
    std::cout << "Instance 1 value: " << instance1->getValue() << std::endl;
    std::cout << "Instance 2 value: " << instance2->getValue() << std::endl;

    instance1->setValue(42);

    // The value is updated in both instances
    std::cout << "Instance 1 value: " << instance1->getValue() << std::endl;
    std::cout << "Instance 2 value: " << instance2->getValue() << std::endl;

    return 0;
}

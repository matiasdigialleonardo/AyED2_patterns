#include <iostream>
#include <string>
 using namespace std;

class Chair {
    public:
        virtual void sitOn() = 0;
};

class Sofa {
    public:
        virtual void sitOn() = 0;
};

class Table {
    public:
        virtual void sitAt() = 0;
};

class ModernChair : public Chair {
    public:
        void sitOn() {
            cout << "Sitting on a modern chair." << endl;
        }
};

class VictorianChair : public Chair {
    public:
        void sitOn() {
            cout << "Sitting on a Victorian chair." << endl;
        }
};

class ArcDecoChair : public Chair {
    public:
        void sitOn() {
            cout << "Sitting on an ArcDeco chair." << endl;
        }
};

class ModernSofa : public Sofa {
    public:
        void sitOn() {
            cout << "Sitting on a modern sofa." << endl;
        }
};

class VictorianSofa : public Sofa {
    public:
        void sitOn() {
            cout << "Sitting on a Victorian sofa." << endl;
        }
};

class ArcDecoSofa : public Sofa {
    public:
        void sitOn() {
            cout << "Sitting on an ArcDeco sofa." << endl;
        }
};

class ModernTable : public Table {
    public:
        void sitAt() {
            cout << "Sitting at a modern table." << endl;
        }
};

class VictorianTable : public Table {
    public:
        void sitAt() {
            cout << "Sitting at a Victorian table." << endl;
        }
};

class ArcDecoTable : public Table {
    public:
        void sitAt() {
            cout << "Sitting at an ArcDeco table." << endl;
        }
};

class FurnitureFactory
{
    public:
        virtual Chair* createChair() = 0;
        virtual Sofa* createSofa() = 0;
        virtual Table* createTable() = 0;
};

class ModernFurnitureFactory : public FurnitureFactory
{
    public:
        Chair* createChair()
        {
            return new ModernChair();
        }
        Sofa* createSofa()
        {
            return new ModernSofa();
        }
        Table* createTable()
        {
            return new ModernTable();
        }
};

class ArcDecoFurnitureFactory : public FurnitureFactory
{
    public:
        Chair* createChair()
        {
            return new ArcDecoChair();
        }
        Sofa* createSofa()
        {
            return new ArcDecoSofa();
        }
        Table* createTable()
        {
            return new ArcDecoTable();
        }
};

class VictorianFurnitureFactory : public FurnitureFactory
{
    public:
        Chair* createChair()
        {
            return new VictorianChair();
        }
        Sofa* createSofa()
        {
            return new VictorianSofa();
        }
        Table* createTable()
        {
            return new VictorianTable();
        }
};

int main() {

    FurnitureFactory* f = new VictorianFurnitureFactory();

    Chair* vChair = f->createChair();
    Sofa* vSofa = f->createSofa();
    Table* vTable = f->createTable();

    vChair->sitOn();
    vSofa->sitOn();
    vTable->sitAt();

    delete vChair;
    delete vSofa;
    delete vTable;
    delete f;

    return 0;
}
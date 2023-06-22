#include <iostream>

class Shape {
public:
    virtual void draw() const = 0;
    virtual Shape* clonar() const = 0;
};

class Rectangle : public Shape {
private:
    int width;
    int height;

public:
    Rectangle(int width, int height) : width(width), height(height) {}

    void draw() const override {
        std::cout << "Dibujando un rectángulo con ancho: " << width << ", alto: " << height << std::endl;
    }

    Shape* clonar() const override {
        return new Rectangle(*this);
    }
};

class Circle : public Shape {
private:
    int radius;

public:
    Circle(int radius) : radius(radius) {}

    void draw() const override {
        std::cout << "Dibujando un círculo con radio: " << radius << std::endl;
    }

    Shape* clonar() const override {
        return new Circle(*this);
    }
};

int main() {
    // Crear un rectángulo
    Shape* rectangle = new Rectangle(10, 5);
    rectangle->draw();

    // Clonar el rectángulo
    Shape* clonedRectangle = rectangle->clonar();
    clonedRectangle->draw();

    delete rectangle;
    delete clonedRectangle;

    // Crear un círculo
    Shape* circle = new Circle(5);
    circle->draw();

    // Clonar el círculo
    Shape* clonedCircle = circle->clonar();
    clonedCircle->draw();

    delete circle;
    delete clonedCircle;

    return 0;
}
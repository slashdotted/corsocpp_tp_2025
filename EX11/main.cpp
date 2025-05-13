#include <cassert>

// Declare a scoped enumeration Color with values RED, GREEN, BLUE, YELLOW
enum class Color { RED, GREEN, BLUE, YELLOW };

// Define an interface IColored which declares two methods
// Color getColor() const
// void setColor(Color c)
struct IColored
{
    virtual Color getColor() const = 0;
    virtual void setColor(Color c) = 0;
};

// Define an interface IShape which declares two methods
//	double area() const
//	double  perimeter() const
struct IShape
{
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
};

// Create a concrete class named Rectangle which implements both the
// IShape and the IColored interfaces.
// Add the necessary fields to store the required information (which can be set using the constructor).
struct Rectangle : public IShape, public IColored
{
    Rectangle(double b, double h, Color c)
        : m_b{b}
        , m_h{h}
        , m_c{c}
    {}

    Color getColor() const override { return m_c; }

    void setColor(Color c) override { m_c = c; }
    double area() const override { return m_b * m_h; }

    double perimeter() const override { return m_b * 2 + m_h * 2; }

private:
    double m_b, m_h;
    Color m_c;
};

// Write some test code to verify your implementation.
int main()
{
    Rectangle r{10, 5, Color::RED};
    assert(r.getColor() == Color::RED);
    r.setColor(Color::BLUE);
    assert(r.getColor() == Color::BLUE);
    assert(r.area() == 50);
    assert(r.perimeter() == 30);
}

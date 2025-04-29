#include <iostream>

struct Animal
{
    Animal(const std::string &name, const std::string &sound)
        : m_name{name}
        , m_sound{sound}
    {}

    virtual void makeSound() const { std::cout << "Animal " << m_name << '\n'; }

private:
    std::string m_name;
    std::string m_sound;
};

struct Dog : public Animal
{
    Dog(const std::string &name)
        : Animal{name, "Woof"}
    {}

    void makeSound() const override
    {
        std::cout << "I'm a dog... I'm an ";
        Animal::makeSound();
    }
};

struct Cat : public Animal
{
    Cat(const std::string &name)
        : Animal{name, "Meow"}
    {}

    void makeSound() const override
    {
        std::cout << "I'm a cat... I'm an ";
        Animal::makeSound();
    }
};

void printAnimalSound(const Animal *animal)
{
    animal->makeSound();
}

void printAnimalSound(const Animal &animal)
{
    animal.makeSound();
}

void printAnimalSound2(Animal animal)
{
    animal.makeSound();
}

int main()
{
    Animal spaturno{"Giobbe", "#!*çç*ç"};
    Dog dog{"Laika"};
    Cat cat{"Tom"};
    printAnimalSound(&spaturno);
    printAnimalSound(&dog);
    printAnimalSound(&cat);

    printAnimalSound(spaturno);
    printAnimalSound(dog);
    printAnimalSound(cat);

    printAnimalSound2(spaturno);
    printAnimalSound2(dog);
    printAnimalSound2(cat);
    return 0;
}

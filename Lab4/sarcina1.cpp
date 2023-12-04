#include <iostream>
#include <string>

class Person {
protected:
    std::string name;
    int age;

public:
    Person(){
        name = "";
        age = 0;
    }
    Person(const std::string& name, int age)
        : name(name), age(age) {}

    // citire
    friend std::istream& operator>>(std::istream& in, Person& Person) {
        std::cout << "Introduceti numele: ";
        in >> Person.name;
        std::cout << "Introduceti varsta: ";
        in >> Person.age;
        return in;
    }

    // afisare
    friend std::ostream& operator<<(std::ostream& out, const Person& Person) {
        out << "name: " << Person.name << ", age: " << Person.age;
        return out;
    }

    // copiere
    Person(const Person& other)
        : name(other.name), age(other.age) {}

    // atribuire
    Person& operator=(const Person& other) {
        if (this != &other) {
            name = other.name;
            age = other.age;
        }
        return *this;
    }
};

class Colaborator : public Person {
private:
    std::string post;
    double salariu;

public:
    Colaborator(){
        
    }
    Colaborator(const std::string& name, int age, const std::string& post, double salariu)
        : Person(name, age), post(post), salariu(salariu) {}

    friend std::istream& operator>>(std::istream& in, Colaborator& colaborator) {
        in >> static_cast<Person&>(colaborator); 
        std::cout << "Introduceti postul: ";
        in >> colaborator.post;
        std::cout << "Introduceti salariul: ";
        in >> colaborator.salariu;
        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, const Colaborator& colaborator) {
        out << static_cast<const Person&>(colaborator) << ", Post: " << colaborator.post << ", Salariu: " << colaborator.salariu;
        return out;
    }

    Colaborator(const Colaborator& other)
        : Person(other), post(other.post), salariu(other.salariu) {}

    Colaborator& operator=(const Colaborator& other) {
        if (this != &other) {
            Person::operator=(other);
            post = other.post;
            salariu = other.salariu;
        }
        return *this;
    }
};

int main() {
    Colaborator colaborator1("Ana", 30, "Programator", 5000.0);

    std::cout << "Informatii despre colaborator:\n" << colaborator1 << "\n\n";

    Colaborator colaborator2;
    std::cin >> colaborator2;

    std::cout << "Colaboratorul introdus:\n" << colaborator2 << "\n";

    return 0;
}

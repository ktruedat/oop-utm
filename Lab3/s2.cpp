#include <iostream>

struct ListItem {
    int data;
    ListItem* next;

    ListItem(int value) : data(value), next(nullptr) {}
};

class List {
private:
    ListItem* head; 

public:
    List() : head(nullptr) {}

    List(const List& other) {
        head = nullptr;
        ListItem* otherCurrent = other.head;
        while (otherCurrent) {
            push_back((*otherCurrent).data);   // otherCurrent->data
            otherCurrent = otherCurrent->next;
        }
    }

    ~List() {
        clear();
    }

    void clear() {
        this->~List();
        while (head) {
            ListItem* temp = head;
            head = head->next;
            delete temp;
        }
    }

    List& operator=(const List& other) {
        if (this != &other) {
            clear(); 
            ListItem* otherCurrent = other.head;
            while (otherCurrent) {
                push_back(otherCurrent->data);
                otherCurrent = otherCurrent->next;
            }
        }
        return *this;
    }

    List operator+(const List& other) const {
        List result = *this; 
        ListItem* otherCurrent = other.head;
        while (otherCurrent) {
            result.push_back(otherCurrent->data);
            otherCurrent = otherCurrent->next;
        }
        return result;
    }

    friend bool operator==(const List& lhs, const List& rhs) {
        ListItem* lhsCurrent = lhs.head;
        ListItem* rhsCurrent = rhs.head;
        while (lhsCurrent && rhsCurrent) {
            if (lhsCurrent->data != rhsCurrent->data) {
                return false;
            }
            lhsCurrent = lhsCurrent->next;
            rhsCurrent = rhsCurrent->next;
        }
        return lhsCurrent == nullptr && rhsCurrent == nullptr;
    }

    friend bool operator!=(const List& lhs, const List& rhs) {
        return !(lhs == rhs);
    }

    friend bool operator<(const List& list1, const List& list2) {
        ListItem* current1 = list1.head;
        ListItem* current2 = list2.head;

        while (current1 != nullptr && current2 != nullptr) {
            if (current1->data < current2->data) {
                return true;
            } else if (current1->data > current2->data) {
                return false;
            }
            current1 = current1->next;
            current2 = current2->next;
        }

        return (current1 != nullptr && current2 == nullptr);
    }

    friend bool operator>(const List& list1, const List& list2) {
        return !(list1 < list2) && (list1 != list2);
    }

    friend std::ostream& operator<<(std::ostream& os, const List& list) {
        ListItem* current = list.head;
        while (current) {
            os << current->data << " ";
            current = current->next;
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, List& list) {
        int value;
        is >> value;
        list.push_back(value);
        return is;
    }

    void push_back(int value) {
        ListItem* newItem = new ListItem(value);
        if (!head) {
            head = newItem;
        } else {
            ListItem* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newItem;
        }
    }

   
};

int main() {
    List list1, list2;
    

    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);

    std::cout << "List1: " << list1 << std::endl;
    List list3(list1);
    std::cout << "List3: " << list3 << std::endl;

    list2.push_back(4);
    list2.push_back(5);

    std::cout << "List2: " << list2 << std::endl;

    List sumList = list1 + list2;

    std::cout << "Suma listelor: " << sumList << std::endl;

    if (list1 == list2) {
        std::cout << "List1 este egal cu List2." << std::endl;
    } else {
        std::cout << "List1 nu este egal cu List2." << std::endl;
    }
    if (list1 == list3) {
        std::cout << "List1 este egal cu List3." << std::endl;
    } else {
        std::cout << "List1 nu este egal cu List3." << std::endl;
    }

    if (list1 != list3) {
        std::cout << "List1 este diferit de List3." << std::endl;
    } else {
        std::cout << "List1 nu este diferit de List3." << std::endl;
    }

    if (list1 < list2) {
        std::cout << "List1 este mai mic decat List2." << std::endl;
    } else {
        std::cout << "List1 nu este mai mic decat List2." << std::endl;
    }

    if (list1 > list2) {
        std::cout << "List1 este mai mare decat List2." << std::endl;
    } else {
        std::cout << "List1 nu este mai mare decat List2." << std::endl;
    }

    std::cout << "Introduceti un element pentru adaugare in lista: ";
    std::cin >> list1;
    std::cout << "Lista dupa adaugare: " << list1 << std::endl;

    return 0;
}

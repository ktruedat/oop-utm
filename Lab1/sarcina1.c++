#include <iostream>
#include <cstring>
#include <ostream>

struct Country{
    private:
        char*  name;
        char continent[50];
        int population;
    public:
        Country(const char* name, const char* continent, int population){
            this->name = new char[strlen(name)+1];
            strcpy(this->name, name);
            strcpy(this->continent, continent);
            this->population = population;
        }

        ~Country(){
            delete[] name;
        }

        void setName(const char* name){
            delete[] name;
            this->name = new char[strlen(name) + 1];
            strcpy(this->name, name);
        }

        void setContinent(const char* continent){
            strcpy(this->continent, continent);
        }

        void setPopulation(int population){
            this->population = population;
        }

        bool compare(const Country& country){
            return strcmp(this->name, country.name) == 0 && strcmp(this->continent, country.continent) == 0 && this->population == country.population;
        }
};

int main(){
    Country Romania("Romania", "Europa", 100000);
    Country Germania("Germania", "Europa", 100000);

    if(Romania.compare(Germania)){
        std::cout << "Tari identice" << std::endl;
    } else{
        std::cout << "Tari diferite" <<std::endl;
    }
    return 0;
};

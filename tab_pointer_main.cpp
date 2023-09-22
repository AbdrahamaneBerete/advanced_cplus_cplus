#include <iostream>

class Building {
public:
    Building() : id_(-1) {
        std::cout << "Building::Building() at " << this << std::endl;
    }
    
    Building(int identifier) : id_(identifier) {
        std::cout << "Building::Building(" << id_ << ") at " << this << std::endl;
    }
    
    Building(const Building& rhs) : id_(rhs.id_) {
        std::cout << "Building::Building(rhs = " << &rhs << ", id_ = " << rhs.id_ << ") at " << this << std::endl;
    }
    
    ~Building() {
        std::cout << "Building::~Building() " << id_ << " at " << this << std::endl;
    }
    
    Building& operator=(const Building& rhs) {
        std::cout << "Building::operator=(" << rhs.id_ << ") at this = " << this << std::endl;
        if (&rhs != this) {
            id_ = rhs.id_;
        }
        return *this;
    }
    
    void print(std::ostream& out) const {
        out << "Building " << id_ << " at " << this << std::endl;
    }
    
private:
    int id_;
};

int main(int argc, char** argv) {
    std::cout << "Welcome to SimTown! Please enter the street size" << std::endl;
    
    int size = 0;
    std::cin >> size;
    
    Building** street = new Building*[size];
    std::cout << "Street address = " << street << std::endl;
    
    for (int ib = 0; ib < size; ++ib) {
        street[ib] = new Building(ib);
    }
    
    // Resize array
    
    Building** bigger_street = new Building*[size + 1];
    for (int i = 0; i < size; ++i) {
        bigger_street[i] = street[i];
    }
    delete[] street;
    size += 1;
    street = bigger_street;
    
	{
    Building city_hall(1000);
    Building* new_city_hall = new Building(city_hall);// Test copy Constructeur
    street[size - 1] = new_city_hall;
    }
    
   
    for (int i = 0; i < size; ++i) {
        
        if (street[i] != nullptr) {

           street[i]->print(std::cout);
        }
        
    }

    for (int i = 0; i < 10; ++i) {
        delete street[i];  // Deallocate individual Building objects
    }
    
    delete[] street;  // Deallocate the array of Building pointers
    
    std::cout << "Done" << std::endl;
    return 0;  // Normal termination
}

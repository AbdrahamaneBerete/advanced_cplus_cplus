#ifndef sim_town_building_h
#define sim_town_building_h
#include <iostream>

// forward declaration
class Storey;

class Building {
public: 
    Building() : id_( -1 ), storeys_(nullptr), nb_storeys_(0) {
        std::cout << "Building::Building() at " << this << std::endl;
    }
    Building( int identifier, int nb_floors=1); 

    Building( const Building& rhs ); 

    Storey& create_and_add_storey();

    ~Building();

    // Overloading the assignment operator for traceability
    Building& operator=( const Building& rhs );

    friend std::ostream& operator<<( std::ostream& out, const Building& building );
private: 
    // Copies nb_storeys_
    void clone_storeys( Storey* to, const Storey* from );
    int id_;
    Storey* storeys_;
    int nb_storeys_;
};

#endif

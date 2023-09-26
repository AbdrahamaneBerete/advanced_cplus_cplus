#ifndef sim_town_storey_h
#define sim_town_storey_h
#include <iostream>
class Storey {
public:
    Storey() : source_( serial_number_ ), uid_( serial_number_ ) {
	++serial_number_;
        std::cout << "Storey::Storey(): id = source = " 
	    << uid_ << " at " << this << std::endl;
    }
    Storey( const Storey& rhs );
    ~Storey() {
        std::cout << "Storey::~storey() " << this << std::endl;
    };
    Storey& operator=( const Storey& rhs );
    friend std::ostream& operator<<( std::ostream& out, const Storey& storey ); // not a member function, friend to access private members
private:
    int source_; // non fongible token
    int uid_; // unique identifier.
    static int serial_number_; 
};

#endif
#include <iostream>
#include <Building.h>
#include <Storey.h>

Building::Building( int identifier, int nb_floors ) 
    : id_( identifier ), storeys_(nullptr), nb_storeys_(nb_floors) {
		std::cout << "Building::Building( " << id_ << " ) at " << this << std::endl;
		storeys_ = new Storey[nb_storeys_];
    }

Building::Building( const Building& rhs ) 
    : id_( rhs.id_ ), storeys_( new Storey [rhs.nb_storeys_] ), nb_storeys_( rhs.nb_storeys_ ) {
	std::cout << "Building::Building( rhs = " 
	    << &rhs << ", id_ " << rhs.id_ << " ) at " << this << std::endl;
	clone_storeys( storeys_, rhs.storeys_ );
}

Building::~Building() {
    std::cout << "Building::~Building() " << id_ << " at " << this << std::endl;
    delete[] storeys_;
}

Storey& Building::create_and_add_storey() {
    Storey* new_storeys = new Storey[ nb_storeys_ + 1];
    clone_storeys( new_storeys, storeys_ );
    delete[] storeys_;
    ++nb_storeys_;
    return storeys_[nb_storeys_-1];
}

Building& Building::operator=( const Building& rhs ) {
    std::cout << "Building::operator=( " << rhs.id_ << " ) at this = " << this << std::endl;
    if( &rhs != this ) {
	if( nb_storeys_ != rhs.nb_storeys_ ) { // no need to reallocate if same size
	    delete[] storeys_; // cleanup
	    nb_storeys_ = rhs.nb_storeys_;
	    storeys_ = new Storey[ nb_storeys_ ];
	}
	id_ = rhs.id_;
	clone_storeys( storeys_, rhs.storeys_ );
    }
    return *this;
}

std::ostream& operator<<( std::ostream& out, const Building& building ) {
    out << " ==       Building " << &building << ", id_=" 
	    << building.id_ << "        == \n" ;
    for( int istor = 0; istor < building.nb_storeys_; ++ istor ) {
		out << " ===== " << building.storeys_[istor] << " ===== \n";
    }

    return out;
}

void Building::clone_storeys( Storey* to, const Storey* from ) {
    for( int istor = 0; istor < nb_storeys_; ++istor ) {
		to[istor] = from[istor];
    }
}

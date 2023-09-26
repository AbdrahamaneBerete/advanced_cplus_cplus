#include <iostream>
#include <Building.h>
#include <dyn_array.h>

int main( int argc, char** argv ) {
    std::cout << " Welcome to SimTown! Please enter the street size"
	<< std::endl;
    int size = 0;
    std::cin >> size;

    DynArray<Building> street(size);

    std::cout << "Street adress = " << &street << std::endl; 
    for( int ib = 0 ; ib < size; ++ ib ) {
		street[ib] = Building( ib, 2*ib );
    }

    // Resize array. 
    Building city_hall(1000);
    street.push_back( city_hall ); 

    for( int i = 0 ; i < street.size(); ++ i ) {
		std::cout << street[i] << std::endl;
    }
	

    std::cout << "Done" <<std::endl;
    return 0;
}





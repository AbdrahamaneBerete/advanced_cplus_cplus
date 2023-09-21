#include <iostream>
#include <string>


class Building {
	public:
		Building(): id_(-1) {
			std::cout<< "Building::Building () at " << this << std::endl;
		}
		Building(int identifier) : id_(identifier) {
			std::cout<< "Building::Building(" << id_ << ") at " << this << std::endl;
		}	
		~Building() {
			std::cout << "Building::~Building() " << id_ << " at " << this << std::endl;
		}
		
		Building& operator=( const Building& rhs) {
			std::cout << "Building::operator=( " << rhs.id_ << ") at this = " << this << std::endl;
			if(&rhs != this) {
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



int main( int argc, char** argv ) {
        std::cout << "welcome to SimTown! Please enter the street size " << std::endl;
	
	int size = 0;
	std::cin>> size;
	
	Building** street = new Building* [size];
	std::cout << "Street adress = " << street << std::endl;
	for(int ib=0; ib<size; ++ib) {
		street[ib] = new Building( ib);
	}	
	
	for(int i=0; i<10 ; ++i) {
		if(street[i] != nullptr) {
			street[i]->print(std::cout);
		}	

	}
	for(int i=0; i<10; ++i) {
		delete street[i];
	}
	delete[] street;

	std::cout << "Done" << std::endl;
	return 0; // Normal termination
}




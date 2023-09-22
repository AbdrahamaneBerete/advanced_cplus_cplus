#include <iostream>
#include <string>

class Storey {
	public:
		Storey() : source_(serial_number_), uid_(serial_number_) {
			++serial_number_;
			std::cout <<" Storey::Storey() : id = source = " << uid_ << " at " << this << std::endl;
		}	
		Storey(const Storey& rhs);
		~Storey() {
			std::cout << "Storey::~Storey() at  " << this << std::endl;

		};	
		Storey& operator=(const Storey& rhs);
		friend std::ostream& operator<<(std::ostream& out, const Storey& rhs);
	private:
		int source_;
		int uid_;// unique identifier
		static int serial_number_; //constant value for all objects of the class
};
int Storey::serial_number_ = 1;
Storey::Storey( const Storey& rhs ) : source_( rhs.source_), uid_( serial_number_) {
	std::cout << " Storey:: Storey( rhs = id = " << rhs.uid_ << " ), uid = " << uid_ << " at " << this << std::endl;
        serial_number_ += 1;
}
Storey& Storey::operator=( const Storey& rhs) {
	if( this != &rhs) {
		source_ = rhs.source_;
		uid_ = serial_number_;
		serial_number_ +=1;
	}
	return *this;
}
std::ostream& operator << (std::ostream& out, const Storey& rhs) {
	out << " --Storey " << &rhs << " : id=" << rhs.uid_ << ", NFT=" << rhs.source_;
	return out;
}	
class Building {
	public:
		Building(): id_(-1), storeys_(nullptr), nb_storeys_(0) {
			std::cout<< "Building::Building () at " << this << std::endl;
		}
		Building(int identifier, int nb_floors=1) : id_(identifier), storeys_(nullptr)
							    ,nb_storeys_(nb_floors) 
         	{
			std::cout<< "Building::Building(" << id_ << ") at " << this << std::endl;
			storeys_ = new Storey[nb_floors];
		}
		Building(const Building& rhs) : id_( rhs.id_), storeys_(nullptr), nb_storeys_(rhs.nb_storeys_) {
			std::cout << "Building::Building( rhs = " << &rhs << ", id_ = " << rhs.id_ << ") at " << this << std::endl; 
                       storeys_ = new Storey[nb_storeys_];
			for(int i=0; i<nb_storeys_; i++) {
				storeys_[i] = rhs.storeys_[i];
			}
			std::cout << " copy done " << std::endl;
		}
		~Building() {
			std::cout << "Building::~Building() " << id_ << " at " << this << std::endl;
			delete[] storeys_;
		}
		
		Building& operator=( const Building& rhs) {
			std::cout << "Building::operator=( " << rhs.id_ << ") at this = " << this << std::endl;
			if(&rhs != this) {
				if( nb_storeys_ != rhs.nb_storeys_) {//need to reallocate
				   delete[] storeys_;//cleanup
				   nb_storeys_ = rhs.nb_storeys_;
				   storeys_ = new Storey[ nb_storeys_];
				}  

				id_ = rhs.id_;
				for(int i=0; i<nb_storeys_; ++i) {
					storeys_[i] = rhs.storeys_[i];
				}	
			}	
			return *this;

		}		
		void print(std::ostream& out) const {
			out << "Building " << id_ << " at " << this << std::endl;
		}	
	private:
		int id_;
		Storey* storeys_;
		int nb_storeys_;

};



int main( int argc, char** argv ) {
        std::cout << "welcome to SimTown! Please enter the street size " << std::endl;
	
	int size = 0;
	std::cin>> size;
	
	Building* street = new Building [size];
	std::cout << "Street adress = " << street << std::endl;
	for(int ib=0; ib<size; ++ib) {
		street[ib] =  Building( ib);
	}	
	
	// Resize array
	{
	Building* bigger_street = new Building [size +1];
	for( int i =0 ; i < size; ++i) {
		bigger_street[i] = street[i];
	}
	delete [] street;
	size += 1;
	street = bigger_street;
	}
	{
	Building city_hall(1000);
	Building new_city_hall(city_hall);
	street[size-1] = new_city_hall;
	}
	for(int i=0; i<10 ; ++i) {
		
		street[i].print(std::cout);	

	}
	delete[] street;

	std::cout << "Done" << std::endl;
	Storey step_2;
	std::cout << step_2 ;
	return 0; // Normal termination
}




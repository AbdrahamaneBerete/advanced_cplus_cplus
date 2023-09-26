#include <iostream>
#include <Storey.h>

int Storey::serial_number_ = 1;
Storey::Storey( const Storey& rhs ) : source_( rhs.source_), uid_( serial_number_ ) {
    std::cout << "Storey::Storey( rhs = id = " << rhs.uid_ 
	<< " ), uid = " << uid_ << " at " << this << std::endl;
    serial_number_ += 1;
}
Storey& Storey::operator=( const Storey& rhs ) {
    std::cout << "Storey::operator=( rhs = " << rhs << ") on " << *this << std::endl;
    if( this != &rhs ) {
		source_ = rhs.source_;
		uid_ = serial_number_;
		serial_number_ += 1;
    }
    return *this;
}
std::ostream& operator<<( std::ostream& out, const Storey& storey ) {
    out << "  --Storey " << &storey << ": id=" << storey.uid_ << ", NFT=" << storey.source_;
    return out;
}


	
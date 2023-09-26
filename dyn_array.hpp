#include <assert.h>

template <class T> DynArray <T>::DynArray( int size ) :
    capacity_( (size > 0) ? size : 1), 
    size_( size ) {
		elems_ = new T [capacity_];
		assert( size > -1 );//debug
}

template <class T> DynArray <T>::~DynArray() {
    delete[] elems_;
}

template <class T> T& DynArray <T>::push_back( const T& element ) {
    if( size_ == capacity_ ) {
		grow();
    }
    elems_[size_] = element;
	++size_;
    return elems_[size_];
}

template <class T> T& DynArray <T>::operator[] ( int index ) {
    assert( index < size_ && index >=0 );
    return elems_[index];
}

template <class T> const T& DynArray <T>::operator[]( int index ) const {
    assert( index < size_ && index >=0 );
    return elems_[index];
}

template <class T> void DynArray <T>::grow() {
    capacity_ *=2;
    T* new_elements = new T [capacity_];
    for( int i = 0; i < size_; ++i ) {
		new_elements[i] = elems_[i];
    }
    delete[] elems_;
    elems_ = new_elements;
}
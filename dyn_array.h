#ifndef sim_town_dyn_array_h
#define sim_town_dyn_array_h

// A minimal sequential container
template <class T> class DynArray {
public:
    // Creates an array with size default elements.  
    DynArray( int size );
    ~DynArray();

    inline int size() const { return size_; }

    T& push_back( const T& element );

    T& operator[]( int index );
    const T& operator[]( int index ) const;
    
private:
    void grow();
    int capacity_;
    int size_;
    T* elems_;
};

#include <dyn_array.hpp>

#endif
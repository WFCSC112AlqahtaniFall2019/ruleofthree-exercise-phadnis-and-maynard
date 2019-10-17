//
// Created by Ryan Phadnis on 10/17/19.
//
#include <iostream>
#include "IntList.h"
using namespace std;

IntList::IntList ( int size  , int initvalue) {
    if( size > 0){
        list_ = new int[ size ];
        size_ = size ;
        for( int i = 0; i < size_ ; i ++)
            list_ [i] = initvalue ;
    }
    else {
        list_ = 0;
        size_ = 0;
    }

}

//1) write a definition for the destructor
IntList::~IntList()
{
    delete []list_;
}

//2) fix the copy constructor
IntList :: IntList ( const IntList & L ){
    //list_ = L . list_ ;
    size_ = L.size_;

    list_ = new int[size_];
    for(int i = 0; i < size_; i++)
    {
        *(list_ + i) = *(L.list_ + i);
    }
}

//3) rewrite the copy assignment operator using an optimized method
IntList& IntList:: operator =( const IntList & rhs ){
    /*if( list_ )
        delete [] list_ ;
    size_ = rhs . size_ ;
    if( rhs . size_ > 0){
        list_ = new int [ rhs . size_ ];
        for ( int i = 0; i < rhs . size_ ; i ++)
            list_ [ i ] = rhs . list_ [ i ];
    }
    else
        list_ = 0; */
    if(this != &rhs)
    {
        cout << "Running copy assignment operator" << endl;
        delete [] list_;
        list_ = new int;
        *list_ = *(rhs.list_);
    }

    return *this;
}

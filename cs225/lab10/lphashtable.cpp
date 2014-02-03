/*
   Linear-Probing Based Hash Table (Lab 10)
   Created by Chase Geigle for CS225, Spring 2011
*/

#include "lphashtable.h"

template <class K, class V>
LPHashTable<K,V>::LPHashTable( int tsize, Hash<K> & hash ) : HashTable<K,V>(hash) {
    if( tsize <= 0 )
        tsize = 16;
    table = new pair<K,V>*[tsize];
    for( int i = 0; i < tsize; i++ )
        table[i] = NULL;
    size = tsize;
    elems = 0;
}

template <class K, class V>
LPHashTable<K,V>::~LPHashTable() {
    for( int i = 0; i < size; i++ )
        delete table[i];
    delete [] table;
}

template <class K, class V>
LPHashTable<K,V> const & LPHashTable<K,V>::operator=( LPHashTable const & rhs ) {
    if( this != &rhs ) {
        for( int i = 0; i < size; i++ )
            delete table[i];
        delete [] table;

        table = new pair<K,V>*[rhs.size];
        for( int i = 0; i < rhs.size; i++ ) {
            if( rhs.table[i] == NULL )
                table[i] = NULL;
            else
                table[i] = new pair<K,V>( *(rhs.table[i]) );
        }
        size = rhs.size;
        elems = rhs.elems;
    }
    return *this;
}

template <class K, class V>
LPHashTable<K,V>::LPHashTable( LPHashTable<K,V> const & other ) : HashTable<K,V>(other.hash) {
    table = new pair<K,V>*[other.size];
    for( int i = 0; i < other.size; i++ ) {
        if( other.table[i] == NULL )
            table[i] = NULL;
        else
            table[i] = new pair<K,V>( *(other.table[i]) );
    }
    size = other.size;
    elems = other.elems;
}

template <class K, class V>
void LPHashTable<K,V>::insert( K const & key, V const & value ) {
    // your code here
    // remember to resize the table when necessary!
    int idx=hash(key, size);
 
    while(table[idx]!=NULL)
    {
    idx++;
    }
    table[idx]=new pair<K,V>(key, value);

    
}

template <class K, class V>
void LPHashTable<K,V>::remove( K const & key ) {
    int idx = hash( key, size );
    while( table[idx] != NULL ) {
        if( table[idx]->first == key ) {
            delete table[idx];
            table[idx] = NULL;
            elems--;
            break;
        }
        idx = ( idx + 1 == size ) ? 0 : idx + 1;
    }
}

template <class K, class V>
V LPHashTable<K,V>::find( K const & key ) const {
    int idx = hash( key, size );
    while( table[idx] != NULL ) {
        if( table[idx]->first == key )
            return table[idx]->second;
        idx = ( idx + 1 == size ) ? 0 : idx + 1;
    }
    return V();
}

template <class K, class V>
bool LPHashTable<K,V>::keyExists( K const & key ) const {
    int idx = hash( key, size );
    while( table[idx] != NULL ) {
        if( table[idx]->first == key )
            return true;
        idx = ( idx + 1 ) % size;
    }
    return false;
}

template <class K, class V>
void LPHashTable<K,V>::clear() {
    for( int i = 0; i < size; i++ )
        delete table[i];
    delete [] table;
    table = new pair<K,V>*[16];
    size = 16;
    elems = 0;
}

template <class K, class V>
void LPHashTable<K,V>::resizeTable() {
    pair<K,V> ** temp = new pair<K,V>*[size * 2];
    for( int i = 0; i < size * 2; i++ )
        temp[i] = NULL;

    for( int i = 0; i < size; i++ ) {
        if( table[i] != NULL ) {
            int idx = hash( table[i]->first, size * 2 );
            while( temp[idx] != NULL )
                idx = ( idx + 1 == size ) ? 0 : idx + 1;
            temp[idx] = table[i];
        }
    }

    delete [] table;
    // don't delete elements since we just moved their pointers around
    table = temp;
    size *= 2;
}

template <class K, class V>
vector< pair<K,V> > LPHashTable<K,V>::vectorize() const {
    vector< pair<K,V> > ret;
    for( int i = 0; i < size; i++ ) {
        if( table[i] != NULL )
            ret.push_back( *table[i] );
    }
    return ret;
}

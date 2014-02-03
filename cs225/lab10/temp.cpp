template <class K, class V>
void SCHashTable<K,V>::remove( K const & key ) {
    
    bool x;
    x=keyExists(key);
    int idx = hash( key, size );
    typename list< pair<K,V> >::iterator it;
   
    if(x)
    {
     for( it = table[idx].begin(); it != table[idx].end(); it++ ) {
        if( it->first == key ) break;
      }
	 table[idx].erase(it);
    }
    
    // your code here
    // notes: you do not need to shrink the hash table
    //        you should read the note in the spec about "List Iterators"
}

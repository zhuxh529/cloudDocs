 if( this != &rhs ) {
        delete [] table;
        table = new list< pair<K,V> >[rhs.size];
        for( int i = 0; i < rhs.size; i++ )
            table[i] = rhs.table[i];
        size = rhs.size;
        elems = rhs.elems;
        hash = rhs.hash;
    }
    return *this;










///////////////////////////////////////////////////////////////////////
	 TextFile infile( filename );
    StringHash hasher;
    LPHashTable<string, int> hashTable(256, hasher);
    while( infile.good() ) {
        string word = infile.getNextWord();
        string temp;
        for( int i = 0; i < word.length(); i++ ) {
         
         if(!isspace(word[i])) {
temp.push_back(word[i]);
cout<<temp<<endl;
}
         else 
         {
            int val = 0;
            if( hashTable.keyExists( temp) )
                val = hashTable.find( temp ); 
            hashTable.remove( temp );
            hashTable.insert( temp, val + 1 );
			   temp.clear();
 				cout<<val<<"  ";
			}
        }
    }
    vector< pair<string, int> > vect = hashTable.vectorize();
   
    for( unsigned int i = 0; i < vect.size(); i++ ) {
        if( vect[i].second >= threshold )
            ret.push_back( vect[i] );
    }
	


///////////////////////////////////////////////////////////////////////



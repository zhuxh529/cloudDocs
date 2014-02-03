/*
   Word Frequency Counter (Lab 10)
   Created by Chase Geigle for CS225, Spring 2011
*/

#include "word_counter.h"

WordFreq::WordFreq( string infile ) : filename(infile) { /* nothing */ }

vector< pair<string, int> > WordFreq::getWords( int threshold ) {
  
    // your code here!
    // note: see char_counter.cpp if you're having trouble.
   

///////////////////////////////////////////////////////////////////////
	 TextFile infile( filename );
    StringHash hasher;
    LPHashTable<string, int> hashTable(33000, hasher);
int her=0;
int the=0;
    while( infile.good() ){
        string word = infile.getNextWord();
     //   string temp;
     /*   for( int i = 0; i < word.length(); i++ ) {
         if(!isspace(word[i])) {
temp.push_back(word[i]);
cout<<temp<<endl;
}
        }*/
           int val = 0;
				//temp=word;
            if( hashTable.keyExists( word) ) 
           {val = hashTable.find( word ); }

            hashTable.remove( word );
        
            hashTable.insert( word,  val + 1 );
			   //temp.clear();
           if(word=="her") her++;
			 if(word=="the") the++;
               
 				
    }
   // cout<<her<<"   "<<the<<endl;
      vector< pair<string, int> > ret;
    vector< pair<string, int> > vect = hashTable.vectorize();
   
    for( unsigned int i = 0; i < vect.size(); i++ ) {
        if( vect[i].second >= threshold )
            ret.push_back( vect[i] );
    }
	


///////////////////////////////////////////////////////////////////////

	
    return ret;
}

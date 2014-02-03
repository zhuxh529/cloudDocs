/*
   Anagram Finder (Lab 10)
   Created by Chase Geigle for CS225, Spring 2011
*/

#include "anagram_finder.h"

AnagramFinder::AnagramFinder( string ifile ) : file(true), filename(ifile) {
    /* nothing */
}

AnagramFinder::AnagramFinder( vector<string> istrings ) : file(false),
    strings(istrings) {
    /* nothing */
}

bool AnagramFinder::checkWord( string const & word, string const & test ) {
    // your code here!
    LetterHash hasher;
    SCHashTable<char, int> hashTable(256, hasher);
int val;
    for( int i = 0; i < word.length(); i++ ) {
             val = 0;
            if( hashTable.keyExists( word[i] ) )
                val = hashTable.find( word[i] ); 
            hashTable.remove( word[i] );
            hashTable.insert( word[i], val + 1 );
           }

    for( int i = 0; i < test.length(); i++ ) {
            if(!hashTable.keyExists( test[i] )) return false;
            
            if( hashTable.keyExists( test[i] ) )
                val = hashTable.find( test[i] ); 
            hashTable.remove( test[i] );
            hashTable.insert( test[i], val - 1 );
           }

int ha;
    for( int i = 0; i < word.length(); i++ ) 
 {
ha = hashTable.find( word[i] );
if(ha!=0) return false;
 }


    return true;
}

vector<string> AnagramFinder::getAnagrams( string word ) {
    // set up the return vector
    vector<string> ret;

    if( file ) {
        TextFile infile( filename );
        string line;
        vector<string> tests;
        while( infile.good() ) {
            string test = infile.getNextWord();
            if( checkWord( word, test ) ) 
                ret.push_back( test );
        }
    } else {
        for( unsigned int i = 0; i < strings.size(); i++ ) {
            if( checkWord( word, strings[i] ) )
                ret.push_back( strings[i] );
        }
    }
    return ret;
}

void AnagramFinder::writeAnagrams( string word, string filename ) {
    vector<string> anagrams = getAnagrams( word );
    ofstream outfile(filename.c_str());
    if( outfile.is_open() ) {
        for( unsigned int i = 0; i < anagrams.size(); i++ )
            outfile << anagrams[i] << endl;
    }
    outfile.close();
}
/*
   Logfile Parser (Lab 10)
   Created by Chase Geigle for CS225, Spring 2011
*/

#include "logfile_parser.h"

#include <iostream>

// creates a LogLine from the given line---you can ignore this.
LogfileParser::LogLine::LogLine( string line ) {
    istringstream iss( line );
    iss >> customer;
    customer = customer.substr(1, customer.length()-3);
    iss >> url;
    string dte = "";
    string dline;
    do {
        iss >> dline;
        dte += dline;
    } while( iss );

    date = time(NULL);
    tm * tme = localtime( &date );
    strptime( dte.c_str(), "%c", tme );
    date = mktime( tme );
}



LogfileParser::LogfileParser( string fname ) : whenVisitedTable(256, hasher) {
    SCHashTable< string, bool > pageVisitedTable(256, hasher);
    ifstream infile( fname.c_str() );
    string line;
    while( infile.good() ) {
        getline( infile, line );
        
        // if the line's length is 0, move to the next loop iteration
        if( line.length() == 0 )
            continue;

        LogLine ll( line );
        
      	string KEY;
         KEY=ll.customer;
         KEY.append(ll.url);
         //ll.date.tm_hour= ll.date.tm_hour-1;
        if(whenVisitedTable.keyExists(KEY))
        {
         if(whenVisitedTable.find(KEY)<ll.date)
			{
			whenVisitedTable.remove(KEY);
			 whenVisitedTable.insert(KEY, ll.date);
			
			}}

        else {whenVisitedTable.insert(KEY, ll.date);}
        
			
			////////////////////////////////////////
			bool cao=false;
			
         for(int i=0; i<uniqueURLs.size(); i++)
		 {if(uniqueURLs[i].compare(ll.url) == 0)
			cao = true;}
         if(cao==false)
         {uniqueURLs.push_back(ll.url);}
        // given the LogLine above, update the member variable hash table and
        // any other hash tables necessary to solve this problem. this should
        // also build the uniqueURLs vector.
    }

    
}

pair< bool, time_t > LogfileParser::dateVisited( string customer, string url ) {
    pair< bool, time_t > ret;
    // your code here! query your hash table for this function---should be short
    time_t x;
	 string KEY;
     KEY=customer;
     KEY.append(url);
    x=whenVisitedTable.find(KEY);
    ret.first=whenVisitedTable.keyExists(KEY);
	 ret.second=x;
    return ret;
}

vector<string> LogfileParser::uniquePages() {
    return uniqueURLs;
}

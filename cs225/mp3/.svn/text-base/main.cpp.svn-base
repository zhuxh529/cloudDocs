#include "list.h"
#include "BlockBMP.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

List<RGBApixel> imageToList( BMP const & img, bool reverse = false ) {
	List<RGBApixel> list;
	for( int i = 0; i < img.tellWidth(); i++ ) {
		for( int j = 0; j < img.tellHeight(); j++ ) {
			if( reverse )
				list.insertFront(*img(i,j));
			else
				list.insertBack(*img(i,j));
		}
	}
	return list;
}

BlockBMP listToImage( List<RGBApixel> const & list, int width, int height ) {
	BlockBMP ret;
	ret.setSize( width, height );
	vector<RGBApixel> v(list.begin(), list.end());
	int x = 0;
	int y = 0;
	for( unsigned int i = 0; i < v.size(); i++ ) {
		*ret(x,y) = v[i];
		y++;
		if( y == height ) {
			y = 0;
			x++;
		}
	}
	return ret;
}

void checkSoln( string test, BMP out, string soln_file ) {
	BMP soln;
	soln.readFromFile(soln_file.c_str());

	if( !(soln == out) )
		cerr << "[" << test << "]: Image does not match " << soln_file << endl;
}

void testInserts() {
	cout << "[main]: testing inserts" << endl;
	List<int> list;

	// test insertFront
	for( int i = 1; i <= 10; i++ )
		list.insertFront(i);

	cout << "[testInserts]: " << list << endl;

	List<int> list2;

	// test insertBack
	for( int i = 1; i <= 10; i++ )
		list2.insertBack(i);

	cout << "[testInserts]: " << list2 << endl;
}


void smalltest(){ // my own test goes here    my own test goes here    my own test goes here    go here ho here
	cout << "[main]: lalala, my own: " << endl;
	List<int> list;
   List<int> list2;
	// test insertFront
	for( int i = 1; i < 1; i++ )
		list.insertBack(i);

   for( int i = 1; i < 3; i++ )
		list2.insertFront(i);

   cout << "looooooooooo original" << list << endl;
   cout << "laaaaaaaaaaa return" << list2 << endl;
 /*  cout << "now mixspit"<<endl; 

    list2=list.mixSplit();
   cout << "looooooooooo original" << list << endl;
   cout << "laaaaaaaaaaa return" << list2 << endl;
	
*/
   list.interleaveWith(list2) ;
   cout << "now interleavewith"<<endl; 
   cout << "looooooooooo original" << list << endl;
   cout << "laaaaaaaaaaa return" << list2 << endl;




	// test insertBack
	






}

void testMixSplit() {
   
	cout << "[main]: testing mixSplit" << endl;
	BMP in;
	in.readFromFile("in_03.bmp");

	List<RGBApixel> list = imageToList(in);

	List<RGBApixel> split = list.mixSplit();

	BMP out = listToImage( list, in.tellWidth(), in.tellHeight() / 2 );
	out.writeToFile("mixSplit_this.bmp");

	checkSoln("testMixSplit", out, "soln_mixSplit_this.bmp");

	out = listToImage( split, in.tellWidth(), in.tellHeight() / 2 );
	out.writeToFile("mixSplit_split.bmp");

	checkSoln("testMixSplit", out, "soln_mixSplit_split.bmp");
}

void testInterleaveWith() {
	cout << "[main]: testing interleaveWith (requires mixSplit!)" << endl;
	BMP frame1;
	frame1.readFromFile("in_03.bmp");

	BMP frame2;
	frame2.readFromFile("in_04.bmp");

	List<RGBApixel> f1 = imageToList(frame1);
	List<RGBApixel> f2 = imageToList(frame2);

	List<RGBApixel> f1_odd = f1.mixSplit();
	List<RGBApixel> f2_odd = f2.mixSplit();

	f1.interleaveWith(f2_odd);
	f2.interleaveWith(f1_odd);

	BMP out = listToImage( f1, frame1.tellWidth(), frame1.tellHeight() );
	out.writeToFile("interleaved_1.bmp");

	checkSoln("testInterleaveWith", out, "soln_interleaved_1.bmp");

	out = listToImage( f2, frame1.tellWidth(), frame1.tellHeight() );
	out.writeToFile("interleaved_2.bmp");

	checkSoln("testInterleaveWith", out, "soln_interleaved_2.bmp");
}

inline vector<int> buildVector( BlockBMP const & b, int d ) {
	vector<int> v;
	for( int i = 1; i <= ( b.tellWidth() * b.tellHeight() ) / ( d * d ); i++ )
		v.push_back(i);

	return v;
}

void testSort() {
	cout << "[main]: testing sort" << endl;

	srand(225);

	// read in image to be shuffled
	BlockBMP b;
	b.readFromFile("in_01.bmp");

	int d = 64;
	vector<int> v = buildVector(b, d);
	random_shuffle(v.begin(), v.end());

	// generate shuffled image (done for you already)
	/*
	BMP b2 = b.genImg(v, d);
	b2.writeToFile("in_shuffled_64.bmp");
	*/

	// make list and sort it
	List<int> img_srt(v.begin(), v.end());
	img_srt.sort();

	// vectorize and rebuild image
	vector<int> v2(img_srt.begin(), img_srt.end());

	BMP b3 = b.genImg(v2, d);
	b3.writeToFile("unshuffled_64.bmp");

	checkSoln("testSort", b3, "in_01.bmp");

	d = 1;
	v = buildVector(b, d);
	random_shuffle(v.begin(), v.end());

	/*
	BMP q = b.genImg( v, d );
	q.writeToFile("in_shuffled_1.bmp");
	*/

	List<int> q_srt(v.begin(), v.end());
	q_srt.sort();

	v2 = vector<int>(q_srt.begin(), q_srt.end());

	b3 = b.genImg( v2, d );
	b3.writeToFile("unshuffled_1.bmp");

	checkSoln("testSort", b3, "in_01.bmp");
}

void testMP31() {
	testInserts();
	testMixSplit();
	testInterleaveWith();
}

void testMP32() {
	testSort();
}

int main( int argc, char ** argv ) {
	vector<string> args(argv, argv+argc);
	if( argc == 1 || args[1] == "all" ) {
		testMP31();
		testMP32();
	} else {
      if( args[1] == "test")// modified~
			smalltest();
		if( args[1] == "mp3.1" || args[1] == "mp31" )
			testMP31();
		else if( args[1] == "mp3.2" || args[1] == "mp32" )
			testMP32();
		else if( args[1] == "inserts" )
			testInserts();
		else if( args[1] == "mixsplit" || args[1] == "mixSplit" )
			testMixSplit();
		else if( args[1] == "interleavewith" || args[1] == "interleaveWith" )
			testInterleaveWith();
		else if( args[1] == "sort" || args[1] == "mergesort" || args[1] == "mergeSort" )
			testSort();
	}

	return 0;
}

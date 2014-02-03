/*************************************************
 *												*
 *  EasyBMP Cross-Platform Windows Bitmap Library *
 *												*
 *  Author: Paul Macklin						  *
 *   email: macklin01@users.sourceforge.net	   *
 * support: http://easybmp.sourceforge.net		*
 *												*
 *		  file: EasyBMP.cpp					 *
 *	date added: 03-31-2006					  *
 * date modified: 07-22-2006					  *
 *	   version: 1.04							*
 *												*
 *   License: BSD (revised/modified)			  *
 * Copyright: 2005-6 by the EasyBMP Project	   *
 *												*
 * description: Actual source file				*
 *												*
 * Modified 9/06 by Bill Kinnersley for CS225	 *
 * Changes:									   *
 *   - improved "const correctness" throughout	*
 *   - implemented BMP::operator=()			   *
 *   - altered BMP::operator()() to print the	 *
 *	 original, invalid coordinates in case	  *
 *	 of an error								*
 *   - misc. stylistic changes (indentation,	  *
 *	 etc.)									  *
 *   - added const version of operator()		  *
 *												*
 *************************************************/

#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sstream>
#include <string>

#include "EasyBMP.h"

using namespace std;

/* These functions are declared in EasyBMP.h */

bool EasyBMPwarnings = true;

void SetEasyBMPwarningsOff(void) { EasyBMPwarnings = false; }
void SetEasyBMPwarningsOn(void) { EasyBMPwarnings = true; }
bool GetEasyBMPwarningState(void) { return EasyBMPwarnings; }


/* These functions are declared in EasyBMP_DataStructures.h */

int IntPow(int base, int exponent)
{
	int i;
	int output = 1;
	for(i=0; i < exponent; i++)
		output *= base;
	return output;
}

BMFH::BMFH()
{
	bfType = 19778;
	bfReserved1 = 0;
	bfReserved2 = 0;
}

void BMFH::SwitchEndianess()
{
	bfType = FlipWORD( bfType );
	bfSize = FlipDWORD( bfSize );
	bfReserved1 = FlipWORD( bfReserved1 );
	bfReserved2 = FlipWORD( bfReserved2 );
	bfOffBits = FlipDWORD( bfOffBits );
	return;
}

BMIH::BMIH()
{
	biPlanes = 1;
	biCompression = 0;
	biXPelsPerMeter = DefaultXPelsPerMeter;
	biYPelsPerMeter = DefaultYPelsPerMeter;
	biClrUsed = 0;
	biClrImportant = 0;
}

void BMIH::SwitchEndianess()
{
	biSize = FlipDWORD( biSize );
	biWidth = FlipDWORD( biWidth );
	biHeight = FlipDWORD( biHeight );
	biPlanes = FlipWORD( biPlanes );
	biBitCount = FlipWORD( biBitCount );
	biCompression = FlipDWORD( biCompression );
	biSizeImage = FlipDWORD( biSizeImage );
	biXPelsPerMeter = FlipDWORD( biXPelsPerMeter );
	biYPelsPerMeter = FlipDWORD( biYPelsPerMeter );
	biClrUsed = FlipDWORD( biClrUsed );
	biClrImportant = FlipDWORD( biClrImportant );
	return;
}

void BMIH::display()
{
	using namespace std;
	cout << "biSize: " << (int) biSize << endl
		<< "biWidth: " << (int) biWidth << endl
		<< "biHeight: " << (int) biHeight << endl
		<< "biPlanes: " << (int) biPlanes << endl
		<< "biBitCount: " << (int) biBitCount << endl
		<< "biCompression: " << (int) biCompression << endl
		<< "biSizeImage: " << (int) biSizeImage << endl
		<< "biXPelsPerMeter: " << (int) biXPelsPerMeter << endl
		<< "biYPelsPerMeter: " << (int) biYPelsPerMeter << endl
		<< "biClrUsed: " << (int) biClrUsed << endl
		<< "biClrImportant: " << (int) biClrImportant << endl << endl;
}

void BMFH::display()
{
	using namespace std;
	cout << "bfType: " << (int) bfType << endl
		<< "bfSize: " << (int) bfSize << endl
		<< "bfReserved1: " << (int) bfReserved1 << endl
		<< "bfReserved2: " << (int) bfReserved2 << endl
		<< "bfOffBits: " << (int) bfOffBits << endl << endl;
}



// operator<< (not a member function)
//   - parameters: ostream & - output stream to be used for output
//                 RGBApixel const & pixel - pixel to be output
//   - prints the contents of the given RGBApixel to the given output stream
std::ostream & operator<<(std::ostream & out, RGBApixel const & pixel)
{
	out << "(" << (int) pixel.Red << "," << (int) pixel.Green
	    << "," << (int) pixel.Blue << ")";
	return out;
}



/* These functions are declared in EasyBMP_BMP.h */

bool BMP::setColor(int ColorNumber , RGBApixel const & NewColor)
{
	using namespace std;
	if(BitDepth != 1 && BitDepth != 4 && BitDepth != 8)
	{
		if(EasyBMPwarnings)
		{
			cout << "EasyBMP Warning: Attempted to change color table for a BMP object" << endl
				<< "				 that lacks a color table. Ignoring request." << endl;
		}
		return false;
	}

	if(!Colors)
	{
		if( EasyBMPwarnings )
		{
			cout << "EasyBMP Warning: Attempted to set a color, but the color table" << endl
				<< "				 is not defined. Ignoring request." << endl;
		}
		return false;
	}

	if(ColorNumber >= tellNumberOfColors())
	{
		if(EasyBMPwarnings)
		{
			cout << "EasyBMP Warning: Requested color number "
				<< ColorNumber << " is outside the allowed" << endl
				<< "				 range [0," << tellNumberOfColors()-1
				<< "]. Ignoring request to set this color." << endl;
		}
		return false;
	}

	Colors[ColorNumber] = NewColor;

	return true;
}

BMP::BMP(BMP const & rhs)
{
	int i, ncolors;
	BitDepth = rhs.BitDepth;
	Width = rhs.Width;
	Height = rhs.Height;
	XPelsPerMeter = rhs.XPelsPerMeter;
	YPelsPerMeter = rhs.YPelsPerMeter;

	capacity = rhs.capacity;

	if (rhs.myPixels != NULL) {
		myPixels = new RGBApixel[capacity];
		for (i = 0; i < Width*Height; i++) {
			myPixels[i] = rhs.myPixels[i];
		}
	} else {
		myPixels = NULL;
	}

	if (rhs.Colors) {
		ncolors = rhs.tellNumberOfColors();
		Colors = new RGBApixel[ncolors];
		for (i = 0; i < ncolors; i++)
			Colors[i] = rhs.Colors[i];
	} else {
		Colors = NULL;
	}

	SizeOfMetaData1 = rhs.SizeOfMetaData1;
	if (rhs.MetaData1) {
		MetaData1 = new uint8_t[SizeOfMetaData1];
		for (i = 0; i < SizeOfMetaData1; i++)
			MetaData1[i] = rhs.MetaData1[i];
	} else {
		MetaData1 = NULL;
	}
	SizeOfMetaData2 = rhs.SizeOfMetaData2;
	if (rhs.MetaData2) {
		MetaData2 = new uint8_t[SizeOfMetaData2];
		for (i = 0; i < SizeOfMetaData2; i++)
			MetaData2[i] = rhs.MetaData2[i];
	} else {
		MetaData2 = NULL;
	}
}

BMP const & BMP::operator=(BMP const & rhs)
{
	int i, ncolors;
	if (this != &rhs) {
		if (myPixels != NULL && capacity < rhs.Width*rhs.Height) {
			delete [] myPixels;
			myPixels = NULL;
		}
		if (Colors)
			delete [] Colors;
		if (MetaData1)
			delete [] MetaData1;
		if (MetaData2)
			delete [] MetaData2;

		BitDepth = rhs.BitDepth;
		Width = rhs.Width;
		Height = rhs.Height;
		XPelsPerMeter = rhs.XPelsPerMeter;
		YPelsPerMeter = rhs.YPelsPerMeter;

		if (rhs.myPixels != NULL) {
			if (myPixels == NULL) {
				capacity = Width*Height;
				myPixels = new RGBApixel[capacity];
			}
			for (i = 0; i < Width*Height; i++) {
				myPixels[i] = rhs.myPixels[i];
			}
		} else {
			myPixels = NULL;
		}

		if (rhs.Colors) {
			ncolors = rhs.tellNumberOfColors();
			Colors = new RGBApixel[ncolors];
			for (i = 0; i < ncolors; i++)
				Colors[i] = rhs.Colors[i];
		} else {
			Colors = NULL;
		}

		SizeOfMetaData1 = rhs.SizeOfMetaData1;
		if (rhs.MetaData1) {
			MetaData1 = new uint8_t[SizeOfMetaData1];
			for (i = 0; i < SizeOfMetaData1; i++)
				MetaData1[i] = rhs.MetaData1[i];
		} else {
			MetaData1 = NULL;
		}
		SizeOfMetaData2 = rhs.SizeOfMetaData2;
		if (rhs.MetaData2) {
			MetaData2 = new uint8_t[SizeOfMetaData2];
			for (i = 0; i < SizeOfMetaData2; i++)
				MetaData2[i] = rhs.MetaData2[i];
		} else {
			MetaData2 = NULL;
		}
	}

	return *this;
}

bool operator==(RGBApixel const & left, RGBApixel const & right) {
	return (left.Red == right.Red && left.Green == right.Green
			&& left.Blue == right.Blue);
}

bool operator!=(RGBApixel const & left, RGBApixel const & right) {
	return !(left == right);
}

bool BMP::operator==(const BMP & rhs) const
{
	int width = tellWidth();
	int height = tellHeight();
	if (rhs.tellWidth() != width || rhs.tellHeight() != height)
		return false;

	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
			if (*((*this)(i,j)) != *(rhs(i,j)))
				return false;

	return true;
}

bool BMP::operator!=(const BMP & rhs) const
{
	return !operator==(rhs);
}


RGBApixel BMP::getColor(int ColorNumber) const
{
	RGBApixel Output;
	Output.Red   = 255;
	Output.Green = 255;
	Output.Blue  = 255;
	Output.Alpha = 0;

	using namespace std;
	if(BitDepth != 1 && BitDepth != 4 && BitDepth != 8)
	{
		if(EasyBMPwarnings)
		{
			cout << "EasyBMP Warning: Attempted to access color table for a BMP object" << endl
				<< "				 that lacks a color table. Ignoring request." << endl;
		}
		return Output;
	}

	if(!Colors)
	{
		if(EasyBMPwarnings)
		{
			cout << "EasyBMP Warning: Requested a color, but the color table" << endl
				<< "				 is not defined. Ignoring request." << endl;
		}
		return Output;
	}

	if(ColorNumber >= tellNumberOfColors())
	{
		if(EasyBMPwarnings)
		{
			cout << "EasyBMP Warning: Requested color number "
				<< ColorNumber << " is outside the allowed" << endl
				<< "				 range [0," << tellNumberOfColors()-1
				<< "]. Ignoring request to get this color." << endl;
		}
		return Output;
	}

	Output = Colors[ColorNumber];

	return Output;
}

BMP::BMP()
{
	initializeDefaults();
}

BMP::BMP(int startWidth, int startHeight)
{
	initializeDefaults();
	setSize(startWidth, startHeight); // TODO (toole1): Refactor to make this faster
}

BMP::BMP(const string & FileName)
{
	initializeDefaults();
	readFromFile(FileName);
}

BMP::BMP(const char * FileName)
{
	initializeDefaults();
	if (FileName != NULL)
		readFromFile(FileName);
}

void BMP::initializeDefaults()
{
	Width = 1;
	Height = 1;
	BitDepth = 24;
	capacity = 16*16; // This is super haxx so that resizing a blank BMP to a 16x16 or less is free
	                  // This is for testing timings, so allocations don't overwhelm running time
	myPixels = new RGBApixel[capacity];
	Colors = NULL;
			
	myPixels[0].Red = 255;
	myPixels[0].Green = 255;
	myPixels[0].Blue = 255;
	myPixels[0].Alpha = 0;

	XPelsPerMeter = 0;
	YPelsPerMeter = 0;

	MetaData1 = NULL;
	SizeOfMetaData1 = 0;
	MetaData2 = NULL;
	SizeOfMetaData2 = 0;
}

BMP::~BMP()
{
	delete [] myPixels;

	if(Colors)
		delete [] Colors;
	if(MetaData1)
		delete [] MetaData1;
	if(MetaData2)
		delete [] MetaData2;
}

RGBApixel* BMP::operator()(int i, int j)
{
	using namespace std;
	int x = i, y = j;

	if(x >= Width)
		x = Width-1;
	if(x < 0)
		x = 0;
	if(y >= Height)
		y = Height-1;
	if(y < 0)
		y = 0;

	// if we changed x or y, there must have been a problem
	if((x != i || y != j) && EasyBMPwarnings)
	{
		cout << "EasyBMP Warning: Attempted to access non-existent pixel "
			<< "(" << i << ", " << j << ");" << endl
			<< "				 Truncating request to fit in the range [0,"
			<< Width-1 << "] x [0," << Height-1 << "]." << endl;
	}

	return &(Pixels(x,y));
}

RGBApixel const * BMP::operator()(int i, int j) const
{
	using namespace std;
	int x = i, y = j;

	if(x >= Width)
		x = Width-1;
	if(x < 0)
		x = 0;
	if(y >= Height)
		y = Height-1;
	if(y < 0)
		y = 0;

	// if we changed x or y, there must have been a problem
	if((x != i || y != j) && EasyBMPwarnings)
	{
		cout << "EasyBMP Warning: Attempted to access non-existent pixel "
			<< "(" << i << ", " << ");" << endl
			<< "				 Truncating request to fit in the range [0,"
			<< Width-1 << "] x [0," << Height-1 << "]." << endl;
	}

	return &(Pixels(x,y));
}

int BMP::tellBitDepth() const { return BitDepth; }

int BMP::tellHeight() const { return Height; }

int BMP::tellWidth() const { return Width; }

int BMP::tellNumberOfColors() const
{
	int output = IntPow(2, BitDepth);
	if (BitDepth == 32)
		output = IntPow(2, 24);
	return output;
}

bool BMP::setBitDepth(int NewDepth)
{
	using namespace std;
	if(NewDepth != 1 && NewDepth != 4 &&
			NewDepth != 8 && NewDepth != 16 &&
			NewDepth != 24 && NewDepth != 32)
	{
		if(EasyBMPwarnings)
		{
			cout << "EasyBMP Warning: User attempted to set unsupported bit depth "
				<< NewDepth << "." << endl
				<< "				 Bit depth remains unchanged at "
				<< BitDepth << "." << endl;
		}
		return false;
	}

	BitDepth = NewDepth;
	if(Colors)
		delete [] Colors;
	int NumberOfColors = IntPow(2, BitDepth);
	if(BitDepth == 1 || BitDepth == 4 || BitDepth == 8)
		Colors = new RGBApixel [NumberOfColors];
	else
		Colors = NULL;
	if(BitDepth == 1 || BitDepth == 4 || BitDepth == 8)
		createStandardColorTable();

	return true;
}

bool BMP::setSize(int NewWidth , int NewHeight)
{
	using namespace std;
	if(NewWidth <= 0 || NewHeight <= 0)
	{
		if(EasyBMPwarnings)
		{
			cout << "EasyBMP Warning: User attempted to set a non-positive width or height." << endl
				<< "				 Size remains unchanged at "
				<< Width << " x " << Height << "." << endl;
		}
		return false;
	}

	Width = NewWidth;
	Height = NewHeight;
	
	if (capacity < Width*Height) {
		delete [] myPixels;
		capacity = Width*Height;
		myPixels = new RGBApixel[capacity];
	}

	RGBApixel white;
	white.Red   = 255;
	white.Green = 255;
	white.Blue  = 255;
	white.Alpha = 0;   //TODO (toole1): Pretty sure this should be 255
	for(int i = 0; i < Width*Height; i++)
		myPixels[i] = white;

	return true;
}

bool BMP::writeToFile(const char * fileName) const
{
	if (fileName != NULL)
		return writeToFile(string(fileName));
	else
		return false;
}

bool BMP::writeToFile(string fileName) const
{
	size_t dotpos = fileName.find_last_of(".");
	if (dotpos == string::npos)
		fileName += ".bmp";
	else
	{
		string ext = fileName.substr(dotpos + 1);
		for (size_t i = 0; i < ext.size(); i++)
			ext[i] = tolower(ext[i]);

		if (ext != "bmp")
		{
			for (size_t i = 0; i < fileName.size(); i++)
			{
				if (!isSafeFileChar(fileName[i]))
				{
					cerr << "ERROR: Unsafe file path specified: " << fileName << endl;
					exit(-1);
				}
			}
			string tempDir = "/tmp/" + sanitize(getUserName()) + "/easybmp/";
			stringstream tempFiless;
			tempFiless << tempDir << "temp" << time(NULL) << rand() << ".bmp";
			string tempFile = tempFiless.str();

			system(("rm -rf '" + tempFile + "'").c_str());
			system(("mkdir -m 0700 -p '" + tempDir + "'").c_str());
//			bool prevWarningState = EasyBMPwarnings;
//			EasyBMPwarnings = false;
			bool result = writeToBMPFile(tempFile.c_str());
			if (!result) return false;
//			EasyBMPwarnings = prevWarningState;
			cout << ("convert '" + tempFile + "' '" + fileName + "'").c_str() << endl;
			system(("convert '" + tempFile + "' '" + fileName + "'").c_str());
			system(("rm -rf '" + tempFile + "'").c_str());
			return result;
		}
	}

	return writeToBMPFile(fileName.c_str());
}

bool BMP::writeToBMPFile(const char* FileName) const
{
	using namespace std;
	if(!EasyBMPcheckDataSize())
	{
		if(EasyBMPwarnings)
		{
			cout << "EasyBMP Error: Data types are wrong size!" << endl
				<< "			   You may need to mess with EasyBMP_DataTypes.h" << endl
				<< "			   to fix these errors, and then recompile." << endl
				<< "			   All 32-bit and 64-bit machines should be" << endl
				<< "			   supported, however." << endl << endl;
		}
		return false;
	}

	FILE* fp = fopen(FileName, "wb");
	if(fp == NULL)
	{
		if(EasyBMPwarnings)
		{
			cout << "EasyBMP Error: Cannot open file "
				<< FileName << " for output." << endl;
		}
		fclose(fp);
		return false;
	}

	// some preliminaries

	double dBytesPerPixel = ((double) BitDepth) / 8.0;
	double dBytesPerRow = dBytesPerPixel * (Width+0.0);
	dBytesPerRow = ceil(dBytesPerRow);

	int BytePaddingPerRow = 4 - ((int) (dBytesPerRow))% 4;
	if(BytePaddingPerRow == 4)
		BytePaddingPerRow = 0;

	double dActualBytesPerRow = dBytesPerRow + BytePaddingPerRow;

	double dTotalPixelBytes = Height * dActualBytesPerRow;

	double dPaletteSize = 0;
	if(BitDepth == 1 || BitDepth == 4 || BitDepth == 8)
		dPaletteSize = IntPow(2,BitDepth)*4.0;

	// leave some room for 16-bit masks
	if( BitDepth == 16 )
		dPaletteSize = 3*4;

	double dTotalFileSize = 14 + 40 + dPaletteSize + dTotalPixelBytes;

	// write the file header

	BMFH bmfh;
	bmfh.bfSize = (uint32_t) dTotalFileSize;
	bmfh.bfReserved1 = 0;
	bmfh.bfReserved2 = 0;
	bmfh.bfOffBits = (uint32_t) (14+40+dPaletteSize);

	if(IsBigEndian())
		bmfh.SwitchEndianess();

	fwrite((char*) &(bmfh.bfType), sizeof(uint16_t), 1, fp);
	fwrite((char*) &(bmfh.bfSize), sizeof(uint32_t), 1, fp);
	fwrite((char*) &(bmfh.bfReserved1), sizeof(uint16_t), 1, fp);
	fwrite((char*) &(bmfh.bfReserved2), sizeof(uint16_t), 1, fp);
	fwrite((char*) &(bmfh.bfOffBits), sizeof(uint32_t), 1, fp);

	// write the info header

	BMIH bmih;
	bmih.biSize = 40;
	bmih.biWidth = Width;
	bmih.biHeight = Height;
	bmih.biPlanes = 1;
	bmih.biBitCount = BitDepth;
	bmih.biCompression = 0;
	bmih.biSizeImage = (uint32_t) dTotalPixelBytes;
	if(XPelsPerMeter)
		bmih.biXPelsPerMeter = XPelsPerMeter;
	else
		bmih.biXPelsPerMeter = DefaultXPelsPerMeter;
	if(YPelsPerMeter)
		bmih.biYPelsPerMeter = YPelsPerMeter;
	else
		bmih.biYPelsPerMeter = DefaultYPelsPerMeter;

	bmih.biClrUsed = 0;
	bmih.biClrImportant = 0;

	// indicates that we'll be using bit fields for 16-bit files
	if(BitDepth == 16)
		bmih.biCompression = 3;

	if(IsBigEndian())
		bmih.SwitchEndianess();

	fwrite((char*) &(bmih.biSize), sizeof(uint32_t), 1, fp);
	fwrite((char*) &(bmih.biWidth), sizeof(uint32_t), 1, fp);
	fwrite((char*) &(bmih.biHeight), sizeof(uint32_t), 1, fp);
	fwrite((char*) &(bmih.biPlanes), sizeof(uint16_t), 1, fp);
	fwrite((char*) &(bmih.biBitCount), sizeof(uint16_t), 1, fp);
	fwrite((char*) &(bmih.biCompression), sizeof(uint32_t), 1, fp);
	fwrite((char*) &(bmih.biSizeImage), sizeof(uint32_t), 1, fp);
	fwrite((char*) &(bmih.biXPelsPerMeter), sizeof(uint32_t), 1, fp);
	fwrite((char*) &(bmih.biYPelsPerMeter), sizeof(uint32_t), 1, fp);
	fwrite((char*) &(bmih.biClrUsed), sizeof(uint32_t), 1, fp);
	fwrite((char*) &(bmih.biClrImportant), sizeof(uint32_t), 1, fp);

	// write the palette
	if(BitDepth == 1 || BitDepth == 4 || BitDepth == 8)
	{
		int NumberOfColors = IntPow(2,BitDepth);

		// This does not belong in this function!  Moving to constructor / readFromFile
		// if there is no palette, create one
		//if(!Colors)
		//{
		//   if(!Colors)
		//	  Colors = new RGBApixel [NumberOfColors];
		//   createStandardColorTable();
		//}

		int n;
		for(n=0; n < NumberOfColors; n++)
			fwrite((char*) &(Colors[n]), 4, 1, fp);
	}

	// write the pixels
	int i,j;
	if(BitDepth != 16)
	{
		uint8_t* Buffer;
		int BufferSize = (int) ((Width*BitDepth)/8.0);
		while(8*BufferSize < Width*BitDepth)
			BufferSize++;
		while(BufferSize % 4)
			BufferSize++;

		Buffer = new uint8_t [BufferSize];
		for(j=0; j < BufferSize; j++)
			Buffer[j] = 0;

		j=Height-1;

		while(j > -1)
		{
			bool Success = false;
			if(BitDepth == 32)
				Success = Write32bitRow(Buffer, BufferSize, j);
			if(BitDepth == 24)
				Success = Write24bitRow(Buffer, BufferSize, j);
			if(BitDepth == 8)
				Success = Write8bitRow(Buffer, BufferSize, j);
			if(BitDepth == 4)
				Success = Write4bitRow(Buffer, BufferSize, j);
			if(BitDepth == 1)
				Success = Write1bitRow(Buffer, BufferSize, j);
			if(Success)
			{
				int BytesWritten = (int) fwrite((char*) Buffer, 1, BufferSize, fp);
				if(BytesWritten != BufferSize)
					Success = false;
			}
			if(!Success)
			{
				if(EasyBMPwarnings)
					cout << "EasyBMP Error: Could not write proper amount of data." << endl;
				j = -1;
			}
			j--;
		}

		delete [] Buffer;
	}

	if(BitDepth == 16)
	{
		// write the bit masks

		uint16_t BlueMask = 31;	// bits 12-16
		uint16_t GreenMask = 2016; // bits 6-11
		uint16_t RedMask = 63488;  // bits 1-5
		uint16_t ZeroWORD;

		if(IsBigEndian())
			RedMask = FlipWORD(RedMask);
		fwrite((char*) &RedMask, 2, 1, fp);
		fwrite((char*) &ZeroWORD, 2, 1, fp);

		if(IsBigEndian())
			GreenMask = FlipWORD(GreenMask);
		fwrite((char*) &GreenMask, 2, 1, fp);
		fwrite((char*) &ZeroWORD, 2, 1, fp);

		if(IsBigEndian())
			BlueMask = FlipWORD(BlueMask);
		fwrite((char*) &BlueMask, 2, 1, fp);
		fwrite((char*) &ZeroWORD, 2, 1, fp);

		int DataBytes = Width*2;
		int PaddingBytes = (4 - DataBytes % 4) % 4;

		// write the actual pixels

		for(j=Height-1; j >= 0; j--)
		{
			// write all row pixel data
			i=0;
			int WriteNumber = 0;
			while(WriteNumber < DataBytes)
			{
				uint16_t TempWORD;

				uint16_t RedWORD = (uint16_t) ((Pixels(i,j)).Red / 8);
				uint16_t GreenWORD = (uint16_t) ((Pixels(i,j)).Green / 4);
				uint16_t BlueWORD = (uint16_t) ((Pixels(i,j)).Blue / 8);

				TempWORD = (RedWORD<<11) + (GreenWORD<<5) + BlueWORD;
				if(IsBigEndian())
					TempWORD = FlipWORD(TempWORD);

				fwrite((char*) &TempWORD, 2, 1, fp);
				WriteNumber += 2;
				i++;
			}

			// write any necessary row padding
			WriteNumber = 0;
			while(WriteNumber < PaddingBytes)
			{
				uint8_t TempBYTE;
				fwrite((char*) &TempBYTE, 1, 1, fp);
				WriteNumber++;
			}
		}
	}

	fclose(fp);

	return true;
}

bool BMP::isSafeFileChar(int c)
{
	if (isalnum(c)) return true;
	if (string("_ .-/\\~!@#$%()[]|").find(c) != string::npos) return true;
	return false;
}

const char * BMP::getUserName()
{
	return getpwuid(getuid())->pw_name;
}

string BMP::sanitize(const string & input)
{
	string out;
	out.reserve(input.length());
	for (size_t i = 0; i < input.size(); i++)
		if (isSafeFileChar(input[i]))
			out += input[i];
	return out;
}

bool BMP::readFromFile(const char * fileName)
{
	if (fileName != NULL)
		return readFromFile(string(fileName));
	else
		return false;
}

bool BMP::readFromFile(string fileName)
{
	size_t dotpos = fileName.find_last_of(".");
	if (dotpos == string::npos)
		fileName += ".bmp";
	else
	{
		string ext = fileName.substr(dotpos + 1);
		for (size_t i = 0; i < ext.size(); i++)
			ext[i] = tolower(ext[i]);

		if (ext != "bmp")
		{
			for (size_t i = 0; i < fileName.size(); i++)
			{
				if (!isSafeFileChar(fileName[i]))
				{
					cerr << "ERROR: Unsafe file path specified: " << fileName << endl;
					exit(-1);
				}
			}
			string tempDir = "/tmp/" + sanitize(getUserName()) + "/easybmp/";
			stringstream tempFiless;
			tempFiless << tempDir << "temp" << time(NULL) << rand() << ".bmp";
			string tempFile = tempFiless.str();

			system(("rm -rf '" + tempFile + "'").c_str());
			system(("mkdir -m 0700 -p '" + tempDir + "'").c_str());
			system(("convert '" + fileName + "' '" + tempFile + "'").c_str());
			bool prevWarningState = EasyBMPwarnings;
			EasyBMPwarnings = false;
			bool result = readFromBMPFile(tempFile.c_str());
			EasyBMPwarnings = prevWarningState;
			system(("rm -rf '" + tempFile + "'").c_str());
			return result;
		}
	}
	return readFromBMPFile(fileName.c_str());
}

bool BMP::readFromBMPFile( const char* FileName )
{
	using namespace std;
	if( !EasyBMPcheckDataSize() )
	{
		if( EasyBMPwarnings )
		{
			cout << "EasyBMP Error: Data types are wrong size!" << endl
				<< "			   You may need to mess with EasyBMP_DataTypes.h" << endl
				<< "			   to fix these errors, and then recompile." << endl
				<< "			   All 32-bit and 64-bit machines should be" << endl
				<< "			   supported, however." << endl << endl;
		}
		return false;
	}

	FILE* fp = fopen(FileName, "rb");
	if(fp == NULL)
	{
		if(EasyBMPwarnings)
		{
			cout << "EasyBMP Error: Cannot open file "
				<< FileName << " for input." << endl;
		}
		setBitDepth(1);
		setSize(1,1);
		return false;
	}

	// read the file header

	BMFH bmfh;
	bool NotCorrupted = true;

	NotCorrupted &= SafeFread((char*) &(bmfh.bfType), sizeof(uint16_t), 1, fp);

	bool IsBitmap = false;

	if(IsBigEndian() && bmfh.bfType == 16973)
		IsBitmap = true;
	if(!IsBigEndian() && bmfh.bfType == 19778)
		IsBitmap = true;

	if(!IsBitmap)
	{
		if(EasyBMPwarnings)
		{
			cout << "EasyBMP Error: " << FileName
				<< " is not a Windows BMP file!" << endl;
		}
		fclose(fp);
		return false;
	}

	NotCorrupted &= SafeFread( (char*) &(bmfh.bfSize) , sizeof(uint32_t) , 1, fp);
	NotCorrupted &= SafeFread( (char*) &(bmfh.bfReserved1) , sizeof(uint16_t) , 1, fp);
	NotCorrupted &= SafeFread( (char*) &(bmfh.bfReserved2) , sizeof(uint16_t) , 1, fp);
	NotCorrupted &= SafeFread( (char*) &(bmfh.bfOffBits) , sizeof(uint32_t) , 1 , fp);

	if( IsBigEndian() )
	{ bmfh.SwitchEndianess(); }

	// read the info header

	BMIH bmih;

	NotCorrupted &= SafeFread( (char*) &(bmih.biSize) , sizeof(uint32_t) , 1 , fp);
	NotCorrupted &= SafeFread( (char*) &(bmih.biWidth) , sizeof(uint32_t) , 1 , fp);
	NotCorrupted &= SafeFread( (char*) &(bmih.biHeight) , sizeof(uint32_t) , 1 , fp);
	NotCorrupted &= SafeFread( (char*) &(bmih.biPlanes) , sizeof(uint16_t) , 1, fp);
	NotCorrupted &= SafeFread( (char*) &(bmih.biBitCount) , sizeof(uint16_t) , 1, fp);

	NotCorrupted &= SafeFread( (char*) &(bmih.biCompression) , sizeof(uint32_t) , 1 , fp);
	NotCorrupted &= SafeFread( (char*) &(bmih.biSizeImage) , sizeof(uint32_t) , 1 , fp);
	NotCorrupted &= SafeFread( (char*) &(bmih.biXPelsPerMeter) , sizeof(uint32_t) , 1 , fp);
	NotCorrupted &= SafeFread( (char*) &(bmih.biYPelsPerMeter) , sizeof(uint32_t) , 1 , fp);
	NotCorrupted &= SafeFread( (char*) &(bmih.biClrUsed) , sizeof(uint32_t) , 1 , fp);
	NotCorrupted &= SafeFread( (char*) &(bmih.biClrImportant) , sizeof(uint32_t) , 1 , fp);

	if( IsBigEndian() )
	{ bmih.SwitchEndianess(); }

	// a safety catch: if any of the header information didn't read properly, abort
	// future idea: check to see if at least most is self-consistent

	if( !NotCorrupted )
	{
		if( EasyBMPwarnings )
		{
			cout << "EasyBMP Error: " << FileName
				<< " is obviously corrupted." << endl;
		}
		setSize(1,1);
		setBitDepth(1);
		fclose(fp);
		return false;
	}

	XPelsPerMeter = bmih.biXPelsPerMeter;
	YPelsPerMeter = bmih.biYPelsPerMeter;

	// if bmih.biCompression 1 or 2, then the file is RLE compressed

	if( bmih.biCompression == 1 || bmih.biCompression == 2 )
	{
		if( EasyBMPwarnings )
		{
			cout << "EasyBMP Error: " << FileName << " is (RLE) compressed." << endl
				<< "			   EasyBMP does not support compression." << endl;
		}
		setSize(1,1);
		setBitDepth(1);
		fclose(fp);
		return false;
	}

	// if bmih.biCompression > 3, then something strange is going on
	// it's probably an OS2 bitmap file.

	if( bmih.biCompression > 3 )
	{
		if( EasyBMPwarnings )
		{
			cout << "EasyBMP Error: " << FileName << " is in an unsupported format."
				<< endl
				<< "			   (bmih.biCompression = "
				<< bmih.biCompression << ")" << endl
				<< "			   The file is probably an old OS2 bitmap or corrupted."
				<< endl;
		}		
		setSize(1,1);
		setBitDepth(1);
		fclose(fp);
		return false;
	}

	if( bmih.biCompression == 3 && bmih.biBitCount != 16 )
	{
		if( EasyBMPwarnings )
		{
			cout << "EasyBMP Error: " << FileName
				<< " uses bit fields and is not a" << endl
				<< "			   16-bit file. This is not supported." << endl;
		}
		setSize(1,1);
		setBitDepth(1);
		fclose(fp);
		return false;
	}

	// set the bit depth

	int TempBitDepth = (int) bmih.biBitCount;
	if(	TempBitDepth != 1  && TempBitDepth != 4
			&& TempBitDepth != 8  && TempBitDepth != 16
			&& TempBitDepth != 24 && TempBitDepth != 32 )
	{
		if( EasyBMPwarnings )
		{
			cout << "EasyBMP Error: " << FileName << " has unrecognized bit depth." << endl;
		}
		setSize(1,1);
		setBitDepth(1);
		fclose(fp);
		return false;
	}
	setBitDepth( (int) bmih.biBitCount );

	// set the size

	if( (int) bmih.biWidth <= 0 || (int) bmih.biHeight <= 0 )
	{
		if( EasyBMPwarnings )
		{
			cout << "EasyBMP Error: " << FileName
				<< " has a non-positive width or height." << endl;
		}
		setSize(1,1);
		setBitDepth(1);
		fclose(fp);
		return false;
	}
	setSize( (int) bmih.biWidth , (int) bmih.biHeight );

	// some preliminaries

	double dBytesPerPixel = ( (double) BitDepth ) / 8.0;
	double dBytesPerRow = dBytesPerPixel * (Width+0.0);
	dBytesPerRow = ceil(dBytesPerRow);

	int BytePaddingPerRow = 4 - ( (int) (dBytesPerRow) )% 4;
	if( BytePaddingPerRow == 4 )
	{ BytePaddingPerRow = 0; }

	// if < 16 bits, read the palette

	if( BitDepth < 16 )
	{
		// determine the number of colors specified in the
		// color table

		int NumberOfColorsToRead = ((int) bmfh.bfOffBits - 54 )/4;
		if( NumberOfColorsToRead > IntPow(2,BitDepth) )
		{ NumberOfColorsToRead = IntPow(2,BitDepth); }

		if( NumberOfColorsToRead < tellNumberOfColors() )
		{
			if( EasyBMPwarnings )
			{
				cout << "EasyBMP Warning: file " << FileName << " has an underspecified" << endl
					<< "				 color table. The table will be padded with extra" << endl
					<< "				 white (255,255,255,0) entries." << endl;
			}
		}

		int n;
		for( n=0; n < NumberOfColorsToRead ; n++ )
		{
			SafeFread( (char*) &(Colors[n]) , 4 , 1 , fp);	
		}
		for( n=NumberOfColorsToRead ; n < tellNumberOfColors() ; n++ )
		{
			RGBApixel WHITE;
			WHITE.Red = 255;
			WHITE.Green = 255;
			WHITE.Blue = 255;
			WHITE.Alpha = 0;
			setColor( n , WHITE );
		}


	}

	// skip blank data if bfOffBits so indicates

	int BytesToSkip = bmfh.bfOffBits - 54;;
	if( BitDepth < 16 )
	{ BytesToSkip -= 4*IntPow(2,BitDepth); }
	if( BitDepth == 16 && bmih.biCompression == 3 )
	{ BytesToSkip -= 3*4; }
	if( BytesToSkip < 0 )
	{ BytesToSkip = 0; }
	if( BytesToSkip > 0 && BitDepth != 16 )
	{
		if( EasyBMPwarnings )
		{
			cout << "EasyBMP Warning: Extra meta data detected in file " << FileName << endl
				<< "				 Data will be skipped." << endl;
		}
		uint8_t* TempSkipBYTE;
		TempSkipBYTE = new uint8_t [BytesToSkip];
		SafeFread( (char*) TempSkipBYTE , BytesToSkip , 1 , fp);
		delete [] TempSkipBYTE;
	}

	// This code reads 1, 4, 8, 24, and 32-bpp files
	// with a more-efficient buffered technique.

	int i,j;
	if( BitDepth != 16 )
	{
		int BufferSize = (int) ( (Width*BitDepth) / 8.0 );
		while( 8*BufferSize < Width*BitDepth )
		{ BufferSize++; }
		while( BufferSize % 4 )
		{ BufferSize++; }
		uint8_t* Buffer;
		Buffer = new uint8_t [BufferSize];
		j= Height-1;
		while( j > -1 )
		{
			int BytesRead = (int) fread( (char*) Buffer, 1, BufferSize, fp );
			if( BytesRead < BufferSize )
			{
				j = -1;
				if( EasyBMPwarnings )
				{
					cout << "EasyBMP Error: Could not read proper amount of data." << endl;
				}
			}
			else
			{
				bool Success = false;
				if( BitDepth == 1  )
				{ Success = Read1bitRow(  Buffer, BufferSize, j ); }
				if( BitDepth == 4  )
				{ Success = Read4bitRow(  Buffer, BufferSize, j ); }
				if( BitDepth == 8  )
				{ Success = Read8bitRow(  Buffer, BufferSize, j ); }
				if( BitDepth == 24 )
				{ Success = Read24bitRow( Buffer, BufferSize, j ); }
				if( BitDepth == 32 )
				{ Success = Read32bitRow( Buffer, BufferSize, j ); }
				if( !Success )
				{
					if( EasyBMPwarnings )
					{
						cout << "EasyBMP Error: Could not read enough pixel data!" << endl;
					}
					j = -1;
				}
			}
			j--;
		}
		delete [] Buffer;
	}

	if( BitDepth == 16 )
	{
		int DataBytes = Width*2;
		int PaddingBytes = ( 4 - DataBytes % 4 ) % 4;

		// set the default mask

		uint16_t BlueMask = 31; // bits 12-16
		uint16_t GreenMask = 992; // bits 7-11
		uint16_t RedMask = 31744; // bits 2-6

		// read the bit fields, if necessary, to
		// override the default 5-5-5 mask

		if( bmih.biCompression != 0 )
		{
			// read the three bit masks

			uint16_t TempMaskWORD;

			SafeFread( (char*) &RedMask , 2 , 1 , fp );
			if( IsBigEndian() )
			{ RedMask = FlipWORD(RedMask); }
			SafeFread( (char*) &TempMaskWORD , 2, 1, fp );

			SafeFread( (char*) &GreenMask , 2 , 1 , fp );
			if( IsBigEndian() )
			{ GreenMask = FlipWORD(GreenMask); }
			SafeFread( (char*) &TempMaskWORD , 2, 1, fp );

			SafeFread( (char*) &BlueMask , 2 , 1 , fp );
			if( IsBigEndian() )
			{ BlueMask = FlipWORD(BlueMask); }
			SafeFread( (char*) &TempMaskWORD , 2, 1, fp );
		}

		// read and skip any meta data

		if( BytesToSkip > 0 )
		{
			if( EasyBMPwarnings )
			{
				cout << "EasyBMP Warning: Extra meta data detected in file "
					<< FileName << endl
					<< "				 Data will be skipped." << endl;
			}
			uint8_t* TempSkipBYTE;
			TempSkipBYTE = new uint8_t [BytesToSkip];
			SafeFread( (char*) TempSkipBYTE , BytesToSkip , 1 , fp);
			delete [] TempSkipBYTE;
		}

		// determine the red, green and blue shifts

		int GreenShift = 0;
		uint16_t TempShiftWORD = GreenMask;
		while( TempShiftWORD > 31 )
		{ TempShiftWORD = TempShiftWORD>>1; GreenShift++; }
		int BlueShift = 0;
		TempShiftWORD = BlueMask;
		while( TempShiftWORD > 31 )
		{ TempShiftWORD = TempShiftWORD>>1; BlueShift++; }
		int RedShift = 0;
		TempShiftWORD = RedMask;
		while( TempShiftWORD > 31 )
		{ TempShiftWORD = TempShiftWORD>>1; RedShift++; }

		// read the actual pixels

		for( j=Height-1 ; j >= 0 ; j-- )
		{
			i=0;
			int ReadNumber = 0;
			while( ReadNumber < DataBytes )
			{
				uint16_t TempWORD;
				SafeFread( (char*) &TempWORD , 2 , 1 , fp );
				if( IsBigEndian() )
				{ TempWORD = FlipWORD(TempWORD); }
				ReadNumber += 2;

				uint16_t Red = RedMask & TempWORD;
				uint16_t Green = GreenMask & TempWORD;
				uint16_t Blue = BlueMask & TempWORD;

				uint8_t BlueBYTE = (uint8_t) 8*(Blue>>BlueShift);
				uint8_t GreenBYTE = (uint8_t) 8*(Green>>GreenShift);
				uint8_t RedBYTE = (uint8_t) 8*(Red>>RedShift);

				(Pixels(i,j)).Red = RedBYTE;
				(Pixels(i,j)).Green = GreenBYTE;
				(Pixels(i,j)).Blue = BlueBYTE;

				i++;
			}
			ReadNumber = 0;
			while( ReadNumber < PaddingBytes )
			{
				uint8_t TempBYTE;
				SafeFread( (char*) &TempBYTE , 1, 1, fp);
				ReadNumber++;
			}
		}

	}

	fclose(fp);
	return true;
}

bool BMP::createStandardColorTable( void )
{
	using namespace std;
	if( BitDepth != 1 && BitDepth != 4 && BitDepth != 8 )
	{
		if( EasyBMPwarnings )
		{
			cout << "EasyBMP Warning: Attempted to create color table at a bit" << endl
				<< "				 depth that does not require a color table." << endl
				<< "				 Ignoring request." << endl;
		}
		return false;
	}

	if( BitDepth == 1 )
	{
		int i;
		for( i=0 ; i < 2 ; i++ )
		{
			Colors[i].Red = i*255;
			Colors[i].Green = i*255;
			Colors[i].Blue = i*255;
			Colors[i].Alpha = 0;
		}
		return true;
	}

	if( BitDepth == 4 )
	{
		int i = 0;
		int j,k,ell;

		// simplify the code for the first 8 colors
		for( ell=0 ; ell < 2 ; ell++ )
		{
			for( k=0 ; k < 2 ; k++ )
			{
				for( j=0 ; j < 2 ; j++ )
				{
					Colors[i].Red = j*128;
					Colors[i].Green = k*128;
					Colors[i].Blue = ell*128;
					i++;
				}
			}
		}

		// simplify the code for the last 8 colors
		for( ell=0 ; ell < 2 ; ell++ )
		{
			for( k=0 ; k < 2 ; k++ )
			{
				for( j=0 ; j < 2 ; j++ )
				{
					Colors[i].Red = j*255;
					Colors[i].Green = k*255;
					Colors[i].Blue = ell*255;
					i++;
				}
			}
		}

		// overwrite the duplicate color
		i=8;
		Colors[i].Red = 192;
		Colors[i].Green = 192;
		Colors[i].Blue = 192;

		for( i=0 ; i < 16 ; i++ )
		{ Colors[i].Alpha = 0; }
		return true;
	}

	if( BitDepth == 8 )
	{
		int i=0;
		int j,k,ell;

		// do an easy loop, which works for all but colors
		// 0 to 9 and 246 to 255
		for( ell=0 ; ell < 4 ; ell++ )
		{
			for( k=0 ; k < 8 ; k++ )
			{
				for( j=0; j < 8 ; j++ )
				{
					Colors[i].Red = j*32;
					Colors[i].Green = k*32;
					Colors[i].Blue = ell*64;
					Colors[i].Alpha = 0;
					i++;
				}
			}
		}

		// now redo the first 8 colors
		i=0;
		for( ell=0 ; ell < 2 ; ell++ )
		{
			for( k=0 ; k < 2 ; k++ )
			{
				for( j=0; j < 2 ; j++ )
				{
					Colors[i].Red = j*128;
					Colors[i].Green = k*128;
					Colors[i].Blue = ell*128;
					i++;
				}
			}
		}

		// overwrite colors 7, 8, 9
		i=7;
		Colors[i].Red = 192;
		Colors[i].Green = 192;
		Colors[i].Blue = 192;
		i++; // 8
		Colors[i].Red = 192;
		Colors[i].Green = 220;
		Colors[i].Blue = 192;
		i++; // 9
		Colors[i].Red = 166;
		Colors[i].Green = 202;
		Colors[i].Blue = 240;

		// overwrite colors 246 to 255
		i=246;
		Colors[i].Red = 255;
		Colors[i].Green = 251;
		Colors[i].Blue = 240;
		i++; // 247
		Colors[i].Red = 160;
		Colors[i].Green = 160;
		Colors[i].Blue = 164;
		i++; // 248
		Colors[i].Red = 128;
		Colors[i].Green = 128;
		Colors[i].Blue = 128;
		i++; // 249
		Colors[i].Red = 255;
		Colors[i].Green = 0;
		Colors[i].Blue = 0;
		i++; // 250
		Colors[i].Red = 0;
		Colors[i].Green = 255;
		Colors[i].Blue = 0;
		i++; // 251
		Colors[i].Red = 255;
		Colors[i].Green = 255;
		Colors[i].Blue = 0;
		i++; // 252
		Colors[i].Red = 0;
		Colors[i].Green = 0;
		Colors[i].Blue = 255;
		i++; // 253
		Colors[i].Red = 255;
		Colors[i].Green = 0;
		Colors[i].Blue = 255;
		i++; // 254
		Colors[i].Red = 0;
		Colors[i].Green = 255;
		Colors[i].Blue = 255;
		i++; // 255
		Colors[i].Red = 255;
		Colors[i].Green = 255;
		Colors[i].Blue = 255;

		return true;
	}
	return true;
}

bool SafeFread( char* buffer, int size, int number, FILE* fp )
{
	using namespace std;
	int BytesRead;
	if( feof(fp) )
	{ return false; }
	BytesRead = (int) fread( buffer , size , number , fp );
	if( BytesRead < number )
	{ return false; }
	return true;
}

void BMP::setDPI( int HorizontalDPI, int VerticalDPI )
{
	XPelsPerMeter = (int) ( HorizontalDPI * 39.37007874015748 );
	YPelsPerMeter = (int) (   VerticalDPI * 39.37007874015748 );
}

int BMP::tellVerticalDPI( void ) const
{
	// Below code replaced to keep function const-correct.
	// This is somewhat hackish.
	// Ideally, YPelsPerMeter should never be 0 -- it should be set
	// to the default immediately upon BMP creation if needed.
	//if( !YPelsPerMeter )
	//{ YPelsPerMeter = DefaultYPelsPerMeter; }
	//return (int) ( YPelsPerMeter / (double) 39.37007874015748 );

	int YPPM = YPelsPerMeter;
	if (!YPPM)
		YPPM = DefaultYPelsPerMeter;
	return (int) (YPPM / (double) 39.37007874015748);
}
int BMP::tellHorizontalDPI( void ) const
{
	// See comment in tellVerticalDPI().
	//if( !XPelsPerMeter )
	//{ XPelsPerMeter = DefaultXPelsPerMeter; }
	//return (int) ( XPelsPerMeter / (double) 39.37007874015748 );

	int XPPM = XPelsPerMeter;
	if (!XPPM)
		XPPM = DefaultXPelsPerMeter;
	return (int) (XPPM / (double) 39.37007874015748);
}

/* These functions are defined in EasyBMP_VariousBMPutilities.h */

BMFH GetBMFH( const char* szFileNameIn )
{
	using namespace std;
	BMFH bmfh;

	FILE* fp;
	fp = fopen( szFileNameIn,"rb");

	if( !fp  )
	{
		if( EasyBMPwarnings )
		{
			cout << "EasyBMP Error: Cannot initialize from file "
				<< szFileNameIn << "." << endl
				<< "			   File cannot be opened or does not exist."
				<< endl;
		}
		bmfh.bfType = 0;
		return bmfh;
	}

	SafeFread( (char*) &(bmfh.bfType) , sizeof(uint16_t) , 1 , fp );
	SafeFread( (char*) &(bmfh.bfSize) , sizeof(uint32_t) , 1 , fp );
	SafeFread( (char*) &(bmfh.bfReserved1) , sizeof(uint16_t) , 1 , fp );
	SafeFread( (char*) &(bmfh.bfReserved2) , sizeof(uint16_t) , 1 , fp );
	SafeFread( (char*) &(bmfh.bfOffBits) , sizeof(uint32_t) , 1 , fp );

	fclose( fp );

	if( IsBigEndian() )
	{ bmfh.SwitchEndianess(); }

	return bmfh;
}

BMIH GetBMIH( const char* szFileNameIn )
{
	using namespace std;
	BMFH bmfh;
	BMIH bmih;

	FILE* fp;
	fp = fopen( szFileNameIn,"rb");

	if( !fp  )
	{
		if( EasyBMPwarnings )
		{
			cout << "EasyBMP Error: Cannot initialize from file "
				<< szFileNameIn << "." << endl
				<< "			   File cannot be opened or does not exist."
				<< endl;
		}
		return bmih;
	}

	// read the bmfh, i.e., first 14 bytes (just to get it out of the way);

	uint8_t TempBYTE;
	int i;
	for( i = 14 ; i > 0 ; i-- )
	{ SafeFread( (char*) &TempBYTE , sizeof(uint8_t) , 1, fp ); }

	// read the bmih

	SafeFread( (char*) &(bmih.biSize) , sizeof(uint32_t) , 1 , fp );
	SafeFread( (char*) &(bmih.biWidth) , sizeof(uint32_t) , 1 , fp );
	SafeFread( (char*) &(bmih.biHeight) , sizeof(uint32_t) , 1 , fp );
	SafeFread( (char*) &(bmih.biPlanes) , sizeof(uint16_t) , 1 , fp );

	SafeFread( (char*) &(bmih.biBitCount) , sizeof(uint16_t) , 1 , fp );
	SafeFread( (char*) &(bmih.biCompression) , sizeof(uint32_t) , 1 , fp );
	SafeFread( (char*) &(bmih.biSizeImage) , sizeof(uint32_t) , 1 , fp );
	SafeFread( (char*) &(bmih.biXPelsPerMeter) , sizeof(uint32_t) , 1 , fp );

	SafeFread( (char*) &(bmih.biYPelsPerMeter) , sizeof(uint32_t) , 1 , fp );
	SafeFread( (char*) &(bmih.biClrUsed) , sizeof(uint32_t) , 1 , fp );
	SafeFread( (char*) &(bmih.biClrImportant) , sizeof(uint32_t) , 1 , fp );

	fclose( fp );

	if( IsBigEndian() )
	{ bmih.SwitchEndianess(); }

	return bmih;
}

void DisplayBitmapInfo( const char* szFileNameIn )
{
	using namespace std;
	FILE* fp;
	fp = fopen( szFileNameIn,"rb");

	if( !fp  )
	{
		if( EasyBMPwarnings )
		{
			cout << "EasyBMP Error: Cannot initialize from file "
				<< szFileNameIn << "." << endl
				<< "			   File cannot be opened or does not exist."
				<< endl;
		}
		return;
	}
	fclose( fp );

	// don't duplicate work! Just use the functions from above!

	BMFH bmfh = GetBMFH(szFileNameIn);
	BMIH bmih = GetBMIH(szFileNameIn);

	cout << "File information for file " << szFileNameIn
		<< ":" << endl << endl;

	cout << "BITMAPFILEHEADER:" << endl
		<< "bfType: " << bmfh.bfType << endl
		<< "bfSize: " << bmfh.bfSize << endl
		<< "bfReserved1: " << bmfh.bfReserved1 << endl
		<< "bfReserved2: " << bmfh.bfReserved2 << endl	
		<< "bfOffBits: " << bmfh.bfOffBits << endl << endl;

	cout << "BITMAPINFOHEADER:" << endl
		<< "biSize: " << bmih.biSize << endl
		<< "biWidth: " << bmih.biWidth << endl
		<< "biHeight: " << bmih.biHeight << endl
		<< "biPlanes: " << bmih.biPlanes << endl
		<< "biBitCount: " << bmih.biBitCount << endl
		<< "biCompression: " << bmih.biCompression << endl
		<< "biSizeImage: " << bmih.biSizeImage << endl
		<< "biXPelsPerMeter: " << bmih.biXPelsPerMeter << endl
		<< "biYPelsPerMeter: " << bmih.biYPelsPerMeter << endl
		<< "biClrUsed: " << bmih.biClrUsed << endl
		<< "biClrImportant: " << bmih.biClrImportant << endl << endl;
	return;
}

int GetBitmapColorDepth( const char* szFileNameIn )
{
	BMIH bmih = GetBMIH( szFileNameIn );
	return (int) bmih.biBitCount;
}

void PixelToPixelCopy( BMP& From, int FromX, int FromY,
		BMP& To, int ToX, int ToY)
{
	*To(ToX,ToY) = *From(FromX,FromY);
	return;
}

void PixelToPixelCopyTransparent( BMP& From, int FromX, int FromY,
		BMP& To, int ToX, int ToY,
		RGBApixel& Transparent )
{
	if( From(FromX,FromY)->Red != Transparent.Red ||
			From(FromX,FromY)->Green != Transparent.Green ||
			From(FromX,FromY)->Blue != Transparent.Blue )	
	{ *To(ToX,ToY) = *From(FromX,FromY); }
	return;
}

void RangedPixelToPixelCopy( BMP& From, int FromL , int FromR, int FromB, int FromT,
		BMP& To, int ToX, int ToY )
{
	// make sure the conventions are followed
	if( FromB < FromT )
	{ int Temp = FromT; FromT = FromB; FromB = Temp; }

	// make sure that the copied regions exist in both bitmaps
	if( FromR >= From.tellWidth() )
	{ FromR = From.tellWidth()-1; }
	if( FromL < 0 ){ FromL = 0; }

	if( FromB >= From.tellHeight() )
	{ FromB = From.tellHeight()-1; }
	if( FromT < 0 ){ FromT = 0; }

	if( ToX+(FromR-FromL) >= To.tellWidth() )
	{ FromR = To.tellWidth()-1+FromL-ToX; }
	if( ToY+(FromB-FromT) >= To.tellHeight() )
	{ FromB = To.tellHeight()-1+FromT-ToY; }

	int i,j;
	for( j=FromT ; j <= FromB ; j++ )
	{
		for( i=FromL ; i <= FromR ; i++ )
		{
			PixelToPixelCopy( From, i,j,
					To, ToX+(i-FromL), ToY+(j-FromT) );
		}
	}

	return;
}

void RangedPixelToPixelCopyTransparent(
		BMP& From, int FromL , int FromR, int FromB, int FromT,
		BMP& To, int ToX, int ToY ,
		RGBApixel& Transparent )
{
	// make sure the conventions are followed
	if( FromB < FromT )
	{ int Temp = FromT; FromT = FromB; FromB = Temp; }

	// make sure that the copied regions exist in both bitmaps
	if( FromR >= From.tellWidth() )
	{ FromR = From.tellWidth()-1; }
	if( FromL < 0 ){ FromL = 0; }

	if( FromB >= From.tellHeight() )
	{ FromB = From.tellHeight()-1; }
	if( FromT < 0 ){ FromT = 0; }

	if( ToX+(FromR-FromL) >= To.tellWidth() )
	{ FromR = To.tellWidth()-1+FromL-ToX; }
	if( ToY+(FromB-FromT) >= To.tellHeight() )
	{ FromB = To.tellHeight()-1+FromT-ToY; }

	int i,j;
	for( j=FromT ; j <= FromB ; j++ )
	{
		for( i=FromL ; i <= FromR ; i++ )
		{
			PixelToPixelCopyTransparent( From, i,j,
					To, ToX+(i-FromL), ToY+(j-FromT) ,
					Transparent);
		}
	}

	return;
}
bool BMP::CreateGrayscaleColorTable()
{
	using namespace std;
	BMP & InputImage = *this;

	int localBitDepth = InputImage.tellBitDepth();
	if( localBitDepth != 1 && localBitDepth != 4 && localBitDepth != 8 )
	{
		if( EasyBMPwarnings )
		{
			cout << "EasyBMP Warning: Attempted to create color table at a bit" << endl
				<< "				 depth that does not require a color table." << endl
				<< "				 Ignoring request." << endl;
		}
		return false;
	}
	int i;
	int NumberOfColors = InputImage.tellNumberOfColors();

	uint8_t StepSize;
	if( localBitDepth != 1 )
	{ StepSize = 255/(NumberOfColors-1); }
	else
	{ StepSize = 255; }

	for( i=0 ; i < NumberOfColors ; i++ )
	{
		uint8_t TempBYTE = i*StepSize;
		RGBApixel TempColor;
		TempColor.Red = TempBYTE;
		TempColor.Green = TempBYTE;
		TempColor.Blue = TempBYTE;
		TempColor.Alpha = 0;
		InputImage.setColor( i , TempColor );
	}
	return true;
}

bool BMP::Read32bitRow( uint8_t* Buffer, int BufferSize, int Row )
{
	int i;
	if( Width*4 > BufferSize )
	{ return false; }
	for( i=0 ; i < Width ; i++ )
	{ memcpy( (char*) &(Pixels(i,Row)), (char*) Buffer+4*i, 4 ); }
	return true;
}

bool BMP::Read24bitRow( uint8_t* Buffer, int BufferSize, int Row )
{
	int i;
	if( Width*3 > BufferSize )
	{ return false; }
	for( i=0 ; i < Width ; i++ )
	{ memcpy( (char*) &(Pixels(i,Row)), Buffer+3*i, 3 ); }
	return true;
}

bool BMP::Read8bitRow(  uint8_t* Buffer, int BufferSize, int Row )
{
	int i;
	if( Width > BufferSize )
	{ return false; }
	for( i=0 ; i < Width ; i++ )
	{
		int Index = Buffer[i];
		*( this->operator()(i,Row) )= getColor(Index);
	}
	return true;
}

bool BMP::Read4bitRow(  uint8_t* Buffer, int BufferSize, int Row )
{
	int Shifts[2] = {4  ,0 };
	int Masks[2]  = {240,15};

	int i=0;
	int j;
	int k=0;
	if( Width > 2*BufferSize )
	{ return false; }
	while( i < Width )
	{
		j=0;
		while( j < 2 && i < Width )
		{
			int Index = (int) ( (Buffer[k]&Masks[j]) >> Shifts[j]);
			*( this->operator()(i,Row) )= getColor(Index);
			i++; j++;
		}
		k++;
	}
	return true;
}
bool BMP::Read1bitRow(  uint8_t* Buffer, int BufferSize, int Row )
{
	int Shifts[8] = {7  ,6 ,5 ,4 ,3,2,1,0};
	int Masks[8]  = {128,64,32,16,8,4,2,1};

	int i=0;
	int j;
	int k=0;

	if( Width > 8*BufferSize )
	{ return false; }
	while( i < Width )
	{
		j=0;
		while( j < 8 && i < Width )
		{
			int Index = (int) ( (Buffer[k]&Masks[j]) >> Shifts[j]);
			*( this->operator()(i,Row) )= getColor(Index);
			i++; j++;
		}
		k++;
	}
	return true;
}

bool BMP::Write32bitRow( uint8_t* Buffer, int BufferSize, int Row ) const
{
	int i;
	if( Width*4 > BufferSize )
	{ return false; }
	for( i=0 ; i < Width ; i++ )
	{ memcpy( (char*) Buffer+4*i, (char*) &(Pixels(i,Row)), 4 ); }
	return true;
}

bool BMP::Write24bitRow( uint8_t* Buffer, int BufferSize, int Row ) const
{
	int i;
	if( Width*3 > BufferSize )
	{ return false; }
	for( i=0 ; i < Width ; i++ )
	{ memcpy( (char*) Buffer+3*i,  (char*) &(Pixels(i,Row)), 3 ); }
	return true;
}

bool BMP::Write8bitRow(  uint8_t* Buffer, int BufferSize, int Row ) const
{
	int i;
	if( Width > BufferSize )
	{ return false; }
	for( i=0 ; i < Width ; i++ )
	{ Buffer[i] = FindClosestColor( Pixels(i,Row) ); }
	return true;
}

bool BMP::Write4bitRow(  uint8_t* Buffer, int BufferSize, int Row ) const
{
	int PositionWeights[2]  = {16,1};

	int i=0;
	int j;
	int k=0;
	if( Width > 2*BufferSize )
	{ return false; }
	while( i < Width )
	{
		j=0;
		int Index = 0;
		while( j < 2 && i < Width )
		{
			Index += ( PositionWeights[j]* (int) FindClosestColor( Pixels(i,Row) ) );
			i++; j++;
		}
		Buffer[k] = (uint8_t) Index;
		k++;
	}
	return true;
}

bool BMP::Write1bitRow(  uint8_t* Buffer, int BufferSize, int Row ) const
{
	int PositionWeights[8]  = {128,64,32,16,8,4,2,1};

	int i=0;
	int j;
	int k=0;
	if( Width > 8*BufferSize )
	{ return false; }
	while( i < Width )
	{
		j=0;
		int Index = 0;
		while( j < 8 && i < Width )
		{
			Index += ( PositionWeights[j]* (int) FindClosestColor( Pixels(i,Row) ) );
			i++; j++;
		}
		Buffer[k] = (uint8_t) Index;
		k++;
	}
	return true;
}

uint8_t BMP::FindClosestColor( RGBApixel const & input ) const
{
	using namespace std;

	int i=0;
	int NumberOfColors = tellNumberOfColors();
	uint8_t BestI = 0;
	int BestMatch = 999999;

	while( i < NumberOfColors )
	{
		RGBApixel Attempt = getColor( i );
		int TempMatch = IntSquare( (int) Attempt.Red - (int) input.Red )
			+ IntSquare( (int) Attempt.Green - (int) input.Green )
			+ IntSquare( (int) Attempt.Blue - (int) input.Blue );
		if( TempMatch < BestMatch )
		{ BestI = (uint8_t) i; BestMatch = TempMatch; }
		if( BestMatch < 1 )
		{ i = NumberOfColors; }
		i++;
	}
	return BestI;
}

bool EasyBMPcheckDataSize( void )
{
	using namespace std;
	bool ReturnValue = true;
	if( sizeof( uint8_t ) != 1 )
	{
		if( EasyBMPwarnings )
		{
			cout << "EasyBMP Error: uint8_t has the wrong size ("
				<< sizeof( uint8_t ) << " bytes)," << endl
				<< "			   Compared to the expected 1 byte value" << endl;
		}
		ReturnValue = false;
	}
	if( sizeof( uint16_t ) != 2 )
	{
		if( EasyBMPwarnings )
		{
			cout << "EasyBMP Error: uint16_t has the wrong size ("
				<< sizeof( uint16_t ) << " bytes)," << endl
				<< "			   Compared to the expected 2 byte value" << endl;
		}
		ReturnValue = false;
	}
	if( sizeof( uint32_t ) != 4 )
	{
		if( EasyBMPwarnings )
		{
			cout << "EasyBMP Error: uint32_t has the wrong size ("
				<< sizeof( uint32_t ) << " bytes)," << endl
				<< "			   Compared to the expected 4 byte value" << endl;
		}
		ReturnValue = false;
	}
	return ReturnValue;
}

/**********************************************************
 * testscene.cpp -- part of CS225 MP2
 *
 * This file performs some basic tests of the Scene class.
 * It is not intended to catch every possible error.You may 
 * modifty this or write your own testscene.cpp to perform 
 * additional tests.
 *
 *   Author: Jonathan Ray
 *   Date: 02 Feb 2007
 */

#include "scene.h"

int main()
{
	Scene* set = new Scene(5);
	set->addpicture("in_01.bmp", 0, 0, 0);
  cout<<"lalalalalalllllllllllllll"<<endl;
	set->addpicture("in_02.bmp", 1, 60, 60);
	set->addpicture("in_03.bmp", 2, 150, 0);
  cout<<"lalalalalalllllllllllllll"<<endl;
	Image result = set->drawscene();
	result.writeToFile("scene.bmp");	
  cout<<"lalalalalalllllllllllllll"<<endl;

	set->changelayer(1, 3);
	result = set->drawscene();
	result.writeToFile("scene2.bmp");

	set->translate(0, 50, 50);
	result = set->drawscene();
	result.writeToFile("scene3.bmp");

	set->getpicture(0)->adjustbrightness(-70,-70,-70);
	result = set->drawscene();
	result.writeToFile("scene4.bmp");

	set->deletepicture(3);
	result = set->drawscene();
	result.writeToFile("scene5.bmp");

	Scene* sc = new Scene(*set);
	sc->getpicture(0)->flipleft();
	result = set->drawscene();
	result.writeToFile("scene6.bmp");  //scene 5 and scene 6 should be the same
	result = sc->drawscene();
	result.writeToFile("scene7.bmp");

	delete set;
	set = new Scene(5);
	*set = *sc;
	result = set->drawscene();
	result.writeToFile("scene8.bmp");   //scene7 and scene8 should be the same.
	delete set;
	delete sc;

	return 0;
}


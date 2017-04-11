/*
	The custom gpsMATH.h library was developed to execute an algorithm that calculates the azimuth and
	elevation angles of a target with respect to a base station. These angles can be used to control two 
	servo motors for pan/tilt operation. This example program displays all of the public functions 
	available in the gpsMATH library.

	The program begins by passing sample gps coordinates using the setBase and setTarg functions. Next, 
	the latitude, longitude, and altitude are trasferred to their respective x, y, and z Cartesian 
	equivalents in meters. A difference vector is then defined using the East, North, Up coordinate 
	system that is found from the product of the Cartesian differences and a rotation matrice. The pan 
	angle with respect to the y-axis (North) and tilt angle with respect to the xy-plane (East-North) 
	is then calculated in degrees using the arctangent (atan2) formula.
	
	Copyright (C) 2017 Jonathan Rasch
	All rights reserved.

	This sketch is free software; you can redistribute it and/or modify it under the terms of the GNU 
	Lesser General Public License as published by the Free Software Foundation; either version 2.1 of 
	the License, or (at your option) any later version.

	This sketch is distributed in the hope that it will be useful,but WITHOUT ANY WARRANTY; without
	even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
	Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General Public License along with this library; if
	not, write to the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include "gpsMath.h"

// Create the gpsMath object
gpsMath gpsM;

// Declare the signed variables that will hold the latitude, longitude, and altitude coordinates
double bLat, bLon, bAlt, tLat, tLon, tAlt;

void setup()
{
	Serial.begin(9600);

	Serial.println(F("gpsMathTest.ino"));
	Serial.println(F("Jonathan Rasch - 2017"));
	Serial.println(F("A basic demonstration of gpsMath using random coordinates..."));
	Serial.println(F(" "));

// Random GPS coordinates for base station
	bLat = 30.40990; bLon = -86.608582; bAlt = 4.0;

// Random GPS coordinates for target
	tLat = 30.409701; tLon = -86.608063; tAlt = 64.0;   

// Set the coordinates and print them to the terminal
	gpsM.setBase(bLat, bLon, bAlt);
	gpsM.setTarg(tLat, tLon, tAlt);

// Print the result of each public function to the serial monitor 
	Serial.println(F("The Cartesian x, y, and z coordinates for the base station are: "));
	Serial.println(gpsM.bConvertX());
	Serial.println(gpsM.bConvertY());
	Serial.println(gpsM.bConvertZ());
	Serial.println(F(" "));
	Serial.println(F("The Cartesian x, y, and z coordinates for the target are: "));
	Serial.println(gpsM.tConvertX());
	Serial.println(gpsM.tConvertY());
	Serial.println(gpsM.tConvertZ());
	Serial.println(F(" "));
	Serial.println(F("The following east, north, up coordinates define a difference vector from target to base: "));
	Serial.println(gpsM.xEAST());
	Serial.println(gpsM.yNORTH());
	Serial.println(gpsM.zUP());
	Serial.println(F(" "));
	Serial.println(F("The azimuth angle with respect to the y-north axis is (positive clockwise): "));
	Serial.println(gpsM.azimuth());
	Serial.println(F(" "));
	Serial.println(F("The elevation angle with respect to the x-east/y-north plane is: "));
	Serial.println(gpsM.elevation());
}

void loop()
{

}
/*
	gpsMath - a small GPS library for Arduino to transfer geodetic coordinates of a
	target and base station to east-north-up azimuth and elevation angles.
	Copyright (C) 2017 Jonathan Rasch
	All rights reserved.

	This library is free software; you can redistribute it and/or
	modify it under the terms of the GNU Lesser General Public
	License as published by the Free Software Foundation; either
	version 2.1 of the License, or (at your option) any later version.

	This library is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
	Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General Public
	License along with this library; if not, write to the Free Software
	Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

// gpsMath.h

#ifndef _GPSMATH_h
#define _GPSMATH_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#define _SEMI_MAJOR_AXIS 6378137
#define _FIRST_ECCENTRICITY_SQUARED 0.00669437990

class gpsMath
{
public:
	void setBase(double bLat, double bLon, double bAlt);
	void setTarg(double tLat, double tLon, double tAlt);
	double bConvertX();
	double bConvertY();
	double bConvertZ();
	double tConvertX();
	double tConvertY();
	double tConvertZ();
	double xEAST();
	double yNORTH();
	double zUP();
	double azimuth();
	double elevation();

private:
	double bLenNormal();
	double tLenNormal();
	double deltaX() { return ( tConvertX() - bConvertX() ); }
	double deltaY() { return ( tConvertY() - bConvertY() ); }
	double deltaZ() { return ( tConvertZ() - bConvertZ() ); }
	double _bLat{ 0 }, _bLon{ 0 }, _bHi{ 0 }, _tLat{ 0 }, _tLon{ 0 }, _tHi{ 0 };

};

#endif


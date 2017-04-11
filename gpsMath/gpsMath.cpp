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

#include "gpsMath.h"

double gpsMath::bLenNormal(void)
{
	return _SEMI_MAJOR_AXIS / sqrt( 1 - ( _FIRST_ECCENTRICITY_SQUARED * sin(_bLat) * sin(_bLat) ) );
}

double gpsMath::bConvertX(void)
{
	return ( bLenNormal() + _bHi ) * cos(_bLat) * cos(_bLon);
}

double gpsMath::bConvertY(void)
{
	return ( bLenNormal() + _bHi ) * cos(_bLat) * sin(_bLon);
}

double gpsMath::bConvertZ(void)
{
	return ( ( bLenNormal() * ( 1 - _FIRST_ECCENTRICITY_SQUARED ) ) + _bHi ) * sin(_bLat);
}

double gpsMath::tConvertX(void)
{
	return ( tLenNormal() + _bHi ) * cos(_tLat) * cos(_tLon);
}

double gpsMath::tConvertY(void)
{
	return ( tLenNormal() + _tHi ) * cos(_tLat) * sin(_tLon);
}

double gpsMath::tConvertZ(void)
{
	return ( ( tLenNormal() * ( 1 - _FIRST_ECCENTRICITY_SQUARED ) ) + _tHi ) * sin(_tLat);
}

double gpsMath::tLenNormal(void)
{
	return _SEMI_MAJOR_AXIS / sqrt( 1 - ( _FIRST_ECCENTRICITY_SQUARED * sin(_tLat) * sin(_tLat) ) );
}

double gpsMath::xEAST(void)
{
	return -deltaX() * sin(_bLon) + deltaY() * cos(_bLon);
}

double gpsMath::yNORTH(void)
{
	return -deltaX() * sin(_bLat) * cos(_bLon) - deltaY() * sin(_bLat) * sin(_bLon) + deltaZ() * cos(_bLat);
}

double gpsMath::zUP(void)
{
	return deltaX() * cos(_bLat) * cos(_bLon) + deltaY() * cos(_bLat) * sin(_bLon) + deltaZ() * sin(_bLat);
}

double gpsMath::azimuth(void)
{
	double radAz{ atan2( xEAST(), yNORTH() ) };
	return radAz * RAD_TO_DEG;
}

double gpsMath::elevation(void)
{
	double radElv{ atan2( zUP(), sqrt( xEAST() * xEAST() + yNORTH() * yNORTH() ) ) };
	return radElv * RAD_TO_DEG;
}

void gpsMath::setBase(double bLat, double bLon, double bAlt)
{
	_bLat = bLat * DEG_TO_RAD; 
	_bLon = bLon * DEG_TO_RAD; 
	_bHi = bAlt;
}

void gpsMath::setTarg(double tLat, double tLon, double tAlt)
{
	_tLat = tLat * DEG_TO_RAD;
	_tLon = tLon * DEG_TO_RAD;
	_tHi = tAlt;
}

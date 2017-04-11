# Master
gpsMath

The gpsMath library offers the capability to calculate the azimuth and elevation angles of a target with respect to a base station. 

GPS latitude, longitude, and altitude coordinates for the base and target are set by the user, or the results of a GPS library can continuously feed the object variables. These coordinates are converted into their equivalent x, y, and z Cartesian values in meters. The product of their difference and a rotation matrix results in a position vector in the East, North, Up coordinate system.  

These coordinates are fed into the atan2 function to yield the azimuth angle with respect to the y-North axis, as well as the elevation angle with respect to the x-East/y-North plane. Angles are given in degrees with a positive clockwise direction.

The purpose of this library is to calculate the angles needed to direct a base station antenna toward a target. Arduino's servo.h library can be used with the map function to map the servo's pulse width modulation (pwm) value to an angle in degrees. The initial heading of the antenna must be north in order for the angles to return a valid position. In other words, a neutral pwm should direct the antenna toward the y-north axis, and the antenna should be parallel with the x-east/y-north plane. Note that the atan2 function returns values constrained from -180 to +180 degrees.

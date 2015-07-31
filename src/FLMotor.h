/*Copyright (c) 2015 Frightening Lightning. All rights reserved.


 Developed by: Michael Hulet
               https://github.com/raysarebest


See the project LICENSE file (https://github.com/EastRobotics/Lightning/blob/master/LICENSE)
for the full license of this file.

The above copyright notice and this permission notice shall be included in all copies or
substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
CONTRIBUTORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
WITH THE SOFTWARE.*/

//Prevent programmers from trying to use this on unsupported platforms
#if defined(__LIGHTNING_UNSUPPORTED__) && (!defined(VEX) || !defined(VEX2) || !defined(VexIQ))
#define __LIGHTNING_UNSUPPORTED__
#ifndef LIGHTNING_UNSUPPORTED_WARNING
#error "Lightning is only designed to function on VEX platforms"
#else
#warning "Lightning is only designed to function on VEX platforms"
#endif
#else

//Make sure this file is only #included once
#pragma once
//Silence any "Unreference function/variable warnings
#pragma systemFile
//Import other used parts of this framework
#include "FLObject.h"

//Make conditional #including of FLObject possible
#ifndef __FLMOTOR_H__
#define __FLMOTOR_H__

//FLMotor -- The general Lightning object representation of a motor
typedef struct _FLMotor{
	//FLMotor inherits directly from FLObject
	FLObject super;
	tMotor port;
}FLMotor;

//FLMotorSpeed -- Enumeration to define commonly-used motor speeds
typedef enum _FLMotorSpeed{
	//To stop is to not move. Duh.
 FLMotorSpeedStop = 0,
 //If you wanna stall the motors, it's safe to put it at a speed of 30, but that's about the lowest it's safe to go
 FLMotorSpeedStall = 30,
 //31 is about the minimum speed you can assign to a motor before it begins to twitch
 FLMotorSpeedMin = 31,
 //While a true half is 63.5, we're defining integer constants here, so we'll give it the high end
 FLMotorSpeedHalf = 64,
 //For some reason, the maximum possible power for a VEX motor is 127. Don't ask me why.
 FLMotorSpeedMax = 127
}FLMotorSpeed;

//MARK: - Function Declarations

//FLMotor designated initializer -- Returns a pointer to an FLMotor
FLMotor *motorForPort(tMotor port);
//Getter for super property
FLObject *getSuperOfMotor(FLMotor *engine);
//Gettor for port pportrty
tMotor getPortOfMotor(FLMotor *engine);
//Setter for speed property
void setSpeedOfMotor(FLMotor *engine, int speed);
//Getter for speed property
short getSpeedOfMotor(FLMotor *engine);

//MARK: - Function Definitions

FLMotor *motorForPort(tMotor port){
	//TODO: - Make sure a motor for a port can only be created once
	FLMotor new;
	FLObject *super = newObject();
	new.super = *super;
	new.port = port;
	return &new;
}

FLObject *getSuperOfMotor(FLMotor *engine){
	//Turn the normal reference into a pointer and hand it back
	return &engine->super;
}

tMotor getPortOfMotor(FLMotor *engine){
	return engine->port;
}

void setSpeedOfMotor(FLMotor *engine, int speed){
	//Make the physical motor turn at the specified speed
	motor[getPortOfMotor(engine)] = speed;
}

//Compatibility overload to silence any compiler warnings about typecasting
void setSpeedOfMotor(FLMotor *engine, FLMotorSpeed speed){
	setSpeedOfMotor(engine, (int)speed);
}

short getSpeedOfMotor(FLMotor *engine){
	//Return the speed of the physical motor
	return motor[getPortOfMotor(engine)];
}
#endif
#endif

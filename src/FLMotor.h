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

//MARK: - Function Declarations

//FLMotor designated initializer -- Returns a pointer to an FLMotor
FLMotor *newMotorWithPort();
//Getter for super property
FLObject *getSuperOfMotor(FLMotor *motor);
//Gettor for port property
tMotor getPortOfMotor(FLMotor *motor);

//MARK: - Function Definitions

FLMotor *newMotorWithPort(tMotor port){
	//TODO: - Make sure a motor for a port can only be created once
	FLMotor new;
	FLObject *super = newObject();
	new.super = *super;
	new.port = port;
	return &new;
}

FLObject *getSuperOfMotor(FLMotor *motor){
	//Turn the normal reference into a pointer and hand it back
	return &motor->super;
}

tMotor getPortOfMotor(FLMotor *motor){
	return motor->port;
}
#endif
#endif

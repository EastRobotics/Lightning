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

//Import other used parts of this framework
#ifndef MHOBJECT
#include "MHObject.h"
#endif

//Silence any unreferenced function/variable warnings
#pragma systemFile

//Make conditional #including of MHObject possible
#ifndef MHMOTOR
#define MHMOTOR

//MHMotor -- The general Lightning object representation of a motor
typedef struct _MHMotor{
	//MHMotor inherits directly from MHObject
	MHObject super;
}MHMotor;

//MARK: - Function Declarations

//MHMotor designated initializer -- Returns a pointer to an MHMotor
MHMotor *newMotor();
//Getter for super property
MHObject *getSuperOfMotor(MHMotor *motor);

//MARK: - Function Definitions

MHMotor *newMotor(){
	MHMotor new;
	MHObject *super = newObject();
	new.super = *super;
	return &new;
}

MHObject *getSuperOfMotor(MHMotor *motor){
	//Turn the normal reference into a pointer and hand it back
	return &motor->super;
}

#endif

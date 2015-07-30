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

//Make conditional #including of FLObject possible
#ifndef __FLOBJECT_H__
#define __FLOBJECT_H__
//FLObject -- The base class (or struct, I guess) of every Lightning object
typedef struct _FLObject{
	//A unique tag, so it's easy to keep track of what's what
	int tag;
}FLObject;

//MARK: - Function Declarations

//FLObject designated initializer -- Returns a pointer to a new FLObject
FLObject *newObject();
//Getter for tag property
int getTagOfObject(FLObject *object);

//MARK: - Private Function Declarations

void autoInitializeObject(FLObject *object);

//MARK: - Function Definitions

FLObject *newObject(){
	static int tag = 0;
	FLObject new;
	new.tag = tag;
	++tag;
	return &new;
}

//MARK: - Property Getters

int getTagOfObject(FLObject *object){
	autoInitializeObject(object);
	return object->tag;
}

//MARK: - Hopefully Private Functions

void autoInitializeObject(FLObject *object){
	//If it's NULL, we'll initialize it. Otherwise, we'll just let it be
	if(!object){
		object = newObject();
	}
}
#endif
#endif

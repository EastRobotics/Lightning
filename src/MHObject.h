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

//Silence any unreferenced function/variable warnings
#pragma systemFile

//Make conditional #including of MHObject possible
#ifndef MHOBJECT
#define MHOBJECT

//MHObject -- The base class (or struct, I guess) of every Lightning object
typedef struct _MHObject{
	//A conditionally-set tag, so it's easy to keep track of what's what
	int tag;
}MHObject;

//MARK: - Function Declarations

//MHObject designated initializer -- Returns a pointer to a new MHObject
MHObject *newObject();
//Setter for tag property
void setTagOfObject(MHObject *object, int newValue);
//Getter for tag property
int getTagOfObject(MHObject *object);

//MARK: - Private Function Declarations

void autoInitializeObject(MHObject *object);

//MARK: - Function Definitions

MHObject *newObject(){
	static int tag = 0;
	MHObject new;
	new.tag = tag;
	tag++;
	return &new;
}

//MARK: - Property Setters

void setTagOfObject(MHObject *object, int newValue){
	autoInitializeObject(object);
	object->tag = newValue;
}

//MARK: - Property Getters

int getTagOfObject(MHObject *object){
	autoInitializeObject(object);
	return object->tag;
}

//MARK: - Hopefully Private Functions

void autoInitializeObject(MHObject *object){
	//If it's NULL, we'll initialize it. Otherwise, we'll just let it be
	if(!object){
		object = newObject();
	}
}

#endif

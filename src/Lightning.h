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

//Make conditional #including of Lightning easily possible
#ifndef __LIGHTNING__
#define __LIGHTNING__

//#include FLObject if it hasn't been done so already
#ifndef __FLOBJECT_H__
#include "FLObject.h"
#endif

//#include FLMotor if it hasn't been done so already
#ifndef __FLMOTOR_H__
#include "FLMotor.h"
#endif

#endif
#endif

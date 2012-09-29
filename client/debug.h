/*
 * debug.h
 *
 *  Created on: Aug 25, 2012
 *      Author: tomer
 */

#ifndef DEBUG_H_
#define DEBUG_H_

//#define DEBUG

#ifdef DEBUG
#define DEBUG_MSG(str) do { std::cout << str << std::endl; } while( false )
#else
#define DEBUG_MSG(str) do { } while ( false )
#endif


#endif /* DEBUG_H_ */

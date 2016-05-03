/*
 * InteruptVector.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: mahmoud
 */

#ifndef INTERUPTVECTOR_H_
#define INTERUPTVECTOR_H_

#define ISR(vector, ...) 	\
		void vector(void) __attribute__ ((signal,used,externally_visible)) __VA_ARGS__;\
		void vector(void)

#define INTERUPTVECTOR_SETGLOPALINTERUPT		__asm__("SEI")

#define INTERUPTVECTOR_CLRGLOPALINTERUPT		__asm__("CLI")



#endif /* INTERUPTVECTOR_H_ */

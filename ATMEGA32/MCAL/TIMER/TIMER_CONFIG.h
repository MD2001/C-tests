/***********************************************************************************************************/
/***************************** Author : Mohamed diaa********************************************************/
/***************************** Layer : MCAL ****************************************************************/
/***************************** SWC : TIMER *****************************************************/
/***************************** Version : 1.0 ***************************************************************/
#ifndef TIMER_CONFIG_H
#define TIMER_CONFIG_H



/*
 * OPRTIONS:
 * 1-Normal
 * 2-PWM, Phase Correct
 * 3-CTC
 * 4-Fast PWM
 * */
#define Mode 		4
/*
 * OPRTIONS:
 *	1- No_clock_source
 *	2- presquler_1
 *	3- presquler_8
 *	4- presquler_64
 *	5- presquler_256
 *	6- presquler_1024
 * */
#define CLOCK		3
/*
 * OPTIONS:
 * 1-disconnected
 * 2-Toggle
 * 3-Clear
 * 4-Set
 * */

#define OC0State	2









#endif

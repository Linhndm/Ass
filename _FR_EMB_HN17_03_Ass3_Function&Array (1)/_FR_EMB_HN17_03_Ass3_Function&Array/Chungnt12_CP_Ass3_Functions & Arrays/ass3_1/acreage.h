#ifndef __ACREAGE_H_
#define __ACREAGE_H_

#include <math.h>

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#define ERR 0
#define RECTANGLE 1 /*if rectangle*/
#define KEY 1
/*******************************************************************************
 * API
 ******************************************************************************/
/*!
 * @brief <Perform a rectangular area calculation based on perimeter and diagonal>
 *
 * @param perimeter <intput perimeter>.
 * @param diagonals <intput diagonals>.
 *
 * @return <float acreage>.
 */
 float acreage (float perimeter, float diagonals);

 /*!
 * @brief <test input value>
 *
 * @param perimeter <intput perimeter>.
 * @param diagonals <intput diagonals>.
 *
 * @return <true or false>.
 */
 int testInput (float perimeter, float diagonals);

#endif /*__ACREAGE_H_*/
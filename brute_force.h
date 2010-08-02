/**
 * \file brute_force.h
 *
 *  Copyright (C) 2009-2010, Ongaro Mattia <moongaro at gmail.com>
 *  All rights reserved.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 */

#ifndef BRUTE_FORCE_H
#define BRUTE_FORCE_H

/**
 * \brief		   Brute force function
 */
#ifdef __cplusplus
extern "C" {
#endif
/**
 * \brief          Brute force a md5 hash
 *
 * \param base	   starting string
 * \param offsize  offsize from start
 * \param hash     hash to crack
 * \param start    starting character
 * \param end      terminating character
 */
int brute_force ( char * base , size_t offsize, unsigned char hash [ 16 ], char start, char end );

/**
 * \brief           Return the length of a group made by the same letter starting by the end of the string
 *
 * \param str	    the string
 * \param character the character
 */
int final_chars ( const char * str, char character );

#ifdef __cplusplus
}
#endif

#endif

/* End of brute_force.h */
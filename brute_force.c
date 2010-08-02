/**
 * \file brute_force.c
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

#include "brute_force.h"

#include <string.h>

/*
 *		Brute force a md5 hash
 */
int brute_force ( char * base , size_t offsize, unsigned char hash [ 16 ], char start, char end )
{
	int final_chars ( const char * str, char character );

	unsigned char * generated_hash = ( unsigned char * ) calloc ( 17, sizeof ( char ) );
	generated_hash [ 16 ] = 0x00;

	int counter, c, occurence;
    for ( ; strcmp ( ( const char * ) hash, ( const char * ) generated_hash ) ; base [ offsize ] ++ )
    {
		occurence = final_chars ( ( const char * ) base,  end );
	
		if ( occurence ) {
			md5 ( ( const unsigned char * ) ( base ), strlen ( base ), generated_hash );
			if ( ! strcmp ( ( const char * ) hash, ( const char * ) generated_hash ) ) {
				return 0;
			}

			for ( counter = offsize, c = 0 ; c < occurence ; c ++, counter -- )
			{
				if ( base [ counter ] >= end )
				{
					if ( counter > 0 )
					{
						base [ counter - 1 ] ++;
					}
					else {
						base [ ++ offsize ] = start;
					}
					base [ counter ] = start;
				}
			}
		}
		md5 ( ( const unsigned char * ) ( base ), strlen ( base ), generated_hash );
   }

   base [ offsize ] --;
   return 0;
}

/*
 *			Return the length of a group made by the same letter starting by the end of the string
 */
int final_chars ( const char * str, char character )
{
    size_t length = strlen( str ) - 1;
	int counter;
	for ( counter =length ; str [ counter ] == character ; counter -- );

	return ( length - counter );
} 

/* End of brute_force.c */
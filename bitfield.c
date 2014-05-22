/**
 * @file
 * @brief A data structure which manages the (un)marking of bitfields
 * @author  Willem Thiart himself@willemthiart.com
 * @version 0.1
 *
 * @section LICENSE
 * Copyright (c) 2011, Willem-Hendrik Thiart
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * The names of its contributors may not be used to endorse or promote
      products derived from this software without specific prior written
      permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL WILLEM-HENDRIK THIART BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <stdint.h>

#include "bitfield.h"

void bitfield_init(bitfield_t * me, const int nbits)
{
    //assert(0 < nbits);
    me->size = nbits;
    me->bits = calloc(me->size, sizeof(uint32_t));
    assert(me->bits);
}

void bitfield_clone(bitfield_t * me, bitfield_t * clone)
{
    clone->size = me->size;
    clone->bits = calloc(me->size, sizeof(uint32_t));
    memcpy(clone->bits, me->bits, sizeof(uint32_t) * me->size);
}

void bitfield_release(bitfield_t* me)
{
    free(me->bits);
}

void bitfield_mark(bitfield_t * me, const int bit)
{
    int cint;

    assert(me->bits);
    assert(0 <= bit);
    assert(bit < me->size);

    cint = bit / 32;
    me->bits[cint] |= 1 << (31 - bit % 32);
}

void bitfield_unmark(bitfield_t * me, const int bit)
{
    int cint;

    assert(me->bits);
    assert(0 <= bit);
    assert(bit < me->size);

    cint = bit / 32;
    me->bits[cint] &= ~(1 << (31 - bit % 32));
}


// TODO need to remove 32 bit centeredness from this function
int bitfield_is_marked(bitfield_t * me, const int bit)
{
    assert(me->bits);
    assert(0 <= bit);
    if (!(bit < me->size))
    {
        int * p = (int*)0x12345678;
        *p = 0;
    }
    assert(bit < me->size);

    int cint;

    cint = bit / 32;
    return 0 != (me->bits[cint] & (1 << (31 - bit % 32)));
}

int bitfield_get_length(bitfield_t * me)
{
    return me->size;
}

char *bitfield_str(bitfield_t * me)
{
    char *str;
    int ii;

    str = malloc(me->size + 1);

    for (ii = 0; ii < me->size; ii++)
    {
        str[ii] = bitfield_is_marked(me, ii) ? '1' : '0';
    }

    str[me->size] = '\0';
    return str;
}


#include <stdbool.h>
#include <assert.h>
#include <setjmp.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "CuTest.h"

#include <stdint.h>

#include "bitfield.h"

void TestBitfield_get_length_gets_initialised_length(
    CuTest * tc
)
{
    bitfield_t bf;

    bitfield_init(&bf, 40);
    CuAssertTrue(tc, 40 == bitfield_get_length(&bf));
}

void TestBitfield_markbit_is_marked(
    CuTest * tc
)
{
    bitfield_t bf;

    bitfield_init(&bf, 40);
    CuAssertTrue(tc, 0 == bitfield_is_marked(&bf, 5));
    bitfield_mark(&bf, 5);
    CuAssertTrue(tc, 1 == bitfield_is_marked(&bf, 5));
}

void TestBitfield_unmarkbit_is_unmarked(
    CuTest * tc
)
{
    bitfield_t bf;

    bitfield_init(&bf, 40);
    bitfield_mark(&bf, 5);
    bitfield_unmark(&bf, 5);
    CuAssertTrue(tc, 0 == bitfield_is_marked(&bf, 5));
}

void TestBitfield_str_produces_correct_string(
    CuTest * tc
)
{
    bitfield_t bf;

    char *str;

    bitfield_init(&bf, 20);

    str = bitfield_str(&bf);
    CuAssertTrue(tc, 0 == strcmp(str, "00000000000000000000"));
    free(str);

    bitfield_mark(&bf, 5);
    bitfield_mark(&bf, 7);
    str = bitfield_str(&bf);
    CuAssertTrue(tc, 0 == strcmp(str, "00000101000000000000"));
    free(str);
}

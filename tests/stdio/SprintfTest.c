/***
 * Excerpted from "Test-Driven Development for Embedded C",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/jgade for more book information.
***/
/*- ------------------------------------------------------------------ -*/
/*-    Copyright (c) James W. Grenning -- All Rights Reserved          -*/
/*-    For use by owners of Test-Driven Development for Embedded C,    -*/
/*-    and attendees of Renaissance Software Consulting, Co. training  -*/
/*-    classes.                                                        -*/
/*-                                                                    -*/
/*-    Available at http://pragprog.com/titles/jgade/                  -*/
/*-        ISBN 1-934356-62-X, ISBN13 978-1-934356-62-3                -*/
/*-                                                                    -*/
/*-    Authorized users may use this source code in your own           -*/
/*-    projects, however the source code may not be used to            -*/
/*-    create training material, courses, books, articles, and         -*/
/*-    the like. We make no guarantees that this source code is        -*/
/*-    fit for any purpose.                                            -*/
/*-                                                                    -*/
/*-    www.renaissancesoftware.net james@renaissancesoftware.net       -*/
/*- ------------------------------------------------------------------ -*/


#include "unity_fixture.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

TEST_GROUP(sprintf);

static char *output;
static const char * expected;

TEST_SETUP(sprintf)
{
    expected = "";
}

TEST_TEAR_DOWN(sprintf)
{
    free(output);
}

static void expect(const char * s)
{
    u_int32_t size = sizeof(char) * (strlen(s) + 2);
    output = malloc(size);   
    memset(output, 0xaa, size);

    expected = s;

}

static void given(int charsWritten)
{
    printf("expected: %s\n", expected);
    TEST_ASSERT_EQUAL(strlen(expected), charsWritten);
    TEST_ASSERT_EQUAL_STRING(expected, output);
    TEST_ASSERT_BYTES_EQUAL(0xaa, output[strlen(expected) + 1]);
}


#if 1 
TEST(sprintf, NoFormatOperations)
{
    expect("hey");
    given(sprintf(output, "hey"));
}

TEST(sprintf, InsertString)
{
    expect("Hello World\n");
    given(sprintf(output, "Hello %s\n", "World"));
}




TEST(sprintf, VeryBigString)
{
    char *my_s = "\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789\
                0123456789";
    expect(my_s);
    given(sprintf(output, "%s", my_s));
}
#endif  

/* to run this also change in SprintfTestRunner.c */
#if 0 
TEST(sprintf, NoFormatOperations)
{
    char output[5];

    TEST_ASSERT_EQUAL(4, sprintf(output, "hey"));
    TEST_ASSERT_EQUAL_STRING("hey", output);
}
#endif

#if 0 
TEST(sprintf, NoFormatOperations)
{
    char output[5];
    memset(output, 0xaa, sizeof output);

    TEST_ASSERT_EQUAL(3, sprintf(output, "hey"));
    TEST_ASSERT_EQUAL_STRING("hey", output);
    TEST_ASSERT_BYTES_EQUAL(0xaa, output[4]);
}

TEST(sprintf, InsertString)
{
    char output[20];
    memset(output, 0xaa, sizeof output);

    TEST_ASSERT_EQUAL(12, sprintf(output, "Hello %s\n", "World"));
    TEST_ASSERT_EQUAL_STRING("Hello World\n", output);
    TEST_ASSERT_BYTES_EQUAL(0xaa, output[13]);
}
#endif

#if 0 
TEST(sprintf, NoFormatOperations)
{
    char output[5];

    TEST_ASSERT_EQUAL(3, sprintf(output, "hey"));
    TEST_ASSERT_EQUAL_STRING("hey", output);
}
#endif

#if 0 
TEST(sprintf, NoFormatOperations)
{
    char output[5] = "";
    TEST_ASSERT_EQUAL(3, sprintf(output, "hey"));
    TEST_ASSERT_EQUAL_STRING("hey", output);
}
#endif

#if 0 
TEST(sprintf, NoFormatOperations)
{
    char output[5];
    memset(output, 0xaa, sizeof output);

    TEST_ASSERT_EQUAL(3, sprintf(output, "hey"));
    TEST_ASSERT_EQUAL_STRING("hey", output);
}
#endif


#if 0 
TEST(sprintf, InsertString)
{
    char output[20] = "";

    TEST_ASSERT_EQUAL(12, sprintf(output, "Hello %s\n", "World"));
    TEST_ASSERT_EQUAL_STRING("Hello World\n", output);
}
#endif

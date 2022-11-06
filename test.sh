#!/bin/sh

function g_print()
{
    echo -e "\x1b[0;32m$1\x1b[0m"
}

g_print "test_read_valid_line:"

exec build/bin/test/test_read_valid_line



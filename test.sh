#!/bin/sh

function g_print()
{
    echo -e "\x1b[0;32m$1\x1b[0m"
}

g_print "test_read_valid_line:"

build/bin/test/test_read_valid_line

echo

g_print "test_display:"

build/bin/test/test_display

echo

g_print "test_remove_section:"

build/bin/test/test_remove_section

echo

g_print "test_add_section:"

build/bin/test/test_add_section

echo

g_print "test_modify_section:"

build/bin/test/test_modify_section

// =============================================================================
// Scilab ( http://www.scilab.org/ ) - This file is part of Scilab
// Copyright (C) 2015 - Scilab Enterprises - Antoine ELIAS
//
//  This file is distributed under the same license as the Scilab package.
// =============================================================================
//
// <-- CLI SHELL MODE -->
//
// <-- Non-regression test for bug 14097 -->
//
// <-- Bugzilla URL -->
// http://bugzilla.scilab.org/14097
//
// <-- Short Description -->
//
// genlib no more adds a separator at the end of the lib path if it is not given in the directory path.

ref = pathconvert("SCI/modules/string/macros/");
genlib("slib", "SCI/modules/string/macros");
s1=string(slib)(1);
assert_checkequal(s1, ref);
clear slib

genlib("slib", "SCI/modules/string/macros/");
s2=string(slib)(1);
assert_checkequal(s2, ref);
clear slib

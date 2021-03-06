// =============================================================================
// Scilab ( http://www.scilab.org/ ) - This file is part of Scilab
// Copyright (C) 2012 - SE - Sylvestre Ledru
//
//  This file is distributed under the same license as the Scilab package.
// =============================================================================

// <-- CLI SHELL MODE -->

// <-- Non-regression test for bug 12033 -->
//
// <-- Bugzilla URL -->
// http://bugzilla.scilab.org/show_bug.cgi?id=12033
//
// <-- Short Description -->
// assert_checkalmostequal was failing with two %inf values.


ret=assert_checkalmostequal ( %inf , %inf, 1.e-10)
assert_checkequal(ret, %t);

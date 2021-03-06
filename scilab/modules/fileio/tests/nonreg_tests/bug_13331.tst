// =============================================================================
// Scilab ( http://www.scilab.org/ ) - This file is part of Scilab
// Copyright (C) 2014 - Scilab Enterprises - Sylvain GENIN
//
//  This file is distributed under the same license as the Scilab package.
// =============================================================================
//
// <-- CLI SHELL MODE -->
//
// <-- Non-regression test for bug 13331 -->
//
// <-- Bugzilla URL -->
// http://bugzilla.scilab.org/show_bug.cgi?id=13331
//
// <-- Short Description -->
// Users are no longer able to write inconsistent options to mopen,
//   mopen(file, "wr") exits now with a proper error

refMsg = msprintf(_("%s: invalid status.\n"), "mopen");

assert_checkerror("mopen(""texte.txt"", ""rw"")",refMsg);

assert_checkerror("mopen(""texte.txt"", ""r+w"")",refMsg);

assert_checkerror("mopen(""texte.txt"", ""r="")",refMsg);

assert_checkerror("mopen(""texte.txt"", ""L"")",refMsg);

assert_checkerror("mopen(""texte.txt"", ""w+lb"")",refMsg);


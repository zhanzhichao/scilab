/*
 * Scilab ( http://www.scilab.org/ ) - This file is part of Scilab
 * Copyright (C) 2014 - Scilab Enterprises - Antoine ELIAS
 *
 * This file must be used under the terms of the CeCILL.
 * This source file is licensed as described in the file COPYING, which
 * you should have received as part of this distribution.  The terms
 * are also available at
 * http://www.cecill.info/licences/Licence_CeCILL_V2.1-en.txt
 *
 */

extern "C" {
#include "gw_gui.h"
#include "api_scilab.h"
#include "Scierror.h"
#include "localization.h"
#include "createGraphicObject.h"
#include "getGraphicObjectProperty.h"
#include "graphicObjectProperties.h"
#include "HandleManagement.h"
}

int sci_saveGui(char *fname, unsigned long fname_len)
{
    SciErr sciErr;
    int* piAddr1 = NULL;
    long long hFig = 0;
    int iFig = 0;

    int iType = 0;
    int* piType = &iType;
    int* piAddr2 = NULL;
    char* pstFile = NULL;

    int iRhs = nbInputArgument(pvApiCtx);

    CheckInputArgument(pvApiCtx, 2, 2);
    CheckOutputArgument(pvApiCtx, 1, 1);

    sciErr = getVarAddressFromPosition(pvApiCtx, 1, &piAddr1);
    if (sciErr.iErr)
    {
        printError(&sciErr, 0);
        return 1;
    }

    if (isHandleType(pvApiCtx, piAddr1) == 0 || isScalar(pvApiCtx, piAddr1) == 0)
    {
        Scierror(999, _("%s: Wrong size for input argument #%d: A single handle expected.\n"), fname, 1);
        return 1;
    }

    if (getScalarHandle(pvApiCtx, piAddr1, &hFig))
    {
        Scierror(999, _("%s: Can not read input argument #%d.\n"), fname, 1);
        return 1;
    }

    iFig = getObjectFromHandle((long)hFig);
    if (iFig == 0)
    {
        Scierror(999, _("%s: The handle is not or no more valid.\n"), fname);
        return 0;
    }

    getGraphicObjectProperty(iFig, __GO_TYPE__, jni_int, (void**)&piType);
    if (piType == NULL || iType != __GO_FIGURE__)
    {
        Scierror(999, _("%s: Wrong type for input argument #%d: Figure handle expected.\n"), fname, 1);
        return 1;
    }

    sciErr = getVarAddressFromPosition(pvApiCtx, 2, &piAddr2);
    if (sciErr.iErr)
    {
        printError(&sciErr, 0);
        return 1;
    }

    if (isStringType(pvApiCtx, piAddr2) == 0 || isScalar(pvApiCtx, piAddr2) == 0)
    {
        Scierror(999, _("%s: Wrong size for input argument #%d: A string expected.\n"), fname, 1);
        return 1;
    }


    if (getAllocatedSingleString(pvApiCtx, piAddr2, &pstFile))
    {
        if (pstFile)
        {
            freeAllocatedSingleString(pstFile);
        }

        Scierror(202, _("%s: Wrong type for argument #%d: A string expected.\n"), fname, 2);
        return 1;
    }

    char* ret = xmlsave(iFig, pstFile);
    freeAllocatedSingleString(pstFile);

    if (ret[0] != '\0')
    {
        Scierror(202, _("%s: %s.\n"), fname, ret);
        free(ret);
        return 1;
    }

    free(ret);
    createScalarBoolean(pvApiCtx, iRhs + 1, 1);
    AssignOutputVariable(pvApiCtx, 1) = iRhs + 1;
    ReturnArguments(pvApiCtx);
    return 0;
}
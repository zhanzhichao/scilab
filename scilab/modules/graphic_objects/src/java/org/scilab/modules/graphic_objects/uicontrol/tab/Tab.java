/*
 * Scilab ( http://www.scilab.org/ ) - This file is part of Scilab
 * Copyright (C) 2014 - Scilab enterprises - Antoine ELIAS
 *
 * This file must be used under the terms of the CeCILL.
 * This source file is licensed as described in the file COPYING, which
 * you should have received as part of this distribution.  The terms
 * are also available at
 * http://www.cecill.info/licences/Licence_CeCILL_V2.1-en.txt
 *
 */

package org.scilab.modules.graphic_objects.uicontrol.tab;

import static org.scilab.modules.graphic_objects.graphicObject.GraphicObjectProperties.__GO_UI_TAB__;

import javax.swing.UIDefaults;
import javax.swing.UIManager;

import org.scilab.modules.graphic_objects.console.Console;
import org.scilab.modules.graphic_objects.uicontrol.Uicontrol;
import org.scilab.modules.graphic_objects.utils.LayoutType;

/**
 * @author Vincent COUVERT
 */
public class Tab extends Uicontrol {

    /**
     * Constructor
     */
    public Tab() {
        super();
        setStyle(__GO_UI_TAB__);
        if (Console.getConsole().getUseDeprecatedLF()) {
            setRelief(RELIEF_FLAT);
        } else {
            UIDefaults defaults = UIManager.getDefaults();

            //font
            setFont(defaults.getFont("TabbedPane.font"));

            //h-alignment
            setHorizontalAlignment("left");

            //v-alignement
            setVerticalAlignment("middle");

            //layout
            setLayout(LayoutType.BORDER);
        }
    }

}
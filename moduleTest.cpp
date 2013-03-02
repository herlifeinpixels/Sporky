#include <iostream>
#include <winable.h>
#inculde <Windows.h>
using namespace std;

/* We need to write:
/*
/* 1. abstract class Module
/* 2. class RecipeModule extends Module
/* 3. class ProgramModule entends Module
/* 4. class MacroModule entends Module
/* 5. class GestureModule entends Module
/* 
/* See example on creating and extending abstract classes: 
/* http://www.learncpp.com/cpp-tutorial/126-pure-virtual-functions-abstract-base-classes-and-interface-classes/
*/

#include "module.h"

int main () {
    
    // Test Constructor
    Module mod0;
    cout << "Should be Illegal, you can't instantiate an abstract class: " << mod0 << endl;

    // Leave the abstract class empty for now, we'll do the easy stuff first and code that later
    
    // Test Program Module
    ProgramModule myChrome;
    myProgram.setProgram("C:\Program Files (x86)\Google\Chrome\Application\chrome.exe");
    cout << "Should print path file above: " << myChrome.getProgramPath() << endl;
    cout << "Should print program name(Chrome): " << myChrome.getProgramName() << endl;
    
// -----------------------------------------------------------------------------------------------------

    // Test Macro Module
    // Note for self: http://msdn.microsoft.com/en-us/library/ms644959%28v=vs.85%29.aspx#wh_keyboardhook

    MacroModule myPrintMacro;
    // Note: we need to have a seperate objects to pass around keystrokes/mouse-clicks in our program
    // We'll get Nate's team to write a listener for windows keyboard input
    // For now we can implement this:

    // Simulate data we get from keypress via WIN API
    WORD CONTROL = 0x11;
    WORD P = 0x50;
    WORD ENTER = 0x0D;

    // enter a sequence of ctrl P Enter
    myPrint.attachKeystroke("CTRL", CONTROL, true); // hold key down
    myPrint.attachKeystroke("P", P, true);
    myPrint.attachKeystroke("P", P, false);
    myPrint.attachKeystroke("CTRL", CONTROL, false); // key up
    myPrint.attachKeystroke("Enter", ENTER, true);
    myPrint.attachKeystroke("Enter", ENTER, false);
    cout << "Should return an array of keystrokes in order (CTRL, P, Enter): " << myPrint.getKeyStokes() << endl;
    
    String thirdKey = myPrint.getKeyAt(2);
    cout << "Should return the 3rd key that the user presses NOT the 3rd sequence: " << thirdKey << endl;

    // delete from sequence
    myPrint.deleteKeyStroke(1);
    cout << "Should return an array of keystrokes in order (P, Enter): " << myPrint.getKeyStokes() << endl;

    
// -----------------------------------------------------------------------------------------------------

    // Test Gesture Module
    // This module will mostly interface with Gesture team's code
    GestureModule mySwipe;

    // Nate's team will write seperate process to capture and store gestures
    try {
        mySwipe.capture();
	} catch (gestureException& e) {
		cerr << e.what() << endl;
	}

    // Gesture takes on sequence fixed points in space, think of connecting dots on android lock screen
    cout << "Should return an array of sequences: " << mySwipe.getSequence() << endl;
    // Sample output: IDK, ask Nate.

} // end main
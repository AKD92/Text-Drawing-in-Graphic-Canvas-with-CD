

/****************************************************************************************
    Implementation of program execution and GUI building procedure
    Author:             Ashis Kumar Das
    Email:              akd.bracu@gmail.com
    GitHub:             https://github.com/AKD92
*****************************************************************************************/






#include <iup.h>
#include <stdio.h>
#include <string.h>



#define BUFFER_SIZE             2 * 1024
#define TXTFSIZE                "txtFsize"
#define TXTENTRY                "txtEntry"
#define CANVAS_IUP              "iup_canvas"






int iFontSize;
char strMessage[BUFFER_SIZE];






int main(void);
static Ihandle *createMainWindow(void);


int cb_btnExit(Ihandle *btn);
int cb_btnDraw(Ihandle *btn);
int cb_canvasMap(Ihandle *dispCanvas);
int cb_canvasUnmap(Ihandle *dispCanvas);
int cb_canvasDraw(Ihandle *dispCanvas, float posx, float posy);
int cb_canvasResize(Ihandle *dispCanvas, int width, int height);
int cb_canvasMouse(Ihandle *dispCanvas, int x, int y, char *status);







int main(void) {
    
    Ihandle *dlgMain;
    const char *strInitMsg;
    
    strInitMsg = "\"Never in the field"
                "\nof human conflict"
                "\nwas so much owed"
                "\nby so many, to so few...\""
                "\n\n    -    Winston Churchill";
    
    iFontSize = 18;
    strcpy(strMessage, strInitMsg);
    
    IupOpen(0, 0);
    {
        dlgMain = createMainWindow();
        IupSetAttribute(dlgMain, "RASTERSIZE", "450x520");
//      IupSetAttribute(dlgMain, "PLACEMENT", "MAXIMIZED");
        IupShowXY(dlgMain, IUP_CENTER, IUP_CENTER);
        IupMainLoop();
        IupDestroy(dlgMain);
    }
    IupClose();
    return 0;
}




static Ihandle *createMainWindow(void) {
    
    Ihandle *dlgMain;
    Ihandle *dispCanvas, *btnExit, *txtEntry, *btnDraw;
    Ihandle *editVbox, *cmdHbox, *fullVbox;
    Ihandle *txtFontSize, *lblFontSize;
    
    txtEntry = IupText(0);
    IupSetAttribute(txtEntry, "RASTERSIZE", "x120");
    IupSetAttribute(txtEntry, "EXPAND", "HORIZONTAL");
//  IupSetAttribute(txtEntry, "FONTSIZE", "11");
    IupSetAttribute(txtEntry, "MULTILINE", "YES");
    IupSetAttribute(txtEntry, "WORDWRAP", "YES");
    IupSetAttribute(txtEntry, "VALUE", strMessage);
    
    lblFontSize = IupLabel("Font Size :");
//  IupSetAttribute(lblFontSize, "IMAGE", "B");
    
    txtFontSize = IupText(0);
    IupSetAttribute(txtFontSize, "RASTERSIZE", "60x20");
    IupSetAttribute(txtFontSize, "EXPAND", "NO");
    IupSetInt(txtFontSize, "VALUE", iFontSize);
    IupSetAttribute(txtFontSize, "MASKINT", "1:100");
    
    btnDraw = IupButton("Draw This Text", 0);
    IupSetAttribute(btnDraw, "RASTERSIZE", "105x30");
//  IupSetAttribute(btnDraw, "IMAGE", "B");
    IupSetCallback(btnDraw, "ACTION", (Icallback) cb_btnDraw);
    
    cmdHbox = IupHbox(lblFontSize, txtFontSize, IupFill(), btnDraw, 0);
    IupSetAttribute(cmdHbox, "ALIGNMENT", "ACENTER");
    IupSetAttribute(cmdHbox, "EXPAND", "HORIZONTAL");
    IupSetAttribute(cmdHbox, "NGAP", "7");
    IupSetAttribute(cmdHbox, "NMARGIN", "0x0");
    
    editVbox = IupVbox(txtEntry, cmdHbox, 0);
    IupSetAttribute(editVbox, "EXPAND", "HORIZONTAL");
    IupSetAttribute(editVbox, "NGAP", "7");
    IupSetAttribute(editVbox, "NMARGIN", "0x0");
    
    dispCanvas = IupCanvas(0);
    IupSetAttribute(dispCanvas, "EXPAND", "YES");
    IupSetAttribute(dispCanvas, "SCROLLBAR", "NO");
    IupSetCallback(dispCanvas, "MAP_CB", (Icallback) cb_canvasMap);
    IupSetCallback(dispCanvas, "UNMAP_CB", (Icallback) cb_canvasUnmap);
    IupSetCallback(dispCanvas, "ACTION", (Icallback) cb_canvasDraw);
    IupSetCallback(dispCanvas, "RESIZE_CB", (Icallback) cb_canvasResize);
    IupSetCallback(dispCanvas, "MOTION_CB", (Icallback) cb_canvasMouse);
    
    btnExit = IupButton("Exit To System", 0);
    IupSetAttribute(btnExit, "RASTERSIZE", "105x30");
    IupSetCallback(btnExit, "ACTION", (Icallback) cb_btnExit);
    
    fullVbox = IupVbox(editVbox, dispCanvas, btnExit, 0);
    IupSetAttribute(fullVbox, "ALIGNMENT", "ARIGHT");
    IupSetAttribute(fullVbox, "EXPAND", "YES");
    IupSetAttribute(fullVbox, "NGAP", "10");
    IupSetAttribute(fullVbox, "NMARGIN", "15x15");
    
    IupSetHandle(TXTENTRY, txtEntry);
    IupSetHandle(CANVAS_IUP, dispCanvas);
    IupSetHandle(TXTFSIZE, txtFontSize);
    
    dlgMain = IupDialog(fullVbox);
    IupSetAttribute(dlgMain, "TITLE", "Text Drawing With CD (akd.bracu@gmail.com)");
    IupSetAttribute(dlgMain, "SHRINK", "YES");
    IupSetAttribute(dlgMain, "MINSIZE", "350x360");
    IupSetAttribute(dlgMain, "ICON", "A");
    return dlgMain;
}




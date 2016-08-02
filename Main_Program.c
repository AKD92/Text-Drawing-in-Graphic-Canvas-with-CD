

/****************************************************************************************
    Implementation of program execution and GUI building procedure
    Author:             Ashis Kumar Das
    Email:              akd.bracu@gmail.com
    GitHub:             https://github.com/AKD92
*****************************************************************************************/






#include <iup.h>
#include <cd.h>
#include <stdio.h>
#include <string.h>



#define TXTFSIZE                "txtFsize"
#define TXTENTRY                "txtEntry"
#define CANVAS_IUP              "iup_canvas"
#define CANVAS_CD               "cd_canvas"






int iFontSize;
char strMessage[2 * 1024];






int main(void);
Ihandle *createMainWindow(void);


int cb_btnExit(Ihandle *btn);
int cb_btnDraw(Ihandle *btn);
int cb_canvasMap(Ihandle *canvas);
int cb_canvasUnmap(Ihandle *canvas);
int cb_canvasDraw(Ihandle *canvas, float posx, float posy);
int cd_canvasResize(Ihandle *canvas, int width, int height);
int cb_canvasMouse(Ihandle *canvas, int x, int y, char *status);







int main(void) {
    
    char *sMsg;
    Ihandle *dlgMain;
    
    sMsg = "\"Never in the field\
\nof human conflict\
\nwas so much owed\
\nby so many, to so few...\"\
\n\n    -    Winston Churchill";
    
    iFontSize = 18;
    strcpy(strMessage, sMsg);
    
    IupOpen(0, 0);
    {
        dlgMain = createMainWindow();
        IupSetAttribute(dlgMain, "RASTERSIZE", "450x520");
//      IupSetAttribute(dlgMain, "PLACEMENT", "MAXIMIZED");
        IupShowXY(dlgMain, IUP_CENTER, IUP_CENTER);
        IupMainLoop();
    }
    IupClose();
    return 0;
}




Ihandle *createMainWindow(void) {
    
    Ihandle *dlgMain;
    Ihandle *canvas, *btnExit, *txtEntry, *btnDraw;
    Ihandle *editVbox, *cmdHbox, *wholeVbox;
    Ihandle *txtFontSize, *lblFontSize;
    
    txtEntry = IupText(0);
    IupSetAttribute(txtEntry, "RASTERSIZE", "x120");
    IupSetAttribute(txtEntry, "EXPAND", "YES");
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
    IupSetAttribute(editVbox, "NMARGIN", "0x5");
    
    canvas = IupCanvas(0);
    IupSetAttribute(canvas, "EXPAND", "YES");
    IupSetAttribute(canvas, "SCROLLBAR", "NO");
    IupSetCallback(canvas, "MAP_CB", (Icallback) cb_canvasMap);
    IupSetCallback(canvas, "UNMAP_CB", (Icallback) cb_canvasUnmap);
    IupSetCallback(canvas, "ACTION", (Icallback) cb_canvasDraw);
    IupSetCallback(canvas, "RESIZE_CB", (Icallback) cd_canvasResize);
    IupSetCallback(canvas, "MOTION_CB", (Icallback) cb_canvasMouse);
    
    btnExit = IupButton("Exit To System", 0);
    IupSetAttribute(btnExit, "RASTERSIZE", "105x30");
    IupSetCallback(btnExit, "ACTION", (Icallback) cb_btnExit);
    
    wholeVbox = IupVbox(editVbox, canvas, btnExit, 0);
    IupSetAttribute(wholeVbox, "ALIGNMENT", "ARIGHT");
    IupSetAttribute(wholeVbox, "EXPAND", "YES");
    IupSetAttribute(wholeVbox, "NGAP", "10");
    IupSetAttribute(wholeVbox, "NMARGIN", "12x12");
    
    IupSetHandle(TXTENTRY, txtEntry);
    IupSetHandle(CANVAS_IUP, canvas);
    IupSetHandle(TXTFSIZE, txtFontSize);
    
    dlgMain = IupDialog(wholeVbox);
    IupSetAttribute(dlgMain, "TITLE", "Text Drawing With CD (akd.bracu@gmail.com)");
    IupSetAttribute(dlgMain, "SHRINK", "YES");
    IupSetAttribute(dlgMain, "MINSIZE", "350x360");
    IupSetAttribute(dlgMain, "ICON", "A");
    return dlgMain;
}




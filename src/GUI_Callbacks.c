

/****************************************************************************************
    Implementation of GUI Callback functions
    Author:             Ashis Kumar Das
    Email:              akd.bracu@gmail.com
    GitHub:             https://github.com/AKD92
*****************************************************************************************/






#include <iup.h>
#include <cd.h>
#include <cdiup.h>
#include <string.h>
//#include <cdnative.h>         // using cdiup.h, so we dont need cdnative.h



#define TXTFSIZE                "txtFsize"
#define TXTENTRY                "txtEntry"
#define CANVAS_CD               "cd_canvas"
#define CANVAS_IUP              "iup_canvas"




extern int iFontSize;
extern char strMessage[];       // 'extern char *strMessage' won't work!!




int cb_btnExit(Ihandle *btn);
int cb_btnDraw(Ihandle *btn);
int cb_canvasMap(Ihandle *dispCanvas);
int cb_canvasUnmap(Ihandle *dispCanvas);
int cb_canvasDraw(Ihandle *dispCanvas, float posx, float posy);
int cb_canvasResize(Ihandle *dispCanvas, int width, int height);
int cb_canvasMouse(Ihandle *dispCanvas, int x, int y, char *status);






int cb_btnExit(Ihandle *btn) {
    
    return IUP_CLOSE;
}



int cb_btnDraw(Ihandle *btn) {
    
    Ihandle *txtEntry;
    Ihandle *dispCanvas;
    Ihandle *txtFsize;
    const char *strEntry;
    
    txtFsize = IupGetHandle(TXTFSIZE);
    txtEntry = IupGetHandle(TXTENTRY);
    dispCanvas = IupGetHandle(CANVAS_IUP);
    strEntry = IupGetAttribute(txtEntry, "VALUE");
    
    if (strlen(strEntry) == 0) {
        goto END;
    }
    
    strcpy(strMessage, strEntry);
    iFontSize = IupGetInt(txtFsize, "VALUE");
    
    // Draw updated data on the dispCanvas
    IupUpdate(dispCanvas);
    
    END:
    return IUP_DEFAULT;
}



int cb_canvasMap(Ihandle *dispCanvas) {
    
    cdCanvas *cDraw;
    
//  cDraw = cdCreateCanvas(CD_NATIVEWINDOW, IupGetAttribute(dispCanvas, "WID"));
    cDraw = cdCreateCanvas(CD_IUP, dispCanvas);
    cdCanvasSetBackground(cDraw, CD_DARK_GREEN);
    cdCanvasFont(cDraw, "Times New Roman", -1, 0);
    IupSetAttribute(dispCanvas, CANVAS_CD, (char *) cDraw);
    return IUP_DEFAULT;
}



int cb_canvasUnmap(Ihandle *dispCanvas) {
    
    cdCanvas *cDraw;
    
    cDraw = (cdCanvas *) IupGetAttribute(dispCanvas, CANVAS_CD);
    cdKillCanvas(cDraw);
    return IUP_DEFAULT;
}



int cb_canvasResize(Ihandle *dispCanvas, int width, int height) {
    
    cdCanvas *cDraw;
    
    cDraw = (cdCanvas *) IupGetAttribute(dispCanvas, CANVAS_CD);
    cdCanvasActivate(cDraw);
    return IUP_DEFAULT;
}



int cb_canvasDraw(Ihandle *dispCanvas, float posx, float posy) {
    
    int x, y;
//  int xmin, xmax, ymin, ymax;
    cdCanvas *cDraw;
//  Ihandle *txtEntry;
//  const char *strEntry;
//  
//  txtEntry = IupGetHandle(TXTENTRY);
//  strEntry = IupGetAttribute(txtEntry, "VALUE");
    
    cDraw = (cdCanvas *) IupGetAttribute(dispCanvas, CANVAS_CD);
//  IupGetIntInt(dispCanvas, "DRAWSIZE", &x, &y);
    cdCanvasGetSize(cDraw, &x, &y, 0, 0);
    
    cdCanvasActivate(cDraw);
    cdCanvasSetForeground(cDraw, CD_YELLOW);
    cdCanvasClear(cDraw);
    cdCanvasFont(cDraw, 0, -1, iFontSize);
    
    if (strlen(strMessage) > 0) {
//      cdCanvasTextOrientation(cDraw, 90.0);
//      cdCanvasTextAlignment(cDraw, CD_CENTER);
//      cdCanvasGetTextBox(cDraw, (x-1)/2, (y-1)/2, strEntry, &xmin, &xmax, &ymin, &ymax);
        cdCanvasTextAlignment(cDraw, CD_NORTH_WEST);
        cdCanvasText(cDraw, (x-1)/12, (y-1)/2 + (y-1)/4 + (y-1)/8, strMessage);
//      cdCanvasText(cDraw, (x-1)/2, (y-1)/2, strEntry);
//      cdCanvasRect(cDraw, xmin, xmax, ymin, ymax);
        
        // Draw a Red Filled Circle with cdSector
        cdCanvasSetForeground(cDraw, CD_RED);
        cdCanvasSector(cDraw, (x-1)/2 + (x-1)/4 + (x-1)/8,
                            (y-1)/4, (y-1)/4, (y-1)/4, 0.0, 360.0);
    }
    
//  cdCanvasLineWidth(cDraw, 3);
//  cdCanvasLine(cDraw, 0, 0, (x-1)/2, (y-1)/2);
    
//  cdCanvasTextAlignment(cDraw, CD_NORTH_WEST);
//  cdCanvasVectorTextSize(cDraw, (x-1)/2, (y-1)/2, vText);
//  cdCanvasText(cDraw, (x-1)/8, (y-1)/2 + (y-1)/4 + (y-1)/8, vText);
    
    cdCanvasFlush(cDraw);
    return IUP_DEFAULT;
}



int cb_canvasMouse(Ihandle *dispCanvas, int x, int y, char *status) {
    
    cdCanvas *cDraw;
    int isbt1, isbt2, isbt3;
    long int color;
    int width, height;
    
    cDraw = (cdCanvas *) IupGetAttribute(dispCanvas, CANVAS_CD);
    isbt1 = iup_isbutton1(status);
    isbt2 = iup_isbutton2(status);
    isbt3 = iup_isbutton3(status);
    
    color = CD_RED;
    if (isbt1 == 1) {
        color = CD_YELLOW;
    }
    else if (isbt2 == 1) {
        color = CD_CYAN;
    }
    else if (isbt3 == 1) {
        color = CD_BLUE;
    }
    
    cdCanvasActivate(cDraw);
    cdCanvasGetSize(cDraw, &width, &height, 0, 0);
    cdCanvasSetForeground(cDraw, color);
//  cdCanvasLineWidth
    
    cdCanvasUpdateYAxis(cDraw, &y);
    cdCanvasSector(cDraw, x, y, (height-1)/8, (height-1)/8, 0.0, 360.0);
    cdCanvasFlush(cDraw);
    return IUP_DEFAULT;
}




#include "ICONVIEW.h"
#include "GUI.h"

/* ICONVIEW重绘函数 */
static void __Paint(GUI_HWIN hWin)
{
    ICONVIEW_Obj *pObj = hWin;

}

/* ICONVIEW控件消息处理函数 */
static void __Callback(WM_MESSAGE *pMsg)
{
    switch (pMsg->MsgId) {
    case WM_PAINT :
        __Paint(pMsg->hWin);
        break;
    case WM_TP_CHECKED :
        WM_SetForegroundWindow(pMsg->hWin);
        break;
    case WM_TP_PRESS :
        
        break;
    case WM_TP_LEAVE :
        
        break;
    }
}

/*
* 创建ICONVIEW
* x0:LISTBOX控件的最左像素(相对于父窗口)
* y0:LISTBOX控件的最右像素(相对于父窗口)
* xSize:LISTBOX控件的水平宽度
* ySize:LISTBOX控件的竖直高度
* hParent:父窗口句柄
* Id:窗口ID
* Flag:窗口状态
* cb:用户回调历程指针
**/
GUI_HWIN ICONVIEW_Create(i_16 x0,
    i_16 y0,
    u_16 xSize,
    u_16 ySize,
    WM_HWIN hParent,
    u_16 Id,
    u_8 Style,
    u_16 namepos)
{
    ICONVIEW_Obj *pObj;

    pObj = WM_CreateWindowAsChild(x0, y0, xSize, ySize, hParent,
        Style, Id, __Callback, sizeof(ICONVIEW_Obj) - sizeof(WM_Obj));
    if (pObj == NULL) {
        return NULL;
    }

    return pObj;
}

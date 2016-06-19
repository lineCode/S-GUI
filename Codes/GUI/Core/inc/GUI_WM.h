#ifndef __GUI_WM_H
#define __GUI_WM_H

#include "GUI_Typedef.h"
#include "GUI_Core.h"

/* ϵͳ������Ϣ */
#define WM_INIT_DIALOG       0x0100    /* �Ի����ʼ�� */
#define WM_PAINT             0x0101    /* �ػ� */
#define WM_DELETE            0x0102    /* ɾ������ */
#define WM_CREATED           0x0103    /* �����Ѿ����� */
#define WM_TIME_UPDATA       0x0104    /* ���ڶ�ʱ������ */
#define WM_GET_CLIENT        0x0105    /* ��ȡ�ͻ������ */
#define WM_SET_FOCUS         0x0106    /* ���ý��㴰�� */
#define WM_QUIT              0x0107    /* �˳� */
#define WM_TP_CHECKED        0x0120    /* �����尴�� */
#define WM_TP_REMOVED        0x0121    /* �������ɿ� */
#define WM_TP_PRESS          0x0122    /* ��������һֱ�ڵ�ǰ���� */
#define WM_TP_LEAVE          0x0123    /* ���������뿪��ǰ���� */
#define WM_BUTTON_CLICKED    0x0200    /* BUTTON�ؼ����� */
#define WM_BUTTON_RELEASED   0x0201    /* BUTTON�ؼ��Ѿ��ͷ� */
#define WM_NUTTON_MOVED_OUT  0x0202    /* BUTTON�����Ȼ��ָ���ƿ� */
#define WM_WIONDOW_CHECKED   0x0203    /* ���ڱ���� */
#define WM_LISTBOX_CHECK     0x0204    /* LISTBOX�����(�µ�ѡ����) */
#define WM_KEYDOWN           0x0210    /* �������� */
#define WM_KEYUP             0x0211    /* �����ɿ� */
#define WM_USER_MESSAGE      0x1000    /* �û��Զ������Ϣ */
/* 0x0400�Ժ�Ϊ��չ��Ϣ(�û��Զ���) */

/* ����״̬����(Window status define) */
#define WM_WS_ACTIVE         (1 << 0)   /* ����� */
#define WM_WS_TRANS          (1 << 1)   /* ͸������ */
#define WM_WS_MOVE           (1 << 2)   /* ���ƶ��Ĵ��� */
#define WM_WS_INVAILD        (1 << 3)   /* ��Ч����  */

/* ����ID */
#define WM_NULL_ID          0x0000
#define WM_ROOTWIN_ID       0x0001
#define WM_USER_ID          0x0200

#define _pRootWin ((WM_Obj *)_hRootWin)
#define _RootWin (*_pRootWin)

#define GUI_COUNTOF(a)      (sizeof(a) / sizeof(a[0]))
#define MAX(a, b)           ((a) > (b) ? (a) : (b))
#define MIN(a, b)           ((a) < (b) ? (a) : (b))

typedef GUI_HWIN WM_HWIN;
typedef GUI_MESSAGE WM_MESSAGE;

/* ��Ϣ�����ص����� */
typedef void WM_CALLBACK (WM_MESSAGE *pMsg);

/* ���ڹ��������� */
typedef struct {
    WM_HWIN hParent;        /* ������ָ�� */
    WM_HWIN hFirstChild;    /* ��һ���Ӵ���ָ�� */
    WM_HWIN hNext;          /* ָ����һ��ͬ������ */
    WM_HWIN hNextLine;      /* ָ����һ���� */
    GUI_RECT Rect;          /* ���ڳߴ� */
    GUI_RECT InvalidRect;   /* ������Ч���� */
    GUI_AREA ClipArea;      /* ���ڼ����� */
    WM_CALLBACK *WinCb;     /* ������Ϣ��Ӧ�ص����� */
    u_16 Status;            /* ����״̬ */
    u_16 Id;                /* ����Id */
} WM_Obj;

GUI_RESULT WM_Init(void);
void WM_Exec(void);
void WM__SendMessage(WM_HWIN hWin, WM_MESSAGE *pMsg);
void WM_SendMessage(WM_HWIN hWin, u_16 MsgId, GUI_PARAM Param);
void WM_SendMessageToParent(WM_HWIN hWin, GUI_MESSAGE *pMsg);
GUI_RESULT WM_PostMessage(WM_HWIN hWin, u_16 MsgId, GUI_PARAM Param);
void WM_GetWindowAreaRect(WM_HWIN hWin, GUI_RECT *pRect);
void WM_GetTaliorInvalidRect(WM_HWIN hWin, GUI_RECT *pRect);
WM_HWIN WM_GetFrontWindow(WM_HWIN hWin);
WM_HWIN WM_GetTopChildWindow(WM_HWIN hWin);
WM_HWIN WM_GetTopWindow(void);
void WM_AttachWindow(WM_HWIN hWin, WM_HWIN hParent);
GUI_RESULT WM_SetFocusWindow(WM_HWIN hWin);
GUI_RESULT WM_SetForegroundWindow(WM_HWIN hWin);
WM_HWIN WM_GetForegroundWindow(void);
WM_HWIN WM_CreateWindowAsChild(i_16 x0, i_16 y0, u_16 xSize, u_16 ySize,
    WM_HWIN hParent, u_16 Style, u_16 Id, WM_CALLBACK *WinCb, u_32 bytes);
void WM_DeleteWindow(WM_HWIN hWin);
void WM_InvalidateRect(WM_HWIN hWin, GUI_RECT *pRect);
void WM_Invalidate(WM_HWIN hWin);
GUI_RESULT WM_InvalidTree(WM_HWIN hWin);
GUI_RECT * WM_GetWindowRect(WM_HWIN hWin);
GUI_RECT * WM_GetWindowInvalidRect(WM_HWIN hWin);
GUI_RESULT WM_FindWindow(WM_HWIN hWin);
WM_HWIN WM_GetDialogItem(WM_HWIN hWin, u_16 Id);
WM_HWIN WM_GetWindowHandle(u_16 Id);
u_16 WM_GetDialogId(WM_HWIN hWin);
WM_HWIN WM_GetExposedWindow(u_16 x, u_16 y);
WM_HWIN WM_GetParentHandle(WM_HWIN hWin);
WM_HWIN WM_GetFrontHandle(WM_HWIN hWin);
void WM_MoveWindow(WM_HWIN hWin, i_16 dx, i_16 dy);
void WM_InvalidCoverWindow(WM_HWIN hWin, GUI_RECT *pRect);
WM_HWIN WM_GetClientWindow(WM_HWIN hWin);
GUI_RECT * WM_GetClientRect(WM_HWIN hWin);
GUI_BOOL WM_DefaultKeyProc(GUI_MESSAGE *pMsg);
void WM_DefaultProc(GUI_MESSAGE *pMsg);

#endif /* __GUI_WM_H */
// LINFunctions.h: interface for the CLINFunctions class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINFUNCTIONS_H__CFE0F1C7_2CCA_4700_8EA9_F8BE82F0BDA6__INCLUDED_)
#define AFX_LINFUNCTIONS_H__CFE0F1C7_2CCA_4700_8EA9_F8BE82F0BDA6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "include/vxlapi.h"

typedef struct {
    XLportHandle    xlPortHandle; 
    HANDLE          hMsgEvent;
    CListBox	    *pStatusBox;
    CListBox        *pListRX;
} TStruct;

class CLINFunctions  {
public:
    static constexpr const int MAXPORT = 8;
    static constexpr const int RECEIVE_EVENT_SIZE = 1;     // DO NOT EDIT! Currently 1 is supported only
    static constexpr const int MASTER = 1;     //!< channel is a master
    static constexpr const int SLAVE = 2;     //!< channel is a slave
    static constexpr const int DEFAULT_LIN_DLC = 8;     //!< default DLC for master/slave
    static constexpr const int DEFAULT_LIN_BAUDRATE = 16500;     //!< default LIN baudrate

	CLINFunctions();
	virtual ~CLINFunctions();

    XLstatus LINGetDevice();
    XLstatus LINInit(int linID);
    XLstatus LINSendMasterReq(BYTE data, int linID);
    XLstatus LINClose();
 
    CListBox        *m_pRXBox;
    CListBox        *m_pStatusBox;

private:
    XLstatus         linGetChannelMask();
    XLstatus         linInitMaster(int linID);
    XLstatus         linInitSlave(int linID);
    XLstatus         linCreateRxThread(); 
    XLstatus         linSetSlave(int linID, byte data);

    XLaccess         m_xlChannelMask[MAXPORT];
    XLportHandle     m_xlPortHandle;

    XLhandle         m_hMsgEvent;
    HANDLE           m_hThread;
};

DWORD     WINAPI RxThread( PVOID par );

#endif // !defined(AFX_LINFUNCTIONS_H__CFE0F1C7_2CCA_4700_8EA9_F8BE82F0BDA6__INCLUDED_)

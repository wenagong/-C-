#include "stdafx.h"
#include "CListenSocket.h"
#include"ChatServerDlg.h"

CListenSocket::CListenSocket()
{
}


CListenSocket::~CListenSocket()
{
}


void CListenSocket::OnAccept(int nErrorCode)
{
	// TODO: �ڴ����ר�ô����/����û���
	//AfxMessageBox(_T("����������"));

	((CChatServerDlg*)AfxGetMainWnd())->OnAccept();
	CSocket::OnAccept(nErrorCode);
}

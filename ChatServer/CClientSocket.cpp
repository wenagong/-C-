#include "stdafx.h"
#include "CClientSocket.h"
#include"ChatServerDlg.h"

CClientSocket::CClientSocket()
{
}


CClientSocket::~CClientSocket()
{
}


void CClientSocket::OnReceive(int nErrorCode)
{
	//������Ϣ
	Command cmd;

	Receive(&cmd,sizeof(cmd));

	CString strIPaddress;
	UINT uPort;

	//��ȡ���Ի��򴰿�ָ��
	CChatServerDlg* pMainDlg = (CChatServerDlg*)AfxGetMainWnd();

	switch (cmd.cmd) 
	{
	case LOGIN: 
	{
		//��ȡ�ͻ���IP��ַ
		GetPeerName(strIPaddress, uPort);
		//�����û���
		wchar_t szUsername[30] = { 0 };
		Receive(szUsername, sizeof(szUsername));
		//������ʾ������
		pMainDlg->m_list.InsertItem(0, szUsername);
		pMainDlg->m_list.SetItemText(0, 1, strIPaddress);
		CString strPort;
		strPort.Format(_T("%d"), uPort);
		pMainDlg->m_list.SetItemText(0, 2, strPort);
	}
		break;
	case SEND:
		break;
	}
	CSocket::OnReceive(nErrorCode);
}

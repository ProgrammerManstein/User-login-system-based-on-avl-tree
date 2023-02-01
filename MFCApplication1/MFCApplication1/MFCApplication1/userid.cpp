// userid.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication1.h"
#include "userid.h"
#include "afxdialogex.h"


// userid 对话框

IMPLEMENT_DYNAMIC(userid, CDialogEx)

userid::userid(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
{

}

userid::~userid()
{
}

void userid::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(userid, CDialogEx)
END_MESSAGE_MAP()


// userid 消息处理程序

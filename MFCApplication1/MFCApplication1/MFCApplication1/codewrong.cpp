// codewrong.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication1.h"
#include "codewrong.h"
#include "afxdialogex.h"


// codewrong 对话框

IMPLEMENT_DYNAMIC(codewrong, CDialogEx)

codewrong::codewrong(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_wrong, pParent)
{

}

codewrong::~codewrong()
{
}

void codewrong::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(codewrong, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &codewrong::OnBnClickedButton1)
END_MESSAGE_MAP()


// codewrong 消息处理程序


void codewrong::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

}

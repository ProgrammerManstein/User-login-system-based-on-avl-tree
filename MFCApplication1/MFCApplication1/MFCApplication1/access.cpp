// access.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication1.h"
#include"change.h"
#include "access.h"
#include "afxdialogex.h"
#include "MFCApplication1Dlg.h"
#include"Data.h"

// access 对话框

IMPLEMENT_DYNAMIC(access, CDialogEx)

access::access(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_access, pParent)
{
	
}

access::~access()
{
}

void access::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, idinf);
}


BEGIN_MESSAGE_MAP(access, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON5, &access::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON4, &access::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON1, &access::OnBnClickedButton1)
END_MESSAGE_MAP()


// access 消息处理程序


void access::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(0);
	CMFCApplication1Dlg mfcmain;
	mfcmain.DoModal();
}


void access::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	UserInfo deleteuser;
	BST<UserInfo>* uTree = (BST<UserInfo>*)(Tree);
	deleteuser.setuser(wstring2string(Id.GetBuffer()), wstring2string(password.GetBuffer()));
	ofstream outStream("userinformation.txt");
	uTree->remove(deleteuser);
	uTree->inoderLRV(outStream);
	outStream.close();
	EndDialog(0);
	CMFCApplication1Dlg mfcmain;
	mfcmain.DoModal();
}


void access::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(0);
	change cg;
	cg.Id = Id;
	cg.password = password;
	cg.Tree = Tree;
	cg.DoModal();
}

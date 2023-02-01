// newuser.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication1.h"
#include "newuser.h"
#include "afxdialogex.h"
#include"Data.h"
#include "MFCApplication1Dlg.h"


// newuser 对话框

IMPLEMENT_DYNAMIC(newuser, CDialogEx)

newuser::newuser(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

newuser::~newuser()
{
}

void newuser::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, newid);
	DDX_Control(pDX, IDC_EDIT2, newpassword);
}


BEGIN_MESSAGE_MAP(newuser, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &newuser::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &newuser::OnBnClickedButton2)
END_MESSAGE_MAP()


// newuser 消息处理程序


void newuser::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UserInfo new_user;
	BST<UserInfo>* uTree = (BST<UserInfo>*)(Tree);
	CString ChangeID;
	CString ChangePassword;
	newid.GetWindowTextW(ChangeID);
	newpassword.GetWindowTextW(ChangePassword);
	wstring wstrID(ChangeID.GetBuffer());
	wstring wstrpassword(ChangePassword.GetBuffer());
	string strID = wstring2string(wstrID);
	string strpassword = wstring2string(wstrpassword);
	new_user.setuser(strID, strpassword);
	ofstream outStream("userinformation.txt");
	uTree->insert(new_user);
	uTree->inoderLRV(outStream);
	outStream.close();
	EndDialog(0);
	CMFCApplication1Dlg mfcmain;
	mfcmain.DoModal();
}


void newuser::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(0);
	CMFCApplication1Dlg mfcmain;
	mfcmain.DoModal();
}

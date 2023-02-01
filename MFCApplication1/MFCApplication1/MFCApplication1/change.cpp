// change.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication1.h"
#include "change.h"
#include "afxdialogex.h"
#include "access.h"
#include "afxdialogex.h"
#include "MFCApplication1Dlg.h"
#include"Data.h"


// change 对话框

IMPLEMENT_DYNAMIC(change, CDialogEx)

change::change(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_change, pParent)
{

}

change::~change()
{
}

void change::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, change_id);
	DDX_Control(pDX, IDC_EDIT2, change_password);
}


BEGIN_MESSAGE_MAP(change, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &change::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &change::OnBnClickedButton2)
END_MESSAGE_MAP()


// change 消息处理程序


void change::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UserInfo changeuser;
	UserInfo deleteuser;
	deleteuser.setuser(wstring2string(Id.GetBuffer()), wstring2string(password.GetBuffer()));
	BST<UserInfo>* uTree = (BST<UserInfo>*)(Tree);
	CString ChangeID;
	CString ChangePassword;
	change_id.GetWindowTextW(ChangeID);
	change_password.GetWindowTextW(ChangePassword);
	wstring wstrID(ChangeID.GetBuffer());
	wstring wstrpassword(ChangePassword.GetBuffer());
	string strID = wstring2string(wstrID);
	string strpassword = wstring2string(wstrpassword);
	changeuser.setuser(strID, strpassword);
	ofstream outStream("userinformation.txt");
	uTree->remove(deleteuser);
	uTree->insert(changeuser);
	uTree->inoderLRV(outStream);
	outStream.close();
	EndDialog(0);
	access ac;
	ac.Id = Id;
	ac.password = password;
	ac.Tree = &userTree;
	ac.DoModal();
}


void change::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(0);
	access ac;
	ac.Id = Id;
	ac.password = password;
	ac.Tree = Tree;
	ac.DoModal();
}

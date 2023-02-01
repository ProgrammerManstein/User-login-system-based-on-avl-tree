#pragma once


// change 对话框

class change : public CDialogEx
{
	DECLARE_DYNAMIC(change)

public:
	change(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~change();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_change };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit change_id;
	CEdit change_password;
	afx_msg void OnBnClickedButton1();
	CButton idinf;
	CString Id, password;
	LPCVOID Tree;
	afx_msg void OnBnClickedButton2();
};

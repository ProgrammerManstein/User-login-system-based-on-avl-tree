#pragma once


// access 对话框

class access : public CDialogEx
{
	DECLARE_DYNAMIC(access)

public:
	access(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~access();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_access };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton4();
	CButton idinf;
	CString Id, password;
	LPCVOID Tree;
	afx_msg void OnBnClickedButton1();
};

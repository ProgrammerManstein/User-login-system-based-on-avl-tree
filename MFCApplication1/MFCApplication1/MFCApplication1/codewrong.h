#pragma once


// codewrong 对话框

class codewrong : public CDialogEx
{
	DECLARE_DYNAMIC(codewrong)

public:
	codewrong(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~codewrong();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_wrong };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};

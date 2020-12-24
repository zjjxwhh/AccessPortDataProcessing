
// AccessPortDataProcessingDlg.h: 头文件
//

#pragma once


// CAccessPortDataProcessingDlg 对话框
class CAccessPortDataProcessingDlg : public CDialogEx
{
// 构造
public:
	CAccessPortDataProcessingDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ACCESSPORTDATAPROCESSING_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCheckNo();
	afx_msg void OnBnClickedCheckTime();
	afx_msg void OnBnClickedCheckDuration();
	afx_msg void OnBnClickedCheckProcess();
	afx_msg void OnBnClickedCheckRequest();
	afx_msg void OnBnClickedCheckPort();
	afx_msg void OnBnClickedCheckResult();
	afx_msg void OnBnClickedCheckData();
	afx_msg void OnBnClickedButtonDataProcessing();
	BOOL m_check_bNo;
	BOOL m_check_bTime;
	BOOL m_check_bDuration;
	BOOL m_check_bProcess;
	BOOL m_check_bRequest;
	BOOL m_check_bPort;
	BOOL m_check_bResult;
	BOOL m_check_bData;
	CString m_cstrPathIni;
	void UpdateState();
};

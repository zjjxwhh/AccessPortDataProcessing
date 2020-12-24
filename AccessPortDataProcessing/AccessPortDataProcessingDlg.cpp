
// AccessPortDataProcessingDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "AccessPortDataProcessing.h"
#include "AccessPortDataProcessingDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAccessPortDataProcessingDlg 对话框



CAccessPortDataProcessingDlg::CAccessPortDataProcessingDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ACCESSPORTDATAPROCESSING_DIALOG, pParent)
	, m_check_bNo(TRUE)
	, m_check_bTime(FALSE)
	, m_check_bDuration(FALSE)
	, m_check_bProcess(FALSE)
	, m_check_bRequest(FALSE)
	, m_check_bPort(FALSE)
	, m_check_bResult(FALSE)
	, m_check_bData(TRUE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON_FILE);
}

void CAccessPortDataProcessingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK_NO, m_check_bNo);
	DDX_Check(pDX, IDC_CHECK_TIME, m_check_bTime);
	DDX_Check(pDX, IDC_CHECK_DURATION, m_check_bDuration);
	DDX_Check(pDX, IDC_CHECK_PROCESS, m_check_bProcess);
	DDX_Check(pDX, IDC_CHECK_REQUEST, m_check_bRequest);
	DDX_Check(pDX, IDC_CHECK_PORT, m_check_bPort);
	DDX_Check(pDX, IDC_CHECK_RESULT, m_check_bResult);
	DDX_Check(pDX, IDC_CHECK_DATA, m_check_bData);
}

BEGIN_MESSAGE_MAP(CAccessPortDataProcessingDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CHECK_NO, &CAccessPortDataProcessingDlg::OnBnClickedCheckNo)
	ON_BN_CLICKED(IDC_CHECK_TIME, &CAccessPortDataProcessingDlg::OnBnClickedCheckTime)
	ON_BN_CLICKED(IDC_CHECK_DURATION, &CAccessPortDataProcessingDlg::OnBnClickedCheckDuration)
	ON_BN_CLICKED(IDC_CHECK_PROCESS, &CAccessPortDataProcessingDlg::OnBnClickedCheckProcess)
	ON_BN_CLICKED(IDC_CHECK_REQUEST, &CAccessPortDataProcessingDlg::OnBnClickedCheckRequest)
	ON_BN_CLICKED(IDC_CHECK_PORT, &CAccessPortDataProcessingDlg::OnBnClickedCheckPort)
	ON_BN_CLICKED(IDC_CHECK_RESULT, &CAccessPortDataProcessingDlg::OnBnClickedCheckResult)
	ON_BN_CLICKED(IDC_CHECK_DATA, &CAccessPortDataProcessingDlg::OnBnClickedCheckData)
	ON_BN_CLICKED(IDC_BUTTON_DATA_PROCESSING, &CAccessPortDataProcessingDlg::OnBnClickedButtonDataProcessing)
END_MESSAGE_MAP()


// CAccessPortDataProcessingDlg 消息处理程序

BOOL CAccessPortDataProcessingDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	CString cstrPathHlp = AfxGetApp()->m_pszHelpFilePath;
	CString cstrExeName = AfxGetApp()->m_pszExeName;
	m_cstrPathIni = cstrPathHlp.Left(cstrPathHlp.GetLength() - cstrExeName.GetLength() - 4) + _T("config.ini");
	m_cstrPathIni.Replace(_T("\\"), _T("\\\\"));

	if(PathFileExists(m_cstrPathIni))
	{
		CString cstr;
		CStdioFile fileConfig;
		fileConfig.Open(m_cstrPathIni, CFile::modeRead);		// 打开文件：读取

		fileConfig.ReadString(cstr);
		m_check_bNo = _ttoi(cstr.Right(1));

		fileConfig.ReadString(cstr);
		m_check_bTime = _ttoi(cstr.Right(1));

		fileConfig.ReadString(cstr);
		m_check_bDuration = _ttoi(cstr.Right(1));

		fileConfig.ReadString(cstr);
		m_check_bProcess = _ttoi(cstr.Right(1));

		fileConfig.ReadString(cstr);
		m_check_bRequest = _ttoi(cstr.Right(1));

		fileConfig.ReadString(cstr);
		m_check_bPort = _ttoi(cstr.Right(1));

		fileConfig.ReadString(cstr);
		m_check_bResult = _ttoi(cstr.Right(1));

		fileConfig.ReadString(cstr);
		m_check_bData = _ttoi(cstr.Right(1));

		UpdateData(FALSE);
		fileConfig.Close();

	}

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CAccessPortDataProcessingDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CAccessPortDataProcessingDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CAccessPortDataProcessingDlg::OnBnClickedCheckNo()
{
	UpdateState();
}


void CAccessPortDataProcessingDlg::OnBnClickedCheckTime()
{
	UpdateState();
}


void CAccessPortDataProcessingDlg::OnBnClickedCheckDuration()
{
	UpdateState();
}


void CAccessPortDataProcessingDlg::OnBnClickedCheckProcess()
{
	UpdateState();
}


void CAccessPortDataProcessingDlg::OnBnClickedCheckRequest()
{
	UpdateState();
}


void CAccessPortDataProcessingDlg::OnBnClickedCheckPort()
{
	UpdateState();
}


void CAccessPortDataProcessingDlg::OnBnClickedCheckResult()
{
	UpdateState();
}


void CAccessPortDataProcessingDlg::OnBnClickedCheckData()
{
	UpdateState();
}


void CAccessPortDataProcessingDlg::OnBnClickedButtonDataProcessing()
{
	CString cstrPathOpen, cstrPathSave;
	CStdioFile fileOpen, fileSave;

	CFileDialog FileOpenDlg(TRUE, NULL, _T("untitle.txt"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, _T("Txt(*.txt)|*.txt||"), this);
	if(FileOpenDlg.DoModal() == IDOK)
	{
		cstrPathOpen = FileOpenDlg.GetPathName();
		fileOpen.Open(cstrPathOpen, CFile::modeRead);		// 打开文件：读取

	}
	else
	{
		return;
	}

	CFileDialog FlieSaveDlg(FALSE, NULL, _T("untitle_processed.txt"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, _T("Txt(*.txt)|*.txt||"), this);
	if(FlieSaveDlg.DoModal() == IDOK)
	{
		cstrPathSave = FlieSaveDlg.GetPathName();
		fileSave.Open(cstrPathSave, CFile::modeCreate | CFile::modeWrite);		// 打开文件：创建/覆盖
	}
	else
	{
		return;
	}

	UpdateData(TRUE);
	int nFlag[8] = { m_check_bNo, m_check_bTime, m_check_bDuration, m_check_bProcess, m_check_bRequest, m_check_bPort, m_check_bResult, m_check_bData };

	CString cstrRead, cstrWrite;
	int nTab;

	while(fileOpen.ReadString(cstrRead))
	{
		if(_ttoi(cstrRead.Left(1)) > 0 && _ttoi(cstrRead.Left(1)) <= 9)		// 开头为数字：保证该行是数据行
		{
			if(cstrRead.Find(_T("MASK")) == -1 && cstrRead.Find(_T("Purge")) == -1)		// 排除 MASK 及 Purge 信息
			{
				for(int i = 0; i < 8; i++)
				{

					nTab = cstrRead.Find(_T("\t"));
					cstrWrite = cstrRead.Left(nTab) + _T("\t");
					cstrRead = cstrRead.Right(cstrRead.GetLength() - nTab - 1);

					if(nFlag[i]== TRUE)		// 选框被选中时输出相应数据
					{
						if(i == 7)			// 处理 Data(Hex) 部分，使 Length 及 Data 分别对齐
						{
							CString cstr1, cstr2;
							cstr1 = cstrWrite.Left(cstrWrite.Find(_T(" Data:"))) + _T("   \t");
							cstr2 = cstrWrite.Right(cstrWrite.GetLength() - cstrWrite.Find(_T(" Data:")));
							cstrWrite = cstr1 + cstr2;
						}
						fileSave.WriteString(cstrWrite);
					}
				}
				fileSave.WriteString(_T("\n"));
			}
		}
	}

	ShellExecute(NULL, _T("open"), cstrPathSave, NULL, NULL, SW_SHOW);		// 打开数据文件

	fileSave.Close();
	fileOpen.Close();
}

void CAccessPortDataProcessingDlg::UpdateState()
{
	UpdateData(TRUE);
	CString cstr;
	CStdioFile fileConfig;
	fileConfig.Open(m_cstrPathIni, CFile::modeCreate | CFile::modeWrite);		// 打开文件：读取

	cstr.Format(_T("m_check_bNo = %d\n"), (int)m_check_bNo);
	fileConfig.WriteString(cstr);

	cstr.Format(_T("m_check_bTime = %d\n"), (int)m_check_bTime);
	fileConfig.WriteString(cstr);

	cstr.Format(_T("m_check_bDuration = %d\n"), (int)m_check_bDuration);
	fileConfig.WriteString(cstr);

	cstr.Format(_T("m_check_bProcess = %d\n"), (int)m_check_bProcess);
	fileConfig.WriteString(cstr);

	cstr.Format(_T("m_check_bRequest = %d\n"), (int)m_check_bRequest);
	fileConfig.WriteString(cstr);

	cstr.Format(_T("m_check_bPort = %d\n"), (int)m_check_bPort);
	fileConfig.WriteString(cstr);

	cstr.Format(_T("m_check_bResult = %d\n"), (int)m_check_bResult);
	fileConfig.WriteString(cstr);

	cstr.Format(_T("m_check_bData = %d\n"), (int)m_check_bData);
	fileConfig.WriteString(cstr);

	fileConfig.Close();
}

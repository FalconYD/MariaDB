
// MariaDBTest_CPPDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MariaDBTest_CPP.h"
#include "MariaDBTest_CPPDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMariaDBTestCPPDlg 대화 상자



CMariaDBTestCPPDlg::CMariaDBTestCPPDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MARIADBTEST_CPP_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMariaDBTestCPPDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMariaDBTestCPPDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Bn_Open, &CMariaDBTestCPPDlg::OnBnClickedBnOpen)
	ON_BN_CLICKED(IDC_Bn_Query, &CMariaDBTestCPPDlg::OnBnClickedBnQuery)
	ON_BN_CLICKED(IDC_Bn_Preset_Select, &CMariaDBTestCPPDlg::OnBnClickedBnPresetSelect)
	ON_BN_CLICKED(IDC_Bn_Preset_Insert, &CMariaDBTestCPPDlg::OnBnClickedBnPresetInsert)
	ON_BN_CLICKED(IDC_Bn_Preset_Delete, &CMariaDBTestCPPDlg::OnBnClickedBnPresetDelete)
	ON_BN_CLICKED(IDC_Bn_Preset_Update, &CMariaDBTestCPPDlg::OnBnClickedBnPresetUpdate)
END_MESSAGE_MAP()


// CMariaDBTestCPPDlg 메시지 처리기

BOOL CMariaDBTestCPPDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMariaDBTestCPPDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMariaDBTestCPPDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMariaDBTestCPPDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMariaDBTestCPPDlg::OnBnClickedBnOpen()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_fn_InitDb();
}

/**	
@fn		m_fn_InitDb()
@brief	DB 초기화
@return	void
@param	void
@remark	
 - DB 접근 및 listctrl에 데이터 뷰
@author	선경규(Kyeong Kyu - Seon)
@date	2019/12/24  15:51
*/
void CMariaDBTestCPPDlg::m_fn_InitDb()
{
	MYSQL* connection = NULL;
	MYSQL conn;
	MYSQL_RES* sql_result;
	MYSQL_ROW sql_row;
	MYSQL_FIELD* sql_field;
	CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST_DATA);

	if (mysql_init(&conn) == NULL)
	{
		//error
		AfxMessageBox(_T("Sql Init Error"));
		return;
	}

	connection = mysql_real_connect(&conn, host, user, pw, db, 3306, (const char*)NULL, 0);
	if (connection == NULL) // Connection Error
	{
		// error
		AfxMessageBox(_T("Sql Connection Error"));
		return;
	}
	else
	{

		if (mysql_select_db(&conn, db)) // database Select
		{
			AfxMessageBox(_T("Db Select Error"));
			return;
		}

		char* query = "select * from testtable";
		TCHAR data[MAX_PATH] = { 0, };
		int state = 0;
		int nCols = 0, nRows = 0;
		state = mysql_query(connection, query);

		if (state == 0)
		{
			sql_result = mysql_store_result(connection);


			pListCtrl->DeleteAllItems();
			for (nCols = 0; nCols < ((CHeaderCtrl*)pListCtrl->GetHeaderCtrl())->GetItemCount(); nCols++)
			{
				pListCtrl->DeleteColumn(0);
			}
			pListCtrl->SetExtendedStyle(LVS_EX_GRIDLINES);
			nCols = 0;
			while (sql_field = mysql_fetch_field(sql_result))
			{
				memset(data, 0x00, sizeof(data[0]) * MAX_PATH);
				_in_fn_Multi2Uni_UTF8(sql_field->name, data);
				pListCtrl->InsertColumn(nCols++, data, LVCFMT_CENTER, 50, -1);
			}

			while ((sql_row = mysql_fetch_row(sql_result)) != NULL) // Result Set에서 1개씩 배열에 가저옴.
			{
				// insert data
				memset(data, 0x00, sizeof(data[0]) * MAX_PATH);
				_stprintf_s(data, _T("%d"), nRows);
				pListCtrl->InsertItem(nRows, data);
				memset(data, 0x00, sizeof(data[0]) * MAX_PATH);
				for (nCols = 0; nCols < static_cast<signed int>(sql_result->field_count); nCols++)
				{
					_in_fn_Multi2Uni(sql_row[nCols], data);
					pListCtrl->SetItem(nRows, nCols, LVIF_TEXT, data, 0, 0, 0, NULL);
					memset(data, 0x00, sizeof(data[0]) * MAX_PATH);
				}
				nRows++;
			}
			mysql_free_result(sql_result); //Result Set 해제
		}
		mysql_close(connection);
	}
}

/**
@brief	Unicode to MultiByte
@return	멀티바이트 문자열
@param	유니코드 문자열
@remark
- Unicode를 Multibyte로 변환 하는 함수.
@author	선경규(Kyeong Kyu - Seon)
@date	2018/4/24  13:18
*/
inline void CMariaDBTestCPPDlg::_in_fn_Uni2Multi(wchar_t* InputString, char* OutString)
{
	//if (wcslen(InputString) <= sizeof(wchar_t) * strlen(OutString))
	if (wcslen(InputString) > 0)
	{
		int len = WideCharToMultiByte(CP_ACP, 0, InputString, -1, NULL, 0, NULL, NULL);
		WideCharToMultiByte(CP_ACP, 0, InputString, -1, OutString, len, NULL, NULL);
	}
	else
	{
		OutputDebugString(_T("Not Enough OutString Buffer."));
	}
}

/**
@brief	MultiByte to Unicode
@return	유니코드 문자열
@param	멀티바이트 문자열
@remark
- Multibyte를 Unicode로 변환하는 함수.
@author	선경규(Kyeong Kyu - Seon)
@date	2018/4/24  13:19
*/
inline void CMariaDBTestCPPDlg::_in_fn_Multi2Uni(char* InputString, wchar_t* OutString)
{
	//if (strlen(InputString) < sizeof(char) * wcslen(OutString))
	if(strlen(InputString) > 0)
	{
		static wchar_t strUnicode[1024] = { 0, };
		int nLen = MultiByteToWideChar(CP_ACP, 0, InputString, (int)strlen(InputString), NULL, NULL);
		MultiByteToWideChar(CP_ACP, 0, InputString, (int)strlen(InputString), OutString, nLen);
	}
	else
	{
		OutputDebugString(_T("Not Enough OutString Buffer."));
	}
}

/**
@brief	MultiByte to Unicode_UTF8
@return	유니코드 문자열(UTF8)
@param	멀티바이트 문자열
@remark
- Multibyte를 Unicode로 변환하는 함수.
@author	선경규(Kyeong Kyu - Seon)
@date	2018/4/24  13:19
*/
inline void CMariaDBTestCPPDlg::_in_fn_Multi2Uni_UTF8(const char* InputString, wchar_t* OutString)
{
	//if (strlen(InputString) < sizeof(char) * wcslen(OutString))
	if (strlen(InputString) > 0 && strlen(InputString) < 1024)
	{
		static wchar_t strUnicode[1024] = { 0, };
		int nLen = MultiByteToWideChar(CP_UTF8, 0, InputString, (int)strlen(InputString), NULL, NULL);
		MultiByteToWideChar(CP_UTF8, 0, InputString, (int)strlen(InputString), OutString, nLen);
	}
	else
	{
		OutputDebugString(_T("InputString Length Error."));
	}
}

void CMariaDBTestCPPDlg::OnBnClickedBnQuery()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_fn_ExecuteQuery();
	m_fn_InitDb();
}

/**	
@fn		m_fn_ExecuteQuery()
@brief	쿼리 실행
@return	void
@param	void
@remark	
 - EditControl에 있는 Query문 실행
@author	선경규(Kyeong Kyu - Seon)
@date	2019/12/24  15:51
*/
void CMariaDBTestCPPDlg::m_fn_ExecuteQuery()
{
	const int QUERYMAXLENGTH = 1024;
	MYSQL* connection = NULL;
	MYSQL conn;
	TCHAR strEdit[QUERYMAXLENGTH] = { 0, };
	char strQuery[QUERYMAXLENGTH] = { 0, };

	if (mysql_init(&conn) == NULL)
	{
		//error
		return;
	}

	connection = mysql_real_connect(&conn, host, user, pw, db, 3306, (const char*)NULL, 0);
	if (connection == NULL) // Connection Error
	{
		// error
		AfxMessageBox(_T("Sql Connection Error"));
		return;
	}
	else
	{
		if (mysql_select_db(&conn, db)) // database Select
		{
			AfxMessageBox(_T("Db Select Error"));
			return;
		}

		GetDlgItem(IDC_EDIT_Query)->GetWindowText(strEdit, QUERYMAXLENGTH);

		_in_fn_Uni2Multi(strEdit, strQuery);
		int state = 0;
		state = mysql_query(connection, strQuery);

		if (state == 0)
		{
			// Success
		}
		mysql_close(connection);
	}
}
#pragma region Preset
void CMariaDBTestCPPDlg::OnBnClickedBnPresetSelect()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	GetDlgItem(IDC_EDIT_Query)->SetWindowText(_T("SELECT FieldName FROM testtable WHERE FieldName = val"));
}


void CMariaDBTestCPPDlg::OnBnClickedBnPresetInsert()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	GetDlgItem(IDC_EDIT_Query)->SetWindowText(_T("INSERT INTO testtable(FieldName1, FieldName2, FieldName3, ...) VALUES(val1, val2, val3, ...)"));
}


void CMariaDBTestCPPDlg::OnBnClickedBnPresetDelete()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	GetDlgItem(IDC_EDIT_Query)->SetWindowText(_T("DELETE FROM testtable WHERE FieldName = val"));
}

void CMariaDBTestCPPDlg::OnBnClickedBnPresetUpdate()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	GetDlgItem(IDC_EDIT_Query)->SetWindowText(_T("UPDATE testtable SET FieldName1 = val1, FieldName2 = val2, ... WHERE FieldName = val"));
}
#pragma endregion

/**	
@fn		BOOL PreTranslateMessage(MSG* pMsg)
@brief	키 입력 메시지 처리기
@return	bool
@param	MSG 구조체 포인터
@remark	
 - 엔터시 EditControl에 있는 Text 쿼리 실행.
@author	선경규(Kyeong Kyu - Seon)
@date	2019/12/24  15:56
*/
BOOL CMariaDBTestCPPDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE)
		return TRUE;
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN)
	{
		if (GetDlgItem(IDC_EDIT_Query) == GetFocus())
		{
			OnBnClickedBnQuery();
		}
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}

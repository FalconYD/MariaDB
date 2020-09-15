
// MariaDBTest_CPPDlg.h: 헤더 파일
//

#pragma once


// CMariaDBTestCPPDlg 대화 상자
class CMariaDBTestCPPDlg : public CDialogEx
{
// 생성입니다.
public:
	CMariaDBTestCPPDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MARIADBTEST_CPP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	const char* host = "localhost";
	const char* user = "root";
	const char* pw = "1234";
	const char* db = "testdb";
	inline void _in_fn_Multi2Uni(char* InputString, wchar_t* OutString);
	inline void _in_fn_Uni2Multi(wchar_t* InputString, char* OutString);
	inline void _in_fn_Multi2Uni_UTF8(const char* InputString, wchar_t* OutString);
	void m_fn_InitDb();
	void m_fn_ExecuteQuery();

public:
	afx_msg void OnBnClickedBnOpen();
	afx_msg void OnBnClickedBnQuery();
	afx_msg void OnBnClickedBnPresetSelect();
	afx_msg void OnBnClickedBnPresetInsert();
	afx_msg void OnBnClickedBnPresetDelete();
	afx_msg void OnBnClickedBnPresetUpdate();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};

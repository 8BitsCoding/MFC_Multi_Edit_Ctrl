
// MFCApplication1Dlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1Dlg 대화 상자



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_TEXT_BTN, &CMFCApplication1Dlg::OnBnClickedTextBtn)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 메시지 처리기

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCApplication1Dlg::OnPaint()
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
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication1Dlg::OnBnClickedTextBtn()
{
	// 이론
	// ::FindWindowEx(m_hWnd, NULL, L"edit", NULL);
	// m_hWnd의 윈도우에
	// NULL 모든 윈도우를 검색
	// edit으로 된
	// NULL 검색어는 없음 -> 검색어를 넣고 싶다면 L"~~"넣으면 됨.

	/*
	// WIN32 Style
	HWND h_find_wnd = NULL;
	while (h_find_wnd = ::FindWindowEx(m_hWnd, h_find_wnd, L"edit", NULL)) {
		::SetWindowText(h_find_wnd, L"Hello~");
		// 이렇게 하면 모든 edit 컨트롤에 Hello~가 찍힌다.
	}
	// 만약 버튼을 찾고 싶다면?
	// while (h_find_wnd = ::FindWindowEx(m_hWnd, h_find_wnd, L"button", NULL)) {
	*/

	/*
	// MFC Style 1
	HWND h_find_wnd = NULL;
	CWnd * p_find_wnd = FindWindowEx(m_hWnd, NULL, L"edit", NULL);
	while (p_find_wnd != NULL) {
		p_find_wnd->SetWindowText(L"Hello~");
		p_find_wnd = FindWindowEx(m_hWnd, p_find_wnd->m_hWnd, L"edit", NULL);
	}
	*/

	/*
	// MFC Style + WIN32 Sytle
	HWND h_find_wnd = NULL;
	CWnd * p_find_wnd = NULL;
	while (p_find_wnd = FindWindowEx(m_hWnd, h_find_wnd, L"edit", NULL)) {
		p_find_wnd->SetWindowText(L"Hello~");
		h_find_wnd = p_find_wnd->m_hWnd;
	}
	*/

	/*
	// 다른 방법(임시 객체를 쓰는 방법)
	HWND h_find_wnd = NULL;
	CWnd * p_find_wnd = NULL;
	while (p_find_wnd = FindWindowEx(m_hWnd, h_find_wnd, L"edit", NULL)) {
		p_find_wnd = CWnd::FromHandle(h_find_wnd);
		p_find_wnd->SetWindowText(L"Hello~");
	}
	*/

	HWND h_find_wnd = NULL;
	CWnd find_wnd;
	while (h_find_wnd = ::FindWindowEx(m_hWnd, h_find_wnd, L"edit", NULL)) {
		find_wnd.Attach(h_find_wnd);
		find_wnd.SetWindowText(L"Hello~");
		find_wnd.Detach();
	}
}

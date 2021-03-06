
// ReadNumberDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "ReadNumber.h"
#include "ReadNumberDlg.h"
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


// CReadNumberDlg 대화 상자



CReadNumberDlg::CReadNumberDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_READNUMBER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

BOOL CReadNumberDlg::PreTranslateMessage(MSG * message)
{
	if (message->message == WM_KEYUP)
		if (message->wParam == VK_F5)
			this->OnKeyUp(VK_F5, 0, 0);

	return CDialog::PreTranslateMessage(message);
}

void CReadNumberDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CReadNumberDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_BN_CLICKED(ID_BUTTON_READ, &CReadNumberDlg::OnBnClickedButtonRead)
	ON_WM_KEYUP()
END_MESSAGE_MAP()


// CReadNumberDlg 메시지 처리기

BOOL CReadNumberDlg::OnInitDialog()
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

void CReadNumberDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CReadNumberDlg::OnPaint()
{
	DrawCrossLine();

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

void CReadNumberDlg::DrawCrossLine()
{
	constexpr auto color = RGB(80, 80, 80); //회색

	CClientDC dc(this);
	CPen pen;
	pen.CreatePen(PS_DOT, 1, color);
	dc.SelectObject(&pen);

	//세로선
	dc.MoveTo({ 100,0 });
	dc.LineTo({ 100,210 });

	//가로선
	dc.MoveTo({ 0,90 });
	dc.LineTo({ 210,90 });
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CReadNumberDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CReadNumberDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	//그림
	if (nFlags == MK_LBUTTON)
	{
		CClientDC dc(this);
		dc.MoveTo(old_pos);
		dc.LineTo(point);
	}

	old_pos = point;
	
	DrawCrossLine();

	CDialogEx::OnMouseMove(nFlags, point);
}


void CReadNumberDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (stroke_count == 0) //처음 누를때
	{
		this->first_line.first = point;
	}
	else if (stroke_count == 1) //두번째 누를때
	{
		this->second_line.first = point;
	}
	stroke_count++;

	CDialogEx::OnLButtonDown(nFlags, point);
}



void CReadNumberDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CString str;

	if (stroke_count == 1) //처음 누를때
	{
		this->first_line.second = point;

		str.Format(L"(%d,%d)(%d,%d)",
			first_line.first.x, first_line.first.y,
			first_line.second.x, first_line.second.y);
	}
	else if (stroke_count == 2) //두번째 누를때
	{
		this->second_line.second = point;

		str.Format(L"(%d,%d)(%d,%d)",
			second_line.first.x, second_line.first.y,
			second_line.second.x, second_line.second.y);
	}
	else
	{ }

	SetWindowText(str); //좌표확인용

	CDialogEx::OnLButtonUp(nFlags, point);
}


#include <cmath>

void CReadNumberDlg::OnBnClickedButtonRead()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (stroke_count == 0)
	{
		MessageBox(L"stroke가 너무 적어 분석 불가");
	}


	else if (stroke_count == 1) //0 1 2 3 6 8 9 처리
	{
		auto from = first_line.first;
		auto to = first_line.second;

		if (abs(from.x - to.x) < 10 && //오차범위 10
			abs(from.y - to.y) < 10) //한 점으로 되돌아오는건 0과 8
		{
			if (90 < from.x&&from.x < 110 &&
				80 < from.y&&from.y < 100) //중심에 가까우면 8
				MessageBox(L"8인 것 같네요");
			else
				MessageBox(L"0인 것 같네요");
			//MessageBox(L"일단 0이나 8인 것 같네요");
		}

		else //1 2 3 6 9
		{
			if (abs(from.x - to.x) < 10 && //x좌표가 동일하고 (오차범위 10)
				abs(from.y - to.y) > 60 && //길이 60 이상
				80 <from.x && from.x <110) //그리고 중간에 있어야 함
			{
				MessageBox(L"1인 것 같네요");
			}

			//이제 2 3 6 9 남음
			else if (from.x<100 && from.y<100) //2와 3은 시작점이 좌상단
			{
				if(to.x>100 && to.y>100)
					MessageBox(L"2인 것 같네요");
				else if(to.x<100&& to.y>100)
					MessageBox(L"3인 것 같네요");
			}

			//6 처리
			else if (from.x > 100 && from.y < 100 && //시작점 우상단
					 to.x <100 && to.y>100) //종료점 좌하단
			{
				MessageBox(L"6인 것 같네요");
			}

			//9 처리
			else if (from.x > 100 && from.y < 100 && //시작점 우상단
					 to.x > 100 && to.y>100) //종료점 우하단
			{
				MessageBox(L"9인 것 같네요");
			}

			else
			{
				MessageBox(L"뭔지 모르겠어요");
			}
		}
	}


	else if (stroke_count == 2) //4 5 7처리
	{
		//4 처리.
		if (80 < first_line.first.x && first_line.first.x < 120 && //첫번째 시작점이 중앙 위에 있고
			first_line.first.y < 100 && 
			100 < first_line.second.x && //첫번째 종료점이 오른쪽에 있으며
			abs(second_line.first.x - second_line.second.x) < 20 &&//두번째 x좌표가 동일하고
			abs(second_line.first.y - second_line.second.y) > 50 && //길이 50 이상
			80 < second_line.first.x && second_line.first.x < 120) //그리고 중간에
		{
			MessageBox(L"4인 것 같네요");
		}
		//5 처리
		else if (first_line.first.x < 100 && first_line.first.y < 100 && //첫번째 시작점은 좌상단
			first_line.second.x < 100 && first_line.second.y>100 && //첫번째 종료점은 좌하단
			second_line.first.x < 100 && second_line.first.y < 100 && //두번째 시작점 좌상단
			second_line.second.x>100 && second_line.second.y) //두번째 종료점 우상단
		{
			MessageBox(L"5인 것 같네요");
		}
		//7 처리
		else if (first_line.first.x < 100 && first_line.first.y < 100 && //첫번째는 전부
				 first_line.second.x < 100 && first_line.second.y < 100 && //좌상단
				 second_line.first.x <100&& second_line.first.y<100&& //두번째 시작점도 좌상단
				 second_line.second.x >100&& second_line.second.y>100) //두번째 종료점은 우하단
		{
			MessageBox(L"7인 것 같네요");
		}

		else
			MessageBox(L"뭔지 모르겠어요");
	}


	else
	{	
		MessageBox(L"stroke가 너무 많아 분석 불가");
	}

	//clear
	Invalidate(true);
	this->OnPaint();
	stroke_count = 0;
	first_line = { {0,0},{0,0} };
	second_line = { {0,0},{0,0} };
}


void CReadNumberDlg::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	
	if (nChar == VK_RETURN) //엔터 누를경우
		OnBnClickedButtonRead(); //위임
	
	if (nChar == VK_F5) //새로고침
	{
		Invalidate(true);
		this->OnPaint();
		stroke_count = 0;
		first_line = { { 0,0 },{ 0,0 } };
		second_line = { { 0,0 },{ 0,0 } };
	}

	CDialogEx::OnKeyUp(nChar, nRepCnt, nFlags);
}

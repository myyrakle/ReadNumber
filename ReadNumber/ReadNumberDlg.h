
// ReadNumberDlg.h: 헤더 파일
//

#pragma once
#include <utility>

// CReadNumberDlg 대화 상자
class CReadNumberDlg : public CDialogEx
{
// 생성입니다.
public:
	CReadNumberDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

	virtual BOOL PreTranslateMessage(MSG* message); //F5 인식용

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_READNUMBER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.

private: //속성이요
	CPoint old_pos;
	int stroke_count = 0; //그린 횟수. 2까지만 체크
	//bool crossed = false; //교차된 적이 있나?
	CPoint cross_pos; //교차된 위치
	std::pair<CPoint, CPoint> first_line; //처음 그린 선 위치정보
	std::pair<CPoint, CPoint> second_line; //두번째 그린 선 위치정보

// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	void DrawCrossLine();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedButtonRead();
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
};

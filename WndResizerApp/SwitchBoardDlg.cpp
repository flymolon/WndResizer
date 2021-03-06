// SwitchBoardDlg.cpp : implementation file
//

#include "stdafx.h"
#include "WndResizerApp.h"
#include "SwitchBoardDlg.h"
#include "TestDlg.h"
#include "Example01Dlg.h"
#include "Example02Dlg.h"
#include "Example03Dlg.h"
#include "Example04Dlg.h"
#include "Example05Dlg.h"
#include "Example06Dlg.h"
#include "Example07Dlg.h"
#include "Example08Dlg.h"
#include "Example09Dlg.h"
#include "Example10Dlg.h"

// CSwitchBoardDlg dialog

IMPLEMENT_DYNAMIC(CSwitchBoardDlg, CDialog)

CSwitchBoardDlg::CSwitchBoardDlg(CWnd* pParent /*=NULL*/)
  : CDialog(CSwitchBoardDlg::IDD, pParent)
{
  m_pModelessSheet = NULL;
  m_pPageA = NULL;
  m_pPageB = NULL;
}

CSwitchBoardDlg::~CSwitchBoardDlg()
{
}

void CSwitchBoardDlg::DoDataExchange(CDataExchange* pDX)
{
  CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CSwitchBoardDlg, CDialog)
  ON_BN_CLICKED(IDC_BUTTON_TEST, &CSwitchBoardDlg::OnBnClickedButtonTest)
  ON_BN_CLICKED(IDC_BUTTON_EX01, &CSwitchBoardDlg::OnBnClickedButtonEx1)
  ON_BN_CLICKED(IDC_BUTTON_EX02, &CSwitchBoardDlg::OnBnClickedButtonEx2)
  ON_BN_CLICKED(IDC_BUTTON_EX03, &CSwitchBoardDlg::OnBnClickedButtonEx3)
  ON_BN_CLICKED(IDC_BUTTON_EX04, &CSwitchBoardDlg::OnBnClickedButtonEx4)
  ON_BN_CLICKED(IDC_BUTTON_EX05, &CSwitchBoardDlg::OnBnClickedButtonEx5)
  ON_BN_CLICKED(IDC_BUTTON_EX06, &CSwitchBoardDlg::OnBnClickedButtonEx6)
  ON_BN_CLICKED(IDC_BUTTON_EX07, &CSwitchBoardDlg::OnBnClickedButtonEx7)
  ON_BN_CLICKED(IDC_BUTTON_EX8, &CSwitchBoardDlg::OnBnClickedButtonEx8)
  ON_BN_CLICKED(IDC_BUTTON_EX9, &CSwitchBoardDlg::OnBnClickedButtonEx9)
  ON_BN_CLICKED(IDC_BUTTON_EX10, &CSwitchBoardDlg::OnBnClickedButtonEx10)
  ON_BN_CLICKED(IDC_BUTTON_EX11, &CSwitchBoardDlg::OnBnClickedButtonEx11)
  ON_WM_DESTROY()
END_MESSAGE_MAP()

// CSwitchBoardDlg message handlers

void CSwitchBoardDlg::OnBnClickedButtonTest()
{
  CTestDlg dlg;
  dlg.DoModal();
}
void CSwitchBoardDlg::OnDestroy()
{
  CDialog::OnDestroy();

  DestroyPropertyModelessSheet();
}
void CSwitchBoardDlg::DestroyPropertyModelessSheet()
{
  if (m_pModelessSheet != NULL)
  {
    delete m_pModelessSheet;
    delete m_pPageA;
    delete m_pPageB;

    m_pModelessSheet = NULL;
    m_pPageA = NULL;
    m_pPageB = NULL;
  }
}
void CSwitchBoardDlg::OnBnClickedButtonEx1()
{
  CExample01Dlg dlg;
  dlg.DoModal();
}

void CSwitchBoardDlg::OnBnClickedButtonEx2()
{
  CExample02Dlg dlg;
  dlg.DoModal();
}

void CSwitchBoardDlg::OnBnClickedButtonEx3()
{
  CExample03Dlg dlg;
  dlg.DoModal();
}

void CSwitchBoardDlg::OnBnClickedButtonEx4()
{
  CExample04Dlg dlg;
  dlg.DoModal();
}

void CSwitchBoardDlg::OnBnClickedButtonEx5()
{
  CExample05Dlg dlg;
  dlg.DoModal();
}

void CSwitchBoardDlg::OnBnClickedButtonEx6()
{
  CExample06Dlg dlg;
  dlg.DoModal();
}

void CSwitchBoardDlg::OnBnClickedButtonEx7()
{
  CExample07Dlg dlg;
  dlg.DoModal();
}

void CSwitchBoardDlg::OnBnClickedButtonEx8()
{
  CExample08APpg pageA;
  CExample08BPpg pageB;
  CExample08Sheet sheet(_T("Example 8: CPropertySheet"), this);
  sheet.AddPage( &pageA );
  sheet.AddPage( &pageB );
  sheet.DoModal();
}
void CSwitchBoardDlg::OnBnClickedButtonEx9()
{
  CExample09Dlg dlg;
  dlg.DoModal();
}

void CSwitchBoardDlg::OnBnClickedButtonEx10()
{
  CExample10Dlg dlg;
  dlg.DoModal();
}

void CSwitchBoardDlg::OnBnClickedButtonEx11()
{
  if (m_pModelessSheet != NULL)  // if it was alread created, then destroy it
  {
    DestroyPropertyModelessSheet();
  }

  m_pModelessSheet = new CExample11Dlg(_T("Example 11: Modeless CPropertySheet"), this);
  m_pPageA = new CExample08APpg();
  m_pPageB = new CExample08BPpg();

  m_pModelessSheet->AddPage(m_pPageA);
  m_pModelessSheet->AddPage(m_pPageB);

  m_pModelessSheet->Create(NULL, DS_3DLOOK | DS_SETFONT| WS_THICKFRAME | WS_SYSMENU | WS_POPUP | WS_VISIBLE | WS_CAPTION);
}
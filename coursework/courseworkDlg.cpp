﻿
// courseworkDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "coursework.h"
#include "courseworkDlg.h"
#include "afxdialogex.h"

#include "MyTaskAboutDlg.h"
#include "Calculator.h"
#include "SomeDefinitions.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();
	BOOL OnInitDialog();
	// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX) {
}

BOOL CAboutDlg::OnInitDialog() {
	SetWindowText(_T("О программе. Номер версии: "__COURSE_LAST_COMMIT_INDEX));
	return 0;
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX) {
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Диалоговое окно CcourseworkDlg



CcourseworkDlg::CcourseworkDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_COURSEWORK_DIALOG, pParent)
	, theTask(_T("Для сигнала заданного вида вычислить дискретное преобразование Фурье(ДПФ), нарисовать график сигнальной функции и график модуля  ее ДПФ, предоставить возможность изменять масштаб графика по Х и по У, выбор линейного или логарифмического масштаба по У для графика ДПФ, интерактивный режим изменения параметров сигнала, запись в файл графиков сигнала и ДПФ в формате BMP.")) {
	m_hIcon = AfxGetApp()->LoadIcon(ID_LOGO_ICO);
}

void CcourseworkDlg::DoDataExchange(CDataExchange* pDX) {
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STATIC_TASK, theTask);
}

BEGIN_MESSAGE_MAP(CcourseworkDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CcourseworkDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CcourseworkDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_Task_About_Bn, &CcourseworkDlg::OnBnClickedTaskAboutBn)
	ON_BN_CLICKED(IDC_CALCULATE_BUTTON, &CcourseworkDlg::OnBnClickedCalculateButton)
END_MESSAGE_MAP()


// Обработчики сообщений CcourseworkDlg

BOOL CcourseworkDlg::OnInitDialog() {
	CDialogEx::OnInitDialog();
	SetWindowText(_T("Курсовая - Чаминов Д. А. гр. 1183 " __COURSE__VERSION));

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr) {
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty()) {
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CcourseworkDlg::OnSysCommand(UINT nID, LPARAM lParam) {
	if ((nID & 0xFFF0) == IDM_ABOUTBOX) {
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	} else {
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CcourseworkDlg::OnPaint() {
	if (IsIconic()) {
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	} else {
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CcourseworkDlg::OnQueryDragIcon() {
	return static_cast<HCURSOR>(m_hIcon);
}



void CcourseworkDlg::OnBnClickedOk() {
	// TODO: добавьте свой код обработчика уведомлений
	CDialogEx::OnOK();
}


void CcourseworkDlg::OnBnClickedCancel() {
	// TODO: добавьте свой код обработчика уведомлений
	CDialogEx::OnCancel();
}



void CcourseworkDlg::OnBnClickedTaskAboutBn() {
	MyTaskAboutDlg dlg(this);
	dlg.DoModal();
	// TODO: добавьте свой код обработчика уведомлений
}


void CcourseworkDlg::OnBnClickedCalculateButton() {
	Calculator dlg;
	dlg.DoModal();
}


// testgit4mfcView.cpp : Ctestgit4mfcView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "testgit4mfc.h"
#endif

#include "testgit4mfcDoc.h"
#include "testgit4mfcView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctestgit4mfcView

IMPLEMENT_DYNCREATE(Ctestgit4mfcView, CView)

BEGIN_MESSAGE_MAP(Ctestgit4mfcView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Ctestgit4mfcView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// Ctestgit4mfcView ����/����

Ctestgit4mfcView::Ctestgit4mfcView()
{
	// TODO: �ڴ˴���ӹ������

}

Ctestgit4mfcView::~Ctestgit4mfcView()
{
}

BOOL Ctestgit4mfcView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Ctestgit4mfcView ����

void Ctestgit4mfcView::OnDraw(CDC* /*pDC*/)
{
	Ctestgit4mfcDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Ctestgit4mfcView ��ӡ


void Ctestgit4mfcView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Ctestgit4mfcView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Ctestgit4mfcView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Ctestgit4mfcView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void Ctestgit4mfcView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Ctestgit4mfcView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Ctestgit4mfcView ���

#ifdef _DEBUG
void Ctestgit4mfcView::AssertValid() const
{
	CView::AssertValid();
}

void Ctestgit4mfcView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctestgit4mfcDoc* Ctestgit4mfcView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctestgit4mfcDoc)));
	return (Ctestgit4mfcDoc*)m_pDocument;
}
#endif //_DEBUG


// Ctestgit4mfcView ��Ϣ�������

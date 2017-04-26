
// testgit4mfcView.cpp : Ctestgit4mfcView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Ctestgit4mfcView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// Ctestgit4mfcView 构造/析构

Ctestgit4mfcView::Ctestgit4mfcView()
{
	// TODO: 在此处添加构造代码

}

Ctestgit4mfcView::~Ctestgit4mfcView()
{
}

BOOL Ctestgit4mfcView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Ctestgit4mfcView 绘制

void Ctestgit4mfcView::OnDraw(CDC* /*pDC*/)
{
	Ctestgit4mfcDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// Ctestgit4mfcView 打印


void Ctestgit4mfcView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Ctestgit4mfcView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Ctestgit4mfcView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Ctestgit4mfcView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
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


// Ctestgit4mfcView 诊断

#ifdef _DEBUG
void Ctestgit4mfcView::AssertValid() const
{
	CView::AssertValid();
}

void Ctestgit4mfcView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctestgit4mfcDoc* Ctestgit4mfcView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctestgit4mfcDoc)));
	return (Ctestgit4mfcDoc*)m_pDocument;
}
#endif //_DEBUG


// Ctestgit4mfcView 消息处理程序

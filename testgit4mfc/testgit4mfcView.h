
// testgit4mfcView.h : Ctestgit4mfcView ��Ľӿ�
//

#pragma once


class Ctestgit4mfcView : public CView
{
protected: // �������л�����
	Ctestgit4mfcView();
	DECLARE_DYNCREATE(Ctestgit4mfcView)

// ����
public:
	Ctestgit4mfcDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~Ctestgit4mfcView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // testgit4mfcView.cpp �еĵ��԰汾
inline Ctestgit4mfcDoc* Ctestgit4mfcView::GetDocument() const
   { return reinterpret_cast<Ctestgit4mfcDoc*>(m_pDocument); }
#endif


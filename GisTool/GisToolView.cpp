
// GisToolView.cpp : implementation of the CGisToolView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "GisTool.h"
#endif

#include "GisToolDoc.h"
#include "GisToolView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGisToolView

IMPLEMENT_DYNCREATE(CGisToolView, CView)

BEGIN_MESSAGE_MAP(CGisToolView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CGisToolView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CGisToolView construction/destruction

CGisToolView::CGisToolView() noexcept
{
	// TODO: add construction code here

}

CGisToolView::~CGisToolView()
{
}

BOOL CGisToolView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CGisToolView drawing

void CGisToolView::OnDraw(CDC* /*pDC*/)
{
	CGisToolDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CGisToolView printing


void CGisToolView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CGisToolView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CGisToolView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CGisToolView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CGisToolView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CGisToolView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CGisToolView diagnostics

#ifdef _DEBUG
void CGisToolView::AssertValid() const
{
	CView::AssertValid();
}

void CGisToolView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGisToolDoc* CGisToolView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGisToolDoc)));
	return (CGisToolDoc*)m_pDocument;
}
#endif //_DEBUG


// CGisToolView message handlers

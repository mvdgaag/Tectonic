#include "D3DRenderWidget.h"
#include "Gaag.h"
#include "qevent.h"


D3DRenderWidget::D3DRenderWidget(QWidget* parent) : QWidget(parent) 
{
	setAttribute(Qt::WA_PaintOnScreen, true);
	setAttribute(Qt::WA_NativeWindow, true);
	setFocusPolicy(Qt::FocusPolicy::StrongFocus);
	Gaag.Init(HWND(winId()), width(), height());
}


D3DRenderWidget::~D3DRenderWidget()
{
	Gaag.CleanUp();
}


void D3DRenderWidget::paintEvent(QPaintEvent* evt)
{
	Gaag.Render();
	update(); // calls the next paint event
}


void D3DRenderWidget::resizeEvent(QResizeEvent* evt) 
{
	Gaag.Resize(width(), height());
}


void D3DRenderWidget::mousePressEvent(QMouseEvent* evt)
{
	theInput.OnMouseDown((int)evt->button() - 1);
}


void D3DRenderWidget::mouseReleaseEvent(QMouseEvent* evt)
{
	theInput.OnMouseUp((int)evt->button() - 1);
}


void D3DRenderWidget::mouseDoubleClickEvent(QMouseEvent* evt)
{
}


void D3DRenderWidget::mouseMoveEvent(QMouseEvent* evt)
{
	theInput.OnMouseMove(float2(evt->localPos().x(), evt->localPos().y()));
}


void D3DRenderWidget::keyPressEvent(QKeyEvent* evt)
{
	//HKL key_layout = GetKeyboardLayout(GetCurrentThreadId());
	//int unicode = MapVirtualKeyExW(evt->key(), MAPVK_VK_TO_VSC_EX, key_layout);
	theInput.OnKeyDown(evt->nativeVirtualKey());
}


void D3DRenderWidget::keyReleaseEvent(QKeyEvent *evt)
{
	//HKL key_layout = GetKeyboardLayout(GetCurrentThreadId());
	//int unicode = MapVirtualKeyExW(evt->key(), MAPVK_VK_TO_VSC_EX, key_layout);
	theInput.OnKeyUp(evt->nativeVirtualKey());
}

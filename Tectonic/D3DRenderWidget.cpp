#include "D3DRenderWidget.h"
#include "Gaag.h"


D3DRenderWidget::D3DRenderWidget(QWidget* parent) : QWidget(parent) 
{
	setAttribute(Qt::WA_PaintOnScreen, true);
	setAttribute(Qt::WA_NativeWindow, true);

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
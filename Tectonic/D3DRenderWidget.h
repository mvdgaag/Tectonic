#pragma once

#include <QWidget>


class D3DRenderWidget : public QWidget
{
	Q_OBJECT
	Q_DISABLE_COPY(D3DRenderWidget)
public:
	D3DRenderWidget(QWidget* parent = NULL);
	virtual ~D3DRenderWidget();
	virtual QPaintEngine* paintEngine() const { return NULL; }
protected:
	virtual void resizeEvent(QResizeEvent* evt) override;
	virtual void paintEvent(QPaintEvent* evt) override;
	virtual void mousePressEvent(QMouseEvent* evt) override;
	virtual void mouseReleaseEvent(QMouseEvent* evt) override;
	virtual void mouseDoubleClickEvent(QMouseEvent* evt) override;
	virtual void mouseMoveEvent(QMouseEvent* evt) override;
	virtual void keyPressEvent(QKeyEvent* evt) override;
	virtual void keyReleaseEvent(QKeyEvent *evt) override;
};

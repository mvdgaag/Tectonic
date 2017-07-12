#include "Tectonic.h"
#include <QtWidgets>
#include "D3DRenderWidget.h"


int main(int argc, char *argv[])
{
    QApplication application(argc, argv);
    Tectonic window;

	D3DRenderWidget* render_widget = new D3DRenderWidget();
	QPushButton* button = new QPushButton("Bla");
	QVBoxLayout* layout = new QVBoxLayout();
	layout->addWidget(render_widget);
	layout->addWidget(button);
	
	window.centralWidget()->setLayout(layout);
	window.show();
	return application.exec();
}

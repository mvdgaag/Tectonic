#include "Tectonic.h"
#include <QtWidgets>
#include "D3DRenderWidget.h"
#include "Gaag.h"


pMesh				mMesh;
pMaterial			mMaterial;
pMeshObject			mMeshObject;
pCamera				mCamera;
pDirectionalLight	mLight;


void FrameFunc()
{
	double dt = Gaag.GetFrameDeltaTime();
	mLight->SetDirection(float3(sin(dt), cos(dt), 1.0));
}


void InitModels()
{
	mMesh = theResourceFactory.MakeMesh();
	mMesh->InitCube();

	mMaterial = theResourceFactory.GetDefaultMaterial();

	mMeshObject = new MeshObject();
	mMeshObject->Init(mMesh, mMaterial);

	mLight = theResourceFactory.MakeDirectionalLight(float3(1, 1, 1), float4(1, 1, 1, 1), 0);

	mCamera = Gaag.GetCamera();

	Gaag.RegisterObject(mMeshObject);
	Gaag.RegisterLight(mLight);
}


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

	InitModels();
	Gaag.SetFrameCallback(&FrameFunc);

	window.show();
	return application.exec();
}

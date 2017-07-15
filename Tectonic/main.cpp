#include "Tectonic.h"
#include <QtWidgets>
#include "D3DRenderWidget.h"
#include "Gaag.h"
#include "Terrain.h"
#include "SimpleHeightFlow.h"
#include "PaintTool.h"
#include "BrushLibrary.h"
#include "Brush.h"
#include "CameraController.h"


pDirectionalLight	gLight;

pMaterial			gTerrainMaterial;
pPixelShader		gTerrainPixelShader;
pVertexShader		gTerrainVertexShader;

pMaterial			gTerrainShadowMaterial;
pPixelShader		gTerrainShadowPixelShader;
pVertexShader		gTerrainShadowVertexShader;

pTerrain			gTerrain;
pSimpleHeightFlow	gFlow;
pPaintTool			gPaintTool;
pBrushLibrary		gBrushLibrary;
pCameraController	gCameraController;


static void FrameFunc()
{
	double dt = Gaag.GetFrameDeltaTime();
	gFlow->Update(dt);
	gTerrain->ProcessDirtyLayers();
}


void InitContent()
{
	gLight = theResourceFactory.MakeDirectionalLight(float3(1, 1, -1), float4(10, 10, 10, 1), 2048);
	Gaag.RegisterLight(gLight);

	gTerrainPixelShader = theResourceFactory.LoadPixelShader("Resources/Shaders/TerrainFragmentShader.hlsl");
	gTerrainVertexShader = theResourceFactory.LoadVertexShader("Resources/Shaders/TerrainVertexShader.hlsl");

	gTerrainMaterial = theResourceFactory.MakeMaterial();
	gTerrainMaterial->SetDiffuseValue(float4(0.6f, 0.6f, 0.6f, 0.0f));
	gTerrainMaterial->SetReflectivityValue(0.05f);
	gTerrainMaterial->SetRoughnessValue(0.8f);
	gTerrainMaterial->SetMetalicityValue(0.0f);
	gTerrainMaterial->SetEmissivenessValue(0.0f);
	gTerrainMaterial->SetPixelShader(gTerrainPixelShader);
	gTerrainMaterial->SetVertexShader(gTerrainVertexShader);

	gTerrainShadowMaterial = theResourceFactory.MakeMaterial();
	gTerrainShadowVertexShader = theResourceFactory.LoadVertexShader("Resources/Shaders/TerrainShadowVertexShader.hlsl");
	gTerrainShadowPixelShader = theResourceFactory.LoadPixelShader("Resources/Shaders/TerrainShadowFragmentShader.hlsl");
	gTerrainShadowMaterial->SetVertexShader(gTerrainShadowVertexShader);
	gTerrainShadowMaterial->SetPixelShader(gTerrainShadowPixelShader);
	
	gTerrain = MAKE_NEW(Terrain);
	gTerrain->Init(int2(3), int2(64), float3(50, 50, 5), gTerrainMaterial, gTerrainShadowMaterial);

	gFlow = MAKE_NEW(SimpleHeightFlow);
	gFlow->Init(gTerrain);

	gBrushLibrary = MAKE_NEW(BrushLibrary);
	gBrushLibrary->Init();

	gPaintTool = MAKE_NEW(PaintTool);
	gPaintTool->Init(gBrushLibrary);

	gPaintTool->SetTargetTerrain(gTerrain);
	gPaintTool->SetTargetLayer(gTerrain->GetHeightLayerIndex());

	if (gFlow != nullptr)
	{
		gPaintTool->SetTargetLayer(gFlow->GetLayerIndex());
		gTerrain->SetHeightLayerIndex(gFlow->GetLayerIndex());
	}

	pCamera cam = Gaag.GetCamera();
	cam->SetPosition(float3(100.0f, 100.0f, 100.0f));
	cam->SetTarget(float3(0.0f, 0.0f, 0.0f));
	cam->SetWorldUp(float3(0.0f, 0.0f, 1.0f));

	gCameraController = MAKE_NEW(CameraController);
	gCameraController->SetTargetCamera(cam);
}


void CleanUpContent()
{
	theResourceFactory.DestroyItem(gLight);

	theResourceFactory.DestroyItem(gTerrainMaterial);
	theResourceFactory.DestroyItem(gTerrainPixelShader);
	theResourceFactory.DestroyItem(gTerrainVertexShader);

	theResourceFactory.DestroyItem(gTerrainShadowMaterial);
	theResourceFactory.DestroyItem(gTerrainShadowPixelShader);
	theResourceFactory.DestroyItem(gTerrainShadowVertexShader);

	if (gTerrain)
	{
		delete gTerrain;
		gTerrain = nullptr;
	}
	if (gFlow)
	{
		delete gFlow;
		gFlow = nullptr;
	}
	if (gPaintTool) 
	{
		delete gPaintTool;
		gPaintTool = nullptr;
	}
	if (gBrushLibrary)
	{
		delete gBrushLibrary;
		gBrushLibrary = nullptr;
	}
	if (gCameraController)
	{
		delete gCameraController;
		gCameraController = nullptr;
	}
}


int main(int argc, char *argv[])
{
    QApplication application(argc, argv);
    Tectonic window;

	D3DRenderWidget* render_widget = new D3DRenderWidget();
	QVBoxLayout* layout = new QVBoxLayout();
	layout->addWidget(render_widget);
	
	QFrame* render_frame_widget = window.findChild<QFrame*>(QString("renderframe"), Qt::FindChildrenRecursively);
	assert(render_frame_widget);
	render_frame_widget->setLayout(layout);

	QSplitter* splitter = window.findChild<QSplitter*>(QString("splitter"), Qt::FindChildrenRecursively);
	assert(splitter);
	splitter->setStretchFactor(0, 100);
	splitter->setStretchFactor(1, 1);

	InitContent();
	Gaag.SetFrameCallback(&FrameFunc);

	window.show();
	render_widget->show();

	
	//CleanUpContent();

	return application.exec();
}

#include "PaintTool.h"
#include "BrushLibrary.h"


void PaintTool::Init(pBrushLibrary inBrushLibrary)
{
	mBrushLibrary = inBrushLibrary;
}


void PaintTool::CleanUp()
{
	mBrushLibrary = nullptr;
}


void PaintTool::OnKeyDown(unsigned int inKey)
{
	switch (inKey)
	{
	case (0x42) : // b
		mCurrentBrush = mBrushLibrary->GetBrush("Basic");
		break;
	case (0x4E) : // n
		mCurrentBrush = mBrushLibrary->GetBrush("Noise");
		break;
	case (0x53) : // s
		mCurrentBrush = mBrushLibrary->GetBrush("Smooth");
		break;
	default:
		break;
	}
}


void PaintTool::OnMouseDown(int inButton) 
{ 
	if (inButton == 0) 
		BeginPaint(Gaag.ScreenToWorldPos(theInput.GetMouseCoord())); 
}


void PaintTool::OnMouseUp(int inButton) 
{ 
	if (inButton == 0) 
		EndPaint(Gaag.ScreenToWorldPos(theInput.GetMouseCoord()));
}


void PaintTool::OnMouseMove(float2 inCurrentCoord, float2 inPrevCoord)
{ 
	if (mPainting) 
		ContinuePaint(Gaag.ScreenToWorldPos(theInput.GetMouseCoord()));
}


void PaintTool::BeginPaint(float3 inWorldPos)
{
	mPainting = true;
	ApplyPaint(float2(inWorldPos.x, inWorldPos.y));
}


void PaintTool::EndPaint(float3 inWorldPos)
{
	ApplyPaint(float2(inWorldPos.x, inWorldPos.y));
	mPainting = false;
}


void PaintTool::ContinuePaint(float3 inWorldPos)
{
	ApplyPaint(float2(inWorldPos.x, inWorldPos.y));
}


void PaintTool::ApplyPaint(float2 inWorldCoord)
{
	assert(mTargetTerrain != nullptr);

	if (mCurrentBrush == nullptr)
		return;

	float2 tile_coord = mTargetTerrain->WorldToTileSpace(inWorldCoord);

	std::vector<int2> tile_indices = mTargetTerrain->GetTiles(rect(inWorldCoord - mCurrentBrush->GetRadius(), inWorldCoord + mCurrentBrush->GetRadius()));

	for each (int2 index in tile_indices)
	{
		pRenderTarget target = mTargetTerrain->GetLayerRenderTarget(index, mTargetLayer);
		mTargetTerrain->SetDirty(index, mTargetLayer);
			
		// set neighbords array if needed
		apTexture neighborhood;
		neighborhood.push_back(mTargetTerrain->GetLayerTexture(index, mTargetLayer));
		if (mCurrentBrush->SamplesNeighbors())
		{
			neighborhood.resize(4);
			assert(tile_indices.size() <= 4);
			for each (int2 neighbor_index in tile_indices)
			{
				if (neighbor_index == index)
					continue;

				// horizontal neighbor
				if (neighbor_index.y == index.y)
					neighborhood[1] = mTargetTerrain->GetLayerTexture(neighbor_index, mTargetLayer);
				// vertical neighbor
				else if (neighbor_index.x == index.x)
					neighborhood[2] = mTargetTerrain->GetLayerTexture(neighbor_index, mTargetLayer);
				// diagonal neighbor
				else
					neighborhood[3] = mTargetTerrain->GetLayerTexture(neighbor_index, mTargetLayer);
			}
		}

		float2 world_tile_scale =	float2(mTargetTerrain->GetTileScale().x, mTargetTerrain->GetTileScale().y);
		int2 pixel =				(tile_coord - float2(index)) * float2(target->GetDimensions() - int2(1,1));
		float2 pixels_per_meter =	float2(target->GetDimensions().x, target->GetDimensions().y) / float2(world_tile_scale.x, world_tile_scale.y);
		int2 pixel_radius =			int2(pixels_per_meter * mCurrentBrush->GetRadius() + float2(1.0, 1.0));
		rect paint_rect =			rect(pixel - pixel_radius, pixel + pixel_radius);
		rect world_tile_rect =		rect(mTargetTerrain->TileToWorldSpace(float2(index)), mTargetTerrain->TileToWorldSpace(float2(index + 1)));

		if (target != nullptr)
		{
			mCurrentBrush->Apply(target, paint_rect, world_tile_rect, inWorldCoord, neighborhood);
		}
	}

	/* TODO: required? should be identical, but data is duplicated and hopefully treated exactly the same
	cannot hurt to ensure with a copy

	for each (int2 index in tile_indices)
	{
		pTerrainTile tile = mTargetTerrain->GetTile(index);
		pTerrainTile east = mTargetTerrain->GetTile(index + int2(1, 0));
		pTerrainTile north = mTargetTerrain->GetTile(index + int2(0, 1));
		if (east) 
			TextureUtil::TextureStitchEast(tile->GetHeightTexture(), east->GetHeightTexture());
		if (north) 
			TextureUtil::TextureStitchNorth(tile->GetHeightTexture(), north->GetHeightTexture());
	}*/
}

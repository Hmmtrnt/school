﻿//-----------------------------------------------------------------------------
// @brief  障害物マネージャー.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#include "ObstructManager.h"
#include "ObstructBase.h"
#include "ObstructStatic.h"
#include "ObstructFloat.h"

//-----------------------------------------------------------------------------
// @brief  コンストラクタ.
//-----------------------------------------------------------------------------
ObstructManager::ObstructManager()
	: floatModelSourceHandle(-1)
	, staticModelSourceHandle(-1)
{
	for (int i = 0; i < OBSTRUCT_NUM; ++i)
	{
		obstructs[i] = NULL;
	}
}

//-----------------------------------------------------------------------------
// @brief  デストラクタ.
//-----------------------------------------------------------------------------
ObstructManager::~ObstructManager()
{
	// 処理なし.
}

//-----------------------------------------------------------------------------
// @brief  障害物生成.
//-----------------------------------------------------------------------------
void ObstructManager::CreateObstructs()
{
	floatModelSourceHandle = MV1LoadModel("data/model/obstructFloat/obstructFloat.pmx");
	staticModelSourceHandle = MV1LoadModel("data/model/obstructStatic/obstructStatic.pmd");
	obstructs[0] = new ObstructStatic(staticModelSourceHandle);
	obstructs[1] = new ObstructFloat(floatModelSourceHandle);
	obstructs[2] = new ObstructStatic(staticModelSourceHandle);
	for (int i = 3; i < OBSTRUCT_NUM; ++i)
	{
		obstructs[i] = new ObstructStatic(staticModelSourceHandle);
	}

	// 障害物の位置を初期化.
	float band = 10.0f;
	for (int i = 0; i < OBSTRUCT_NUM; ++i)
	{
		obstructs[i]->SetPos(VGet(band * (i - OBSTRUCT_NUM * 0.5f), 0, -1.0f));
	}
}

//-----------------------------------------------------------------------------
// @brief  障害物削除.
//-----------------------------------------------------------------------------
void ObstructManager::DestroyObstructs()
{
	for (int i = 0; i < OBSTRUCT_NUM; ++i)
	{
		delete(obstructs[i]);
		obstructs[i] = NULL;
	}
	MV1DeleteModel(staticModelSourceHandle);
	MV1DeleteModel(floatModelSourceHandle);
}

//-----------------------------------------------------------------------------
// @brief  更新.
//-----------------------------------------------------------------------------
void ObstructManager::Update()
{
	for (int i = 0; i < OBSTRUCT_NUM; ++i)
	{
		if (obstructs[i] != NULL)
		{
			obstructs[i]->Update();
		}
	}
}

//-----------------------------------------------------------------------------
// @brief  描画.
//-----------------------------------------------------------------------------
void ObstructManager::Draw()
{
	for (int i = 0; i < OBSTRUCT_NUM; ++i)
	{
		if (obstructs[i] != NULL)
		{
			obstructs[i]->Draw();
		}
	}
}
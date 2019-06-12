﻿//-----------------------------------------------------------------------------
// @brief  ゲームのメインクラス.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#include "Game.h"
#include "Camera.h"
#include "Sprite.h"

//-----------------------------------------------------------------------------
// @brief  コンストラクタ.
//-----------------------------------------------------------------------------
Game::Game()
	:  sprite(NULL)
	, camera(NULL)
{
	// 処理なし.
}

//-----------------------------------------------------------------------------
// @brief  デストラクタ.
//-----------------------------------------------------------------------------
Game::~Game()
{
	Finalize();
}

//-----------------------------------------------------------------------------
// @brief  初期化.
//-----------------------------------------------------------------------------
void Game::Initialize(const Device& device)
{
	sprite = new Sprite();
	sprite->Initialize(device, "data/texture/img.png");

	camera = new Camera();
	camera->Initialize();

}

//-----------------------------------------------------------------------------
// @brief  終了処理.
//-----------------------------------------------------------------------------
void Game::Finalize()
{
	if (camera != NULL)
	{
		camera->Finalize();
		delete camera;
		camera = NULL;
	}
	if (sprite != NULL)
	{
		sprite->Finalize();
		delete sprite;
		sprite = NULL;
	}
}

//-----------------------------------------------------------------------------
// @brief  アップデート.
//-----------------------------------------------------------------------------
void Game::Update()
{
}

//-----------------------------------------------------------------------------
// @brief  描画.
//-----------------------------------------------------------------------------
void Game::Render(const Device& device)
{
	// バックバッファを青色でクリアする.
	device.GetDevice()->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);

	// シーン描画を開始する.
	if (SUCCEEDED(device.GetDevice()->BeginScene()))
	{
		// カメラ設定.
		camera->SetCameraMatrices(device);

		// マトリクス設定.
		sprite->SetWorldMatrices(device);

		// レンダリング.
		sprite->Render(device);

		// シーン描画を終了する.
		device.GetDevice()->EndScene();
	}

	// 実際の描画を確定する.
	device.GetDevice()->Present(NULL, NULL, NULL, NULL);
}

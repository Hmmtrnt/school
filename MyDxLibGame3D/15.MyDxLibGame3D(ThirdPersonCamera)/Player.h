﻿//-----------------------------------------------------------------------------
// @brief  プレイヤークラス.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "DxLib.h"

class Player final
{
public:
	Player();				// コンストラクタ.
	~Player();				// デストラクタ.

	void Update();			// 更新.
	void Draw();			// 描画.

	// モデルハンドルの取得.
	int GetModelHandle(){ return modelHandle; }

	// ポジションのgetter/setter.
	const VECTOR& GetPos() const { return pos; }
	void SetPos(const VECTOR set) { pos = set; }

	const VECTOR& GetDir() const { return dir; }

private:
	int		modelHandle;	// モデルハンドル.
	VECTOR	pos;			// ポジション.

	float	accel;			// 加速度.
	VECTOR	velocity;		// 移動力.

	VECTOR	dir;			// 回転方向.
	float	speed;			// 移動速度.
	bool	prebPressFlag;	// 前フレームに押されたかどうか.

	// 静的定数.
	static const float ACCEL;
	static const float DEFAULT_DECEL;
	static const float BREAK_DECEL;
};

#endif // _PLAYER_H_
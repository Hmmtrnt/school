﻿// 2023 Takeru Yui All Rights Reserved.
#include "DxLib.h"
#include "Enemy3.h"

/// <summary>
/// 初期用パラメータの設定
/// </summary>
void Enemy3::SetInitializeData()
{
	// エネミーのグラフィックをメモリにロード＆表示座標を初期化
	enemyGlaphStr = "data/texture/EpicEnemy3.png";
	x = 0;
	y = 150;
	life = ENEMY_LIFE3;

	// エネミーが顔を歪めているかどうかの変数に『歪めていない』を表すFALSEを代入
	damageFlag = false;

	rightMove = true;
	speed = 4;
	speedUpLifeLimit = 10;
}
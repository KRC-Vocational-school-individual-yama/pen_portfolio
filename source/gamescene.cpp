#include "gamescene.h"

#include"libs/scenemanager.h"
#include<DxLib.h>
#include"temp.h"
#include"gameobj.h"
#include"pen.h"

GameScene::GameScene(){
	Create<TmepObject>();
	Create<GameObj>();
	Create<Pen>();
}
GameScene::~GameScene(){

}

void GameScene::Update(){
	Scene::Update();
	if (CheckHitKey(KEY_INPUT_RETURN)) {
		SceneManager::ChangeScene("Title");
	}
}

void GameScene::Draw(){
	Scene::Draw();
	printfDx("何もないので\nエンターキーで\n戻ってもろて");
}


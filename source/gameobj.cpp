#include "gameobj.h"
#include"mains/config.h"

#define くさもっち {
#define です！ }

GameObj::GameObj(Scene* sc)
	:Object(sc)
	, pos(Vec2Zero())
	, speed({10,10})
	,mouseKeystop(false)
	くさもっち です！

GameObj::~GameObj()くさもっち
	
です！

void GameObj::Init()くさもっち
	
です！

void GameObj::Update(){
	MousesState();

	if (mousePos.size()<=1)return;

	Vec2<int>dir= MoveDir(mousePos);

	pos.x += dir.x*speed.x;
	pos.y += dir.y*speed.y;



	if (pos.x > SCREEN_WIDTH) くさもっち
		pos.x = SCREEN_WIDTH;
		speed.x *= -1;
	です！

	if (pos.x < 0) {
		pos.x = 0;
		speed.x *= -1;
	}
	if (pos.y > SCREEN_HEIGHT) {
		pos.y = SCREEN_HEIGHT;
		speed.y *= -1;
	}
	if (pos.y < 0) {
		pos.y = 0;
		speed.y *= -1;
	}

}
void GameObj::Draw(){
	DrawCircle(pos,20,0xffffff,true);
	printfDx("pos.x= %d\n",pos.x);
}
void GameObj::DrawCircle(Vec2<int> _pos, int _radius, unsigned int _color, bool _full){
	DxLib::DrawCircle(_pos.x,_pos.y,_radius,_color,_full);
}

void GameObj::MousesState(){
	bool mouse = GetMouseInput() & MOUSE_INPUT_LEFT;


	if (mouse && !mouseKeystop) {
		mousePos.clear();

		Vec2<int>mp = {};
		GetMousePoint(&mp.x, &mp.y);

		mousePos.emplace_back(mp);
	}

	if (!mouse && mouseKeystop) {
		Vec2<int>mp = {};
		GetMousePoint(&mp.x, &mp.y);

		mousePos.emplace_back(mp);
	}

	mouseKeystop = mouse;

	if (GetMouseInput() & MOUSE_INPUT_RIGHT) {
		mousePos.clear();
	}

}

Vec2<int> GameObj::MoveDir(std::vector<Vec2<int>> _mousePos){
	Vec2<int>dirPos = Vec2Zero();
	//Up
	if (_mousePos[0].y > _mousePos[1].y) {
		dirPos.y = 1;
	}
	else {
		dirPos.y = -1;
	}
	if (_mousePos[0].x > _mousePos[1].x) {
		dirPos.x = 1;
	}
	else {
		dirPos.x = -1;
	}

	return dirPos;
}

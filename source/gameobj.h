#pragma once


#include"libs/object.h"
#include<vector>

class GameObj :public Object {
public:
	GameObj(Scene* sc);
	~GameObj();
	void Init();
	void Update();
	void Draw();

private:
	void DrawCircle(Vec2<int>_pos,int _radius,unsigned int _color,bool _full);
	void MousesState();
	Vec2<int> MoveDir(std::vector<Vec2<int>>_mousePos);
	

	Vec2<int>pos;
	Vec2<int>speed;
	std::vector<Vec2<int>>mousePos;
	bool mouseKeystop;
};
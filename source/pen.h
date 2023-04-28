#pragma once
#include"libs/object.h"
#include<list>


class Pen : public Object {
public:
	Pen(Scene* sc);
	~Pen()			override;
	void Init()		override;
	void Update()	override;
	void Draw()		override;

private:
	void LineS();

	std::list<Vec2<int>>hitohude;
	std::list<std::list<Vec2<int>>>hist;
	std::list<int>tick;

	Vec2<int>mouse;

	int nowTick;
	int count;
	bool keystop;
};
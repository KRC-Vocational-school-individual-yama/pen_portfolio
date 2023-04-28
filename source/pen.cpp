#include "pen.h"

Pen::Pen(Scene* sc)
	:Object(sc)
	,keystop(false)
	,nowTick(1)
	,count(0)
{}
Pen::~Pen(){

}
void Pen::Init(){

}
void Pen::Update(){
	GetMousePoint(&mouse.x,&mouse.y);


	//ëæÇ≥ïœçX
	nowTick += GetMouseWheelRotVol();
	if (nowTick < 1)nowTick = 1;


	//ê¸Çà¯Ç≠
	bool mLeft = GetMouseInput() & MOUSE_INPUT_LEFT;
	if (mLeft) {
		if (!hitohude.empty()) {

		Vec2<int>oldPos = hitohude.back();
		if(mouse.x!=oldPos.x&&mouse.y!=oldPos.y)
			hitohude.emplace_back(mouse),count++;

		}
		else
			hitohude.emplace_back(mouse), count++;

	}

	bool mRight = GetMouseInput() & MOUSE_INPUT_RIGHT;
	if (mRight) {
		hitohude.clear();
		hist.clear();
		tick.clear();
		nowTick = 1;
		count = 0;
	}


	if (!mLeft && keystop) {
		tick.emplace_back(nowTick);
		hist.emplace_back(hitohude);
		hitohude.clear();
	}

	keystop = mRight || mLeft;

}
void Pen::Draw() {
	printfDx("count= %d",count);
	DrawCircle(mouse.x,mouse.y,nowTick/2,0xffffff);


	for (auto& dotto : hitohude) {
		DrawCircleAA(dotto.x, dotto.y, 1, 60, 0xffffff);
	}

	if (GetMouseInput() & MOUSE_INPUT_LEFT) {

		for (auto it = hitohude.begin(); it != hitohude.end(); it++) {
			Vec2<int>& pos = (*it);
			it++;


			DrawCircleAA(pos.x, pos.y, nowTick / 2, 60, 0xffffff);

			if (it == hitohude.end())
				break;

			Vec2<int>& p = (*it);
			it--;




			DrawLine(pos.x, pos.y, p.x, p.y, 0xffffff, nowTick);
		}
		LineS();
	}
	else
		LineS();
}

void Pen::LineS(){
	auto tickIt = tick.begin();

	for (auto& obj : hist) {
			int thisTick = 1;
			if (!tick.empty())
				thisTick = (*tickIt);

		for (auto it = obj.begin(); it != obj.end(); it++) {
			Vec2<int>& pos = (*it);
			it++;


			DrawCircleAA(pos.x,pos.y,thisTick/2,60,0xffffff);

			if (it == obj.end())
				break;

			Vec2<int>& p = (*it);
			it--;



			DrawLineAA(pos.x, pos.y, p.x, p.y, 0xffffff, thisTick);
		}
		
		tickIt++;
	}
}

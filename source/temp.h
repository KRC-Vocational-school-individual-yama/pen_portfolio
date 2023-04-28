#pragma once

#include"libs/object.h"
class TmepObject :public Object {
public:
	TmepObject(Scene* sc);
	~TmepObject()	override;
	void Init()		override;
	void Update()	override;
	void Draw()		override;
private:

};
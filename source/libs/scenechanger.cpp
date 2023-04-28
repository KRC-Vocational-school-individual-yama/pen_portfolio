#include "scenechanger.h"
#include"scene.h"
#include"farstonescene.h"

#include"../title.h"
#include"../gamescene.h"

Scene* SceneChanger::StartScene(){
	return new FarstOneScene();
}

Scene* SceneChanger::Changer(std::string name){
	if (name == "Title") {
		return new Title();
	}
	else if (name=="Game") {
		return new GameScene();
	}
	MessageBox(NULL, ("����ĂȂ��V�[�������w�����I\n�V�[�����F" + name).c_str(), "�̍��l���w���������V�[�������߂�ҁx", MB_ICONERROR | MB_OK);
	assert(false);
	return nullptr;
}

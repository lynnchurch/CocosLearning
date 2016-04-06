#include "GameScene.h"
#include "LogoNode.h"

GameScene::GameScene()
{
}


GameScene::~GameScene()
{
}

bool GameScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto logo = LogoNode::create();
	logo->setPosition(Director::getInstance()->getVisibleSize() / 2);
	addChild(logo);
	return true;
}

Scene* GameScene::createScene()
{
	auto scene = Scene::create();
	auto layer = GameScene::create();
	scene->addChild(layer);
	return scene;
}
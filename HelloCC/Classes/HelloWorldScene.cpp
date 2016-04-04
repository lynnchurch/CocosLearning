#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = HelloWorld::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//auto logo = Sprite::create("logo.png");
	auto img = Director::getInstance()->getTextureCache()->addImage("logo.png");
	auto logoSize = img->getContentSize();
	CCLOG("logo size:%f %f", logoSize.width, logoSize.height);
	auto logo = Sprite::createWithTexture(img);
	logo->setPosition(visibleSize * 4 / 5);

	// 创建图层
	auto layer1 = Layer::create();
	auto layer2 = Layer::create();
	auto layer3 = Layer::create();

	// 创建精灵
	auto sprite1 = Sprite::create("red.png");
	auto sprite2 = Sprite::create("green.png");
	auto sprite3 = Sprite::create("blue.png");
	sprite1->setAnchorPoint(Vec2(0, 0));
	sprite2->setAnchorPoint(Vec2(0, 0));
	sprite3->setAnchorPoint(Vec2(0, 0));

	// 添加精灵到图层
	layer1->addChild(sprite1);
	layer2->addChild(sprite2);
	layer3->addChild(sprite3);

	// 设置图层的位置
	layer1->setPosition(Vec2(10, 10));
	layer2->setPosition(Vec2(30, 30));
	layer3->setPosition(Vec2(50, 50));

	// 添加图层到当前图层
	addChild(layer1);
	addChild(layer2);
	addChild(layer3);
	addChild(logo);

	// 切换场景
	scheduleOnce([visibleSize](float f){
		auto scene2 = Scene::create();
		auto scene2Layer = Layer::create();
		scene2->addChild(scene2Layer);
		auto scene2Sprite1 = Sprite::create("jiangshi.png");
		scene2Sprite1->setPosition(Vec2(visibleSize.width / 4, visibleSize.height / 2));
		scene2Layer->addChild(scene2Sprite1);
		auto scene2Sprite2 = Sprite::create("plant.png");
		scene2Sprite2->setPosition(Vec2(visibleSize.width * 3 / 4, visibleSize.height / 2));
		scene2Layer->addChild(scene2Sprite2);
		Director::getInstance()->replaceScene(scene2);
	}, 3, "Test");

	return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

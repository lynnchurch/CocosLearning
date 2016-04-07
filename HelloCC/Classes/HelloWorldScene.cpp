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

	auto bg1 = Sprite::create("bg1.jpg");
	bg1->setPosition(visibleSize / 2);
	addChild(bg1);

	scheduleOnce([visibleSize](float f){
		auto newScene = Scene::create();
		auto bg2 = Sprite::create("bg2.jpg");
		bg2->setPosition(visibleSize / 2);
		newScene->addChild(bg2);
		//auto tran = TransitionCrossFade::create(1, newScene); // 淡入淡出
		//auto tran = TransitionZoomFlipAngular::create(1, newScene); // 翻转
		//auto tran = TransitionPageTurn::create(1, newScene, false); // 翻页
		//auto tran = TransitionProgressRadialCCW::create(1, newScene); // 顺时针
		//auto tran = TransitionSplitRows::create(1, newScene); // 分行
		//auto tran = TransitionFadeDown::create(1,newScene); // 百叶窗
		//auto tran = TransitionShrinkGrow::create(1, newScene); // 缩放
		auto tran = TransitionMoveInR::create(1, newScene); // 从右移入


		Director::getInstance()->replaceScene(tran);
	}, 2,"Test");

	return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

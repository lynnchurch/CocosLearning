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
		//auto tran = TransitionCrossFade::create(1, newScene); // ���뵭��
		//auto tran = TransitionZoomFlipAngular::create(1, newScene); // ��ת
		//auto tran = TransitionPageTurn::create(1, newScene, false); // ��ҳ
		//auto tran = TransitionProgressRadialCCW::create(1, newScene); // ˳ʱ��
		//auto tran = TransitionSplitRows::create(1, newScene); // ����
		//auto tran = TransitionFadeDown::create(1,newScene); // ��Ҷ��
		//auto tran = TransitionShrinkGrow::create(1, newScene); // ����
		auto tran = TransitionMoveInR::create(1, newScene); // ��������


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

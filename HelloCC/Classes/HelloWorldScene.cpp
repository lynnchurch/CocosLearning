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

	auto map = TMXTiledMap::create("map.tmx");
	addChild(map);

	// ��ȡ��ͼ����
	auto mapPro = map->getProperties();
	CCLOG("map pro:%s", mapPro["type"].asString().c_str());

	// ��ȡͼ������
	auto layerPro = map->getLayer("scene")->getProperties();
	CCLOG("layer pro:%s", layerPro["type"].asString().c_str());

	// ��ȡͼ������
	auto graphPro = map->getPropertiesForGID(2).asValueMap();
	CCLOG("graph pro:%s", graphPro["type"].asString().c_str());

	// ��ȡ��������
	auto objPro = map->getObjectGroup("object")->getProperties();
	CCLOG("obj pro:%s", objPro["type"].asString().c_str());

	// �޸�ָ���������ɫ
	auto colorObj = map->getObjectGroup("object")->getObject("color");
	auto colorObjX = colorObj["x"].asInt();
	auto colorObjY = colorObj["y"].asInt();
	auto colorObjW = colorObj["width"].asInt();
	auto colorObjH = colorObj["height"].asInt();
	auto rect = DrawNode::create();
	rect->drawSolidRect(Vec2(colorObjX, colorObjY), Vec2(colorObjX + colorObjW, colorObjY + colorObjH), Color4F(Color3B(255, 0, 0)));
	addChild(rect);

	// ����С��
	auto player = map->getObjectGroup("object")->getObject("player");
	auto boll = Sprite::create("c.png");
	boll->setPosition(Vec2(player["x"].asFloat(), player["y"].asFloat()));
	addChild(boll);

	// ��Ƭ����ײ���
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [boll, map](Touch *t, Event *e)
	{
		auto point = map->convertToNodeSpace(t->getLocation());
		auto tileX = static_cast<int>(point.x / 32);
		auto tileY = map->getMapSize().height - static_cast<int>(point.y / 32) - 1;
		auto gid = map->getLayer("scene")->getTileGIDAt(Vec2(tileX, tileY));
		auto gidPro = map->getPropertiesForGID(gid);
		CCLOG("gid:%d", gid);
		if (!gidPro.isNull())
		{
			auto pro = map->getPropertiesForGID(gid).asValueMap();
			if (!pro["movable"].isNull() && pro["movable"].asBool())
			{
				boll->setPosition(point);
			}
		}
		
		return true;
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

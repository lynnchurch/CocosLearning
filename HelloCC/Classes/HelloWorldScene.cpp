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

	// 获取地图属性
	auto mapPro = map->getProperties();
	CCLOG("map pro:%s", mapPro["type"].asString().c_str());

	// 获取图层属性
	auto layerPro = map->getLayer("scene")->getProperties();
	CCLOG("layer pro:%s", layerPro["type"].asString().c_str());

	// 获取图块属性
	auto graphPro = map->getPropertiesForGID(2).asValueMap();
	CCLOG("graph pro:%s", graphPro["type"].asString().c_str());

	// 获取对象属性
	auto objPro = map->getObjectGroup("object")->getProperties();
	CCLOG("obj pro:%s", objPro["type"].asString().c_str());

	// 修改指定区域的颜色
	auto colorObj = map->getObjectGroup("object")->getObject("color");
	auto colorObjX = colorObj["x"].asInt();
	auto colorObjY = colorObj["y"].asInt();
	auto colorObjW = colorObj["width"].asInt();
	auto colorObjH = colorObj["height"].asInt();
	auto rect = DrawNode::create();
	rect->drawSolidRect(Vec2(colorObjX, colorObjY), Vec2(colorObjX + colorObjW, colorObjY + colorObjH), Color4F(Color3B(255, 0, 0)));
	addChild(rect);

	// 加载小球
	auto player = map->getObjectGroup("object")->getObject("player");
	auto boll = Sprite::create("c.png");
	boll->setPosition(Vec2(player["x"].asFloat(), player["y"].asFloat()));
	addChild(boll);

	// 瓦片的碰撞检测
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

#include "HelloWorldScene.h"
#include "tinyxml2/tinyxml2.h"
#include "json/document.h"
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

	// 首选项的读写
	/*UserDefault::getInstance()->setStringForKey("data", "Hello Lynn!");
	auto data = UserDefault::getInstance()->getStringForKey("data", "Hello World!");
	MessageBox(data.c_str(), "Message");*/

	// 文件的读写
	//auto fu = FileUtils::getInstance();
	//CCLOG("file path:%s", fu->getWritablePath().c_str());
	//auto filePath = fu->fullPathFromRelativeFile("data.txt", fu->getWritablePath());
	///*auto file = fopen(filePath.c_str(), "w");
	//fprintf(file, "Hello Lynn.\n");
	//fclose(file);*/
	//auto data=fu->getDataFromFile(filePath);
	//CCLOG("file content:%s", data.getBytes());

	// plist文件的读取
	/*auto fu = FileUtils::getInstance();
	auto vm = fu->getValueMapFromFile("user_info.plist");
	auto jack = vm["jack"].asValueMap();
	CCLOG("jack's phone_num:%s",jack["phone_num"].asString().c_str());*/

	// xml文件的读取
	/*auto doc = new tinyxml2::XMLDocument();
	doc->Parse(FileUtils::getInstance()->getStringFromFile("user_info.xml").c_str());
	auto root = doc->RootElement();
	for (auto e = root->FirstChildElement(); e; e = e->NextSiblingElement())
	{
	std::string s;
	for (auto attr = e->FirstAttribute(); attr; attr = attr->Next())
	{
	s+=attr->Name();
	s += ":";
	s += attr->Value();
	s += " ";
	}
	CCLOG("people:%s\n", s.c_str());
	}*/

	// json文件的读取
	rapidjson::Document doc;
	doc.Parse<0>(FileUtils::getInstance()->getStringFromFile("user_info.json").c_str());
	std::string str = doc[(int)0]["name"].GetString();
	str += ":";
	str += doc[(int)0]["age"].GetString();
	str += "\n";
	str += doc[1]["name"].GetString();
	str += ":";
	str += doc[1]["age"].GetString();
	CCLOG(str.c_str());
	return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

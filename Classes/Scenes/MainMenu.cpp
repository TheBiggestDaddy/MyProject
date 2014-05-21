#include "MainMenu.h"
#include <ADLib.h>

using namespace cocos2d;

MainMenu::MainMenu()
    : _logo(nullptr)
{
}

CCScene* MainMenu::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();

    // 'layer' is an autorelease object
    MainMenu *layer = MainMenu::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}


MainMenu* MainMenu::create()
{

    MainMenu *pRet = new MainMenu();
    if (pRet && pRet->init())
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = NULL;
        return NULL;
    }
}

void MainMenu::onBackClick()
{
    CCLog("Back clicked");
}
void MainMenu::onButtonClick()
{
    ADBrowser::openWebURL("http://google.com/");
    _logo->runAction(CCSequence::create(
                         CCEaseElasticOut::create(
                             CCMoveBy::create(2.5f, ccp(100, 100))),
                         CCMoveBy::create(0.1f, ccp(-100,-100)),
                         NULL));
}

bool MainMenu::init()
{
    if(!SceneStyle::init())
        return false;

    //ADSoundManager::playMusic(GameInfo::MENU_MUSIC);

    //Get the screen start of cordinates
    const CCPoint ORIGIN = ADScreen::getOrigin();
    const CCSize VISIBLE_SIZE = ADScreen::getVisibleSize();
    const float SCALE = ADScreen::getScaleFactor();

    _logo = CCSprite::create("flow/flower9.png");
    _logo->setPosition(ccp(ORIGIN.x + 30/SCALE, ORIGIN.y + 30/SCALE));
    _logo->setAnchorPoint(ccp(0,0));
    this->addChild(_logo);

    CCSprite* logo = CCSprite::create("main-menu/facebook_logo.png");
    //logo->setAnchorPoint(ccp(1,1));
    //logo->setPosition(ORIGIN + VISIBLE_SIZE);
    //this->addChild(logo);

    CCMenu* menu = CCMenu::create();

    ADMenuItem* item = ADMenuItem::create(logo);
    //logo->setAnchorPoint(ccp(1,1));
    item->setPosition(ORIGIN + VISIBLE_SIZE*0.5f);


    CCLabelTTF* label = CCLabelTTF::create("Hello", ADLanguage::getFontName(), 30);
    label->setColor(ccc3(255,0,0));
    label->setPosition(item->getContentSize()*0.5f);
    label->setScale(item->getContentSize().width*0.9f / label->getContentSize().width);
    item->addChild(label);
    CONNECT(item->signalOnClick, this, &MainMenu::onButtonClick);

    menu->addChild(item);
    menu->setPosition(ccp(0,0));

    this->addChild(menu);



    return true;
}


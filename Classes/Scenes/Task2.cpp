#include "Task2.h"
#include "MainMenu.h"
#include <ADLib.h>

using namespace cocos2d;

Task2::Task2()
    : _logo(nullptr)
{
}

CCScene* Task2::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();

    // 'layer' is an autorelease object
    Task2 *layer = Task2::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}


Task2* Task2::create()
{

    Task2 *pRet = new Task2();
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

void Task2::onButtonClick()
{
   // CCDirector::sharedDirector()->replaceScene(MainMenue::scene());
}

bool Task2::init()
{
    if(!SceneStyle::init())
        return false;

    const CCPoint ORIGIN = ADScreen::getOrigin();
    const float SCALE = ADScreen::getScaleFactor();
    const CCSize VISIBLE_SIZE = ADScreen::getVisibleSize();

    CCMenu* title_menu = CCMenu::create();
    CCMenu* books_menu = CCMenu::create();

    books_menu->setAnchorPoint(ccp(0,1));
    books_menu->setPosition(ORIGIN);

    CCSprite* title_background = CCSprite::create("first_task/top_panel.png");
    CCSprite* logo_text = CCSprite::create("first_task/logo.png");
    CCSprite* settings_picture = CCSprite::create("first_task/settings-button.png");

    CCSprite* book_picture_1 = CCSprite::create("first_task/button_2.png");
    CCSprite* book_picture_2 = CCSprite::create("first_task/button_2.png");
    CCSprite* book_picture_3 = CCSprite::create("first_task/button_2.png");
    CCSprite* book_picture_4 = CCSprite::create("first_task/button_2.png");
    CCSprite* book_picture_5 = CCSprite::create("first_task/button_2.png");

    ADMenuItem* settings_button = ADMenuItem::create(settings_picture);

    ADMenuItem* book_1 = ADMenuItem::create(book_picture_1);
    ADMenuItem* book_2 = ADMenuItem::create(book_picture_2);
    ADMenuItem* book_3 = ADMenuItem::create(book_picture_3);
    ADMenuItem* book_4 = ADMenuItem::create(book_picture_4);
    ADMenuItem* book_5 = ADMenuItem::create(book_picture_5);

    books_menu->addChild(book_1);
    books_menu->addChild(book_2);
    books_menu->addChild(book_3);
    books_menu->addChild(book_4);
    books_menu->addChild(book_5);

    CCLabelTTF* book_label_1 = CCLabelTTF::create("BOOK 1", ADLanguage::getFontName(), 30);
    CCLabelTTF* book_label_2 = CCLabelTTF::create("BOOK 2", ADLanguage::getFontName(), 30);
    CCLabelTTF* book_label_3 = CCLabelTTF::create("BOOK 3", ADLanguage::getFontName(), 30);
    CCLabelTTF* book_label_4 = CCLabelTTF::create("BOOK 4", ADLanguage::getFontName(), 30);
    CCLabelTTF* book_label_5 = CCLabelTTF::create("BOOK 5", ADLanguage::getFontName(), 30);

    book_label_1->setColor(ccc3(255,0,0));
    book_label_2->setColor(ccc3(255,0,0));
    book_label_3->setColor(ccc3(255,0,0));
    book_label_4->setColor(ccc3(255,0,0));
    book_label_5->setColor(ccc3(255,0,0));

    book_label_1->setPosition(book_1->getContentSize()*0.5f);
    book_label_2->setPosition(book_2->getContentSize()*0.5f);
    book_label_3->setPosition(book_3->getContentSize()*0.5f);
    book_label_4->setPosition(book_4->getContentSize()*0.5f);
    book_label_5->setPosition(book_5->getContentSize()*0.5f);

    book_1->addChild(book_label_1);
    book_2->addChild(book_label_2);
    book_3->addChild(book_label_3);
    book_4->addChild(book_label_4);
    book_5->addChild(book_label_5);

    book_1->setAnchorPoint(ccp(0.5,1));
    book_2->setAnchorPoint(ccp(0.5,1));
    book_3->setAnchorPoint(ccp(0.5,1));
    book_4->setAnchorPoint(ccp(0.5,1));
    book_5->setAnchorPoint(ccp(0.5,1));


    const float TITLE_SCALE = VISIBLE_SIZE.width / title_background->getContentSize().width;

    book_1->setPosition(ccp(VISIBLE_SIZE.width/3,
                           6*(VISIBLE_SIZE.height-title_background->getContentSize().height*TITLE_SCALE)/7));
    book_2->setPosition(ccp(2*VISIBLE_SIZE.width/3,
                           6*(VISIBLE_SIZE.height-title_background->getContentSize().height*TITLE_SCALE)/7));

    book_3->setPosition(ccp(VISIBLE_SIZE.width/3,
                           4*(VISIBLE_SIZE.height-title_background->getContentSize().height*TITLE_SCALE)/7));

    book_4->setPosition(ccp(2*VISIBLE_SIZE.width/3,
                           4*(VISIBLE_SIZE.height-title_background->getContentSize().height*TITLE_SCALE)/7));
    book_5->setPosition(ccp(VISIBLE_SIZE.width/3,
                           2*(VISIBLE_SIZE.height-title_background->getContentSize().height*TITLE_SCALE)/7));

    settings_picture->setScale(TITLE_SCALE*title_background->getContentSize().height/(2*settings_picture->getContentSize().height));

    title_background->setScale(TITLE_SCALE);
    title_background->setAnchorPoint(ccp(0,0));
    title_background->setPosition(ccp(ORIGIN.x,ORIGIN.y+VISIBLE_SIZE.height-title_background->getContentSize().height*TITLE_SCALE));
    //title_background->setPosition(ccp(100,100));

    //title_menu->setAnchorPoint(ccp(0,1));
    title_menu->addChild(settings_button);
    title_menu->setZOrder(1);
    title_menu->setPosition(ccp(ORIGIN.x + 20/SCALE + settings_picture->getContentSize().width * 0.5f,
                                ORIGIN.y + VISIBLE_SIZE.height - title_background->getContentSize().height*0.5*TITLE_SCALE));
    settings_button->setPositionX(VISIBLE_SIZE.width-settings_button->getContentSize().width-20/SCALE);


    logo_text->setScale((title_background->getContentSize().height * TITLE_SCALE)/logo_text->getContentSize().height-0.1f);
    logo_text->setZOrder(1);
    logo_text->setPosition(ccp(ORIGIN.x + title_background->getContentSize().width*0.5f*TITLE_SCALE,
                               ORIGIN.y + VISIBLE_SIZE.height - title_background->getContentSize().height*0.5*TITLE_SCALE));

    logo_text->setScale((title_background->getContentSize().height * TITLE_SCALE)/logo_text->getContentSize().height-0.1f);
    logo_text->setZOrder(1);
    logo_text->setPosition(ccp(ORIGIN.x + title_background->getContentSize().width*0.5f*TITLE_SCALE,
                               ORIGIN.y + VISIBLE_SIZE.height - title_background->getContentSize().height*0.5*TITLE_SCALE));

    this->addChild(title_menu);
    this->addChild(books_menu);
    this->addChild(title_background);
    this->addChild(logo_text);
    return true;
}


//{
//    if(!SceneStyle::init())
//        return false;

//    const CCPoint ORIGIN = ADScreen::getOrigin();
//    const float SCALE = ADScreen::getScaleFactor();
//    const CCSize VISIBLE_SIZE = ADScreen::getVisibleSize();

//    CCMenu* titleMenue = CCMenu::create();
//    CCMenu* button_menue = CCMenu::create();


//    CCSprite* title_background = CCSprite::create("first_task/top_panel.png");
//    CCSprite* back_button_picture = CCSprite::create("first_task/back_button.png");
//    CCSprite* logo_text = CCSprite::create("first_task/logo.png");
//    CCSprite* settings_picture = CCSprite::create("first_task/settings-button.png");

//    CCSprite* button_picture_1 = CCSprite::create("first_task/button_1.png");
//    CCSprite* button_picture_2 = CCSprite::create("first_task/button_1.png");
//    CCSprite* button_picture_3 = CCSprite::create("first_task/button_1.png");

//    ADMenuItem* back_button = ADMenuItem::create(back_button_picture);
//    ADMenuItem* settings_button = ADMenuItem::create(settings_picture);
//    ADMenuItem* button_1 = ADMenuItem::create(button_picture_1);
//    ADMenuItem* button_2 = ADMenuItem::create(button_picture_2);
//    ADMenuItem* button_3 = ADMenuItem::create(button_picture_3);

//    CCLabelTTF* label_butt_1 = CCLabelTTF::create("BUTTON 1", ADLanguage::getFontName(), 30);
//    CCLabelTTF* label_butt_2 = CCLabelTTF::create("BUTTON 2", ADLanguage::getFontName(), 30);
//    CCLabelTTF* label_butt_3 = CCLabelTTF::create("BUTTON 3", ADLanguage::getFontName(), 30);

//    CCLabelTTF* created = CCLabelTTF::create("created in Ukraine", ADLanguage::getFontName(), 50);

//    created->setPosition(ccp(ORIGIN.x+VISIBLE_SIZE.width*0.5f,ORIGIN.y+created->getContentSize().height*1.5f));
//    created->setColor(ccc3(125,125,215));

//    label_butt_1->setPosition(button_1->getContentSize()*0.5f);
//    label_butt_2->setPosition(button_2->getContentSize()*0.5f);
//    label_butt_3->setPosition(button_3->getContentSize()*0.5f);

//    button_1->addChild(label_butt_1);
//    button_2->addChild(label_butt_2);
//    button_3->addChild(label_butt_3);

//    button_1->setColor(ccc3(250,0,0));
//    button_2->setColor(ccc3(0,250,0));
//    button_3->setColor(ccc3(0,0,250));

//    button_1->setPositionY(button_1->getPositionY()+button_1->getContentSize().height*2);
//    button_3->setPositionY(button_3->getPositionY()-button_3->getContentSize().height*2);

//    button_menue->addChild(button_1);
//    button_menue->addChild(button_2);
//    button_menue->addChild(button_3);

//    const float TITLE_SCALE = VISIBLE_SIZE.width / title_background->getContentSize().width;

//    title_background->setScale(TITLE_SCALE);
//    back_button_picture->setScale(TITLE_SCALE);
//    settings_picture->setScale(TITLE_SCALE*title_background->getContentSize().height/(2*settings_picture->getContentSize().height));


//    title_background->setAnchorPoint(ccp(0,1));
//    title_background->setPosition(ccp(ORIGIN.x,ORIGIN.y+VISIBLE_SIZE.height));

//    titleMenue->addChild(back_button);
//    titleMenue->addChild(settings_button);
//    titleMenue->setZOrder(1);
//    titleMenue->setPosition(ccp(ORIGIN.x + 20/SCALE + back_button->getContentSize().width * 0.5f,
//                                ORIGIN.y + VISIBLE_SIZE.height - title_background->getContentSize().height*0.5*TITLE_SCALE));
//    settings_button->setPositionX(VISIBLE_SIZE.width-settings_button->getContentSize().width-20/SCALE);


//    logo_text->setScale((title_background->getContentSize().height * TITLE_SCALE)/logo_text->getContentSize().height-0.1f);
//    logo_text->setZOrder(1);
//    logo_text->setPosition(ccp(ORIGIN.x + title_background->getContentSize().width*0.5f*TITLE_SCALE,
//                               ORIGIN.y + VISIBLE_SIZE.height - title_background->getContentSize().height*0.5*TITLE_SCALE));




//    this->addChild(logo_text);
//    this->addChild(titleMenue);
//    this->addChild(title_background);
//    this->addChild(button_menue);
//    this->addChild(created);


//    CONNECT(settings_button->signalOnClick, this, &Task2::onButtonClick);
//    return true;
//}


////Get the screen start of cordinates
//const CCPoint ORIGIN = ADScreen::getOrigin();
//const CCSize VISIBLE_SIZE = ADScreen::getVisibleSize();
//const float SCALE = ADScreen::getScaleFactor();

//_logo = CCSprite::create("flow/flower9.png");
//_logo->setPosition(ccp(ORIGIN.x + 30/SCALE, ORIGIN.y + 30/SCALE));
//_logo->setAnchorPoint(ccp(0,0));
//this->addChild(_logo);

//CCSprite* logo = CCSprite::create("main-menu/facebook_logo.png");
////logo->setAnchorPoint(ccp(1,1));
////logo->setPosition(ORIGIN + VISIBLE_SIZE);
////this->addChild(logo);

//CCMenu* menu = CCMenu::create();

//ADMenuItem* item = ADMenuItem::create(logo);
////logo->setAnchorPoint(ccp(1,1));
//item->setPosition(ORIGIN + VISIBLE_SIZE*0.5f);


//CCLabelTTF* label = CCLabelTTF::create("Hello", ADLanguage::getFontName(), 30);
//label->setColor(ccc3(255,0,0));
//label->setPosition(item->getContentSize()*0.5f);
//label->setScale(item->getContentSize().width*0.9f / label->getContentSize().width);
//item->addChild(label);
//CONNECT(item->signalOnClick, this, &Task2::onButtonClick);

//menu->addChild(item);
//menu->setPosition(ccp(0,0));

//this->addChild(menu);

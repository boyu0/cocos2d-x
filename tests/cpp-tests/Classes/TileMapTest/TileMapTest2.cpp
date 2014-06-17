#include "TileMapTest2.h"
#include "../testResource.h"

#include "2d/CCTMXLayer2.h"
#include "2d/CCTMXTiledMap2.h"

namespace
{
    enum
    {
        kTagTileMap = 1,
    };
    
    Layer* nextTileMapActionNew();
    Layer* backTileMapActionNew();
    Layer* restartTileMapAction();
    
    //------------------------------------------------------------------
    //
    // TileDemoNew
    //
    //------------------------------------------------------------------
    
    enum
    {
        IDC_NEXT = 100,
        IDC_BACK,
        IDC_RESTART
    };
    
    static int sceneIdx = -1;
    
#define MAX_LAYER    4
    
    static std::function<Layer*()> createFunctions[] = {
        CLN(TMXPerformaceTest1),
        CLN(TMXPerformaceTest2),
        CLN(TMXPerformaceTest3),
        CLN(TMXPerformaceTest4),
    };
    
    Layer* createTileMalayer(int nIndex)
    {
        return createFunctions[nIndex]();
    }
    
    Layer* nextTileMapAction()
    {
        sceneIdx++;
        sceneIdx = sceneIdx % MAX_LAYER;
        
        return createTileMalayer(sceneIdx);
    }
    
    Layer* backTileMapAction()
    {
        sceneIdx--;
        int total = MAX_LAYER;
        if( sceneIdx < 0 )
            sceneIdx += total;
        
        return createTileMalayer(sceneIdx);
    }
    
    Layer* restartTileMapAction()
    {
        return createTileMalayer(sceneIdx);
    }
}

TileDemoNew::TileDemoNew(void)
: BaseTest()
{
//    auto listener = EventListenerTouchAllAtOnce::create();
//    listener->onTouchesMoved = CC_CALLBACK_2(TileDemoNew::onTouchesMoved, this);
//    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

TileDemoNew::~TileDemoNew(void)
{
}

std::string TileDemoNew::title() const
{
    return "No title";
}

std::string TileDemoNew::subtitle() const
{
    return "drag the screen";
}

void TileDemoNew::onEnter()
{
    BaseTest::onEnter();
}

void TileDemoNew::onExit()
{
    BaseTest::onExit();
    Director::getInstance()->setDepthTest(false);
}
void TileDemoNew::restartCallback(Ref* sender)
{
    auto s = new TileMapTestSceneNew();
    s->addChild(restartTileMapAction());

    Director::getInstance()->replaceScene(s);
    s->release();
}

void TileDemoNew::nextCallback(Ref* sender)
{
    auto s = new TileMapTestSceneNew();
    s->addChild( nextTileMapAction() );
    Director::getInstance()->replaceScene(s);
    s->release();
}

void TileDemoNew::backCallback(Ref* sender)
{
    auto s = new TileMapTestSceneNew();
    s->addChild( backTileMapAction() );
    Director::getInstance()->replaceScene(s);
    s->release();
}

void TileDemoNew::onTouchesMoved(const std::vector<Touch*>& touches, Event  *event)
{
//    auto touch = touches[0];
//
//    auto diff = touch->getDelta();
//    auto node = getChildByTag(kTagTileMap);
//    auto currentPos = node->getPosition();
//    node->setPosition(currentPos + diff);
}

void TileMapTestSceneNew::runThisTest()
{
    auto layer = nextTileMapAction();
    addChild(layer);
    
    // fix bug #486, #419.
    // "test" is the default value in Director::setGLDefaultValues()
    // but TransitionTest may setDepthTest(false), we should revert it here
    Director::getInstance()->setDepthTest(true);
    
    Director::getInstance()->replaceScene(this);
}


void TMXPerformaceTest1::onEnter()
{
    TileDemoNew::onEnter();
    
#if ( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
    int count = 10;
#else
    int count = 80;
#endif
    
    for (int i = 0; i < count; ++i)
    {
        auto map = TMXTiledMap2::create("TileMaps/iso-test-zorder.tmx");
        map->setScale(0.5);
        map->setPosition(Vec2(-i, i));
        this->addChild(map);
    }
}

std::string TMXPerformaceTest1::title() const
{
    return "tmx without action";
}


void TMXPerformaceTest2::onEnter()
{
    TileDemoNew::onEnter();
    
    
#if ( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
    int count = 10;
#else
    int count = 80;
#endif
    
    for (int i = 0; i < count; ++i)
    {
        auto map = TMXTiledMap2::create("TileMaps/iso-test-zorder.tmx");
        map->setScale(0.5);
        map->setPosition(Vec2(-i, i));
        
        auto moveBy = MoveBy::create(3.0, Vec2(300, 300));
        map->runAction(RepeatForever::create(Sequence::create(moveBy, moveBy->reverse(), nullptr)));
        
        this->addChild(map);
    }
}

std::string TMXPerformaceTest2::title() const
{
    return "tmx with action";
}


void TMXPerformaceTest3::onEnter()
{
    TileDemoNew::onEnter();
    
    
#if ( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
    int count = 20;
#else
    int count = 80;
#endif
    
    for (int i = 0; i < count; ++i)
    {
        auto map = TMXTiledMap2::create("TileMaps/iso-test-zorder.tmx");
        map->setPosition(Vec2(i + 100, i + 100));
        this->addChild(map);
    }
}

std::string TMXPerformaceTest3::title() const
{
    return "tmx culling";
}


void TMXPerformaceTest4::onEnter()
{
    TileDemoNew::onEnter();
    
#if ( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
    int count = 30;
#else
    int count = 80;
#endif
    
    for (int i = 0; i < count; ++i)
    {
        auto map = TMXTiledMap2::create("TileMaps/iso-test-zorder.tmx");
        map->setPosition(Vec2(1000+i, 1000+i));
        this->addChild(map);
    }
}

std::string TMXPerformaceTest4::title() const
{
    return "tmx not shown";
}
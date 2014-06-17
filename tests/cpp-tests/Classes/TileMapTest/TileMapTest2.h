#ifndef _TILEMAP_TEST_NEW_H_
#define _TILEMAP_TEST_NEW_H_

#include "../testBasic.h"
#include "../BaseTest.h"

class TileDemoNew : public BaseTest
{
public:
    TileDemoNew(void);
    virtual ~TileDemoNew(void);

    virtual std::string title() const override;
    virtual std::string subtitle() const override;
    virtual void onEnter() override;
    virtual void onExit()override;

    void restartCallback(Ref* sender);
    void nextCallback(Ref* sender);
    void backCallback(Ref* sender);

    void onTouchesMoved(const std::vector<Touch*>& touches, Event  *event);
};

class TMXPerformaceTest1 : public TileDemoNew
{
public:
    virtual void onEnter() override;
    virtual std::string title() const override;
};

class TMXPerformaceTest2 : public TileDemoNew
{
public:
    virtual void onEnter() override;
    virtual std::string title() const override;
};

class TMXPerformaceTest3 : public TileDemoNew
{
public:
    virtual void onEnter() override;
    virtual std::string title() const override;
};

class TMXPerformaceTest4 : public TileDemoNew
{
public:
    virtual void onEnter() override;
    virtual std::string title() const override;
};

class TileMapTestSceneNew : public TestScene
{
public:
    virtual void runThisTest();
};

#endif

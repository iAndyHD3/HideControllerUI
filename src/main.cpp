

#include <Geode/modify/CreatorLayer.hpp>
#include <Geode/modify/EditLevelLayer.hpp>
#include <Geode/modify/EndLevelLayer.hpp>
#include <Geode/modify/FLAlertLayer.hpp>
#include <Geode/modify/GJDropDownLayer.hpp>
#include <Geode/modify/GJGarageLayer.hpp>
#include <Geode/modify/GJShopLayer.hpp>
#include <Geode/modify/GauntletLayer.hpp>
#include <Geode/modify/GauntletSelectLayer.hpp>
#include <Geode/modify/LeaderboardsLayer.hpp>
#include <Geode/modify/LevelAreaInnerLayer.hpp>
#include <Geode/modify/LevelAreaLayer.hpp>
#include <Geode/modify/LevelBrowserLayer.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>
#include <Geode/modify/LevelListLayer.hpp>
#include <Geode/modify/LevelPage.hpp>
#include <Geode/modify/LevelSearchLayer.hpp>
#include <Geode/modify/LevelSelectLayer.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include <Geode/modify/RetryLevelLayer.hpp>
#include <Geode/modify/SecretLayer.hpp>
#include <Geode/modify/SecretLayer2.hpp>
#include <Geode/modify/SecretLayer3.hpp>
#include <Geode/modify/SecretLayer4.hpp>
#include <Geode/modify/SecretLayer5.hpp>
#include <Geode/modify/SecretLayer6.hpp>
#include <Geode/modify/SecretRewardsLayer.hpp>
#include <Geode/modify/UILayer.hpp>
#include <Geode/modify/WorldSelectLayer.hpp>

using namespace geode;
using namespace cocos2d;

struct CCApplicationExt : CCApplication {
  void setControllerEnabled(bool val) { m_bControllerConnected = val; }
  static CCApplicationExt* get() {
    return static_cast<CCApplicationExt*>(CCApplication::get());
  }
};

template <typename T> struct CallHelper {
  template <typename F> static T call(F&& f) { return f(); }
};

template <> struct CallHelper<void> {
  template <typename F> static void call(F&& f) { f(); }
};

#define NUMARGS(...) (sizeof((int[]){__VA_ARGS__}) / sizeof(int))

#define GENERATE_MODIFY_N_ARGS(modifyclass, ret, func, args, ...)              \
  class $modify(modifyclass) {                                                 \
  public:                                                                      \
    ret func args {                                                            \
      auto app = CCApplicationExt::get();                                      \
      app->setControllerEnabled(false);                                        \
      return modifyclass::func(__VA_ARGS__);                                   \
    }                                                                          \
  };
// clang-format off
#define GENERATE_MODIFY_0(modifyclass, ret, func, args) GENERATE_MODIFY_N_ARGS(modifyclass, ret, func, args)
#define GENERATE_MODIFY_1(modifyclass, ret, func, args) GENERATE_MODIFY_N_ARGS(modifyclass, ret, func, args, p0)
#define GENERATE_MODIFY_2(modifyclass, ret, func, args) GENERATE_MODIFY_N_ARGS(modifyclass, ret, func, args, p0, p1)
#define GENERATE_MODIFY_3(modifyclass, ret, func, args) GENERATE_MODIFY_N_ARGS(modifyclass, ret, func, args, p0, p1, p2)
#define GENERATE_MODIFY_4(modifyclass, ret, func, args) GENERATE_MODIFY_N_ARGS(modifyclass, ret, func, args, p0, p1, p2, p3)
#define GENERATE_MODIFY_5(modifyclass, ret, func, args) GENERATE_MODIFY_N_ARGS(modifyclass, ret, func, args, p0, p1, p2, p3, p4)
#define GENERATE_MODIFY_6(modifyclass, ret, func, args) GENERATE_MODIFY_N_ARGS(modifyclass, ret, func, args, p0, p1, p2, p3, p4, p5)
#define GENERATE_MODIFY_7(modifyclass, ret, func, args) GENERATE_MODIFY_N_ARGS(modifyclass, ret, func, args, p0, p1, p2, p3, p4, p5, p6)
#define GENERATE_MODIFY_8(modifyclass, ret, func, args) GENERATE_MODIFY_N_ARGS(modifyclass, ret, func, args, p0, p1, p2, p3, p4, p5, p6, p7)
#define GENERATE_MODIFY_9(modifyclass, ret, func, args) GENERATE_MODIFY_N_ARGS(modifyclass, ret, func, args, p0, p1, p2, p3, p4, p5, p6, p7, p8)
#define GENERATE_MODIFY_10(modifyclass, ret, func, args) GENERATE_MODIFY_N_ARGS(modifyclass, ret, func, args, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9)

// clang-format off
//MISSING: UILayer because thats actually custom keybinds

GENERATE_MODIFY_0(CreatorLayer, bool, init, ())
GENERATE_MODIFY_1(EditLevelLayer, bool, init, (GJGameLevel * p0))
GENERATE_MODIFY_0(EndLevelLayer, void, customSetup, ())
GENERATE_MODIFY_9(FLAlertLayer, bool, init, (FLAlertLayerProtocol * p0, char const* p1, gd::string p2, char const* p3, char const* p4, float p5, bool p6, float p7, float p8))
GENERATE_MODIFY_3(GJDropDownLayer, bool, init, (char const* p0, float p1, bool p2))
GENERATE_MODIFY_0(GJGarageLayer, bool, init, ())
GENERATE_MODIFY_1(GJShopLayer, bool, init, (ShopType p0))
GENERATE_MODIFY_1(GauntletLayer, bool, init, (GauntletType p0))
GENERATE_MODIFY_1(GauntletSelectLayer, bool, init, (int p0))
GENERATE_MODIFY_1(LeaderboardsLayer, bool, init, (LeaderboardState p0))
GENERATE_MODIFY_1(LevelAreaInnerLayer, bool, init, (bool p0))
GENERATE_MODIFY_0(LevelAreaLayer, bool, init, ())
GENERATE_MODIFY_1(LevelBrowserLayer, bool, init, (GJSearchObject * p0))
GENERATE_MODIFY_2(LevelInfoLayer, bool, init, (GJGameLevel * p0, bool p1))
GENERATE_MODIFY_1(LevelListLayer, bool, init, (GJLevelList * p0))
GENERATE_MODIFY_1(LevelPage, bool, init, (GJGameLevel * p0))
GENERATE_MODIFY_1(LevelSearchLayer, bool, init, (int p0))
GENERATE_MODIFY_1(LevelSelectLayer, bool, init, (int p0))
GENERATE_MODIFY_0(MenuLayer, bool, init, ())
GENERATE_MODIFY_0(PauseLayer, void, customSetup, ())
GENERATE_MODIFY_0(RetryLevelLayer, void, customSetup, ())
GENERATE_MODIFY_0(SecretLayer2, bool, init, ())
GENERATE_MODIFY_0(SecretLayer3, bool, init, ())
GENERATE_MODIFY_0(SecretLayer4, bool, init, ())
GENERATE_MODIFY_0(SecretLayer5, bool, init, ())
GENERATE_MODIFY_0(SecretLayer, bool, init, ())
GENERATE_MODIFY_1(SecretRewardsLayer, bool, init, (bool p0))
GENERATE_MODIFY_1(UILayer, bool, init, (GJBaseGameLayer * p0))

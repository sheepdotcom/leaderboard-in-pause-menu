#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/PauseLayer.hpp>
class $modify(LDPauseLayer, PauseLayer) {
	void customSetup() {
		PauseLayer::customSetup();
		auto rightButtonMenu = this->getChildByID("right-button-menu");
		auto spr = CCSprite::createWithSpriteFrameName("GJ_levelLeaderboardBtn_001.png");
		spr->setScale(0.65f);
		auto btn = CCMenuItemSpriteExtra::create(spr, this, menu_selector(LDPauseLayer::onLeaderboard));
		btn->setID("leaderboard-button");
		rightButtonMenu->addChild(btn);
	}
	
	void onLeaderboard(CCObject* sender) {
		if (PlayLayer::get()) {
			auto level = PlayLayer::get()->m_level;
			auto levelLeaderboardType = static_cast<LevelLeaderboardType>(GameManager::get()->getIntGameVariable("0098"));
			auto levelLeaderboardMode = static_cast<LevelLeaderboardMode>(GameManager::get()->getIntGameVariable("0164"));
			LevelLeaderboard::create(level, levelLeaderboardType, levelLeaderboardMode)->show();
			return;
		}
		FLAlertLayer::create("Uh Oh", "No PlayLayer found, you sure you in a level?", "OK")->show();
	}
};
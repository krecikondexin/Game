#pragma once

#include <memory>
#include "Enums.h"
#include "TibiaMapCell.h"
#include "TibiaGameObiect.h"
#include "TibiaCreature.h"
#include <list>
#include <utility>
#include <tuple>
#include "TibiaWorld.h"
#include "TibiaGlobalAnimationTimer.h"
#include "TibiaPlayer.h"
#include <random>
namespace TCG
{
	namespace Global
	{
		class TGCGame
		{
			TGC::GlobalAnimationTimer globalAnimationTimer;
			std::shared_ptr<Player> player;
			TGC::World world;
			TGCGame(const TGCGame&);
			TGCGame();
			std::vector<std::pair<TGC::Creature*, TGC::ENUMS::Direction>> moveRequest;
			sf::RenderWindow* window;
		public:
			static TGCGame& getSingleton();
			void setWindow(sf::RenderWindow& window);
			~TGCGame() = default;
			void updateWorld(const float dt, std::shared_ptr<TGC::GameObiect> player);
			void draw(sf::RenderWindow& window);
			std::shared_ptr<TGC::Creature> getPlayer() { return player; }
			void addMoveRequest(TGC::Creature* creature, TGC::ENUMS::Direction dir);
			void resolveMoveRequest();
			void input(sf::Event& event);
			bool isEndAnimationTimeReached();
			template <typename T>
			static T generateRandomNumber(T min, T max);

		};


		template<typename T>
		inline T TGCGame::generateRandomNumber(T min, T max)
		{
			std::random_device randomDevice;
			std::default_random_engine randEng(randomDevice());
			std::uniform_int_distribution<T> uniform_dist(min, max);
			return uniform_dist(randEng);
		}
	}
}


#pragma once
#include "Arkanoid_Paddle.h"
#include "Arkanoid_IBuff.h"

namespace Arkanoid
{
	namespace Buffs
	{
		class BigPaddleBuff : public Arkanoid::Buffs::IBuff
		{
			Arkanoid::Paddle * paddlePTR;
		public:
			BigPaddleBuff() = delete;
			BigPaddleBuff(float duration, Arkanoid::Paddle & paddle);
			virtual void update(const float dt);
			~BigPaddleBuff();
		};
	}
}


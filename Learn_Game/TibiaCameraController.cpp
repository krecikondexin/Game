#include "TibiaCameraController.h"
#include <iostream>
#include "TibiaTGCGame.h"
#include "TibiaCreature.h"
TGC::Camera::CameraController::CameraController()
	:windowPRT(nullptr)
{
}

TGC::Camera::CameraController::CameraController(std::shared_ptr<TGC::Creature> target, sf::RenderWindow & window)
	:windowPRT(&window)
{
	viewObj.setSize(Setting::Const::windowsSizeX, Setting::Const::windowsSizeY);
	viewObj.zoom(Setting::Const::zoom);
	//windowPRT->setView(viewe);
	//viewe.setViewport(sf::Vector2f(target->getPosition()), windowPRT->);
//	viewe.setCenter(sf::Vector2f(target->getPosition().x, target->getPosition().y));
//	viewe.setSize(sf::Vector2f(windowPRT->getSize().x, windowPRT->getSize().y));
//	viewe.setViewport(sf::doubleRect(target->getPosition().x, target->getPosition().y, windowPRT->getSize().y, windowPRT->getSize().y));
//	viewe.setCenter(sf::Vector2f(target->getPosition().x, target->getPosition().y));
}

void TGC::Camera::CameraController::updateCamera(std::shared_ptr<TGC::Creature> target)
{
	viewObj.setCenter(sf::Vector2f(static_cast<double>(target->positionSprite.x), static_cast<double>(target->positionSprite.y)));
}

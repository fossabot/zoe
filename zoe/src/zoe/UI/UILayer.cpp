/*
 * UILayer.cpp
 *
 *  Created on: 12.11.2019
 *      Author: florian
 */

#include "UILayer.h"
#include "../render/api/Render.h"
#include "../Application.h"

namespace Zoe{

UILayer::UILayer(): Layer("UILayer") {
	setSubscribedEvents(EventCategoryApplication|EventCategoryInput);
}

UILayer::~UILayer() {
}

//------------------
//------EVENTS------
//------------------

void UILayer::onEvent(Event& event) {
	static std::function<bool(AppRenderEvent&)> onRenderEvent = std::bind(&UILayer::onRenderEvent, this, std::placeholders::_1);

	static std::function<bool(KeyPressedEvent&)> onKeyPressedEvent = std::bind(&UILayer::onKeyPressedEvent, this, std::placeholders::_1);
	static std::function<bool(KeyReleasedEvent&)> onKeyReleasedEvent = std::bind(&UILayer::onKeyReleasedEvent, this, std::placeholders::_1);

	static std::function<bool(MouseButtonPressedEvent&)> onMouseButtonPressedEvent = std::bind(&UILayer::onMouseButtonPressedEvent, this, std::placeholders::_1);
	static std::function<bool(MouseButtonReleasedEvent&)> onMouseButtonReleasedEvent = std::bind(&UILayer::onMouseButtonReleasedEvent, this, std::placeholders::_1);
	static std::function<bool(MouseMovedEvent&)> onMouseMoveEvent = std::bind(&UILayer::onMouseMoveEvent, this, std::placeholders::_1);

	EventDispatcher dispatcher(event);
	dispatcher.dispatch(onRenderEvent);

	dispatcher.dispatch(onKeyPressedEvent);
	dispatcher.dispatch(onKeyReleasedEvent);

	dispatcher.dispatch(onMouseButtonPressedEvent);
	dispatcher.dispatch(onMouseButtonReleasedEvent);
	dispatcher.dispatch(onMouseMoveEvent);
}

bool UILayer::onKeyPressedEvent(KeyPressedEvent& event) {

	return false;
}

bool UILayer::onKeyReleasedEvent(KeyReleasedEvent& event) {

	return false;
}

bool UILayer::onMouseButtonPressedEvent(MouseButtonPressedEvent& event) {

	return false;
}

bool UILayer::onMouseButtonReleasedEvent(MouseButtonReleasedEvent& event) {

	return false;
}

bool UILayer::onMouseMoveEvent(MouseMovedEvent& event) {

	return false;
}

//----------------------
//------COMPONENTS------
//----------------------

void UILayer::addOval(const float& x, const float& y, const float& w,
		const float& h, const Color& color) {
	Rectangle r {x,y,w,h,0};
	addComponent(new Oval(r,color));
}

void UILayer::addOval(const Rectangle& rect, const Color& color) {
	addComponent(new Oval(rect, color));
}

void UILayer::addRectangle(const float& x, const float& y, const float& w,
		const float& h, const Color& color) {
	throw std::runtime_error("not implemented");
}

void UILayer::addRectangle(const Rectangle& rect, const Color& color) {
	throw std::runtime_error("not implemented");
}

void UILayer::addText(const float& x, const float& y, const char* string,
		const Color& color) {
	throw std::runtime_error("not implemented");
}

void UILayer::addText(const Point& point, const char* string,
		const Color& color) {
	throw std::runtime_error("not implemented");
}

void UILayer::addText(const float& x, const float& y,
		const std::string& string, const Color& color) {
	throw std::runtime_error("not implemented");
}

void UILayer::addText(const Point& point, const std::string& string,
		const Color& color) {
	throw std::runtime_error("not implemented");
}

//

void UILayer::setColor(const Color& color) {
	this->color = color;
}

//

void UILayer::addOval(const float& x, const float& y, const float& w,
		const float& h) {
	Rectangle r = {x,y,w,h,0};
	addComponent(new Oval(r, color));
}

void UILayer::addOval(const Rectangle& rect) {
	addComponent(new Oval(rect, color));
}

void UILayer::addRectangle(const float& x, const float& y, const float& w,
		const float& h) {
	throw std::runtime_error("not implemented");
}

void UILayer::addRectangle(const Rectangle& rect) {
	throw std::runtime_error("not implemented");
}

void UILayer::addText(const float& x, const float& y, const char* string) {
	throw std::runtime_error("not implemented");
}

void UILayer::addText(const Point& point, const char* string) {
	throw std::runtime_error("not implemented");
}

void UILayer::addText(const float& x, const float& y,
		const std::string& string) {
	throw std::runtime_error("not implemented");
}

void UILayer::addText(const Point& point, const std::string& string) {
	throw std::runtime_error("not implemented");
}

void UILayer::addClickCallback(const float& x, const float& y,
		const float& w, const float& h, const ClickCallback& callback) {
	throw std::runtime_error("not implemented");
}

void UILayer::addClickCallback(const Rectangle& rect,
		const ClickCallback& callback) {
	throw std::runtime_error("not implemented");
}

//------------------
//------RENDER------
//------------------

bool UILayer::onRenderEvent(AppRenderEvent& event) {
	static Render* render = nullptr;
	if(render == nullptr){
		render = Application::getContext().getRender();
	}
	render->setClearColor(1, 1, 1, 1);
	render->clear();
	for(auto const& component: components) {
		component->draw();
	}
	return false;
}

}
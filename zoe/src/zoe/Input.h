/*
 * Input.h
 *
 *  Created on: 16.04.2019
 *      Author: florian
 */

#pragma once

#include "zpch.h"
#include "math/vec.h"

namespace Zoe{

class DLL_PUBLIC Input {
public:
	virtual ~Input(){}

	inline static bool isKeyPressed(int keycode) {
			return instance->isKeyPressedImpl(keycode);
		}
	inline static bool isMouseButtonPressed(int button) {
			return instance->isMouseButtonPressedImpl(button);
		}
	inline static vec2 getMousePosition() {
			return instance->getMousePositionImpl();
		}
	inline static float getMouseX(){
		return instance->getMouseXImpl();
	}
	inline static float getMouseY(){
		return instance->getMouseYImpl();
	}
protected:
	virtual bool isKeyPressedImpl(int keycode) = 0;
	virtual bool isMouseButtonPressedImpl(int button) = 0;
	virtual vec2 getMousePositionImpl() = 0;
	virtual float getMouseXImpl() = 0;
	virtual float getMouseYImpl() = 0;
private:
	static Input* instance;
};

}

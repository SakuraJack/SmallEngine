#pragma once

#include "Event.h"

#include <sstream>

namespace SmallEngine {
	//抽象键盘事件基类
	class SMALLENGINE_API KeyEvent : public Event
	{
	public:
		inline int GeyKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKewboard | EventCategoryInput)
	protected:
		KeyEvent(int keycode)
			:m_KeyCode(keycode)	{}

		int m_KeyCode;
	};

	//键盘按下事件类
	class SMALLENGINE_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, int repeatCount) 
			: KeyEvent(keycode), m_RepeatCount(repeatCount) {}
		
		inline int GetRepeatCount() const { return m_RepeatCount; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << "(" << m_RepeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int m_RepeatCount;
	};

	//键盘释放按键类
	class SMALLENGINE_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode)
			: KeyEvent(keycode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};
}


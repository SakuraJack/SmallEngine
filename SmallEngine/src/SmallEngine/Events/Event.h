#pragma once

#include "sepzh.h"
#include "SmallEngine/Core.h"

namespace SmallEngine {
	//当前事件系统为阻塞队列
	//当事件发生时 会立即阻塞并处理

	//事件类型
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButttonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	//事件分类
	enum EventCategory
	{
		None = 0,
		EventCategoryApplication	=	BIT(0),
		EventCategoryInput			=	BIT(1),
		EventCategoryKewboard		=	BIT(2),
		EventCategoryMouse			=   BIT(3),
		EventCategoryMouseButton	=	BIT(4)
	};

//定义返回事件类型和静态类型函数的宏 这样在每个事件类中不必再复制实现
#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override{ return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class SMALLENGINE_API Event
	{
	public:
		bool Handled = false;

		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool isInCategory(EventCategory category) {
			return GetCategoryFlags() & category;
		}
	};

	//事件调度
	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event) 
			: m_Event(event) 
		{

		}
		
		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}

	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
}
#pragma once

#include "sepzh.h"
#include "SmallEngine/Core.h"

namespace SmallEngine {
	//��ǰ�¼�ϵͳΪ��������
	//���¼�����ʱ ����������������

	//�¼�����
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButttonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	//�¼�����
	enum EventCategory
	{
		None = 0,
		EventCategoryApplication	=	BIT(0),
		EventCategoryInput			=	BIT(1),
		EventCategoryKewboard		=	BIT(2),
		EventCategoryMouse			=   BIT(3),
		EventCategoryMouseButton	=	BIT(4)
	};

//���巵���¼����ͺ;�̬���ͺ����ĺ� ������ÿ���¼����в����ٸ���ʵ��
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

	//�¼�����
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
#include "DayNightManager.h"
#include "StateMachine.h"
#include "IState.h"

void DayNightManager::Update()
{
    m_FSM->Update();
    if (m_state == day)
    {
        if (m_FSM->GetState()->CanExit())
        {
            m_FSM->ChangeState(m_states[night]);
            m_state = night;
        }
    }
    else
    {
        if (m_FSM->GetState()->CanExit())
        {
            m_FSM->ChangeState(m_states[day]);
            m_state = day;
        }
    }
}

const char* DayNightManager::GetName()
{
    return nullptr;
}

void DayNightManager::Execute()
{
}

DayNightManager::DayNightManager()
{
    m_states = new IState*[2];
    m_states[day] = new DayState();
    m_states[night] = new NightState();
    m_FSM = new StateMachine(m_states[0]);
    m_state = day;
}

DayNightManager::~DayNightManager()
{
    delete m_FSM;
    delete m_states[day];
    delete m_states[night];
    delete[] m_states;
}

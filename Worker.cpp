#pragma once
#include "common.h"
using namespace std;

Worker::Worker():m_Id(0),m_Name("нч"), m_DptId(0)
{

}
Worker::Worker(int m_Id, const string& m_Name, int m_DptId): m_Id(m_Id), m_Name(m_Name), m_DptId(m_DptId)
{

}

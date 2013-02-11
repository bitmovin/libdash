#include "dashplayerobserver.h"
#include <iostream>

using namespace std;

DashPlayerObserver::DashPlayerObserver()
{
}

DashPlayerObserver::~DashPlayerObserver()
{

}

void DashPlayerObserver::OnSettingsChanged (QtSamplePlayer* widget, const std::string& v_adaption, const std::string& v_representation, const std::string& a_adaption, const std::string& a_representation)
{
    cout << "Settings changed" << endl;
    widget->setBufferFillState(80);
}

void DashPlayerObserver::OnURLChanged(QtSamplePlayer* widget, const std::string& url)
{
    widget->setBufferFillState(40);

    cout << "Url changed" << endl;
}


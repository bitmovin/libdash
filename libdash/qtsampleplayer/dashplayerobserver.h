#ifndef WIDGETOBSERVER_H
#define WIDGETOBSERVER_H

#include <string>
#include "qtsampleplayer.h"

class DashPlayerObserver
{
public:
    DashPlayerObserver();
    virtual ~DashPlayerObserver();

    virtual void OnSettingsChanged (QtSamplePlayer* widget, const std::string& v_adaption, const std::string& v_representation, const std::string& a_adaption, const std::string& a_representation);
    virtual void OnURLChanged(QtSamplePlayer* widget, const std::string& url);
};

#endif // WIDGETOBSERVER_H

#include "DASHPlayer.h"
#include <iostream>
#include <sstream>

using namespace dash::sampleplayer;
using namespace dash::mpd;
using namespace std;

DASHPlayer::DASHPlayer(QtSamplePlayerGui& gui) : gui(&gui)
{
	this->manager = CreateDashManager();
	
	
	this->gui->addWidgetObserver(this);
}
DASHPlayer::~DASHPlayer(void)
{

}
void DASHPlayer::OnSettingsChanged (QtSamplePlayerGui* widget, int video_adaption, int video_representation, int audio_adaption, int audio_representation)
{
	stringstream ss;
	ss << "Selected video adaption: " << video_adaption << " video_repr: " << video_representation << " Audio adaption:  " << audio_adaption << " Audio repr: " << audio_representation;
	this->gui->setStatusBar(ss.str());
}
 void DASHPlayer::OnURLChanged(QtSamplePlayerGui* widget, const std::string& url)
 {
	this->mpd = this->manager->Open((char*)url.c_str());
	if(this->mpd != NULL)
	{

		this->gui->setStatusBar("Gotcha MPD");
		this->gui->setGuiFields(this->mpd);
	}
	else
	{
		this->gui->setStatusBar("Error parsing mpd at: " + url);
	}
 }


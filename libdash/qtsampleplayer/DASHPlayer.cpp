#include "DASHPlayer.h"

using namespace dash::sampleplayer;

DASHPlayer::DASHPlayer(QtSamplePlayerGui& gui) : gui(&gui)
{
	this->manager = CreateDashManager();
	
	
	this->gui->addWidgetObserver(this);
}
DASHPlayer::~DASHPlayer(void)
{

}
void DASHPlayer::OnSettingsChanged (QtSamplePlayerGui* widget, const std::string& v_adaption, const std::string& v_representation, const std::string& a_adaption, const std::string& a_representation)
{

}
 void DASHPlayer::OnURLChanged(QtSamplePlayerGui* widget, const std::string& url)
 {
	this->mpd = this->manager->Open((char*)url.c_str());
	if(this->mpd != NULL)
	{
		this->gui->setStatusBar("Gotcha MPD");

		//this->mpd->GetProfiles()
	}
	else
	{
		this->gui->setStatusBar("Error parsing mpd at: " + url);
	}
 }

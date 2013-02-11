#include "DASHPlayer.h"


DASHPlayer::DASHPlayer(void)
{
	this->manager = CreateDashManager();
}
DASHPlayer::~DASHPlayer(void)
{

}
void DASHPlayer::OnSettingsChanged (QtSamplePlayerGui* widget, const std::string& v_adaption, const std::string& v_representation, const std::string& a_adaption, const std::string& a_representation)
{

}
 void DASHPlayer::OnURLChanged(QtSamplePlayerGui* widget, const std::string& url)
 {

 }

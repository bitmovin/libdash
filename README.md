# libdash


libdash is the **official reference software of the ISO/IEC MPEG-DASH standard** and is an open-source library that provides an object orient (OO) interface to the MPEG-DASH standard, developed by [Bitmovin](http://www.bitmovin.com).

## by bitmovin
<a href="https://www.bitmovin.com"><img src="https://ox4zindgwb3p1qdp2lznn7zb-wpengine.netdna-ssl.com/wp-content/uploads/2016/01/bitmovin-standard-2017.png" width="400px"/></a>

Video encoding 100x faster than any other encoding service
Your videos play everywhere with low startup delay, no buffering and in the highest quality

## Netflix Grade Quality
Encode your content with the same technology as Netflix and YouTube in a way that it plays everywhere with low startup delay and no buffering. <a href="https://bitmovin.com/cloud-encoding-service/">Bitmovins Cloud Encoding Service</a> encodes your content 100x faster than any other competitor while providing such a high quality output.

## API & Documentation
<a href="https://bitmovin.com/cloud-encoding-service/">The Bitmovin Cloud Encoding Service</a> is a powerful cloud encoding tool for developers built by developers. <a href="https://bitmovin.com/bitmovins-video-api/">The Bitmovin API</a> is available in our developer section including comprehensive documentation and API client for different programming languages such as Java, JavaScript, Ruby, Python, PHP, NodeJS, etc.

## HTML5 Adaptive Streaming Player
<a href="https://bitmovin.com/html5-player/">The Bitmovin Adaptive HTML5 Video Player</a> enables HTML5 adaptive streaming with MPEG-DASH native in your browser with no need for plugins like Flash or Silverlight. Due to the native integration with the browser it is possible to play back very high resolutions such as 4K or very high frame rates like 60fps.

## Professional Services
In addition to the public available open source resources and the mailing list support, we provide professional development and integration services, consulting, high-quality streaming componentes/logics, relicensing of libdash etc. based on your individual needs. Feel free to contact us via <a href="mailto:sales@bitmovin.com">sales@bitmovin.com</a> so we can discuss your requirements and provide you an offer.

## Architecture
The general architecture of <a href="https://bitmovin.com/dynamic-adaptive-streaming-http-mpeg-dash/">MPEG-DASH</a> is depicted in the figure below where the orange parts are standardized, i.e., the MPD and segment formats. The delivery of the MPD, the control heuristics and the media player itself, are depicted in blue in the figure. These parts are not standardized and allow the differentiation of industry solutions due to the performance or different features that can be integrated at that level. libdash is also depicted in blue and encapsulates the MPD parsing and HTTP part, which will be handled by the library. Therefore the library provides interfaces for the DASH Streaming Control and the Media Player to access MPDs and downloadable media segments. The download order of such media segments will not be handled by the library this is left to the DASH Streaming Control, which is an own component in this architecture but it could also be included in the Media Player.
In a typical deployment, a DASH server provides segments in several bitrates and resolutions. The client initially receives the MPD through libdash which provides a convenient object oriented interface to that MPD. The MPD contains the temporal relationships for the various qualities and segments. Based on that information the client can download individual media segments through libdash at any point in time. Therefore varying bandwidth conditions can be handled by switching to the corresponding quality level at segment boundaries in order to provide a smooth streaming experience. This adaptation is not part of libdash and the MPEG-DASH standard and will be left to the application which is using libdash.

## Documentation

The doxygen documentation availalbe in the repo.

## Sources and Binaries

You can find the latest sources and binaries on github.

## How to use

### Windows
1. Download the tarball or clone the repository from github (git://github.com/bitmovin/libdash.git)
2. Open the libdash.sln with Visual Studio 2010
3. Build the solution
4. After that all files will be provided in the bin folder
5. You can test the library with the sampleplayer.exe. This application simply downloads the lowest representation of one of our dataset MPDs.

### Ubuntu 12.04
1. sudo apt-get install git-core build-essential cmake libxml2-dev libcurl4-openssl-dev
2. git clone git://github.com/bitmovin/libdash.git
3. cd libdash/libdash
4. mkdir build
5. cd build
6. cmake ../
7. make
8. cd bin
9. The library and a simple test of the network part of the library should be available now. You can test the network part of the library with
10. ./libdash_networkpart_test

#### QTSamplePlayer
Prerequisite: libdash must be built as described in the previous section.

1. sudo apt-add-repository ppa:ubuntu-sdk-team/ppa
2. sudo apt-add-repository ppa:canonical-qt5-edgers/qt5-proper
3. sudo apt-get update
4. sudo apt-get install qtmultimedia5-dev qtbase5-dev libqt5widgets5 libqt5core5 libqt5gui5 libqt5multimedia5 libqt5multimediawidgets5 libqt5opengl5 libav-tools libavcodec-dev libavdevice-dev libavfilter-dev libavformat-dev libavutil-dev libpostproc-dev libswscale-dev
5. cd libdash/libdash/qtsampleplayer
6. mkdir build
7. cd build
8. wget http://www.cmake.org/files/v2.8/cmake-2.8.11.2-Linux-i386.sh
9. chmod a+x cmake-2.8.11.2-Linux-i386.sh
10. ./cmake-2.8.11.2-Linux-i386.sh
11. ./cmake-2.8.11.2-Linux-i386/bin/cmake ../
12. make
13. ./qtsampleplayer

## License

libdash is open source available and licensed under LGPL:

“This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation; either version 2.1 of the License, or (at your option) any later version.
This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
You should have received a copy of the GNU Lesser General Public License along with this library; if not, write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA“

As libdash is licensed under LGPL, changes to the library have to be published again to the open-source project. As many user and companies do not want to publish their specific changes, libdash can be also relicensed to a commercial license on request. Please contact <a href="mailto:sales@bitmovin.com">sales@bitmovin.com</a> to provide you an offer.

## Acknowledgements

We specially want to thank our passionate developers at [Bitmovin](http://www.bitmovin.com) as well as the researchers at the [Institute of Information Technology](http://www-itec.aau.at/dash/) (ITEC) from the Alpen Adria Universitaet Klagenfurt (AAU)!

Furthermore we want to thank the [Netidee](http://www.netidee.at) initiative from the [Internet Foundation Austria](http://www.nic.at/ipa) for partially funding the open source development of libdash.

![netidee logo](http://www.bitmovin.com/files/bitmovin/img/logos/netidee.png "netidee")

## Citation of libdash
We kindly ask you to refer the following paper in any publication mentioning libdash:

Christopher Mueller, Stefan Lederer, Joerg Poecher, and Christian Timmerer, “libdash – An Open Source Software Library for the MPEG-DASH Standard”, in Proceedings of the IEEE International Conference on Multimedia and Expo 2013, San Jose, USA, July, 2013

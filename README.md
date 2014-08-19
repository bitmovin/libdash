# libdash


libdash is the **official reference software of the ISO/IEC MPEG-DASH standard** and is an open-source library that provides an object orient (OO) interface to the MPEG-DASH standard, developed by [bitmovin](http://www.bitmovin.net). 

## Features

* Cross platform build system based on cmake that includes Windows, Linux and Mac.
* Open source available and licensed under the LGPL.
* Comprehensive doxygen documentation of the library availalbe at [bitmovin](http://www.bitmovin.net/files/bitmovin/content/documentation/libdash/3_0/index.html).
* Implements the full MPEG-DASH standard according to ISO/IEC 23009-1, Information Technology Dynamic Adaptive Streaming over HTTP (DASH) Part 1: Media Presentation Description and Segment Formats
* Handles the download and xml parsing of the MPD. Based on that it provides an OO based interface to the MPD.
* Media elements, e.g., SegmentURL, SegmentTemplate, etc., are downloadable in that OO based structure and can be downloaded through libdash, which internally uses libcurl.
* Therefore basically all protocols that libcurl supports, e.g., HTTP, FTP, etc. are supported by libdash.
* However it also provides a configurable download interface, which enables the use of external connections that can be implemented by the user of the library for the download of media segments.
* The use of such external connections will be shown in the libdash_networkpart_test project which is part of libdash solution and also part of the cross platform cmake system and therefore usable on Windows, Linux and Mac.
* The project contains a QT-based sample multimedia player that is based on ffmpeg which uses libdash for the playback of one of our dataset MPDs.
* The development is based on Windows, therefore the code contains a VS10 solution with additional tests and the sample multimedia player.

## Professional Services

In addition to the public available open source resources and the mailing list support, we provide professional development and integration services, consulting, high-quality streaming componentes/logics, relicensing of libdash etc. based on your individual needs. Feel free to contact us via sales@bitmovin.net so we can discuss your requirements and provide you an offer.

## bitdash - Advanced MPEG-DASH Clients


On top of libdash, we provide our [bitdash adaptation framework] (http://www.bitmovin.net), which significantely boosts the streaming performance of MPEG-DASH. It enables up to 100 % higher media throughput than Apple HLS, and 50 % more than Microsoft Smooth Streaming. Additionally it comes together with streaming management functionalities, oscillation prevention mechanisms, DRM key management, multi-source (multi-CDN) support, and much more. It targets embedded platforms such as smartphones, TV-Sets, Set-Top Boxes, etc. and is available on any platform, including Windows, Linux, Mac, Android, etc. Furthermore, we've implementations for HTML5 (MSE) as well as Adobe Flash

Please do not heasitate and contact sales@bitmovin.net to get further information on [bitdash] (http://www.bitmovin.net/)!


## Architecture
<p align="justify">The general architecture of MPEG-DASH is depicted in the figure below where the orange parts are standardized, i.e., the MPD and segment formats. The delivery of the MPD, the control heuristics and the media player itself, are depicted in blue in the figure. These parts are not standardized and allow the differentiation of industry solutions due to the performance or different features that can be integrated at that level. libdash is also depicted in blue and encapsulates the MPD parsing and HTTP part, which will be handled by the library. Therefore the library provides interfaces for the DASH Streaming Control and the Media Player to access MPDs and downloadable media segments. The download order of such media segments will not be handled by the library this is left to the DASH Streaming Control, which is an own component in this architecture but it could also be included in the Media Player.
</p>
<p align="justify">
In a typical deployment, a DASH server provides segments in several bitrates and resolutions. The client initially receives the MPD through libdash which provides a convenient object orient interface to that MPD. The MPD contains the temporal relationships for the various qualities and segments. Based on that information the client can download individual media segments through libdash at any point in time. Therefore varying bandwidth conditions can be handled by switching to the corresponding quality level at segment boundaries in order to provide a smooth streaming experience. This adaptation is not part of libdash and the MPEG-DASH standard and will be left to the application which is using libdash.
</p>


![libdash architecture](http://www.bitmovin.net/files/bitmovin/img/libdash_arch.png "libdash architecture")

## Documentation

The doxygen documentation is online available at [bitmovin](http://www.bitmovin.net/libdash_OpenSource/libdash_2_1_doxygen/index.html).

## Mailinglist

We offer a public accessible mailing list for discussions, questions, announcements, bug-reports, etc. around libdash. Everybody is invited to join, you can find the registration at:

[libdash-dev] (http://vicky.bitmovin.net/mailman/listinfo/libdash-dev)

There are a lot of things to do! So everybody is invited to contribute, to get involved in and exited about DASH!

## Sources and Binaries

You can find the latest sources and binaries in our [download section] (http://www.bitmovin.net) and on github.

## How to use

### Windows
1. Download the tarball or clone the repository from gitlab (git://github.com/bitmovin/libdash.git)
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
10. ./libdash_networpart_test

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

As libdash is licensed under LGPL, changes to the library have to be published again to the open-source project. As many user and companies do not want to publish their specific changes, libdash can be also relicensed to a commercial license on request. Please contact sales@bitmovin.net to provide you an offer.

## Acknowledgements

We specially want to thank our passionate developers at [bitmovin](http://www.bitmovin.net/) as well as the researchers at the [Institute of Information Technology](http://www-itec.aau.at/dash/) (ITEC) from the Alpen Adria Universitaet Klagenfurt (AAU)!

Furthermore we want to thank the [Netidee](http://www.netidee.at) initiative from the [Internet Foundation Austria](http://www.nic.at/ipa) for partially funding the open source development of libdash.

![netidee logo](http://www.bitmovin.net/files/bitmovin/img/logos/netidee.png "netidee")

## Citation of libdash
We kindly ask you to refer the following paper in any publication mentioning libdash:

Christopher Mueller, Stefan Lederer, Joerg Poecher, and Christian Timmerer, “libdash – An Open Source Software Library for the MPEG-DASH Standard”, in Proceedings of the IEEE International Conference on Multimedia and Expo 2013, San Jose, USA, July, 2013

[![githalytics.com alpha](https://cruel-carlota.pagodabox.com/4a93fd520bd266c98e04e03b8463a154 "githalytics.com")](http://githalytics.com/bitmovin/libdash)

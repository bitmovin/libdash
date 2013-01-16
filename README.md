# libdash

![libdash logo](http://www.bitmovin.net/wp-content/uploads/2013/01/libdash_logo.png "libdash")


libdash is a library that provides an object orient (OO) interface to the MPEG-DASH standard.

## Features

* Cross platform build system based on cmake that includes Windows, Linux and Mac.
* Open source available and licensed under the LGPL.
* Implements the full MPEG-DASH standard according to ISO/IEC 23009-1, Information Technology Dynamic Adaptive Streaming over HTTP (DASH) Part 1: Media Presentation Description and Segment Formats
* Handles the download and xml parsing of the MPD. Based on that it provides an OO based interface to the MPD.
* Media elements, e.g., SegmentURL, SegmentTemplate, etc., are downloadable in that OO based structure and can be downloaded through libdash, which internally uses libcurl.
* Therefore basically all protocols that libcurl supports, e.g., HTTP, FTP, etc. are supported by libdash.
* However it also provides a configurable download interface, which enables the use of external connections that can be implemented by the user of the library for the download of media segments.
* The use of such external connections will be shown in the libdash_networkpart_test project which is part of libdash solution and also part of the cross platform cmake system and therefore usable on Windows, Linux and Mac.
* The project contains a sample multimedia player that is based on ffmpeg which uses libdash for the playback of one of our dataset MPDs.
* The development is based on Windows, therefore the code contains a VS10 solution with additional tests and the sample multimedia player.

## Mailinglist

We offer a public accessible mailing list for discussions, questions, announcements, bug-reports, etc. around libdash. Everybody is invited to join, you can find the registration at:

[libdash-dev] (http://vicky.bitmovin.net/mailman/listinfo/libdash-dev)

There are a lot of things to do! So everybody is invited to contribute, to get involved in and exited about DASH!

## Roadmap

* Next release is scheduled at the end of February.
* Doxygen Documentation.
    * Cross platform build system for the ffmpeg based sample player.
    * QT based sample player, which is cross platform buildable through cmake.
    * Further Tests & Bugfixes.
* Ongoing development during 2013
    * Implementation of a middleware for libdash.
        * Will provide buffering mechanisms and build-in adaptation logics.
        * Extends the functionality to extract, e.g., mp4, mp2ts, etc. information of the media stream.
        * Will provide further access methods which should provide a simplified interface to the library.
    * Extending the QT based sample player.
    * Testing & Bugfixing

## Sources and Binaries

You can find the latest sources and binaries in our [download section] (http://www.bitmovin.net/?page_id=851) and on github.

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

## License

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

## Acknowledgements

We specially want to thank our passionate developers at bitmovin as well as the researchers at the Institute for Information Technology (ITEC) of the Alpen Adria Universitaet Klagenfurt (AAU)!

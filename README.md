libdash
=======
libdash is a library that provides an object orient (OO) interface to the MPEG-DASH standard.

Features
======
* Cross platform build system based on cmake that includes Windows, Linux and Mac.
* Implements the full MPEG-DASH standard according to ISO/IEC 23009-1, Information Technology – Dynamic Adaptive Streaming over HTTP (DASH) – Part 1: Media Presentation Description and Segment Formats
* Handles the download and xml parsing of the MPD. Based on that it provides an OO based interface to the MPD.
* Media elements, e.g., SegmentURL, SegmentTemplate, etc., are downloadable in that OO based structure and can be downloaded through libdash, which internally uses libcurl.
* Therefore basically all protocols that libcurl supports, e.g., HTTP, FTP, etc. are supported by libdash.
* However it also provides a configurable download interface, which enables the use of external connections that can be implemented by the user of the library for the download of media segments.
* The use of such external connections will be shown in the libdash_networkpart_test project which is part of libdash solution and also part of the cross platform cmake system and therefore usable on Windows, Linux and Mac.
* The project contains a sample multimedia player that is based on ffmpeg which uses libdash for the playback of one of our dataset MPD’s.
* The development is based on Windows, therefore the code contains a VS10 solution with additional tests and the sample multimedia player.

Mailinglist
======
We offer a public accessible mailing list for discussions, questions, announcements, bug-reports, etc. around libdash. Everybody is invited to join, you can find the registration at:

http://vicky.bitmovin.net/mailman/listinfo/libdash-dev

There are a lot of things to do! So everybody is invited to contribute, to get involved in and exited about DASH!

Roadmap
======
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

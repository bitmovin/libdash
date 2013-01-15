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

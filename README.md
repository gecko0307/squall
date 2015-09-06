Squall
======
Squall is an audio engine for games. Originally written by Marat Gilyazetdinov. Last version of the engine was 1.48, then, in 2009, Squall was open-sourced. Since then, the progect is no longer maintained by the original developers, so I decided to publish it on GitHub. I plan to modernize the code base and port the engine to Linux, add OSS or ALSA support. So far I haven't modified anything, just transcoded all the files into UTF-8.

Features
--------
* Written in C++, has also C interface
* Supports WAV (PCM, IMA ADPCM, MS ADPCM), MP3, OGG/Vorbis
* Output via DirectSound
* 3D sound support (even for stereo sounds)
* 5.1 multichannel systems support
* Hardware acceleration support
* HRTF support (CreativeLab EAX, Sensaura ZoomFX)

Known issues
------------
* No 64 bit suport
* WMA and tracker formats support doesn't work

Usage
-----
Squall once was rather popular in Russian game development industry. The following is a list of commercial PC games that are known to use it:
* Full Pipe / Полная труба (2003)
* Dilemma / Дилемма (2006)
* Legend of Beowulf / Легенда о Беовульфе (2007)
* Nuclear Creatures / Ядерные твари (2007)
* Star Legion / Звездный легион (2007)
* Granny and Snowmen / Бабка против снеговиков (2008)
* Farm Frenzy 2 / Веселая ферма 2 (2008)
* Farm Frenzy: Pizza Party / Веселая ферма: печем пиццу (2009)
* Bato: Treasures of Tibet / Бато: сокровища Тибета (2009)
* Stalin's Falcons / Сталинские соколы (2009)
* Astana Racer (2009)
* Possibly many others...

Squall had been also used by a number of game engines, namely, Xors3d Engine and [Isilme](https://code.google.com/p/isilme). There's also a rumor that a strongly modified version of Squall was a part of X-Ray, the engine of S.T.A.L.K.E.R. - not sure if it's true. 
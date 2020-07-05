
Debian
====================
This directory contains files used to package astrad/astra-qt
for Debian-based Linux systems. If you compile astrad/astra-qt yourself, there are some useful files here.

## astra: URI support ##


astra-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install astra-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your astraqt binary to `/usr/bin`
and the `../../share/pixmaps/astra128.png` to `/usr/share/pixmaps`

astra-qt.protocol (KDE)



Debian
====================
This directory contains files used to package Luxd/Lux-qt
for Debian-based Linux systems. If you compile Luxd/Lux-qt yourself, there are some useful files here.

## Lux: URI support ##


Lux-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install Lux-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your Luxqt binary to `/usr/bin`
and the `../../share/pixmaps/Lux128.png` to `/usr/share/pixmaps`

Lux-qt.protocol (KDE)


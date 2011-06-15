/*
 * A program to set the names of KDE 4' virtual desktops (a.k.a virtual
 * workspaces).
 *
 * Adapted from kdebase-workspace-4.6.4 's 
 * kwin/kcmkwin/kwindesktop/main.cpp , which is:
********************************************************************
KWin - the KDE window manager
This file is part of the KDE project.

Copyright (C) 2009 Martin Gräßlin <kde@martin-graesslin.com>

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*********************************************************************
 *
 * Skeleton of KApplication taken from:
 * http://techbase.kde.org/Development/Tutorials/First_program
 *
 * Written by Shlomi Fish ( http://www.shlomifish.org/ ) while disclaiming
 * all rights on the modifications.
 *
 */
#include <QX11Info>
#include <NETRootInfo>
#include <KApplication>
#include <KAboutData>
#include <KCmdLineArgs>
#include <KMessageBox>
#include <KLocale>

int main(int argc, char * argv[])
{
    KAboutData aboutData(
                         // The program name used internally.
                         "tutorial1",
                         // The message catalog name
                         // If null, program name is used instead.
                         0,
                         // A displayable program name string.
                         ki18n("Tutorial 1"),
                         // The program version string.
                         "1.0",
                         // Short description of what the app does.
                         ki18n("Displays a KMessageBox popup"),
                         // The license this code is released under
                         KAboutData::License_GPL,
                         // Copyright Statement
                         ki18n("(c) 2007"),
                         // Optional text shown in the About box.
                         // Can contain any information desired.
                         ki18n("Some text..."),
                         // The program homepage string.
                         "http://example.com/",
                         // The bug report email address
                         "submit@bugs.kde.org");
 
    KCmdLineArgs::init( argc, argv, &aboutData );
    KApplication app;

    KCmdLineArgs * parsedArgs = KCmdLineArgs::parsedArgs();

    QStringList desktopNames;

    for (int i = 0; i < parsedArgs->count() ; i++)
    {
        desktopNames << parsedArgs->arg(i);
    }

    int numDesktops = desktopNames.count();

#ifdef Q_WS_X11
    NETRootInfo info( QX11Info::display(), NET::NumberOfDesktops | NET::DesktopNames );
    // set desktop names
    for( int i = 1; i <= numDesktops; i++ )
    {
        QString desktopName = desktopNames[ i -1 ];
        info.setDesktopName( i, desktopName.toUtf8());
        info.activate();
    }
    // set number of desktops
    info.setNumberOfDesktops( numDesktops );
    info.activate();

    XSync(QX11Info::display(), false);
#endif

    return 0;
}

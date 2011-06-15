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

    int numDesktops = 8;

    QStringList desktopNames;

    desktopNames << "Main";
    desktopNames << "Devel";
    desktopNames << "Chat";
    desktopNames << "Donkey";
    desktopNames << "Music";
    desktopNames << "Config";
    desktopNames << "Desktop 7";
    desktopNames << "Games";
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

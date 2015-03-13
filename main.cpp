/*****************************************************************************
 * main.cpp
 *****************************************************************************
 * Copyright (C) 2014 MX Authors
 *
 * Authors: Adrian
 *          MEPIS Community <http://forum.mepiscommunity.org>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * MX Viewer is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with MX Viewer.  If not, see <http://www.gnu.org/licenses/>.
 **********************************************************************/

#include <QApplication>
#include <QMessageBox>
#include "mxview.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon("/usr/share/pixmaps/mx/mx-viewer.png"));

    QString arg1 = argv[1];
    if (argc == 1 or arg1 == "--help" or arg1 == "-h") {
        QMessageBox::information(0, QString::null,
                                 QApplication::tr("Usage: call program with: mx-view URL [window title]\n\n"
                                                  "The 'mx-viewer' program will display the URL content in a window, window title is optional."));
        return 1;
    }

    const QString url = argc > 1 ? QString(argv[1]) : QString();
    const QString title = argc > 2 ? QString(argv[2]) : QString();

    mxview w(url, title);
    w.show();

    return a.exec();
}
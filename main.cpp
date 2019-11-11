//
// Created by twak on 14/10/2019.
//

#include <iostream>
#include <QApplication>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QMediaPlaylist>
#include <string>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QHBoxLayout>
#include <QtCore/QFileInfo>
#include <QtWidgets/QFileIconProvider>
#include <QImageReader>
#include <QtCore/QDir>
#include <QtCore/QDirIterator>
#include "the_player.h"
#include "the_button.h"

using namespace std;

vector<TheButtonInfo> getInfoIn (string loc) {

    vector<TheButtonInfo> out =  vector<TheButtonInfo>();
    QDir dir(QString::fromStdString(loc) );
    QDirIterator it(dir);

    while (it.hasNext()) {

        QString f = it.next();

        if (!f.contains(".png")) {
            QString thumb = f.left( f .length() - 4) +".png";
            if (QFile(thumb).exists()) {
                QImageReader *imageReader = new QImageReader(thumb);
                    QImage sprite = imageReader->read();
                    if (!sprite.isNull()) {
                        QIcon* ico = new QIcon(QPixmap::fromImage(sprite));

                        QUrl* url = new QUrl(QUrl::fromLocalFile( f ));
                        out . push_back(TheButtonInfo( url , ico  ) );
                    }
            }
            else
                cerr << "warning: skipping video because I couldn't find thumbnail " << thumb.toStdString() << endl;
        }
    }

    return out;
}


int main(int argc, char *argv[]) {

    // let's just check that Qt is operational first
    cout << "Qt version: " << QT_VERSION_STR << endl;

    // create the Qt Application
    QApplication app(argc, argv);

    vector<TheButtonInfo> videos = getInfoIn("/home/twak/Videos/cw2");

    for (TheButtonInfo bi : videos) {
        cout << bi.url->toString().toStdString() << endl;
        cout << bi.icon->isNull() << endl;
    }

    QVideoWidget *videoWidget = new QVideoWidget;

    ThePlayer *player = new ThePlayer;
    player->setVideoOutput(videoWidget);

    QWidget *buttonWidget = new QWidget();
    QHBoxLayout *layout = new QHBoxLayout();
    buttonWidget->setLayout(layout);

    std::vector<TheButton*> buttons;

    for (int i = 0; i < 3; i++) {
        TheButton *button = new TheButton(buttonWidget);
        button->connect(button, SIGNAL(jumpTo(TheButtonInfo* )), player,
                        SLOT (jumpTo(TheButtonInfo* ))); // when clicked, tell the player to play.
        buttons.push_back(button);
        layout->addWidget(button);
        button->init(&videos.at(i));
    }

    player->setContent(&buttons);

    QWidget window;
    QVBoxLayout *hb = new QVBoxLayout();
    hb->setContentsMargins(0, 0, 0, 0);
    window.setLayout(hb);
    window.setFixedSize(800, 680);

    hb->addWidget(videoWidget);
    hb->addWidget(buttonWidget);

    window.show();


    // wait for the app to terminate
    return app.exec();
}

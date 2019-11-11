//
// Created by twak on 11/11/2019.
//

#ifndef CW2_THE_PLAYER_H
#define CW2_THE_PLAYER_H


#include <iostream>
#include <QApplication>
#include <QMediaPlayer>
#include <QtWidgets/QGraphicsScene>
#include <QtMultimediaWidgets/QGraphicsVideoItem>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QMediaPlaylist>
#include <string>
#include <iostream>
#include <dirent.h>
#include <QtWidgets/QPushButton>

using namespace std;

class ThePlayer : public QMediaPlayer {

Q_OBJECT

public:
    ThePlayer() : QMediaPlayer(NULL) {
        connect (this, SIGNAL (stateChanged(QMediaPlayer::State)), this, SLOT (printState(QMediaPlayer::State)) );
    }

private slots:
    void printState (QMediaPlayer::State ms) {
        cout << ms << " so there" << endl;
    }
};



#endif //CW2_THE_PLAYER_H

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
#include "the_button.h"
#include <vector>

using namespace std;

class ThePlayer : public QMediaPlayer {

Q_OBJECT

private:
    std::vector<TheButtonInfo*>* vector;
    std::vector<TheButton*>* buttons;

public:
    ThePlayer() : QMediaPlayer(NULL) {
        setVolume(0); // be slightly less annoying
        connect (this, SIGNAL (stateChanged(QMediaPlayer::State)), this, SLOT (printState(QMediaPlayer::State)) );
    }

    void setContent(std::vector<TheButton*>* b){
        buttons = b;
        jumpTo(buttons -> at(0) -> info);
    }

private slots:
    void printState (QMediaPlayer::State ms) {
        switch (ms) {
            case QMediaPlayer::State::StoppedState:
                play();
        }
    }

public slots:

    void jumpTo (TheButtonInfo* button) {
//        cout << file->toString().toStdString() << endl;
        setMedia( * button -> url);
        play();
    }
};



#endif //CW2_THE_PLAYER_H

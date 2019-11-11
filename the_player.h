//
// Created by twak on 11/11/2019.
//

#ifndef CW2_THE_PLAYER_H
#define CW2_THE_PLAYER_H


#include <QApplication>
#include <QMediaPlayer>
#include <QtWidgets/QGraphicsScene>
#include <QtMultimediaWidgets/QGraphicsVideoItem>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QMediaPlaylist>
#include <QtWidgets/QPushButton>
#include "the_button.h"
#include <vector>
#include <QTimer>

using namespace std;

class ThePlayer : public QMediaPlayer {

Q_OBJECT

private:
    std::vector<TheButtonInfo>* infos;
    std::vector<TheButton*>* buttons;
    QTimer* mTimer;
    long count = 0;

public:
    ThePlayer() : QMediaPlayer(NULL) {
        setVolume(0); // be slightly less annoying
        connect (this, SIGNAL (stateChanged(QMediaPlayer::State)), this, SLOT (printState(QMediaPlayer::State)) );

        mTimer = new QTimer(NULL);
        mTimer->setSingleShot(false);
        mTimer->setInterval(300);
        mTimer->start();

        connect( mTimer, SIGNAL (timeout()), SLOT ( shuffle() ) );
    }

    void setContent(std::vector<TheButton*>* b, std::vector<TheButtonInfo>* i){
        buttons = b;
        infos = i;

        jumpTo(buttons -> at(0) -> info);
    }

private slots:

    void shuffle() {
        buttons -> at( count++ % buttons->size() ) -> init( & infos -> at (rand() % infos->size() ) );
    }

    void printState (QMediaPlayer::State ms) {
        switch (ms) {
            case QMediaPlayer::State::StoppedState:
                play(); // play again again
        }
    }

public slots:

    void jumpTo (TheButtonInfo* button) {
        setMedia( * button -> url);
        play();
    }
};



#endif //CW2_THE_PLAYER_H

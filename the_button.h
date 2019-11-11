//
// Created by twak on 11/11/2019.
//

#ifndef CW2_THE_BUTTON_H
#define CW2_THE_BUTTON_H


#include <QtWidgets/QPushButton>
#include <QtMultimediaWidgets/QVideoWidget>

class TheButton : public QPushButton {

public:

    QUrl *video;

     TheButton(QWidget *parent, QVideoWidget *pWidget) :  QPushButton(parent) {

    }

    void init(QUrl &url) {

    }
};


#endif //CW2_THE_BUTTON_H

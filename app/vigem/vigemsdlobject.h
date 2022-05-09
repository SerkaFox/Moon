#ifndef VIGEMSDLOBJECT_H
#define VIGEMSDLOBJECT_H

#include <SDL.h>

#include <QObject>
#include <QDebug>

#include "vigemclient.h"

class VigemSDLObject : public QObject
{
    Q_OBJECT
public:
    explicit VigemSDLObject(Vigem::VigemClient * client, QObject *parent = nullptr);

public slots:
    bool handleKeyboardEvent(SDL_KeyboardEvent * event);


private:
    Qt::Key getQtKey(SDL_KeyboardEvent * event);

    Vigem::VigemClient * vigem_client;
};

#endif // VIGEMSDLOBJECT_H
